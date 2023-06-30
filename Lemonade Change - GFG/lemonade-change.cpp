//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        
        // code here
        vector<pair<int, int>> amt;
        amt.push_back({20,0});
        amt.push_back({10,0});
        amt.push_back({5,0});
        
        
        int n= bills.size();
        
        for(int i=0;i<n;i++){
            int change =0;
            change  = bills[i] - 5;
            
            // add to amt
            if(bills[i] == 5){
                amt[2].second++;
            }
            
            if(bills[i] == 10){
                amt[1].second++;
            }
            
            if(bills[i] == 20){
                amt[0].second++;
            }
            
            // for(int i=0;i<3;i++){
            //     cout<<amt[i].first<<" -> "<<amt[i].second<<endl;
            // }
            
            if(change != 0 ){
                for(int i=0;i<3;i++){
                    if(amt[i].second != 0){
                        // if(amt[i].first  == change){
                        //     amt[i].second--;
                        // }
                        
                        if(amt[i].first <= change) {
                            int c = change / amt[i].first;
                            // cout<<"C is "<<c<<endl;
                            if(c<= amt[i].second){
                                change   = change  - (c* amt[i].first);
                                amt[i].second -= c;
                            }
                        }
                    }
                }
                
                
                if(change != 0){
                    // cout<<"lefy - "<<change<<endl;
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends