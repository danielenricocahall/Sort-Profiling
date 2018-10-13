import os
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import numpy as np


PATH = '../Results/' 

### Fetch all files in path
fileNames = os.listdir(PATH)
mode = "unsorted"
### Filter file name list for files ending with .csv
fileNames = [file for file in fileNames if mode in file]

### Loop over all files
for file in fileNames:

    ### Read .csv file and append to list
    df = pd.read_csv(PATH + file,index_col = 0, usecols=[0,2])
#    df.drop(df.columns['Current/Preceding'],axis=1)
    ### Create line for every file
    label = file.replace("_" + mode + ".csv", '')
    plt.semilogx(df, label = label)

### Generate the plot
plt.legend(loc='upper right')
plt.xlabel('N (number of elements)')
plt.ylabel('Current/Preceding')
plt.title('Ratio Results (' + mode.capitalize() + ')')
plt.show()
