
public class Main {

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int ans = binary_search(arr, 9);
        System.out.println(ans);
    }

    static int binary_search(int[] arr, int target) {
        int s = 0;
        int e = arr.length - 1;
        while (s <= e) {
            int mid = s + ((e - s) / 2);
            if (target < arr[mid]) {
                e = mid - 1;
            } else if (target > arr[mid]) {
                s = mid + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
}