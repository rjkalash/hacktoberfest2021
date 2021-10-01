// Check if the number is odd or even.

import java.util.*;
class BitwiseOddEven {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.print("Enter a number : ");
		int num = input.nextInt();
		if ((num & 1) == 0)
			System.out.println("Even number.");
		else
			System.out.println("Odd number.");
	}
}