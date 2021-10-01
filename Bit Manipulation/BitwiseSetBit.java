// Set ith bit as 1.

class BitwiseSetBit {
	public static void main(String[] args) {
		System.out.println(setBit(173, 2));
	}
	public static int setBit(int num, int i) {
		return (num|(1<<(i-1)));
	}
}