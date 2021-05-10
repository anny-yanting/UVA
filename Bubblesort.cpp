#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        int v[t+5];
        for(int i = 0; i < t; i++)
            cin >> v[i];
        int ans = 0;
        for(int i = 0; i<t; i++) {
            for(int j = i+1; j<t; j++){
              if(v[j] < v[i]) {
                 int temp = v[i];
                 v[i] = v[j];
                 v[j] = temp;
                 ans++;
              }
           }
        }
        printf( "Optimal train swapping takes %d swaps.\n", ans );
    }
    return 0;
}