#include<iostream>
#include<stack>

using namespace std;


void delet__middle( stack<int>& s,int count,int size){
 if(count==size/2){
    s.pop();
 }else{
    int temp=s.top();
    s.pop();
    delet__middle(s,count+1,s.size());
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




bool check(string exp){
    stack<char> temp;
    for(int i=0;i<exp.length();i++){
        char ch=exp[i];

        if(ch=='(' ||ch=='{' ||ch=='['){
            temp.push(ch);
        }
        else{
            if(!temp.empty()){
                char top=temp.top();
                if(ch==')' && top=='(' ||
                ch=='}' && top=='{'||
                ch==']' && top=='['
                ){
                    temp.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }

    if(temp.empty()){
        return true;
    }
    else{
        return false;
    }
        

}








void insert_at_start(stack<int>& s,int element){
    if(s.empty()){
    
        s.push(element);
    
    }
    else{
        int temp=s.top();
        s.pop();
        insert_at_start(s,element);
        s.push(temp);
    }

}



void reverse(stack<int>& s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    reverse(s);
    insert_at_start(s,temp);
}



void sort_insert(stack<int>& s, int element) {
    if (s.empty() || s.top() <= element) {
        s.push(element);
        return;
    }
    
    int temp = s.top();
    s.pop();
    sort_insert(s, element);
    
    s.push(temp); // Put the top element back after recursion
}

// Recursive function to sort the stack
void sort(stack<int>& s) {
    if (s.empty()) {
        return;
    }

    int temp = s.top();
    s.pop();

    // Sort the remaining stack recursively
    sort(s);

    // Insert the current element in the sorted order
    sort_insert(s, temp);
}




int evaluatePostfix(const string& expression) {
    stack<int> stack;

    for (int i=0;i<expression.length();i++) {
        
        if (isdigit(expression[i])) {
            stack.push(expression[i] - '0'); //chk ltr but easy
        }
       
        else {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            switch (expression[i]) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(a / b);
                    break;
            }
        }
    }
    return stack.top();
}





bool check_brackets(string exp){
    stack<char> s;
    bool isok=false;
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='(' || exp[i]=='+' ||exp[i]=='-' ||exp[i]=='/' ||exp[i]=='*'){
            s.push(exp[i]);
        }
        else if(exp[i]==')' ){
            isok=false;
            while(s.top()!='('){
                char top=s.top();
                if(top=='+' ||top=='-' ||top=='/' ||top=='*'){
                    isok=true;
                }
                s.pop();
            }
            if(isok){
                s.pop();
            }
            
           
        }
    }

     if(!isok){
        s.pop();
                 }
    return isok;

}



int findMinimumCost(string str) {
  	
    //odd condition
    if(str.length()%2 == 1) {
        return -1;
    }
    
    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        
        if(ch == '{') 
            s.push(ch);
		else
        {
            //ch is closed brace
            if(!s.empty() && s.top() == '{') {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    
        //stack contains invalid expression
        int a = 0, b = 0;
        while(!s.empty()) {
            if(s.top() == '{') {
                b++;
            }
            else
            {
                a++;
            }
            s.pop();
        }
        
            int ans = (a+1)/2 + (b+1)/2;    //jut remeber this expression no logic
            return ans;
    
    
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
    n.push(2);
    n.push(-11);
    n.push(15);
    n.push(1);                  //removing middle of stack

    // dislpay(n);

    // int count=0;
    // delet__middle(n,count,n.size());
    // cout<<"after deleting middel:\n";
    // dislpay(n);

    

    // string exp="{()}";
    // bool is_correct=check(exp);

    // if(is_correct){
    //     cout<<"expression is valid\n";                   //cheking expression valid or not
    // }
    // else{
    //     cout<<"not a valid expression\n";
    // }


    // dislpay(n);
    // int count=n.size()-1;
    // insert_at_start(n,99);                           //INSERT AT BOTTOM
    
    // cout<<"after: "<<endl;
    // dislpay(n);


    dislpay(n);
    reverse(n);                                      //reversing a stack
    dislpay(n);



    // dislpay(n);
    // sort(n);                                         //sorting a stack(a bit complx highly recursive)
    // dislpay(n);



    // string postfixExpression = "534*+9-";  
    // int result = evaluatePostfix(postfixExpression);                          //post fix expression  (also called Reverse Polish Notation)
    // cout << "The result of the postfix expression is:"<<result<< endl;




    // string exp="(2+2)";
    // bool result=check_brackets(exp);

    // if(result){
    //     cout<<"the expression is valid\n";                           //check redundent parenthesis
    // }else{
    //     cout<<"invalid expression\n";
    // }

    // string exp="{{}}}}";
    // int result=findMinimumCost(exp);
    // cout<<"cost to fix this expression is: "<<result<<endl;

    


}