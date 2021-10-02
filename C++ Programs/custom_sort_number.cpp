#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(void){
    vector<int> order={2,1,8,3};
    vector<int> num={2,1,2,5,7,1,9,3,6,8,8};
    vector<int> ans;

    map<int,int> mp;
    for(auto x:num){
        mp[x]++;
    }
    
    for(auto x:order){
        if(mp.find(x)!=mp.end()){
        auto temp=mp.find(x);
        int count=temp->second;
        vector<int>v(count,x);
        ans.insert(ans.end(),v.begin(),v.end());
        mp.erase(x);
        }
    }

for(auto x:mp){
          vector<int>v(x.second,x.first);
           ans.insert(ans.end(),v.begin(),v.end());
    }

for(auto x:ans){
         cout<<x<<" ";
    }

}