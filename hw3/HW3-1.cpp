#include <bits/stdc++.h>
using namespace std;

string input;
string goal;
int in[10000];
vector<vector<int>> Graph;
int visited[10000] = {0};
vector<int> line;
void DFS(int x);


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n, m;
	cin >> n >> m;
	Graph.resize(n + 5);

    vector<vector<int>> Graph_;
	Graph_.resize(n + 5);
    memset(in, 0, sizeof(in));

	cin >> input;


	for (int i = 0; i < n; i ++){
        in[i] = (int)input[i] - 'a';
	}

	int x, y;
	for (int i = 0; i < m; i ++) {
		cin >> x >> y;
		x=x-1;
		y=y-1;
		Graph[x].push_back(y);
		Graph_[y].push_back(x);
	}

	cin >> goal;
	int goal_size = goal.size();
    int go = 0;
    int now = 0;
	for (int i = 0; i < goal_size; i ++){
        go |= 1 << (int)(goal[i] - 'a');
	}


	for (int i = 0; i < n; i ++){
        if (!visited[i]){
            DFS(i);
        }
	}

	memset(visited, 0, sizeof(visited));
	for (int i = n - 1; i >= 0; i --){
        if (!visited[line[i]]) {
			int now = 0;
			int c = line[i];
            visited[c] = 1;
            stack<int> stack_;
            stack_.push(c);
            now |= 1 << in[c];
            while (stack_.size()) {
                int x = stack_.top();
                stack_.pop();
                for (int j = 0; j < Graph_[x].size(); j ++) {
                    if (visited[Graph_[x][j]] == 0) {
                        visited[Graph_[x][j]] = 1;
                        now |= 1 << in[Graph_[x][j]];
                        stack_.push(Graph_[x][j]);
                    }
                }
                /*int stack_size = stack_.size();
                if(stack_size == 0){
                    break;
                }*/
            }
            bool correct = true;
            for (int i = 0; i < 26; i ++){
                if (go & (1 << i)){
                    if (!(now & (1 << i))){
                        correct = false;
                    }
                }
            }

			if (correct) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}



	cout << "No" << endl;
}

void DFS(int x) {
	visited[x] = 1;
	int graph_size = Graph[x].size();
	for (int i = 0; i < graph_size; i ++){
        if (!visited[Graph[x][i]]){
            DFS(Graph[x][i]);
        }
	}

	line.push_back(x);
}
