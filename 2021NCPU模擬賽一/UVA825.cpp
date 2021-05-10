#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--){
        int w, n;
        cin >> w >> n;
        cin.ignore();
        int map[100][100] = {0};
        int dp[100][100] = {0};
        string str;
        for(int i = 1; i <= w; i++){
            getline(cin, str);
            stringstream ss(str);
            int j;
            ss >> j;
            while(ss >> j){
                map[i][j] = -1;
            }
        }
        dp[1][1] = 1;
        for(int i = 1; i <= w; i++){
            for(int j = 1; j <= n; j++){
                if(map[i][j] == -1)
                    continue;
                if(i > 1)
                    dp[i][j] += dp[i-1][j];
                if(j > 1)
                    dp[i][j] += dp[i][j-1];
            }
        }
        cout << dp[w][n] << "\n";
        if(t)
            cout << "\n";
    }
    return 0;
}