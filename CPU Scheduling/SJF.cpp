// SJF Method
#include <iostream>
using namespace std;

int main()
{
    int n, sum_wt = 0, sum_tat = 0, sumb = 0;
    float avgw, avgt, TP;

    cout << "Enter the no. of Processes : ";
    cin >> n;

    // Accepting ID's, Required Times
    int p[n], a[n], b[n], w[n], r[n], tat[n], c[n], completed[n];

    cout << "___---Enter the Process ID, Arrival Time & Burst Time---___" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " : ";
        cin >> p[i] >> a[i] >> b[i];
        completed[i] = 0;
    }

    int time = 0;
    int count = 0;

    while (count < n)
    {
        int index = -1;
        int min_burst = 9999;

        // Find shortest available process
        for (int i = 0; i < n; i++)
        {
            if (completed[i] == 0 && a[i] <= time)
            {
                if (b[i] < min_burst)
                {
                    min_burst = b[i];
                    index = i;
                }
            }
        }

        // If no process has arrived
        if (index == -1)
        {
            time++;
            continue;
        }

        // Calculate Waiting Time
        w[index] = time - a[index];

        // Response Time for Non-Preemptive SJF
        r[index] = w[index];

        // Execute process
        time = time + b[index];

        // Calculate Completion Time and TAT
        c[index] = time;
        tat[index] = c[index] - a[index];

        completed[index] = 1;
        count++;
    }

    // Displaying all Times
    cout << "\nProcess_ID   Arrival_Time  Burst_Time  Waiting_Time  TAT  Completion_Time  Response_Time" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << p[i] << "\t\t"
             << a[i] << "\t\t"
             << b[i] << "\t\t"
             << w[i] << "\t"
             << tat[i] << "\t"
             << c[i] << "\t\t"
             << r[i] << "\n";
    }

    // Calculating averages
    for (int i = 0; i < n; i++)
    {
        sum_wt = sum_wt + w[i];
        sum_tat = sum_tat + tat[i];
        sumb = sumb + b[i];
    }

    avgw = (float)sum_wt / n;
    avgt = (float)sum_tat / n;
    TP = (float)n / sumb;

    cout << "\nAverage Waiting Time : " << avgw << endl;
    cout << "Average Turn around Time : " << avgt << endl;
    cout << "ThroughPut : " << TP;

    return 0;
}