#include<iostream>
#include<stack>
#include<ctime>

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
stack<int> s;
s.push(3);
s.push(4);
cout<<s.size();
time_t d = time(0); // Get current time
    std::cout << "Epoch time: " << d << "\n";
    std::cout << "Readable time: " << ctime(&d); // Convert and display as readable format
    return 0;

}