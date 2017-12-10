**Table of Contents**

* [Walking a sequence](#walking-a-sequence)  
	* [in Python](#in-python)  
	* [in C](#in-c)  
		* [Kernighan and Ritchie  - The C Programming language](#kernighan-and-ritchie----the-c-programming-language)  
		* [Example: Finding an element in the list](#example-finding-an-element-in-the-list)  
		* [Example: Traversing to the tail](#example-traversing-to-the-tail)  
		* [Example: Traversing a list in the reverse](#example-traversing-a-list-in-the-reverse)  


# Walking a sequence

## in Python

```python

array = [2, 3, 4, 99, -1]

for i in range(len(array)): 
    # do something with elements in array
    print("element at position", i, array[i])

for elem in array: 
    # do something with elements in array
    print("Element", elem) 

```

## in C 

Idiomatic way of walking a sequence (array, linked list, etc) in C. 

```c
int array[SIZE]; 
for (int i = 0; i < SIZE; i++){ 
    // do something with element in array
    printf("element at position %d is %d", i, array[i]);
    //...
    //... 
} 

Node *head; // already points at a valid linked list 
for (Node *ptr = head; ptr != NULL; ptr = ptr->next){ 
    // do something with element in the list 
    printf("element(%p) has data %d", ptr, ptr->data);
    //...
    //...
}

```

### Kernighan and Ritchie  - The C Programming language
![linkWalk](http://j.mp/linkWalk)

### Example: Finding an element in the list  

Assume you have a handle to a particular node (say `Node* start`) in the linked list. Write a function that finds a node that matches a particular data value `d`. 

```c
Node* find(Node* start, int data) { 
    for (Node *ptr = start; ptr != NULL; ptr = ptr->next){ 
        // do something with element in the list 
        if (ptr->data == data){
            printf("Data found!\n"); 
            return ptr;  
        }
    }
    printf("Data %d not found!\n", data); 
    return NULL;
}
```

### Example: Traversing to the tail 

Assume you have a handle to a particular node (say `Node* start`) in the linked list. And the algorithm requires you to traverse to the tail node. If you were to write a function to the do the same,  this is how it would look like: 

```c
Node* traverse_to_tail(Node* start) { 
    Node *prev = NULL;
    for (Node *ptr = start; ptr != NULL; ptr = ptr->next){ 
        // do something with element in the list 
        prev = ptr; 
    }
    return prev; 
}
```

### Example: Traversing a list in the reverse 

Beginning at node `start`, the following function moves     
  - to the tail 
  - and reverse walks the list, printing the data values in the list. 
  - It is assumed that there is a valid `prev` field in the `Node` object

```c
void traverse_reverse(Node* start) {
    Node *tail = traverse_to_tail(start);
    
    for (Node *ptr = tail; ptr != NULL; ptr = ptr->prev){ 
        // do something with element in the list 
        printf("Element has %d\n", ptr->data);  
    } 
}
```

