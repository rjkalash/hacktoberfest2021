import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        
        StringBuilder result = new StringBuilder();
        Scanner sc = new Scanner(System.in);
        int en = 7;
        System.out.println("Enter the encrypted text:");
        String text = sc.nextLine();
        for(int i=0;i<text.length();i++)
        {
            char chr = text.charAt(i);
            if(chr == ' ')
            {
                result.append(" ");
            }
            else if((chr>=0 && chr<=64) || (chr>=91 && chr<=96) || (chr>=123 && chr<=127))
            {
                result.append("");
            }
           else if(Character.isUpperCase(chr))
           {
               char ch = (char) ('A'+(chr - 'A' - en + 26) % 26);
               result.append(ch);
           }
           else
           {
               char ch = (char)('a' + (chr - 'a' - en + 26) % 26);
               result.append(ch);
           }
        }
        if(result.toString().isEmpty())
        {
            System.out.println("No hidden message");
            return;
        }
        for(int j=0;j<result.length();j++)
        {
            char chr1 = result.charAt(j);
            if((chr1>=65 && chr1<=90) || (chr1>=97 && chr1<=122))
            {
                System.out.println("Decrypted text:");
                System.out.println(result);
                return;
            }
            /*else
            {
                System.out.println("No hidden message");
                return;
            }*/
        }
      /*  if(result.toString().equals(" ") || result.toString().equals("") || result.toString().isEmpty())
        {*/
            System.out.println("No hidden message");
            return;
        //}
        
        /*System.out.println("Decrypted text:");
        System.out.println(result);*/
        
    }
}
