//create class cricketer
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class cricketer{
public:
    string name;
    int age;
    int noOFtest;

};
int main(){
    // cricketer rohit;
    // rohit.name="rohit sharma";
    // rohit.age=34;
    // rohit.noOFtest=100;
    // cricketer virat;
    // virat.name="virat kohil";
    // virat.age=33;
    // virat.noOFtest=120;
    string name;
    int age;
    vector<cricketer> cricketers;
    for(int i=0;i<5;i++){
        cricketer s;
        cout<<"enter name :";
        cin>>s.name;
        cout<<"age :";
        cin>>s.age;
        cricketers.push_back(s);
    }
    for(int i=0;i<5;i++){
        cout<<"name :"<<cricketers[i].name<<endl;
        cout<<"age :"<<cricketers[i].age<<endl;
        //cout<<"no of test match :"<<cricketers[i].noOFtest<<endl;
    }
}