#include<iostream>
#include<vector>
#include<string>
using namespace std;

// syntax: template<typename _name>
//  or : template<class _name>
// use when we dont care about the type of the input
// template doesn't really exist, it just exist when we call it
// don't loi dung template qua nhieu
template<typename T>
void print(T value){
    std:: cout << value <<endl;
}
template<typename V, int N> // this will specified be compile time
class Array{
    private:
    V m_array[N]; // neu ma khoi tao cai size luon thi se bi loi
    // tao mot cai template de khi khoi dong chuong trinh se khong bi
    //loi ma van co mot cai size cua array
public:
int getsize()const {return N;}
}; // intializ in main : Array<int, _size> _name

struct hocsinh{
    string name;
    int mssv;
    string ten_truong;
    
};
/// overload <<
// type: void()
// 2 operant: (ostream& or istream&, )  ->original object

void operator << (ostream& COUT, hocsinh& sv1){
    COUT << sv1.mssv<<" "<<sv1.name<<" "<<sv1.ten_truong<<endl;

}
struct school
{
    vector<hocsinh> back_khoa;

    void operator+=(hocsinh& sv){
        this->back_khoa.push_back(sv);
    }
    
    void printsv(){
        for (hocsinh sv: back_khoa){01098837827
            cout <<sv;
        }
    }
};
ostream& operator<<(ostream& COUT,school& s){
        for (hocsinh hs: s.back_khoa){
            COUT << hs;
        }
        return COUT;
    }


int main() {
    hocsinh sv1{"phong",2110446,"bach khoa"};
    hocsinh sv2{"Ling",2124146,"khoa hoc tu nhien"};
    hocsinh sv3{"Phus",2236123,"cnnt"};
    hocsinh sv4{"meomeo",231636,"bach khoa"};


    cout << sv1; // cai nay no khong biet phai cout cai gi
    // nen la minh phai tao mot cai ham ghi ra ho no ->overload
    school myschool;
    myschool += sv1;
    myschool += sv2;
    myschool += sv3;
    myschool += sv4;
    myschool -= sv4;


    cout << myschool;

    return 0;
}