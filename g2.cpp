class Solution {
public:
    void recursive_fill (vector<vector<int>>& image, int sr, int sc, int color, int start_color) {
        if (color == start_color) return;
        if (sr < 0 || sr > image.size() - 1) return;
        if (sc < 0 || sc > image[0].size() - 1) return;
        if (image[sr][sc] != start_color) return;
        
        image[sr][sc] = color;     
        // One position up
        recursive_fill(image, sr - 1, sc, color, start_color);
        // One position down
        recursive_fill(image, sr + 1, sc, color, start_color);
        // One position left
        recursive_fill(image, sr, sc - 1, color, start_color);
        // One position right
        recursive_fill(image, sr, sc + 1, color, start_color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        recursive_fill(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};






















class Solution {
public:
int dc[5] = {-1, 0, 1, 0, -1};
struct cell {
    int r, c;
    cell(int x, int y) : r(x), c(y){};
};
    bool isValid(int r, int c,int m,int n) {
    return r >= 0 && c >= 0 && r < m && c < n;
    }    
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int color) {
        int oldCol = img[sr][sc];
        if(oldCol!=color){
            int m = img.size();
            int n = img[0].size();
            queue<cell> q;
            q.push({sr, sc});
            img[sr][sc] = color;
            while(!q.empty()){
                cell u = q.front();
                q.pop();
                for (int i = 0; i < 4;++i){
                    int r = u.r + dc[i];
                    int c = u.c + dc[i+1];
                    if(isValid(r,c,m,n)&&img[r][c]==oldCol){
                        q.push({r, c});
                        img[r][c]=color;
                    }   
                }
            }
        }
        return img;
    }   
};



















An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n







