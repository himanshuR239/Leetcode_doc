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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, 0);
        ans[0] = INT_MAX;
        ans[1] = INT_MIN;
        ListNode* temp = head;
        ListNode* temp1 = temp->next;
        ListNode* temp2 = temp1->next;

        if(!temp || !temp1 || !temp2) return {-1, -1};

        int cnt = 1;
        vector<int> arr;
        while(temp2){
            if((temp1->val > temp->val && temp1->val > temp2->val) || (temp1->val < temp->val && temp1->val < temp2->val)){
                arr.push_back(cnt);
            }
            cnt++;
            temp2 = temp2->next;
            temp1 = temp1->next;
            temp = temp->next;
        }
        int n = arr.size();
        for(int i = 1; i < n; i++){
            ans[0] = min(ans[0], arr[i] - arr[i-1]);
            ans[1] = arr[n-1] - arr[0];
        }

        if(ans[0] == INT_MAX || ans[1] == INT_MIN) return {-1, -1};
        return ans;
    }
};