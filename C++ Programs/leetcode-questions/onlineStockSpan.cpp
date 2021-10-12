// problem link - https://leetcode.com/problems/online-stock-span/
// Author : Nishit Bansal, Nishit278 @ github
// solution using stack 

#include <bits/stdc++.h>
#include <vector>
#define ll long long int 
#define FOR(i,n) for (int i=0;i<n;i++)

using namespace std;
int solve(){
    ll n;
    cin >> n;
    ll arr[n];
    FOR(i,n){
        cin >> arr[i];
    }
    vector<ll> vec;
    stack <ll> st;
    ll count;
    FOR(i,n){
        if(st.empty() || (!st.empty() && st.top()>arr[i])){
            vec.push_back(1);
            st.push(arr[i]);
            
            
        }
        else if(!st.empty() && st.top()<=arr[i]){
            while(!st.empty() && st.top()<arr[i]){
                st.pop();
            }
            st.push(arr[i]);
            cout << st.top()<< endl;
            vec.push_back((i+1) - st.size()+1);
        }
    }
        FOR(i,n){
            cout << vec[i]<< " ";
        }
    cout << endl;
    return 0;
    
}
int main (){
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}