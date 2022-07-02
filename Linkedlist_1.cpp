#include<iostream>
using namespace std;

class Node{

public:

int data;
Node*nextNode;

Node(int data){
    this->data=data;
    nextNode=NULL;
}
Node(){
    nextNode=NULL;
}

};

void printLinkedlist(Node*head){
    Node*temp=head;

    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->nextNode;

    }
}


Node* takeInput(){
   
    cout<<"Enter data"<<":"<<endl;
    int data1;
    cin>>data1;
    Node * head=new Node(data1);
    Node*tail=head;

    char condition; 
    cout<<"Do you want to add more Data --YES(y) and NO(n)"<<endl;
    cin>>condition;

    while(condition=='y'){
             cout<<"Enter data :"<<endl;
    int data;
    cin>>data;
    Node*newNode=new Node(data);
    tail->nextNode=newNode;
    tail=tail->nextNode;
    cout<<"Do you want to add more Data --YES(y) and NO(n)"<<endl;
    cin>>condition;
    }
return head;
}



Node* insertNode(Node*head,int data,int index){
    Node*newNode=new Node(data);
    Node*temp=head;
 
    if(index==0){
        newNode->nextNode=head;
        head=newNode;
    }
    else{
    int i=0;
    while(i<index-1 && temp!=NULL){
        temp=temp->nextNode;
        i++;
    }
    if(temp!=NULL){
    newNode->nextNode=temp->nextNode;
    temp->nextNode=newNode;
    }
    }
    return head;
}

Node* deleteNode(Node*head,int index){

    Node*temp=head;

    if(index==0){
         Node*a=head;
        head=head->nextNode;
        delete a;

    }
    else{
        int i=0;
        while(i<index-1 && temp!=NULL){
            
            temp=temp->nextNode;
            i++;
        }

        if(temp!=NULL){

            Node*a=temp->nextNode;
            temp->nextNode=temp->nextNode->nextNode;
            delete a;
        }

    }


return head;
}


int lengthLinkedlist(Node*head){
    Node*temp=head;
int count=0;
    while(temp!=NULL){
        temp=temp->nextNode;
        count++;
    }

    return count;
}

void printOneElement(Node*head,int index){

    Node*temp=head;
    if(index==0){
    cout<<temp->data<<endl;;
        
    }
    else{

    for(int i=0;i<index;i++){
        temp=temp->nextNode;
    }

    cout<<temp->data<<endl;;
    }
}

Node* midElement(Node*head){
    Node*slow=head;
    Node*fast=head->nextNode;

    while((slow->nextNode!=NULL)&&(fast!=NULL && fast->nextNode!=NULL)  ){
        slow=slow->nextNode;
        fast=fast->nextNode->nextNode;
    }

   return slow;
}


// Node* mergeTwoSortedList(Node*head1,Node*head2){
//     Node*finalHead=NULL;
//     Node*finalTail=NULL;

//     if(head1->data<=head2->data){
//             finalHead=head1;
            
//             head1=head1->nextNode;
//         }

//         else{
//             finalHead=head2;
           
//            head2= head2->nextNode;
//         }
//         finalTail=head1;

//     while(head1!=NULL && head2!=NULL){

//         if(head1->data<=head2->data){
//             finalTail->nextNode=head1;
//             head1=head1->nextNode;

//         }
//         else{
//             finalTail->nextNode=head2;
            
//             head2=head2->nextNode;
//         }
//             finalTail=finalTail->nextNode;

//     }

//     if(head1!=NULL){
//         finalTail->nextNode=head1;
//     }
//     if(head2!=NULL){
//         finalTail->nextNode=head2;
//     }

//     return finalHead;
// }



Node* reverseList(Node*head){
    if(head==NULL ||head->nextNode==NULL){
        return head;
    }

    Node*temp=reverseList(head->nextNode);
    head->nextNode->nextNode=head;
    head->nextNode=NULL;
    return temp;

}



Node* mergeSortedList(Node* head1, Node* head2)
{
    Node* newHead = NULL;
    Node *tail=NULL;
   

    // Pick either head1 or head2 to make new head
    if (head1->data <= head2->data) {
        newHead = head1;
        head1=head1->nextNode;
    }
    else {
        newHead = head2;
        head2=head2->nextNode;
    }
    tail=newHead;
   
    while(head1!=NULL && head2!=NULL)
    {
        if (head1->data <= head2->data) {
        tail->nextNode = head1;
        head1=head1->nextNode;
    }
    else {
        tail->nextNode = head2;
        head2=head2->nextNode;
    }
   
    tail=tail->nextNode;

    }

    if(head1!=NULL)
    {
        tail->nextNode=head1;
    }
    if(head2!=NULL)
    {
        tail->nextNode=head2;
    }

    return newHead;
}

Node* mergeSort(Node*head){

    if(head==NULL || head->nextNode==NULL ){
        return head;
    }


    Node*mid=new Node();
    mid=midElement(head);

    Node*nexthalf=mid->nextNode;
    mid->nextNode=NULL;

    // Node*final=mergeTwoSortedList(mergeSort(head),mergeSort(nexthalf));
    Node*final=mergeSortedList(mergeSort(head),mergeSort(nexthalf));
    
    return final;

    
}

void printInReverse(Node*head){
    if(head==NULL){
        return;
    }
  printInReverse(head->nextNode);
  cout<<head->data<<" ";
}


int main(){

// Node node1(23);
// Node*head=&node1;
// Node node2(45);
// node1.nextNode=&node2;
// cout<<head<<" "<<&node1<<endl;
// cout<<node1.data<<"  "<<node1.nextNode<<endl;
// cout<<node2.data<<" "<<node2.nextNode<<"  "<<node1.nextNode->data<<endl;




// Node *node1=new Node(23);
// Node*head=node1;
// Node *node2=new Node(45);
// node1->nextNode=node2;
// // cout<<head<<" "<<node1<<endl;
// // cout<<node1->data<<"  "<<node1->nextNode<<endl;
// // cout<<node2->data<<" "<<node2->nextNode<<"  "<<node1->nextNode->data<<endl;
// Node *node3=new Node(76);
// node2->nextNode=node3;


// Node* linkedList=takeInput();

// // printLinkedlist(linkedList);

// // Node *head=insertNode(linkedList,43,2);
// // Node*head=deleteNode(linkedList,0);
// // printLinkedlist(head);

// cout<<lengthLinkedlist(linkedList)<<endl;

// printOneElement(linkedList,0);
// midElement(linkedList);

// Node* list1=takeInput();
// Node* list2=takeInput();

// Node*final=mergeTwoSortedList(list1,list2);
// printLinkedlist(final);

// Node* newlist=takeInput();
// newlist=mergeSort(newlist);
// cout<<"i reached here"<<endl;

// printLinkedlist(newlist);

// Node *list=takeInput();
// list=reverseList(list);
// printLinkedlist(list);

Node *listt=takeInput();
// listt=mergeSort(listt);
printLinkedlist(listt);
cout<<endl;
printInReverse(listt);

}