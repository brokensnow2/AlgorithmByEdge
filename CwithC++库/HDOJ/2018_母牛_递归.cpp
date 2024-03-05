#include <iostream>
#include <stdio.h>

using namespace std;
/**
 * 思想：
 * 到了第n年；老母牛一共生了n-1头（第一年，只有老母牛1头，注意理清题意）
 * 而那n-1头，因为小牛三年后就可以每年生一头，所以那n-1头有n-4头分别可以在
 * 第5年，第六年...,第n-1年开始生小牛
 * 他们可以生n-4,n-5,...,1头
 * 对于小牛生的小牛，就可以这样递归。
 * 终止条件是近三年出生的牛他们不会生
 * 最后加上老母牛的1
 * PS：母牛自己的个数在上一层递归就记录了
 * 
 * 
 * 不是很好理解去看DP解法
 * 
*/

/**
 * @param sum: 总数,不带老母牛
 * @param age: 它生了多少
 * 
*/
void cow(int &sum,int age)
{
    // 它生了多少
    sum += age;
    // 终止条件
    if (age <= 3)
    //生了小于等于3个的，是近三年生的，他们不能生
    	return;
    else
    {	// 计算它的孩子能生多少
        for (int i = 0; i < age - 3; i++)
        {
            cow(sum, age - 3 - i);
        }
    }
}

int main()
{
    int n;
    int num = 0;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }
        // n-1是指老母牛生了n-1头
        cow(num,n-1);
        cout << num+1 << endl;
        num = 0;
    }
    
    return 0;
}