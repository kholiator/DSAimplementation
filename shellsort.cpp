#include <iostream>
using namespace std;

void shellSort(int arr[], int n)
{
    int comp=0,swaps=0;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
                comp++;
            }
            swaps++;
            arr[j] = temp;
        }
    }
    cout<<"In shell sort,"<<endl<<" No. of comparisons: "<<comp<<endl<<"No. of swaps: "<<swaps<<endl;
   
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    int comp=0,swap=0;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            comp++;
        }
        arr[j + 1] = key;
        swap++;
    }
   cout<<"In shell sort,"<<endl<<" No. of comparisons: "<<comp<<endl<<"No. of swaps: "<<swap<<endl;
    
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int size;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;
    int arr1[size];
    cout<<"Enter the array elements: "<<endl;
    for(int i=0;i<size;i++)
    cin>>arr1[i];

    int arr2[size];
    for(int i=0;i<size;i++)
    arr2[i]=arr1[i];

    cout << "Array before sorting: \n";
    printArray(arr1, size);

    shellSort(arr1, size);
    insertionSort(arr2,size);

    cout << " Array after sorting using Shell Sort: "<<endl;
    printArray(arr1, size);

    return 0;
}

