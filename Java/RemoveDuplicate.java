public class RemoveDuplicate {
    public static void main(String[] args) {
        int num[] = {20, 20, 30, 40, 50, 50, 50};
        System.out.println("Original array length: " + num.length);
        System.out.print("Array elements are: ");
        for (int i = 0; i < num.length; i++)
        {
            System.out.print(num[i]+" ");
        }
        System.out.println("The new length of the array is: "+array_sort(num));

    }

    public static int array_sort(int[] num) {
        int index = 1;
        for (int i = 1; i < num.length; i++) {
            if (num[i] != num[index-1])
                num[index++] = num[i];
        }
        return index;
    }

}

