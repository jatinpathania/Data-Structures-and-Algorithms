#include<bits/stdc++.h>
using namespace std;

struct Meeting{
    int start;
    int end;
};

bool cmp(Meeting a, Meeting b){
    return a.end < b.end;     //asc order
}

int maxMeetings(vector<int>& start, vector<int>& end){
    int n= start.size();
    vector<Meeting> meetings(n);
    for(int i=0 ; i<n ;i++){
        meetings[i]= {start[i], end[i]};
    }

    sort(meetings.begin(), meetings.end(), cmp);

    int count=1;     //first meeting can always be takedn
    int lastEnd= meetings[0].end;
    for(int i=1 ; i<n ;i++){
        if(meetings[i].start > lastEnd){
            count++;
            lastEnd= meetings[i].end;
        }
    }
    return count;
}

int main(){
    vector<int> start={2,3,9,7};
    vector<int> end= {5,10,11,9};
    int res= maxMeetings(start, end);
    cout<<"The max meetings that can be held in meeting room are "<<res<<endl;
}