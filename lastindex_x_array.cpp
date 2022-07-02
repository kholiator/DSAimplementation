#include<iostream>
using namespace std;
 int  lastindex_x_array(int ar[],int size,int x)
{
    if(size==0){
        return -1;
    }
    
    int smallpart=lastindex_x_array(ar+1,size-1,x);
    
    if(ar[0]==x){
        return smallpart+1;

        }
    
    else{
        if(smallpart==-1){
            return smallpart;
        }
        else{
            return smallpart+1;
        }
    }
    
}
int main(){
    int n;
    cin>>n;
    int *ar=new int [n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int x;
    cout<<"enter number"<<endl;
    cin>>x;
   cout<< lastindex_x_array(ar,n,x)<<endl;
   delete ar;
}