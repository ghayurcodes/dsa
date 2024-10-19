#include <iostream>
                                             //fifo (first in first out)

using namespace std;

class que{
    int front;
    int rear;
    int size;
    int *arr;



    que(int size){
        this->size=0;
        arr=new int[size];
        this->front=0;
        this->rear=0;
    }



    void push(int data){
        if(rear==size){
            cout<<"overflowed \n";
        }
        else{

        }
    }
};

int main() {
    
}
