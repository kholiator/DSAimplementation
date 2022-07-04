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

Node *mergeSortedList(Node *head1, Node *head2)
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
}
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

Node *mergeSort(Node *head)
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

bool hasCycle(Node *head)
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
}

Node *thirdNodeLast(Node *head)
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
}

void removeNthNodeEnd(Node *head, int N)
{
    int length = lengthLinkedlist(head);
    int index = length - N;
    head = deleteNode(head, index);
}

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

Node*partition(Node*head,int x){
    Node*smaller=NULL;
    Node*smallerlast=NULL;
    Node*equal=NULL;
    Node*equallast=NULL;
    Node*greater=NULL;
    Node*greaterLast=NULL;
    Node*temp=head;

    while(temp!=NULL){
        if(temp->data<x){
            Node*newNode=new Node(temp->data);
            if(smaller==NULL){
                smaller=newNode;
                smallerlast=newNode;
            }
            else{
                smallerlast->nextNode=newNode;
                smallerlast=smallerlast->nextNode;
            }

            temp=temp->nextNode;
        }
        else if(temp->data>x){
            Node*newNode=new Node(temp->data);
            if(greater==NULL){
                greater=newNode;
                greaterLast=newNode;
            }
            else{
                greaterLast->nextNode=newNode;
                greaterLast=greaterLast->nextNode;
            }
            temp=temp->nextNode;
        }
        else{
            Node*newNode=new Node(temp->data);
            if(equal==NULL){
                equal=newNode;
                equallast=newNode;
            }
            else{
                equallast->nextNode=newNode;
                equallast=equallast->nextNode;
            }
            temp=temp->nextNode;
        }
    }
   
    if(smaller==NULL){
        if(equal!=NULL){
            if(greater!=NULL){
                equallast->nextNode=greater;
                head=equal;
            }
            else{
                head=equal;
            }
        }
        else{
            if(greater!=NULL){
                head=greater;
            }
            else{
                head=NULL;
            }
        }
    }
    else{
        if(equal!=NULL){
            if(greater!=NULL){
                smallerlast->nextNode=equal;
                equallast->nextNode=greater;
                head=smaller;
            }
            else{
                smallerlast->nextNode=equal;
                head=smaller;
            }
        }
        else{
            if(greater!=NULL){
                smallerlast->nextNode=greater;
                head=smaller;
            }
            else{
                head=smaller;
            }
        }

    }
    return head;
}

int main()
{

    /*  Node *linkedList = takeInput();

      // 1. Traverse the Linked list and Display all its node Elements.*****************************

      cout << "1. Traverse the Linked list and Display all its node Elements.*****************************" << endl;

      printLinkedlist(linkedList);

      // 2.Insert a new node at Beginning,Middle and at the End of Linked List.********************

      // At Beginning

      cout << "2.Insert a new node at Beginning**********************" << endl;

      linkedList = insertNode(linkedList, 20, 0);
      printLinkedlist(linkedList);

      // In Middle
      cout << "2.Insert a new node in Beginning******************" << endl;
      int length = lengthLinkedlist(linkedList);
      int middleIndex = (length - 1) / 2;

      linkedList = insertNode(linkedList, 88, middleIndex);
      printLinkedlist(linkedList);

      // At End
      cout << "2.Insert a new node at End********************" << endl;

      length = lengthLinkedlist(linkedList);

      linkedList = insertNode(linkedList, 90, length - 1);
      printLinkedlist(linkedList);

      // 3.Delete a node from the Beginning,Middle or at the End of Linked list.**********************

      // Lets delete element from Beginning
      cout << "3. Delete a node from the Beginning****************" << endl;

      linkedList = deleteNode(linkedList, 0);
      printLinkedlist(linkedList);

      // 4.Display the node elements in sorted order.*****************
      cout << "4.Display the node elements in sorted order.******************" << endl;

      linkedList=mergeSort(linkedList);
      printLinkedlist(linkedList);

      // 5.Reverse the nodes of the Linked list and Display the Data Items.****************************

      cout << "5.Reverse the nodes of the Linked list and Display the Data Items.****************************" << endl;

      linkedList = reverseLinkedList(linkedList);
      printLinkedlist(linkedList);
      */

   /* Node *newnode1 = new Node(5);
    Node *newnode2 = new Node(6);
    Node *newnode3 = new Node(7);
    Node *newnode4 = new Node(8);
    Node *newnode5 = new Node(9);
    newnode1->nextNode = newnode2;
    newnode2->nextNode = newnode3;
    newnode3->nextNode = newnode4;
    newnode4->nextNode = newnode5;
    newnode5->nextNode = NULL;
    cout << boolalpha << hasCycle(newnode1) << endl;*/


  /*  Node*newNode=takeInput();
    Node*thirdNodeFromLast=thirdNodeLast(newNode);
    if(thirdNodeFromLast==NULL){
        cout<<"NULL Node"<<endl;
    }
    cout<<thirdNodeFromLast->data;*/


    /*Node*newNode=takeInput();
    printLinkedlist(newNode);
    removeNthNodeEnd(newNode,4);
    printLinkedlist(newNode);*/

    /*Node*newNode=takeInput();
    printLinkedlist(newNode);

    cout<<boolalpha<<isPalindrome(newNode)<<endl;

       */

      Node* newNode=takeInput();
      printLinkedlist(newNode);
    //   newNode=removeDuplicates(newNode);
    newNode=partition(newNode,3);
      printLinkedlist(newNode);

}
