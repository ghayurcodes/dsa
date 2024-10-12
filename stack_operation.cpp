#include<iostream>

using namespace std;//stacks LIFO (last in forst out)

class Doublestack{
    int top1;
    int top2;
    int* arr;
    int size;

    public:
    Doublestack(int size){
        this->size=size;
        arr=new int[size];
        top1=-1;
        top2=size;
    }


    void push1(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
            cout<<"element added\n";
        }

        else{
            cout<<"stack overflowed\n";
        }
    }

     void push2(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
            cout<<"element added\n";
        }

        else{
            cout<<"stack overflowed\n";
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"stack underflowed\n";
        }
    }

    int peak(){
        if(top>=0 && top<size){
            return arr[top];
        }
        else {
            cout<<"Stack is empty!\n";
            return -1;
        }
    }
};

int main(){
    // stack<int> s;//stl method

    // s.push(3);
    // cout<<s.top();

    Doublestack s(5);
    s.push(45);
    s.push(45);
    s.push(45);
    s.push(451);
    s.push(46);
   
    cout<<s.peak();
    cout<<endl;
    s.pop();
cout<<s.peak();
 




}