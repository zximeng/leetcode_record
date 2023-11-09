class Solution {
public:
    // brute force, just check every cell one by one
    //directions to check 
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int length;
    int m;
    int n;
    bool placeWordInCrossword(vector<vector<char>>& board, string word) 
    {
        m = board.size();
        n = board[0].size();
        length = word.size();
        
        for (int i = 0; i < m; i++) {
            for( int j = 0; j < n; j++) {
                if (board[i][j] != '#') {
                    int idx = 0;
                    // the previous cell need to be blocked && s
                    if (((i-length+1)>=0) && (i==(m-1) || board[i+1][j]=='#') && verify(board,word,i,j,idx,0)) {
                        return true;
                    }
                    if(((m-i)-length>=0) && (i==0 or board[i-1][j] == '#') && (verify(board,word,i,j,idx,1))) {
                        return true;
                    }
                    if ((j+1-length>=0) && (j==(n-1) or board[i][j+1]=='#') && verify(board,word,i,j,idx,2)) {
                        return true;
                    }
                    if (((n-j)-length>=0) && (j==0 or board[i][j-1]=='#') && verify(board,word,i,j,idx,3)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    int verify(vector<vector<char>>& board, string word, int i, int j, int idx, int d)
    {
        if (idx == length) {
            if (i >=0 && i <m && j >=0 && j <n && board[i][j]!='#') {
                return 0;
            }
            return 1;
        }
        // if still valid 
        if  (board[i][j]==' ' || board[i][j]==word[idx]) {
            if (verify(board, word, i+dir[d][0], j+dir[d][1], idx+1, d)) {
                return 1;
            }
        }
    
        return 0;
    }
};