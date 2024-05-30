/**
C++中的优先队列是一种特殊的队列，它可以简单地理解为一个堆数据结构。
在优先队列中，只能访问处于队首位置的元素，
同时优先队列能保证该元素是整个队列中最大（或最小）的元素¹。
优先队列在实际问题中有很多应用，最典型的就是用于优化Dijkstra最短路算法。
====================================
优先队列的定义方式如下¹：
```cpp
#include <queue> // 优先队列需要的头文件

priority_queue <type> name; // 定义一个最大优先队列

priority_queue <type, vector<type>, greater<type> > name;  // 定义一个最小优先队列

type：这是数据类型，可以是任何有效的C++数据类型，如int，float，string等。

vector<type>：这是底层容器，用于实现优先队列。
默认情况下，优先队列使用的是vector，但也可以使用deque。不能使用list，因为需要随机访问
因为堆是完全二叉树，可以用数组表示，所以可以使用vector容器。

greater<type>：这是一个比较函数对象，用于确定优先队列中元素的优先级。默认情况下，优先队列使用的是less<type>，也就是大根堆，队首元素最大。
当我们使用greater<type>时，就变成了小根堆，队首元素最小。
=========================================

// 例子
priority_queue <int> q;
priority_queue <string, vector<string>, greater<string> > qs;
```
在这里，`priority_queue <type> name;`定义的是一个最大优先队列，
也就是队首永远是优先级最高的元素的优先队列。
而`priority_queue <type, vector<type>, greater<type> > name;`
定义的是一个最小优先队列，也就是队首永远是优先级最小的元素的优先队列¹。

优先队列的主要操作函数包括¹：
```cpp
q.push(x); // 向优先队列q中插入一个元素x
q.pop(); // 删除优先队列队首元素
q.top(); // 访问优先队列的队首元素
q.empty(); // 查询优先队列是否为空
```
这些操作的时间复杂度分别为：`push`和`pop`的时间复杂度为O(log n)，
`top`和`empty`的时间复杂度为O(1)¹。
========================================
在优先队列使用自己定义的类型：
在C++的优先队列中使用自定义类型，需要提供一个比较函数或者重载运算符，
以便优先队列知道如何比较你的自定义类型。
这是因为优先队列需要知道如何确定元素的优先级。

重载运算符：
C++的priority_queue默认是一个大根堆，
也就是说，它的比较函数默认是std::less，
这个函数实际上是使用<运算符来比较元素的。
|－－－－－－－－－－－－－－－－－－－－－
|通过比较函数返回true的元素优先级越小
|less使用<
|所以3<5? true；所以3优先级小
|
|－－－－－－－－－－－－－－－－－－－－－

但是，可以通过提供自定义的比较函数来改变这个行为。
举个例子，假设我们有一个自定义类型Person，并且我们重载了<运算符，
使得年龄大的Person对象小于年龄小的Person对象。
然后我们创建了一个
priority_queue<Person>。
在这个优先队列中，年龄最大的Person对象会被视为优先级最高的元素，
因为它在<运算符的定义下是最小的。


提供一个使用>运算符的比较函数时，如std::greater，那么priority_queue就会变成一个小根堆。
这是因为std::greater会认为较大的元素“小于”较小的元素，所以在优先队列中，较小的元素会被视为优先级更高。
|－－－－－－－－－－－－－－－－－－－－－
|通过比较函数返回true的元素优先级越小
|greater使用>
|所以3>5? false；所以3优先级大
|
|－－－－－－－－－－－－－－－－－－－－－
举个例子，如果你有一个自定义类型，并且你重载了>运算符，
使得年龄大的对象“小于”年龄小的对象。
然后你创建了一个
priority_queue<Person, vector<Person>, greater<Person>>。
在这个优先队列中，
年龄最小的对象会被视为优先级最高的元素，因为它在>运算符的定义下是最小的。
++++++++++++++++++++++++
比较函数：
struct Person {
    string name;
    int age;

    Person(string _name, int _age) : name(_name), age(_age) {}
};

struct CompareAge {
    bool operator()(Person const& p1, Person const& p2) {
        // 注意：这里使用了大于运算符，所以这实际上是一个小根堆（即优先级最小的元素在队首）
        return p1.age > p2.age;
    }
};

int main() {
    priority_queue<Person, vector<Person>, CompareAge> pq;

    pq.push(Person("Alice", 22));
    pq.push(Person("Bob", 25));
    pq.push(Person("Charlie", 20));

    while (!pq.empty()) {
        Person top = pq.top();
        pq.pop();
        cout << top.name << " is " << top.age << " years old." << endl;
    }

    return 0;
}
在这个例子中，我们定义了一个CompareAge结构体，它有一个operator()函数，
这个函数告诉优先队列如何比较Person类型。
然后我们在定义优先队列时，使用CompareAge作为第三个模板参数。
这样，优先队列就会使用CompareAge来确定Person的优先级。
当你在一个类或结构体中重载函数调用运算符时，
你可以让这个类或结构体的对象像函数一样被调用。
在这个例子中，CompareAge结构体重载了函数调用运算符，
所以你可以创建一个CompareAge对象，
并像调用函数一样使用它来比较两个Person对象。

这段代码中的函数调用运算符接受两个Person类型的引用作为参数，然后比较这两个Person的age字段。如果p1的age大于p2的age，则返回true，否则返回false。这样，当你在优先队列中使用CompareAge作为比较函数对象时，优先队列就会根据Person的age字段来确定元素的优先级。

总的来说，这段代码重载的是函数调用运算符()，使得CompareAge对象可以像函数一样被调用，用于比较两个Person对象。
*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> maxHeap; // 默认是大根堆

    maxHeap.push(3);
    maxHeap.push(4);
    maxHeap.push(1);

    cout << "maxHeap Top element: " << maxHeap.top() << endl; // 输出 4

    maxHeap.pop();
    cout << "New top element: " << maxHeap.top() << endl; // 输出 3
		
	priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(1);
    minHeap.push(3);
    minHeap.push(2);
    cout << "minHeap Top element" << minHeap.top() << endl;
    return 0;
}



