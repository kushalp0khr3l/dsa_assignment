# Documentation for program_5.c
**Q.**  How can we implement the undirected graph using adjacency matrix? Write a function that
implement the BFS and DFS technique to traverse through the graph. Demonstrate the
use of your program with example graph.

## (a) Data Structures
The program represents the graph using an **Adjacency Matrix**:
* **adj[MAX][MAX]**: A 2D integer array where adj[i][j] = 1 indicates an edge between node `i` and node `j`. For an undirected graph, this matrix is symmetric.
* **visited[MAX]**: An array used to keep track of nodes already processed to handle cycles and avoid infinite recursion.
* **queue[]**: A linear array used as a First-In-First-Out (FIFO) structure for the BFS traversal.



## (b) Key Functions
* **addEdge(u, v)**: Populates the matrix at [u][v] and [v][u] to represent a bidirectional link.
* **DFS(v)**: A recursive function that follows a "Depth-First" strategy. It visits a neighbor and immediately dives deeper into that neighbor's connections before backtracking.
* **BFS(start)**: An iterative function using a queue. It visits all immediate neighbors of a node (Breadth-First) before moving on to the next level of nodes.



## (c) main() Organization
1.  **Graph Setup**: Defines 5 nodes and adds edges: (0,1), (0,2), (1,3), (1,4).
2.  **DFS Execution**: Starts at node 0. It visits 1, then immediately goes to 1's children (3 and 4) before finally returning to visit node 2.
3.  **BFS Execution**: Starts at node 0. It visits all direct neighbors (1 and 2) first, then moves to the next level (3 and 4).
4.  **Comparison**: The output prints both results to highlight the structural difference between "diving deep" and "expanding wide."

## (d) Sample Run
**Graph Structure:** 0 is connected to 1 and 2; 1 is connected to 3 and 4.

**Output:**
```text
DFS (Goes deep first): 0 1 3 4 2 
BFS (Goes broad first): 0 1 2 3 4
```