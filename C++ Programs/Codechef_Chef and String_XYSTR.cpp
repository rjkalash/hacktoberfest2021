#include <iostream>
using namespace std;

int dp[400000];


int find(int i , int size, string s){
    if(i>=size) return 0;
    if(dp[i]!=-1) return dp[i];
    int k=0;
    
    int m=0;
    if((i+1) < size && (s[i]=='x' && s[i+1]=='y' || s[i]=='y' && s[i+1]=='x') ){
         k= 1+find(i+2 , size, s);
    }
  m= find(i+1 , size, s);
    
    
    
     
     
    return dp[i]=max(k,m);
    
}
int main() {
  long int a;
  cin>>a;
  
  for(int b=0;b<a;b++){
      string c;
      cin>>c;
      int len=c.length();
     
     int ans=0;
     for(int i=0;i<len;i++){
         if((i+1) < len && (c[i]=='x' && c[i+1]=='y' || c[i]=='y' && c[i+1]=='x') ){
         ans++;
         i++;
        }
         
     }
     
     
     cout<<ans<<endl;
    
      
      
  }
  
  
  
  
  
}
