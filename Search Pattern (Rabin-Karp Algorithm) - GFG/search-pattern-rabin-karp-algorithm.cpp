//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            vector<int> index;
            int d = 256;
            int q=101;
            int N = txt.size();
            int M = pat.size();
            int i, j;
            int p = 0;
            int t = 0;
            int h = 1;
        

            for (i = 0; i < M-1; i++)
                h = (h*d)%q;

            for (i = 0; i < M; i++)
            {
                p = (d*p + pat[i])%q;
                t = (d*t + txt[i])%q;
            }
        
            for (i = 0; i <= N - M; i++)
            {
        
               
                if ( p == t )
                {
                 
                    for (j = 0; j < M; j++)
                    {
                        if (txt[i+j] != pat[j])
                            break;
                    }
        
                 
                    if (j == M)
                     
                        index.push_back(i+1);
                }

                if ( i < N-M )
                {
                    t = (d*(t - txt[i]*h) + txt[i+M])%q;
        
                    if (t < 0)
                    t = (t + q);
                }
            }
            if(index.size() == 0){
                index.push_back(-1);
                return index;
            }
            
            return index;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends