#include<iostream>
#include<string>
using namespace std;
class student {
public:
    string name;
    int rollno;
    student(string n,int r){
        name=n;
        rollno=r;
    }
};
void change(student *chetan){ //*ptr=&s  
    chetan->name="bhandari";  //dereference
}
int main(){
    student chetan("chetan",45);
    cout<<chetan.name<<endl;
    change(&chetan);
    cout<<chetan.name<<endl;
}