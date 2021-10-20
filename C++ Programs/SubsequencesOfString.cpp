#include<bits/stdc++.h>
using namespace std;

int subSequences(string str, string output[]){

    if(str.length() == 0){
        output[0] = "";
        return 1;
    }
    int smallerOutputSize = subSequences(str.substr(1), output);
    for(int i = 0; i < smallerOutputSize ; i++){
        output[i + smallerOutputSize] = str[0] + output[i];    
    }
    return 2*smallerOutputSize;
}
int main(){
    string output[1000];

    int outputSize = subSequences("pqrst", output);

    for(auto i : output){
        cout << i << endl;
    }
    return 0;
}
