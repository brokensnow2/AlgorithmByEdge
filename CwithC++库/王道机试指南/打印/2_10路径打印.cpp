#include <iostream>  // 引入输入/输出流库
#include <map>  // 引入map容器库
#include <vector>  // 引入vector容器库
#include <sstream>  // 引入字符串流库

struct Node {  // 定义一个结构体表示目录节点
    std::string name;  // 节点的名字
    std::map<std::string, Node*> children;  // 存储子节点的map
};

void printTree(Node* node, int indent = 0) {  // 打印目录树的函数
    if (node == nullptr) return;  // 如果节点为空，直接返回
    std::cout << std::string(indent, ' ') << node->name << std::endl;  // 打印节点名字，缩进量由indent决定
    for (auto& pair : node->children) {  // 遍历子节点
        printTree(pair.second, indent + 1);  // 递归打印子节点，缩进量加1
    }
}

int main() {  // 主函数
    std::vector<std::string> paths = {"a\\b\\c", "a\\d\\e", "b\\cst", "d\\"};  // 存储路径的vector
    Node* root = new Node{"root"};  // 创建根节点

    for (auto& path : paths) {  // 遍历所有路径
        std::stringstream ss(path);  // 创建一个字符串流
        std::string segment;  // 存储路径的每一部分
        Node* currentNode = root;  // 当前处理的节点，初始为根节点

        while (std::getline(ss, segment, '\\')) {  // 使用'\\'作为分隔符，将路径分割成多个部分
            if (currentNode->children.count(segment) == 0) {  // 如果当前节点的子节点中没有这个部分，就创建一个新的节点
                currentNode->children[segment] = new Node{segment};
            }
            currentNode = currentNode->children[segment];  // 将当前节点移动到新创建的节点
        }
    }

    printTree(root);  // 打印目录树
    return 0;  // 程序正常退出
}

