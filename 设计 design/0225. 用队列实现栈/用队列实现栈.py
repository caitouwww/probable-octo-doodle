"""
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是push to back, peek/pop from front, size, 和is empty这些操作是合法的。
你所使用的语言也许不支持队列。你可以使用 list 或者 deque（双端队列）来模拟一个队列, 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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