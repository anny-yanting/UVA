#include<bits/stdc++.h>
using namespace std;
int prime[4793] = {0};
bool mark[46400];
void set_prime(){
    int sq = floor(sqrt(46340.0));
    mark[1] = true;
    for (int i=2; i<=sq; i++){
        if (!mark[i]){
            for (int j=i*i;j<=46340;j+=i){
                    mark[j] = true;
            }
        }
    }
    int n = 0;
    for(int i = 2; i <= 46340;i++){
        if(!mark[i]){
            prime[n] = i;
            n++;             
        }
    }
}
int main(void)
{
    set_prime();
    string s;
    stringstream ss;
    while(getline(cin, s)){
        if(s == "0")
            break;
        int base[1000], pow[1000];
        memset(base, 0, sizeof(base));
        memset(pow, 0, sizeof(pow));
        int num = 1;
        int a, b;
        ss.str(s);
        while(ss >> a >> b){
            for(int i = 0; i < b; i++)
                num *= a;
        }
        ss.clear();
        int target = num - 1;
        // int tmp = target;
        int j = 0, k= 0;

        while(prime[j] <= target){
            if((target % prime[j] == 0)){
                base[k] = prime[j];
                pow[k]++;
                target /= prime[j];
            }
            else{
                j++;
                if(pow[k] != 0)
                    k++;
            }
        }
        for(int i = k; i >= 0; i--){
            if(i == k)
                cout << base[i] << " " << pow[i];
            else 
                cout << " "<<base[i] <<" " <<pow[i];
        }
        cout << "\n";
    }

    return 0;
} 