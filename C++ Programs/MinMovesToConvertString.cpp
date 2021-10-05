/*
You are given a string s consisting of n characters which are either 'X' or 'O'.

A move is defined as selecting three consecutive characters of s and converting them to 'O'. Note that if a move is applied to the character 'O', it will stay the same.

Return the minimum number of moves required so that all the characters of s are converted to 'O'. 
*/

#include<iostream>
#include<string>
using namespace std; 


int minimumMoves(string s) {
        int n = s.size(); 
        int count = 0; 
        for(int i=0 ;i<n ;i++){
            if(s[i] == 'X'){
                count++; 
                i = i+2; 
            }
        }
        
        return count; 
}

    
int main(){
    string s; 
    cin >> s; 
    cout << minimumMoves(s) << endl; 
    return 0; 
}