#include <iostream>
#include <stack>
#include <string.h>
#include<math.h>
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

#pragma region // ARRAY IMPLEMENTATION --> has limited size#

#define SIZE 5
int a[SIZE];
int top = -1;
void overflow(int a[])
{
    int new_a[SIZE * 2];
    for (int i = 0; i < SIZE; i++)
    {
        new_a[i] = a[i];
    }
    a = new_a;
}
void Push(int data)
{
    if (top == SIZE - 1)
    {
        overflow(a);
    }
    a[++top] = data;
}
void Pop()
{
    if (top == -1)
    {
        cout << "Stack is empty";
        return;
    }
    top--;
}
int Top()
{
    return a[top];
}
void print()
{
    for (int i = 0; i <= top; i++)
    {
        cout << a[i] << " ";
    }
}
#pragma endregion
#pragma region // LINKED LIST IMPLEMENTATION -->unlimited size
/*We will use the head of the linked list as
the top of the stack*/
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        this->data = x;
        next = NULL;
    }
};
Node *head = NULL;
void push(int data)
{
    Node *node = new Node(data);
    node->next = head;
    head = node;
}
void pop()
{
    head = head->next;
}
int topp()
{
    return head->data;
}
void isempty()
{
    if (head)
    {
        cout << "No empty";
    }
    else
        cout << "Empty";
}
void printnode()
{
    Node *node = head;
    while (node)
    {
        cout << node->data << " ";
        node = node->next;
    }
    free(node);
}
#pragma endregion
// APPLICATION OF STACK
void ReverseString(char *c, int n)
{
    stack<char> s;
    // stack<data type> var_name;
    for (int i = 0; i < n; i++)
    {
        s.push(c[i]);
    } // O(n)
    for (int i = 0; i < n; i++)
    {
        c[i] = s.top();
        s.pop();
    } // O(n)
}
void reverseuselinkedlist(Node *&head)
{
    stack<Node *> s;
    Node *temp = head;
    while (temp)
    {
        s.push(temp);
        temp = temp->next;
    }
    temp = s.top();
    head = temp;
    s.pop();
    while (!s.empty())
    {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}
bool checkpair(char a, char b)
{
    if (a == '{' && b == '}')
        return true;
    else if (a == '[' && b == ']')
        return true;
    else if (a == '(' && b == ')')
        return true;
    return false;
}
void BalanParenthese(char *c, int n)
{
    // last open first close
    // cai nao mo thi phai ben trai dong thi phai ben phai
    // push tat ca cac open bracket vao stack
    // khi thay close bracket thi xem
    // no co tuong thich voi top cua stack k
    // tuong thich thi yes else no
    stack<char> s;
    for (int i = 0; i < n; i++)
    {
        if (c[i] == '{' || c[i] == '[' || c[i] == '(')
        {
            s.push(c[i]);
        }
        else if (!s.empty())
        {
            if (checkpair(s.top(), c[i]))
                s.pop();
            else
            {
                cout << "Not balance parenthese!";
                return;
            }
        }
    }
    if (s.empty())
        cout << "Balance parentheses ^^";
    else
        cout << "Not balance parenthese!";
    return;
}
/*INFIX, PREFIX, POSTFIX
2+3 --> <operand><operator><operand>
first we need to find <operand><operand><operator>
then find next nextf
if prefix(dau dau)--> go from right to left
if postfix(dau sau)--> go from letf to right*/
int operation(char op, int n1, int n2){
    switch(op){
        case '+':
            return n1 +n2;
        case '-':  return abs(n1 - n2);
        case '*': return n1 *n2;
        case '/': return n1/n2;
        default : 
            return 0;
    }
}
char postfix(char *c)
{
    int num1, num2,num3;
    stack<char> s;
    for (int i = 0; i < strlen(c); i++)
    {
        if (c[i] >= '0' && c[i] <= '9')
            s.push(c[i]);
        else{
            num1 = s.top() - '0';
            s.pop();
            num2 = s.top() - '0';
            s.pop();
            s.push(operation(c[i], num1, num2) + '0');
        }
    }
    return s.top();
}
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

/*Infix, prefix, postfix
2+3 --> <operand><operator><operand>
first we need to find <operand><operand><operator>
then find next nextf */

int main()
{
    char c[50] = "23+65-+9*";
    cout <<postfix(c) -'0';
    return 0;
}