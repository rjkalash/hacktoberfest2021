#include <iostream>
#include <string>
using namespace std;

int main() {
  string firstname;
  cout<<"Type your name:";
  getline(cin,firstname);
  cout<<"Your name is:"<<firstname;
}