class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        for i in nums:
            if i==target:
                return nums.index(i)
            else :
                nums.append(target)
                nums.sort()
                return nums.index(target)
                
        