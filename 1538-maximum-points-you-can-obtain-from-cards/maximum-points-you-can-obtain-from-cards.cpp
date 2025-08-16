class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0;
        int rsum=0;
        int sum=0;
        int maxs=0;
        for(int i=0;i<k;i++){
            lsum=lsum+cardPoints[i];

        }
        maxs=lsum;
        sum=lsum;
        int rind=n-1;
        for(int j=k-1;j>=0;j--){
            lsum-=cardPoints[j];
            rsum+=cardPoints[rind];
            sum=lsum+rsum;
            maxs=max(maxs,sum);
            rind--;
        }
        return maxs;
    }
};