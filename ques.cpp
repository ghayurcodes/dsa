#include <iostream>
                                             //fifo (first in first out)

using namespace std;

class que{
    int qfront;
    int rear;
    int size;
    int *arr;



    que(int size){
        this->size=0;
        arr=new int[size];
        this->qfront=0;
        this->rear=0;
    }



    void push(int data){
        if(rear==size){
            cout<<"overflowed \n";
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }



    void pop(){
        if(qfront==rear){
            cout<<"underflowed que is empty\n";
        }
        else{
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
        }
    }


    int front(){
        if(qfront==rear){
            cout<<"empty que";
            return -1;
        }
        else{
            return arr[qfront];
        }
    }


    bool isempty(){
        if(qfront==rear){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
    
}
