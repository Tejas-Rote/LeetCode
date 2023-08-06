class Solution {
public:
    // static bool cmp(pair<char, pair<int, int>> a, pair<char, pair<int, int>> b) {
    //     if (a.second.first != b.second.first) {
    //         return a.second.first > b.second.first; 
    //     }
    //     return a.second.second < b.second.second; 
    // }
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto it : freqMap) {
            pq.push({it.second, it.first});
        }

        string ans;
        while (!pq.empty()) {
            pair<int, char> topElement = pq.top();
            pq.pop();
            while (topElement.first--) {
                ans += topElement.second;
            }
        }

        return ans;
//         int n = s.size();
//         map<char, pair<int, int>> mp;
//         for(int i=0;i<n;i++){
//             if(mp.find(s[i] )== mp.end()){
//                 mp.insert({s[i], {1, i}});
//             }else {
//                 mp[s[i]].first++;
//             }
//         }

//         vector<pair<char, pair<int, int>>> vec;
//         for (auto it : mp) {
//             vec.push_back(it);
//         }
//         sort(vec.begin(), vec.end(), cmp);
        
//         string ans;
//         for (auto it : vec) {
//             while(it.second.first--){
//                 ans +=it.first;
//             }
//         }

//         return ans;
    }
};