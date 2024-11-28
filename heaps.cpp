#include<iostream>
//cbt:(complete binary tree) A complete binary tree is a binary tree in which every level, 
//except possibly the last, is completely filled, and all nodes in the last level are as far left as possible

//heap is a cbt that comes with heap order property


using namespace std;

class heap{
    public:
    int a[20];
    int size;

    heap(){
        size=0;
        a[size]=-1;
    }

    void insert(int val){                       //insert and del time coleity O(logn)

        size=size+1;
        int index=size;
        a[index]=val;

        while(index>1){
            int parent=index/2;

            if(a[parent]<a[index]){
                swap(a[parent],a[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }




    void print(){
        for(int i=1;i<=size;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }



    void del(){
        if(size==0){
            cout<<"nothing to delete\n";
            return;
        }
        //steop1
        a[1]=a[size];
        //step 2
        size=size-1;

        //step 3 taking root node to corect position
        int i=1;
        while(i<size){
            int leftnode=i*2;
            int rightnode=i*2+1;


            if(leftnode<size && a[leftnode]>a[i]){
                swap(a[leftnode],a[i]);
                i=leftnode;
            }
            if(rightnode<size && a[rightnode]>a[i]){
                swap(a[rightnode],a[i]);
                i=rightnode;
            }
            else{
                return;
            }
        }
    }

};



using namespace std;
int main(){
    heap h;
    h.insert(34);
    h.insert(32);
    h.insert(31);
    h.insert(39);
    h.insert(22);
    h.insert(93);
    h.insert(99);


    cout<<"\t displaying\n";
    h.print();

    h.del();

     cout<<"\t displaying\n";
    h.print();
}