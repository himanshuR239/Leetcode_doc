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
    void reorderList(ListNode* head) {
        if(!head) return;

        // Step1: find the middle node
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is the mid

        // Step2: Reverse the second half
        ListNode* prev = NULL;
        ListNode* cur = slow->next;
        slow->next = NULL; //Split into two halves

        while(cur){
            ListNode* next_node = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next_node;
        } //prev is new head of reversed second half

        // Step3: Merge the two half
        ListNode* first = head;
        ListNode* sec = prev;
        while(sec){
            ListNode* temp1 = first->next;
            ListNode* temp2 = sec->next;

            first->next = sec;
            sec->next = temp1;

            first = temp1;
            sec = temp2;
        }
    }
};