// Find the ith bit of the number.
// For example :- 14 in decimal is 1110 in binary so its 3rd bit is 4.

class BitwiseFindBit {
	public static void main(String[] args) {
		System.out.println(returnBit(173, 4));
	}
	public static int returnBit(int num, int i) {
		return ((num&(1<<(i-1))));
	}
}