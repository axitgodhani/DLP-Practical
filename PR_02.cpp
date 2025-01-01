#include<bits/stdc++.h>
using namespace std;

unordered_map<int, bool> acc;
unordered_map<string, int> trans;

bool valid = false;

void chk(string &s, int st, int i){
    if(i == s.length()){
        if(acc[st]){
            valid = true;
        }
        return;
    }

    string key = to_string(st) + "_" + s[i];
    int nxt = trans[key];
    chk(s, nxt, i+1);
}

int main(){
    int ipCt, stCt, accCt, init;
    cout << "Num Inputs: ";
    cin >> ipCt;

    cout << "Inputs: ";
    vector<char> ips(ipCt);
    for(int i = 0; i < ipCt; i++){
        cin >> ips[i];
    }

    cout << "Num States: ";
    cin >> stCt;

    cout << "Init State: ";
    cin >> init;

    cout << "Num Accepting: ";
    cin >> accCt;

    cout << "Accept States: ";
    for(int i = 0; i < accCt; i++){
        int st;
        cin >> st;
        acc[st] = true;
    }

    cout << "Transitions\n";
    for(int i = 1; i <= stCt; i++){
        for(int j = 0; j < ipCt; j++){
            string key = to_string(i) + '_' + ips[j];
            int nxt;
            cout << i << " -> " << ips[j] << " = ";
            cin >> nxt;
            trans[key] = nxt;
        }
    }

    string s;
    cout << "Input: ";
    cin >> s;

    chk(s, init, 0);

    if(valid){
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }
}