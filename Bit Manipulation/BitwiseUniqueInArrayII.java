// Every element in the array occurs thrice except one of the element. Find this unique element.

import java.util.*;
class BitwiseUniqueInArrayII {
	public static void main(String[] args) {
		int[] array = {2,2,3,2,7,7,8,7,8,8,3,9,3};
		System.out.println(uniqueElement(array));
	}
	public static void sortArray(int[] arr) {
		Arrays.sort(arr);
	}
	public static int numberOfBinaryDigits(int num) {
		return ((int)(Math.log(num)/Math.log(2))+1);
	}
	public static int uniqueElement(int[] arr) {
		sortArray(arr);
		int start = 0;
		int end = numberOfBinaryDigits(arr[arr.length-1]);
		int unique = 0;
		while (start < end) {
			int count = 0;
			for (int i = 0; i < arr.length; i++) {
				if ((arr[i]&1) == 1)
					count++;
				arr[i] = arr[i]>>1;
			}
			unique += (count%3)<<start;
			start++;
		}
		return unique;
	}
}