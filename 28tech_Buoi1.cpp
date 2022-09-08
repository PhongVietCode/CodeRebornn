#include <bits/stdc++.h>
using namespace std;
long long a[200005]; // se duoc auto gia tri la 0
    if(a == '{' || a == '[' || a == '(')
    if(a == '}' || a == ']' || a == ')')
bool ispair(char a, char b){
    switch (a)
    {
    case '{':
        return b == '}';
        break;
    case '[':
        return b == ']';
        break;
    case '(':
        return b == ')';
        break;    
    default:
        break;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
}