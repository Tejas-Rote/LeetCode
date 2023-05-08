class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> temp;
        // priority_queue<int> pq;
        priority_queue<int, vector<int>, greater<int> >pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                // temp.push_back(matrix[i][j]);
                pq.push(matrix[i][j]);
            }
        }

        // sort(temp.begin(), temp.end)
        int ans;
        for(int i=0;i<k-1;i++){
            pq.pop();

        }

        ans = pq.top();
        return ans;
    }
};