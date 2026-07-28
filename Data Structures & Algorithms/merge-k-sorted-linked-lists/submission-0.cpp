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

    ListNode* merge(ListNode* l1, ListNode* l2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 != NULL && l2 != NULL) {

            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        if (l1)
            tail->next = l1;
        else
            tail->next = l2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.empty())
            return NULL;

        while (lists.size() > 1) {

            vector<ListNode*> merged;

            for (int i = 0; i < lists.size(); i += 2) {

                ListNode* l1 = lists[i];

                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : NULL;

                merged.push_back(merge(l1, l2));
            }

            lists = merged;
        }

        return lists[0];
    }
};
