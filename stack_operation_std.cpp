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



void sort(stack<int>& s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();
    sort(s);
    if(s.empty()){
        s.push(temp);
    }
    else{
        if(temp<s.top()){
        insert_at_start(s,temp);
    }
    else{
        s.push(temp);
    }
    }
    
    
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
    n.push(11);
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


    // dislpay(n);
    // reverse(n);                                      //reversing a stack
    // dislpay(n);



    dislpay(n);
    sort(n);
    dislpay(n);



}