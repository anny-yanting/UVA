#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    while(cin >> str){
        if(str == "0")
            break;
        int sumo = 0;
        int sume = 0;
        for(int i = 0; i < str.size(); i++){
            if((i % 2) != 0)
                sumo += (str[i] - '0');
            else
                sume += (str[i] - '0');
        }
        if((abs(sumo - sume) % 11 )== 0)
            cout << str << " is a multiple of 11." << "\n";
        else
            cout << str << " is not a multiple of 11." << "\n";
    }
}
