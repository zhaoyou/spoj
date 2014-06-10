
import java.util.*;

/**
  MergeSort 
*/
public class MergeSort {

	public static void main(String[] args) {
		List<Integer> list = new ArrayList<Integer>();
		list.add(3);

		list.add(8);

		list.add(12);

		list.add(4);

		list.add(9);

		list.add(7);

		list.add(10);
		list.add(2);

		
		System.out.println("unsorted list: " + list);
		System.out.println(mergeSort(list));

	}

	public static List<Integer> mergeSort(List<Integer> list) {
		if (list.size() <= 1) return list;

		int middle = list.size() / 2;

		List<Integer> leftList  = list.subList(0, middle);
		List<Integer> rightList = list.subList(middle , list.size());

		leftList = mergeSort(leftList);
		rightList = mergeSort(rightList);
		return merge(leftList, rightList);

	}

	public static List<Integer> merge(List<Integer> leftList, List<Integer> rightList) {
		List<Integer> result = new ArrayList<Integer>();

		Iterator<Integer> it1 = leftList.iterator();
		Iterator<Integer> it2 = rightList.iterator();

		int i = it1.next();
		int j = it2.next();

		while(true) {
			if (i - j <= 0) {
					result.add(i);
		
					if (it1.hasNext()) {
						i = it1.next();
					} else {
							result.add(j);
							while(it2.hasNext()) {
								result.add(it2.next());
							}
							break;
					}
			} else {
				result.add(j);

				if (it2.hasNext()) {
						j = it2.next();
				} else {
					result.add(i);
					while(it1.hasNext()) {
						result.add(it1.next());
					}
					break;
				}
			}
		}
		return result;
	}

} 