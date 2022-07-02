#include<iostream>
using namespace std;
   int  firstindex_x_array(int ar[],int size,int x)
{
    if(size==0){
        return -1;
    }
    if(ar[0]==x){
        return 0;
    }
    
    int smallpart=firstindex_x_array(ar+1,size-1,x);
   
   if(smallpart==-1){
       return smallpart;
   }
   else{
    return smallpart+1;
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

   cout<< firstindex_x_array(ar,n,x)<<endl;
}