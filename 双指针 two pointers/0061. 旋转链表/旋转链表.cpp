/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head)
    {
        int res=0;
        while(head!=NULL)
        {
            head=head->next;
            res++;
        }
        return res;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        //自写
        // int len=getLength(head);
        // if(len==0)  return head;
        // if(len==1)   return head;
        // if(k%len==0) return head;
        // k=k%len;
        // while(k--)
        // {
        //     ListNode* prev=new ListNode(NULL),*cur=head;
        //     while(cur->next!=NULL)
        //     {   
        //         prev=cur;
        //         cur=cur->next;
        //     }
        //     prev->next=NULL;
        //     cur->next=head;
        //     head=cur;
        // }
        // return head;
        // 说是循环旋转，但其实本质上是将尾部向前数第K个元素作为头，原来的头接到原来的尾上
        if(head==NULL||k==0)    return head;
        ListNode* cursor=head;
        ListNode* tail=new ListNode(NULL);
        int length=1;
        while(cursor->next!=NULL)
        {
            cursor=cursor->next;
            length++;
        }
        int loop=length-(k%length);
        tail=cursor;
        cursor->next=head;
        cursor=head;
        for(int i=0;i<loop;i++)
        {
            cursor=cursor->next;
            tail=tail->next;
        }
        tail->next=NULL;
        return cursor;
    }
};