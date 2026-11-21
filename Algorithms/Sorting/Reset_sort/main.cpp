/*

Single for Loop (Resetting to Start)

This method compares adjacent elements and sets i = -1 whenever a swap happens.
On the next iteration, i++ brings the index back to 0 to re-verify the array from
the start.
*/

#include <iostream>
using namespace std;

void singleLoopSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            // Swap adjacent elements
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;

            // Reset index to -1 so i++ makes it 0 on the next iteration
            i = -1;
        }
    }
}

int main()
{
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    singleLoopSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
