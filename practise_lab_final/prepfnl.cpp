#include<iostream>

using namespace std;

class heap{
    int*a;
    int curr,size;


    public:

    heap(int s){
        a=new int[s];
        size=s;
        curr=0;

    }




    void add(int val){
        if(curr==size-1){
            cout<<"space fulled\n";
            return;
        }

        a[curr]=val;
        int tmp=curr;
        curr=curr+1;

        while (tmp!=0)
        {
        int p=(2-1)/2;
        int maz=0;
        if(a[tmp]>a[p]){
            //logic here swap and tmp=p;
        }
        }
        
    }

}