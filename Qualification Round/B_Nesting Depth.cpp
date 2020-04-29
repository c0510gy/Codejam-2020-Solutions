#include <iostream>
#include <string>
using namespace std;

int T;
string S, ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for(int tt = 1; tt <= T; ++tt){
        cout << "Case #" << tt << ": ";
        cin >> S;
        ans = "";
        int depth = 0;
        for(int j = 0; j < S.size(); ++j){
            int n = S[j] - '0';
            while(n > depth){
                ans += "(";
                depth++;
            }
            while(n < depth){
                ans += ")";
                depth--;
            }
            ans += S[j];
        }
        for(; depth; --depth)
            ans += ")";
        cout << ans << "\n";
    }
    return 0;
}
