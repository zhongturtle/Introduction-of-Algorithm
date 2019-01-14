#include <bits/stdc++.h>
using namespace std;

const int N = 8;
const int M = N*(N-1)/2;
const int LEN = (1<<M);

bitset<LEN> B;

void readB(){
    string s;
    cin >> s;

    int i=LEN-1;
    for (char c:s){
        int x;
        if ( 0<=c && c<='9' ) x = c-'0';
        else x = c-'A'+10;
        for (int j=0; j<4; j++, i--){
            B[i] = (x>>3)&1;
            x<<=1;
        }
    }
}

bool HamC(const vector< pair<int,int> > &edges){
    // input: edge set of an 8 vertex simple graph G
    // output: return true if G contain a hammington path, otherwise false
    // time complexity: O(m) where m = number of edge

    int G = 0;
    for ( auto e : edges ){
        int u = e.first;
        int v = e.second;
        if (u>v) swap(u,v);
        int idx = v*(v-1)/2+u;;
        if (u==v) idx = -1;
        G |= (1<<idx);
    }
    return B[G];
}

void test(){
    vector< pair<int,int> > edges;
    for (int i=1; i<N; i++) edges.push_back( {i-1,i} );
    cout << HamC(edges) << endl; // 0

    edges.push_back( {N-1,0} );
    cout << HamC(edges) << endl; // 1
}

// Complete the solve function below.
void solve(){
    int n, m; cin >> n >> m;
    bool valid = false;
    vector<pair<int,int>> cont;
    for (int i=0; i<m; i++){
        int u, v; cin >> u >> v; // edge (u,v)
        cont.push_back({u,v})
    }
	cont.push_back( {7, 0} );
	cont.push_back( {7, 1} );
	for (int i = 1; i <= n; i ++) {
		for (int j = i; j < n - 1; j ++) {
			cont[m + 1].second = i - 1;
			cont[m].second = j;
			if (HamC(cont)) {
				valid = true;
				break;
			}
		}
		if (valid){
            break;
        }
	}
	if (valid) {
        cout << "Yes";
    }
	else{
        cout << "No";
    }
    cout << endl;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);

    readB();

    int T; cin >> T;
    while (T--) solve();
}
