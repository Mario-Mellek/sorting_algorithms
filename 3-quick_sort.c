#include "sort.h"

void quickSort_recur(int arr[], int low, int high, size_t size);
int partition(int arr[], int low, int high, size_t size);
void swap(int *x, int *y, const int *arr, size_t size);

/**
 * quick_sort - wrapper function that helps
 * sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: size of arr
*/
void quick_sort(int *array, size_t size)
{
	quickSort_recur(array, 0, size - 1, size);
}

/**
 * quickSort_recur - Recursive function that sorts
 * a subarray (both sides) of integers in ascending order
 * @arr: The subarray to be sorted
 * @low: Subarray's lowest index
 * @high: Subarray's highest index
 * @size: size of arr
*/
void quickSort_recur(int arr[], int low, int high, size_t size)
{
	int pivotIdx;

	if (low < high)
	{
		pivotIdx = partition(arr, low, high, size);
		quickSort_recur(arr, low, pivotIdx - 1, size);
		quickSort_recur(arr, pivotIdx + 1, high, size);
	}
}

/**
 * partition - Partitions a subarray around a pivot value
 * @arr: The subarray to be partitioned
 * @low: Subarray's lowest index
 * @high: Subarray's highest index
 * @size: size of arr
 * Return: the index of the pivot
*/
int partition(int arr[], int low, int high, size_t size)
{
	int pivotVal = arr[high];
	int i = low;
	int j;

	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivotVal)
		{
			if (i != j)
				swap(&arr[i], &arr[j], arr, size);
			i++;
		}
	}
	if (i != high)
		swap(&arr[i], &arr[high], arr, size);
	return (i);
}

/**
 * swap - Swaps two elements in an array and prints the array after swapping
 * @x: Pointer to first element to be swapped
 * @y: Pointer to second element to be swapped
 * @arr: Array to be swapped
 * @size: size of arr
*/
void swap(int *x, int *y, const int *arr, size_t size)
{
	int temp = *x;
	*x = *y;
	*y = temp;

	print_array(arr, size);
}
