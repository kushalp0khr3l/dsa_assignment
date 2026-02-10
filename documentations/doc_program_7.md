# Documentation for program_7.c

**Q.** Given a weighted graph, implement Dijkstra’s algorithm to find the shortest path from a
source node to all other nodes.

## (a) Data Structures
The program uses the following structures to manage the graph and path data:
* **Adjacency Matrix**: A 2D array graph[V][V] stores the edge weights. graph[i][j] = 0 implies no connection, while any positive integer represents the weight (cost) of the path.
* **Distance Array (dist[])**: An integer array where each index i holds the shortest known distance from the source to vertex "i".
* **Visited Array (visited[])**: A boolean array to mark vertices that have been fully processed, ensuring the greedy choice is only made from unvisited nodes.



## (b) Key Functions
* **minDistance()**: A helper function that scans the "dist[]" array to find the vertex with the minimum value that has not yet been included in the shortest-path tree.
* **dijkstra(graph, src)**: The main algorithm logic. It initializes distances to infinity "(INT_MAX)", sets the source distance to 0, and iteratively "relaxes" the edges of the graph.
* **Relaxation Logic**: For every neighbor "v" of a chosen vertex "u", the function checks if the path through "u" is shorter than the previously recorded distance to "v".



## (c) main() Organization
1.  **Graph Definition**: Initializes a $5 \times 5$ matrix representing a weighted undirected graph.
2.  **Algorithm Trigger**: Calls the 'dijkstra' function with 0 as the starting source node.
3.  **Result Display**: Prints a summary table showing the shortest distance from the source to every other node in the graph.

## (d) Sample Run
**Input Graph Structure:** Nodes 0-4 with various weights (e.g., 0 to 1 is weight 10).

**Output:**
```text
Vertex 	 Distance from Source (0)
0 		 0
1 		 10
2 		 50
3 		 30
4 		 60
```