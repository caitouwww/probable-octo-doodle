"""
有一堆石头，每块石头的重量都是正整数。

每一回合，从中选出两块最重的石头，然后将它们一起粉碎。假设石头的重量分别为x 和y，且x <= y。那么粉碎的可能结果如下：

如果x == y，那么两块石头都会被完全粉碎；
如果x != y，那么重量为x的石头将会完全粉碎，而重量为y的石头新重量为y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。



提示：

1 <= stones.length <= 30
1 <= stones[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/last-stone-weight
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
#import heapq
from heapq import heapify,heappop,heappush
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        """
        l = len(stones)
        if l==1:
            return stones[0]
        else:
            heap_stones = heapq.nlargest(l,stones)
            while len(heap_stones)>1:
                if heap_stones[0]==heap_stones[1]:
                    heapq.heappop(heap_stones)
                    heap_stones.sort(reverse=True)
                    heapq.heappop(heap_stones)
                elif heap_stones[0]!=heap_stones[1]:
                    tmp = heap_stones[0]-heap_stones[1]
                    heapq.heappop(heap_stones)
                    heap_stones.sort(reverse=True)
                    heapq.heappop(heap_stones)
                    heapq.heappush(heap_stones,tmp)
                heap_stones.sort(reverse=True)
        
        if len(heap_stones)==1:
            return heap_stones[0]
        else:
            return 0
        """
        for i in range(len(stones)):
            stones[i] = -stones[i]
        
        heapify(stones)

        while len(stones)>0:
            y = -heappop(stones)
            if len(stones)==0:
                return y
            x = -heappop(stones)
            if x!=y:
                heappush(stones,x-y)
        return 0
        