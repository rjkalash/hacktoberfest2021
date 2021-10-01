// Find the rightmost set bit of a number.
// For example :- 14 in decimal is 1110 in binary so its rightmost set bit is 2.

class BitwiseRightmostSetBit {
	public static void main(String[] args) {
		System.out.println(rightmostSetBit(364));
	}
	public static int rightmostSetBit(int num) {
		int lastBit = num&1;
		int countZeros = 0;
		while (lastBit != 1) {
			countZeros++;
			num = num>>1;
			lastBit = num&1;
		}
		return (1<<countZeros);
	}
}