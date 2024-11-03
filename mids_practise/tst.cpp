#include<iostream>
using namespace std;



class Node{
    public:
    string ename;
    int duration;
    string type;
    Node* nxt;


    public:
    Node(string name,string type,int duration){
        this->duration=duration;
        this->ename=name;
        this->type=type;
        this->nxt=NULL;
    }
};

class Exercise{
    public:
    Node* head;

    public:
    Exercise(){
        head=NULL;
    }


    void add(){
        string anme,type;
        int duration;
        cout<<"ente rname\n";
        cin>>anme;
        cout<<"enter duration\n";
        cin>>duration;
        cout<<"ente rtype\n";
        cin>>type;
        Node* newnode=new Node(anme,type,duration);

        if(head==NULL){
            head=newnode;
        }
        else{
            Node* temp=head;
            while(temp->nxt!=NULL){
                temp=temp->nxt;
            }
            temp->nxt=newnode;

        }
    }


    void remove(string name){
         

        if(head==NULL){
           cout<<"nothing to rmove empty list\n";
           return;
        }
        else{
            Node* temp=head;
            while(temp!=NULL){
                if(temp->nxt->ename==name){
                    break;
                }
                temp=temp->nxt;
            }
            Node* todel=temp->nxt;
            temp->nxt=todel->nxt;
            delete todel;
        }
    }


    void disp(){

        Node* temp=head;
        int i=0;

        while(temp!=NULL){
            cout<<i++<<" : "<<"\t"<<temp->ename<<"\t"<<temp->type<<"\t"<<temp->duration<<endl;
            temp=temp->nxt;
        }
        

    }


};




int main(){
    cout<<"+++++WELCOME++++\n";
    Exercise e;
    e.add();
    e.add();
    e.add();
    cout<<"displaying\n";
    e.disp();
    cout<<"ente rnam eto remove\n";
    string n;
    cin>>n;
    e.remove(n);
    e.disp();
   
}