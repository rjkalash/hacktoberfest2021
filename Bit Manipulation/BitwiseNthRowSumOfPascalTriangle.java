// Find the sum of the numbers in nth row of the Pascal's Triangle.

class BitwiseNthRowSumOfPascalTriangle {
	public static void main(String[] args) {
		System.out.println(nthRowSumOfPascalTriangle(3));
	}
	public static int nthRowSumOfPascalTriangle(int rowNumber) {
		return (1<<(rowNumber-1));
	}
}