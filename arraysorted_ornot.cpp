#include<iostream>
using namespace std;
    bool arraysorted_ornot(int *ar,int size){
        if(size==0){
            return true;
        }
        if(ar[0]>ar[1]){
            return false;
        }
        bool smallpart=arraysorted_ornot(ar+1,size-1);
        return smallpart;
        
    }

int main(){
    int n;
    cin>>n;
    int *ar=new int[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int size=sizeof(ar)/sizeof(ar[0]);
    cout<<arraysorted_ornot(ar,size)<<endl;
}