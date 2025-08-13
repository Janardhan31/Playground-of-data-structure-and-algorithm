class NumArray {
private:
    int len = 0;
    vector < int > seg;
public:
    void build(vector<int>&nums, int ind, int low, int high){
        if(low == high){
            seg[ind] = nums[low];
            return;
        }
        int mid = (low + high)/2;
        build(nums, 2*ind+1, low, mid);
        build(nums, 2*ind+2, mid+1, high);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    NumArray(vector<int>& nums) {
        len = nums.size();
        seg.resize(4 * len, 0);
        build(nums,0,0,len-1);
    }

    int queryUtility(int ind, int low, int high, int l, int r){
        if(low >= l && high <= r)
            return seg[ind];
        if(high < l || low > r)
            return 0;
        int mid = (low + high)/2;
        int left =  queryUtility(2*ind+1,   low, mid, l, r);
        int right = queryUtility(2*ind+2, mid+1, high, l, r);
        return left + right;
    }
    
    int sumRange(int left, int right) {
        return queryUtility(0, 0, len-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */