#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *nextNode;

    Node(int data)
    {
        this->data = data;
        nextNode = NULL;
    }
};

Node* midElement(Node*head){
    Node*slow=head;
    Node*fast=head->nextNode;

    while((slow->nextNode!=NULL)&&(fast!=NULL && fast->nextNode!=NULL)  ){
        slow=slow->nextNode;
        fast=fast->nextNode->nextNode;
    }

   return slow;
}

void BinarySearch(Node*head,int number,int si,int ei){
    

}