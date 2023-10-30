#include <iostream>
#include <math.h>
#include "conio.h"
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
            if(top==nullptr)
                top=tempNode;
            else{
                tempNode->next=top;
                top=tempNode;
            }
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

            while(1){
                char ch=getch();
                if(ch=='\n')
                    break;
                cout<<ch<<" ";
                if(ch>='0' && ch<='9')
                    push(ch-48);
                else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
                    int r_operand=pop()->data;
                    int l_operand=pop()->data;
                    switch (ch)
                    {
                        case '+':
                            push(l_operand+r_operand);
                        break;
                        case '-':
                            push(l_operand-r_operand);
                        break;
                        case '*':
                            push(l_operand*r_operand);
                        break;
                        case '/':
                            push(l_operand/r_operand);
                        break;
                        case '^':
                            push(pow(l_operand,r_operand));
                        break;
                    }
                }
            }
            cout<<" Answer = ";
            return pop()->data;
        }


};

int main(){

    Expression_Stack stack;
    cout<<stack.Post_Expression()<<endl;

    return 0;
}