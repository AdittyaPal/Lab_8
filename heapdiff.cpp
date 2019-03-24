#include<iostream>
using namespace std;
class BinaryHeap
{
    public:
    int* arr;//pointer to the beginning of the array which implements the binary heap
    int maxSize;//stores the maximum size of the array
    int currSize;//stores the current size of the array
    BinaryHeap(int maxSize)//parametrized constructor
    {
        arr=new int[maxSize];//array with the passed size is declared
        this->maxSize=maxSize;//date memeber maxSize is initialized
        currSize=0;//current size is inilialized to zero
    }//end of parameterized constructor
    void swap(int a,int b)//function to swap the elements at two array indices
    {
        arr[a]=arr[a]+arr[b];
        arr[b]=arr[a]-arr[b];
        arr[a]=arr[a]-arr[b];
    }//end of the function to swap two elements
    void insert(int num)//function to insert an element into the heap
    {
        if(currSize==maxSize)//if array index is out of bounds
        cout<<"Heap Overflow\n";//the heap overflows
        else
        {
            arr[currSize++]=num;//the value is added to the next element in the array
            minHeapifyUp(currSize-1);
        }
    }//end of function to insert an element into heap
    void displayTree(int i,int space)//function to display the elements as a tree
    {
        if(i<currSize)//if the end of the subtree has not been reached
        {
            displayTree(i*2+2,++space);//the right subtree is displayed with an increased tab space
            cout<<endl;//a new line to print the current node value
            for(int i=1;i<space;i++)//for loop to print the correct number of
            cout<<"\t";//tab spaces
            cout<<arr[i]<<endl;//the value at the root of the current subtree is displayed
            displayTree(i*2+1,space);//the left subtree is displayed
        }
    }//end of function to display the elements as a tree
    void extractMin()//function to return the minimum of the elements in the heap
    {
        if(currSize==1)//else if there is one value in the heap
        currSize--;//that value is returned
        else
        {
            arr[0]=arr[--currSize];//the last element of the array is stored in the root
            minHeapifyDown(0);//the element at the root is placed in its correct position in the heap
        }
    }//end of function to return the minimum of the elements in the heap
    void deleteAt(int i)//function to delete the element at index i.
    {
        if(i<currSize)
        {
            arr[i]=arr[0]-1;//the element at index i is made the minimum in the heap
            minHeapifyUp(i);
            extractMin();//that minimum is extracted using extractMin()
        }
        else
        cout<<"Index to be deleted does not store an element.\n";
    }
    void minHeapifyUp(int i)//function to check the relation of a child with its parent
    {
        if(i>0&&arr[i]<arr[(i-1)/2])//the relation of the child with the parent is checked
        {
            swap(i,(i-1)/2);//and swapped if the rule is not satisfied
            minHeapifyUp((i-1)/2);//the rule is checked for the parent of the current node
        }
    }//end of function to check the relation of a child with its parent
    void minHeapifyDown(int i)//function to check the realtion of the parent with the child
    {
        int least=i;//stores the index of the child with the minimum value
        if(i*2+1<currSize&&arr[i*2+1]<arr[least])//the relation of the left child with the parent is checked
        least=i*2+1;
        if(i*2+2<currSize&&arr[i*2+2]<arr[least])//the relation of the right child with the parent is checked
        least=i*2+2;    
        if(least!=i)//if the rule is not satisfied
        {
            swap(i,least);//they are swapped
            minHeapifyDown(least);//the rule is checked for the child of the current node
        }
    }//end of function to check the realtion of the parent with the child
};
int main()
{
    int max=0;
    cout<<"Enter the capacity of the binary heap.\n";
    cin>>max;
    BinaryHeap bh1(max);
    int choice=0;
    int value=0;
    cout<<"Enter 1 till the user wants to input elements into the heap else 0.\n";
    do
    {
        cout<<"Enter your choice.\n";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter the value to be inserted into the heap.\n";
            cin>>value;
            bh1.insert(value);
        }
    }while(choice!=0);
    bh1.displayTree(0,0);
    cout<<"Enter 1 till the user wants to delete elements from the heap else 0.\n";
    do
    {
        cout<<"Enter your choice.\n";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter the index to be deleted from the heap.\n";
            cin>>value;
            bh1.deleteAt(value);
            bh1.displayTree(0,0);
        }
    }while(choice!=0);
    cout<<endl;
}
