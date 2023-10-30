#include <iostream>
#include <math.h>
using namespace std;

class Stack{

    private:
        struct Node{
        int data;
        Node *next;
        Node(int d=0, Node* n=nullptr){
            data=d;
            next=n;
        }
        };
        Node *top;

    public:
        Stack(){
            top=nullptr;
        }

        void push(int d){
            Node *newNode=new Node(d);
            if(top==nullptr)
                top=newNode;
            else{
                newNode->next=top;
                top=newNode;
            }
        }

        Node* pop(){
            Node *tempNode=top;
            top=top->next;
            return tempNode;
        }

        int BinaryToDecimal(long long int num){

        Stack binaryStack;
        for(int i=0; num; ++i){
            int digit=num%10;
            num/=10;
            binaryStack.push(digit*pow(2,i));
        }

        int Dec=0;
        while(!binaryStack.isEmpty()){
            Node *tempNode=binaryStack.pop();
            Dec+=tempNode->data;
            delete tempNode;
        }
        return Dec;
        }

        long long int DecimalToBinary(int num){

            Stack DecimalStack;
            while(num){
                int digit=num%2;
                num/=2;
                DecimalStack.push(digit);
            }

            long long int Bin=0;
            while(!DecimalStack.isEmpty()){
                Node* tempNode=DecimalStack.pop();
                Bin = Bin * 10 + tempNode->data;
                delete tempNode;
            }
            return Bin;
        }

        bool isEmpty(){
            if(top==nullptr)
                return true;
            else
                return false;
        }

        void stack_Top(){
            cout<<"Top Node Data: "<<top->data<<endl;
        }
        void below_Top(){
            if(top->next!=nullptr)
                cout<<"Below Top: "<<top->next->data<<endl;
        }

        void Print_Stack(){
            Node *temp=top;
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }

};

int main(){

    Stack bin;
    cout<<"From Decimal to Binary"<<endl;
    cout<<"11000101 : "<<bin.BinaryToDecimal(11000101)<<endl;
    cout<<"10101010 : "<<bin.BinaryToDecimal(10101010)<<endl;
    cout<<"11111111 : "<<bin.BinaryToDecimal(11111111)<<endl;
    cout<<"10000000 : "<<bin.BinaryToDecimal(10000000)<<endl;
    cout<<"1111100000 : "<<bin.BinaryToDecimal(1111100000)<<endl;

    Stack Dec;
    cout<<"\nFrom Decimal to Binary"<<endl;
    cout<<"4 : "<<Dec.DecimalToBinary(4)<<endl;
    cout<<"5 : "<<Dec.DecimalToBinary(5)<<endl;
    cout<<"6 : "<<Dec.DecimalToBinary(6)<<endl;
    cout<<"7 : "<<Dec.DecimalToBinary(7)<<endl;
    cout<<"8 : "<<Dec.DecimalToBinary(8)<<endl;
    cout<<"9 : "<<Dec.DecimalToBinary(9)<<endl;

    return 0;
}