// CODE IN C++
#include<bits/stdc++.h> 
using namespace std;

// Calculating longest Prefix which also Suffix.
int* getlps(string ptr){
    int n = ptr.length();
    int *lps = new int[n];
    lps[0] = 0;
    int i = 1;
    int j = 0;
    while(i < n)
    {
        if(ptr[i] == ptr[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else{
            if(j != 0)
            {
                j = lps[j - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Finding the Kmp Algorithm.
bool kmpStringMatching(string text, string pattern)
{
    int texLen = text.length();
    int patrLen = pattern.length();
    int i = 0;
    int j = 0;
    int *lps = getlps(pattern);
    while(i != texLen && j != patrLen){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            if(j!= 0)
            {
                j = lps[j - 1];
            }
            else{
                i++;
            }
        }
    }
    if(j == patrLen){
        return true;
    }
    return false;
}


int main()
{
    string str = "geeksforgeeks";
    string pat = "forgee";
    cout<<kmpStringMatching(str, pat) << endl;
    return 0;
}
