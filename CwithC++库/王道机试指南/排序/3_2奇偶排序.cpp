extern "C" {
#include <stdio.h> // 引入标准输入输出库
#include <string.h> // 引入字符串处理库
}

#include <sstream> // 引入字符串流库
#include <algorithm> // 引入C++的算法库
#include <iostream>
#include <vector>

using namespace std; // 使用标准命名空间


int main()
{
	//
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> array;
    string word;
        while (getline(iss, word, ' ')) { // 根据空格分割
        array.push_back(stoi(word));
    }

    sort(array.begin(),array.end());
    cout << array[array.size()-1] << endl;
    for (int i = 0; i < array.size()-1; i++)
    {
        cout << array[i] << " ";
    }

}