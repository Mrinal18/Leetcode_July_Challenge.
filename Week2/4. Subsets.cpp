/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/ 


class Solution {
    
private: 
    
    void dfs(vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, int startindex){
        
        //we need a deep copy of subset because value of subset will keep on changing
        
        
        result.push_back(subset);
        
        for(int i = startindex; i < nums.size(); i++){
            subset.push_back(nums[i]);
        //calling this function again to find all the subset again
            dfs(nums, result, subset, i+1);
            subset.pop_back();
        }
        
            
    }
    
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        
        sort(nums.begin(), nums.end());
        
        int startindex = 0;
        
        dfs(nums, result, subset, 0);
        
        return result;
        
    }
};
