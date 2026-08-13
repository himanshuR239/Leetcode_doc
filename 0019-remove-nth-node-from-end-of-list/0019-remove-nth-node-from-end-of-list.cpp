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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        if(!head || !head->next) return NULL;
        // cnt no. of nodes
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp->next;
        }
        if(cnt == n){
            return head->next;
        }

        temp = head;
        int rem = cnt - n;
        while(temp){
            rem--;
            if(rem == 0){
                ListNode* del = temp->next;
                temp->next = temp->next->next;
                delete del;
                break;
            }
            temp = temp->next;
        }

        return head;
    }
};