/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/

/*/*class Solution {
    
private:
    bool isFoundindfs(vector<vector<char>>& board, string word, int k, int i, int j){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size()|| word[k] != board[i][j]){
            return false;
        }
        
        if(k == word.length() - 1) 
            return true;
        
        char current = board[i][j];
        
        board[i][j] = '*'; //this means i have visited the character
        
        bool search_next = isFoundindfs(board, word, k+1, i-1, j) ||
                            isFoundindfs(board, word, k+1, i+1, j) ||
                            isFoundindfs(board, word, k+1, i, j-1) ||
                            isFoundindfs(board, word, k+1, i, j+1);
        
        cout << search_next << " ";
        board[i][j] = current; //reseetting the board game
        
        return search_next;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0; i < m; i++){
            for(int j=0; j< n; j++){
                if(isFoundindfs(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        
        return false;
    }
};*/


 /*  class Solution {
    public:
    	 bool exist(vector<vector<char> > &board, string word) {
    		 m=board.size();
    		 n=board[0].size();
            for(int x=0;x<m;x++)
                for(int y=0;y<n;y++)
                {
    				if(isFound(board,word.c_str(),x,y))
    					return true;
                }
            return false;
        }
    private:
    	int m;
    	int n;
        bool isFound(vector<vector<char> > &board, const char* w, int x, int y)
        {
    		if(x<0||y<0||x>=m||y>=n||board[x][y]=='\0'||*w!=board[x][y])
    			return false;
            if(*(w+1)=='\0')
                return true;
    		char t=board[x][y];
    		board[x][y]='\0';
    		if(isFound(board,w+1,x-1,y)||isFound(board,w+1,x+1,y)||isFound(board,w+1,x,y-1)||isFound(board,w+1,x,y+1))
    			return true; 
    		board[x][y]=t;
            return false;
        }
    };*/
class Solution {
private: 
    /*bool searchword(vector<vector<char>>& board, int i, int j, string& word, int idx, vector<vector<bool>>& visited){
        visited[i][j] = true;
        if(idx == word.length() - 1) return true; //this means ki i have reached the last char of the word and that will only happen if all my chars in the words have been traversed.
        
        //now i have to check for all the 4 directions
        if(i > 0 && !visited[i-1][j] && board[i-1][j] == word[idx+1] && searchword(board, i-1, j, word, idx+1, visited)) return true;
        if(j > 0 && !visited[i][j-1] && board[i][j-1] == word[idx+1] && searchword(board, i, j-1, word, idx+1, visited)) return true;
        if(i < board.size() -1  && !visited[i+1][j] && board[i+1][j] == word[idx+1] && searchword(board, i+1, j, word, idx+1, visited)) return true;
        if(j < board.size() - 1 && !visited[i][j+1] && board[i][j+1] == word[idx+1] && searchword(board, i, j+1 , word, idx+1, visited)) return true;
        
        
        
        visited[i][j] = false;
        return false;
    }*/
    
    //second way for O(1) is to remove visited and convert the character which is visted into something else and then revert it back when not in use.
    
    bool searchword(vector<vector<char>>& board, int i, int j, string& word, int idx){
        if(idx == word.length() - 1) return true;
        board[i][j] -= 65; //we are subtracting the value of character to make it someting else.
        
        //now i have to check for all the 4 directions
        if(i > 0 && board[i-1][j] == word[idx+1] && searchword(board, i-1, j, word, idx+1)) return true;
        if(j > 0  && board[i][j-1] == word[idx+1] && searchword(board, i, j-1, word, idx+1)) return true;
        if(i < board.size() -1 && board[i+1][j] == word[idx+1] && searchword(board, i+1, j, word, idx+1)) return true;
        if(j < board[0].size() - 1 && board[i][j+1] == word[idx+1] && searchword(board, i, j+1 , word, idx+1)) return true;
        
        
        board[i][j] += 65;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        
        //vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        for(int i = 0; i < row; i++){
            for(int j =0; j < col; j++){
                if(board[i][j] == word[0] && searchword(board, i, j, word, 0)) 
                    return true;
            }
        }
        
        return false;
        
    }
};
