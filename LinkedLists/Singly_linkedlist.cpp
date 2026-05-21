#include <cstddef>       // this provides mainly: NULL, nullptr, size_t, ptrdiff_t etc....
#include<iostream>
using namespace std;

/* linked lists mainly have : 
    - insert at beginning(pushfront)
    - insert at end(pushback)
    - insert at middle
    - delete at beginning(popfront)
    - delete from end(popback)
    - display
    - search by value
 */

class Node{
public :
    int data;
    Node* next;
    // This is a pointer and meaning of this is "next is a pointer that can store address of a Node.
    // indirectly Node is like data type."

    Node(int value){    // constructor
        data = value;        // assigning the value to the data.
        next = NULL;
    }
};

class List{ 
private: 
    Node* head;  
    Node* tail;         // Only the LL class should control it thats why it is private.(Encapsulation concept)
public:
    // constructor
    List(){
        head = tail = NULL;  // automatically intializes head to nullptr when an obj is created and make sure not to contain garbage values in it
    }

    void push_front(int val ){
        Node* newNode = new Node(val);  // new is the keyword which allocates the memory in heap dynamically.
        if(head == NULL){               // checks if the head is NULL that means no elements are there in the LL at present
            head = tail = newNode;       // if yes then assigns it to a newNode that is our value and returns nothing
            return;
        } else {                   // if any element is already existed in the LL then head wiil be assign the new value so 
                                   // so that the first element is now becomea the head
            newNode->next = head;
            head = newNode;
        }
    }
    
    void push_back(int val){
        Node* newNode = new Node(val);    
        // there are two ways to create objs for a class they are: 
        // 1.creating in stack memory like "List.ll"
        // 2.creating in heap memory like "Node* newnode = new Node(val)" for this we have to use the "new" keyword
        // this new kw will allocate and assigns the value to the variable and calls the constructor.
        if(head == NULL){
            head = tail = newNode;
        }   else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){ // we create temporary because we've to store the value of head and shift the head to next then del the temp
        if(head == NULL){
            cout << "Linked list is empty\n";
            return ;
        }   
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    
    void pop_back(){
        if(head == NULL){
            cout << "Linked list is empty\n";
            return;
        }
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }
// inserting an element at a particular position
    void insert(int val, int pos){
        if(pos < 0){
            cout << "Invalid position\n";
            return;
        }
        if(pos == 0){           // adding at position 0 is nothing but pushing front
            push_front(val);
            return;
        }
        Node* temp = head;
        for(int i = 0; i < pos - 1; i++){          // stopping at the prev of the position node because we want to break the link b/w pos and prev node
            if(temp == NULL){
                cout <<  "Invalid position\n";
                return;
            }
             temp = temp->next;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
// checking for emptyness
    bool isEmpty(){
        return head = NULL;
    }
// finding the length of a linked list
    int lengthOf_linkedList(){
        int count = 0;
        Node* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
// searching an element
    bool search(int target){
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == target){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
// delete at a position
    void delete_at_position(int pos){
        if(pos < 0){
            cout << "Invalid Position\n";
            return;
        }
        if(pos == 0){
            pop_front();
            return;
        }
        Node* temp = head;
        for(int i = 0; i < pos - 1; i++){
            if(temp->next == NULL){
                cout << "Invalid position\n";
                return;
            }
            temp = temp->next;
        }
        Node* node_to_delete = temp->next;
        if(node_to_delete == NULL){
            cout << "Invalid position\n";
            return;
        }
        temp->next = node_to_delete->next;
        if(node_to_delete == tail){
            tail = temp;
        }
        delete node_to_delete;
    }
// reversing a linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        tail = head;  // After reversing, old head becomes tail

        while (current != nullptr) {
            nextNode = current->next;  // store next
            current->next = prev;      // reverse link
            prev = current;            // move prev forward
            current = nextNode;        // move current forward
        }

        head = prev;  // update head to new front
    }

    void printLL(){            // to display the LL we assume a temp ptr and traverse upto end of the linked list 
        Node* temp = head;         // here traversing happens only with the help of head ptr coz its a singly linkedlist

        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

};

int main(){

    List ll;           // creating an obj
    ll.push_front(9);
    ll.push_front(10);
    ll.push_front(11);
    ll.push_front(12);
    ll.push_front(13);

    ll.pop_front();
    ll.pop_front();

    ll.printLL(); 
    
    ll.reverse();

    ll.printLL(); 

    return 0;
}

/*
==================== WITHOUT OOPS (STRUCT BASED IMPLEMENTATION) ====================

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; 
    
};

Node* head = NULL;

// Insert at beginning
void push_front(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void push_back(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete from beginning
void pop_front() {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void pop_back() {
    if (head == NULL) return;

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Print list
void printLL() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Reverse list
void reverse() {
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}
*/