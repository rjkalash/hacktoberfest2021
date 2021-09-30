#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector< vector<int> > arr(n,vector<int>(n));
    for(int i = 0;i < n;i++){
       for(int j = 0;j < n;j++){
          cin >> arr[i][j];
       }
    }
    int ld=0,rd=0;
    for(int i=0;i<n;i++){
        ld+=arr[i][i];
        rd+=arr[i][n-i-1];
    }
    cout<<(abs(ld-rd));
    return 0;

}