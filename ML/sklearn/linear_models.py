#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.preprocessing import PolynomialFeatures
from sklearn.pipeline import Pipeline
from sklearn.linear_model import LinearRegression
from sklearn.linear_model import SGDRegressor
from sklearn.linear_model import Ridge

# use sns style
sns.set()

# read data
data = pd.read_csv('../data/house_price/train.csv')

# drop na columns
data = data.dropna(axis=1)

target = 'SalePrice'
sale_price_corr = data.corrwith(data[target],numeric_only=True)
top_corr_cols = sale_price_corr.sort_values(ascending=False)[1:11]

# pick top features
features = top_corr_cols.index

X = data[features]
y = data[target]

# normalize data
scaler = StandardScaler()
X = scaler.fit_transform(X)

# split data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.4)

# Linear Model
lin_reg_model = LinearRegression()
lin_reg_model.fit(X_train,y_train)

y_lin_reg = lin_reg_model.predict(X_test)

plt.figure(1)
plt.plot(y_test, y_lin_reg,'o')
plt.plot(y_test, y_test,'-')
plt.title('LinearRegression')
plt.savefig('images/LinearRegression.png')

# SGD Regressor
sgd_model = SGDRegressor()
sgd_model.fit(X_train, y_train)

y_sgd = sgd_model.predict(X_test)

plt.figure(2)
plt.plot(y_test, y_sgd,'o')
plt.plot(y_test, y_test,'-')
plt.title('SGDRegressor')
plt.savefig('images/SGDRegressor.png')

# Ridge Model
ridge_model = Ridge(alpha=0.1)
ridge_model.fit(X_train,y_train)

y_ridge = ridge_model.predict(X_test)

plt.figure(3)
plt.plot(y_test, y_ridge,'o')
plt.plot(y_test, y_test,'-')
plt.title('Ridge')
plt.savefig('images/Ridge.png')

# Polynomial Regression
poly_model = Pipeline([('poly', PolynomialFeatures(degree=2)),
                       ('linear', LinearRegression(fit_intercept=False))])
poly_model.fit(X_train,y_train)

y_poly = poly_model.predict(X_test)

plt.figure(4)
plt.plot(y_test, y_poly,'o')
plt.plot(y_test, y_test,'-')
plt.title('PolynomialRegression')
plt.savefig('images/PolynomialRegression.png')


plt.show()
