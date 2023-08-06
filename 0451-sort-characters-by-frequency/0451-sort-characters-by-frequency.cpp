class Solution {
public:
    static bool cmp(pair<char, pair<int, int>> a, pair<char, pair<int, int>> b) {
        if (a.second.first != b.second.first) {
            return a.second.first > b.second.first; // Sort by frequency in descending order
        }
        return a.second.second < b.second.second; // Sort by index in ascending order
    }
    string frequencySort(string s) {
        int n = s.size();
        map<char, pair<int, int>> mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i] )== mp.end()){
                mp.insert({s[i], {1, i}});
            }else {
                mp[s[i]].first++;
            }
        }
        
        // for(auto i :mp){
        //     cout<<i.first<<" -> "<<i.second.first<<" "<<i.second.second<<endl;
        // }
        // cout<<endl;
        vector<pair<char, pair<int, int>>> vec;
        for (auto it : mp) {
            vec.push_back(it);
        }
        sort(vec.begin(), vec.end(), cmp);
        
        string ans;
        for (auto it : vec) {
            // cout << "Char: " << it.first << ", f: " << it.second.first << ", i : " << it.second.second << endl;
            while(it.second.first--){
                ans +=it.first;
            }
        }
        
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};