#include<iostream>
#include<vector>
using namespace std;

class priorityQueue{
    vector<int> pq;
    public:
    priorityQueue(){

    }
 
  

    void insert(int number){
        pq.push_back(number);
        int childIndex=pq.size()-1;

        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;

            if(pq[childIndex]<pq[parentIndex]){
                int temp=pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;

            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
   

    }

    int removeMin(){

        if(isEmpty()){
            return 0;
        }
        int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex=0;
        int minIndex=parentIndex;

        
        int childIndexleft=2*parentIndex+1;
        int childIndexright=2*parentIndex+2;
        while(childIndexleft<pq.size()){

        if(pq[minIndex]>pq[childIndexleft]){
            minIndex=childIndexleft;
        }
        if( childIndexright<pq.size()&& pq[minIndex]>pq[childIndexright]){
            minIndex=childIndexright;
        }
        if(minIndex==parentIndex){
            break;
        }
        int temp=pq[parentIndex];
        pq[parentIndex]=pq[minIndex];
        pq[minIndex]=temp;
        parentIndex=minIndex;
        childIndexleft=2*parentIndex+1;
        childIndexright=2*parentIndex+2;
        }
        return ans;
    }




    bool isEmpty(){
      return pq.size()==0;  
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty()){
            return 0;
        }
        else
        return pq.front();
    }
};

int main(){

priorityQueue p;
p.insert(100);
p.insert(10);
p.insert(15);
p.insert(4);
p.insert(17);
p.insert(21);
p.insert(67);

cout<<p.getSize()<<endl;
cout<<p.getMin()<<endl;

while(!p.isEmpty()){
    cout<<p.removeMin()<<endl;
}


}