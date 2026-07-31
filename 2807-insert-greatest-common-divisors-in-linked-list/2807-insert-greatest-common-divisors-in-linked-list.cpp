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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* temp1 = head;
        while(temp1->next){
            ListNode* temp = new ListNode(gcd(temp1->val, temp1->next->val));
            temp->next = temp1->next;
            temp1->next = temp;

            temp1 = temp->next;
        }

        return head;
    }
};