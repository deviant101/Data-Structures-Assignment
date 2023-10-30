#include <iostream>
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

    public:
        Queue(): front(nullptr), rear(nullptr) {}

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
        }

        Node* Dequeue(){
            Node *tempNode=front;
            front=front->next;
            return tempNode;
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