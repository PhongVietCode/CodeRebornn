#include<iostream>
#include<math.h>
#include<queue>
using namespace std;
struct BstNode{
        int data; 
        BstNode*left; // con tro tro vao node
        BstNode*right;
    BstNode(int data){
        this->data = data;
        left  = right = NULL;
    }
    };
BstNode* insert(BstNode* root, int data){
    BstNode * node = new BstNode(data);
    if (root == NULL){
        root = node;
    }
    else if (data <= root->data){
        root->left = insert(root->left, data); 
        // insert(left,data) will creat a root = node (bc root is NULL in this case)
        // --> root->left = new node;
    }
    else 
        root->right =  insert(root->right, data);
    return root;
}
BstNode* search(BstNode *root, int data){
    if (root == NULL) return NULL;
    else if (root->data == data) return root; // found
    else if (data <= root->data) return search(root->left, data);
    else return search(root->right, data);
}
BstNode* findmin(BstNode*root){
    if (root == NULL){
        return root;
    }
    while(root->left != NULL)
        root = root->left;
    return root;
}
int findmax(BstNode*root){
    if (root == NULL){
        cout <<"tree is empty\n";
        return -1;
    }
    if (root->right == NULL) return root->data; //dk dung
    return findmax(root->right); // tai sao return lam gi
}
int recursionheight(BstNode*root){ // cho nay chua hieu lam
    if (root == NULL){
        return 0;
    }
    return max(recursionheight(root->left),recursionheight(root->right)) + 1; // + 1 bc we add the edge of root connect with the subtree
}
int iterativeHeight(BstNode*root){
    int height = -1;
    int nodecount = 0;// this count all node in a current level
    //and push all the children in to the queue 
    BstNode *temp;
    queue<BstNode* > q;
    q.push(root);
    while(!q.empty()){
        nodecount = q.size();
        // if the number of node in the next levle is 0 -> leaf node -> return height
        if (nodecount == 0){
            return height;
        }
        else // else height + 1 -> have one more level
            height++;
        //Remove all the node in this level
        // and push new node of next level
        while (nodecount > 0){
            temp = q.front();// take the first node of the queue
            q.pop();
            if (temp ->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
            nodecount--;
        }
    }
    return height;
}
void traversal(BstNode*root){ // -level order - time O(n) - space -O(1)
    if (root == NULL)  return;
    cout << root->data<< " ";
    BstNode *temp;
    queue<BstNode* > q;
    q.push(root);
    while(!q.empty()){
        if (!q.empty()){
            temp = q.front();
            q.pop();
        }
        if (temp->left != NULL){
            q.push(temp->left);
            cout << temp->left->data<<" ";
        }
        if (temp->right != NULL){
            q.push(temp->right);
            cout << temp->right->data<<" ";
        }
        
    }
}
/*Preorder: root- left-right
  Inorder: left-root-right
  Postorder: left-right-root
  */
void Preorder(BstNode*root){
    if (root == NULL)
        return;
    cout << root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(BstNode*root){
    if (root == NULL)
        return;
    Preorder(root->left);
    cout << root->data<<" ";
    Preorder(root->right);
}
void Postorder(BstNode*root){
    if (root == NULL)
        return;
    Preorder(root->left);
    Preorder(root->right);
    cout << root->data<<" ";
}
bool isBST(BstNode *root){
    queue<BstNode*>q;
    BstNode*temp = root;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if (temp->left->data <= temp->data)
            q.push(temp->left);
        else return false;
        if (temp->right->data > temp->data)
            q.push(temp->right);
        else return false;
    }
    return true;
}
bool isBstUtil(BstNode*root, int min, int max){
    if (root == NULL) return true;
    if (root->data > min 
    && root->data < max 
    && isBstUtil(root->left,min,root->data) 
    && isBstUtil(root->right,root->data,max))
        return true;
    // left subtree: min not change, max value is the value of root .
    // right subtree: min is the value of root, max not change.
    // max and min is macro
    else return false;
}
// delete a node in a tree: case3: 2 children -> get min value in right or get max value in left
BstNode* deletenode(BstNode * root, int data)
{
    if (root == NULL){
        return root;
    }
    else if (data < root->data){
        root->left = deletenode(root->left,data);
    }
    else if (data > root->data){
        root->right = deletenode(root->right,data);
    }
        
    else{// found
        // case 1: no children
        if (root->left == NULL && root->right == NULL){
            delete root;
            root = NULL; 
        } 
        // case2: 1 children 
        else if (root->left == NULL){
            BstNode*temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL){
            BstNode*temp = root;
            root = root->left;
            delete temp;
        }// case 3: 2 children
        else{ //case 3: 2 children
            BstNode* temp = findmin(root->right);
            // copy the data of the min node
            root->data = temp->data;
            // delete the duplicate node
            root->right = deletenode(root->right,temp->data);
        }  
    }
    return root;
}
/*Inorder successor: 
a node that have a right subtree->inoder successor will be the left most in its right subtree
a node that does not have a right subtree ->  look under the code for more information 
*/ 
BstNode*getsuccessor(BstNode*root, int data){
    // search the node
    BstNode*cur = search(root, data);
    if (cur == NULL) return NULL;
    // case 1: has right subtree
    if (cur->right != NULL){
       return findmin(cur->right); // go right and go to the left most
    }
    // case 2: no right subtree
    else {
        BstNode*successor = NULL; // the follow the ancestor
        BstNode*ancestor = root;
        while(ancestor != cur){
            if (cur->data < ancestor->data){ // set successor as ancestor because the cur is in the left subtree of the ancestor
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else ancestor = ancestor->right; 
            /* not set successor = ancestor because the ancestor
            has been visited before so we must go to the neastest ancestor that the cur is the left subtree of it*/ 
        }
        return successor;
    }
}

//GRAPH REPRESENTATION

    //1. creat 2 list store vertices(ARRAY) and edge(CLASS)
    // this represent is costly because it cost O(n^2) because
    // in the worse case with n vertices it has n(n-1) edges;
    class Edge{
        int startvertex; // get index from the ARRAY storing vertices
        int endvertex;
        int cost;
    };
    //2. create a n.n matrix for storing edge -> ADJACENCY MATRIX
    // Collum is start point, row is end point 
    // - This will reduce the time we find connected node and edge connnected
    // but the space we use for storing adjacency matrix is O(v^2)
    // This is good if the graph is dense even if the vertes is square 
    
    //3.ADJACENCY LIST : use a linked list to store the end vertex of each start vertex
    // initialize an array that each element is the pointer to the head of each linked list
    // SPACE: O(e) - e for edge 
int main(){
    /*TREE: --> Recursive data structure 
       Node at the top called ROOT
       Node dont have children callled LEAF
       Node have same parent called SIBLINGS
       Links are not bi-directional
       A->B
       A is ancestor of B
       B is descendent of A 
       Subtree
       N node -> N - 1 links  
       Nodes just accept incoming link
       - Depth of x is length of path from root to node x tu tren xuong
       - Height of x is the length of path from x to leaf tu duoi len
       --> height of tree is height of root
       Binary tree: 
            each node just have 2 children 
        Application: 
            Storing naturally -> hierarchical data
            Organize data -> for quick search, insertion, deletion
            Network Routing algorithm
        */
    /*BINARY TREE: Each node just have 2 children 
        STRICT BINARY TREE: Each node must have 2 or 0 children
        COMPLETE BINARY TREE:  all node have same level 
        are completely filled and last level must not com-filled but as left as possible  

        Max node at level i  = 2^i.
        PERFECT BINARY TREE: all is filled  
        Number of node = 2^no_level - 1
        Max node of height h = 2^(h + 1) -1 
        Height of perf-bina-tree has n node: h = log2(n+1) -1
        Height of comp-bina-tree has n node: round(log2(n))
        Balanced Bina_tree: height of left subtree - height of right subtree < 1
        Height of empty tree: -1;
        --- if one node  = 0;
        TMPLEMENTATION: 
            - dynamically create node
            --> struct.... int , *left, *right
            - Arrays(complete bina-tree): 
            index of left child: 2i+1, right child: 2i+2
       */
    /*BINARY SEARCH TREE
    Search, Insert, Remove: O(logn)
    all the value in the left is lesser or equal
    all the value in the right is greater
        */
    BstNode *root = NULL; //  address of the tree
    root = insert(root, 10);
    
    /*GRAPH:
    Like a tree but there is no rule for connection
    (a,b)->order
    {a,b}->unorder
    A graph with all the directed edge is digraph else is undirected graph
    A weighted graph is the graph has edge cost
    Type edge: self-loop
                multiedge -> each edge has different cost
    Number of edge: 0 <= e <= n(n-1) for directed 
                    0 <= e <= n(n-1)/2 for undirected
    --> there is no self-loop or multiedge here
    PATH(Walk): a sequence vertices is connected by an edge
    Simlpe path(path): there is no vertices is repeated 
    Trail: there is no edge is repeated 
    Strongly connected and weekly connected: there is a path to any other vertex 
    Close walk(cylcle: edge is not repeated)!= acyclic graph: start and end at same vertex */
    
    return 0;
}