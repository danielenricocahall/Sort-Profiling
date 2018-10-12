import os
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import numpy as np

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

### Generate the plot
plt.legend(loc='upper left')
plt.xlabel('N (number of elements)')
plt.ylabel('Time (s)')
plt.title('Profiling Results (Unsorted)')
plt.show()
