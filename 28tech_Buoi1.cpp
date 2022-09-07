#include <bits/stdc++.h>
using namespace std;
long long a[200005]; // se duoc auto gia tri la 0
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    long long ans = 1e18;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++){
        long long mx = 0, pre = 0;
        for (int j = i - 1; j >= 1; j--){
                // nâng cái số đằng trc lên 1 số có thể là bội số nhỏ nhất của số tiếp theo
            // để mà tìm ra số tiếp theo phải cộng thêm bao nhiêu lần mới lớn hơn 
             // xem coi có cần phải cộng thêm số dư để ra đúng bội số k
            pre += a[i] - pre % a[i]; // lấy số không chia hết hoặc chia hết cho số trc đó trừ đi
            // số dư -> ta được 1 số cố thể chia hết cho số trc nó rồi cộng thêm chính số trc
            // đó nữa để ra bội số nhỏ nhất cần tìm 
            mx += pre / a[i]; // tìm ra số n cần thiêt để cộng lên
        }
        pre = 0;
        for (int j = i + 1; j <= n; j++){
            // nâng cái số đằng trc lên 1 số có thể là bội số nhỏ nhất của số tiếp theo
            // để mà tìm ra số tiếp theo phải cộng thêm bao nhiêu lần mới lớn hơn 
           // xem coi có cần phải cộng thêm số dư để ra đúng bội số k
            pre += a[i] - pre % a[i]; // lấy số không chia hết hoặc chia hết cho số trc đó trừ đi
            // số dư -> ta được 1 số cố thể chia hết cho số trc nó rồi cộng thêm chính số trc
            // đó nữa để ra bội số nhỏ nhất cần tìm 
            mx += pre / a[i]; // tìm ra số n cần thiêt để cộng lên
        }
        ans = min(ans, mx);
    }
    cout << ans;
}