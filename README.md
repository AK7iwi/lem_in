








- Rooms vs Links - Different access patterns:
a) Rooms:
Fixed number: known after parsing all rooms
Random access: need to find room "0" or room "2" by name
Indexed access: rooms[i] for iteration
Array fits: O(1) access, known size
b) Links (connections per room):
Variable number: each room has a different number of connections
Unknown count: don't know how many links until parsing is done
Sequential access: iterate through a room's neighbors
Linked list fits: dynamic growth, sequential iteration