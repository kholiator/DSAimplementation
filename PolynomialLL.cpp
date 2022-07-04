#include <iostream>
using namespace std;

class PolynomialNode
{

public:
    int number;
    int degree;
    PolynomialNode *nextNode;

    PolynomialNode(int number, int degree)
    {
        this->number = number;
        this->degree = degree;
        nextNode = NULL;
    }
};

//function to create Polynomial equation in user friendly manner.

PolynomialNode *createPolynomial()
{

    cout << "Enter number" << endl;
    int number;
    cin >> number;
    cout << "Enter Degree" << endl;
    int degree;
    cin >> degree;
    PolynomialNode *head = new PolynomialNode(number, degree);
    PolynomialNode *tail = head;

    cout << "Want to add More number in Equation" << endl;
    cout << "(y)for YES or (n)for NO" << endl;
    char response;
    cin >> response;

    while (response == 'y')
    {
        cout << "Enter number" << endl;
        int number;
        cin >> number;
        cout << "Enter Degree" << endl;
        int degree;
        cin >> degree;
        PolynomialNode *newNode = new PolynomialNode(number, degree);
        tail->nextNode = newNode;
        tail = tail->nextNode;

        cout << "Want to add More number in Equation" << endl;
        cout << "(y)for YES or (n)for NO" << endl;

        cin >> response;
    }
    return head;
}


//Function to Print Polynomial Equation.

void printPolynomial(PolynomialNode *head)
{
    PolynomialNode *temp = head;

    while (temp != NULL)
    {
        cout << showpos << temp->number << "x^" << noshowpos << temp->degree << " ";
        temp = temp->nextNode;
    }
    cout << endl;
}




//Function For Addition of Two Polynomial Equation and Returning a new Polynomial equation.

PolynomialNode *addition(PolynomialNode *head1, PolynomialNode *head2)
{

    PolynomialNode *fhead = NULL;
    PolynomialNode *ftail = NULL;

    PolynomialNode *temp1 = head1;
    PolynomialNode *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {

        if (temp1->degree > temp2->degree)
        {
            PolynomialNode *newNode = new PolynomialNode(temp1->number, temp1->degree);
            if (fhead == NULL)
            {
                fhead = newNode;
                ftail = newNode;
            }
            ftail->nextNode = newNode;
            ftail = ftail->nextNode;
            temp1 = temp1->nextNode;
        }

        else if (temp2->degree > temp1->degree)
        {
            PolynomialNode *newNode = new PolynomialNode(temp2->number, temp2->degree);
            if (fhead == NULL)
            {
                fhead = newNode;
                ftail = newNode;
            }
            ftail->nextNode = newNode;
            ftail = ftail->nextNode;
            temp2 = temp2->nextNode;
        }

        else
        {
            int newnumber = (temp1->number) + (temp2->number);

            if (newnumber != 0)
            {
                PolynomialNode *newNode = new PolynomialNode(newnumber, temp1->degree);
                if (fhead == NULL)
                {
                    fhead = newNode;
                    ftail = newNode;
                }

                ftail->nextNode = newNode;
                ftail = ftail->nextNode;
            }
            temp1 = temp1->nextNode;
            temp2 = temp2->nextNode;
        }
    }

    while (temp1 != NULL)
    {
        PolynomialNode *Newnode = new PolynomialNode(temp1->number, temp1->degree);
        ftail->nextNode = Newnode;
        ftail = ftail->nextNode;
        temp1 = temp1->nextNode;
    }

    while (temp2 != NULL)
    {
        PolynomialNode *NewNode = new PolynomialNode(temp2->number, temp2->degree);
        ftail->nextNode = NewNode;
        ftail = ftail->nextNode;
        temp2 = temp2->nextNode;
    }

    return fhead;
}


//Function For Subtraction of Two Polynomial Equation and Returning a new Polynomial equation.



PolynomialNode *subtraction(PolynomialNode *head1, PolynomialNode *head2)
{

    PolynomialNode *fhead = NULL;
    PolynomialNode *ftail = NULL;

    PolynomialNode *temp1 = head1;
    PolynomialNode *temp2 = head2;

    while (temp1 != NULL && temp2 != NULL)
    {

        if (temp1->degree > temp2->degree)
        {
            PolynomialNode *newNode = new PolynomialNode(temp1->number, temp1->degree);
            if (fhead == NULL)
            {
                fhead = newNode;
                ftail = newNode;
            }
            ftail->nextNode = newNode;
            ftail = ftail->nextNode;
            temp1 = temp1->nextNode;
        }

        else if (temp2->degree > temp1->degree)
        {
            PolynomialNode *newNode = new PolynomialNode((-1) * temp2->number, temp2->degree);
            if (fhead == NULL)
            {
                fhead = newNode;
                ftail = newNode;
            }
            ftail->nextNode = newNode;
            ftail = ftail->nextNode;
            temp2 = temp2->nextNode;
        }

        else
        {
            int newnumber = (temp1->number) - (temp2->number);

            if (newnumber != 0)
            {
                PolynomialNode *newNode = new PolynomialNode(newnumber, temp1->degree);
                if (fhead == NULL)
                {
                    fhead = newNode;
                    ftail = newNode;
                }

                ftail->nextNode = newNode;
                ftail = ftail->nextNode;
            }
            temp1 = temp1->nextNode;
            temp2 = temp2->nextNode;
        }
    }

    while (temp1 != NULL)
    {
        PolynomialNode *Newnode = new PolynomialNode(temp1->number, temp1->degree);
        ftail->nextNode = Newnode;
        ftail = ftail->nextNode;
        temp1 = temp1->nextNode;
    }

    while (temp2 != NULL)
    {
        PolynomialNode *NewNode = new PolynomialNode((-1) * temp2->number, temp2->degree);
        ftail->nextNode = NewNode;
        ftail = ftail->nextNode;
        temp2 = temp2->nextNode;
    }

    return fhead;
}



