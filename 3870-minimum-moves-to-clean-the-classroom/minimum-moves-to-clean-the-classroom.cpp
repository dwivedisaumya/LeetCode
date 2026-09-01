class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        
        int m = classroom.size();
        int n = classroom[0].size();

        // Starting point and litter positions
        int sr, sc;
        vector<pair<int,int>> litter;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                
                if(classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        // No litter
        if(k == 0)
            return 0;

        // All litter collected
        int fullMask = (1 << k) - 1;

        // row, col, energy, mask
        queue<tuple<int,int,int,int>> q;

        // visited[row][col][energy][mask]
        bool visited[20][20][51][1 << 10] = {};

        q.push({sr, sc, energy, 0});
        visited[sr][sc][energy][0] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                auto [r, c, e, mask] = q.front();
                q.pop();

                // All litter collected
                if(mask == fullMask)
                    return moves;

                // Try 4 directions
                for(int d = 0; d < 4; d++) {

                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    // Outside grid
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    // Obstacle
                    if(classroom[nr][nc] == 'X')
                        continue;

                    // No energy
                    if(e == 0)
                        continue;

                    int ne = e - 1;
                    int nmask = mask;

                    // If new cell has litter
                    for(int i = 0; i < k; i++) {
                        if(litter[i].first == nr &&
                           litter[i].second == nc) {
                            
                            nmask |= (1 << i);
                        }
                    }

                    // Reset area
                    if(classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    // New state
                    if(!visited[nr][nc][ne][nmask]) {

                        visited[nr][nc][ne][nmask] = true;

                        q.push({nr, nc, ne, nmask});
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};