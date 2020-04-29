#include <iostream>
#define MAXB 100
using namespace std;

int T, B;
bool ans[MAXB];
int query(int idx){
    int res;
    cout << idx << endl;
    fflush(stdout);
    cin >> res;
    return res;
}
int recl(int j){
    int c1 = -1, c2 = -1, ret = 0;
    for(int i = 0; i < j; ++i){
        if(ans[i] == ans[B - i - 1]){
            if(c1 == -1){
                int r = query(i + 1); ret++;
                if(r == ans[i])
                    c1 = 1;
                else
                    c1 = 0;
            }
            if(!c1){
                ans[i] = !ans[i];
                ans[B - i - 1] = !ans[B - i - 1];
            }
        }else{
            if(c2 == -1){
                int r = query(i + 1); ret++;
                if(r == ans[i])
                    c2 = 1;
                else
                    c2 = 0;
            }
            if(!c2){
                ans[i] = !ans[i];
                ans[B - i - 1] = !ans[B - i - 1];
            }
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T >> B;
    for(int tt = 1; tt <= T; ++tt){
        int cnt = 0;
        for(int j = 0, cnt = 0; j < B / 2; ++j){
            ans[j] = query(j + 1); cnt++;
            if(cnt % 10 == 0){
                ans[j] = query(j + 1); cnt++;
                cnt += recl(j);
            }else if(cnt % 10 == 1)
                cnt += recl(j);
            ans[B - j - 1] = query(B - j); cnt++;
            if(cnt % 10 == 1)
                cnt += recl(j);
        }
        for(int j = 0; j < B; ++j)
            cout << ans[j];
        cout << endl;
        fflush(stdout);
        char res; cin >> res;
        if(res == 'N')
            break;
    }
    return 0;
}
