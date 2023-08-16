class Solution {
public:
    vector<int> printMax(vector<int>& arr, int n, int k) {
        deque<int> Qi(k);
        vector<int> ans;

        int i;
        for (i = 0; i < k; ++i) {
            while (!Qi.empty() && arr[i] >= arr[Qi.back()])
                Qi.pop_back();

            Qi.push_back(i);
        }

        for (; i < n; ++i) {
            ans.push_back(arr[Qi.front()]);
            cout << arr[Qi.front()] << " ";

            while (!Qi.empty() && Qi.front() <= i - k)
                Qi.pop_front();

            while (!Qi.empty() && arr[i] >= arr[Qi.back()])
                Qi.pop_back();

            Qi.push_back(i);
        }
        ans.push_back(arr[Qi.front()]);
        cout << arr[Qi.front()] << endl;
        return ans;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxE  = INT_MIN;
        int n = nums.size();
       
        return  printMax(nums, n, k);
    }
};