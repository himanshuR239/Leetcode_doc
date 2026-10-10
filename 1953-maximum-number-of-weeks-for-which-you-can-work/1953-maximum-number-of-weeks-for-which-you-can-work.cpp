class Solution {
public:
    using ll = long long;
    long long numberOfWeeks(vector<int>& milestones) {
        int n = milestones.size();

        ll tot = accumulate(milestones.begin(), milestones.end(), 0LL);

        int maxi = *max_element(milestones.begin(), milestones.end());

        ll ans;
        ans = min(tot, 2*(tot - maxi) + 1);

        return ans;
    }
};