#include <iostream>
using namespace std;

class Element{
    public:
        int i; // row
        int j; // column
        int value; // value
};

class Sparse{
    private:
        int columns; // total number of columns in the matrix
        int rows; // total number of rows in the matrix
        int number; // total number of non zero elements in the matrix
        Element *element;
    
    public:
        Sparse(int columns, int rows, int number){
            this->columns = columns;
            this->rows = rows;
            this->number = number;
            element = new Element[number];
        }
        ~Sparse(){
            delete[] element;
        }

    void input();
    void print();
};

void Sparse::input()
{
    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < number; i++)
    {
        cin >> element[i].i >> element[i].j >> element[i].value;
    }
}

void Sparse::print()
{
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (element[k].i == i && element[k].j == j)
            {
                cout << element[k++].value << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    int rows;
    int columns;
    int numbers;

    cout << "Enter the number of rows" << endl;
    cin >> rows;

    cout << "Enter the number of columns" << endl;
    cin >> columns;

    cout << "Enter the number of non-zero elements:" << endl;
    cin >> numbers;

    Sparse A(rows, columns, numbers);
    A.input();
    cout << "Matrix 1" << endl;
    A.print();

    return 0;
}