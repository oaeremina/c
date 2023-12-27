#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j] += 1;
            }
            else {
                heights[j] = 0;
            }
        }
        stack<int> s;
        for (int j = 0; j < cols; j++) {
            while (!s.empty() && heights[j] < heights[s.top()]) {
                int top = s.top();
                s.pop();
                int width = s.empty() ? j : j - s.top() - 1;
                maxArea = max(maxArea, heights[top] * width);
            }
            s.push(j);
        }
        while (!s.empty()) {
            int top = s.top();
            s.pop();
            int width = s.empty() ? cols : cols - s.top() - 1;
            maxArea = max(maxArea, heights[top] * width);
        }
    }
    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    cout << maximalRectangle(matrix);
    return 0;
}