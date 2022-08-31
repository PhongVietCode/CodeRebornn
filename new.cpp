#include <bits/stdc++.h>
using namespace std;
using namespace ::chrono;

void merge_arr(int *arr, int start, int middle, int end)
{
    int *temp = new int[end - start + 1];
    int i = start, j = middle, k = 0;  
    while(i <= middle && j <= end){
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else 
            temp[k++] = arr[j++];
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
    // int arr[] = {0, 29, 284, 31,1};
    // mergesort(arr,0, sizeof(arr) / sizeof(arr[0])-1);
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }

//-----------
#pragma region
    vector<int> values(10000);
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