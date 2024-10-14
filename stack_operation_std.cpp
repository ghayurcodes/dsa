#include<iostream>
#include<stack>

using namespace std;




int main(){


    string word="hello";

    stack<char> s;

    for(int i=0;i<word.length();i++){
        char j=word[i];
        s.push(j);                          //tyo reverse a string using stack
    }
    string ans="";
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }


    cout<<"reversd string is: "<<ans<<endl;

}