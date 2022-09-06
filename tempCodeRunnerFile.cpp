int demuoc(int n){
    int count = 0;
    for(int i = 1; i<=n ;++i){
        if(n%i== 0) count++;
    }
    return count;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n;
    cin >> n;
    int a[n];
    int max = 0;
    for (int i = 0; i <n ;i++){
        cin >> a[i];
        max = demuoc(a[i]) > max ? demuoc(a[i]): max;
    }
    cout << max;
    return 0;
}