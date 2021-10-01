void ccountSubsets(int arr[], int n, int gcd[], int m)
{
    // Map to store frequency of array elements
    unordered_map<int, int> freq;
 
    // Map to store number of subsets with given gcd
    unordered_map<int, int> subsets;
 
    // Initialize maximum element. Assumption: all array
    // elements are positive.
    int arrMax = 0;
 
    // Find maximum element in array and fill frequency
    // map.
    for (int i=0; i<n; i++)
    {
        arrMax = max(arrMax, arr[i]);
        freq[arr[i]]++;
    }
 
    // Run a loop from max element to 1 to find subsets
    // with all gcds
    for (int i=arrMax; i>=1; i--)
    {
        int sub = 0;
        int add = freq[i];
 
        // Run a loop for all multiples of i
        for (int j = 2; j*i <= arrMax; j++)
        {
            // Sum the frequencies of every element which
            // is a multiple of i
            add += freq[j*i];
 
            // Excluding those subsets which have gcd > i but
            // not i i.e. which have gcd as multiple of i in
            // the subset for ex: {2,3,4} cnsidering i = 2 and
            // subset we need to exclude are those havng gcd as 4
            sub += subsets[j*i];
        }
         
        // Number of subsets with GCD equal to 'i' is pow(2, add)
        // - 1 - sub   
        subsets[i] = (1<<add) - 1 - sub;
    }
 
    for (int i=0; i<m; i++)
      cout << "Number of subsets with gcd " << gcd[i] << " is "
          << subsets[gcd[i]] << endl;
}
 
// Driver program