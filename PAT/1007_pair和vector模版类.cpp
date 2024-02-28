#include <iostream> // 引入输入输出库
#include <vector> // 引入向量库

/**
 * @brief std::vector和std::pair都是C++标准库中的模板类。


    std::vector是一个动态数组，可以在运行时添加和删除元素。它的大小可以自动调整以适应元素的添加和删除。
    std::vector提供了一些方法来操作数组，如push_back（在数组末尾添加元素）、pop_back（删除数组末尾的元素）、size（获取数组的大小）等。
    例如，std::vector<int>是一个可以存储整数的动态数组。
	C++中的std::vector支持下标访问。
	例如：
    std::vector<int> v = {1, 2, 3, 4, 5};
	std::cout << v[0];  // 输出：1


    std::pair是一个可以存储两个元素的结构。这两个元素可以是任何类型，可以相同，也可以不同。
    std::pair提供了两个公共成员变量：first和second，分别用于访问存储在pair中的第一个和第二个元素。
    例如，std::pair<int, std::string>可以存储一个整数和一个字符串。
    int main() {
        pair<std::string, int> pair = make_pair("Hello", 5);

        // 输出pair中的元素
        std::cout << pair.first << " " << pair.second << std::endl;

        return 0;
    }
 * @param seq 
 * @return std::pair<int, std::pair<int, int> > 
 */

// 计算最大子序列
std::pair<int, std::pair<int, int> > max_subsequence(std::vector<int> seq) {
    int max_sum = -1;
    int temp_sum = 0;
    int start = 0;
    int end = 0;
    int temp_index = 0;

    // 遍历序列
    for (int i = 0; i < seq.size(); i++) {
        temp_sum += seq[i];
        // 如果临时和小于0，重置临时和和临时索引
        if (temp_sum < 0) {
            temp_sum = 0;
            temp_index = i + 1;
        }
        // 如果临时和大于最大和，更新最大和和起始、结束索引
        else if (temp_sum > max_sum) {
            max_sum = temp_sum;
            start = temp_index;
            end = i;
        }
    }

    return std::make_pair(max_sum, std::make_pair(seq[start], seq[end]));
}

int main() {
    int num;
    std::cin >> num; // 输入数字
    int count = 0;
    std::vector<int> seq(num);
    for (int i = 0; i < num; i++) {
        std::cin >> seq[i]; // 输入序列
        if (seq[i] < 0) {
            count += 1;
        }
    }
    if (count != num) {
        int max_sum, first_num, last_num;
        max_sum = max_subsequence(seq).first;
        first_num = max_subsequence(seq).second.first;
        last_num = max_subsequence(seq).second.second;
        std::cout << max_sum << " " << first_num << " " << last_num << std::endl;
    }
    else {
        std::cout << "0 " << seq[0] << " " << seq[seq.size()-1] << std::endl;
    }
    return 0;
}
