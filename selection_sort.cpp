#include<iostream>
using namespace std;

void selection_sort(int arr[],int size){
    if(size==1 || size==0){
        return;
    }

    int min=arr[0];
    int index=0;
    int count=0;
    for(int i=1;i<size;i++){
        count++;
        if(min>arr[i]){
            min=arr[i];
            index=i;

        }
    }
    arr[index]=arr[0];
    arr[0]=min;
  cout << "number of comparisons required to sort array in case of Selection_sort is " << count << endl;
selection_sort(arr+1,size-1);
}





int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    selection_sort(arr,n);


    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}