class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int max_area = 0;

        while (i < j) {
            int width = j - i;
            int height_ = min(height[i], height[j]);
            max_area = max(max_area, width * height_);

            // Move the pointer pointing to the shorter line
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max_area;
    }
};
