import pandas as pd
import numpy as np
import plotly.express as px
import plotly.graph_objects as go

launch = np.arange(20)
success = np.random.randint(2, size=20)
flag = []
count_1 = 0
for x in success:
    if (x==1):
        flag.append("X")
        count_1 += 1
    else:
        flag.append("Y")

print(flag)
print("count of 1 = ", count_1)

data = pd.DataFrame({'Launch':launch, 'Success':success, 'Flag':flag})
print(data)

count = data["Success"].value_counts()
fig = px.pie(data, values=count.values, names=count.index, title="Pie Chart of Success")
fig.show()
