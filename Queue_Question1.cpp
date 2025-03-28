#include<iostream>
using namespace std;
class Q;

class Node{
private:
    int data;
    Node* next;
public:
    Node(int n):next(nullptr),data(n){}
    friend class Q;
};//노드 기본 구성

class Q{
private:
    int size;
    Node* front;
    Node* rear;
public:
    Q();
    void isEmpty();
    void SIZE();
    void FRONT();
    void REAR();
    void ENQUEUE(int N);
    void DEQUEUE();

    void CLEAR();
    void FIND(int N);
    void DISPLAY();
};

int main(){


    return 0;
}
Q::Q():size(0),front(nullptr),rear(nullptr){}
void Q::isEmpty(){
    if(size==0){
        cout<<"True\n";
    }else{
        cout<<"False\n";
    }
}
void Q::SIZE(){cout<<size<<"\n";}
void Q::FRONT(){
    if(size==0) {
        return;
    }
    cout<<front->data<<"\n";
}
void Q::REAR(){
    if(size==0){
        return;
    }
    cout<<rear->data<<"\n";
}
void Q::ENQUEUE(int N){
    Node* new_node=new Node(N);
    if(size==0){
        front=rear=new_node;
    }else{
        new_node->next= nullptr;
        rear->next=new_node;
        rear=new_node;
    }
    size++;
}
void Q::DEQUEUE(){
    if(size==0){
        return;
    }
    Node* erase_node=front;
    front=front->next;
    delete erase_node;
    size--;
    if(size==0){
        rear= nullptr;
        return;
    }
}
void Q::CLEAR(){
    int N=size;
    for(int i=0;i<N;i++){
        if(size==0){
            break;
        }
        Node* erase_node=front;
        front=front->next;
        delete erase_node;
        size--;
        if(size==0){
            rear= nullptr;
            break;
        }
    }
}
void Q::FIND(int N){
    Node* find=front;
    for(int i=0;i<size;i++){
        if(find->data==N){
            cout<<"Found";
            return;
        }
        find=find->next;
    }
    cout<<"Not Found";
}
void Q::DISPLAY(){
    if(size==0){
        cout<<"Empty";
        return;
    }
    Node* cursor=front;
    for(int i=0;i<size;i++){
        cout<<cursor->data<<" ";
        cursor=cursor->next;
    }
}