import java.util.Scanner;
public class SwapNumber {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int a= scanner.nextInt();
        int b=scanner.nextInt();
        int aSwap=a;
        int bSwap=b;
        a ^= b;
        b ^= a;
        a ^= b;
        System.out.println("Before Swap a="+aSwap+" b="+bSwap);
        System.out.println("After Swap a="+a+" b="+b);
    }
}
