#include<iostream>

using namespace std;//stacks LIFO (last in forst out)

class stack{
    int top;
    int* arr;
    int size;

    stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }


    void push(int element){

    }

    void pop(){

    }

    int top(){
        
    }
};

int main(){
    // stack<int> s;//stl method

    // s.push(3);
    // cout<<s.top();

    stack s(10);



}