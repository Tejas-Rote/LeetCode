class Solution {
private: 
    struct Cmp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first == b.first) {
                return a.second < b.second;
            } else {
                return a.first > b.first;
            }
        }
    };
public:
    // static bool cmp(pair<int, string> a, pair<int, string> b){
    //     if(a.first == b.first){
    //         return a.second<b.second;
    //     }else {
    //         return a.first>b.first;
    //     }
    // }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string, int> mp;
        vector<string> ans;
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Cmp> pq;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            pq.push(make_pair(it->second, it->first));
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()) {
            ans.insert(ans.begin(), pq.top().second);
            pq.pop();
        }
        return ans;
        
        
//         vector<pair<int, string>> v;
//         for(auto it: mp){
//             v.push_back({it.second,it.first});
//         }
        
//         sort(v.begin() , v.end(), cmp);
//         for(auto i:v){
//             if(k>0){
//                 ans.push_back(i.second);
//                 k--;
//             }
//         }
        // return ans;
    }
};