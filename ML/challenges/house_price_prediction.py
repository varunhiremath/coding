#!/usr/bin/python3

import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import pandas as pd

import scipy.stats as stats
from scipy.special import boxcox1p
from scipy.stats import boxcox_normmax

from sklearn.compose import make_column_transformer
from sklearn.ensemble import RandomForestRegressor
from sklearn.ensemble import GradientBoostingRegressor
from sklearn.linear_model import LinearRegression
from sklearn.linear_model import Ridge
from sklearn.linear_model import SGDRegressor
from sklearn.metrics import mean_squared_error
from sklearn.model_selection import train_test_split
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import OneHotEncoder
from sklearn.preprocessing import PolynomialFeatures
from sklearn.preprocessing import StandardScaler, RobustScaler
from sklearn.tree import DecisionTreeRegressor

from xgboost import XGBRegressor
#from lightgbm import LGBMRegressor
#from mlxtend.regressor import StackingCVRegressor

# use sns style
sns.set()

# read data
train_file_path = "../data/house_price/train.csv"
test_file_path = "../data/house_price/test.csv"

train_df = pd.read_csv(train_file_path)
test_df = pd.read_csv(test_file_path)

plt.figure()
plt.plot(train_df['YrSold'], train_df['SalePrice'],'o')
plt.show()

# fill na values
fill_na_values = {}
fill_na_values["PoolQC"] = "No Pool"
fill_na_values["Fence"] = "No Fence"
fill_na_values["Alley"] = "No Alley Access"
fill_na_values["MiscFeature"] = "None"
fill_na_values["FireplaceQu"] = "No Fireplace"
fill_na_values["MasVnrType"] = "None"
fill_na_values["MasVnrArea"] = 0
fill_na_values["Exterior1st"] = "Other"
fill_na_values["Exterior2nd"] = "Other"
fill_na_values["Electrical"] = "SBrkr"
fill_na_values["KitchenQual"] = "TA"
fill_na_values["Functional"] = "Typ"
fill_na_values["SaleType"] = "Oth"


garage_qual_features = ["GarageType", "GarageQual", "GarageCond", "GarageFinish"]
for feature in garage_qual_features:
    fill_na_values[feature] = "No Garage"

garage_num_features = ["GarageYrBlt", "GarageCars", "GarageArea"]
for feature in garage_num_features:
    fill_na_values[feature] = 0

bsmt_features = ['BsmtQual', 'BsmtCond', 'BsmtExposure', 'BsmtFinType1', 'BsmtFinType2']
for feature in bsmt_features:
    fill_na_values[feature] = "No Basement"

bsmt_num_features = ["BsmtFinSF1", "BsmtFinSF2", "TotalBsmtSF", "BsmtUnfSF","BsmtFullBath","BsmtHalfBath"]
for feature in bsmt_num_features:
    fill_na_values[feature] = 0

def process_data(data, na_values):
    data.fillna(na_values, inplace=True)

    data['Utilities'].fillna(data['Utilities'].mode()[0], inplace=True)
    data['LotFrontage'] = data.groupby('Neighborhood')['LotFrontage'].transform(lambda x: x.fillna(x.median()))
    data['MSZoning'] = data.groupby('MSSubClass')['MSZoning'].transform(lambda x: x.fillna(x.mode()[0]))

    MSSUbCLass = {
    20: "1-STORY 1946 & NEWER ALL STYLES",
    30: "1-STORY 1945 & OLDER",
    40: "1-STORY W/FINISHED ATTIC ALL AGES",
    45: "1-1/2 STORY - UNFINISHED ALL AGES",
    50: "1-1/2 STORY FINISHED ALL AGES",
    60: "2-STORY 1946 & NEWER",
    70: "2-STORY 1945 & OLDER",
    75: "2-1/2 STORY ALL AGES",
    80: "SPLIT OR MULTI-LEVEL",
    85: "SPLIT FOYER",
    90: "DUPLEX - ALL STYLES AND AGES",
    120: "1-STORY PUD (Planned Unit Development) - 1946 & NEWER",
    150: "1-1/2 STORY PUD - ALL AGES",
    160: "2-STORY PUD - 1946 & NEWER",
    180: "PUD - MULTILEVEL - INCL SPLIT LEV/FOYER",
    190: "2 FAMILY CONVERSION - ALL STYLES AND AGES",
    }


    OverallQualCond = {
    10: "Very Excellent",
    9: "Excellent",
    8: "Very Good",
    7: "Good",
    6: "Above Average",
    5: "Average",
    4: "Below Average",
    3: "Fair",
    2: "Poor",
    1: "Very Poor",
    }

    data.replace({"OverallQual": OverallQualCond, "OverallCond": OverallQualCond,"MSSubClass": MSSUbCLass}, inplace=True)

    data['MoSold'] = data['MoSold'].astype(str)

process_data(train_df, fill_na_values)
process_data(test_df, fill_na_values)

def null_values(data):
    return data.isna().sum().values.sum()

print("Number of null values in train data = ", null_values(train_df))
print("Number of null values in test data = ", null_values(train_df))


