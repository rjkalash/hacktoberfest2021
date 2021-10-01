// Find a raised to the power b.

class BitwiseCalPower {
	public static void main(String[] args) {
		System.out.println(power(5, 3));
	}
	public static int power(int a, int b) {
		int answer = 1;
		int temp = a;
		while (b != 0) {
			int lastBitOf_b = b&1;
			if (lastBitOf_b == 1)
				answer *= temp;
			b = b>>1;
			temp *= temp;
		}
		return answer;
	}
}