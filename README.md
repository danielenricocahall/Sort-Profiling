# Advanced-DAA-Sort-Profiling
Implementation and profiling of various sorting algorithms, including:

* Bubble Sort
* Insertion Sort
* Selection Sort
* Heap Sort
* Merge Sort (varying termination points)
* BST Sort
  * placing all elements in a binary search tree, and performing in-order traversal
 
 To demonstrate the relative strengths and weaknesses of each algorithm, they were tested under 3 conditions:
 * Completely sorted list
 * Half sorted list
 * Unsorted list
 
 To ensure robustness in the estimate, each scenario was tested 20 times for each sort, and the average across the 20 runs was
 recorded (Monte Carlo testing). The testbed can be found under Driver.cpp. The results of these tests can be found in the Results folder in their respective csv files. Plots generated using Pyplot can also be found in the Results folder, and seen below. Best fit lines were computed using scipy's curve_fit function.
![alt text](https://github.com/danielenricocahall/Advanced-DAA-Sort-Profiling/blob/master/Completely_Sorted_Results.png)
![alt text](https://github.com/danielenricocahall/Advanced-DAA-Sort-Profiling/blob/master/Half_Sorted_Results.png)
 ![alt text](https://github.com/danielenricocahall/Advanced-DAA-Sort-Profiling/blob/master/Unsorted_Results.png)

 
 All implementations are in C++, as that is the language I am most familiar with. The algorithms are contained in an object which implements the Sorter interface, so extending this project to support other sorts (such as Gnome, Tim, Shell, or Stooge) should be fairly trivial.
 
 If you have any questions, feel free to email me at danielenricocahall@gmail.com.
 
