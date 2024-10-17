#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void find_next_smaller_element( vector<int>& arr){
    stack<int> s;
    s.push(-1);
    for(int i=0;i<arr.size();i++){
        if(arr[i]<s.top()){
            
        }
    }

}


int main(){

    vector<int> arr;
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);                   //next samller element
    arr.push_back(3);

    find_next_smaller_element(arr);


}