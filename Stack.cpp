#include <iostream>
using namespace std;

class Stack{

    private:
        struct Node
        {
            int data;
            Node *next;
            Node(int d=0, Node* n=nullptr){
                data=d;
                next=n;
            }
        };
        Node *top;
        int stackSize;

    public:
        Stack(){
            top=nullptr;
            stackSize=-1;
        }

        void push(int d){
            Node *newNode=new Node(d);
            if(top==nullptr)
                top=newNode;
            else{
                newNode->next=top;
                top=newNode;
            }
            ++stackSize;
        }

        void pop(){
            Node *tempNode=top;
            top=top->next;
            delete tempNode;
            --stackSize;
        }

        void stack_Top(){
            cout<<"Top Node Data: "<<top->data<<endl;
        }
        void below_Top(){
            if(top->next!=nullptr)
                cout<<"Below Top: "<<top->next->data<<endl;
        }
        void stack_size(){
            cout<<"Current # elements in Stack: "<<stackSize+1<<endl;
        }
        

};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.stack_Top();
    st.below_Top();
    st.stack_size();
    st.pop();
    st.stack_size();
    st.stack_Top();


    return 0;
}