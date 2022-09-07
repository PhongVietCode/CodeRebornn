#include <bits/stdc++.h>
using namespace std;
using namespace ::chrono;

struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 bool isPalindrome(ListNode* head) {
        if (head == NULL) return false;
        ListNode  *prev, *slow = head, *front , *fast = head->next->next;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        prev = slow;
        slow = slow->next;
        prev->next = NULL;
        while (slow){ // dao ve sau lai
            front = slow->next;
            slow->next = prev;
            prev = slow;
            slow = front;
        }
        slow = prev;
        fast = head;
        while(slow){
            if(fast->val != slow->val) return false;
            slow =slow->next;
            fast = fast->next;
        }
        return true;
    }
    while(i <= middle) 
            temp[k++] = arr[i++];
    while(j <= middle) 
            temp[k++] = arr[j++];
    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i - start];
    }
}
void mergesort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge_arr(arr, start, mid, end);
    } 
}
int findwinner(int n, int k ,int subn, int loser, int* a){
        // find the winner
        if (n == 1){
            for(int i = 1; i <= subn;i++){
               if (a[i]) return i;
            }
        }
        // find the loser
        loser += k - 1;
        // neu ma het 1 vong tron
        if (loser > subn){
           loser -= subn;
        }
        // check tai do
        while(a[loser] == 0)
            loser++;
        a[loser] = 0;
        //check dang truoc
        while(a[loser+1] == 0)
            loser++;
        
        return findwinner(--n,k,subn,loser + 1,a);
        
    }
    int findTheWinner(int n, int k) {
        int subn = n,loser = 1;
        int a[n + 1];
        for (int i = 0; i < n;i++){
            a[i] = 1;
        }
        
        return findwinner(n,k, subn, loser,a);
    }
int main()
{
    ListNode *head = NULL;
    ListNode *node1 = new ListNode(1,head);
    ListNode *node2 = new ListNode(2,node1);
    ListNode *node3 = new ListNode(2,node2);
    ListNode *node4 = new ListNode(1,node3);
    cout << isPalindrome(node4);
    // int arr[] = {0, 29, 284, 31,1};
    // mergesort(arr,0, sizeof(arr) / sizeof(arr[0])-1);
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }

//-----------
#pragma region
        vector<int>
            values(10000);
    // Generate Random values
    auto f = []() -> int
    { return rand() % 10000; };

    // Fill up the vector
    generate(values.begin(), values.end(), f);

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    // Call the function, here sort()
    sort(values.begin(), values.end());

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get duration. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time: "
         << duration.count() << " ms" << endl;
#pragma endregion
}