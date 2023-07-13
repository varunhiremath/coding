#!/usr/bin/python3

import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
import pandas as pd

#plt.style.use('classic')
sns.set()

# Create some data
rng = np.random.RandomState(0)
x = np.linspace(0, 10, 500)
y = np.cumsum(rng.randn(500, 6), 0)

# Plot the data with Matplotlib defaults
plt.figure(1)
plt.plot(x, y)
plt.legend('ABCDEF', ncol=2, loc='upper left');
plt.savefig("images/sns_styleplot.png")

# create multivariate data
data = np.random.multivariate_normal([0, 0], [[5, 2], [2, 2]], size=2000)
data = pd.DataFrame(data, columns=['x', 'y'])

plt.figure(2)
sns.kdeplot(data['x'],fill=True)
plt.savefig("images/sns_kdeplot.png")

#plt.figure(3)
sns.displot(data=data, x="x", y="y", kind='kde')
plt.savefig("images/sns_displot.png")

plt.figure(4)
sns.histplot(data['x'])
plt.savefig("images/sns_hisplot.png")

#plt.figure(5)
sns.jointplot(data, x="x", y="y", kind='reg')
plt.savefig("images/sns_jointplot.png")

#plt.figure(6)
sns.pairplot(data)
plt.savefig("images/sns_pairplot.png")

#plt.figure(7)
tips = sns.load_dataset('tips')
tips['pct'] = tips['tip']/tips['total_bill']*100.0
grid = sns.FacetGrid(tips, row="sex", col="time", margin_titles=True)
#grid.map(sns.kdeplot, "pct");
grid.map(sns.histplot, "pct")
plt.savefig("images/sns_facetgrid.png")

#plt.figure(8)
g = sns.catplot(data=tips, x="day", y="total_bill", hue="sex", kind="box")
plt.savefig("images/sns_catplot.png")

plt.show()
