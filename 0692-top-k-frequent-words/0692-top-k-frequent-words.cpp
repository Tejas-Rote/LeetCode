class Solution {
public:
    static bool cmp(pair<int, string> a, pair<int, string> b){
        if(a.first == b.first){
            return a.second<b.second;
        }else {
            return a.first>b.first;
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string, int> mp;
        vector<string> ans;
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        vector<pair<int, string>> v;
        for(auto it: mp){
            v.push_back({it.second,it.first});
            // cout<<it.first<<" "<<it.second<<endl;
        }
        
        sort(v.begin() , v.end(), cmp);
        // reverse(v.begin() , v.end());
        for(auto i:v){
            // cout<<i.first<<" "<<i.second<<endl; 
            if(k>0){
                ans.push_back(i.second);
                k--;
            }
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};