class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        unordered_map<long long,unordered_map<long long,long long>>mp;
        unordered_set<long long>s(nums.begin(),nums.end());
        int ans=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                long long diff=(long long)nums[i]-(long long)nums[j];
                long long temp=0;
                if(mp[j][diff]){
                    temp=mp[j][diff];
                }
                ans+=temp;
                if(s.count(nums[i]+diff)) mp[i][diff]+=temp+1;
            }
        }
        return ans;
    }
};