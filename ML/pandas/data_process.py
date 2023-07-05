#!/usr/bin/python3

# Testing various pandas methods
# Using housing data from Kagle: https://www.kaggle.com/c/house-prices-advanced-regression-techniques/overview

import pandas as pd

data = pd.read_csv('../data/house_price/train.csv')

# print information
print("Information on data")
print(data.info())
print("-------------------")

# describe the data
print("Description of data")
print(data.describe())
print("-------------------")

# print starting rows
print("Top rows of data")
print(data.head())
print("-------------------")

# print column names
print("Columns of data")
print(data.columns)
print(data.columns.tolist())
print("-------------------")

# print shape (size) of data
print("Shape of the data")
print(data.shape)
print("-------------------")

print("Use of iloc, print 4th column")
print(data.iloc[:10,3])
print("-------------------")

print("Use of loc, print LotArea column")
print(data.loc[:10,"LotArea"])
print("-------------------")


# number of null values per column
print("Number of nulls per column")
print(data.isnull().sum())
print("-------------------")

# columns with null data
print("Columns with null data")
null_cols = data.columns[data.isna().any()]
print(null_cols, len(null_cols))
print("-------------------")

# remove na/null data
print("Cleaned data info")
clean_data = data.dropna(axis=1) #axis = 1 removes columns, axis = 0 removes rows
print(clean_data.head())
print(clean_data.shape)
print("-------------------")

# replace null data
print("Replace null data with specified values")
values = {}
for col in null_cols:
    values[col] = 0.0
clean_data = data.fillna(value=values)
print(clean_data.isnull().sum())
print("total na = ", clean_data.isnull().sum().values.sum())
print("-------------------")

# select columns by data type
print("Columns with datatype object")
obj_cols = data.select_dtypes(include=["object"]).columns
print(obj_cols)
print("-------------------")

# select columns by data type
print("Mode value of a column")
#print(data[obj_cols[0]].mode()[0])
print(data.mode().iloc[0,:])
print("-------------------")

# sort a column
print("Sorting data")
print(data.sort_values(by='SalePrice').head())
print(data['SalePrice'].sort_values())
print("-------------------")


# correlation
print("Compute correlation between columns")
print(data.corr())
sale_price_corr = data.corrwith(data["SalePrice"])
top_corr_cols = sale_price_corr.sort_values(ascending=False)[1:11]
print(top_corr_cols)
print("-------------------")
