#include "sort.h"

void quickSort_recur(int arr[], int low, int high, size_t size);
int partition(int arr[], int low, int high, size_t size);
void swap(int *x, int *y, const int *arr, size_t size);

void quick_sort(int *array, size_t size)
{
	quickSort_recur(array, 0, size - 1, size);
}

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

void swap(int *x, int *y, const int *arr, size_t size)
{
	int temp = *x;
	*x = *y;
	*y = temp;

	print_array(arr, size);
}
