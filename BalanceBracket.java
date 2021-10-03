import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class BalanceBracket {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String string = scanner.nextLine();
        Deque<Character> stack = new ArrayDeque<>();

        for (int i = 0; i < string.length(); i++) {
            char x = string.charAt(i);

            if (x == '(' || x == '[' || x == '{') {
                stack.push(x);
                continue;
            }
            if (stack.isEmpty()) {
                System.out.println("bracket not balanced");
                return;
            }

            char check;
            switch (x) {
                case ')':
                    check = stack.pop();
                    if (check == '{' || check == '[') {
                        System.out.println("bracket not balanced");
                        return;
                    }
                    break;

                case '}':
                    check = stack.pop();
                    if (check == '(' || check == '[') {
                        System.out.println("bracket not balanced");
                        return;
                    }
                    break;

                case ']':
                    check = stack.pop();
                    if (check == '(' || check == '{') {
                        System.out.println("bracket not balanced");
                        return;
                    }
                    break;
            }
        }
        if (stack.isEmpty()) {
            System.out.println("bracket balanced");
        } else {
            System.out.println("bracket not balanced");
        }

    }
}
