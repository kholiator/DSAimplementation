#include<iostream>
using namespace std;

int partition(int a[],int si,int ei){
    int count=0;

    for(int i=si+1;i<=ei;i++){
        if(a[si]>a[i]){
            count++;
        }
    }
    int newindex=si+count;
    int temp=a[newindex];
    a[newindex]=a[si];
    a[si]=temp;

    int i=si;
    int j=ei;

    while(i<newindex && j>newindex){
        if(a[i]>a[newindex]){
            if(a[j]<a[newindex]){
            int temp2=a[i];
            a[i]=a[j];
            a[j]=temp2;
            i++;
            j--;

            }
            else{
                j--;
            }
        }
        else{
            i++;
        }
    }
    return newindex;

}
void quick_sort(int a[],int si,int ei){


if(si>=ei){
    return;
}
    int c=partition(a,si,ei);

    quick_sort(a,si,c-1);
    quick_sort(a,c+1,ei);


}

int main(){
    int n;
    cout<<"size of array"<<endl;
    cin>>n;

    int *a=new int [n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

quick_sort(a,0,n-1);

for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
}
cout<<endl;


delete[]a;
return 0;
}