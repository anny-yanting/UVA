#include<bits/stdc++.h>
using namespace std;
bool vowel[50];
int main(int argc, char const *argv[])
{
    string s;
    while(getline(cin, s)){
        vowel['A'] = vowel['a'] = vowel['E'] = vowel['e'] = vowel['I'] = vowel['i']= vowel['O']= vowel['o']= vowel['U']= vowel['u'] = true;
        for(int i = 0; i < s.size(); i++){
            if(isalpha(s[i])){
                char c = s[i];
                if(vowel[c])
                    cout << c;
                i++;
                for(;i<s.size() && isalpha(s[i]);i++)
                    cout << s[i];
                if(!vowel[c])
                    cout << c;
                
                cout << "ay";
                i--;
            }
            else
                cout << s[i];
        }
        cout << "\n";
    }
    return 0;
}