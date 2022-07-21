#include <iostream>
//Max size of our stack array
#define MAX 10

using namespace std;

class Solution
{
    public:
    // initialize top array with -1
    int top = -1;
    // initialize stack array with max size
    int stack[MAX];
    
    // This is our main method, our all method will be called from here
    void MainMethod()
    {
        //printf top element
        Peek();
        //push an element in stack
        Push_Data(10);
        Push_Data(20);
        Push_Data(30);
        Push_Data(40);
        //printf top element
        Peek();
        // pop last element (40)
        Pop_Data();
        //printf after pop
        Peek();
        //push an element in stack
        Push_Data(100);
        Push_Data(60);
        //Printf all stack element
        Print_All_Element();
        
    };
    
    //Print all element 
    void Print_All_Element()
    {
        for(int i = 0; i <= top; i++)
        cout<<stack[i]<<" ";
        
        cout<<endl;
    }
    
    // Check array is emapty/not
    bool isEmpty()
    {
        if(top == -1)
        return true;
        
        return false;
    };
    //Check our starck array is full or not
    bool isFull()
    {
        if(top == MAX)
        return true;
        
        return false;
    };
    //before push an item, check stack is full or not
    int Push_Data(int value)
    {
        if(!isFull())
        {
            stack[++top] = value;
        }
        else cout<< "Array is full.Before push, make an pop operation."<<endl;
    };
    //before pop an item, check stack is empty or not
    void Pop_Data()
    {
        
        if(!isEmpty())
        {
            top = top - 1;
        }
        else cout<< "Array is empty.Before pop, make an push operation."<<endl;
    };
    //it will peek the top element
    void Peek()
    {
        if(!isEmpty())
        cout<<stack[top]<<endl;
        
        else cout<< "Array is empty"<<endl;
    }
};

int main(void)
{
    Solution obj;
    obj.MainMethod();
    
    return 0;
}