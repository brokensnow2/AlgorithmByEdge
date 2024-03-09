/**
 * 
 * 
 * 
*/
#include <iostream>

using namespace std;

bool is_triangle(int a, int b, int c) {
    // 判断是否满足三角形条件:两边之和大于第三边
    return a + b > c && a + c > b && b + c > a;
}

int main() {
    int M;
    cin >> M;
    while (M--) {
        int A, B, C;
        cin >> A >> B >> C;
        if (is_triangle(A, B, C)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

/*
或者：
首先，我们将三条边按照从小到大的顺序排序。
然后，我们用最大的两个边相减，判断是否小于最小的一条边。
接着，我们用最小的两个边相加，判断是否大于第三条边。

#include <iostream>
#include <algorithm>

using namespace std;

bool is_triangle(int a, int b, int c) {
    // 按从小到大排序
    int sides[3] = {a, b, c};
    sort(sides, sides + 3);
    int smallest = sides[0];
    int middle = sides[1];
    int largest = sides[2];
    
    // 判断是否满足三角形条件
    return smallest + middle > largest;
}

int main() {
    int M;
    cin >> M;
    while (M--) {
        int A, B, C;
        cin >> A >> B >> C;
        if (is_triangle(A, B, C)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}




*/