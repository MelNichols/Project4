#include <iostream> 
#include <cstdlib>
#include <string>

using namespace std;


class LinkedList {
protected: 
	struct node {
		int data;
		node* next;
	};

	node* head = nullptr;
	node* curr = nullptr;
	node* tail = nullptr;
	node* track = nullptr;

public:
	LinkedList() {};
	~LinkedList() {};

	void Output()
	{
		curr = head;
		int count = 0;
		while (curr != nullptr) {
			cout << curr->data << " ";
			curr = curr->next;
			count++;
			if (count % 10 == 0){
			    cout << "\n";
			}
		}
	};

	void NewNode(int someData) 
	{ 
		node* n = new node;
		n->next = nullptr;
		n->data = someData;

		if (head != nullptr) {
			curr = head;
			while (curr->next != nullptr) {
				curr = curr->next;
			}
			curr->next = n;
		} else {
			head = n;
		}
		
		tail = n;
	};

	void Delete(int deleteData) 
	{
		node* deletePointer = nullptr;
		curr = head;
		while ((curr != nullptr) && (curr->data != deleteData)) {
			track = curr;
			curr = curr->next;
		}

		deletePointer = curr;
		curr = curr->next;
		track->next = curr;
		delete deletePointer;
		
	};

	void Insert(int insertData, int count)
	{
		node* n = new node;
		n->next = nullptr;
		n->data = insertData;

		if (head != nullptr) {
			curr = head;
			for (int i = 0; i < count - 2; i++) {
				curr = curr->next;
				track = curr->next;
			}
			curr->next = n;
			curr->next->next = track;
		}
		else
		{
			head = n;
		}
	};
	
int Length()
	{
	  	curr = head;
	  	int count = 0;
		while (curr != nullptr) {
			count++;
			curr = curr->next;
		}
		
		return count;
	};

virtual void merge(LinkedList left, LinkedList right, LinkedList list){
    
    int leftL = left.Length();
    int rightL = right.Length();
    int i, j = 0;
    
    while(i < leftL && j < rightL){
        left.curr = head;
        right.curr = head;
        list.curr = head;
        
        if(left.curr->data <= right.curr->data){
            list.curr->data = left.curr->data;
            list.curr-> next;
            left.curr-> next;
            i++;
        } else {
            list.curr->data = right.curr->data;
            list.curr-> next;
            right.curr-> next;
            j++;
        }
    }
    
    while(i < leftL){
        list.curr->data = left.curr->data;
        list.curr-> next;
        left.curr-> next;
        i++;
    }
        
    while(j < rightL){
        list.curr->data = right.curr->data;
        list.curr-> next;
        right.curr-> next;
        j++;
    }
};


virtual void mergeSort(LinkedList list, int min, int max){
    int mid = max / 2;
    if (max < 2) { return; }
    
    LinkedList left;
    LinkedList right;
    
    for(int i = 0; i < mid; i++){
        list.curr = head;
        int nodeValue = list.curr->data;
        left.NewNode(nodeValue);
        left.curr = left.curr-> next;
        list.curr = list.curr-> next;
    }
    
    for(int i = mid; i < max - 1; i++){
        list.curr = head;
        
        //iterates through the list to get to midpoint
        int count = 0;
		while (curr != nullptr && count < mid) {
			curr = curr->next;
		}
        
        int nodeValue = list.curr->data;
        right.NewNode(nodeValue);
        right.curr = right.curr-> next;
        list.curr = list.curr-> next;
    }
    
    int leftL = left.Length();
    int rightL = right.Length();
    
    mergeSort(left, 0, leftL);
    mergeSort(right, 0, rightL);
    merge(left, right, list);
}
};

int main()
{

	LinkedList MainList;
	
	for(int i=0; i<50; i++){
	    //generate random number and add to linked list
	    int randNode = rand() % 100;
	    MainList.NewNode(randNode);
	}

	cout << endl;

	MainList.Output();
	cout << "\n";
	
    /*
    MainList.mergeSort(MainList, 0, 50);
	
    When I call the function I get the following error: 
    timeout: the monitored command dumped core
    sh: line 1: 119431 Segmentation fault      timeout 10s main
    I went over the function code countless times but I can't figure out how to fix this in a linked list.
	*/
	
	MainList.Output();

	return 0;
}
