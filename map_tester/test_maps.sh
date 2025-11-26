#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

VALID_PASSED=0
VALID_FAILED=0
INVALID_PASSED=0
INVALID_FAILED=0

# Arrays to store failed maps
VALID_FAILED_MAPS=()
INVALID_FAILED_MAPS=()

echo -e "${YELLOW}Building lem-in...${NC}"
make clean > /dev/null 2>&1
make all > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${RED}Build failed!${NC}"
    exit 1
fi
echo -e "${GREEN}Build successful!${NC}\n"

echo -e "${YELLOW}========================================${NC}"
echo -e "${YELLOW}Testing VALID maps (should succeed):${NC}"
echo -e "${YELLOW}========================================${NC}\n"
while IFS= read -r -d '' map; do
    map_name=$(basename "$map")
    map_path=$(echo "$map" | sed 's|^ressources/maps/valid_maps/||')
    echo -e "${BLUE}Testing: $map_path${NC}"
    output=$(./lem-in < "$map" 2>&1)
    exit_code=$?
        if [ $exit_code -eq 0 ]; then
            echo -e "${GREEN}✓ PASSED${NC}"
            echo -e "Output (first 20 lines):"
            echo "$output" | head -20
            echo ""
            ((VALID_PASSED++))
        else
            echo -e "${RED}✗ FAILED (exit code: $exit_code)${NC}"
            echo -e "Error output:"
            echo "$output"
            echo ""
            ((VALID_FAILED++))
            VALID_FAILED_MAPS+=("$map_path")
        fi
    echo "----------------------------------------"
done < <(find ressources/maps/valid_maps -type f -name "*.txt" -print0)

echo ""
echo -e "${YELLOW}========================================${NC}"
echo -e "${YELLOW}Testing INVALID maps (should fail):${NC}"
echo -e "${YELLOW}========================================${NC}\n"
while IFS= read -r -d '' map; do
    map_name=$(basename "$map")
    map_path=$(echo "$map" | sed 's|^ressources/maps/invalid_maps/||')
    echo -e "${BLUE}Testing: $map_path${NC}"
    output=$(./lem-in < "$map" 2>&1)
    exit_code=$?
    if [ $exit_code -ne 0 ]; then
        # Check if first line is "ERROR"
        first_line=$(echo "$output" | head -n 1)
        if [ "$first_line" = "ERROR:" ]; then
            echo -e "${GREEN}✓ PASSED (correctly rejected with ERROR)${NC}"
            if [ -n "$output" ]; then
                echo -e "Error message:"
                echo "$output"
            fi
            ((INVALID_PASSED++))
        else
            echo -e "${RED}✗ FAILED (rejected but first line is not 'ERROR')${NC}"
            echo -e "Expected first line: ERROR"
            echo -e "Got first line: '$first_line'"
            echo -e "Full output:"
            echo "$output"
            ((INVALID_FAILED++))
            INVALID_FAILED_MAPS+=("$map_path")
        fi
    else
        echo -e "${RED}✗ FAILED (should have failed but didn't!)${NC}"
        echo -e "Output:"
        echo "$output"
        ((INVALID_FAILED++))
        INVALID_FAILED_MAPS+=("$map_path")
    fi
    echo ""
    echo "----------------------------------------"
done < <(find ressources/maps/invalid_maps -type f -name "*.txt" -print0)

echo ""
echo "=========================================="
echo -e "${YELLOW}Test Summary:${NC}"
echo "=========================================="
echo -e "Valid maps:   ${GREEN}$VALID_PASSED passed${NC} / ${RED}$VALID_FAILED failed${NC}"
echo -e "Invalid maps: ${GREEN}$INVALID_PASSED passed${NC} / ${RED}$INVALID_FAILED failed${NC}"
echo ""

TOTAL_TESTS=$((VALID_PASSED + VALID_FAILED + INVALID_PASSED + INVALID_FAILED))
TOTAL_PASSED=$((VALID_PASSED + INVALID_PASSED))
TOTAL_FAILED=$((VALID_FAILED + INVALID_FAILED))

# Display failed maps
if [ $TOTAL_FAILED -gt 0 ]; then
    echo "=========================================="
    echo -e "${RED}Failed Maps:${NC}"
    echo "=========================================="
    
    if [ ${#VALID_FAILED_MAPS[@]} -gt 0 ]; then
        echo -e "${YELLOW}Valid maps that failed:${NC}"
        for map in "${VALID_FAILED_MAPS[@]}"; do
            echo -e "  ${RED}✗${NC} $map"
        done
        echo ""
    fi
    
    if [ ${#INVALID_FAILED_MAPS[@]} -gt 0 ]; then
        echo -e "${YELLOW}Invalid maps that should have failed but didn't:${NC}"
        for map in "${INVALID_FAILED_MAPS[@]}"; do
            echo -e "  ${RED}✗${NC} $map"
        done
        echo ""
    fi
fi

if [ $TOTAL_FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed! ($TOTAL_PASSED/$TOTAL_TESTS)${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed! ($TOTAL_PASSED/$TOTAL_TESTS passed)${NC}"
    exit 1
fi

