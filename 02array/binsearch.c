#include <stdio.h>

int binsearch (int key, int arr[], int low, int high)
{
        while (low <= high) {
                int mid = (low+high) / 2;
        
                if (arr[mid] == key)
                        return mid;            
                if (arr[mid] < key)
                        low = mid + 1;
                else
                        high = mid - 1;
        }
        return -1;
}

int rbinsearch(int key, int arr[], int low, int high)
{
        if (high < low)
                return -1;
        int mid = (low + high) / 2;
        if (key == arr[mid])
                return mid;
        if (key > arr[mid])
                return rbinsearch(key, arr, mid+1, high);
        return rbinsearch(key, arr, low, mid-1);
}

int main()
{
        int     n, arr[] = { 30, 40, 45, 72, 83 };

        n = sizeof(arr) / sizeof(arr[0]);
        printf("45 at index: %d\n", binsearch(45, arr, 0, n-1));
        printf("72 at index: %d\n", rbinsearch(72, arr, 0, n-1));
}