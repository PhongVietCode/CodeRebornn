#include<bits/stdc++.h>
using namespace std;
vector<int> num;// store single digit of b
int solve(int a, int b, int k){

    int res = 0;
    for (int i = a; i <= b;i++){
        int sum = 0;
        int temp = i;
        bool case1 = false;
        if(i % k == 0)
            case1 = true;
        while(temp >0){
            sum += temp%10;
            temp /= 10;
        }
        if (sum % k == 0 && case1)  res++;

        
    }
    return res;
}

int romantostring(string s){
    unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
                                   
   int sum = T[s.back()];
   for (int i = s.length() - 2; i >= 0; --i) 
   {
       if (T[s[i]] < T[s[i + 1]])
       {
           sum -= T[s[i]];
       }
       else
       {
           sum += T[s[i]];
       }
   }
   
   return sum;

}


 // Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
bool isSameTree(TreeNode* p, TreeNode* q) {
       bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL)
            return p == q;
        if(p->val != q->val) return false;
        else{
            return isSameTree(p->left,q->left)
            && isSameTree(p->right,q->right);
        }
    }
    /* c2:
    if (p == NULL || q == NULL)
            return p == q;
        return (p->val == q->val) && isSameTree(p->left,q->left)
            && isSameTree(p->right,q->right);
    */
    }
bool isEqual(TreeNode*leftrt,TreeNode*rightrt){
        if (leftrt == NULL || rightrt == NULL)
            return leftrt == rightrt;
        return leftrt->val == rightrt->val 
        && isEqual(leftrt->left,rightrt->right) 
        && isEqual(leftrt->right,rightrt->left);
    }
bool isSymmetric(TreeNode* root) {
        return isEqual(root->left,root->right);

        //iterative way:
        /*TreeNode *left, *right;
        if (!root)
            return true;
        
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        
        while (!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (NULL == left && NULL == right)
                continue;
            if (NULL == left || NULL == right)
                return false;
            if (left->val != right->val)
                return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;*/

    }
int depth (TreeNode *root) {
        if (root == NULL) return 0;
        return max (depth(root -> left), depth (root -> right)) + 1;
    }
int findheight(TreeNode*root){
    if (root == NULL)
        return 0;
    else
        return max(findheight(root->left), findheight(root->right)) + 1;
}

    bool isBalanced (TreeNode *root) {
        if (root == NULL) return true;
        
        int left=depth(root->left);
        int right=depth(root->right);
        
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
    TreeNode* p = s.top();
    s.pop();
    if (p){
        s.push(p->left);
        s.push(p->right);
        std::swap(p->left,p->right);
    }
    }
    return root;
    }
    // recursive
    /*0
    if (root) {
    invertTree(root->left);
    invertTree(root->right);
    std::swap(root->left, root->right);
}
return root;
*/
    int findsum (TreeNode* node){
        queue<TreeNode *> q1;
        q1.push(node);
        int sum = 0;
        while(!q1.empty()){
            TreeNode *temp = q1.top();
            q1.pop();
            sum += temp->val;
            if (temp->left)
                q1.push(temp->left);
            if (temp->right)
                q1.push(temp->right);
        }
        return sum;
    }
    int findTilt(TreeNode* root) {
        if (root->left != NULL || root->right != NULL)
            return abs(findTilt(root->left) - findTilt(root->right));
        if (root->left == NULL && root->right == NULL || root == NULL)
            return 0;
        else if (root->left != NULL && root->right != NULL)
            return abs(findsum(root->left) - findsum(root->right));
        else if (root->right != NULL)
            return findsum(root->right);
        else if (root->lef != NULL)
            return findsum(root->left);
    
    }
    int tiltsum = 0;
    int findtiltver2(TreeNode *root){
        DFS(root);
        return tiltsum;
    }
    int DFS(TreeNode*root){
        if (!root)
            return 0;
        int leftsum = DFS(root->left);
        int rightsum = DFS(root->right);
        tiltsum += abs(leftsum - rightsum);
        return leftsum + rightsum +root->val;
    }
TreeNode* sortedArrayToBST(vector<int>& nums) {
    vector<int> num;
    // bubble sort
    for (int i = 0; i < nums.size() -1 ; i++){
        num.push_back(nums[i]);
        for (int j = i; j < nums.size() - 1;j++){
            if (nums[i] < nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
                
        }
    }
    TreeNode *root;
    root->val = nums[0];
    TreeNode *temp = root;
    for (int i = 0; i < num.size() - 1;i++){
        TreeNode *node = new TreeNode(num[i]);
        if (node->val < temp->val)
            temp->left = node;
        else
            temp->right = node;
    }
    return root;
}
vector<int> twosum(vector<int> nums, int target){
    int n = nums.size();
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n;i++){
        arr[i] = make_pair(num[i], i);
    }

    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    while(left < right){
        int sum2 = arr[left].first + arr[right].first;
        if(sum2 == target)
            return {arr[left].first, arr[right].first};
        if (sum2 < target)
            left++;
        else
            right--;
    }
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    // cach 1: dung 2 node: 1 la dummy head 2 la temp, temp la node
    // chay, cai nao be hon thi temp next toi cai do
    // them truong hop cuoi cung thi temp next toi cai con du lai
    // nho xoa dummy bang cach cho temp =  dummy next -> delete dummy
    // return temp

    // cach2: recursive
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    if (list1->val <= list2 ->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else{

        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int findmax(vector<int> num, int index){
        int max = num[index];
        for (int i = index; i < num.size() -1 ;i++){
            if (max < num[i]) max = num[i];
        }
        return max;
    }
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int i = 0;
        for (i; i < prices.size() - 1;i++){
            if (min > prices[i]) min = prices[i];
        }
        if (prices[prices.size() - 1] == min )  return 0; 
        return findmax(prices, i + 1) - min;
    }

int main()
{
    
    return 0;
}