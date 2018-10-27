#include <iostream>
using namespace std;

void merge(int *arr, int li, int size1, int ri, int size2)
{
    int lli = li;
    int rri = ri;
    int *aux = new int[size1 + size2];
    for (int i = 0; i < size1 + size2; i++)
    {
        if (li >= lli + size1)
            aux[i] = arr[ri++];
        else if (ri >= rri + size2)
            aux[i] = arr[li++];
        else if (arr[li] > arr[ri])
            aux[i] = arr[ri++];
        else
            aux[i] = arr[li++];
    }
    int index = 0;
    for (int i = lli; i < lli + size1 + size2; i++)
        arr[i] = aux[index++];
    delete[] aux;
}

void mergeSort(int *arr, int start, int end)
{
    if (start >= (end - 1))
        return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid, end);
    merge(arr, start, mid - start, mid, end - mid);
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mergeSort(arr, 0, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    delete[] arr;

    return 0;
}