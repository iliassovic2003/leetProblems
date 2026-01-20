class Solution(object):
    def sortColors(self, nums):
        index0 = 0
        lens = len(nums)
        index2 = lens - 1
        temp = 0

        i = 0
        while (i < lens and i <= index2) :
            if (nums[i] == 0) :
                if (index0 < i) :
                    temp = nums[index0]
                    nums[index0] = 0
                    nums[i] = temp
                index0 += 1
                i += 1
            elif (nums[i] == 2) :
                temp = nums[index2]
                nums[index2] = 2
                nums[i] = temp
                index2 -= 1
            else :
                i += 1