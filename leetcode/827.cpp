#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // (-1, 0), (0, 1), (1, 0), (0, -1)
    const vector<int> dir = {-1, 0, 1, 0, -1};

    bool check(int n, int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    int dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &tag, int val) {
        int ret = 1;
        int n = grid.size();
        tag[i][j] = val;
        for (int k = 0; k < 4; ++k) {
            int x = i + dir[k], y = j + dir[k + 1];
            if (check(n, x, y) && grid[x][y] == 1 && tag[x][y] == 0) {
                ret += dfs(grid, x, y, tag, val); 
            }
        }
        return ret;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int ret = 0;
        // tag[i][j] = k 表示(i,j)属于岛屿k
        vector<vector<int>> tag(n, vector<int>(n, 0));
        unordered_map<int, int> area;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && tag[i][j] == 0) {
                    area[i * n + j + 1] = dfs(grid, i, j, tag, i * n + j + 1);
                    ret = max(ret, area[i * n + j + 1]);    
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> connected;
                    int temp = 1;
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dir[k], y = j + dir[k + 1];
                        if (check(n, x, y) && tag[x][y] != 0 && connected.count(tag[x][y]) == 0) {
                            temp += area[tag[x][y]];
                            connected.emplace(tag[x][y]);
                        }
                    }
                    ret = max(ret, temp);
                }
            }
        }

        return ret;
    }
};