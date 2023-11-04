#include <iostream>
#include <math.h>
#include <string>
// #include "conio.h"
using namespace std;

class Expression_Stack{
    private:
        struct Node{
            int data;
            Node* next;
            
            Node(int d=0){
                data=d;
                next=nullptr;
            }
        };
        Node *top;
        string expression;
    
    public:
        Expression_Stack():top(nullptr), expression(""){}

        void push(int d){
            Node *tempNode=new Node(d);
            tempNode->next=top;
            top=tempNode;
        }

        Node* stack_top(){
            return top;
        }

        Node* pop(){

            Node *TempNode=top;
            top=top->next;
            return TempNode;
        }

        bool isEmpty(){
            if(top==nullptr)
                return true;
            return false;
        }

        void Print(){
            Node *tempNode=top;
            while(tempNode!=nullptr){
                cout<<tempNode->data<<" ";
                tempNode=tempNode->next;
            }
            cout<<endl;
        }

        int Post_Expression(){
            cout<<"Enter Postfix Expression: ";
            while(1){
                string ch="";
                cin>>ch;
                if(ch=="q")     //exiting on q
                    break;
                else if(ch=="+" || ch=="-" || ch=="*" || ch=="/" || ch=="^"){
                    int r_operand=pop()->data;
                    int l_operand=pop()->data;
                    if(ch=="+")
                        push(l_operand+r_operand);
                    else if(ch=="-")
                        push(l_operand-r_operand);
                    else if(ch=="*")
                        push(l_operand*r_operand);
                    else if(ch=="/")
                        push(l_operand/r_operand);
                    else if(ch=="^")
                        push(pow(l_operand,r_operand));
                }
                else
                    push(stoi(ch));
            }
            cout<<"Result = ";
            return pop()->data;
        }
};

int main(){

    Expression_Stack stack;
    cout<<stack.Post_Expression()<<endl;

    return 0;
}