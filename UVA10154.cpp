#include<bits/stdc++.h>
using namespace std;

struct turtle
{
    int weight, strength;
};
vector<turtle> Turtle;
int dp[6000];
bool compare(turtle t1, turtle t2){
   return t1.strength < t2.strength;
}
void solve(){
    dp[0] = 0;
    for(int i = 1; i < 6000;i++)
        dp[i] = 1000000;
    int maximum = 0;
    for(int i = 0; i < Turtle.size(); i++){
        for(int j = maximum; j >= 0; j--){
            if(dp[j] + Turtle[i].weight <= Turtle[i].strength && Turtle[i].weight + dp[j] < dp[j+1] ){
                dp[j+1] = dp[j] + Turtle[i].weight;
                maximum = max(maximum, j + 1);
            }
        }
    }
    cout << maximum << "\n";
}
int main()
{   
    turtle t;
    Turtle.clear();
    int count = 0;
    while(cin >> t.weight >> t.strength)
        Turtle.push_back(t);
    sort(Turtle.begin(), Turtle.end(), compare);
    solve();
    return 0;
}