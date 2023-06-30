//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int n, int capacity, int pages[]){
        unordered_set<int> s;
    
        unordered_map<int, int> indexes;
        int page_faults = 0;
        for (int i=0; i<n; i++)
        {
            if (s.size() < capacity)
            {
                if (s.find(pages[i])==s.end())
                {
                    s.insert(pages[i]);
                    page_faults++;
                }
                indexes[pages[i]] = i;
            }
     
           
            else
            {
                if (s.find(pages[i]) == s.end())
                {
                    int lru = INT_MAX, val;
                    for (auto it=s.begin(); it!=s.end(); it++)
                    {
                        if (indexes[*it] < lru)
                        {
                            lru = indexes[*it];
                            val = *it;
                        }
                    }
                    s.erase(val);
                    s.insert(pages[i]);
                    page_faults++;
                }
                indexes[pages[i]] = i;
            }
        }
 
    return page_faults;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends