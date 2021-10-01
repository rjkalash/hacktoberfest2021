// Find XOR of all the numbers in range [num1, num2].

class BitwiseXorInRangeII {
	public static void main(String[] args) {
		int num1 = 3;
		int num2 = 9;
		System.out.println(xorInRange(num2)^xorInRange(num1-1));
	}
	public static int xorInRange(int num) {
		if (num%4 == 0)
			return num;
		else if (num%4 == 1)
			return 1;
		else if (num%4 == 2)
			return num+1;
		else
			return 0;
	}
}