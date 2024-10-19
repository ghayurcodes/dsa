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
       if((qfront==0 && rear==size-1)||(rear==(qfront-1)%(size-1))){
        cout<<"que is full\n";
       }
       else if(qfront==-1){
        qfront=rear=0;
        arr[rear]=data;
    
       }
       else if(rear==size-1 && qfront!=0){
        rear=0;
        arr[rear]=data;
       }
       else{
        arr[rear]=data;
            rear++;
       }
    }



    void pop(){
       if(qfront==-1){
        cout<<"quue ois empty\n";//emopty que

       }
       else if(qfront==rear){//pnly 1 element prest in que
        qfront=rear=-1;
       }
       else if(qfront==size-1){//to maintain cyclic nature
        qfront =0;
       }
       else{
        qfront++;//nprmal que
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
