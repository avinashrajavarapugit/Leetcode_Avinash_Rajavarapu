class Solution {
public:
    bool inBounds(const std::vector<std::vector<int>>& grid, int row, int col){
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        std::queue<std::pair<int, int>> q;

        for (int row = 0; row < grid.size(); row++){
            for (int col = 0; col < grid[0].size(); col++){

                if (grid[row][col] == 0)
                    q.push({row, col});

            }
        }

        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()){

            std::pair<int, int> curr = q.front();
            q.pop();

            for (const std::pair<int, int>& direction : directions){

                std::pair<int, int> newCell = {curr.first + direction.first, curr.second + direction.second};

                if (inBounds(grid, newCell.first, newCell.second) && grid[newCell.first][newCell.second] == 2147483647){
                    grid[newCell.first][newCell.second] = grid[curr.first][curr.second] + 1;

                    q.push(newCell);
                }

            }

        }

    }
};
