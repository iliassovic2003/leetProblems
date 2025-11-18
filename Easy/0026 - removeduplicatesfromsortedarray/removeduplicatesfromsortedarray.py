class Solution(object):
    def removeDuplicates(self, nums):
        if (not nums or len(nums) == 0) :
            return 0
        
        new_i = 0

        for i in range(0, len(nums)) :
            if (nums[new_i] != nums[i]) :
                new_i += 1
                nums[new_i] = nums[i]

        return (new_i + 1)