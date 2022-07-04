#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// Node class

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
    Node()
    {
        nextNode = NULL;
    }
};

// Function for entering data in LinkedList
Node *takeInput()
{

    Node *head = NULL;
    cout << "DO YOU WANT TO ADD DATA" << endl;
    cout << "'y' for YES or 'n' for NO" << endl;
    char responseUser;
    cin >> responseUser;
    if (responseUser == 'y')
    {
        cout << "Enter data"
             << ":" << endl;
        int data1;
        cin >> data1;
        head = new Node(data1);
        Node *tail = head;

        cout << "DO YOU WANT TO ADD MORE DATA" << endl;
        char response;
        cin >> response;

        while (response == 'y')
        {
            cout << "Enter data :" << endl;
            int data;
            cin >> data;
            Node *newNode = new Node(data);
            tail->nextNode = newNode;
            tail = tail->nextNode;
            cout << "DO YOU WANT TO ADD MORE DATA" << endl;
            cin >> response;
        }
    }
    return head;
}

// Function to traverse the Linked list and Displaying all its node elements.

void printLinkedlist(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->nextNode;
    }
    cout << endl;
}

// Function for calculating Length of Linkedlist

int lengthLinkedlist(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->nextNode;
        count++;
    }

    return count;
}

// Function for Inserting node at index provided by User.

Node *insertNode(Node *head, int data, int index)
{
    Node *newNode = new Node(data);
    Node *temp = head;

    if (index == 0)
    {
        newNode->nextNode = head;
        head = newNode;
    }
    else
    {
        int i = 0;
        while (i < index - 1 && temp != NULL)
        {
            temp = temp->nextNode;
            i++;
        }
        if (temp != NULL)
        {
            newNode->nextNode = temp->nextNode;
            temp->nextNode = newNode;
        }
    }
    return head;
}

// Function for Deleting node at index provided by User.

Node *deleteNode(Node *head, int index)
{

    Node *temp = head;

    if (index == 0)
    {
        Node *a = head;
        head = head->nextNode;
        delete a;
    }
    else
    {
        int i = 0;
        while (i < index - 1 && temp != NULL)
        {

            temp = temp->nextNode;
            i++;
        }

        if (temp != NULL)
        {

            Node *a = temp->nextNode;
            temp->nextNode = temp->nextNode->nextNode;
            delete a;
        }
    }

    return head;
}

// Function to merge two Sorted Linkedlist into sorted List.

/*Node *mergeSortedList(Node *head1, Node *head2)
{
    Node *finalHead = NULL;
    Node *finalTail = NULL;

    if (head1->data <= head2->data)
    {
        finalHead = head1;
        head1 = head1->nextNode;
    }
    else
    {
        finalHead = head2;
        head2 = head2->nextNode;
    }
    finalTail = finalHead;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            finalTail->nextNode = head1;
            head1 = head1->nextNode;
        }
        else
        {
            finalTail->nextNode = head2;
            head2 = head2->nextNode;
        }

        finalTail = finalTail->nextNode;
    }

    if (head1 != NULL)
    {
        finalTail->nextNode = head1;
    }
    if (head2 != NULL)
    {
        finalTail->nextNode = head2;
    }

    return finalHead;
}*/
// Function to get middle node of Linked list

Node *midElement(Node *head)
{
    Node *slow = head;
    Node *fast = head->nextNode;

    while ((slow->nextNode != NULL) && (fast != NULL && fast->nextNode != NULL))
    {
        slow = slow->nextNode;
        fast = fast->nextNode->nextNode;
    }

    return slow;
}
// Function to Sort Linked list using Mergesort .

/*Node *mergeSort(Node *head)
{

    if (head == NULL || head->nextNode == NULL)
    {
        return head;
    }

    Node *mid = new Node();
    mid = midElement(head);

    Node *nextHalf = mid->nextNode;
    mid->nextNode = NULL;

    Node *final = mergeSortedList(mergeSort(head), mergeSort(nextHalf));

    return final;
}
*/
// Function for Reversing the LinkedList.

Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->nextNode == NULL)
    {
        return head;
    }

    Node *smallPart = reverseLinkedList(head->nextNode);
    head->nextNode->nextNode = head;
    head->nextNode = NULL;
    return smallPart;
}

/*bool hasCycle(Node *head)
{
    unordered_set<Node *> addressSet;
    Node *temp = head;

    while (temp != NULL)
    {
        if (addressSet.find(temp) != addressSet.end())
        {
            return true;
        }
        addressSet.insert(temp);
        temp = temp->nextNode;
    }

    return false;
}*/

/*Node *thirdNodeLast(Node *head)
{
    Node *temp1 = NULL;
    Node *temp2 = head;
    Node *temp3 = head->nextNode;

    while (temp2 != NULL && temp3->nextNode != NULL  )
    {
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3->nextNode;
    }
    return temp1;
}*/

/*void removeNthNodeEnd(Node *head, int N)
{
    int length = lengthLinkedlist(head);
    int index = length - N;
    head = deleteNode(head, index);
}*/

bool isPalindrome(Node *head)
{
    Node *temp = head;
    Node *mid = midElement(temp);
    Node *secondhead = mid->nextNode;
    mid->nextNode = NULL;

    bool result;
    temp = head;

    secondhead = reverseLinkedList(secondhead);



    while (temp != NULL && secondhead != NULL)
    {
        if (temp->data == secondhead->data)
        {
            result = true;
            temp = temp->nextNode;
            secondhead = secondhead->nextNode;
        }
        else
        {
            result = false;
            break;
        }
    }
    
    return result;
}

Node* removeDuplicates(Node*head){
    unordered_set<int>dataset;
    Node*temp1=head;
    Node*temp2=NULL;
    while(temp1!=NULL){
        if(dataset.find(temp1->data)!=dataset.end()){
            temp2->nextNode=temp1->nextNode;
            delete temp1;
            temp1=temp2->nextNode;
        }
        else{
            dataset.insert(temp1->data);
            temp2=temp1;
            temp1=temp1->nextNode;
        }
    }
    return head;
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
void displayNthNodeEnd(Node *head, int N)
{
    int length = lengthLinkedlist(head);
    int index = length - N;
    printOneElement(head, index);
}


Node* retainMdeleteN(Node*head,int M,int N){
    Node*current=head;
    Node*temp=NULL;
    int count;
    while(current){
        for(count=1;count<M && current!=NULL;count++){
            current=current->nextNode;
        }
        if(current==NULL){
            return head;
        }
        temp=current->nextNode;
        for(count=1;count<=N && temp!=NULL;count++){
            Node *a=temp;
            temp=temp->nextNode;
            delete a;
        }
        current->nextNode=temp;
        current=temp;
    }
    return head;
}

int main()
{

      Node*newNode=takeInput();
      printLinkedlist(newNode);
    //   displayNthNodeEnd(newNode,3);
    retainMdeleteN(newNode,2,2);
    printLinkedlist(newNode);


}
