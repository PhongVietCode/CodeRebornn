#include <iostream>
#include<string>
#include<set>
using namespace std;
class person{
    public: 
    float age;
    string name;
    bool operator < (const person& other) const{
        return this->age < other.age;
    }
    bool operator > (const person& other) const{
        return this->age > other.age;
    }
};
int main() {
    /*Syntax: std::set<T> objname;
    1. Set is a associative container that contains a sorted set 
    of unique objects of type key.
    2. Usually implement by a red-black tree
    3. insertion, removal, search have logirarthmic complexity
    4. We can pass the order of sorting while constructing set obj
    5. they store unique element and store in order*/
   set<int> Set = {1,2,3,4,5,1,2,3,4,5}; // default is ascending order  
    set<person, std::greater<person>> set = {{12,"my"},{20,"phong"},{30,"phu"}};
   for(const auto& e: set){
    cout << e.age<<" "<<e.name<<endl;
   }
    return 0;
}