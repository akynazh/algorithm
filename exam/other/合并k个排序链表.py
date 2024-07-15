"""
合并k个排序链表 · Merge K Sorted Lists

描述
合并 k 个排序链表（序列为升序序列），并且返回合并后的排序链表（序列为升序学列）。尝试分析和描述其复杂度。

样例：

输入：

lists = [2->6->null,5->null,7->null]
输出：

2->5->6->7->null
解释：

将2->6->null、5->null和7->null合并成一个升序的链表。
"""


class Node:
    def __init__(self, v: int) -> None:
        self.v = v
        self.next = None


def solve(lst) -> Node:
    if not lst:
        return
    res = Node(0)
    root = res
    c = len(lst)
    while c > 0:
        m = 0x7F7F7F7F
        idx = -1
        for i in range(len(lst)):
            node = lst[i]
            if node and node.v < m:
                idx = i
                m = node.v
        if idx >= 0:
            lst[idx] = lst[idx].next
            if not lst[idx]:
                c -= 1
            res.next = Node(m)
            res = res.next
    return root.next


h = Node(1)
h.next = Node(2)
h.next.next = Node(3)
h1 = Node(0)
h1.next = Node(4)
res = solve([h, h1])
while res:
    print(res.v)
    res = res.next
