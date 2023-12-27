#include <iostream>
#include <vector>
#include <cmath>

bool findIndexDiffValueDiffPair(const std::vector<int>& nums, int indexDiff, int valueDiff) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (i != j && abs(i - j) <= indexDiff && abs(nums[i] - nums[j]) <= valueDiff) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::vector<int> nums = {1, 3, 5, 7, 9};
    int indexDiff = 3;
    int valueDiff = 2;

    if (findIndexDiffValueDiffPair(nums, indexDiff, valueDiff)) {
        std::cout << "Pair exists" << std::endl;
    } else {
        std::cout << "Pair does not exist" << std::endl;
    }

    return 0;
}