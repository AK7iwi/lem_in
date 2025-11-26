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

# Build the project
echo -e "${YELLOW}Building lem-in...${NC}"
make re > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo -e "${RED}Build failed!${NC}"
    exit 1
fi
echo -e "${GREEN}Build successful!${NC}\n"

# Test valid maps
echo -e "${YELLOW}========================================${NC}"
echo -e "${YELLOW}Testing VALID maps (should succeed):${NC}"
echo -e "${YELLOW}========================================${NC}\n"
for map in ressources/maps/valid_maps/*.txt; do
    if [ -f "$map" ]; then
        map_name=$(basename "$map")
        echo -e "${BLUE}Testing: $map_name${NC}"
        output=$(./lem-in < "$map" 2>&1)
        exit_code=$?
        if [ $exit_code -eq 0 ]; then
            echo -e "${GREEN}✓ PASSED${NC}"
            echo -e "Output (first 10 lines):"
            echo "$output" | head -10
            echo ""
            ((VALID_PASSED++))
        else
            echo -e "${RED}✗ FAILED (exit code: $exit_code)${NC}"
            echo -e "Error output:"
            echo "$output"
            echo ""
            ((VALID_FAILED++))
        fi
        echo "----------------------------------------"
    fi
done

echo ""

# Test invalid maps
echo -e "${YELLOW}========================================${NC}"
echo -e "${YELLOW}Testing INVALID maps (should fail):${NC}"
echo -e "${YELLOW}========================================${NC}\n"
for map in ressources/maps/invalid_maps/*.txt; do
    if [ -f "$map" ]; then
        map_name=$(basename "$map")
        echo -e "${BLUE}Testing: $map_name${NC}"
        output=$(./lem-in < "$map" 2>&1)
        exit_code=$?
        if [ $exit_code -ne 0 ]; then
            echo -e "${GREEN}✓ PASSED (correctly rejected)${NC}"
            if [ -n "$output" ]; then
                echo -e "Error message:"
                echo "$output"
            fi
            ((INVALID_PASSED++))
        else
            echo -e "${RED}✗ FAILED (should have failed but didn't!)${NC}"
            echo -e "Output:"
            echo "$output"
            ((INVALID_FAILED++))
        fi
        echo ""
        echo "----------------------------------------"
    fi
done

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

if [ $TOTAL_FAILED -eq 0 ]; then
    echo -e "${GREEN}All tests passed! ($TOTAL_PASSED/$TOTAL_TESTS)${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed! ($TOTAL_PASSED/$TOTAL_TESTS passed)${NC}"
    exit 1
fi

