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
    ListNode* solve(ListNode* head, int k, int times)
    {
        if(head == NULL || times == 0)
            return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* succ = NULL;
        int count = 0;
        while(curr != NULL && count < k)
        {
            succ = curr->next;
            curr->next = prev;
            prev = curr;
            curr = succ;
            count++;          
        }
        head->next = solve(succ, k, --times);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int length = 0;
        while(temp != NULL)
        {
            ++length;
            temp = temp->next;
        }
        int times =length/k;
        return solve(head, k, times);
    }
};