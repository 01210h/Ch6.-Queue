#include<iostream>
using namespace std;

class List;

class Node{
private:
    int data;
    Node* next;
public:
    Node(int N):data(N),next(nullptr);
    friend class List;
};

class List{
private:
    int size;
    Node* front;
    Node* rear;
public:
    List();
    void enqueue(int n);
    void dequeue();
    bool EMPTY();
    int SIZE();
    int FRONT();
};


int main(){


    return 0;
}
List::List():front(nullptr),rear(nullptr),size(0){}
void List::enqueue(int n){
    Node* new_node=new Node(n);
    new_node->next= nullptr;//큐는 항상 끝에 삽입되므로
    if(EMPTY()){
        front=rear=new_node;
    }else{
        rear->next=new_node;//연결
        rear=new_node;
    }
    size++;
}
void List::dequeue(){
    if(EMPTY()) {
        return;
    }
    Node* erase_node=front;
    if(SIZE()==0){
        front=rear= nullptr;
    }else {
        front = front->next;
    }
    delete erase_node;
    size--;
}
bool List::EMPTY(){return (size==0);}
int List::SIZE(){return size;}
int List::FRONT(){
    if(EMPTY()){
        return -1;
    }
    return front->data;
}
