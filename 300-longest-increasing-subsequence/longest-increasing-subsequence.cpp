class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),m=0;
        vector<int>v(n,1);
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    v[i]=max(v[i],v[j]+1);
                    // m=max(m,nums[j]+1);
                }
            }
        }
        for(int i=0;i<n;i++) m=max(m,v[i]);
        return m;
        
    }
};