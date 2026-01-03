#include <bits/stdc++.h>
using namespace std;

// Time complexity- O(N*logN) + O(N)
struct Meeting{
    int start;
    int end;
    int pos;
};
class Solution {
public:
    static bool cmp(Meeting a, Meeting b){
        return a.end< b.end; //asc
    }
    vector<int> maxMeetings(vector<int>& start, vector<int>& end){
        int n= start.size();
        vector<Meeting> meetings(n);        // if removed n..use push back for pushing to the meetings array
        vector<int> res;

        for(int i=0; i<n; i++){
            meetings[i]= { start[i], end[i], i+1 };
        }

        sort(meetings.begin(), meetings.end(), cmp);
        res.push_back(meetings[0].pos);   //first meeting can always be takedn
        int lastEnd= meetings[0].end;

        for(int i=1; i<n; i++){
            if( meetings[i].start > lastEnd ){
                res.push_back(meetings[i].pos);
                lastEnd= meetings[i].end;
            }
        }
        return res;
    }
};

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    Solution sol;
    vector<int> res = sol.maxMeetings(start, end);
    for (int idx : res) cout << idx << " ";
}


// for returning count

// #include<bits/stdc++.h>
// using namespace std;

// struct Meeting{
//     int start;
//     int end;
// };

// bool cmp(Meeting a, Meeting b){
//     return a.end < b.end;     //asc order
// }

// int maxMeetings(vector<int>& start, vector<int>& end){
//     int n= start.size();
//     vector<Meeting> meetings(n);
//     for(int i=0 ; i<n ;i++){
//         meetings[i]= {start[i], end[i]};
//     }

//     sort(meetings.begin(), meetings.end(), cmp);

//     int count=1;     
//     int lastEnd= meetings[0].end;
//     for(int i=1 ; i<n ;i++){
//         if(meetings[i].start > lastEnd){
//             count++;
//             lastEnd= meetings[i].end;
//         }
//     }
//     return count;
// }

// int main(){
//     vector<int> start={2,3,9,7};
//     vector<int> end= {5,10,11,9};
//     int res= maxMeetings(start, end);
//     cout<<"The max meetings that can be held in meeting room are "<<res<<endl;
// }