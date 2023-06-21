#include <iostream>
#include <vector>

//The Dutch National Flag algorithm, also known as the 3-way partitioning algorithm


/*
problem statement -
 rearrange a vector of non-negative integers such that all numbers of the form
 3m preceds all numbers of the form 3m+1 and he latter is followed by all numbers of the form 3m+2
 implement an in place algorithm without using extra arrays . 
 in the output print only number of numbers of the form 3m,3m+1 and 3m+2   
*/

void dutchFlagAlgorithm(std::vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (nums[mid] % 3 == 0) {
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] % 3 == 1) {
            mid++;
        } else {
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    std::vector<int> nums = {1, 3, 2, 4, 6, 5, 9, 8, 7, 10, 12, 11};
    
    std::cout << "Original Vector: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    dutchFlagAlgorithm(nums);

    std::cout << "Rearranged Vector: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
