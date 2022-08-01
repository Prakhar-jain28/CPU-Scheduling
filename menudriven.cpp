#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define imax INT_MAX
#define imin INT_MIN
const ll mod = 1e9 + 7;

class FCFS
{
    // Private data members
    int nProcess;             // number of processes
    vector<float> nBurstTime; // burst time of each process
    vector<float> fArrivalTime;
    // public datamember block
public:
    // copy constructor
    FCFS(int nProcess1, const vector<float> &nBurstTime1, const vector<float> &fArrivalTime1)
    {
        nProcess = nProcess1;
        for (int i = 0; i < nProcess; i++)
        {
            nBurstTime.push_back(nBurstTime1[i]);
        }
        for (int i = 0; i < nProcess; i++)
        {
            fArrivalTime.push_back(fArrivalTime1[i]);
        }
    }
    // member function declaration
    void WaitingTime();
    void AverageWaitingTime();
    void TurnAroundTime();
};
// Waiting time calculation for each process
void FCFS::WaitingTime()
{
    float fSum = 0;
    cout << "Waiting Time : ";
    for (int i = 0; i < nProcess; i++)
    {
        cout << fSum - fArrivalTime[i] << " ";
        fSum += nBurstTime[i];
    }
    cout << endl;
}
// code to calculate avg waiting time
void FCFS::AverageWaitingTime()
{
    float fSum = 0, x = 0;
    cout << "Average Waiting Time: ";
    for (int i = 0; i < nProcess; i++)
    {
        x += fSum - fArrivalTime[i];
        fSum += nBurstTime[i];
    }
    cout << (x / nProcess) << endl;
}
// code to calculate turn around time for each process
void FCFS::TurnAroundTime()
{
    float fSum = 0;
    cout << "Turnaround Time: ";
    for (int i = 0; i < nProcess; i++)
    {
        fSum += nBurstTime[i];
        cout << fSum - fArrivalTime[i] << " ";
    }
    cout << endl;
}

class SJF
{
    // Private data members
    int nProcess;             // number of processes
    vector<float> nBurstTime; // burst time of each process

    // public datamember block
public:
    // copy constructor
    SJF(int nProcess1, const vector<float> &nBurstTime1)
    {
        nProcess = nProcess1;
        for (int i = 0; i < nProcess; i++)
        {
            nBurstTime.push_back(nBurstTime1[i]);
        }
        sort(nBurstTime.begin(), nBurstTime.end());
    }
    // member function declaration
    void WaitingTime();
    void AverageWaitingTime();
    void TurnAroundTime();
};
// Waiting time calculation for each process
void SJF::WaitingTime()
{
    float fSum = 0;
    cout << "Waiting Time : ";
    for (int i = 0; i < nProcess; i++)
    {
        cout << fSum << " ";
        fSum += nBurstTime[i];
    }
    cout << endl;
}
// code to calculate avg waiting time
void SJF::AverageWaitingTime()
{
    float fSum = 0, x = 0;
    cout << "Average Waiting Time: ";
    for (int i = 0; i < nProcess; i++)
    {
        x += fSum;
        fSum += nBurstTime[i];
    }
    cout << (x / nProcess) << endl;
}
// code to calculate turn around time for each process
void SJF::TurnAroundTime()
{
    float fSum = 0;
    cout << "Turnaround Time: ";
    for (int i = 0; i < nProcess; i++)
    {
        fSum += nBurstTime[i];
        cout << fSum << " ";
    }
    cout << endl;
}

class Priority
{
    // Private data members
    int nProcess;
    vector<float> fBurstTime;
    vector<pair<int, int>> nPriority;

public:
    Priority(int nProcess1, const vector<float> &fBurstTime1, vector<pair<int, int>> &nPriority1)
    {
        nProcess = nProcess1;
        for (int i = 0; i < nProcess1; i++)
        {
            fBurstTime.push_back(fBurstTime1[i]);
        }

        for (int i = 0; i < nProcess1; i++)
        {
            nPriority.push_back(make_pair(nPriority1[i].first, nPriority1[i].second));
        }
        sort(nPriority.begin(), nPriority.end());
    }

    void WaitingTime();
    void AverageWaitingTime();
    void TurnAroundTime();
};

