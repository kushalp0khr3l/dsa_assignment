# Documentation for program_3.c

**Q.** Write and Implement the reverse traversal algorithm in the the linked list. Write main() to
demonstrate the use of the function.

## (a) Data Structure Definition
The program uses a standard Singly Linked List.

- **struct Node**: Contains an int data for the value and a struct Node *next pointer to link to the succeeding node.
- The end of the list is marked by a NULL pointer.


## (b) Function Descriptions
- **createNode(int data)**: Allocates memory for a node using malloc, sets the data, and initializes the next pointer to NULL.
- **reverseList(struct Node *head)**: Uses an iterative approach with three pointers (prev, curr, next) to flip the direction of the list. It returns the new head.
- **printList(struct Node *node)**: A simple loop that visits each node and prints the data until it hits NULL.
## (c) Main Method Organization
The main() function is as:
 1. **Creation**: Manually links 5 nodes to create a list from 1 to 5.
 2. **Display**: Prints the list in its original order.
 3. **Reversal**: Calls reverseList and updates the head pointer.
 4. **Verification**: Prints the list again to show it is now in reverse.
 ## (d) Sample OutputPlaintext
```original linked list:
1 -> 2 -> 3 -> 4 -> 5
reverse traversal:
5 -> 4 -> 3 -> 2 -> 1 
```

## (e) Complexity
- **Time Complexity**:
 $O(n)$ because we traverse the list once.
 - **Space Complexity** : $O(1)$ since we only use a few extra pointers and no recursion.