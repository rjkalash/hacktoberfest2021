import java.util.Scanner;

public class ReverseNumber {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int n= scanner.nextInt();
        int temp=n;
        int rem=0,rev=0;
        while(temp>0){
            rem=temp%10;
            rev=rev*10+rem;
            temp/=10;
        }
        System.out.println(rev);
    }
}