void Priority::WaitingTime()
{
    float fSum = 0;
    cout << "Waiting Time : ";
    for (int i = 0; i < nProcess; i++)
    {
        cout << fSum << " ";
        fSum += fBurstTime[(nPriority[i].second)];
    }
    cout << endl;
}

void Priority::AverageWaitingTime()
{
    float fSum = 0, x = 0;
    cout << "Average Waiting Time: ";
    for (int i = 0; i < nProcess; i++)
    {
        x += fSum;
        fSum += fBurstTime[(nPriority[i].second)];
    }
    cout << (x / nProcess) << endl;
}

void Priority::TurnAroundTime()
{
    float fSum = 0;
    cout << "Turnaround Time: ";
    for (int i = 0; i < nProcess; i++)
    {
        fSum += fBurstTime[(nPriority[i].second)];
        cout << fSum << " ";
    }
    cout << endl;
}

class RoundRobin
{
    // Private data members
    int nProcess;             // number of processes
    vector<float> nBurstTime; // burst time of each process
    float nTimeQunatum;
    // public datamember block
public:
    // copy constructor
    RoundRobin(int nProcess1, int nTimeQuantum1,
               const vector<float> &nBurstTime1)
    {
        nProcess = nProcess1;
        nTimeQunatum = nTimeQuantum1;
        for (int i = 0; i < nProcess; i++)
        {
            nBurstTime.push_back(nBurstTime1[i]);
        }
    }
    // member function declaration
    void WaitingTime();
    void AverageWaitingTime();
    void TurnAroundTime();
};
// Waiting time calculation for each process
void RoundRobin::WaitingTime()
{
    float fSum = 0, nCompleted = 0, fTemp[nProcess];
    int nIndex = 0;
    for (int i = 0; i < nProcess; i++)
    {
        fTemp[i] = nBurstTime[i];
    }
    cout << "Waiting Time : ";
    while (nCompleted != nProcess)
    {
        if (nIndex == nProcess)
            nIndex = 0;

        if (fTemp[nIndex] >= nTimeQunatum)
        {
            fTemp[nIndex] -= nTimeQunatum;
            fSum += nTimeQunatum;
            if (fTemp[nIndex] == 0)
            {
                nCompleted++;
                cout << "P" << nIndex + 1 << " -> " << fSum - nBurstTime[nIndex] << "     ";
            }
        }
        else if (fTemp[nIndex] < nTimeQunatum && fTemp[nIndex] != 0)
        {
            fSum += fTemp[nIndex];
            fTemp[nIndex] = 0;
            nCompleted++;
            cout << "P" << nIndex + 1 << " -> " << fSum - nBurstTime[nIndex] << "     ";
        }
        nIndex++;
    }
    cout << endl
         << endl;
}
// code to calculate avg waiting time
void RoundRobin::AverageWaitingTime()
{
    float fSum = 0, nCompleted = 0, fTemp[nProcess], fResult = 0;
    int nIndex = 0;
    for (int i = 0; i < nProcess; i++)
    {
        fTemp[i] = nBurstTime[i];
    }
    cout << "Average Waiting Time : ";
    while (nCompleted != nProcess)
    {
        if (nIndex == nProcess)
            nIndex = 0;

        if (fTemp[nIndex] >= nTimeQunatum)
        {
            fTemp[nIndex] -= nTimeQunatum;
            fSum += nTimeQunatum;
            if (fTemp[nIndex] == 0)
            {
                nCompleted++;
                fResult += fSum - nBurstTime[nIndex];
            }
        }
        else if (fTemp[nIndex] < nTimeQunatum && fTemp[nIndex] != 0)
        {
            fSum += fTemp[nIndex];
            fTemp[nIndex] = 0;
            nCompleted++;
            fResult += fSum - nBurstTime[nIndex];
        }
        nIndex++;
    }
    cout << fResult / nProcess << endl
         << endl;
}
// code to calculate turn around time for each process
void RoundRobin::TurnAroundTime()
{
    float fSum = 0, nCompleted = 0, fTemp[nProcess];
    int nIndex = 0;
    for (int i = 0; i < nProcess; i++)
    {
        fTemp[i] = nBurstTime[i];
    }
    cout << "Turn Around Time : ";
    while (nCompleted != nProcess)
    {
        if (nIndex == nProcess)
            nIndex = 0;

        if (fTemp[nIndex] >= nTimeQunatum)
        {
            fTemp[nIndex] -= nTimeQunatum;
            fSum += nTimeQunatum;
            if (fTemp[nIndex] == 0)
            {
                nCompleted++;
                cout << "P" << nIndex + 1 << " -> " << fSum << "     ";
            }
        }
        else if (fTemp[nIndex] < nTimeQunatum && fTemp[nIndex] != 0)
        {
            fSum += fTemp[nIndex];
            fTemp[nIndex] = 0;
            nCompleted++;
            cout << "P" << nIndex + 1 << " -> " << fSum << "     ";
        }
        nIndex++;
    }
    cout << endl
         << endl;
}

