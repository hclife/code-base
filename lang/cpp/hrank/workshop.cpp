//Attending Workshops
#include<bits/stdc++.h>
using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop {
    int start,end;
    int duration;
};

struct Available_Workshops {
    Workshop *work;
    int n;
};

Available_Workshops *initialize(int *start,int *dur,int n) {
    Workshop *w=new Workshop[n];
    for (register int i=0;i<n;++i) {
        w[i].start=start[i];
        w[i].duration=dur[i];
        w[i].end=start[i]+dur[i];
    }
    Available_Workshops *aw=new Available_Workshops;
    aw->work=w;aw->n=n;
    return aw;
}

#define MAXV(x,y)       ((x)>(y)?(x):(y))
int CalculateMaxWorkshops(Available_Workshops *p) {
    Workshop *w=p->work;
    int data[1003];
    for (register int i=0;i<1003;++i) data[i]=1000006;
    for (register int i=0;i<p->n;++i) {
        int s=w[i].start,e=w[i].end;
        if (data[s]>e) data[s]=e;
    }
    int ans[1003];
    for (register int i=0;i<1003;++i) ans[i]=0;
    for (register int i=1000;i>=0;--i) {
        if (data[i]>1000000) {
            ans[i]=ans[i+1];
            continue;
        }
        int val=1;
        if (data[i]<=1000) val+=ans[data[i]];
        ans[i]=MAXV(ans[i+1],val);
    }
    return ans[0];
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
