"""
���һ��֧�� push��pop��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��

push(x)-- ��Ԫ�� x ����ջ�С�
pop()-- ɾ��ջ����Ԫ�ء�
top()-- ��ȡջ��Ԫ�ء�
getMin() -- ����ջ�е���СԪ�ء�
ʾ��:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> ���� -3.
minStack.pop();
minStack.top();      --> ���� 0.
minStack.getMin();   --> ���� -2.

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/min-stack
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.helper = []

    def push(self, x: int) -> None:
        self.stack.append(x)
        if len(self.helper) == 0:
            self.helper.append(x)
        else:
            if x <= self.helper[-1]:
                self.helper.append(x)

    def pop(self) -> None:
        num = self.stack.pop()
        if len(self.helper) > 0 and num == self.helper[-1]:
            self.helper.pop()


    def top(self) -> int:
        if len(self.stack) == 0:
            return None
        return self.stack[-1]

    def getMin(self) -> int:
        if len(self.helper) == 0:
            return None
        return self.helper[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()