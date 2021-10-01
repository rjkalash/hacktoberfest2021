#include <iostream>

using namespace std;

class Element{
    public:
        int row;
        int column;
        int value;
};

class Sparse{
    private:
        int total_rows;
        int total_columns;
        int nNonZeroes;
        Element *elements;
    public:
        Sparse(int total_rows, int total_columns, int nNonZeroes){
            this->total_rows = total_rows;
            this->total_columns = total_columns;
            this->nNonZeroes = nNonZeroes;
            this->elements = new Element[nNonZeroes];
        }

        ~Sparse(){
            delete[] elements;
        }

        void create_matrix();
        void print();
        void sort();
        void swap(Element &a, Element &b);
        Sparse operator+(Sparse &matrix2);
};

void Sparse::create_matrix(){
    for(int i = 0; i < nNonZeroes; i++){
        cout << "Enter the non zero term " << i + 1 << endl;
        cout << "Enter the row of the non zero term" << endl;
        cin >> elements[i].row;

        cout << "Enter the column of the non zero term" << endl;
        cin >> elements[i].column;

        cout << "Enter the value of the non zero term" << endl;
        cin >> elements[i].value;
    }
}
void Sparse::print(){
    for(int i = 0; i < nNonZeroes; i++){
        cout << elements[i].row << " " << elements[i].column << " " << elements[i].value << endl;
    }
}

void Sparse::sort(){
    for(int i = 0; i < nNonZeroes; i++){
        for(int j = i + 1; j < nNonZeroes; j++){
            if(elements[i].row > elements[j].row){
                swap(elements[i], elements[j]);
            }
            if(elements[i].row == elements[j].row && elements[i].column > elements[j].column){
                swap(elements[i], elements[j]);
            }
        }
    }
}

void Sparse::swap(Element &a, Element &b){
    Element temp = a;
    a = b;
    b = temp;
}

// addition
Sparse Sparse::operator+(Sparse &matrix2){
    // adding the triplets
    // assuming the matrices are sorted

    //check if the number of rows and columns are same
    if(total_rows != matrix2.total_rows || total_columns != matrix2.total_columns){
        cout << "The matrices are not of same size" << endl;
        return Sparse(0,0,0);
    }

    // now add
    int nNonZeroes2 = matrix2.nNonZeroes;
    Element *elements2 = matrix2.elements;
    int i = 0, j = 0, k = 0;

    int result_nonzeroes = 0;
    Sparse *result = new Sparse(total_rows, total_columns, nNonZeroes + nNonZeroes2);

    while(i < this->nNonZeroes && j < nNonZeroes2){
        // if both the column and row are equal
        if(elements[i].row == elements2[j].row && elements[i].column == elements2[j].column){
            // simply add
            result->elements[k].row = elements[i].row;
            result->elements[k].column = elements[i].column;
            result->elements[k].value = elements[i].value + elements2[j].value;
            i++;
            j++;
            k++;
        }

        // if the matrix 1 row is greater than matrix 2 row
        else if(elements[i].row > elements2[j].row){
            // this means that the second matrix will be copied and the second matrix and result will progress
            result->elements[k].row = elements2[j].row;
            result->elements[k].column = elements2[j].column;
            result->elements[k].value = elements2[j].value;
            j++;
            k++;
        }
        // if the matrix 2 row is greater than matrix 1 row
        else if(elements[i].row < elements2[j].row){
            // this means that the first matrix will be copied and the first matrix and result will progress
            result->elements[k].row = elements[i].row;
            result->elements[k].column = elements[i].column;
            result->elements[k].value = elements[i].value;
            i++;
            k++;
        }

        // if the rows are equal but not the columns
        else if(elements[i].row == elements2[j].row && elements[i].column != elements2[j].column){
            // if the column of the first matrix is greater than the column of the second matrix
            if(elements[i].column > elements2[j].column){
                // copy the second matrix
                result->elements[k].row = elements2[j].row;
                result->elements[k].column = elements2[j].column;
                result->elements[k].value = elements2[j].value;
                j++;
                k++;
            }
            // if the column of the second matrix is greater than the column of the first matrix
            else if(elements[i].column < elements2[j].column){
                // copy the first matrix
                result->elements[k].row = elements[i].row;
                result->elements[k].column = elements[i].column;
                result->elements[k].value = elements[i].value;
                i++;
                k++;
            }
        }
    }
    // left over terms of matrix 1
    while(i < this->nNonZeroes){
        result->elements[k].row = elements[i].row;
        result->elements[k].column = elements[i].column;
        result->elements[k].value = elements[i].value;
        i++;
        k++;
    }
    // left over terms of matrix 2
    while(j < nNonZeroes2){
        result->elements[k].row = elements2[j].row;
        result->elements[k].column = elements2[j].column;
        result->elements[k].value = elements2[j].value;
        j++;
        k++;
    }
    
    result->nNonZeroes = k;

    return *result;
}

int main(){
    int total_rows, total_columns, nNonZeroes;
    cout << "Enter the total number of rows" << endl;
    cin >> total_rows;

    cout << "Enter the total number of columns" << endl;
    cin >> total_columns;

    cout << "Matrix 1 " << endl;
    cout << "Enter the number of non zero terms" << endl;
    cin >> nNonZeroes;

    Sparse matrix1(total_rows, total_columns, nNonZeroes);
    matrix1.create_matrix();
    cout << " Matrix1 :" << endl;
    matrix1.print();

    cout << "Matrix 2 " << endl;
    cout << "Enter the number of non zero terms" << endl;
    cin >> nNonZeroes;

    Sparse matrix2(total_rows, total_columns, nNonZeroes);
    matrix2.create_matrix();
    cout << " Matrix2 :" << endl;
    matrix2.print();

    // sort both matrices
    matrix1.sort();
    matrix2.sort();
    
    // addition
    cout << "Addition" << endl;
    Sparse result = matrix1 + matrix2;
    result.print();

    return 0;
}
