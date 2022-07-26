#include <iostream>
#include <string.h>
using namespace std;
/*HUONG DAN SU DUNG GITHUB CUA TUI
1. SAVE CHANGE TU MAY LEN GIT HUB
   GIT ADD
   GIT COMMIT
   GIT PULL
   GIT PUSH
2. SAVE CHANGE TU GITHUB VE MAY
 GIT PULL

*/
/* array
 static array: contain n elements, range from 0 to n -1, indexable
 dynamic array: how to implement this
 one way is using the static array
 1. create a static array with initial capacity
 2. add elements
 3. if full, creat a new static array and double its capacity, copy all the elements from old to new one and
 add element.
 REMOVE:
 Need 2 pointer trc và sau
*/
/*   DOUBLE- SINGLE LINKED LIST
 REMOVE: Need 1 pointer  meanwhile singly linked list needs 2 pointer
 Reverse is easy
 Extra  memory for one more pointer
 Becareful when add or delete a node because it has prev node */
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
void inserthead(Node *&head, int data)
{
    Node *node = new Node(data);
    if (head == NULL)
    {
        head = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
    return;
}
void inserttail(Node *&head, int data)
{
    Node *node = new Node(data);
    Node *tail = NULL;
    if (head == NULL)
    {
        head = node;
        tail = node;
        return;
    }
    tail = head;
    while (tail->next)
    {
        tail = tail->next;
    }
    tail->next = node;
    node->prev = tail;
    tail = node;
    return;
}
void deleteindex(Node *&head, int index)
{
    Node *temp = head;
    int count = 1;
    while (temp)
    {
        if (count == index - 1)
        {
            temp->next = temp->next->next;
            (temp->next)->prev = temp;
            return;
        }
        temp = temp->next;
        count++;
    }
    cout << "your index is invalid";
}
void RecursionPrint(Node* p){
    if (p == NULL) return; // stop condition
    cout << p->data<<" ";  
    RecursionPrint(p->next); // recurtion 
}
void RecursionReverPrint(Node*p){
    if (p == NULL) return; // stop condition
    RecursionReverPrint(p->next); // recurtion 
    cout << p->data<<" ";  
}
void printxuoi(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    return;
}
void printnguoc(Node *head)
{
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    while (temp)
    {
        cout << temp->data << "<->";
        temp = temp->prev;
    }
    cout << "NULL";
}
void Reverse(Node *&head)
{
    Node *cur = head;
    Node *prev = NULL;
    Node *nextt = NULL;
    while (cur != NULL)
    {
        nextt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nextt;
    }
    head = prev;
    return;
}
/*STACK lIFO: last in first out
    Instructions:
        pop(): delete head
        push(): add head
    Used:
        compilers
        tower of hanoi
    Complexcity:
        O(1) for (pop, push, size, peeking)
        but O(n) for search
    Problems: Bracket
        [{}] -> valid
        ({}) -> valid
        {([]) -> invalid
*/
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
int main()
{
    Node *head = NULL;
    inserthead(head, 10);
    inserthead(head, 11);
    inserthead(head, 12);
    inserthead(head, 13);
    inserthead(head, 14);
    RecursionReverPrint(head);
    
    return 0;
}
