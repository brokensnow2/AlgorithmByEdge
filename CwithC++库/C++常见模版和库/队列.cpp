#include <iostream>
#include <queue>

using namespace std;

int main() {
    std::queue<int> q;

    // 入队操作
    q.push(1);
    q.push(2);
    q.push(3);

    // 出队操作
    while (!q.empty()) {
        int front = q.front(); // 查看队首元素
        int back = q.back(); // 查看队尾元素
        std::cout << front << std::endl;
        q.pop(); // 移除队首元素,没有返回值
        cout << "队列的大小是 " << q.size() << endl;

    }

    return 0;
}
