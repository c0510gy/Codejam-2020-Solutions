#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>
#define MAXN 50
#define MAXL 10000
using namespace std;

typedef long long int lli;

int T, N;
string P[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        cout << "Case #" << tt << ": ";
        cin >> N;
        for(int j = 0; j < N; ++j)
            cin >> P[j];
        string ans = "";
        string prefix = "", sufix = "", middle = "";
        bool pos = true;
        for(int j = 0; j < N; ++j){
            string p = "", s = "";
            for(int i = 0; i < P[j].size(); ++i){
                if(P[j][i] == '*')
                    break;
                p += P[j][i];
            }
            for(int i = P[j].size() - 1; i >= 0; --i){
                if(P[j][i] == '*')
                    break;
                s += P[j][i];
            }
            int cnt_tot = 0;
            for(int i = 0; i < P[j].size(); ++i)
                if(P[j][i] == '*') ++cnt_tot;
            for(int i = 0, cnt = 0; i < P[j].size(); ++i){
                if(P[j][i] == '*'){
                    ++cnt;
                    continue;
                }
                if(cnt > 0 && cnt < cnt_tot){
                    middle += P[j][i];
                }
            }
            if(p != ""){
                int i = 0;
                for(; i < prefix.size() && i < p.size(); ++i){
                    if(prefix[i] != p[i]){
                        pos = false;
                        break;
                    }
                }
                if(!pos)
                    break;
                for(; i < p.size(); ++i)
                    prefix += p[i];
            }
            if(s != ""){
                int i = 0;
                for(; i < sufix.size() && i < s.size(); ++i){
                    if(sufix[i] != s[i]){
                        pos = false;
                        break;
                    }
                }
                if(!pos)
                    break;
                for(; i < s.size(); ++i)
                    sufix += s[i];
            }
        }
        if(!pos){
            cout << "*\n";
        }else{
            string rsufix = "";
            for(int j = sufix.size() - 1; j >= 0; --j){
                rsufix += sufix[j];
            }
            cout << prefix << middle << rsufix << "\n";
        }
    }
    return 0;
}
