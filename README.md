








- Rooms vs Links - Different access patterns:
a) Rooms:
Fixed number: known after parsing all rooms
Random access: need to find room "0" or room "2" by name (start/end rooms)
Indexed access: rooms[i] for iteration
Array fits: O(1) access, known size
b) Links (connections per room):
Variable number: each room has a different number of connections
Unknown count: don't know how many links until parsing is done
Sequential access: iterate through a room's neighbors
Linked list fits: dynamic growth, sequential iteration


Reallocate with capacity for the room. Specify O(n) --> O(log(n))
Better that reallocate each time
has_start, has_end flag:

Save the boolean value before free

// Scenario 1: Start room at index 0
has_start = true;        // Pointer exists
start_index = 0;         // It's at position 0
if (has_start)           // true → pointer will be restored ✓
    start_room = &rooms[0];

// Scenario 2: No start room
has_start = false;       // Pointer doesn't exist
start_index = 0;         // Still 0 (initialized value)
if (has_start)           // false → pointer won't be restored ✓

// Scenario 3: Start room at index 5
has_start = true;        // Pointer exists
start_index = 5;         // It's at position 5
if (has_start)           // true → pointer will be restored ✓
    start_room = &rooms[5];
