#include <iostream>
using namespace std;

int ackermann(int m, int n)
{
    if (m == 0){
        return n + 1;
    }
    else if (n == 0){
        return ackermann(m - 1, 1);
    }
    else
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}
int main()
{

    cout << "Enter the values of m and n :  ";
    int m, n;
    cin >> m >> n;
    cout<<"The result is : "<<endl;
    cout << ackermann(m, n)<< endl;
    return 0;
}