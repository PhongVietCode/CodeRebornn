#include <iostream>
#include <string.h>
#include<stack> // stack from standard template library
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
void ReverseO1(char*c, int n){
    int j = n-1;
    for (int i =0;i < n/2;i++){
        if (i<j){
            char temp = c[i];
            c[i] = c[j];
            c[j] = temp;
        }
        j--;
    }
}
// Reverse use linked list:
/*creat stack<node*>
push
top them and set as head
pop()v */

int main()
{
    Node*head= NULL;
    inserthead(head,1);
    inserthead(head,2);
    inserthead(head,3);
    inserthead(head,4);
    inserthead(head,5);
    inserthead(head,6);
    printxuoi(head);
    reverseuselinkedlist(head);
    printxuoi(head);

    
    return 0;
}
