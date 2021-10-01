// Given an array in which every element occurs twice except the one element. Find the unique element.

class BitwiseUniqueInArrayI {
	public static void main(String[] args) {
		int [] array = {2,3,4,1,2,1,3,6,4,5,7,6,7};
		System.out.println("Unique element : "+uniqueElement(array));
	}
	public static int uniqueElement(int[] arr) {
		int result = 0;
		for (int element : arr) {
			result = result^element;
		}
		return result;
	}
}