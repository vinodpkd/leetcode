class Solution:
    def twoSum(self, arr: List[int], target: int) -> List[int]:
        for i in range(len(arr)):
            if target-arr[i] in arr[i+1:]:
                return i,i+1+arr[i+1:].index(target-arr[i])
