//basic implementation of Min Heap
#include<iostream> 
#include<climits> 
using namespace std; 


//swapping of values between a and b
void swap(int *a,int *b)
{
	int temp = *a;
	*a=*b;
	*b=temp;
}

//Mininum heap class is defined in this part

class Minheap
{
	private :
		int *heap_arry;
		int heap_size;
		int capacity;


	public:
		//constructor ,Here Heap Array is constructed with capacity (cap) 
		Minheap(int capacity);

		//here,we get parent node
		int parent (int i){return((i-1)/2);}

		//Here, we get right node of it
		int right_child (int i){return(2*i);}

		//Here, we get left child node of it
		int left_child (int i){return((2*i)+1);}

		//function for inserting element in heap
		void insert_key(int key);

		//function for deleting element from heap
		void delete_key(int j);

		//function for finding mininum value from heap
		int extract_min(){return (heap_arry[0]);}

		//function for arranging heap's element to follow heap property 
		void heapify(int arr[], int n, int i) ;


};


Minheap :: Minheap(int cap)
{
	heap_size=0;
	capacity=cap;
	heap_arry=new int[cap];
}

void Minheap :: insert_key(int key)
{
	if(heap_size==capacity)
	{
		cout<<"heap_array is overflow\n";
	}

	heap_size++;
	int i=heap_size-1;
	heap_arry[i]=key;

	while(i!=0 && heap_arry[parent(i)]>heap_arry[i])
	{
		swap(&heap_arry[(parent(i))],&heap_arry[i]);
		i=parent(i);
	}
}

void Minheap :: delete_key(int j)
{
	heap_arry[j]=heap_arry[heap_size-1];
	heap_size--;

	heapify(heap_arry, heap_size,j);

}

void Minheap :: heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] < arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] < arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 


int main()
{
	Minheap h(10);

	h.insert_key(10);
	h.insert_key(0);
	h.insert_key(20);
	h.insert_key(14);
	h.insert_key(15);
	h.insert_key(1);
	h.insert_key(7);

	cout<< h.extract_min() <<"  ";

	h.delete_key(0);
	cout<< h.extract_min() <<"  ";

	return 0;
}