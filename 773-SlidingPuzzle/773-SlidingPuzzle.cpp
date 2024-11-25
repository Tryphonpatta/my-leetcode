int slidingPuzzle(vector<vector<int>>& board) {
    int steps = -1;
    string start = boardToString(board);
    string req = "123450";

    vector<vector<int>> cur(2, vector<int>(3, 0));

    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    queue<string> q;
    q.push(start);
    int curSteps = 0;

    unordered_set<string> seen;
    seen.insert(start);

    while (!q.empty() && steps == -1) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            string curState = q.front();
            q.pop();

            if (curState == req) {
                steps = curSteps;
                break;
            }

            int r, c;
            for (int j = 0; j < 6; j++) {
                if (j <= 2) {
                    cur[0][j] = curState[j] - '0';
                    if (cur[0][j] == 0) {
                        r = 0;
                        c = j;
                    }
                } else {
                    cur[1][j - 3] = curState[j] - '0';
                    if (cur[1][j - 3] == 0) {
                        r = 1;
                        c = j - 3;
                    }
                }
            }

            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                if (nr >= 0 && nr < 2 && nc >= 0 && nc < 3) {
                    swap(cur[r][c], cur[nr][nc]);
                    string childState = boardToString(cur);
                    swap(cur[r][c], cur[nr][nc]);

                    if (seen.find(childState) == seen.end()) {
                        q.push(childState);
                        seen.insert(childState);
                    }
                }
            }
        }
        curSteps++;
    }

    return steps;
}