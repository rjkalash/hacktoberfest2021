//CSES Problem Set "Number Spiral" in a Mathematical approach

#include <iostream>
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    long x,y;
	    cin>>x>>y;
	    long n = (x>y)?x:y;
	    long res = n*n -n +1;
	    if(n%2==0){
	        res = res + (x - y);
	    }else{
	        res = res + (y - x);
	    }
	    cout<<res<<"\n";
	}
	return 0;
}