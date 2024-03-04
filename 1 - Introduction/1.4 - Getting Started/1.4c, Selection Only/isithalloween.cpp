#include<bits/stdc++.h>
using namespace std;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string M; int D;
    cin >> M >> D;

    if( ( M == "OCT" && D == 31 ) || ( M == "DEC" && D == 25 ) ) cout << "yup" << endl;
    else                                                         cout << "nope" << endl;

}
