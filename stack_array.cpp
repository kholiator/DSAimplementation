#include<iostream>
using namespace std;
template<typename T>
class Stack{
    private:
    T *stackArray;
    int index;
    int capacity;

    void changeSize(){
        T *newstackArray=new T[capacity*2];
        for(int i=0;i<capacity;i++){
            newstackArray[i]=stackArray[i];
        }
        capacity*=2;
        delete[]stackArray;
        stackArray=newstackArray;
    }
    public:
    Stack(){
        capacity=5;
        stackArray=new T[capacity];
        index=0;
    }
    Stack(int totalSize){
        capacity=totalSize;
        stackArray=new int[capacity];
        index=0;
    }

void push(T element){
    if(index==capacity){
        changeSize();
    }
    stackArray[index]=element;
    index++;
}
int size(){
  return index;
}

bool isEmpty(){
    if(size()==0){
        return true;
    }
    else{
        return false;
    }
}

T pop(){
    if(isEmpty()){
        cout<<"Empty stack"<<endl;
        return 0;
    }
    else{
        int temp=stackArray[index-1];
        index=index-1;
        return temp;
    }
}

T top(){
      if(isEmpty()){
        cout<<"Empty stack"<<endl;
        return 0;
    }
    else{
        return stackArray[index-1];
    }
}

};

void reverseStack(Stack<int>s,Stack<int>helper){
    if(s.isEmpty() || s.size()==1){
        return;
    }
    int temp=s.top();
    s.pop();
    reverseStack(s,helper);
    while(!s.isEmpty()){
        helper.push(s.pop());
    }
    s.push(temp);
    while(!helper.isEmpty()){
        s.push(helper.pop());
    }
}

void printStack(Stack<int>s){
    Stack<int>temp;
    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        temp.push(s.pop());
    }
    while(!temp.isEmpty()){
        s.push(temp.pop());
    }

}


int main(){
    Stack<int> s1;
   s1.push(1);
   s1.push(2);
   s1.push(3);
   s1.push(4);
   s1.push(5);
   s1.push(6);
   s1.push(7);
   printStack(s1);
  
  cout<<"After reversing"<<endl;
  Stack<int>helper;
  reverseStack(s1,helper);
   printStack(s1);





}
        