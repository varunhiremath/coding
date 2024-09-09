import pandas as pd
import numpy as np
import plotly.express as px
import plotly.graph_objects as go

numberofbicyclessold_array=[50,100,40,150,160,70,60,45]
months_array=["Jan","Feb","Mar","April","May","June","July","August"]

fig=go.Figure()
fig.add_trace(go.Scatter(x=months_array, y=numberofbicyclessold_array, mode='lines', marker=dict(color='green')))

fig.update_layout(title='Bicycle Sales', xaxis_title='Months', yaxis_title='Number of Bicycles Sold')
fig.show()

score_array=[80,90,56,88,95]
grade_array=['Grade 6','Grade 7','Grade 8','Grade 9','Grade 10']

fig = px.bar( x=grade_array, y=score_array, title='Pass Percentage of Classes')
fig.show()


airline_data =  pd.read_csv("airline_data.csv",
                            encoding = "ISO-8859-1",
                            dtype={'Div1Airport': str, 'Div1TailNum': str,
                                   'Div2Airport': str, 'Div2TailNum': str})

data = airline_data.sample(n=500, random_state=42)

## Write your code here
fig = px.sunburst(
    data,
    values='Flights',
    path=['Month','DestStateName'],
    title='Flight Distribution Hierarchy'
)
fig.show()

fig = px.pie(data, values="Flights", names="Flights", title="Pie Chart of Flights")

fig.show()
