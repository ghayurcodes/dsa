#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void find_next_smaller_element(vector<int>& arr){
    stack<int> s;
    s.push(-1);
    for(int i=arr.size()-1;i>=0;i--){
        int temp=arr[i];
        while(s.top()>=arr[i]){  //!(s.top()<=arr[i]) can also be written
            s.pop();                                        //simple but abit tricky
        }
        arr[i]=s.top();
        s.push(temp);
    }

}


void display(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){

    vector<int> arr;
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(2);                   //next samller element
    arr.push_back(3);


    display(arr);
    find_next_smaller_element(arr);
    display(arr);




}