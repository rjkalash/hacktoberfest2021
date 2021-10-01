// Java program to remove duplicates in a sorted array
// by basic-bhavya

class Solution
{
    static int removeDuplicates(int arr[], int n)
    {
        if (n==0 || n==1)
            return n;
      
        int[] temp = new int[n];
         
        int j = 0;
        for (int i=0; i<n-1; i++)
            if (arr[i] != arr[i+1])
                temp[j++] = arr[i];
        temp[j++] = arr[n-1];  
         
        for (int i=0; i<j; i++)
            arr[i] = temp[i];
      
        return j;
    }
     
    public static void main (String[] args)
    {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int arr[] = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = s.nextInt();
        }
        n = removeDuplicates(arr, n);
  
        for (int i=0; i<n; i++)
           System.out.print(arr[i]+" ");
    }
}