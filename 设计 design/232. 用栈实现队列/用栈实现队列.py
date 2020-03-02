"""
ʹ��ջʵ�ֶ��е����в�����

push(x) -- ��һ��Ԫ�ط�����е�β����
pop() -- �Ӷ����ײ��Ƴ�Ԫ�ء�
peek() -- ���ض����ײ���Ԫ�ء�
empty() -- ���ض����Ƿ�Ϊ�ա�
ʾ��:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // ���� 1
queue.pop();   // ���� 1
queue.empty(); // ���� false
˵��:

��ֻ��ʹ�ñ�׼��ջ���� -- Ҳ����ֻ��?push to top,?peek/pop from top,?size, ��?is empty?�����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
�������в���������Ч�� �����磬һ���յĶ��в������ pop ���� peek ��������

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/implement-queue-using-stacks
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
"""
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.A = []
        self.B = []

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.A.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if self.empty():
            return
        if len(self.B)==0:
            while len(self.A)!=0:
                self.B.append(self.A.pop())
            return self.B.pop()
        else:
            return self.B.pop()


    def peek(self) -> int:
        """
        Get the front element.
        """
        if self.empty():
            return 
        if len(self.B)==0:
            while len(self.A)!=0:
                self.B.append(self.A.pop())
            return self.B[-1]
        else:
            return self.B[-1]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        if len(self.A)==0 and len(self.B)==0:
            return True
        return False


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()