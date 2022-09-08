// postfix
// #include <bits/stdc++.h>
// using namespace std;
// long long a[200005]; // se duoc auto gia tri la 0

// bool tophigherprece(char top, char a){
//     bool ishigher = false;
//     if(top == '^') ishigher = true;
//     else if(top == '*'){
//         if (a == '^')
//             ishigher = false;
//         else
//             ishigher = true;
//     }
//     return ishigher;
// }
// void infixtopostfix(int n){
//     while(n--){
//         int i = 0;
//         stack<char> infix;
//         string postfix = "";
//         string c = "";
//         cin >> c;
//         while(c[i]){
//             if(c[i] == '(') // la open bracket thi push vao
//                 infix.push(c[i]);
//             else if (c[i] >= 'a' && c[i] <= 'z') // la chu thi cho vao day luon
//                 postfix += c[i];
//             else if(c[i] == ')'){ // close bracket thi pop het ra
//                 while(infix.top() != '('){
//                     postfix += infix.top();
//                     infix.pop();
//                 }
//                 infix.pop(); // pop dau mo ngoac ra
//             }
//             else{ // cac phep toan
//                 if(!infix.empty())
//                     if(tophigherprece(infix.top(),c[i])){ // neu bac cao hon thi pop ra luon
//                         postfix += infix.top();
//                         infix.pop();
//                     }
//                 infix.push(c[i]);
//             }
//             i++;
//         }
//         while(!infix.empty()){
//             postfix += infix.top();
//             infix.pop();
//         }
//         cout << postfix << endl;
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin >> n;
//     infixtopostfix(n);
// }
// max chuoi ngoac dung
// #include <bits/stdc++.h>
//     using namespace std;
//     long long a[200005]; // se duoc auto gia tri la 0
// chuoi ngoac dung
// void solve(int num){
//     while(num--){
//         stack<char> s;
//         stack<int> id;
//         int i = 0;
//         int maxlength = 0;
//         string n;
//         cin >> n;
//         while (n[i])
//         {
//             if (n[i] == '(')
//             {
//                 s.push(n[i]);
//                 id.push(i);
//             }
//             else
//             {
//                 if (!s.empty())
//                 {
//                     if (s.top() == '('){
//                         s.pop();
//                         id.pop();
//                     }
//                     else {
//                         s.push(n[i]);
                        
//                         id.push(i);
//                     }
//                 }else {
//                     s.push(n[i]);
//                     id.push(i);
//                 }
//             }
//             i++;
//         }

//         maxlength = n.length() - id.top() - 1;
//         int last = 0;
//         while(id.size()!= 1){
//             int last = id.top();
//             id.pop();           
//             maxlength = (last - id.top() - 1> maxlength)?(last-id.top() - 1): maxlength;
//         }
//         last = id.top(); // lay do dai cuoi cung
//         maxlength = (last> maxlength)?(last): maxlength;
//         cout <<maxlength<<endl;
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin >> n;
//     solve(n);
// }
// #include <bits/stdc++.h>
// using namespace std;
// long long a[200005]; // se duoc auto gia tri la 0

// void solve(string n){
//     int i = 0;
//     int level = 0, maxlevel = 0;
//     stack<char> s;
//     while(n[i]){
//         if(n[i] == '('){
//             s.push(n[i]);
//         }
//         else {
//             if (!s.empty()){
//                 if (s.top() == '('){
//                     level++;
//                     s.pop();    
//                 }
//             }
//         }
//         if(s.empty()){
//             maxlevel = max(level,maxlevel);
//             level = 0;
//         }
        
//         i++;
//     }
//     cout << maxlevel;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     string n;
//     cin >> n;
//     solve(n);
// }

// #include <bits/stdc++.h>
// using namespace std;
// long long a[200005]; // se duoc auto gia tri la 0

// void solve(string n){
//     int i = 0;
//     int level,maxlevel = 0;
//     stack<char> s;
//     stack<char> s2;
//     stack<int> id;
//     int size = n.length();
//     //loc cac vi tri ngoac sai
//     while(n[i]){
//         if(n[i] == '('){
//             s.push(n[i]);
//             id.push(i);
//         }
//         else {
//             if (!s.empty()){
//                 if (s.top() == '('){
//                     s.pop();
//                     id.pop();
//                 }
//                 else {
//                     s.push(n[i]);
//                     id.push(i);
//                 }
//             }else{
//                 s.push(n[i]);
//                 id.push(i);
//             }
//         }
//         i++;
//     }
//     // da chon ra duoc khoang co cac chuoi ngoac dung
//     int lastplace = size;
//     if(!id.empty()){
//         while(id.size() != 0){
//             // chon ra chuoi co ban dai nhat
//             level = 0;
//             for (int j = id.top() + 1;j < lastplace;j++){
//                 if(n[j] == '(')
//                     s2.push(n[j]);
//                 else{
//                     s2.pop();
//                     level++;
//                 }
//                 if (s2.empty()){
//                     maxlevel = level > maxlevel ? level : maxlevel;
//                     level = 0;
//                 }
//             }
//             lastplace = id.top();
//             id.pop();
//         }
//         for (int j = 0;j < lastplace;j++){
//             if(n[j] == '(')
//                 s2.push(n[j]);
//             else{
//                 s2.pop();
//                 level++;
//             }
//             if (s2.empty()){
//                 maxlevel = level > maxlevel ? level : maxlevel;
//                 level = 0;
//             }
//         }
//     }
//     else{
//         level = 0;
//         for(int j = 0;j < n.length();j++){
//             // chon ra chuoi co ban dai nhat
//             if(n[j] == '(')
//                 s2.push(n[j]);
//             else{
//                 s2.pop();
//                 level++;
//             }
//             if (s2.empty()){
//                 maxlevel = level > maxlevel ? level : maxlevel;
//                 level = 0;
//             }
//         }
//     }
//     cout << maxlevel;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     string n;
//     cin >> n;
//     solve(n);
// }
