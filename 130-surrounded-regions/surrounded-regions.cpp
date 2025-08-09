class Solution {
public:

void dfs(int m,int n,int r,int c,vector <vector<int>>&vis,vector<vector<char>>& mat)
{
    vis[r][c]=1;
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    int nr,nc;
    for (int i = 0; i < 4; i++) {
                nr = r + dr[i];
                nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0&& mat[nr][nc]=='O')
                dfs(m,n,nr,nc,vis,mat);}
                
}

    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        char c;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for (int j=0;j<m;j++){
        if (vis[0][j]==0)
        {
            if(board[0][j]=='O')
            dfs(m,n,0,j,vis,board);
        }

        if (vis[n-1][j]==0){
            if (board[n-1][j]=='O')
            dfs(m,n,n-1,j,vis,board);
        }
        
    }

    for (int j=0;j<n;j++){
        if (vis[j][0]==0)
        {
            if(board[j][0]=='O')
            dfs(m,n,j,0,vis,board);
        }

        if (vis[j][m-1]==0){
            if (board[j][m-1]=='O')
            dfs(m,n,j,m-1,vis,board);
        }
        
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)
        {
            if (vis[i][j]==0)
            board[i][j]='X';
        }
    }
}};