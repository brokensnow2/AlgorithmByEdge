#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
int main() {
    int n, x;
    while (cin >> n >> x && (n || x)) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        nums.push_back(x);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
*/


/**
 * 因为数列原本有序
 * 我们可以在遍历数列的过程中，当遇到第一个比插入元素大的数时，先输出插入元素，然后再输出这个数。
 * 这样就可以在不实际插入元素的情况下，输出一个看起来是有序的数列。
 * 
*/

int main() {
    int n, x;
    while (cin >> n >> x && (n || x)) {
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        bool inserted = false;
        for (int i = 0; i < n; ++i) {
            if (!inserted && nums[i] > x) {
                cout << x << " ";
                inserted = true;
            }
            cout << nums[i] << " ";
        }
        if (!inserted) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
