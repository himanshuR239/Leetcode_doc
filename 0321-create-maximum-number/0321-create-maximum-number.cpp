class Solution {
public:
    vector<int> maxnum(vector<int>& nums, int len){
        vector<int> res;
        int n = nums.size();
        int drop = n - len;

        for(int i = 0; i < n; i++){
            while(!res.empty() && res.back() < nums[i] && drop > 0){
                res.pop_back();
                drop--;
            }
            res.push_back(nums[i]);
        }

        res.resize(len);

        return res;
    }

    string merge(vector<int> &n1, vector<int> &n2, int k){
        vector<int> res(k, 0);
        // string s1 = "", s2 = "";
        // for(int i = 0; i < n1.size(); i++) s1 += n1[i] + '0';
        // for(int i = 0; i < n2.size(); i++) s2 += n2[i] + '0';

        // if(s2 > s1) return merge(n2,n1,k);

        int i = 0, j = 0, x = 0;
        while(i < n1.size() && j < n2.size()){
            if(n2[j] > n1[i]){
                res[x++] = n2[j];
                j++;
            }
            else if(n1[i] == n2[j]){
                int ind1 = i, ind2 = j;
                while(ind1 < n1.size() && ind2 < n2.size() && n1[ind1] == n2[ind2]){
                    ind1++;
                    ind2++;
                }

                if(ind2 == n2.size() || (ind1 < n1.size() && n1[ind1] > n2[ind2])){
                    res[x++] = n1[i];
                    i++;
                }
                else{
                    res[x++] = n2[j];
                    j++;
                }
            }
            else{
                res[x++] = n1[i];
                i++;
            }
        }
        while(i < n1.size()){
            res[x++] = n1[i];
            i++;
        }
        while(j < n2.size()){
            res[x++] = n2[j];
            j++;
        }

        string ans = "";

        for(int i = 0; i < k; i++) ans += to_string(res[i]);
        return ans;

    }


    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        string s = "";
        for(int i = 0; i <= m && i <= k; i++){
            if(k - i > n) continue;

            vector<int> n1 = maxnum(nums1, i);
            vector<int> n2 = maxnum(nums2, k-i);
            string st = merge(n1, n2, k);

            s = max(s, st);
        }

        vector<int> ans;
        for(int i = 0; i < s.size(); i++){
            ans.push_back(s[i] - '0');
        }

        return ans;
    }
};