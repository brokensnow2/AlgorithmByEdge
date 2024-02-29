#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;

    // 入队操作
    q.push(1);
    q.push(2);
    q.push(3);

    // 出队操作
    while (!q.empty()) {
        int front = q.front(); // 查看队首元素
        std::cout << front << std::endl;
        q.pop(); // 移除队首元素
    }

    return 0;
}
