#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class heap{
    public:
    int size;
    int* arr;
    int current;

    heap(int size){
        this->size=size;
        arr=new int[size];
        current=0;
    }


    void add(int val){
        if(current==size){
        cout<<"array is full\n";
        return;
        }

        arr[current]=val;
        int index=current;
        current=current+1;
        while(index!=0){
            int parent=(index-1)/2;

            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                
                return;
               
            }
        }


    }



    void display(){
        for(int i=0;i<current;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int maxnum(){
        return arr[0];
    }


};

int main(){
    heap h(10);
    h.add(10);
    h.add(5);
    h.add(20);
    h.add(15);


    cout<<"displaying all:\n";
    h.display();

    cout<<"\nMin number in heap: "<<h.maxnum()<<" "<<h.maxnum()<<endl;
}

