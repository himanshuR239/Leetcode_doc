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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        int n = 1;
        ListNode* temp = head;
        while(temp->next){
            n++;
            temp = temp->next;
        }
        k = k % n;
        if(k == 0) return head;
        temp->next = head;

        int rem = n - k;
       
        ListNode* temp2 = head;
        for(int i = 1; i < rem; i++){
            temp2 = temp2->next;
        }
        ListNode* new_head = temp2->next;
        temp2->next = NULL;;
    
        return new_head;
    }
};