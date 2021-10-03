import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import sklearn

data = pd.read_csv('/content/loan-train.csv')
data.head()

data.shape

data.dtypes

data.corr()

p = data['Property_Area'].values
p

data.isnull().sum()

from sklearn.preprocessing import LabelEncoder
le = LabelEncoder()

data.Property_Area=le.fit_transform(data.Property_Area)
data.Property_Area.head(20)

data.Loan_Status = le.fit_transform(data.Loan_Status)
data.Loan_Status.head(20)

new_data = data.replace(np.NaN,{'LoanAmount':100,'Loan_Amount_Term':360.0,'Credit_History':1.0})
new_data

new_data.isnull().sum()

sns.relplot(x='ApplicantIncome',y='LoanAmount',hue='Credit_History',data=new_data)

a = new_data.drop(['Loan_ID','Gender','Married','Dependents','Education'],axis='columns')
print(a)

b = new_data['Loan_Status']
print(b)

from sklearn.model_selection import train_test_split
a_train,a_test,b_train,b_test = train_test_split(a,b,test_size=0.5,random_state=2)

print(len(a_train))
print(len(b_test))

from sklearn.tree import DecisionTreeClassifier

clf = DecisionTreeClassifier(random_state=5)
clf.fit(a_train,b_train)

b_pred=clf.predict(a_test)

b_pred

from sklearn.metrics import accuracy_score
accuracy=accuracy_score(b_test)

print('accuracy is',accuracy*100,'%')

from sklearn.metrics import confusion_matrix

cm=np.array(confusion_matrix(y_test,y_pred))

cm

from sklearn import tree

tree.plot_tree(clf)

plt.figure()

tree.plot_tree(clf,filled=True)  

plt.savefig('tree.jpg',format='jpg',bbox_inches = "tight")
