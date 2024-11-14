#27. Remove Element
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        while(val in nums):
            ind = nums.index(val)
            del nums[ind]

        return len(nums)
        
