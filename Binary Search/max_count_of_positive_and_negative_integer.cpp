int maximumCount(vector<int>& nums) {
    if(nums[0] > 0) {
return nums.size();
}

if(nums[nums.size()-1] < 0) {
return nums.size();
}

int l = 0;
int r = nums.size()-1;
int mid;

// Find the last negative number
while(l <= r) {
mid = (l+r)/2;

if(nums[mid] < 0) {
    l = mid + 1;
} else {
    r = mid - 1;
}
}

int negCount = l; // Count of negative numbers

// Find the first positive number
l = 0;
r = nums.size()-1;

while(l <= r) {
mid = (l+r)/2;

if(nums[mid] <= 0) {
    l = mid + 1;
} else {
    r = mid - 1;
}
}

int posCount = nums.size() - l; // Count of positive numbers

return max(negCount, posCount);
}