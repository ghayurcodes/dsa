#include <iostream>
                                             //fifo (first in first out)

using namespace std;

class que{
    int qfront;
    int rear;
    int size;
    int *arr;

public:

    que(int size){
        this->size=size;
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

    void display(){
        if(qfront==rear){
            cout<<"que is empty\n";
        }
        else{
            for(int i=qfront;i<rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    que q(5);

    q.push(3);
    q.push(4);
    q.push(7);
    q.push(1);
    q.push(9);


    cout<<q.front();
    cout<<endl;
    q.pop();
    cout<<q.front();
    cout<<endl;
    q.display();

    
}
