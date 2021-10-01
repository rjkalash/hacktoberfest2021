class Main
{
    // Function to return the maximum product of a subarray of a given array
    public static int findMaxProduct(int[] A)
    {
        // base case
        if (A.length == 0) {
            return 0;
        }
 
        // maintain two variables to store the maximum and minimum product
        // ending at the current index
        int max_ending = A[0], min_ending = A[0];
 
        // to store the maximum product subarray found so far
        int max_so_far = A[0];
 
        // traverse the given array
        for (int i = 1; i < A.length; i++)
        {
            int temp = max_ending;
 
            // update the maximum product ending at the current index
            max_ending = Integer.max(A[i], Integer.max(A[i] * max_ending,
                                                A[i] * min_ending));
 
            // update the minimum product ending at the current index
            min_ending = Integer.min(A[i], Integer.min(A[i] * temp,
                                                A[i] * min_ending));
 
            max_so_far = Integer.max(max_so_far, max_ending);
        }
 
        // return maximum product
        return max_so_far;
    }
 
    public static void main(String[] args)
    {
        int[] A = { -6, 4, -5, 8, -10, 0, 8 };
 
        System.out.print("The maximum product of a subarray is " + findMaxProduct(A));
    }
}





