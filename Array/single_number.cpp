int singleNumber(vector<int>& nums) {
    int xora = 0;

    for(auto k :nums) {
        xora = xora^k;
    }
    return xora;
}