#include <iostream>
using namespace std;

class Stack
{
private:
    int *array;
    int count1;
    int count2;
    int capacity1;
    int capacity2;
    int nextIndex1;
    int nextIndex2;

    void initializearray(int *arr)
    {
        for (int i = 0; i < capacity1 + capacity2; i++)
        {
            arr[i] = 0;
        }
    }

public:
    Stack()
    {
        capacity1 = 5;
        capacity2 = 5;
        array = new int[capacity1 + capacity2];
        initializearray(array);
        count1 = 0;
        count2 = 0;
        nextIndex1 = 0;
        nextIndex2 = capacity1;
    }

    void push1(int element)
    {
        if (count1 == capacity1)
        {
            int *newArray = new int[(capacity1 * 2) + capacity2];
            int temp = capacity1;
            capacity1 = capacity1 * 2;
            initializearray(newArray);
            for (int i = 0; i < temp; i++)
            {
                newArray[i] = array[i];
            }
            int oldIndex = temp;
            int newIndex = capacity1;
            for (int i = 0; i < count2; i++)
            {
                newArray[newIndex] = array[oldIndex];
                oldIndex++;
                newIndex++;
            }
            nextIndex2 = capacity1 + count2;
            delete[] array;
            array = newArray;
        }
        array[nextIndex1] = element;
        nextIndex1++;
        count1++;
    }
    void push2(int element)
    {
        if (count2 == capacity2)
        {
            int *newArray = new int[capacity1 + (capacity2 * 2)];
            capacity2 = capacity2 * 2;
            initializearray(newArray);

            for (int i = 0; i < capacity1; i++)
            {
                newArray[i] = array[i];
            }

            int oldIndex = capacity1;
            int newIndex = capacity1;
            for (int i = 0; i < count2; i++)
            {
                newArray[newIndex] = array[oldIndex];
                oldIndex++;
                newIndex++;
            }
            nextIndex2 = capacity1 + count2;
            delete[] array;
            array = newArray;
        }
        array[nextIndex2] = element;
        nextIndex2++;
        count2++;
    }

    int pop1()
    {
        if (isEmpty1())
        {
            cout << "Stack1 is Empty" << endl;
            return 0;
        }
        int temp = array[nextIndex1 - 1];
        nextIndex1--;
        count1--;
        return temp;
    }

    int pop2()
    {
        if (isEmpty2())
        {
            cout << "Stack2 is Empty" << endl;
            return 0;
        }
        int temp = array[nextIndex2 - 1];
        nextIndex2--;
        count2--;
        return temp;
    }

    int size1()
    {
        return count1;
    }
    int size2()
    {
        return count2;
    }

    bool isEmpty1()
    {
        return count1 == 0;
    }
    bool isEmpty2()
    {
        return count2 == 0;
    }

    int top1()
    {
        return array[nextIndex1 - 1];
    }

    int top2()
    {
        return array[nextIndex2 - 1];
    }
};

int main()
{

    Stack s;

    cout << "Inserting elements in stack 1 and stack 2 using push1() and push2()*********" << endl;
    s.push1(1);
    cout << s.top1() << endl;

    s.push2(11);
    cout << s.top2() << endl;

    s.push1(2);
    cout << s.top1() << endl;

    s.push2(12);
    cout << s.top2() << endl;

    s.push1(3);
    cout << s.top1() << endl;

    s.push1(4);
    cout << s.top1() << endl;

    s.push2(13);
    cout << s.top2() << endl;

    s.push1(5);
    cout << s.top1() << endl;

    s.push1(6);
    cout << s.top1() << endl;

    s.push2(14);
    cout << s.top2() << endl;

    s.push1(7);
    cout << s.top1() << endl;

    s.push2(15);
    cout << s.top2() << endl;

    s.push2(16);
    cout << s.top2() << endl;

    cout << "Size of stack1 after inserting 1,2,3,4,5,6,7 :" << endl;
    cout << s.size1() << endl;
    cout << "Size of stack1 after inserting 11,12,13,14,15,16,17 :" << endl;
    cout << s.size2() << endl;

    cout << "Deleting Elements of stack1 and stack2 using pop1() and pop2()*****" << endl;
    cout << s.pop2() << endl;
    cout << s.pop2() << endl;
    cout << s.pop2() << endl;
    cout << s.pop2() << endl;
    cout << s.pop2() << endl;
    cout << s.pop2() << endl;
    cout << s.pop2() << endl;
    cout << s.pop1() << endl;
    cout << s.pop1() << endl;
    cout << s.pop1() << endl;
    cout << s.pop1() << endl;
    cout << s.pop1() << endl;
}