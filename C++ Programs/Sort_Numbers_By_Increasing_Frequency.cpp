#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

int main(void){
    
    vector<int> num={2,4,4,6,2,2,9,9,9,9};
    map<int,int>umap;
    vector<int> ans;
  
    for(auto x:num){
        umap[x]++;
    }

  sort(num.begin(),num.end(),[&](int a,int b){
      return umap[a]!=umap[b] ?umap[a]<umap[b]:umap[a]>umap[b];
  });






for(auto x:num){
         cout<<x<<" ";
    }

}