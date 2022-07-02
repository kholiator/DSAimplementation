#include<iostream>
using namespace std;
 int allindex_x_array(int ar[],int size,int x,int *output)
{
    if(size==0){
        return 0;
    }
    
    int smallpart=allindex_x_array(ar+1,size-1,x,output);
    
       for(int i=0;i<smallpart;i++){
           output[i]=output[i]+1;
       }
    if(ar[0]==x){
        for(int i=smallpart;i>0;i--){
            output[i]=output[i-1];
        }
        output[0]=0;
        return smallpart+1;
        }
    else{
        return smallpart;
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
    int *output=new int[n];
   cout<< allindex_x_array(ar,n,x,output)<<endl;

   for(int i=0;i<allindex_x_array(ar,n,x,output);i++){
       cout<<output[i]<<" ";
   }
   cout<<endl;
   delete ar;
   delete output;
}