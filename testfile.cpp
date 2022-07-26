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
    REMOVE: Need 1 pointer  */
    struct Node{
        int data;
        Node* next;
        Node* prev;
        Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;   
    }
    };
    void inserthead(Node*& head,int data){
        Node* node = new Node(data);
        if (head == NULL){
            head = node;
            return;
        }
        node->next = head;
        head->prev = node;
        head = node;
        return;
    }
    void inserttail(Node*& head, int data){
        Node*node = new Node(data);
        Node*tail = NULL;
        if (head == NULL){
            head = node;
            tail = node;
            return;
        }
        tail = head;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = node;
        node->prev = tail;
        tail = node;
        return;
    }
    void deleteindex(Node*&head, int index){
    Node* temp = head;
    int count = 1;
    while(temp){
        if (count == index-1){
            temp->next = temp->next->next;
            (temp->next)->prev = temp;
            return;
        }
        temp = temp->next;
        count++;
    }
    cout << "your index is invalid";
}
    void printxuoi(Node*head){
    Node*temp = head;
    while(temp){
        cout<< temp->data<<"<->";
        temp = temp->next;
    }
    cout <<"NULL"<<endl;
    return;
}
    void printnguoc(Node*head){
    Node*temp = head;
    while(temp->next){
        temp = temp->next;
    }
    while(temp){
        cout << temp->data<<"<->";
        temp = temp->prev;
    }
    cout <<"NULL";
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
         



*/  
int main(){
    Node *head = NULL;
    inserthead(head,10);
    printnguoc(head);
    printxuoi(head);
    int num;
    cin>>num;
    cout <<"phong";
    cout << "thay doi lan 1";
    system("pause");
    return 0;
}
