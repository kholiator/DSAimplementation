#include <iostream>
using namespace std;

void waitingTimeCalculation(int processes[], int n, int bt[], int wt[], int quantum)
{
    int rbt[n];
    for (int i = 0; i < n; i++)
    {
        rbt[i] = bt[i];
    }
    int time = 0;
    while (true)
    {
        bool done = true;
        for (int i = 0; i < n; i++)
        {
            if (rbt[i] > 0)
            {
                done = false;

                if (rbt[i] > quantum)
                {
                    time = time + quantum;
                    rbt[i] = rbt[i] - quantum;
                }
                else
                {
                    time = time + rbt[i];
                    wt[i] = time - bt[i];
                    rbt[i] = 0;
                }
            }
        }
        if (done == true)
        {
            break;
        }
    }
}

void turnAroundTimeCalculation(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}

void averageWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
    waitingTimeCalculation(processes, n, bt, wt, quantum);

    double result = 0;
    cout << "Process   "
         << "Burst Time "
         << "Waiting Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << bt[i] << "\t " << wt[i] << endl;
        result = result + wt[i];
    }
    result = result / n;
    cout << "Average Waiting Time :" << result << endl;
}
void averageTATime(int processes[], int n, int bt[], int wt[], int tat[])
{
    turnAroundTimeCalculation(processes, n, bt, wt, tat);
    double result = 0;
    cout << "Process  "
         << "Burst Time  "
         << "Turn Around Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t" << bt[i] << "\t " << tat[i] << endl;
        result = result + tat[i];
    }
    result = result / n;
    cout << "Average Turnaround time :" << result;
}
int main()
{

    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int bt[] = {11, 5, 9};
    int wt[n];
    int tat[n];
    int quantum = 2;
    averageWaitingTime(processes, n, bt, wt, quantum);
    averageTATime(processes, n, bt, wt, tat);
}
