#include "template/template.h"
size_t s = 0;
bool ans = false;
void find(vector<vector<char>> &b, string &w, int count, int i, int j){
    if(count >= s){
        ans = true;
        return;
    }else{
        char last = w[count];
        if (j > 0){
            if (b[i][j-1] == last){
                b[i][j-1] = ' ';
                find(b, w, count+1, i, j-1);
                b[i][j-1] = last;
            }
        }
        if (i > 0){
            if (b[i-1][j] == last){
                b[i-1][j] = ' ';
                find(b, w, count+1, i-1, j);
                b[i-1][j] = last;
            }
        }
        if (i < b.size()-1){
            if (b[i+1][j] == last){
                b[i+1][j] = ' ';
                find(b, w, count+1, i+1, j);
                b[i+1][j] = last;
            }
        }
        if (j < b[0].size()-1){
            if (b[i][j+1] == last) {
                b[i][j+1] = ' ';
                find(b, w, count+1, i, j+1);
                b[i][j+1] = last;
            }
        }
    }
}
int main(){
    vector<vector<char>> board {{'a', 'a'}};
    vector<pair<int,int>> start;
    string word = "aaa";
    s = word.size();
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            if (board[i][j] == word[0]){
                start.emplace_back(i,j);
            }
        }
    }
    for (auto x: start){
        board[x.first][x.second] = ' ';
        find(board, word, 1, x.first,x.second);
        board[x.first][x.second] = word[0];
        if(ans)
            break;
    }
    cout << ans << endl;
    return ans;
}