/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* groupprev=dummy;

        while(true){
            ListNode* kth=groupprev;
            for(int i=0;i<k;i++){
                kth=kth->next;
                if(kth==nullptr)
                    return dummy->next;
            }
            ListNode* groupnext=kth->next;
            ListNode* prev=groupnext;
            ListNode* curr=groupprev->next;
            while(curr!=groupnext){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            ListNode* temp=groupprev->next;
            groupprev->next=kth;
            groupprev=temp;
        }
        return dummy->next;

    }
};
