class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }

    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> pq(cmp);
        int n = a.size();
        for (int i = 0; i < n; i++) {
            int diff = abs(a[i] - x);
            pq.push({a[i], diff});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        // reverse(ans.begin(), ans.end());
        return ans;
    }

};