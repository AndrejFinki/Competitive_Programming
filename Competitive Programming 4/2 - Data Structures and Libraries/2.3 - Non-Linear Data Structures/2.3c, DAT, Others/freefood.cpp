#include<bits/stdc++.h>
using namespace std;

const int maxD = 400;
int N;
bool hasFood[maxD] = {};

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int L, R;
    for( int i = 0 ; i < N ; i++ ){
        cin >> L >> R;
        for( int j = L ; j <= R ; j++ ) hasFood[j] = true;
    }

    int rv = 0;
    for( int i = 1 ; i <= 365 ; i++ ) rv += hasFood[i];

    cout << rv << endl;

}
