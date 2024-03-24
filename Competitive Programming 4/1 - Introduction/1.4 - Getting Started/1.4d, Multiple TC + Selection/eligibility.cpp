#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define endl '\n'

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while( t-- ){

        string NAME, STUDY, BIRTH; int COURSES;
        cin >> NAME >> STUDY >> BIRTH >> COURSES;

        if( stoi( STUDY.substr( 0, 4 ) ) >= 2010 ){ cout << NAME << " eligible" << endl; continue; }
        if( stoi( BIRTH.substr( 0, 4 ) ) >= 1991 ){ cout << NAME << " eligible" << endl; continue; }
        if( COURSES > 40 ){ cout << NAME << " ineligible" << endl; continue; }
        cout << NAME << " coach petitions" << endl;

    }

}
