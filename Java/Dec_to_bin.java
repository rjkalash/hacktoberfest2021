import java.util.*;
public class Dec_to_bin
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        System.out.println("enter a number");
        int num= in.nextInt();
        int[] arr = new int[100];
        int temp=num;
        int j = (arr.length-1);
        while(temp>0)
        {
            arr[j]=temp%2;
            temp=temp/2;
            j--;
            
        }
        for(int i=j;i<arr.length;i++)
        {
            System.out.print( arr[i]);
        }
    }
}
