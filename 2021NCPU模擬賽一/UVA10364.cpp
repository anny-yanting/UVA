#include<bits/stdc++.h>
using namespace std;
vector<int> v;
bool vis[100];
void init(){
    v.clear();
    for(int i = 0; i < 100; i++)
        vis[i] = false;
}
bool cmp(int a, int b){
    return a > b;
}
bool dfs(int now_position, int total_length, int num_edge, int each_edge_length, int flag){
    if(total_length == each_edge_length){
        now_position = total_length = 0;
        flag++;
        if(flag == 3)
            return true;
    }
    for(int i = now_position; i < num_edge;i++){
        if(!vis[i]){
            if(total_length + v[i] <= each_edge_length){
                vis[i] = true;
                if(dfs(i + 1, total_length + v[i], num_edge, each_edge_length, flag))
                    return true;
                vis[i] = false;
            }
            if(total_length + v[i] == each_edge_length)
                vis[i] = false;
        }
    }
    return false;
}
int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    while(n--){
        init();
        int flag = 0;
        int sum = 0;
        int t;
        cin >> t;
        for(int i= 0; i < t; i++){
            int a;
            cin >> a;
            v.push_back(a);
            sum += a;
        }
        sort(v.begin(), v.end(), cmp);
        if((sum%4)!= 0){
            cout << "no" << "\n";
            continue;
        }
        else{
            int x = dfs(0, 0, t, sum / 4, flag);
            if(x)
                cout << "yes" << "\n";
            else
                cout << "no" << "\n";
        }
    }
    return 0;
}