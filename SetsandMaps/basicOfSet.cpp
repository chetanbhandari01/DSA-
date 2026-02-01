#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(1);  //not insert because duplicate not allow

    s.erase(2);   //it will delete 2 from set

    cout<<s.size()<<endl;

    //finding element in set
    int target = 3;
    //s.find() ->it searches in the set and
    //if it is not found then its return last element 
    if(s.find(target)!=s.end()){  //not equal to last element
        cout<<"exists "<<endl;
    }
    else cout<<"does not exist"<<endl;

    //for printing use for each loop
    for(int x : s){
        cout<<x<<" ";
    }

    
}