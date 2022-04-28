#include <iostream>
using namespace std;
int maxm[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;
void takeinput()
{
    int i, j;
    cout << "Enter the no of Processes:";
    cin >> n;
    cout << "Enter the no of resources instances: ";
    cin >> r;
    cout << "Enter the Maximum Matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            cin >> maxm[i][j];
        }
    }
    cout << "Enter the Allocation Matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            cin >> alloc[i][j];
        }
    }
    cout << "Enter the available Resources:\n";
    for (j = 0; j < r; j++)
    {
        cin >> avail[j];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            need[i][j] = maxm[i][j] - alloc[i][j];
        }
    }
}
void display()
{
    int i, j;
    cout << "Process\t\tMaximum\t\tAllocation\tNeed\t\tAvailable\t";
    for (i = 0; i < n; i++)
    {
        cout << endl;
        cout << "P" << i + 1 << "\t\t";
        for (j = 0; j < r; j++)
        {
            cout << maxm[i][j] << " ";
        }
        cout << "\t\t";
        for (j = 0; j < r; j++)
        {
            cout << alloc[i][j] << " ";
        }
        cout << "\t\t";
        for (j = 0; j < r; j++)
        {
            cout << need[i][j] << " ";
        }
        cout << "\t\t";
        if (i == 0)
        {
            for (j = 0; j < r; j++)
                cout << avail[j] << " ";
        }
    }
}
void cal()
{
    int finish[100];
    int temp, flag = 1, k;
    int c1 = 0;
    int safe[100];
    int i, j;
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }
    cout << "\n";
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            int c = 0;
            for (j = 0; j < r; j++)
            {
                if ((finish[i] == 0) && (need[i][j] <= avail[j]))
                {
                    c++;
                    if (c == r)
                    {
                        for (k = 0; k < r; k++)
                        {
                            avail[k] += alloc[i][j];
                            finish[i] = 1;
                            flag = 1;
                        }
                        cout << "P" << i + 1 << "-->";
                        if (finish[i] == 1)
                        {
                            i = n;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 1)
        {
            c1++;
        }
        else
        {
            cout << "P" << i + 1 << "-->";
        }
    }
    if (c1 == n)
    {
        cout << "THE END";
        cout << "\n The system is in safe state";
    }
    else
    {
        cout << "\n Process are in dead lock";
        cout << "\n System is in unsafe state";
    }
    cout << endl;
}
int main()
{
    takeinput();
    display();
    cal();
    return 0;
}
