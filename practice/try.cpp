#include "../template/template.h"

int main(){
    string st = "101023";
    vector<string> ip(4,"");
    int count = 0;
    for (int i = 0; i<4; i++){
        int c = 0;
        while(c != 3){
            if (st.size()-count <= 3-i){
                break;
            }
            ip[i].push_back(st[count]);
            c++;
            count++;
        }
    }

    show(ip);
    return 0;
}