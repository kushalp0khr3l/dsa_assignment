# Documentation for program_4.c
**Q.**  How can we implement the doubly linked list using structure? Write a method to insert(after
given node) and delete the node in doubly linked list. Write main() to demonstrate the use
of the functions.

## (a) Data Structures
The program implements a **Doubly Linked List (DLL)** using a structure:
* **struct Node** : Contains an integer data, a *next pointer to the following node, and a *prev pointer to the preceding node.
* The structure allows for $O(1)$ time deletion if the node pointer is known, as it provides direct access to the neighbor nodes.



## (b) Key Functions
* **insertAfter(prev_node, data)**: Inserts a new element after a given node. It reassigns the next pointer of the prev_node and the prev pointer of the subsequent node to include the new node in the sequence.
* **deleteNode(*head_ref, del_node)**: Removes a target node. It bridges the gap by connecting the del_node->prev directly to del_node->next. It specifically handles cases where the node is the head or the tail.
* **printList(head)**: Iterates through the list from the start and prints data values separated by **<->** to visualize the bidirectional links.



## (c) main() Organization
The main() function demonstrates the lifecycle of the DLL:
1.  **Initialization**: Creates an initial head node (value 10).
2.  **Sequential Insertion**: Uses insertAfter to build the list to **10 <-> 20 <-> 30**.
3.  **Removal**: Calls **deleteNode** on the middle element **(20)** to demonstrate how the list re-links itself.
4.  **Verification**: Prints the list state after insertions and after deletion to confirm accuracy.

## (d) Sample Run
Output:
```text
List after insertions:
10 <-> 20 <-> 30 <-> NULL
List after deleting node 20:
10 <-> 30 <-> NULL
```