#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    // 借助一个辅助数组，大小为m+n；
    // 两个指针（其实就是下标。。）指向数组；从头到尾来比较然后一个个放入辅助数组；最后将辅助数组复制给num1.
    // 时间复杂度为 O（m+n）, 空间复杂度为m+n
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3;
        int i = 0, j = 0;
        while (i < m && j < n) 
        {
            if (nums1[i] <= nums2[j]) 
                nums3.push_back(nums1[i++]);
            else 
                nums3.push_back(nums2[j++]);
        }
        while (i < m)
        {
            nums3.push_back(nums1[i++]);
        }
        while (j < n)
        {
            nums3.push_back(nums2[j++]);
        }
        for(int x = 0; x < (m + n); x++)
            nums1[x] = nums3[x];
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    Solution().merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    return 0;
}