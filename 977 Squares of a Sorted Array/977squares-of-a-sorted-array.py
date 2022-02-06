class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        new_sq=[]
        for i in nums:
            i=i*i
            new_sq.append(i)
        return sorted(new_sq)