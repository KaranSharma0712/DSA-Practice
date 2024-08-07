//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
private:
    void solve(vector<vector<int>> &mat,vector<string>& ans,string path,int i,int j,int n,vector<vector<int>> &vis){
        if(i==n-1 && j==n-1) {
            ans.push_back(path);
            return;
        }
        string dir = "DLRU";
        int x[4] = {1,0,0,-1};
        int y[4] = {0,-1,1,0};
        
        for(int index = 0; index < 4; index++){
            int nexti = i+x[index];
            int nextj = j+y[index];
            if(nexti >= 0 && nextj >= 0 && nexti<n && nextj < n && mat[nexti][nextj]==1 && !vis[nexti][nextj] ){
                vis[i][j]=1;
                solve(mat,ans,path+dir[index],nexti,nextj,n,vis);
                vis[i][j]=0;
            }
            
        }
        
    }
public:
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        string path;
        if(mat[0][0]==0) return ans;
        vis[0][0]=1;
        solve(mat,ans,"",0,0,n,vis);
        return ans;
   
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
