// Reset ith bit with 0.

class BitwiseResetBit {
	public static void main(String[] args) {
		System.out.println(resetBit(175, 3));
	}
	public static int resetBit(int num, int i) {
		return (num&(~(1<<i-1)));
	}
}