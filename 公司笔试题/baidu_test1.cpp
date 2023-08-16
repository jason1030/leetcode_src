#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;


int main(){
    int n =0;
    vector<int> vec;
    vector<int> red;
    vector<int> blue;
    long long mod =(2<<10 +7);
    cin>>n;
    for(int i =0;i<n;i++){
        int num;
        scanf("%d", &num);
        vec.push_back(num);
        
    }
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='R') red.push_back(vec[i]);
        else blue.push_back(vec[i]);
    }
    long long result =0;
    for(auto itB=blue.begin();itB!=blue.end();itB++){
        for(auto itR =red.begin();itR!=red.end();itR++){
            result+=(*itB)*(*itR)%mod;
        }
    }
    cout<<result%mod<<endl;
}