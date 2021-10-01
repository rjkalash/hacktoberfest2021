// Check if the number is the power of 2 or not.

class BitwiseCheckForPowerOf2 {
	public static void main(String[] args) {
		System.out.println(check(8));
	}
	public static boolean check(int num) {
		if (num == 0)
			return false;
		return ((num&(num-1)) == 0 ? true : false);
	}
}