
C DOC:

Init

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


start_index/end_index:

When you do pointer1 - pointer2 in C:
The result is the number of elements between the pointers

data->map->rooms points to rooms[0] (array name decays to pointer to first element)

If start_room points to rooms[0]:
rooms array in memory:
[room0][room1][room2][room3][room4]
 ^
 |
 rooms (points here)
 start_room (also points here if it's the first room)

start_room - rooms = 0  (same position)

If start_room points to rooms[2]:
[room0][room1][room2][room3][room4]
 ^              ^
 |              |
 rooms          start_room

start_room - rooms = 2  (2 elements difference)

Lem_in:


Parsing:
Format required
No empty lines

BFS algo:

Vizualizer:

https://www.libsdl.org/
https://github.com/libsdl-org/SDL

Explain how to add SDL:

	// ft_putstr(SDL_GetError(), STDERR_FILENO); // Use for debug