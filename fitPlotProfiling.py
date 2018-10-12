import os
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import numpy as np


def log(n, k, m):
    return k*n*np.log(n) + m*n

def square(n, k):
    return k*n^2

### Set your path to the folder containing the .csv files
PATH = './' # Use your path

### Fetch all files in path
fileNames = os.listdir(PATH)
mode = "_unsorted.csv"
### Filter file name list for files ending with .csv
fileNames = [file for file in fileNames if mode in file]

### Loop over all files
for file in fileNames:

    ### Read .csv file and append to list
    df = pd.read_csv(PATH + file,index_col = 0, usecols=[0,1])
#    df.drop(df.columns['Current/Preceding'],axis=1)
    ### Create line for every file
    plt.semilogx(df, label = file.replace(mode,''))
    x, y = zip(*[tuple(x) for x in df.to_records()])
    popt, pcov = curve_fit(log, x, y)
    plt.semilogx(x, log(x, *popt), '*', label = file.replace(mode, '') + "_fit " + '%5.3f n log n + %5.3f n' % tuple(popt))


### Generate the plot
plt.legend(loc='upper left')
plt.xlabel('N (number of elements)')
plt.ylabel('Time (s)')
plt.title('Profiling Results (Unsorted)')
plt.show()
