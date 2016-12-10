//
//  main.cpp
//  IslandPerimeter
//
//  Created by Gargium on 12/10/16.
//  Copyright © 2016 Rakshit Garg. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    //add 4-n to the perimeter for each 1 we see, where n is the number of 1's surrounding that 1
    int perimeter = 0;    ;
    for (int i = 0; i < grid.size(); i++) {
        size_t cols = grid[0].size();
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                int addToPerim = 4;
                if (j-1 >= 0 && grid[i][j-1] == 1)
                    addToPerim--;
                if (j+1 != grid[0].size() && grid[i][j+1] == 1)
                    addToPerim--;
                if (i-1 >= 0 && grid[i-1][j] == 1)
                    addToPerim--;
                if (i+1 != grid.size() && grid[i+1][j] == 1)
                    addToPerim--;
                perimeter += addToPerim;
            }
        }
    }
    
    return perimeter;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> grid;
    grid.push_back({0,1});
    std::cout << islandPerimeter(grid);
    
    return 0;
}
