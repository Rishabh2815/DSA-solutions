#include <iostream>
#include <vector>

using namespace std;

// DFS helper function to perform flood fill
void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor) {
    int rows = image.size();
    int cols = image[0].size();

    // Base Case: Check bounds, match old color, and safeguard against infinite loops
    if (r < 0 || r >= rows || c < 0 || c >= cols || image[r][c] != oldColor) {
        return;
    }

    // Update the color of the current pixel
    image[r][c] = newColor;

    // Recursively check 4-directional neighbors (up, down, left, right)
    dfs(image, r - 1, c, oldColor, newColor); // Up
    dfs(image, r + 1, c, oldColor, newColor); // Down
    dfs(image, r, c - 1, oldColor, newColor); // Left
    dfs(image, r, c + 1, oldColor, newColor); // Right
}

vector<vector<int>> floodFillDFS(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc];
    
    // If the starting pixel already has the new color, no processing is needed
    if (oldColor != newColor) {
        dfs(image, sr, sc, oldColor, newColor);
    }
    return image;
}
