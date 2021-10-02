/* A tuple is an object that can hold elements. The elements can be of differenr datatypes.
The elements of tuples are initialized as arguments in order in which they will be accesssed */

#include <iostream>
#include <tuple> //for tuple ,tuple_size(),swap(),tie(),tuple_cat()
#include <string>
using namespace std;
int main()
{
    //declaring tuple
    tuple<char, int, string, float> student;

    /* make_tuple() is used to assign tuple with values .The values passed should be in order 
    with the values declared in tuple.*/

    //Assigning value to tuple using make_tuple
    student = make_tuple('A', 7, "Akriti", 2.22);

    /*get() is used to access the tuple values and modify them.
     It accepts the index and tuple name as arguments to access a particular tuple element*/

    //Printing initial tuple values using get
    cout << "The initial values of tuple : ";
    cout << get<0>(student) << " " << get<1>(student) << " " << get<2>(student) << " " << get<3>(student) << endl;

    //using get() to change values of tuple
    get<0>(student) = 'C';
    get<3>(student) = 4.44;

    //Printing modified tuple values using get
    cout << "The modified values of tuple : ";
    cout << get<0>(student) << " " << get<1>(student) << " " << get<2>(student) << " " << get<3>(student) << endl;

    /* tuple_size :- It returns the number of elements present in tuple */

    //use of tuple_size to find size of tuple
    //Printing size of tuple
    cout << "Printing size of tuple :";
    cout << tuple_size<decltype(student)>::value << endl;

    /* The swap() swaps the elements of two different tuples*/
    //Initializing second tuple

    tuple<char, int, string, float> student1('e', 12, "Ishu", 3.33);

    //Printing second tuple values using get
    cout << "The second tuple values  : ";
    cout << get<0>(student1) << " " << get<1>(student1) << " " << get<2>(student1) << " " << get<3>(student1) << endl;

    //swapping student values with student1
    student.swap(student1);

    //Printing student values using get
    cout << "The  student : ";
    cout << get<0>(student) << " " << get<1>(student) << " " << get<2>(student) << " " << get<3>(student) << endl;

    //Printing student1 values using get
    cout << "The student1 : ";
    cout << get<0>(student1) << " " << get<1>(student1) << " " << get<2>(student1) << " " << get<3>(student1) << endl;

    /* tie() - The work of tie is to unpack the tuple values into seperate variables
     There are two variants of tie,with and without "ignore" ,the "ignore" ignores a particular
     tuple element and stops it from getting unpacked. */
    int i_val;
    char ch_val;
    string str;
    float fl_val;

    //use of tie() without ignore
    tie(ch_val, i_val, str, fl_val) = student;

    cout << "The unpacked tuple values (without ignore) are : ";
    cout << ch_val << " " << i_val << " " <<str<<" "<< fl_val;
    cout << endl;

    //use of tie with ignore
    tie(ch_val, ignore , str, fl_val) = student;

    cout << "The unpacked tuple values (with ignore) are : ";
    cout << ch_val << " " << i_val << " " <<str<<" "<< fl_val;
    cout << endl;

    /* tuple_cat() :- This function concatenates two tuples and returns a new tuple. */

    //Concatenating two tuples to return a new tuple
    auto student2 = tuple_cat(student , student1);

    //displaying the returned tuple

    cout << "The  student2(concatenated tuple) : ";
    cout << get<0>(student2) << " " << get<1>(student2) << " " << get<2>(student2) << " " << get<3>(student2)<<" "<< get<4>(student2) << " " << get<5>(student2) << " " << get<6>(student2) << " " << get<7>(student2) << endl;


    return 0;
}