void fcfs()
{
    cout << "Enter the number of processes: ";
    int nProcesses;
    cin >> nProcesses;
    cout << "Enter the Burst time of all the processes: ";
    vector<float> nBurstTime;
    vector<float> fArrivalTime;
    for (int i = 0; i < nProcesses; i++)
    {
        float temp;
        cin >> temp;
        nBurstTime.push_back(temp);
    }
    cout << "Enter the Arrival Time of all the processes: ";
    for (int i = 0; i < nProcesses; i++)
    {
        float temp;
        cin >> temp;
        fArrivalTime.push_back(temp);
    }
    FCFS obj1(nProcesses, nBurstTime, fArrivalTime);
    obj1.WaitingTime();
    obj1.AverageWaitingTime();
    obj1.TurnAroundTime();
}

void sjf()
{
    cout << "Enter the number of processes: ";
    int nProcesses;
    cin >> nProcesses;
    cout << "Enter the Burst time of all the processes: ";
    vector<float> nBurstTime;
    for (int i = 0; i < nProcesses; i++)
    {
        float temp;
        cin >> temp;
        nBurstTime.push_back(temp);
    }
    SJF obj2(nProcesses, nBurstTime);
    obj2.WaitingTime();
    obj2.AverageWaitingTime();
    obj2.TurnAroundTime();
}

void ps()
{
    cout << "Enter the number of processes: ";
    int nProcesses;
    cin >> nProcesses;
    cout << "Enter the Burst time of all the processes: ";
    vector<float> fBurstTime;
    for (int i = 0; i < nProcesses; i++)
    {
        float temp;
        cin >> temp;
        fBurstTime.push_back(temp);
    }
    cout << "Enter the Priority for all the processes: ";
    vector<pair<int, int>> nPriority;
    for (int i = 0; i < nProcesses; i++)
    {
        float temp;
        cin >> temp;
        nPriority.push_back(make_pair(temp, i));
    }

    Priority obj3(nProcesses, fBurstTime, nPriority);

    obj3.WaitingTime();
    obj3.AverageWaitingTime();
    obj3.TurnAroundTime();
}

void rr()
{
    int nProcesses;
    cout << "Enter the number of processes: ";
    cin >> nProcesses;
    vector<float> nBurstTime;
    cout << "Enter the Burst time of all the processes: ";
    for (int i = 0; i < nProcesses; i++)
    {
        float temp;
        cin >> temp;
        nBurstTime.push_back(temp);
    }
    int nTimeQuantum;
    cout << "Enter the Time Qunatum:";
    cin >> nTimeQuantum;
    cout << endl;

    RoundRobin obj4(nProcesses, nTimeQuantum, nBurstTime);

    obj4.WaitingTime();
    obj4.AverageWaitingTime();
    obj4.TurnAroundTime();
}

int32_t main()
{

    ll iChoice;
    while (1)
    {
        cout << "Enter 1 -> First Come Firft Serve" << endl
             << "Enter 2 -> Shortest Job First" << endl
             << "Enter 3 -> Priority Scheduling" << endl
             << "Enter 4 -> Round Robin" << endl
             << "Enter 5 -> Exit" << endl;
        cin >> iChoice;
        switch (iChoice)
        {
        case 1:
            fcfs();
            break;

        case 2:
            sjf();
            break;

        case 3:
            ps();
            break;

        case 4:
            rr();
            break;

        case 5:
            cout << "----------------X--------------X----------------" << endl;
            return 0;
            break;

        default:
            cout << "Invalid Input" << endl;
            break;
        }
    }

    return 0;
}
