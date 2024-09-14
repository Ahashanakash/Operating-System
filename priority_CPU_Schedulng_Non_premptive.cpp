#include <bits/stdc++.h>
using namespace std;

struct process {
    string s;    
    int at;      
    int bt;      
    int pt;      
    int tat;     
    int wt;      
    int ct;      
};


bool cmp(const process &a, const process &b) {
    return a.at <  b.at;
}


void currenttime(process proc[], int n) {
    int ct = 0;
    int over = 0;
    vector<bool> done(n, false);

    while (over < n) {
        int hp = -1, idx = -1; 

        for (int i = 0; i < n; i++) {
            if (!done[i] && proc[i].at <= ct && proc[i].pt > hp) {
                hp = proc[i].pt;
                idx = i;
            }
        }

        if (idx != -1) {
            proc[idx].ct = ct + proc[idx].bt; 
            done[idx] = true;
            over++;
            ct = proc[idx].ct; 
        } else {
            ct++; 
        }
    }
}

void turnaroundtime(process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].ct - proc[i].at;
    }
}

void waitingtime(process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].wt = proc[i].tat - proc[i].bt;
        if (proc[i].wt < 0)
            proc[i].wt = 0;
    }
}

int main() {
    cout << "Number of processes: ";
    int n;
    cin >> n;
    
    process proc[n]; 
    
    cout << "Enter process name, priority, arrival time, and burst time:\n";
    for (int i = 0; i < n; i++) {
        cin >> proc[i].s >> proc[i].at >> proc[i].bt >> proc[i].pt;
    }

    sort(proc, proc + n, cmp);

    currenttime(proc, n);
    turnaroundtime(proc, n);
    waitingtime(proc, n);

    cout << "Process\tPriority\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << proc[i].s << "\t" << proc[i].pt << "\t\t" << proc[i].at << "\t" 
             << proc[i].bt << "\t" << proc[i].ct << "\t\t" << proc[i].tat << "\t\t" 
             << proc[i].wt << '\n';
    }

    return 0;
}
