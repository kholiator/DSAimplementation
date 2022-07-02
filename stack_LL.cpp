#include<iostream>
using namespace std;
template<typename T>
class Node{

public:

T data;
Node<T>*nextNode;
Node<T>*prevNode;

Node(T data){
    this->data=data;
    nextNode=NULL;
    prevNode==NULL;
}
Node(){
    nextNode=NULL;
    prevNode==NULL;
}

};
template<typename T>
class Stack{
    private:
    Node<T>*head;
    int count;

    public:
    Stack(){
        head=NULL;
        count=0;
    }

    void push(T element){
        Node<T>*newNode=new Node<T>(element);
        newNode->prevNode=head;
        head=newNode;
        count++;
    }
    int size(){
        return count;
    }

    bool isEmpty(){
        return count==0;
    }

    T pop(){
        if(count==0){
            cout<<"Empty stack"<<endl;
            return 0;
        }
        else{
            Node<T>*temp=head;
            T data=temp->data;
            head=head->prevNode;
            delete temp;
            count--;
            return data;
        }
    }

    T top(){
        if(count==0){
            cout<<"Empty stack"<<endl;
            return 0;
        }
        return head->data;
    }


};

int main(){
   Stack <int>s1;
     s1.push(2);
    s1.push(4);
    s1.push(6);
    s1.push(8);
    cout<<s1.top()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.size()<<endl;
    cout<<boolalpha<<s1.isEmpty()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    s1.push(8);
    s1.push(9); 
    s1.push(10);
    s1.push(11);
    s1.push(12);
    s1.push(13);
    s1.push(14);
    cout<<s1.top()<<endl;
    cout<<s1.size()<<endl;



}
