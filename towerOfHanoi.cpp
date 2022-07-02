#include <iostream>
using namespace std;

void towerOfHanoi(int n, char initialRod, char finalRod, char helperRod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, initialRod, helperRod, finalRod);
    cout << "Disk " << n << " from " << initialRod << " to " << finalRod << endl;
    towerOfHanoi(n - 1, helperRod, finalRod, initialRod);
}

int main()
{
    int n;
    cout << "Enter the number of Disks" << endl;
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
}