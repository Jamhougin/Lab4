Lab 4 C++

Deadline 19th November @ 11 am.

All code must be consistently indented. Variables must be appropriately named. 
Using the linkedlist code from blackboard to complete the lab. Lab Book Diary
You must also show your lab book, when demoing the code.

The lab book shows your work as you do it and illustrates your approach to solving the problems below.  The lab book is worth 10%.

You must both demo the lab and upload the code to get a mark.

When you are demoing the lab you will be asked questions about the code. 

All methods must work correctly at least 
when the list is Empty,
when passing a  null pointer,
when the frontPointer is being altered
if a pointer passed as a parameter is not in the list 
Provide tests that fully test the methods including the above situations

// search for the first item with the value d as data

//return a pointer to the item found

Item* Search(int data);

// erase the item pointed to by loc

void Erase(Item *loc);

// insert a copy of data before or after loc

void InsertBefore(Item *loc, int data);

void InsertAfter(Item *loc, int data);

//push a copy of data on to the back(end ) of the list. PushBack adds an item to the end of the list.

void PushBack(int data);

//returns true if  PopBack is successful. Popback removes the last item in the list.Fill data with a copy the data in the node

bool PopBack(int &data);

//returns true if  PopFront is successful. Pop an item from the front of the list. Fill data with a copy of the data in the node.

bool PopFront(int &data);

void DeleteFront();

void DeleteAll();

