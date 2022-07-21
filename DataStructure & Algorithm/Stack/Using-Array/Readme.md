# Stack Data-structure

A stack is a linear data structure that follows the principle of Last In First Out (LIFO). This means the last element inserted inside the stack is removed first.<br>

You can think of the stack data structure as the pile of plates on top of another.<br>

**Here, you can :**<br>

Put a new plate on top<br>
Remove the top plate<br>
And, if you want the plate at the bottom, you must first remove all the plates on top. This is exactly how the stack data structure works.<br>

**LIFO Principle of Stack :**<br>

In programming terms, putting an item on top of the stack is called push and removing an item is called pop.<br>

**Basic Operations of Stack :**<br>

There are some basic operations that allow us to perform different actions on a stack.<br>

_Push :_ Add an element to the top of a stack<br>
_Pop :_ Remove an element from the top of a stack<br>
_IsEmpty :_ Check if the stack is empty<br>
_IsFull :_ Check if the stack is full<br>
_Peek :_ Get the value of the top element without removing it<br>

**Algorithm :**<br>

The operations work as follows:<br>

1. A pointer called TOP is used to keep track of the top element in the stack.<br>
2. When initializing the stack, we set its value to -1 so that we can check if the stack is empty by comparing TOP == -1.<br>
3. On pushing an element, we increase the value of TOP and place the new element in the position pointed to by TOP.<br>
4. On popping an element, we return the element pointed to by TOP and reduce its value.<br>
5. Before pushing, we check if the stack is already full<br>
6. Before popping, we check if the stack is already empty<br>

**Complexity :**<br>

1. Popping an element from a stack will take O(1) time complexity. Popping the last element in a stack will take O(n).<br>
2. pushing an element from a stack will take O(1) time complexity. pushing at last element in a stack will take O(n).<br>
3. find an element from array is O(n).<br>
4. access an element from array is also o(n).<br>

**Source :**<br>

1. https://medium.com/swlh/stacks-and-queues-f281aa5462cf
2. https://www.programiz.com/dsa/stack#:~:text=A%20stack%20is%20a%20linear,plates%20on%20top%20of%20another.
3. https://www.geeksforgeeks.org/time-complexities-of-different-data-structures/
