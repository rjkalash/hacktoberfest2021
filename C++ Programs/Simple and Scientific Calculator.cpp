#include<iostream>
#include<cmath>
using namespace std;

class SimpleCalculator
{
public:

	float a;
	float b;

void getdataSimple()
	{
		cout <<"Enter the value of a :" << endl;
		cin >> a;
		cout << "Enter the value of b :" << endl;
		cin >> b;
	}

void performOperation()
	{
		cout << "Value of a+b is " << a+b << endl;
		cout << "Value of a-b is " << a-b << endl;
		cout << "Value of a*b is " << a*b << endl;
		cout << "Value of a/b is " << a/b << endl;
	}
};

class ScientificCalculator 
	{
int a, b;

    public:
        void getDataScientific()
        {
            cout << "Enter the value of a" << endl;
            cin >> a;
            cout << "Enter the value of b" << endl;
            cin >> b;
        }

void performOperationScientific()
		{
			cout << "The Value of sin(a) is " << sin(a) << endl;
			cout << "The Value of cos(a) is " << cos(a) << endl;
			cout << "The Value of tan(a) is " << tan(a) << endl;
			cout << "The Value of exp(a) is " << exp(a) << endl;
		}

	};

class HybridCalculator : public SimpleCalculator,public ScientificCalculator
	{

	};

int main()
{
	HybridCalculator calc;
		calc.getdataSimple();
		calc.performOperation();
		calc.getDataScientific();
		calc.performOperationScientific();

	return 0;
}
