#include<bits/stdc++.h>
using namespace std;

const int maxN = 10005;
int N;
map <string, int> freq;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for( int i = 0 ; i < N ; i++ ){
        string courses = "";
        string course_list[5];
        for( string &s : course_list ) cin >> s;
        sort( course_list, course_list+5 );
        for( const string &s : course_list ) courses += s;
        freq[courses]++; 
    }

    int max_freq = 0, max_freq_count = 0;
    for( const pair <string, int> &p : freq ){
        if( p.second < max_freq ) continue;
        if( p.second > max_freq ){ max_freq = p.second; max_freq_count = 0; }
        max_freq_count += p.second;
    }

    cout << max_freq_count << endl;

}
