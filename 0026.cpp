//26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int start,end;
        while(i < nums.size())
        {
            start = i,end = 0;
            if((i+1) < nums.size() && nums[i] == nums[i+1])
            {
                
                i++;
                while((i+1) < nums.size() && nums[i] == nums[i+1])
                {i++;}
                end = i;
                nums.erase(nums.begin()+start,nums.begin()+end);
                i = i - (end - start);
            }
            else
            {
                i++;
            }

            
        }

        return nums.size();
    }
-----------
//Another solution
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int i = 0;
	
	while(i+1 < a.size())
	{
		//j = i;
		while(i+1 < a.size() && a[i] == a[i+1])
		{
			a.erase(a.begin()+i);
			//std::cout << a[i] << ' ' << a[i+1] << '\n';			
		}
		i++;
	}
    return a.size();
    }
};
};
---------------
//Another solution
class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        std::set<int> s(a.begin(),a.end());
        std::copy(s.begin(),s.end(),a.begin());
        return s.size();
    }
};
--------------
//Two pointers
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        
          int i = 0;
  for (int j = 1; j < arr.size(); j++) {
    if (arr[i] != arr[j]) {
      i++;
      arr[i] = arr[j];
    }
  }
  return i + 1;

        
    }
};
