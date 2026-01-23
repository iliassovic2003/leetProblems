class Solution:
    def search(self, nums: list[int], target: int) -> int:
        start = 0;   
        end = len(nums)

        while (start < end) :
            median = math.floor(start + (end - start) / 2)
            if (target < nums[median]) :
                end = median
            elif (target > nums[median]) :
                start = median + 1
            else :
                return median

        return -1