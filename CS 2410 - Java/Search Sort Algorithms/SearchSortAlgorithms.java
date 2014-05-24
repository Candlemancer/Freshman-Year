// Jonathan Petersen
// A01236750
// Chapter 12
// Generic Search

// Original Code by Malik/Burton
// Java Programming: Guided Learning with Early Objects
// Copyright 2009, Course Technology, Cengage Learning

public class SearchSortAlgorithms<T> {

	public < T extends Comparable<T> > void selectionSort(T[] list, int listLength) {

		int smallestIndex;
		T temp;

		for (int index = 0; index < listLength - 1; index++) {

			smallestIndex = index;

			for (int minIndex = index + 1; minIndex < listLength; minIndex++) {

				Comparable<T> compElem = (Comparable<T>) list[minIndex];

				if (compElem.compareTo(list[smallestIndex]) < 0) smallestIndex = minIndex;

			}

			temp = list[smallestIndex];
			list[smallestIndex] = list[index];
			list[index] = temp;

		}

		return;
	}

	public static < T extends Comparable<T> > int sequentialSearch(T[] array, int size, T key) {

		for (int i=0; i<size; i++) {

			if(array[i].compareTo(key) == 0) return i;

		}
		
		return -1;
	}

	public static void main(String[] args) {

		Integer[] intArr = {3, 5, 9, 47, 212, 65535};

		System.out.print("The array is as follows: ");
		for (int i : intArr) System.out.print(i + " ");
		System.out.print("\n");

		System.out.print("Searching for 212. Index: ");
		System.out.print(sequentialSearch(intArr, intArr.length, 212));
		System.out.println();

		System.out.print("Searching for 123. Index: ");
		System.out.print(sequentialSearch(intArr, intArr.length, 123));
		System.out.println();

		System.out.print("Searching for 9999999. Index: ");
		System.out.print(sequentialSearch(intArr, intArr.length, 9999999));
		System.out.println();



	}


}