def normalize_numeric_features(data):
    numeric_features = data.select_dtypes(include=np.number).columns
    skew_features = data[numeric_features].apply(lambda x: stats.skew(x)).sort_values(ascending=False)
    high_skew_features = skew_features[skew_features > 0.5]
    print(high_skew_features.index)
    for feature in high_skew_features.index:
        data[feature] = boxcox1p(data[feature], boxcox_normmax(data[feature] + 1))
    return data

#train_df = normalize_numeric_features(train_df)
#test_df = normalize_numeric_features(test_df)

categorical_features = train_df.select_dtypes(exclude=np.number).columns
enc = OneHotEncoder(sparse_output=False, handle_unknown="ignore")
transformer = make_column_transformer((enc, categorical_features), remainder='passthrough')

transformed = transformer.fit_transform(train_df[categorical_features])
enc_data = pd.DataFrame(transformed, columns=transformer.get_feature_names_out(), index=train_df.index)
train_enc_df = pd.concat([train_df.drop(categorical_features,axis=1),enc_data],axis=1)


transformed = transformer.transform(test_df[categorical_features])
enc_data = pd.DataFrame(transformed, columns=transformer.get_feature_names_out(), index=test_df.index)
test_enc_df = pd.concat([test_df.drop(categorical_features,axis=1),enc_data],axis=1)

print(train_enc_df.shape)
print(test_enc_df.shape)

# extract data
X = train_enc_df.drop(columns=["Id", "SalePrice"])
y = np.log1p(train_enc_df['SalePrice'])

# normalize data
scaler = RobustScaler()
X = scaler.fit_transform(X)

# split data
X_train, X_valid, y_train, y_valid = train_test_split(X, y, test_size=0.4, random_state=99)
y_real = np.expm1(y_valid)

# Random Forest
rfr_model = RandomForestRegressor()
rfr_model.fit(X_train, y_train)

y_pred = np.expm1(rfr_model.predict(X_valid))
mse_rfr = mean_squared_error(y_pred, y_real)

plt.figure(1)
plt.plot(y_real, y_pred,'o', label="MSE = %e" % mse_rfr)
plt.plot(y_real, y_real,'-')
plt.title('RandomForestRegressor')
plt.legend()

#xgboost
xgb_model = XGBRegressor(learning_rate=0.01, n_estimators=3460,
                         max_depth=3, min_child_weight=0,
                         gamma=0, subsample=0.7,
                         colsample_bytree=0.7,
                         objective='reg:squarederror', nthread=-1,
                         scale_pos_weight=1, seed=27,
                         reg_alpha=0.00006)


xgb_model.fit(X_train, y_train)

y_pred = np.expm1(xgb_model.predict(X_valid))
mse_xgb = mean_squared_error(y_pred, y_real)

plt.figure(2)
plt.plot(y_real, y_pred,'o', label="MSE = %e" % mse_xgb)
plt.plot(y_real, y_real,'-')
plt.title('XGBRegressorRegressor')
plt.legend()

#GradientBoostingModel
gbr_model = GradientBoostingRegressor(n_estimators=3000, learning_rate=0.05, max_depth=4, max_features='sqrt', min_samples_leaf=15, min_samples_split=10, loss='huber', random_state =42)

gbr_model.fit(X_train, y_train)

y_pred = np.expm1(gbr_model.predict(X_valid))
mse_gbr = mean_squared_error(y_pred, y_real)
print(mse_gbr)

plt.figure(3)
plt.plot(y_real, y_pred,'o', label="MSE = %e" % mse_gbr)
plt.plot(y_real, y_real,'-')
plt.title('GradientBoostingRegressor')
plt.legend()

# LGBMRegressor
lgbm_model = LGBMRegressor(objective='regression',
                         num_leaves=4,
                         learning_rate=0.01,
                         n_estimators=5000,
                         max_bin=200,
                         bagging_fraction=0.75,
                         bagging_freq=5,
                         bagging_seed=7,
                         feature_fraction=0.2,
                         feature_fraction_seed=7,
                         verbose=-1)

lgbm_model.fit(X_train, y_train)

y_pred = np.expm1(lgbm_model.predict(X_valid))
mse_lgbm = mean_squared_error(y_pred, y_real)

plt.figure(4)
plt.plot(y_real, y_pred,'o', label="MSE = %e" % mse_lgbm)
plt.plot(y_real, y_real,'-')
plt.title('LGBMRegressor')
plt.legend()

# StackingCVRegressor
stack_model = StackingCVRegressor(regressors=(rfr_model, xgb_model, gbr_model, lgbm_model),
                                  meta_regressor=xgb_model,
                                  use_features_in_secondary=True)

stack_model.fit(X_train, y_train)

y_pred = np.expm1(stack_model.predict(X_valid))
mse_stack = mean_squared_error(y_pred, y_real)

plt.figure(4)
plt.plot(y_real, y_pred,'o', label="MSE = %e" % mse_stack)
plt.plot(y_real, y_real,'-')
plt.title('StackingCVRegressor')
plt.legend()

plt.show()
