public class InsertSort {

	public static void main(String[] args) {
		int array[] = new int[]{3, 7 , 8, 1, 4, 9};

		for(int i = 1; i < array.length; i++) {
			for (int k = i; k > 0 && array[k] < array[k - 1]; k--) {
				swap(array, k, k -1 );
			}
		}

		for(int j = 0; j < array.length; j++) {
			System.out.println(array[j]);
		}
	}

	public static void swap(int[] array, int first, int last) {
		int temp = array[first];
		array[first] = array[last];
		array[last] = temp;
	}
}