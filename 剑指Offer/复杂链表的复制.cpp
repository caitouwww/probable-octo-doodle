/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        cloneNodes(pHead);
        connectRandomNodes(pHead);
        return reconnectNodes(pHead);
    }
    void cloneNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        while(pNode != nullptr){
            RandomListNode* pCloned = new RandomListNode(NULL);
            pCloned->label = pNode->label;
            pCloned->next = pNode->next;
            pCloned->random = nullptr;
             
            pNode->next = pCloned;
            pNode = pCloned->next;
        }
    }
    void connectRandomNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        while(pNode != nullptr){
            RandomListNode* pCloned = pNode->next;
            if(pNode->random != nullptr)
                pCloned->random = pNode->random->next;
            pNode = pCloned->next;
        }
    }
    RandomListNode* reconnectNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        RandomListNode* pClonedHead = nullptr;
        RandomListNode* pClonedNode = nullptr;
         
        if(pNode != nullptr){
            pClonedHead = pNode->next;
            pClonedNode = pNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        while(pNode != nullptr){
            pClonedNode->next = pNode->next;
            pClonedNode = pClonedNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        return pClonedHead;
    }
};