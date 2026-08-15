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
    // custom comparator to compare by node value not bu node address
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val < b->val; //max heap
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;

        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp){
                pq.push(temp);
                temp = temp->next;
            }
        }
        if(pq.empty()) return NULL;

        ListNode* ans = pq.top();
        pq.pop();
        ans->next = NULL;

        while(!pq.empty()){
            ListNode* temp = pq.top();
            pq.pop();
            temp->next = ans;
            ans = temp;
        }

        return ans;
    }
};