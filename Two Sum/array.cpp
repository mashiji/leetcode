题目：
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
    
    
    
    
1. 222ms 暴力搜索   复杂度O(n2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int>*p=new vector<int>;
        for(int i=0;i<nums.size()-1;i++)
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    p->push_back(i);
                    p->push_back(j);
                    break;
                }
            }
        return *p;
    }
};
2. 9ms
/*
    排序后从左右端点开始扫描
    复杂度O(nlogn)
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        int n = numbers.size();
        int *a = new int[n];
        for(int i = 0;i < n;i++)    a[i] = numbers[i];
        sort(numbers.begin(),numbers.end());
        int lhs = 0,rhs = n-1;
        while(rhs > lhs){
            if(numbers[lhs] + numbers[rhs] > target)    rhs--;
            else if(numbers[lhs] + numbers[rhs] < target)   lhs++;
            else{
                int id1,id2;
                for(int i = 0;i < n;i++){
                    if(a[i] == numbers[lhs]){
                        id1 = i + 1;
                        break;
                    }
                }
                for(int i = n - 1;i >= 0;i--){
                    if(a[i] == numbers[rhs]){
                        id2 = i + 1;
                        break;
                    }
                }
                res.push_back(min(id1,id2));
                res.push_back(max(id1,id2));
                return res;
            }
        }
    }
};

3. 9ms hash 用一个哈希表，存储每个数对应的下标，复杂度O(n)
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> mapping;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      mapping[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
      const int gap = target - nums[i];
      if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
        result.push_back(i + 1);
        result.push_back(mapping[gap] + 1);
        break;
     }
    }
  return result;
  }
};
