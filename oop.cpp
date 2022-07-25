#include <iostream>
#include <string.h>
using namespace std;
// 10/7/22
class AbstractEmployee{
    virtual void Ask4Promotion() = 0;
};
class Employee : AbstractEmployee{
public:
    Employee(string name = "Dell biet", string company = "Dell biet", int age = 0){
        this->Name = name;
        this->Company = company;
        this->Age = age;
    }
    void Intro(){
        cout << "My name is: "<<
         this->Name << ". I am working in : "
         << this->Company<<"\n i am:"<< this->Age<< endl;
    }
    string getName(){
        return this->Name;
    }
    string getCompany(){
        return this->Company;
    }
    int getAge(){
        return this->Age;
    }
    void Ask4Promotion(){
        if (this->Age > 30)
        {
            cout << this->Name <<" got promoted"<<endl;
        }
        else{
            cout << this->Name << " must wait for more time"<<endl;
        }
    }
    virtual void Work(){
        cout << Name<< " is checking email "<<endl;
    }
protected:   
    string Name;
    string Company;
    int Age;
};
class Dev : public Employee{
    public:
        Dev(string name, string company, int age,string fav) : Employee(name,company,age){
            this->fav_pro = fav;
        }
        void Bug()
        {
            Employee::Intro();
            cout << getName()<< " likes to use "<< this->fav_pro<<endl;
        }
        void Work(){
        cout << Name<< " writing "<<this->fav_pro<<endl;
    }
    private:
        string fav_pro;
};
class Teacher: public Employee{
public:
    Teacher(string name, string company, int age, string subject)
        :Employee(name,company,age){
            this->subject = subject;
    }
    void Prepare(){
        cout << Name << " is preparing "<< this->subject<<endl;
    }
    void Work(){
        cout << Name<< " is teaching "<<this->subject<<endl;
    }
private:
string subject;
};


int main()
{
    Employee emp1 = Employee("Phong","Duc Phong",20);
    Employee emp2 = Employee("Han","duc Phong",40);
    
    Dev dev1 = Dev("Hung","FPT",31,"C++");  
    Teacher tec1 = Teacher("Thinh","NHH",36,"Math");
    
    Employee  *e1 = &dev1;
    Employee  *e2 = &tec1;

    cout <<"uigfqi";
    
    

}
//git remote add origin https://github.com/PhongVietCode/CodeHe.git