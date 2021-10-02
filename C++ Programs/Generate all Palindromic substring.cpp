//Cpp code for generating all possible palindromic substrings.
#include <bits/stdc++.h>
using namespace std;

int substringSES(string s,int start,int end){
    // when end reaches at the end of the string still recur for some more cases if present  
  
    if(end == s.size()){
    start++;
    end = start;
  }
  /* when end reaches at the end of the string 
    and all cases are covered */
  if(end == s.size())
    return 0;

    /* if a char at start index matches char at end index
    count it and recur for more cases */
  if(s[start] == s[end])
    return 1 + substringSES(s, start, end + 1);
  else 
    /* if char at both index does'nt matches skip it 
    and recur for more cases */
    return substringSES(s, start, end + 1); 
}

int main()
{
  int t;cin>>t;
  while(t--){
    string s;cin>>s;
    int start = 0;
    int end = s.size()-1;
    cout<<substringSES(s,start,start)<<"\n";
  }

  return 0;
}
