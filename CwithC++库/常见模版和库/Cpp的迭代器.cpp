#include <vector>
#include <iostream>
int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for(auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
/**
Q:迭代器是一个可移动的指针？

A: 是的，你可以将迭代器视为一个特殊类型的指针。
迭代器是一种访问容器（如数组或链表）元素的对象，
它可以在容器的元素之间移动（即迭代）。
迭代器提供了一种方法，使得你无需知道容器的内部结构就能访问其内部的元素。

迭代器的行为类似于指针：通过解引用迭代器(*号)，可以获取它当前指向的元素；
通过递增和递减迭代器，可以使其指向容器中的下一个或上一个元素。

然而，迭代器比指针更为强大和灵活。
例如，对于一个`std::vector`（动态数组），
你可以使用随机访问迭代器在常数时间内访问任何元素；
对于一个`std::list`（链表），你可以使用双向迭代器来向前或向后遍历元素。
这些操作对于原始指针来说是不可能的（或者说非常困难的）。

总的来说，迭代器是一种使得你可以在不了解容器内部实现的情况下，
以统一且安全的方式访问和修改容器元素的工具。希望这个解答对你有所帮助！

*/
