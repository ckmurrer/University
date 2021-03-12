'''
    Name: Cody Murrer
    Project: Machine Learning - Linear Regression (uses a dataset of the tesla stock market data that uses the market high values to predict the market closing price)
    Date: 11/20/20
'''
# used for data manipulation
import pandas as pd
# used for array operations
import numpy as np
# used for its machine learning algorithm and data handeling
from sklearn import linear_model
# utility package used to help calculate the loss and score of the algorithm
from sklearn import metrics
# used to split the used dataset into two datasets training and testing
from sklearn.model_selection import train_test_split
# used to plot the scatterplot for a visual display of the predicted outputs
import matplotlib.pyplot as plt
# opens and reads the dataset
dataset = pd.read_csv('TSLA_DataSet_yearly.csv')
# sets specific coloumns in the dataset to the x(independent) and y(dependent) axis
x = dataset['High'].values.reshape(-1,1)
y = dataset['Close'].values
# splits the dataset in an 80%-20% split
# model is trained with 80% of the data from the dataset and tested with 20% of the dataset
xTrainingData, xTestingData, yTrainingData, yTestingData = train_test_split(x,y,test_size=.2)
# sets lin model equal to the linear regression method from the sklearn import
linModel = linear_model.LinearRegression()
# creates a model based off of the training data 
model = linModel.fit(xTrainingData,yTrainingData)
# prediction of the dependent variable using the independent variables test data
yPredict = model.predict(xTestingData)
# comparison of the target values vs the predicted vales
compare = pd.DataFrame({'Actual':yTestingData, 'Predicted':yPredict})
print(compare)
# intercept of predicted model
print('Intercept', model.intercept_)
# coefficent value of predicted model
print('Coefficent', model.coef_)
# standard deviation of the prediction errors
print('RMSE (Root Mean Squared Error)', np.sqrt(metrics.mean_squared_error(yTestingData,yPredict)))
# creates a scatter plot based on the x axis as market high and y axis as market close
# points on the graph are created from the xTestingData values and the yPredict values 
plt.style.use('default')
plt.style.use('ggplot')
fig, graph = plt.subplots(figsize=(8,4))
# sets the x and y axis of the graph and plots its data
graph.plot(xTestingData,yPredict, color='k', label='Regression model')
graph.scatter(x,y,edgecolor='k',facecolor='grey', alpha=0.7,label='Sample data')
# sets the x and y axis labels and creates a legend for the graph
graph.set_ylabel('Market close price($)',fontsize=14)
graph.set_xlabel('Market high price($)',fontsize=14)
graph.legend(facecolor='white', fontsize=11)
# displays the text giving the formula for the trend line
# if else to change the equation on the graph based on if the intercept is positive or negative
if model.intercept_ > 0:
    graph.text(0.55,0.15, '$y = %.2f x + %.2f $' % (model.coef_[0], abs(model.intercept_)), fontsize=17, transform=graph.transAxes)
else:
    graph.text(0.55,0.15, '$y = %.2f x - %.2f $' % (model.coef_[0], abs(model.intercept_)), fontsize=17, transform=graph.transAxes)
# displays the scatterplot
fig.tight_layout()
plt.show()