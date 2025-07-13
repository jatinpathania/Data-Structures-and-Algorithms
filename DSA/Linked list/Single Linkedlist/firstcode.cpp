#include <iostream>
using namespace std;
struct Node{            // creating a self defining datatype...we can even use class here
    int data;
    Node* next= nullptr;
    public:
    Node(int data){
        this->data= data;
    }
};
int main()
{
    Node y= Node(10);
    Node *z= new Node(20);     // a pointer to the memory location....it is dynamically allocating a node with value 20
    cout<<y.data<<endl;
    cout<<y.next<<endl;

    cout<<z->data<<endl;
    cout<<z->next<<endl;
return 0;
}