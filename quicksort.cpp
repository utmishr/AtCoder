#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

int partition(int arr[], int low, int high)
{
  srand(time(NULL));
  int pivotIndex = low + rand() % (high - low);
  // why used pivotIndex = low + rand() % (high - low)
  // Let's say the original array is [4, 2, 9, 6, 23, 12, 34, 0, 1] and we are sorting a sub-array that starts
  // at index 3 (low = 3) and ends at index 6 (high = 6). The current sub-array is [6, 23, 12, 34].
  // If we don't add low to the pivot index, the value of rand() % (high - low) would be a random number
  // between 0 and 6 - 3 = 3. So, let's say that the random number generated is 2. The pivot index would be 2,
  // which corresponds to the element '12' in the current sub-array.
  // But if we add low to the pivot index, the value of rand() % (high - low) + low would be a random
  // number between 3 and 6 - 3 + 3 = 3. So, let's say that the random number generated is 2.
  // The pivot index would be 2 + 3 = 5, which corresponds to the element '12' in the current sub-array.
  int pivot = arr[pivotIndex];

  swap(arr[pivotIndex], arr[high]);

  int i = low - 1;
  for (int j = low; j <= high - 1; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[high]);
  return i + 1;
}

void quicksort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
  }
}

int main()
{
  int arr[] = {4, 2, 9, 6, 23, 12, 34, 0, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  quicksort(arr, 0, n - 1);

  cout << "Sorted array: \n";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}
