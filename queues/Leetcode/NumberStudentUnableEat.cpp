#include<iostream>
#include<queue>
using namespace std;
int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int>q;
    int n=students.size();
    int s=0;  //sandwiches ghumega
    for(int i=0;i<n;i++){
        q.push(students[i]);
    }
    int count=0;
    while(q.size()>0 && count!=q.size()){
        if(q.front()==sandwiches[s]){
            q.pop();
            s++;
            count=0;
        }
        else {
            int r=q.front();
            q.push(r);
            q.pop();
            count++;
        }
    }
    return q.size();
}
int main(){
    vector<int>student={1,1,1,0,0,1};
    vector<int>sandwiches={1,0,0,0,1,1};
    int ans={countStudents(student,sandwiches)};
    cout<<ans;
}