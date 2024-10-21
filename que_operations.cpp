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



void non_repeating(string s) {
    map<char, int> count;
    queue<char> q;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        
        count[ch]++;
        
       
        q.push(ch);

                                                                     //veryeasy logic but very weird  stack cannot be sused bcuz we dont ahve fronta cess
        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }

        
        if (q.empty()) {
            ans += '#';  
        } else {
            ans += q.front();  
        }
    }

    
    cout << ans << endl;
}




int petrolPumpTour(int petrol[], int distance[], int n) {
    int start = 0;  // Starting petrol pump
    int balance=0;
    int deficit=0;
    

   
    for (int i = 0; i < n; i++) {
        balance+= (petrol[i] - distance[i]);
    
        if (balance < 0) {
            start = i + 1;                          //very smart and simp,approch than chat gpy
           balance=0;
           deficit +=balance ;
        }
    }


    if (deficit+balance>=0) {
        return start;  // Starting point of the tour
    } else {
        return -1;  // No solution exists
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


    //  string g="aabc";
    //  non_repeating(g);                           //first non-repeating char in string

    
    int petrol[] = {6, 3, 7};
    int distance[] = {4, 6, 3};
    int n = sizeof(petrol) / sizeof(petrol[0]);

    int start = petrolPumpTour(petrol, distance, n);
  
    if (start != -1) {
        cout << "Start from petrol pump index: " << start << endl;
    } else {
        cout << "No solution exists" << endl;
        
    }


    
    return 0;
}