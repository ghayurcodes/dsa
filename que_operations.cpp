#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;

void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}


void reverseQueue(queue<int>& q) {
    stack<int> s;
    
    // Transfer all elements from the queue to the stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    
    // Transfer elements back from the stack to the queue (reverses order)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

void reverse_recursion(queue<int>& q){
    if(q.empty()){
        return;
    }
    int temp=q.front();
    q.pop();
    reverse_recursion(q);
    q.push(temp);

}

void reverseK(queue<int>& q,int k){
    stack<int> s;

    

        for(int j=0;j<k;j++){
            s.push(q.front());
            q.pop();
        }

        while (!s.empty())
        {
            q.push(s.top());
            s.pop();
        }

        for(int h=0;h<q.size()-k;h++){
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
        
}



void non_repeating(string s){
    map<char,int> count;
    queue<int> q;
    string ans="";

    for(int i=0;i<s.length();i++){
        char ch=s[i];
        count[ch]++;
        q.push(ch);
    }
}

int main(){
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(8);
    q.push(1);
    q.push(5);
    q.push(9);

    // cout << "Original queue: ";
    // display(q);
    
    // // Reversing the queue
    // reverse_recursion(q);                    //reversing
    
    // cout << "Reversed queue: ";
    // display(q);



    // cout << "Original queue: ";
    // display(q);
    // reverseK(q,3);                    //reversing K elements    
    // cout << "Reversed queue: ";
    // display(q);


     string g="aabc";
     non_repeating(g);

    
    

    
    return 0;
}