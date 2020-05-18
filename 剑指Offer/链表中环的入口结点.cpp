/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* meetingNode = MeetingNode(pHead);
        if(meetingNode == nullptr)    return nullptr;
        //得到环中节点的数目
        int nodesInLoop = 1;
        ListNode* pNode1 = meetingNode;
        while(pNode1->next != meetingNode){
            pNode1 = pNode1->next;
            ++nodesInLoop;
        }
        //先移动pNode1，次数为环中节点的数目
        pNode1 = pHead;
        for(int i = 0; i < nodesInLoop; i++){
            pNode1 = pNode1->next;
        }
        //再移动pNode1和pNode2
        ListNode* pNode2 = pHead;
        while(pNode1 != pNode2){
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        return pNode1;
    }
    ListNode* MeetingNode(ListNode* pHead){
        if(pHead == nullptr)    return nullptr;
        
        ListNode* pSlow = pHead->next;
        if(pSlow == nullptr)    return nullptr;
        
        ListNode* pFast = pSlow->next;
        while(pFast != nullptr && pSlow != nullptr){
            if(pFast == pSlow)    return pFast;
            
            pSlow = pSlow->next;
            pFast = pFast->next;
            if(pFast != nullptr)    pFast = pFast->next;
        }
        return nullptr;
    }
};