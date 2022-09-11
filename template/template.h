#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define us unsigned short
#define sq(x) x*x
#define eb(x) emplace_back(x)
#define push(x) push_back(x)
#define pop() pop_back()
#define pushf(x) push_front(x)
#define popf() pop_front()
#define b begin()
#define e end()
#define loop(x,start,y,z,i) for(int x = start; z == '>' ? x>y:x<y; x += i)
#define it(x,y) for(auto x:y)
#define nl "\n"
using namespace std;
template <typename T>
void show(T &iter){
    std::cout << nl;
    for_each(iter.b,iter.e,[](auto &x){std::cout << x << " ";});
    std::cout << nl;
}