import os
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import numpy as np


def log(n, k, m):
    return k*n*np.log(n) + m*n

def square(n, k):
    return k*np.square(n)

def linear(n, k):
    return k*n
### Set your path to the folder containing the .csv files
PATH = './' # Use your path

### Fetch all files in path
fileNames = os.listdir(PATH)
mode = "_sorted"
### Filter file name list for files ending with .csv
fileNames = [file for file in fileNames if mode in file]

### Loop over all files
for file in fileNames:

    ### Read .csv file and append to list
    df = pd.read_csv(PATH + file,index_col = 0, usecols=[0,1])
#    df.drop(df.columns['Current/Preceding'],axis=1)
    ### Create line for every file
    label = file.replace("_" + mode + ".csv", '')
    plt.semilogx(df, label = label)
    x, y = zip(*[tuple(x) for x in df.to_records()])
    x = np.array(x)
    y = np.array(y)
    # this is disgusting, I'm so sorry
    if mode is "unsorted" or mode is "half-sorted":
        if "Merge" in file or "Heap" in file or "BST" in file:
            popt, pcov = curve_fit(log, x, y)
            plt.semilogx(x, log(x, *popt), '*', label = label + "_fit " + str(round(popt[0],12)) + ' n log n + ' + str(round(popt[1],12)) + ' n')
        elif "Bubble" in file or "Selection" in file or "Insertion" in file:
            popt, pcov = curve_fit(square, x, y)
            plt.semilogx(x, square(x, *popt), '*', label = label + "_fit " + str(round(popt[0],12)) + ' n^2')

    elif mode is "_sorted":
        print(file) 
        if "Merge" in file or "Heap" in file:
            popt, pcov = curve_fit(log, x, y)
            plt.semilogx(x, log(x, *popt), '*', label = label + "_fit " + str(round(popt[0],12)) + ' n log n + ' + str(round(popt[1],12)) + ' n')
        elif "Selection" in file or "Insertion" in file or "BST" in file:
            popt, pcov = curve_fit(square, x, y)
            plt.semilogx(x, square(x, *popt), '*', label = label + "_fit " + str(round(popt[0],12)) + ' n^2')
        elif "Bubble" in file:
            popt, pcov = curve_fit(linear, x, y)
            plt.semilogx(x, linear(x, *popt), '*', label = label + "_fit " + str(round(popt[0],12)) + ' n')
### Generate the plot
plt.legend(loc='upper left')
plt.xlabel('N (number of elements)')
plt.ylabel('Time (s)')
plt.title('Profiling Results (' + mode.capitalize() + ')')
plt.show()
