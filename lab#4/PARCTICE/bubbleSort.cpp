
// bubble sort
#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubbleSort(int *arr, int size)
{
  bool swapped; // optimization flag

  for (int i = 0; i < size - 1; i++) // total passes
  {
    swapped = false;
    for (int j = 0; j < size - i - 1; j++) // compare adjacent elements
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j + 1]);
        swapped = true;
      }
    }

    // if no swaps happened in this pass → already sorted
    if (!swapped)
      break;
  }
}

int main()
{
  const int SIZE = 5;
  int arr[SIZE] = {5, 2, 4, 3, 1};

  cout << "Before sorting:\n";
  for (int i = 0; i < SIZE; i++)
    cout << arr[i] << " ";

  bubbleSort(arr, SIZE);

  cout << "\nAfter sorting:\n";
  for (int i = 0; i < SIZE; i++)
    cout << arr[i] << " ";

  return 0;
}

