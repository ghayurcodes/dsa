#include<iostream>
//cbt:(complete binary tree) A complete binary tree is a binary tree in which every level, 
//except possibly the last, is completely filled, and all nodes in the last level are as far left as possible

//heap is a cbt that comes with heap order property




class heap{
    public:
    int a[20];
    int size;

    heap(){
        size=0;
        a[size]=-1;
    }

    void insert(int val){

        size=size+1;
        int index=size;
        a[index]=val;

        while(index>1){
            int parent=index/2;

            if
        }
    }

};



using namespace std;
int main(){
    cout<<"hey\n";
}