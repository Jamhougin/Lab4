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
		if (frontPointer == NULL || frontPointer == loc || loc == NULL)
		{
			pushFront(data);
		}
		else
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
		else if (loc ==NULL)
		{
			pushBack(data);
		}
		else
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
	int popNum = NULL;							
	if (myList.popBack(popNum))					//Empty check
	{
		std::cout << popNum << "\n";
	}
	else
	{
		std::cout << "Nothing Happened\n";
	}
	if (myList.popFront(popNum))				//Empty check
	{
		std::cout << popNum << "\n";
	}
	else
	{
		std::cout << "Nothing Happened\n";
	}
	myList.pushBack(9);							//9
	myList.pushFront(1);						//1 9
	myList.pushFront(3);						//3 1 9
	myList.pushFront(4);						//4 3 1 9
	myList.pushFront(2);						//2 4 3 1 9
	myList.pushFront(5);						//5 2 4 3 1 9
	myList.deleteFront();						//2 4 3 1 9
	myList.pushBack(7);							//2 4 3 1 9 7
	myList.erase(myList.search(7));				//2 4 3 1 9
	myList.erase(myList.search(4));				//2 3 1 9 
	if (myList.popBack(popNum))					//2 3 1
	{
		std::cout << popNum << "\n";
	}
	if (myList.popFront(popNum))					//3 1
	{
		std::cout << popNum << "\n";
	}
	myList.insertBefore(myList.search(1), 4);	//3 4 1
	myList.insertBefore(myList.search(3), 8);	//8 3 4 1
	myList.insertAfter(myList.search(1), 2);	//8 3 4 1 2
	myList.insertAfter(myList.search(3), 9);	//8 3 9 4 1 2
	myList.Display();
	myList.deleteAll();
	myList.deleteAll();							//Empty check
	myList.Display();
	return 0;
}