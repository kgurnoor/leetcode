# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        """
        : for every element i in range(n), if isBadVersion returns true ,                return  i 
        start with a number , go upto 'n', check if isBadVersion is true , then return that number
        
        : 
        """
        
        if n<2:
            return n
        start=1
        end=n
        while(start<=end):
            mid=(start+end)/2
            if isBadVersion(mid) and not isBadVersion(mid-1):
                return mid
            elif isBadVersion(mid-1):
                end = (mid-1)
            else:
                start=mid+1
        
            