class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int left=0;
        int right=n-1;
        int i=n-1;
        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                ans[i]=nums[left]*nums[left];
                left++;
            }
            else{
                ans[i]=nums[right]*nums[right];
                right--;
            }
            i--;
        }
        return ans;
        
    }
};