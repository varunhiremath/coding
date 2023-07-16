# Linear Models

| Preprocessing |Import | Syntax | Description |
|---------------|-------|--------|-------------|
| train_test_split | from sklearn.model_selection import train_test_split | X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.4) | Split data into two sets |
| StandardScalar|from sklearn.preprocessing import StandardScaler| scaler = StandardScaler() <br> X = scaler.fit_transform(X) | Scales the features |
| PolynomialFeatures | from sklearn.preprocessing import PolynomialFeatures | poly = PolynomialFeatures(degree=2) <br> poly.fit_transform(X) | Add polynomial features |


| Model	 | Inport	| Syntax | Description	| Links	|
|--------|--------------|--------|--------------|-------|
| LinearRegression| from sklearn.linear_model import LinearRegression | model = LinearRegression() <br> model.fit(X,y) <br> model.predict(X_test) | Least-squares based linear regression | [link](https://scikit-learn.org/stable/modules/linear_model.html#ordinary-least-squares) |
| SGDRegessor | from sklearn.linear_model import SGDRegressor | model = SGDRegressor() <br> model.fit(X,y) <br> model.predict(X_test) | Linear regression using Gradient Descent      | [link](https://scikit-learn.org/stable/modules/generated/sklearn.linear_model.SGDRegressor.html#sklearn.linear_model.SGDRegressor) |
| Ridge	      | from sklearn.linear_model import Ridge | model = Ridge(alpha=0.1) <br> model.fit(X,y) <br> model.predict(X_test) | Regularized linear regression	| [link](https://scikit-learn.org/stable/modules/linear_model.html#ridge-regression-and-classification) |
