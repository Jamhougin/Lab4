//James Hall
//C00007006
#include <iostream>

class Item
{
public:
	int data;
	Item* nextItemPointer;

};
class List
{
public:
	Item* frontPointer;
	List() :frontPointer(NULL) {};
	~List()
	{
		deleteAll();
	}
	Item* search(int data) 
	{
		Item* returnPointer;
		if(frontPointer == NULL)
		{
			return NULL;
		}
		else
		{
			returnPointer = frontPointer;
			while (returnPointer->nextItemPointer != NULL || returnPointer->data == data)
			{
				if (returnPointer->data == data) {
					return returnPointer;
				}
				returnPointer = returnPointer->nextItemPointer;
			}
			return NULL;
		}
	}
	void erase(Item* loc) 
	{
		if(loc != NULL)
		{
			if (loc == frontPointer)
			{
				deleteFront();
			}
			else
			{
				Item* place = frontPointer;
				while (place->nextItemPointer != loc)
				{
					place = place->nextItemPointer;
				}
				Item* toDelete = place->nextItemPointer;
				place->nextItemPointer = place->nextItemPointer->nextItemPointer;
				delete toDelete;
			}
		}
	}
	void insertBefore(Item* loc, int data)
	{
		if (frontPointer == NULL || frontPointer == loc)
		{
			pushFront(data);
		}
		else if (loc != NULL)
		{
			Item* insertItem = new Item();
			Item* place = frontPointer;
			insertItem->data = data;
			insertItem->nextItemPointer = loc;
			while (place->nextItemPointer != loc)
			{
				place = place->nextItemPointer;
			}
			place->nextItemPointer = insertItem;
		}
	}
	void insertAfter(Item* loc, int data)
	{
		if (frontPointer == NULL || frontPointer == loc)
		{
			pushFront(data);
		}
		else if (loc !=NULL)
		{
			Item* insertItem = new Item();
			Item* place = frontPointer;
			insertItem->data = data;
			while (place != loc)
			{
				place = place->nextItemPointer;
			}
			insertItem->nextItemPointer = place->nextItemPointer;
			place->nextItemPointer = insertItem;
		}
	}
	void pushFront(int data)
	{
		Item* newItemPointer = new Item();
		newItemPointer->data = data;
		newItemPointer->nextItemPointer = frontPointer;
		frontPointer = newItemPointer;
	}
	void pushBack(int data)
	{
		Item* newItemPointer = new Item();
		newItemPointer->data = data;
		newItemPointer->nextItemPointer = NULL;
		Item* place = frontPointer;
		if (frontPointer == NULL) 
		{
			pushFront(data);
		}
		else
		{
			while (place->nextItemPointer != NULL)
			{
				place = place->nextItemPointer;
			}
			place->nextItemPointer = newItemPointer;
		}
	}
	bool popBack(int& data)
	{
		if (frontPointer != NULL)
		{
			Item* place = frontPointer;
			while (place->nextItemPointer != NULL)
			{
				place = place->nextItemPointer;
			}
			data = place->data;
			erase(place);
			return true;
		}
		return false;
	}
	bool popFront(int& data)
	{
		if (frontPointer != NULL)
		{
			data = frontPointer->data;
			deleteFront();
			return true;
		}
		return false;
	}
	void deleteFront()
	{
		if (frontPointer != NULL)
		{
			Item* temp = frontPointer;
			frontPointer = frontPointer->nextItemPointer;
			delete temp;
			
		}
	}
	void deleteAll()
	{
		while (frontPointer != NULL)
		{
			deleteFront();
		}
	}
	void Display()
	{
		if (frontPointer == NULL)
		{
			std::cout << "List is Empty\n";
		}
		else
		{
			for (Item* curItemPointer = frontPointer; curItemPointer != NULL; curItemPointer = curItemPointer->nextItemPointer)
			{
				std::cout << curItemPointer->data << " ";
			}
			std::cout << "\n";
		}
	}
};
int main()
{
	List myList;
	myList.deleteFront();						//Empty check
	myList.erase(myList.search(7));				//Empty check
	int popNum = NULL;	
	std::cout << "Empty list popBack check: ";
	if (myList.popBack(popNum))					//Empty check
	{
		std::cout << popNum << "\n";
	}
	else
	{
		std::cout << "Nothing Happened\n";
	}
	std::cout << "Empty list popFront check: ";
	if (myList.popFront(popNum))				//Empty check
	{
		std::cout << popNum << "\n";
	}
	else
	{
		std::cout << "Nothing Happened\n";
	}
	myList.pushBack(4);							//4
	std::cout << "pushBack(4) called: ";
	myList.Display();
	myList.deleteFront();
	std::cout << "deleteFront called: ";
	myList.Display();
	myList.pushBack(3);							//3
	if (myList.popBack(popNum))					
	{
		std::cout << "popBack(popNum) called: " << popNum << "\n";
	}
	myList.pushBack(6);							//6
	if (myList.popFront(popNum))				
	{
		std::cout << "popFront(popNum) called: " << popNum << "\n";
	}
	myList.pushBack(9);							//9
	std::cout << "pushBack(9) called: ";
	myList.Display();
	myList.pushFront(1);						//1 9
	myList.pushFront(3);						//3 1 9
	myList.pushFront(4);						//4 3 1 9
	myList.pushFront(2);						//2 4 3 1 9
	myList.pushFront(5);						//5 2 4 3 1 9
	std::cout << "pushFront(5) called: ";
	myList.Display();
	myList.deleteFront();						//2 4 3 1 9
	std::cout << "deletFront() called: ";
	myList.Display();
	myList.pushBack(7);							//2 4 3 1 9 7
	std::cout << "pushBack(7) called: ";
	myList.Display();
	myList.erase(myList.search(7));				//2 4 3 1 9
	std::cout << "erase(myList.search(7)) called: ";
	myList.Display();
	myList.erase(myList.search(4));				//2 3 1 9 
	std::cout << "erase(myList.search(4)) called: ";
	myList.Display();
	if (myList.popBack(popNum))					//2 3 1
	{
		std::cout << "popBack(popNum) called: " << popNum << "\n";
	}
	if (myList.popFront(popNum))				//3 1
	{
		std::cout << "popFront(popNum) called: " << popNum << "\n";
	}
	myList.insertBefore(myList.search(1), 4);	//3 4 1
	std::cout << "insertBefore(myList.search(1), 4) called: ";
	myList.Display();
	myList.insertBefore(myList.search(3), 8);	//8 3 4 1
	std::cout << "insertBefore(myList.search(3), 8) called: ";
	myList.Display();
	myList.insertAfter(myList.search(1), 2);	//8 3 4 1 2
	std::cout << "insertAfter(myList.search(1), 2) called: ";
	myList.Display();
	myList.insertAfter(myList.search(3), 9);	//8 3 9 4 1 2
	std::cout << "insertAfter(myList.search(3), 9) called: ";
	myList.Display();
	myList.deleteAll();
	myList.deleteAll();							//Empty check
	std::cout << "deleteAll() called: ";
	myList.Display();
	char enterChar;
	std::cout << "Enter any char to continue:\n";
	std::cin >> enterChar;
	return 0;
}