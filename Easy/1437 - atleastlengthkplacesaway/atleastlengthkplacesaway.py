class Solution:
    def kLengthApart(self, nums: list[int], k: int) -> bool:
        j = k

        for i in range(len(nums)) :
            if (nums[i] == 1) :
                if (j < k) :
                    return False
                j = 0
            else :
                j += 1
        return True