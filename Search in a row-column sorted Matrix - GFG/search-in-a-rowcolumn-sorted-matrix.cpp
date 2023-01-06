//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > mat, int n, int m, int x) 
    {
        // code here
        // bool ans =false;
        // if(n==1){
        //     for(int i=0;i<m;i++){
        //         if(matrix[0][i] == x){
        //           ans = true ;
        //         }
        //     }
        // }
        // else {
        //     int row;
        //     for(int i=0;i<n;i++){
        //         if(matrix[i][0] >x){
        //             row = i;
        //             break;
        //         }
        //     }
            
        //     cout<<row;
            
        //     for(int i=0;i<m;i++){
        //         if(matrix[row][i] == x){
        //           ans = true ;
        //         }
        //     }
        // }
        // return ans;
        
    //     if(n==0){
    //         return -1;
    //     }
        
    //     int smallest = matrix[0][0] ;
    //     int largest = matrix[0][0];
        
        
    //     if(x<smallest || x > largest){
    //         return -1;
    //     }
        
        
        
    //     int i=0,j=n-1;
    //     while(i<n && j>=0){
    //         if(matrix[i][j] == x){
    //             return 1;
            
    //         if(matrix[i][j]>x){
    //             j--;
    //         }else {
    //             i++;
    //         }
    //     }
    // }
    
    
    
    
    if (n == 0)
        return -1;
 
    int smallest = mat[0][0], largest = mat[n - 1][m - 1];
    if (x < smallest || x > largest)
        return -1;
 
    // set indexes for top right element
    int i = 0, j = n - 1;
    while (i < n && j >= 0) {
        if (mat[i][j] == x) {
            // cout << "Element found at " << i << ", " << j;
            return 1;
        }
        if (mat[i][j] > x)
            j--;
 
        // Check if mat[i][j] < x
        else
            i++;
    }
 
    // cout << "n Element not found";
    return 0;
    
    
    
    
    
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends