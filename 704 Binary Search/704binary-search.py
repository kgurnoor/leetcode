class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        a= -1
        for i in nums:
            if i==target:
                return nums.index(i)
        return a    