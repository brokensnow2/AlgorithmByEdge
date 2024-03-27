/**
 * 最简真分数，是分子和分母的最大公约数为1，且分子小于分母
 * 
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
	int n;
    cin >> n;
	// 存储n个数
    vector<int> array(n);
    for (int i = 0; i < n; i++){
        cin >> array[i];
    }
    // 排序
    sort(array.begin(), array.end());
	// 存储结果
    int count = 0;
    
    for (int i = 0; i < array.size() - 1; i++){
		for (int j = i+1; j < array.size(); j++){
            if (gcd(array[j], array[i]) == 1){
                ++count;
            }
        }
    }
    cout << count <<endl;
}