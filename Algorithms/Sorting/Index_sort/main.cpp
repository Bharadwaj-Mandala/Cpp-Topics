/*

Single while Loop (Gnome Sort)

A cleaner variation known as Gnome Sort moves the index backward by one step (i--)
after a swap rather than restarting from zero. This avoids re-checking already sorted
elements at the beginning of the array
*/

#include <iostream>
using namespace std;

void gnomeSort(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {

        if (i == 0 || arr[i] >= arr[i - 1])
        {
            i++;
        }
        else
        {
            // Swap and step backward
            swap(arr[i], arr[i - 1]);
            i--;
        }
    }
}

int main()
{
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    gnomeSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
