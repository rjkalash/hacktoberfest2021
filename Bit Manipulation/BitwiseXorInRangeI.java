// Find XOR from numbers 0 to num.

class BitwiseXorInRangeI {
	public static void main(String[] args) {
		for (int i = 0; i <= 10; i++)
			System.out.println(i+" = "+xorInRange(i));
	}
	public static int xorInRange(int num) {
		if (num%4 == 0)
			return num;
		else if (num%4 == 1)
			return 1;
		else if (num%4 == 2)
			return (num+1);
		else
			return 0;
	}
}