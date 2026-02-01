#include<iostream>
#include<vector>
using namespace std;
class MyCircularQueue {
public:
    int f;  //front
    int b;  //back
    int c;  //capacity
    int s;  //size
    vector<int>arr;
    MyCircularQueue(int k) {
        f=0;
        b=0;
        s=0;
        c=k;
        vector<int>v(k);
        arr=v;
    }
    bool enQueue(int value) {  //push back
        if(s==c) return false;
        arr[b]=value;
        b++;
        if(b==c) b=0;  //imp
        s++;
        return true;
    }
    bool deQueue() {    //pop front
        if(s==0) return false;
        f++;
        if(f==c) f=0;  //imp
        s--;
        return true;
    }
    int Front() {
        if(s==0) return -1;
        return arr[f];
    }
    int Rear() {
        if(s==0) return -1;
        if(b==0) return arr[c-1];   //imp
        return arr[b-1]; 
    }
    bool isEmpty() {
        if(s==0) return true;
        else return false;
    }
    bool isFull() {
        if(s==c) return true;
        else return false;
    }
    void display(){
        for(int i=f;i<b;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    MyCircularQueue q(5); //q(5) size declear
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50); 
    //q.display();
    //q.deQueue();
    //q.display();
    q.Front();
    // q.display();
}