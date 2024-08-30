def is_prime(num):
    """判断一个数是否是素数"""
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

def next_prime(num):
    """找到大于等于num的下一个素数"""
    while not is_prime(num):
        num += 1
    return num

def hash_function(key, t_size):
    """哈希函数"""
    return key % t_size

def insert_and_locate(nums, m_size, n):
    """插入并定位元素"""
    t_size = next_prime(m_size)
    hash_table = [-1] * t_size  # 初始化哈希表，-1表示空位

    result = []
    for i in range(n):
        num = nums[i]
        index = hash_function(num, t_size)

        if hash_table[index] != -1: # 二次探测
            for j in range(1, n):  # 使用不同的变量 j
                next_index = (index + j**2) % t_size
                if hash_table[next_index] == -1:
                    hash_table[next_index] = num
                    result.append(next_index)
                    break
                elif j == n - 1:  # 如果已经进行了 n-1 次探测，仍未找到空位
                    result.append('-')
                    break
        else:
            hash_table[index] = num
            result.append(index)

    return result

# 读取输入
m_size, n = map(int, input().split())
nums = list(map(int, input().split()))

# 插入并定位元素，并输出结果
result = insert_and_locate(nums, m_size, n)
print(" ".join(map(str, result)))

