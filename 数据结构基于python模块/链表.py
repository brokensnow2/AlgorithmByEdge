# 链表节点定义
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
# 链表反转
def reverseList(head):
    prev, curr = None, head
    while curr:
        nxt = curr.next       # 保存下一个
        curr.next = prev      # 翻转指向
        prev = curr           # 前进
        curr = nxt
    return prev               # prev 是新头

def reverseList2(head):
    if not head or not head.next:
        return head
    new_head = reverseList(head.next)  # 递归翻转后面
    head.next.next = head              # 后一个指向我
    head.next = None                   # 我指向None
    return new_head

# 头插法反转
def insert_head(head, list_new):
    new_node = ListNode(head.val)
    new_node.next = list_new.next
    list_new.next = new_node

def reverseList3(head):
    list_new = ListNode()
    while head:
        insert_head(head, list_new)
        head = head.next
    return list_new.next

# 头插法反转
def reverseList3_1(head):
    dummy = ListNode(0)          # 局部变量，每次调用都是新的
    while head:
        next_node = head.next    # 先保存下一个，否则断链后找不到了
        head.next = dummy.next   # 当前节点指向新链表的第一个节点
        dummy.next = head        # 哑节点指向当前节点（头插）
        head = next_node         # 移动到原链表的下一个
    return dummy.next