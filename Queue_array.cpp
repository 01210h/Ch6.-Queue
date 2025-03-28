
#include<iostream>
using namespace std;

class Q{
private:
    int* n;
    int S;
    int N;
    int f;//먼저 들어온 원소 가리킴
    int r;//마지막으로 들어온 원소 인덱스+1;
public:
    Q(int s);
    void enqueue(int data);
    void dequeue();
    int front();
    int size();
    bool empty();
};

int main(){
    int num;
    cin>>num;
    Q arr(num);

    return 0;
}

Q::Q(int s):n(nullptr),N(0),f(0),r(0),S(s){
    n = new int[s];
}

void Q::enqueue(int data){
    if(size()==S){
        return;
    }
    n[r]=data;
    r=(r+1)%S;
    N++;
}
void Q::dequeue(){
    if(empty()){
        return;
    }
    f=(f+1)%S;
    N--;
}
int Q::front(){
    if(empty()){
        return -1;
    }
    return n[f];
}
int Q::size(){
    return N;
}
bool Q::empty(){
    return (N==0);
}
