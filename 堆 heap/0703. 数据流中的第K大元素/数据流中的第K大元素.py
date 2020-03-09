"""
���һ���ҵ��������е�K��Ԫ�ص��ࣨclass����ע���������ĵ�K��Ԫ�أ����ǵ�K����ͬ��Ԫ�ء�

���KthLargest����Ҫһ��ͬʱ��������k ����������nums�Ĺ��������������������еĳ�ʼԪ�ء�ÿ�ε���KthLargest.add�����ص�ǰ�������е�K���Ԫ�ء�

ʾ��:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);// returns 4
kthLargest.add(5);// returns 5
kthLargest.add(10);// returns 5
kthLargest.add(9);// returns 8
kthLargest.add(4);// returns 8
˵��:
����Լ���nums�ĳ��ȡ�k-1��k ��1��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/kth-largest-element-in-a-stream
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
