// Java program to check whether a
// string is a Palindrome
// Using two pointing variables

// Main class
public class GFG {

	// Method
	// Returning true if string is palindrome
	static boolean isPalindrome(String str)
	{

		// Pointers pointing to the beginning
		// and the end of the string
		int i = 0, j = str.length() - 1;

		// While there are characters to compare
		while (i < j) {

			// If there is a mismatch
			if (str.charAt(i) != str.charAt(j))
				return false;

			// Increment first pointer and
			// decrement the other
			i++;
			j--;
		}

		// Given string is a palindrome
		return true;
	}

	// Method 2
	// main driver method
	public static void main(String[] args)
	{
		// Input string
		String str = "geeks";

		// passing bool function till holding true
		if (isPalindrome(str))

			// It is a pallindrome
			System.out.print("Yes");
		else

			// Not a pallindrome
			System.out.print("No");
	}
}