//Function for Merging two sorted list ----{used in Multiplication}....

PolynomialNode *mergeSortedList(PolynomialNode *head1, PolynomialNode *head2)
{
    PolynomialNode *finalHead = NULL;
    PolynomialNode *finalTail = NULL;

    if (head1->degree <= head2->degree)
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
        if (head1->degree <= head2->degree)
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




// Function to get middle node of Polynomial Linked list ----{used in Multiplication}....

PolynomialNode *midElement(PolynomialNode *head)
{
    PolynomialNode *slow = head;
    PolynomialNode *fast = head->nextNode;

    while ((slow->nextNode != NULL) && (fast != NULL && fast->nextNode != NULL))
    {
        slow = slow->nextNode;
        fast = fast->nextNode->nextNode;
    }

    return slow;
}



// Function for MergeSort  ----{used in Multiplication}....

PolynomialNode *mergeSort(PolynomialNode *head)
{

    if (head == NULL || head->nextNode == NULL)
    {
        return head;
    }

    PolynomialNode *mid;
    mid = midElement(head);

    PolynomialNode *nextHalf = mid->nextNode;
    mid->nextNode = NULL;

    PolynomialNode *final = mergeSortedList(mergeSort(head), mergeSort(nextHalf));

    return final;
}


// Function to Simplify a Polynomial equation that is to reduce the length by adding/subtracting numbers of same degree. ----{used in Multiplication}....


PolynomialNode *simplify(PolynomialNode *head)
{

    PolynomialNode *temp1 = NULL;
    PolynomialNode *temp2 = head;
    PolynomialNode *temp3 = head->nextNode;

    while (temp3 != NULL)
    {
        if (temp3->degree == temp2->degree)
        {

            if (temp1 == NULL)
            {

                temp3->number = (temp3->number) + (temp2->number);
                temp2->nextNode = NULL;
                delete temp2;
                temp2 = temp3;
                temp3 = temp3->nextNode;
                head = temp2;
            }
            else
            {
                temp3->number = (temp3->number) + (temp2->number);
                temp1->nextNode = temp3;
                temp2->nextNode = NULL;
                delete temp2;
                temp2 = temp3;
                temp3 = temp3->nextNode;
            }
        }
        else
        {
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3->nextNode;
        }
    }
    return head;
}




// Function for Multiplication of two Polynomial equations.

PolynomialNode *multiplication(PolynomialNode *head1, PolynomialNode *head2)
{
    PolynomialNode *finalhead = NULL;
    PolynomialNode *finaltail = NULL;
    PolynomialNode *temp1 = head1;
    while (temp1 != NULL)
    {
        PolynomialNode *temp2 = head2;
        while (temp2 != NULL)
        {
            int degree = (temp1->degree) + (temp2->degree);
            int number = (temp1->number) * (temp2->number);
            PolynomialNode *newNode = new PolynomialNode(number, degree);
            if (finalhead == NULL)
            {
                finalhead = newNode;
                finaltail = newNode;
            }
            else
            {
                finaltail->nextNode = newNode;
                finaltail = finaltail->nextNode;
            }
            temp2 = temp2->nextNode;
        }
        temp1 = temp1->nextNode;
    }

    finalhead = mergeSort(finalhead);
    finalhead = simplify(finalhead);
    return finalhead;
}





int main()
{


    PolynomialNode *equation1=createPolynomial();
    PolynomialNode *equation2=createPolynomial();

    cout<<"*************************Implementing Addition***********************"<<endl;

    PolynomialNode *addedEquation=addition(equation1,equation2);
    printPolynomial(addedEquation);

    cout<<"*************************Implementing Subtraction***********************"<<endl;


    PolynomialNode *subtractedEquation=subtraction(equation1,equation2);
    printPolynomial(subtractedEquation);


    cout<<"*************************Implementing Multiplication***********************"<<endl;


    PolynomialNode *multipliedEquation=multiplication(equation1,equation2);
    printPolynomial(multipliedEquation);
    

 
}