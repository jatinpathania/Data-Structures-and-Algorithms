// linked list is nothing but a collection of nodes
// in arrays we were able to delete any element at any time ... but in linked list we can't do any 
// a single element of linked list is known as node.
// If there is singly linked list then there is null stored in Next pointer..

// Operations
// 1. Insertion
// 2. Searching
// 3. Deletion

// newNode-> next= head;
// Head = newNode


// Insertion at beginning

//  create a new node
//  set next of new node as head
//  update head as newnode


//  Insertion at End

//  create a new node
//  traverse to last node
//  set last node next as newnode



//  Insertion at position

// create a newnode
// traverse till position
// set next of newnode as next of current 
// update next of currnode as newnode

// Traversal

// create a curr variable initilise as head
// while(curr != null)
// cout<< curr->data<<" "
// update curr as curr-> next


// Traveres till a given part

// create a curr variable initilise as head
// int count=1
// while(curr != null)
// coutt<arr.data
// arr= curr->next
// count++



// delete at head
// create a temp node and initilise it as head
// update head as head->next
// update next of temp as nullptr
// delte ptr


//delete at tail
//traverse to last 2nd node
// create a temp and initilise it next of 2nd last
// set next of current as null
// delete temp

// linked list takes more space so it is a major disadvantage
