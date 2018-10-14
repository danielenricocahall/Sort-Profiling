# Advanced-DAA-Sort-Profiling
Implementation and profiling of various sorting algorithms, including:

* Bubble Sort
* Insertion Sort
* Selection Sort
* Heap Sort
* Merge Sort (varying termination points)
* BST Sort
  * placing all elements in a binary search tree, and performing in-order traversal
 
 
All implementations are in C++, as that is the language I am most familiar with. The algorithms are contained in an object which implements the Sorter interface, so extending this project to support other sorts (such as Gnome, Tim, Shell, or Stooge) should be fairly trivial.
 
 To demonstrate the relative strengths and weaknesses of each algorithm, they were tested under 3 conditions:
 * Completely sorted list
 * Half sorted list
 * Unsorted list
 
 To ensure robustness in the estimate, each scenario was tested 20 times for each sort, and the average time across the 20 runs was recorded (Monte Carlo testing). The testbed can be found in Driver.cpp. The results of these tests can be found in the Results folder in their respective csv files. The first column, labeled 'N', is the input size, and the second column column, labeled 'Average Time (s)', represents the average time (in seconds) taken for the algorithm to finish sorting. The third column labeled "Current / Preceding" measures the ratio between the average times for different sizes inputs. This ratio ensures the results fit the theoretical estimate (e.g; for an n^2 algorithm, increasing the input size by a factor of 10 should increase the Current/Preceding ratio by 100, whereas it should be near linear for an n log n). Profiling and ratio plots generated using Pyplot can also be found in the Results folder, and seen below. Best fit lines were computed using scipy's curve_fit function. The scripts used to generate these plots can be found in the Scripts folder.
 
 ## Profiling Results ##
![alt text](https://github.com/danielenricocahall/Advanced-DAA-Sort-Profiling/blob/master/Results/Completely_Sorted_Profiling_Results.png)
 ![alt text](https://github.com/danielenricocahall/Advanced-DAA-Sort-Profiling/blob/master/Results/Unsorted_Profiling_Results.png)
 
 ## Current/Preceding Results ##
![alt text](https://github.com/danielenricocahall/Advanced-DAA-Sort-Profiling/blob/master/Results/Completely_Sorted_Ratio_Results.png)
 ![alt text](https://github.com/danielenricocahall/Advanced-DAA-Sort-Profiling/blob/master/Results/Unsorted_Ratio_Results.png)
 
 ## Conclusions ##
 If you have any questions, feel free to email me at danielenricocahall@gmail.com.
 
