class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int val, int newColor) {
        // Base case: Check if the current position is out of bounds, already has the new color,
        // or does not match the original color (val)
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] == newColor || image[i][j] != val) {
            return;
        }

        // Update the current pixel with the new color
        image[i][j] = newColor;

        // Recursively call DFS for all four neighboring pixels (up, down, left, right)
        dfs(image, i - 1, j, val, newColor); // Move up
        dfs(image, i + 1, j, val, newColor); // Move down
        dfs(image, i, j - 1, val, newColor); // Move left
        dfs(image, i, j + 1, val, newColor); // Move right
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Get the color of the starting pixel
        int val = image[sr][sc];
        
        // If the starting pixel already has the new color, we don't need to do anything
        if (val != newColor) {
            // Start the DFS from the starting pixel
            dfs(image, sr, sc, val, newColor);
        }
        
        // Return the updated image
        return image;
    }
};
