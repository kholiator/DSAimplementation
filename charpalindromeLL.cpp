#include<iostream>
using namespace std;

//  Char Node class

class Node
{

public:
    char data;
    Node *nextNode;

    Node(char data)
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
    cout << "'1' for YES or '0' for NO" << endl;
    int responseUser;
    cin >> responseUser;
    if (responseUser == 1)
    {
        cout << "Enter data"
             << ":" << endl;
        char data1;
        cin >> data1;
        head = new Node(data1);
        Node *tail = head;

        cout << "DO YOU WANT TO ADD MORE DATA" << endl;
        int response;
        cin >> response;

        while (response == 1)
        {
            cout << "Enter data :" << endl;
            char data;
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

// Function to check if current char Linked list is Palindrome or not 

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


int main(){

    Node*newNode=takeInput();
    printLinkedlist(newNode);
    cout<<boolalpha<<isPalindrome(newNode)<<endl;
}