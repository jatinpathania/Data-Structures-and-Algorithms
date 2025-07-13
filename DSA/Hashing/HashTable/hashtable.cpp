#include <bits/stdc++.h>
using namespace std;

class HashTable{
    private:
    int buckets;
    list<int> *table;   //pointer to said buckets   
    public:
    HashTable(int b){
        buckets=b;
        table=new list<int>[buckets];
    }

    void insert(int d);
    void print();
};

void HashTable:: insert(int d){
    int bucket = d%buckets;
    table[bucket].push_back(d);
}

void HashTable::print(){
    for(int i=0 ;i<buckets ;i++){
        cout<<"Bucket "<<i<<" | ";
        for(auto j : table[i]){
            cout<<"-> | "<<j<<" | ";
        }
        cout<<endl;
    }
}
int main()
{
    //create a hashtable with 8 buckets
    HashTable ht(8);
    // set random number seed
    srand(2);
    for(int i=1 ;i<20 ;i++){
        ht.insert(rand()%100);
    }
    ht.print();
return 0;
}