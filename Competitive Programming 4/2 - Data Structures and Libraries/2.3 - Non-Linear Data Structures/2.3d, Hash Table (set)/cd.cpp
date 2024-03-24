#include<bits/stdc++.h>
using namespace std;

int N, M;
set <int> numSet;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    while( cin >> N >> M && (N||M) ){

        numSet.clear();

        int x, rv = 0;
        for( int i = 0 ; i < N ; i++ ){
            cin >> x; numSet.insert(x);
        }
        for( int i = 0 ; i < M ; i++ ){
            cin >> x; rv += numSet.count(x);
        }

        cout << rv << endl;

    }

}
