# Documentation for program_6.c
**Q.**  Given the array of the data (unsorted), Write a program to build the min and max heap.

### (a) Data Structures
The program uses a Binary Heap implemented via a standard Array.
- **Logical structure:** A complete binary tree.
- **Storage:** Array indices represent tree levels. This avoids the memory overhead of pointers (next, prev).

### (b) Key Functions
- **maxHeapify/minHeapify**: The core logic. It compares a node with its children and "sinks" the node down to its correct position to maintain the heap property.
- **buildMaxHeap/buildMinHeap** : Starts from the last non-leaf node (index $n/2 - 1$) and calls heapify moving upwards to the root.
- **swap**: A helper to exchange values between two array indices.

### (c) main() Organization
- **Input**: Defines an unsorted integer array.
- **Max-Heap Construction**: Copies the original data and transforms it into a Max-Heap.
- **Min-Heap Construction**: Transforms the data into a Min-Heap.
- **Output** : Displays the resulting arrays to verify the root (index 0) is the maximum or minimum value respectively.

### (d) Sample Run
```
Input: 12, 11, 13, 5, 6, 7
Output:PlaintextMax-Heap array: 13 11 12 5 6 7 
Min-Heap array: 5 6 7 12 11 13 
```