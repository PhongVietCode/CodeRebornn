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