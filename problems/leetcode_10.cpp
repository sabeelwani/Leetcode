#include "../template/template.h"
bool isMatch(){
    /*"aaa"
    "a.a"
    "aaa"
    "aaaa"
    "a"
    "ab*a"
    "bbbba"
    ".*a*a"
    "aasdfasdfasdfasdfas"
    "aasdf.*asdf.*asdf.*asdf.*s"
     */
    string s = "aasdfasdfasdfasdfas", b = "aasdf.*asdf.*asdf.*asdf.*s";
    int must = 0;
    string p;
    for(int i = 0; i < b.size(); i++){
        if(b[i] == '*')
            continue;
        if(b[i] >= 'a' and b[i] <= 'z' or b[i] == '.'){
            if(i < b.size()-1 and b[i+1] == '*'){
                p.push_back((b[i]-('a'-'A')));
            }else{
                p.push_back(b[i]);
                must += 1;
            }
        }
    }
    char currChar;
    int sSize = s.size(), pSize = p.size();
    int i,j = 0;
    string res;
    for (i = 0; i < pSize; i++){
        currChar = p[i];
        if (j> sSize-1){
            if((currChar >= 97 and currChar <= 122) or currChar == '.')
                res.push_back(currChar);
            break;
        }
        if(currChar >= 97 and currChar <= 122){
            if(s[j] == currChar){
                res.push_back(s[j]);
                if(i<pSize-1)
                    j++;
                must--;
            }else{
                return false;
            }
        }else{
            if(currChar == '.'){
                res.push_back(s[j]);
                j++;
                must--;
            }else{
                currChar = (char) (p[i]+('a'-'A'));
                if(currChar == '.'){
                    if(must == 0){
                        while(j!=sSize){
                            res.push_back(s[j]);
                            j++;
                        }
                    }else{
                        while(must<=sSize-1-j and j!=sSize) {
                            res.push_back(s[j]);
                            j++;
                        }
                    }
                }else{
                    if(must == 0){
                        while(j!=sSize and s[j] == currChar){
                            res.push_back(s[j]);
                            j++;
                        }
                    }else{
                        while(must<=sSize-1-j and j!=sSize  and s[j] == currChar){
                            res.push_back(s[j]);
                            j++;
                        }
                    };
                }
            }

            if(i>=pSize-1)
                j--;
        }
    }
    cout << i << nl;
    cout << res << nl;
    return res == s;
}
int main(){
    cout << isMatch();
    return 0;
}
