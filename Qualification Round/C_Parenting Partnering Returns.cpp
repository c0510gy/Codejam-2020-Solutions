#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 1000
using namespace std;

struct strt{
    int s, e, i;
    bool operator<(const strt& st)const{
        if(s == st.s)
            return e < st.e;
        return s < st.s;
    }
    bool operator>(const strt& st)const{
        if(s == st.s)
            return e > st.e;
        return s > st.s;
    }
};
int T, N;
bool ans[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        cout << "Case #" << tt << ": ";
        cin >> N;
        vector<strt> schd;
        for(int j = 0; j < N; ++j){
            int s, e; cin >> s >> e;
            schd.push_back({s, e, j});
        }
        sort(schd.begin(), schd.end());
        strt C = {0, 0}, J = {0, 0};
        bool pos = true;
        for(int j = 0; j < N; ++j){
            if(C.e <= schd[j].s){
                C = schd[j];
                ans[schd[j].i] = true;
            }else if(J.e <= schd[j].s){
                J = schd[j];
                ans[schd[j].i] = false;
            }else{
                pos = false;
                break;
            }
        }
        if(!pos){
            cout << "IMPOSSIBLE\n";
            continue;
        }
        for(int j = 0; j < N; ++j){
            if(ans[j])
                cout << "C";
            else
                cout << "J";
        }
        cout << "\n";
    }
    return 0;
}
