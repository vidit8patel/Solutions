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
    
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *fast = head, *slow = head;
        while(n--)
            fast = fast -> next;
        if(fast == NULL) 
            return head -> next;
        while(fast -> next != NULL)
            fast = fast -> next, slow = slow -> next;
        slow -> next = slow -> next -> next;
        return head;
    }
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* ptr = head;
//         int len = 0;
//         while(head != NULL)
//         {
//             head = head -> next;
//             len++;
//         }
//         if(len == 1)
//             return NULL;
//         if(len == n)
//             return ptr->next;

//         head = ptr;
//         for(int i = 0; i < len; i++)
//         {
//             if(i == len-n-1)
//             {
//                 head->next = head->next->next;
//                 break;
//             }
//             else head = head->next;
//         }
//         return ptr;
//     }
};