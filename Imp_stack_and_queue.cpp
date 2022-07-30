#include<iostream>
using namespace std;
 /*STACK lIFO: last in first out
    Instructions:
        pop(): delete head
        push(): add head
        top() : get the value at the top
        isempty(): return if the stack if empty
    --> All can be performed in constant time
    Used:
        Function call/Recursion
        undo in an editor
        balanced parenthese {[(]}
        tower of hanoi
    Complexcity:
        O(1) for (pop, push, size, peeking)
        but O(n) for search
    Problems: Bracket
        [{}] -> valid
        ({}) -> valid
        {([]) -> invalid
*/

#pragma region //ARRAY IMPLEMENTATION --> has limited size#

#define SIZE 5
int a[SIZE];
int top = -1;
void overflow(int a[]){
    int new_a[SIZE*2];
    for (int i = 0; i < SIZE;i++){
        new_a[i] = a[i];
    }
    a = new_a;
}
void Push(int data){
    if (top == SIZE -1){
        overflow(a);
    }
    a[++top] = data;
}
void Pop(){
    if (top == -1){
        cout << "Stack is empty";
        return;
    }
    top--;
}
int Top(){
    return a[top];
}
void print(){
    for (int i =0; i <= top;i++){
        cout << a[i]<<" ";
    }
}
#pragma endregion
#pragma region //LINKED LIST IMPLEMENTATION --> unlimited size
/*We will use the head of the linked list as 
the top of the stack*/
struct Node{
    int data;
    Node*next;
    Node(int x){
        this->data =x;
        next = NULL;
    }
};
Node*head = NULL;
void push(int data){
    Node* node = new Node(data);
    node->next = head;
    head = node;
}
void pop(){
    head = head->next;
}
int topp(){
   return head->data; 
}
void isempty(){
    if (head){
        cout <<"No empty";
    }
    else cout <<"Empty";
}
void printnode(){
    Node *node =head;
    while(node){
        cout << node->data<<" ";
        node = node->next;
    }
    free(node);
}
#pragma endregion

/* QUEUE FIFO: first in first out
    Has front and rear, add/offering means enqueue, remove/polling means dequeue
    INSTRUCTIONS:
        enqueue: O(1)
        dequeue: O(1)
        peeking: looking for a value at the front O(1)
        conttains: check the element is contained in the queue O(n)
        removal: remove the elements in the worst case O(n)
        is empty: check is empty O(1)
    USED:
        An waiting line models a queue
        keep track of the most recently added elements
        web sever
        breadth first searhch graph traversal
    IMPLEMENTATION BFS:

*/

int main(){
    
    free(head);
    return 0;
}