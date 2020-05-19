"""
ʹ�ö���ʵ��ջ�����в�����

push(x) -- Ԫ�� x ��ջ
pop() -- �Ƴ�ջ��Ԫ��
top() -- ��ȡջ��Ԫ��
empty() -- ����ջ�Ƿ�Ϊ��
ע��:

��ֻ��ʹ�ö��еĻ�������-- Ҳ����push to back, peek/pop from front, size, ��is empty��Щ�����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧�ֶ��С������ʹ�� list ���� deque��˫�˶��У���ģ��һ������, ֻҪ�Ǳ�׼�Ķ��в������ɡ�
����Լ������в���������Ч�ģ�����, ��һ���յ�ջ������� pop ���� top ��������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/implement-stack-using-queues
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
from queue import Queue
class MyStack:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.queue_push = Queue()
        #self.queue_pop = Queue()
        

    def push(self, x: int) -> None:
        """
        Push element x onto stack.
        """
        self.queue_push.put(x)
        #self.top_ele = x
        #self.shift()
        size = self.queue_push.qsize()
        while size > 1:
            self.queue_push.put(self.queue_push.get())
            size = size - 1
        
    """
    def shift(self):
        while self.queue_pop.qsize():
            self.queue_push.put(self.queue_pop.get())
        self.queue_pop, self.queue_push = self.queue_push, self.queue_pop
    """    
    def pop(self) -> int:
        """
        Removes the element on top of the stack and returns that element.
        """
        """
        while self.queue_push.qsize()>1:
            self.top_ele = self.queue_push.get()
            self.queue_pop.put(self.top_ele)
        res = self.queue_push.get()
        self.queue_push, self.queue_pop = self.queue_pop, self.queue_push
        return res
        """
        #return self.queue_pop.get()
        return self.queue_push.get()

    def top(self) -> int:
        """
        Get the top element.
        """
        #return self.top_ele
        
        top = self.queue_push.get()
        self.push(top)
        return top

    def empty(self) -> bool:
        """
        Returns whether the stack is empty.
        """
        return self.queue_push.empty()

# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()