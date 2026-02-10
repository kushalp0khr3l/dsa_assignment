# Documentation for program_8.c

**Q.** Write a program that generates a list of N random integers in the range [1, 1000], where N
is provided by the user at run time. Then, perform the following tasks:
(a) Ask the user to choose a sorting algorithm from the following:
- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort

(b) Sort the randomly generated numbers using the chosen algorithm.
(c) Print the numbers before and after sorting.
(d) Display the total number of comparisons and swaps (if applicable) performed by the
chosen algorithm.

## (a) Data Structures
* **Dynamic Array**: The program uses "malloc" to allocate an integer array of size `N` at runtime.
* **Counters**: Two "long long" variables ("comparisons" and "swaps") are implemented to measure algorithm efficiency.

## (b) Key Functions
* **Bubble/Selection/Insertion Sort**: Standard $O(n^2)$ algorithms implemented to demonstrate basic sorting logic.
* **Merge Sort**: An $O(n \log n)$ recursive algorithm showcasing divide-and-conquer.
* **"rand()" and "srand()"**: Used to generate non-deterministic integers in the range [1, 1000].

## (c) main() Organization
1. **Setup**: Allocates memory and fills the array with random numbers.
2. **Algorithm Selection**: A "switch" or "if-else" block directs the program to the user's chosen sort.
3. **Execution**: The chosen function sorts the data while incrementing global counters.
4. **Cleanup**: Prints results and uses "free()" to release the dynamic memory.

## (d) Sample Run
**Input N:** 5
**Choice:** 2 (Selection Sort)

**Output:**
```text
Original: 150 2 999 45 12
Sorted: 2 12 45 150 999
Comparisons: 10
Swaps/Moves: 4
```