class Solution {
public:
    int maxprof(int i,int n,int last,vector<pair<pair<int,int>,int>>&v,vector<int>&dp,vector<int>&st){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=0,notake=0;
        // if(last==-1 || v[last].first.second<=v[i].first.first){
        int lower=lower_bound(st.begin()+i,st.end(),v[i].first.second)-st.begin();
        take=v[i].second+maxprof(lower,n,lower,v,dp,st);
        // }
        notake=maxprof(i+1,n,lower+1,v,dp,st);
        return dp[i]=max(take,notake);
    }
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& profit) {
        vector<pair<pair<int,int>,int>>v;
        int n=profit.size();
        vector<int>dp(n+1,-1);
        for(int i=0;i<n;i++){
            v.push_back({{s[i],e[i]},profit[i]});
        }
        sort(v.begin(),v.end());
        // vector<int>start;
        int k=0;
        for(auto i:v){
            s[k++]=i.first.first;
        }
        return maxprof(0,n,-1,v,dp,s);
    }
};