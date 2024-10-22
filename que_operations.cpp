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
            start = i + 1;                          //extremly smart and simp,approch than chat gpy
           deficit +=balance ;
           balance=0;
        }
    }


    if (deficit+balance>=0) {
        return start;  //solution exists
    } else {
        return -1;  // No solution exists
    }
}



int petrolPumpTour_gpt(int petrol[], int distance[], int n) {
    int start = 0;  // Starting petrol pump
    int total_petrol = 0;  // Total surplus petrol
    int current_petrol = 0;  //No major use in the code just to check the circularity. if +ve value then its possible

    // Traverse through all petrol pumps
    for (int i = 0; i < n; i++) {
        total_petrol += (petrol[i] - distance[i]);
        current_petrol += (petrol[i] - distance[i]);

        // If current petrol becomes negative, restart from next petrol pump
        if (current_petrol < 0) {
            start = i + 1;  // Set the new starting point
            current_petrol = 0;  // Reset current petrol                             //gpt approch of upper problem(hard)
        }
    }

    // Check if total petrol is enough to cover the whole distance
    if (total_petrol >= 0) {
        return start;  // Starting point of the tour
    } else {
        return -1;  // No solution exists
    }
}



void interleve(queue<int>& q){

    queue<int> p;
    int halfSize = q.size() / 2;
    
    for(int i=0;i<halfSize;i++){
        p.push(q.front());
        q.pop();
    }
    while(!p.empty()){
        q.push(p.front());
        p.pop();
        q.push(q.front());
        q.pop();
    }






    // stack<int> s1,s2;
    // for(int i=0;i<q.size()/2;i++){
    //     s1.push(q.front());
    //     q.pop();
    // }

    // while(!s1.empty()){
    //     s2.push(s1.top());
    //     s1.pop();
    // }

    // while(!s2.empty()){
    //     q.push(s2.top());
    //     s2.pop();
    //     q.push(q.front());
    //     q.pop();
    // }
}


int main(){
    // queue<int> q;
    // q.push(2);
    // q.push(3);
    // q.push(8);
    // q.push(1);
    // q.push(5);
    // q.push(9);

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

    
    // int petrol[] = {4,6, 7, 4};
    // int distance[] = {6, 5, 3,5};
    // int n = sizeof(petrol) / sizeof(petrol[0]);

    // int start = petrolPumpTour(petrol, distance, n);
  
    // if (start != -1) {                                                                   //famous petrol problenm
    //     cout << "Start from petrol pump index: " << start << endl;
    // } else {
    //     cout << "No solution exists" << endl;
        
    // }



    queue<int> q;
    for(int i=10;i<20;i++){
        q.push(i);
    };
    display(q);
    interleve(q);
    display(q);

    
 
}