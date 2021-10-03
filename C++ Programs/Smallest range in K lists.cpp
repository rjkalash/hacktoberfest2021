class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          vector<pair<int,int>> v;
          for(int i=0;i<k;i++)
          for(int j=0;j<n;j++){
              v.push_back({arr[i][j],i});
          }
          //make sorted array of all elements with k value
          sort(v.begin(),v.end());

          //smallest substring with all k values
          vector<int> mp(k,0);
          int min = INT_MAX;
          int total=0,j=0;
          pair<int,int> ans;

          for(int i=0;i<v.size();i++){
              mp[v[i].second]++;
              if(mp[v[i].second] == 1)
              total++;
              if(total == k){
                  if(v[i].first - v[j].first + 1 < min){
                      min = v[i].first - v[j].first + 1;
                      ans = {v[j].first,v[i].first};
                  }
              }
              //if id = [2,2,2,1,3]
              //choose from last id idx=2
              if(total == k){
                  while(total == k){
                      if(mp[v[j].second] > 1){
                          mp[v[j].second]--;
                          j++;
                      }else{
                          break;
                      }
                  }
                  if(v[i].first - v[j].first + 1 < min){
                      min = v[i].first - v[j].first + 1;
                      ans = {v[j].first,v[i].first};
                  }
              }
          }
          return ans;
    }
};
