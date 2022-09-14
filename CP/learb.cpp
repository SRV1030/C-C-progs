class Solution {
public:
    vector<int>bitset(int n){
        vector<int>freq(50);
        for(int i=0;i<32&&n;i++){
            freq[i]=n%2;
            n=n/2;
        }
        return freq;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int i=0,j=0,ans=1;
        vector<int>freq(50);
        while(j<nums.size()){
            vector<int>cur=bitset(nums[j]);
            while(true){
                int flag=0;
                for(int k=0;k<32;k++){
                    if(cur[k]&&freq[k]){
                        flag=1;
                        break;
                    }
                }
                if(flag==1){                    
                    vector<int>curr=bitset(nums[i++]);
                    for(int k=0;k<32;k++){
                        freq[k]-=curr[k];
                    }
                }else{
                    break;
                }
            }
            for(int i=0;i<32;i++){
                freq[i]+=cur[i];
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};