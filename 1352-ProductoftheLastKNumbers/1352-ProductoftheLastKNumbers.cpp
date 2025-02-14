    public int GetProduct(int k) {
    int result = 1;
    int n = nums.Count;
    for(int i=n-1;i>n-k-1;i--)
    {
        result*=nums[i];
    }
    return result;
}