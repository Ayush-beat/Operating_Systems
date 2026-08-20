//FCFS Method using same arrival time as 0
#include<iostream>
using namespace std;
int main()
{
    int n,sum_wt=0,sum_tat=0,sumb=0;
    float TP,avgw,avgt;
    cout<<"Enter the no. of Processes : ";
    cin>>n;
    //Accepting ID's, Required Times
    int p[n],a[n],b[n],w[n],r[n],tat[n],c[n];
    cout<<"___---Enter the Process ID, Arrival Time & Burst Time---___"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<i+1<<" : ";
        cin>>p[i]>>a[i]>>b[i];
    }
    w[0]=0;
    for(int i=1;i<n;i++)
    {
        w[i]=w[i-1]+b[i-1];
    }
    for (int i = 0; i < n; i++)
    {
        c[i]=w[i]+b[i];
        tat[i]=c[i];
        r[i]=w[i];
    }
    //Displaying all Times
    cout<<"Process_ID   Arrival_Time  Burst_Time  Waiting_Time  TAT  Completion_Time  Response_Time "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<p[i]<<"\t\t"<<a[i]<<"\t\t"<<b[i]<<"\t\t"<<w[i]<<"\t"<<tat[i]<<"\t"<<c[i]<<"\t\t"<<r[i]<<"\n";
    }
    for(int i=0; i<n; i++)
    {
        sum_wt=sum_wt+w[i];
        sum_tat=sum_tat+tat[i];
        sumb=sumb+b[i];
    }    
    avgw=(float)sum_wt/n;
    avgt=(float)sum_tat/n;
    TP=(float)n/sumb;
    cout<<"Average Waiting Time : "<<avgw<<endl;
    cout<<"Average Turn around Time : "<<avgt<<endl;
    cout<<"ThroughPut : "<<TP;
    return 0;
}