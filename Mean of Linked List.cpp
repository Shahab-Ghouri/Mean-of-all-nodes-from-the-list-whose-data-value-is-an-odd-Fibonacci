// CODE BY SHAHAB GHOURI
// BS-CS ( FAST NUCES )

#include <iostream>
#define size 20			// defined the size of fibonacci series
using namespace std;


// creating node class of linked list

class node{
	public:
		int data;
		node *next;
};

// creating class for List
class LinkedList{
	public:
		node *head,*tail;			// head = starting node of LINKED LIST , similarly tail = last node of the list
		LinkedList(){
			head = NULL;
			tail = NULL;
		}
		
		
		// inserting a new node to the list from the end
		void insert(int n){
			node *temp = new node;
			temp->data = n;
			temp->next = NULL;
			if(head == NULL){			// if no list is present create one
				head = temp;
				tail = temp;
			}	// else if the list is present, just create a new node and linked it with the tail node, and create it as a tail node of the list
			else{
				tail->next = temp;
				tail = temp;
			}
		}
		
		// displaying the LINKED LIST
		void display(){
			node *temp;
			temp = head;
			while(temp != NULL){
				cout<<temp->data<<" -> ";
				temp = temp->next; 
			}
			cout<<"NULL";
		}
		
		//  checking odd number in Fibonacci Series
		// 	it's a bool function i.e. it will return a true or false value
		bool is_odd(int n){
			if(n % 2 != 0){
				return true;
			}
			else 
			return false;
		}
		
		// finding the average of list
		float average(int array[]){
			int count = 0;
			node *temp;
			temp = head;	// giving the temp pointer address of head i.e. giving the starting point of list
			int i =0 , sum = 0;
			float average;
			cout<<endl<<endl<<endl<<" Odd Fibonacci Nodes present int the Linked List are : { ";
			while(temp != NULL){				// loop will continue till the temp is equals to NULL i.e till it reaches to end
				if(is_odd(temp->data)){			// checkning if the node is odd or not
												// if odd then continue else move temp to next node
					for(int i=0 ; i<size ;i++){
						if(temp->data == array[i]){		// checking if node is equals to the number present in the fibonacci series
							count++;					// counter to check the count of odd fibonacci numbers in the list
							cout<<temp->data<<" ";
							sum+=temp->data;			// adding each odd fibonacci number present in the list
						}
					}
				}
				temp = temp->next;			// moving temp to next node
				
			}
			cout<<" }"<<endl;
			average = sum /(float)count;			// calculating the average 
			return average;
			

			
		}
		
};
// Global recursive Function to create Fibonacci series 
int FibonacciSeries(int array[],int n,int i,int sum){ 
	if(i>size){
		return 1;
	}
	sum += n;
	n = array[i-1];
	array[i] = sum;
	++i;
	return FibonacciSeries(array,n,i,sum);
}
main(){
	int fibonacci[size];
	fibonacci[0] = 0;
	FibonacciSeries(fibonacci,1,1,0);
	
	for(int i=0; i<size;i++){
		cout<<fibonacci[i]<<" ";
	}
	
	int n,x;
	
	// creating the object of LINKED LIST
	LinkedList obj;
	cout<<"\nEnter the size of Linked List : ";cin>>n;		// user will enter the size of list
	cout<<" Enter the Elements of Linked List : ";			// user will enter the elements of list
	for(int i=0; i<n; i++)
	{
		cin>>x;
		obj.insert(x);
	}
	cout<<endl<<" Linked List is : "<<endl;
	obj.display();
	
	// displaying the average of ODD FIBONCACCI SERIES 
	cout<<endl<<endl<<" Average of ODD FIBONCACCI SERIES IS : "<<obj.average(fibonacci);
}
