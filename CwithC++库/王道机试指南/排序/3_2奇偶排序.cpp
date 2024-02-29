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
	//读取一行
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<int> OddArray;
    vector<int> EvenArray;
    string word;

    //分别操作数字
    while (getline(iss, word, ' ')) { // 根据空格分割
    	if (stoi(word) % 2 == 0)
    	{
			EvenArray.push_back(stoi(word));
    	}
    	else
    	{
        	OddArray.push_back(stoi(word));
    	}
    }
	
    //排序
    sort(EvenArray.begin(),EvenArray.end());
    sort(OddArray.begin(),OddArray.end());

	//输出
    for (int i = 0; i < EvenArray.size(); i++)
    {
        cout << EvenArray[i] << " ";
    }

    for (int i = 0; i < OddArray.size(); i++)
    {
        cout << OddArray[i] << " ";
    }

}