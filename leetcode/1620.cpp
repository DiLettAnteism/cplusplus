#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getSquareDistance(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }

public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int x_start = 0, y_start = 0;
        int x_end = INT_MIN, y_end = INT_MIN;
        for (auto &tower : towers) {
            x_end = max(x_end, tower[0]);
            y_end = max(y_end, tower[1]);
        }
        int best_x = 0, best_y = 0;
        int best_q = 0;
        for (int i = x_start; i <= x_end; ++i) {
            for (int j = y_start; j <= y_end; ++j) {
                int q = 0;
                for (auto &tower : towers) {
                    int squareDistance = getSquareDistance(i, j, tower[0], tower[1]);
                    if (squareDistance > radius * radius) {
                        continue;
                    }
                    q += (int)(tower[2] / (1 + sqrt(squareDistance)));
                }
                if (q > best_q) {
                    best_q = q;
                    best_x = i;
                    best_y = j;
                }
            }
        }
        return {best_x, best_y};
    }
};