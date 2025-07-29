#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<string> ans;
    vector<string> addOperators(string num,int target){
        dfs(0,"",0,0,num,target);
        return ans;
    }

    private:
    void dfs(int i,string path, long long resSoFar, long long prevNum, string &num, int target){
        if(i==num.length()){
            if(resSoFar==target){
                ans.push_back(path);
            }
            return;
        }
        for(int j=i ; j< num.size() ;j++){
            if(j>i && num[i]=='0') break ;  // this skips exprssions like 05,06
            string currStr= num.substr(i,j-i+1);
            int currNum= stoll(currStr);
            if(i==0 ){                               // for first number
                dfs( j+1 , currStr, currNum, currNum, num, target);
            }else{
                dfs(j+1,path+"+"+ currStr, resSoFar+ currNum, currNum, num,target );
                dfs(j+1,path+"-"+ currStr, resSoFar- currNum, -currNum, num,target );
                dfs(j+1,path+"*"+ currStr, resSoFar-prevNum+prevNum*currNum, prevNum*currNum , num,target );
            }
        }
        
        for(int j=i ; j<num.size() ;j++){
            if(j>i && num[i]=='0') break;
        }
    }
};
int main(){
    Solution s;
    string num="123";
    int target=6;
    vector<string> res=s.addOperators(num,target);
    for(string x:res)cout<<x<<endl;
    return 0;
}
