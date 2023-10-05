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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
        {
            return l2;
        }
        if(l2 == nullptr)
        {
            return l1;
        }

        ListNode* res_list = new ListNode();
        ListNode* cur_node = res_list;
        int flag = 0;
        while(l1 != nullptr && l2 != nullptr)
        {
            int cur_val = (l1->val + l2->val + flag) % 10;
            cur_node -> next = new ListNode(cur_val);
            cur_node = cur_node->next;
            if((l1->val + l2->val + flag) >= 10)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* l = l1 == nullptr ? l2 : l1;
        while(l != nullptr)
        {
            int cur_val = (l->val + flag) % 10;
            cur_node -> next = new ListNode(cur_val);
            cur_node = cur_node->next;
            if((l->val + flag) >= 10)
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
            l = l->next;
        }
        if(flag)
        {
            cur_node->next = new ListNode(1);
        }
        return res_list->next;
    }
};