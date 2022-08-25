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