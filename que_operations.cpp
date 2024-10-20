#include<iostream>
#include<queue>
using namespace std;



int main(){
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(8);
    q.push(1);
    q.push(5);

    cout<<"front :"<<q.front()<<" rear: "<<q.back();
    cout<<"size: "<<q.size();
    cout<<endl;
    q.pop();
    cout<<endl;
    cout<<"front :"<<q.front()<<" rear: "<<q.back();
}