#include <iostream>
#include <string.h>
#include<vector>
using namespace std;
void func(int a[][3]){ // pass 2 dim array or **A
    
}
void funt(int a[][3][3]){ //  pass 3 dim array or ***A
       
}
void doublee(int* x){
    *x =*x * *x;
}

// creat struct for node
struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};
// function for ll
void addhead(Node*& head,int data){
    Node* node = new Node(data);
    // check head co null khong
    if (head == NULL){
        head = node;
        return;
    }
    node->next = head;
    head = node;
    return; 
}
void addTail(Node*head, int data){
    Node* node = new Node(data);
    Node*tail = head;
    if(head == NULL){
        head = node;
        tail = node;
        return;
    }
    // lay tail next bang null
    while(tail->next){
        tail = tail->next;
    }
    tail->next = node;
    tail = node;
}
void deletehead(Node*& head){
    if (head == NULL)
        return;
    head = head->next;
}
void deleteTail(Node*head){
    Node*tail =head;
    while(tail->next->next){
        tail = tail->next;
    }
    tail->next = NULL;
}
void deleteIndex(Node*& head, int index){
    Node* node = head;
    int count = 1;
    if (index == 1){
        deletehead(head);
        return;
    }
    while(node){
        if (count == index - 1){
            node->next = node->next->next;
            return;
        }
        node = node->next;
        count++;
    }
    cout <<"try another index" <<endl;
}
void insertIndex(Node* head, int index, int data){
    Node*node = new Node(data);
    Node*temp = head;
    int count = 1 ;
    
    while(temp){
        temp = temp->next;
        count++;
        if (count == index -1){
            node->next = temp->next;
            temp->next = node;
            return;
        }
    }
    cout<<"your index is bigger than the linked list size"<<endl;
}
// need three new nodes
void traverse(Node*& head){
    Node* prev = NULL;
    Node* cur = head;
    Node*next = NULL;
    while(cur){
        // chay next
        next=  cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;

}
void print(Node* head){
    Node* node = head;
    while(node){
        cout << node->data<<"->";
        node = node->next;
    }
    cout <<"NULL";
}

struct Vertex{
    float x,y,z;
};
std::ostream& operator<<(std::ostream& stream, const Vertex& vertex){
    stream << vertex.x<< ", "<<vertex.y<<", "<<vertex.z;
    return stream;
}
void Funcvec(vector<Vertex>& vec){ // pass by reference
    vec.push_back({7,8,9});
}
 
int main()
{
    //ARRAY
    // creat two dimenstions array
    // int b[3][3][3] = {{{0,1,2},{3,4,5},{6,7,8}},
    //                 {{9,10,11},{12,13,14},{15,16,17}}
    //                 ,{{18,19,20},{21,22,23},{24,25,26}}};
    // cout << *(*(*(b+2) + 2) + 1) <<endl<<
    //         *(*(b[2] +2) +1);   
    // funt(b);  
    // int x = 9;
    // cout <<endl<< x<<endl;
    // doublee(&x);
    // cout << x;

    //SINGLY LINKED LIST

    /*VECTOR: 
    creat new array copy and have new vector
    syntax: vector<type> vari_name;
    type: what is in the array
    store like this: <vertex> : will store in line, very optimal
                     <vertex*>: 
    INSTRUCTIONS: vector.erase(): remove a vector
                  vector.clear(): remove all vector
                  ...
    */
    vector<Vertex> verticles;
    verticles.push_back({1,2,3});
    verticles.push_back({4,5,6});
    Funcvec(verticles);
    //NORMAL PRINT: vector
    // for(int i= 0; i < verticles.size();i++){
    //     cout << verticles[i]<<endl; 
    // }
    /*ANOTHER WAY:
    if there is not &, v will copy the value of verticle
     to avoid that, we will add & and const to copy reference*/
    // for(const Vertex& v :verticles){
    //     cout << v<<endl; 
    // }

    verticles.erase(verticles.begin() +1);
    /*This instruction need an iterator: 
    is an object point to
    an element inside the container, we use it to move through the contents of the 
    container. it has five type: input, output, forward, bidirectional, random-access 
    In vector, we use begin() and end() as iterator
    Syntax: "vector<type>:: iterator vari_name" */
    Node *head =NULL;
    addhead(head, 1);
    addTail(head, 2);
    addTail(head,3);
    addTail(head,4);
    addTail(head,5);
    deleteIndex(head,2);
    print(head);

    return 0;  
}
