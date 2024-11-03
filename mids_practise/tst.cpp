#include<iostream>
#include<stack>

using namespace std;

void sort_insert(stack<int>& s,int element){
    if(s.empty()||s.top()<=element){
        s.push(element);
    }
    int temp=s.top();
    s.pop();
    sort_insert(s, element);
    s.push(temp);
}


void sort(stack<int>& s) {

if(s.empty()){
    return;
}
int tenmp=s.top();
s.pop();
sort(s);
// sort_insert();


}




int main(){

}