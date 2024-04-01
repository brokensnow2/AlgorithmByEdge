#include <iostream>
#include <ctime>

// 主函数
int main() {
    // 输入年、月、日
    int year, month, day;
    std::cin >> year >> month >> day;

    /*
    这段代码是在初始化一个struct tm类型的变量time_in。struct tm是C++中的一个结构体，用于表示时间。
    它的成员包括：

	struct tm {
  		int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
  		int tm_min;   // 分，范围从 0 到 59
  		int tm_hour;  // 小时，范围从 0 到 23
  		int tm_mday;  // 一月中的第几天，范围从 1 到 31
  		int tm_mon;   // 月，范围从 0 到 11
  		int tm_year;  // 自 1900 年起的年数
  		int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
  		int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
  		int tm_isdst; // 夏令时
	};
	所以，struct tm time_in = {0, 0, 0, day, month - 1, year - 1900};这行代码的意思是创建一个struct tm类型的变量time_in，并将其初始化为指定的日期和时间。具体来说：

	0, 0, 0表示秒、分钟和小时都设置为0，也就是说时间设置为00:00:00。
	day是一个月中的第几天，直接使用输入的day。
	month - 1是月份，因为struct tm的tm_mon是从0开始计数的，所以需要将输入的month减1。
	year - 1900是年份，因为struct tm的tm_year是从1900年开始计数的，所以需要将输入的year减1900。
    */
    // 设置时间结构体
    tm time_in = {
         0, 0, 0, day, month - 1, year - 1900 
    };

    // 将指定时间转换为时间戳
    time_t time_temp = mktime(&time_in);

    // 再转换回时间结构体，获取星期
    tm* time_out = localtime(&time_temp);

    // 输出结果
    switch (time_out->tm_wday) {
        case 0: std::cout << "星期日" << std::endl; break;
        case 1: std::cout << "星期一" << std::endl; break;
        case 2: std::cout << "星期二" << std::endl; break;
        case 3: std::cout << "星期三" << std::endl; break;
        case 4: std::cout << "星期四" << std::endl; break;
        case 5: std::cout << "星期五" << std::endl; break;
        case 6: std::cout << "星期六" << std::endl; break;
    }

    return 0;
}
