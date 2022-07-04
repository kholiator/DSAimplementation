#include <iostream>
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

// Function to Print one Node of LInkedList

void printOneElement(Node *head, int index)
{

    Node *temp = head;
    if (index == 0)
    {
        cout << temp->data << endl;
        ;
    }
    else
    {

        for (int i = 0; i < index; i++)
        {
            temp = temp->nextNode;
        }

        cout << temp->data << endl;
        ;
    }
}

// Function for displaying Nth node from end

void displayNthNodeEnd(Node *head, int N)
{
    int length = lengthLinkedlist(head);
    int index = length - N;
    printOneElement(head, index);
}

// Function for retaining M nodes and then deleting N nodes ,

Node *retainMdeleteN(Node *head, int M, int N)
{
    Node *current = head;
    Node *temp = NULL;
    int count;
    while (current)
    {
        for (count = 1; count < M && current != NULL; count++)
        {
            current = current->nextNode;
        }
        if (current == NULL)
        {
            return head;
        }
        temp = current->nextNode;
        for (count = 1; count <= N && temp != NULL; count++)
        {
            Node *a = temp;
            temp = temp->nextNode;
            delete a;
        }
        current->nextNode = temp;
        current = temp;
    }
    return head;
}

int main()
{

    Node *newNode = takeInput();
    cout << "INPUT LINKEDLIST**********" << endl;
    printLinkedlist(newNode);
    cout << "Enter a number N" << endl;
    int n;
    cin >> n;
    cout << "Displaying nth node form end***" << endl;

    displayNthNodeEnd(newNode, n);

    cout << "retaining M nodes and then deleting N nodes*****" << endl;

    retainMdeleteN(newNode, 2, 2);
    printLinkedlist(newNode);
}
