"""
设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。

你的KthLargest类需要一个同时接收整数k 和整数数组nums的构造器，它包含数据流中的初始元素。每次调用KthLargest.add，返回当前数据流中第K大的元素。

示例:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);// returns 4
kthLargest.add(5);// returns 5
kthLargest.add(10);// returns 5
kthLargest.add(9);// returns 8
kthLargest.add(4);// returns 8
说明:
你可以假设nums的长度≥k-1且k ≥1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-a-stream
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
import heapq
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.pool = heapq.nlargest(k,nums)[::-1]
        self.k = k

    def add(self, val: int) -> int:
        if len(self.pool)<self.k:
            heapq.heappush(self.pool, val)
        elif val > self.pool[0]:
            heapq.heapreplace(self.pool, val)
        
        return self.pool[0]


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
