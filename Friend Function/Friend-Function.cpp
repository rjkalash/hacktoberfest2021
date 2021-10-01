// Friend Function - Sharoni Bose

#include<iostream>
using namespace std;
class B;
class A
{
	private:
        	int num1;
    	public:
		void inputNumber();
        	void displayNumber();
        	friend void swap(A *, B *);
};
class B
{
	private:
        	int num2;
    	public:
		void inputNumber();
        	void displayNumber();
        	friend void swap(A *, B *);
};
void A::inputNumber()
{
	cout<<"Enter Value of Class A: ";
	cin>>num1;
}
void B::inputNumber()
{
	cout<<"Enter Value of Class B: ";
	cin>>num2;
}
void swap(A *ob1, B *ob2)
{
        int temp;
        temp = ob1->num1;
        ob1->num1 = ob2->num2;
        ob2->num2 = temp;
}
void A::displayNumber()
{
	cout<<"\nSwapped Value of Class A: "<<num1;
	cout<<"\n";
}
void B::displayNumber()
{
	cout<<"Swapped Value of Class B: "<<num2;
	cout<<"\n";
}
int main()
{
	A ob1;
	B ob2;
	ob1.inputNumber();
	ob2.inputNumber();
        swap(&ob1, &ob2);
        ob1.displayNumber();
	ob2.displayNumber();
        return 0;
}