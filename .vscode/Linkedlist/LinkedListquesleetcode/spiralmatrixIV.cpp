#include<iostream>
#include<vector>
using namespace std;
class node{
public:
    int val;
    node*next;
    node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class linkedlist{
public:
    node*head;
    node*tail;
    int size;
    linkedlist(){
        head=tail=NULL;
        size=0;
    }
    vector<vector<int>> spiralMatrix(int m, int n, node* head) {
        vector<vector<int>>arr(m,vector<int>(n,-1));
        int minr=0;
        int minc=0;
        int maxr=m-1;
        int maxc=n-1;
        node*temp=head;
        while(minc<=maxc && minr<=maxr){
            //right
            for(int j=minc;j<=maxc;j++){
                if(temp==NULL) return arr;
                arr[minr][j] =temp->val;
                temp=temp->next;
            }
            minr++;
            if(minr>maxr || minc>maxc) break;
            //down
            for(int j=minr;j<=maxr;j++){
                if(temp==NULL) return arr;
                arr[j][maxc]=temp->val;
                temp=temp->next;
            }
            maxc--;
            if(minr>maxr || minc>maxc) break;
            //left
            for(int j=maxc;j>=minc;j--){
                if(temp==NULL) return arr;
                arr[maxr][j]=temp->val;
                temp=temp->next;
            }
            maxr--;
            if(minr>maxr || minc>maxc) break;
            //up
            for(int j=maxr;j>=minr;j--){
                if(temp==NULL) return arr;
                arr[j][minc]=temp->val;
                temp=temp->next;
            }
            minc++;
        }
        return arr;
    }
    void display(vector<vector<int>>&v){
        int rows = v.size();
        int cols = v[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;i<cols;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    linkedlist ll;
    node*a=new node(1);
    node*b=new node(2);
    node*c=new node(3);
    node*d=new node(4);
    node*e=new node(5);
    node*f=new node(6);
    node*g=new node(7);
    node*h=new node(8);
    node*i=new node(9);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    g->next=h;
    h->next=i;
    int m=3;
    int n=3;
    vector<vector<int>>arr=ll.spiralMatrix(m,n,a);
    ll.display(arr);
}