/*
079. Word Search

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

class Solution {
private:
    bool canUse[100][100];
    int step[4][2];
public:
    void check(int dep, int maxDep, string &word, vector<vector<char> > &board, bool &flag, int x, int y) {
        if (flag) return;
            
        if (dep == maxDep) {
            flag = true;
            return;
        }
        
        for(int i = 0; i < 4; i++) {
            int tx = x + step[i][0];
            int ty = y + step[i][1];
            if (0 <= tx && tx < board.size() && 0 <= ty && ty < board[0].size() && canUse[tx][ty] && 
                board[tx][ty] == word[dep]) {
                canUse[tx][ty] = false;
                check(dep + 1, maxDep, word, board, flag, tx, ty);
                canUse[tx][ty] = true;
            }
        }
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        if (word.size() == 0) return true;
        memset(canUse, true, sizeof(canUse));
            
        step[0][0] = 1;
        step[0][1] = 0;
        step[1][0] = -1;
        step[1][1] = 0;
        step[2][0] = 0;
        step[2][1] = 1;
        step[3][0] = 0;
        step[3][1] = -1;
        
        for(int x = 0; x < board.size(); x++) {
            for(int y = 0; y < board[x].size(); y++) {
                if (board[x][y] == word[0])
                {
                    canUse[x][y] = false;
                    bool flag = false;
                    check(1, word.size(), word, board, flag, x, y);
                    if (flag) return true;
                    canUse[x][y] = true;
                }
            }
        }
        
        return false;
    }
};
