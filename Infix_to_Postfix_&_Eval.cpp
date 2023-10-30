#include <iostream>
#include <string>
#include <math.h>
using namespace std;

struct Node
{
        string data;
        Node *next;

        Node(string d=""): data(d), next(nullptr) {}
};

class Queue{
    private:
        Node *front;
        Node *rear;
        int size;

    public:
        Queue(): front(nullptr), rear(nullptr), size(0) {}

        void Enqueue(string d){
            Node *tempNode = new Node(d);
            if(front==nullptr && rear==nullptr){
                front=tempNode;
                rear=front;
            }
            else{
                rear->next=tempNode;
                rear=tempNode;
            }
            ++size;
        }

        Node* Dequeue(){
            Node *tempNode=front;
            front=front->next;
            --size;
            return tempNode;
        }

        bool isEmpty(){
            if(front==nullptr && rear==nullptr)
                return true;
            return false;
        }

        int Q_size(){
            return size;
        }

        void Print(){
            Node *tempNode=front;
            while(tempNode!=nullptr){
                cout<<tempNode->data<<" ";
                tempNode=tempNode->next;
            }
            cout<<endl;
        }
};

class Operator_Stack{
    private:
        Node *top;
    
    public:
        Operator_Stack():top(nullptr){}

        void push(string d){
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

        void infix_to_postfix(){

            Queue Postfix_Expression;
            while(1){
                string ch="";
                cin>>ch;
                if(ch=="q")
                    break;
                else if(ch=="(")
                    continue;
                else if(ch==")"){
                    if(!isEmpty()){
                        Postfix_Expression.Enqueue(pop()->data);
                    }
                }
                else if(ch=="+" || ch=="-" || ch=="*" || ch=="/" || ch=="^"){
                    push(ch);
                }
                else{
                    Postfix_Expression.Enqueue(ch);
                }
            }
            Postfix_Expression.Print();
            Post_Expression(Postfix_Expression);
        }

        void Post_Expression(Queue &Postfix){
            cout<<"Eval"<<endl;
            // Operator_Stack obj;
            // Postfix.Print();
            // cout<<Postfix.Dequeue()->data<<" ";
            // cout<<Postfix.Dequeue()->data<<" ";
            // cout<<Postfix.Dequeue()->data<<" ";
            // cout<<Postfix.Dequeue()->data<<" ";
            // cout<<Postfix.Dequeue()->data<<" ";
            // cout<<Postfix.Dequeue()->data<<" ";
            // cout<<Postfix.Dequeue()->data<<" ";
            // cout<<Postfix.Dequeue()->data<<" "
            while(Postfix.Q_size()){
            
                string ch="";
                ch=Postfix.Dequeue()->data;

                if(ch=="+" || ch=="-" || ch=="*" || ch=="/" || ch=="^"){
                    int r_operand=stoi(pop()->data);
                    int l_operand=stoi(pop()->data);
                    if(ch=="+"){
                        push(to_string(l_operand+r_operand));
                    }
                    else if(ch=="-"){
                        push(to_string(l_operand-r_operand));
                    }
                    else if(ch=="*"){
                        push(to_string(l_operand*r_operand));
                    }
                    else if(ch=="/"){
                        push(to_string(l_operand/r_operand));
                    }
                    else if(ch=="^"){
                        to_string(pow(l_operand,r_operand));
                    }
                }
                else
                    push(ch);
            }
            cout<<" Answer = ";
            cout<<pop()->data<<endl;
        }

        void clear(){
            while(top!=nullptr){
                Node* tempNode=top;
                top=top->next;
                delete tempNode;
            }
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

};

int main(){

    Operator_Stack op;
    op.infix_to_postfix();
    return 0;
}