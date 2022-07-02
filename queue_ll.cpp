#include<iostream>
using namespace std;
template<typename T>
class Node{

public:

T data;
Node<T>*nextNode;
// Node<T>*prevNode;

Node(T data){
    this->data=data;
    nextNode=NULL;
    // prevNode==NULL;
}
Node(){
    nextNode=NULL;
    // prevNode==NULL;
}

};

template<typename T>
class Queue{
    private:
    Node<T>*head;
    Node<T>*tail;
    int size;
    public:
    Queue(){
        head=NULL;
        tail=NULL;
        size=0;
    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }

    void enqueue(T element){
        Node<T>*newNode=new Node<T>(element);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            size++;
        }
        else{
            tail->nextNode=newNode;
            tail=tail->nextNode;
            size++;
        }
    }

    T dequeue(){
        if(isEmpty()){
            cout<<"Empty Queue"<<endl;
            return 0;
        }
        Node<T>*temp=head;
        head=head->nextNode;
        size--;
        T ans=temp->data;
        delete temp;
        return ans;

    }
    T front(){
         if(isEmpty()){
            cout<<"Empty Queue"<<endl;
            return 0;
        }
        return head->data;

    }


};


int main(){

    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout<<q.front()<<endl;
    cout<<q.getSize()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<boolalpha<<q.isEmpty()<<endl;
    cout<<q.dequeue()<<endl;

    
}