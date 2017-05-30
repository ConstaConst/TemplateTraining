#include "ListQueue.h"

int main() {

    ListQueue<int, 3> que;

    que.push(1);
    que.print();
    que.push(3);
    que.print();
    que.push(4);
    que.print();
    que.push(7);
    que.print();
    que.push(6);
    que.print();
    que.push(9);
    que.print();
    que.push(2);
    que.print();
    que.push(3);
    que.print();
    std::cout << "----------" << std::endl;
    que.pop();
    que.print();
    que.pop();
    que.print();
    que.pop();
    que.print();
    que.pop();
    que.print();
    que.pop();
    que.print();
    que.pop();
    que.print();
    que.pop();
    que.print();

    return 0;
}
