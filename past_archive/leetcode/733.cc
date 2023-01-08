// 733. Flood Fill
// https://leetcode.com/problems/flood-fill/

class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    const int M = image.size();
    const int N = image[0].size();
    const int tc = image[sr][sc];

    int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> check(M, vector<bool>(N, false));

    queue<pair<int, int>> que;
    que.emplace(sr, sc);

    check[sr][sc] = true;
    while (!que.empty()) {
      int r = que.front().first;
      int c = que.front().second;
      que.pop();

      image[r][c] = newColor;

      for (int i = 0; i < 4; ++i) {
        int nr = r + d[i][0];
        int nc = c + d[i][1];
        if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
        if (image[nr][nc] != tc) continue;
        if (check[nr][nc]) continue;

        check[nr][nc] = true;
        que.emplace(nr, nc);
      }
    }
    return image;
  }
};