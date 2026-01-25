#include<iostream>
#include<vector>
using namespace std;
class Minheap{
public:
    int arr[50];
    int idx;
    Minheap(){
        idx=1;
    }
    int top(){
        return arr[1];
    }
    void push(int x){
        arr[idx]=x;
        int i=idx;
        idx++;
        //swapping of i with parent till i==1
        while(i!=1){
            int parent = i/2;
            if(arr[i]<arr[parent]){
                swap(arr[i],arr[parent]);
            }
            else break;
            i = parent;
        }
    }
    void pop(){
        idx--; //idx one position age hota tha
        arr[1] = arr[idx];
        //rearrangement
        int i=1;
        while(true){
            int left = 2*i ,right=2*i+1;
            if(left > idx-1) break;
            if(right > idx-1){
                if(arr[i]>arr[left]){
                    swap(arr[i],arr[left]);
                    i=left;
                }
                break;
            }
            if(arr[left] <arr[right]){
                if(arr[i] > arr[left]){
                    swap(arr[i],arr[left]);//small element ke saat swap kiya
                    i=left;
                }
                break;
            } 
            else{
                if(arr[i] > arr[right]){
                    swap(arr[i],arr[right]);
                    i=right;
                }
                break;
            }
        }
    }
    int size(){
        return idx-1;
    }
    void display(){
        for(int i=1;i<=idx-1;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Minheap mh;
    mh.push(10);
    mh.push(20);
    mh.push(12);
    mh.push(22);
    mh.push(3);
    cout<<mh.top()<<endl;
    mh.display();
    mh.pop();
    mh.display();

}