#include<iostream>
using namespace std;
void generateBinaryStrings(int n,string output){
    if(n==0){
        cout<<output<<" ";
        return;
    }
    generateBinaryStrings(n-1,output+'0');
    generateBinaryStrings(n-1,output+'1');
}

int main(){
    int n;
    cout<<"Enter the length of binary strings: ";
    cin>>n;
    cout << "All binary strings of length "<<n<<" are:\n";
    generateBinaryStrings(n,"");
    return 0;
}
