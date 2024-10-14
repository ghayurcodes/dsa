#include<iostream>
#include<stack>

using namespace std;


void delet__middle( stack<int>& s,int count,int size){
 if(count==size/2){
    s.pop();
 }else{
    int temp=s.top();
    s.pop();
    delet__middle(s,count++,s.size());
    s.push(temp);

 }

}



void dislpay(stack<int> s){
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main(){


    // string word="hello";

    // stack<char> s;

    // for(int i=0;i<word.length();i++){
    //     char j=word[i];
    //     s.push(j);                          //tyo reverse a string using stack
    // }
    // string ans="";
    // while(!s.empty()){
    //     ans+=s.top();
    //     s.pop();
    // }
    // cout<<"reversd string is: "<<ans<<endl;




    stack<int> n;

    n.push(4);
    n.push(6);
    n.push(9);
    n.push(11);
    n.push(15);
    n.push(19);

    dislpay(n);

    int count=0;
    delet__middle(n,count,n.size());
    cout<<"after deleting middel:\n";
    dislpay(n);

    





}