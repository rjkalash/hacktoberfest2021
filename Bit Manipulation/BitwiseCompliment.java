// Find the compliment of the number.

class BitwiseCompliment {
	public static void main(String[] args) {
		System.out.println(complimentNumber(5));
	}
	public static int complimentNumber(int num) {
		return (~num);
	}
}