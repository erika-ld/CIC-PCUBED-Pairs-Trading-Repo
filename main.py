import statsmodels.api as sm
import numpy as np
import pandas as pd
from patsy import dmatrices
import matplotlib.pyplot as plt 

def main():
    # reading data from the csv
    # this csv contains both natural log (to normalize) of adj close price 
    # from each data set made through excel
    df = pd.read_csv('CointegrationTest_Data.csv')
    df.columns = ['Date','LNVGF_Adj_Close','MSI_Adj_Close']
    # checking
    # print(df.head())
    y, X = dmatrices('LNVGF_Adj_Close ~ MSI_Adj_Close', data=df, return_type='dataframe')
    # dmatrices is apart of the pasty library
    # constructs/return 2 matrices 
    # print(y) # the lenovo stock in this case is the outcome variable(y)
    # print(X) # the motorala stock is the predictor(x)
    # in this case, in order to use the statsmodel api, we have to have 
    # the return type as a dataframe
    model = sm.OLS(y, X).fit()
    print(model.summary())
    return 0

if __name__ == "__main__":
    main()