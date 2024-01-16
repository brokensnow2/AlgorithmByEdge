def Hanoi(n :int, src :str, mid :str, dest :str):
    """

    :parma n: n个盘子
    :parma src: 源
    :parma mid: 中转
    :parma dest: 目的地
    """
    if n == 1:
        print(f"{src}->{dest}")
        return
    Hanoi(n-1,src,dest,mid) # 将n-1个盘子放到中转
    print(f"{src}->{dest}") # 将第n个盘子放到目的地
    Hanoi(n-1,mid,src,dest) # 将n-1个盘子放到目的地
    return

num = int(input())
Hanoi(num,'A','B','C')