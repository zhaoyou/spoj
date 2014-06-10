
/**
	快速排序	
 */
public class QuickSort {

	public static void main(String[] args) {
		int [] array = {1, 8, 7, 11, 6, 5, 9};
		quickSort(array, 0, array.length -1);
		for(int k = 0; k < array.length; k++) {
			System.out.println(array[k]);
		}
	}

	public static void quickSort(int[] array, int start, int end) {
		if (start < end) {
			int pos = position(array, start, end);
			quickSort(array, start, pos - 1);
			quickSort(array, pos , end);
		}
	}

	public static int position(int[] array, int start, int end) {
		int temp;
		int i = start, j = end;
		// TODO random v
		int v = array[(start + end) / 2];

		while (i < j) {

			while(array[i] < v) {
				i++;
			}

			while(array[j] > v) {
				j--;
			}

			if (i <= j) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				i++;
				j--;
			}
		}

		return i; 
	}
}