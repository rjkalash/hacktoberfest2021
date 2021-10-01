normal appraoch would be to iterate and find the required answer 
but to do in logn time complexity we can use binary search or upper bound or lower bound for maintaining 
the time complexity

code :

vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int> ans;
    int upper;
    upper=upper_bound(arr, arr+n, x) - arr;
    if(upper==n)
    upper=n-1;
    else 
    upper=upper-1;
    int lower=lower_bound(arr, arr+n ,x)-arr;
    if(lower==0 && arr[lower]!=x)
    lower=lower+1;
    if(upper==n && lower==0 && arr[upper-1]!=x && arr[lower]!=x)
    upper=-1,lower=-1;
    else if(arr[upper]!=x && arr[lower]!=x)
    upper=-1,lower=-1;
    ans.push_back(lower);
    ans.push_back(upper);
    return ans;
    
    
}