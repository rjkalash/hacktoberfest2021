import java.util.*;
public class Decimal2Binary
{
    public static void main(String Args[])
    {
        Scanner ob = new Scanner(System.in);
        int n= ob.nextInt();
        int s=0;
        int c=0;
        while(n!=0)
        {
            int t=n%2;
            s=s+ t*(int)Math.pow(10,c);
            n=n/2;
            c++;
        }
        System.out.println(s);
    }
}
