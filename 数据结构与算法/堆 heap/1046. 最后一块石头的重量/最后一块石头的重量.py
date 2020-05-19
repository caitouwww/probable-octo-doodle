"""
��һ��ʯͷ��ÿ��ʯͷ������������������

ÿһ�غϣ�����ѡ���������ص�ʯͷ��Ȼ������һ����顣����ʯͷ�������ֱ�Ϊx ��y����x <= y����ô����Ŀ��ܽ�����£�

���x == y����ô����ʯͷ���ᱻ��ȫ���飻
���x != y����ô����Ϊx��ʯͷ������ȫ���飬������Ϊy��ʯͷ������Ϊy-x��
������ֻ��ʣ��һ��ʯͷ�����ش�ʯͷ�����������û��ʯͷʣ�£��ͷ��� 0��



��ʾ��

1 <= stones.length <= 30
1 <= stones[i] <= 1000

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/last-stone-weight
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
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
        