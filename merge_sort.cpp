#include<iostream>
using namespace std;
void merge(int a[],int si,int ei ){

int arrsize=ei-si+1;
int mid=(si+ei)/2;
int *arr=new int [arrsize];

int i=si;
int j=mid+1;
int index=0;
while(i<=mid && j<=ei){
    if(a[i]<a[j]){
        arr[index]=a[i];
        i++;
        index++;
    }
    else{
          arr[index]=a[j];
        j++;
        index++;
    }
}

while(i<=mid){
    arr[index]=a[i];
    i++;
    index++;
}
while(j<=ei){
    arr[index]=a[j];
    j++;
    index++;
}

int k=0;
for(int m=si;m<=ei;m++){
   a[m]=arr[k];
   k++;
}
delete[]arr;
}


void merge_sort(int a[],int si,int ei){

if(si>=ei){
    return;
}
int mid=(si+ei)/2;

merge_sort(a,si,mid);
merge_sort(a,mid+1,ei);

merge(a,si,ei);
    





}
int main(){
    int n;
    cout<<"size of array"<<endl;
    cin>>n;

    int *a=new int [n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

merge_sort(a,0,n-1);

for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
cout<<endl;


delete[]a;
return 0;
}