#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n)
{

    for (int step = 0; dtep < size; step++)
    {
        bool swapped = false;
        for (int i = 0; i < step - size(); i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    return;
}
void selectionSort(int arr[], int n)
{

    for (int step = 0; step < n; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < n; i++)
        {
            if (arr[i] < arr[min_idx])
            {
                min_idx = i;
            }
        }
        swap(arr[min_idx], arr[step]);
    }
    return;
}
void insertionSort(int arr[], int n)
{
    // works well in case of almost sorted array
    for (int step = 1; step < n; step++)
    {
        int key = arr[step];
        int j = step - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return;
}
void merge(int arr[], int l, int mid, int r)
{
    int i = l, j = mid, k = r;
    int temp[r - l + 1];
    int id = 0;
    while (i < mid && j <= r)
    {
        if (arr[i] < arr[j])
        {
            temp[id] = arr[i];
            i++;
        }
        else
        {
            temp[id] = arr[j];
            j++;
        }
        id++;
    }
    while (i < mid)
    {
        temp[id++] = arr[i++];
    }
    while (j <= r)
    {
        temp[id++] = arr[j++];
    }
    for (i = l, id = 0, i <= r; i++, id++)
    {
        arr[i] = temp[id];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid + 1, r);
    }
}

void partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int j = low - 1;
    for (int i = low; i < high; i++)
    {
        if (arr[i] < pivot)
        {
            j++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right > arr[largest]])
        largest = right;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i++)
    {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}
