/*
problem: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

SOLUTION:

Algo 1: Using Sorting
Another very simple idea is as follows. We can sort a copy of the given array numsnumsnums, say given by nums_sortednums\_sortednums_sorted. 
Then, if we compare the elements of numsnumsnums and nums_sortednums\_sortednums_sorted, we can determine the leftmost and rightmost elements which mismatch. 
The subarray lying between them is, then, the required shorted unsorted subarray.

Algo 2: Hill-Valley approach using stack
The idea behind this approach is also based on selective sorting. We need to determine the correct position of the minimum and the maximum element in the unsorted subarray to determine the boundaries of the required unsorted subarray.
To do so, in this implementation, we make use of a stackstackstack. We traverse over the numsnumsnums array starting from the beginning. As we go on facing elements in ascending order(a rising slope), we keep on pushing the elements' indices over the stackstackstack. This is done because such elements are in the correct sorted order(as it seems till now). As soon as we encounter a falling slope, i.e. an element nums[j]nums[j]nums[j] which is smaller than the element on the top of the stackstackstack, we know that nums[j]nums[j]nums[j] isn't at its correct position.
In order to determine the correct position of nums[j]nums[j]nums[j], we keep on popping the elemnents from the top of the stackstackstack until we reach the stage where the element(corresponding to the index) on the top of the stackstackstack is lesser than nums[j]nums[j]nums[j]. Let's say the popping stops when the index on stackstackstack's top is kkk. Now, nums[j]nums[j]nums[j] has found its correct position. It needs to lie at an index k+1k + 1k+1.
We follow the same process while traversing over the whole array, and determine the value of minimum such kkk. This marks the left boundary of the unsorted subarray.
Similarly, to find the right boundary of the unsorted subarray, we traverse over the numsnumsnums array backwards. This time we keep on pushing the elements if we see a falling slope. As soon as we find a rising slope, we trace forwards now and determine the larger element's correct position. We do so for the complete array and thus, determine the right boundary.
We can look at the figure below for reference. We can observe that the slopes directly indicate the relative ordering. We can also observe that the point bbb needs to lie just after index 0 marking the left boundary and the point aaa needs to lie just before index 7 marking the right boundary of the unsorted subarray.

Algo 2: Hill-Valley approach using two-pointer
Create a start and end variable to store the indexes of starting and ending positions of the Shortest Unsorted Continuous Subarray respectively.

int n=nums.size();
int start=-1,end=n;
PASS 1 : Iterate from the end, and check weather the element at index i is the current minimum element (curr_min) or not. If not then i is the starting index (start) as nums[i] > nums[i-1] > nums[i-2] > ... (array needs to be in ascending order)

int curr_min=MAX_VAL;
for(int i = n - 1; i>=0; i--) {
	if(curr_min > nums[i]) curr_min = nums[i];
	if(nums[i] > curr_min) start = i;
}
PASS 2 : Iterate from the start, and check weather the element at index i is the current maximum element (curr_max) or not. If not then i is the ending index (end) as nums[i] < nums[i+1] < nums[i+2] < ... (array needs to be in ascending order)

int cur_max = -MAX_VAL;
for(int i=0; i<n; i++) {
	if(cur_max < nums[i]) cur_max = nums[i];
	if(nums[i] < cur_max) end = i;
}
In the end, check for a valid start index :

If not found then return 0.
If found then return end-start+1, that is the length of range in between [start, end].
if(start==-1){ 
	return 0;
}
return end-start+1;
*/

// Time : O(NlogN)
// Space: O(N)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        auto sa=a;
        sort(sa.begin(),sa.end());
        int l=0,r=a.size()-1;
        while(l<a.size() && a[l]==sa[l]) l++;
        while(r>l && a[r]==sa[r]) r--;
        return r-l+1;
    }
};

// Time : O(N)
// Space: O(N)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        stack<int> stk;
        int l=1e6,r=0;
        for(int i=0;i<a.size();i++) {
            while(!stk.empty() && a[stk.top()]>a[i]) {
                l=min(l,stk.top());
                stk.pop();
            }
            stk.push(i);
        }

        while(!stk.empty()) stk.pop();

        for(int i=a.size()-1;i>=0;i--) {
            while(!stk.empty() && a[stk.top()]<a[i]) {
                r=max(r,stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        return r>l?r-l+1:0;
    }
};

// Time : O(N)
// Space: O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int st=-1,en=a.size(),cur_min=1e6,cur_max=-1e6;
        for(int i=a.size()-1;i>=0;i--) {
            cur_min=min(cur_min,a[i]);
            if(a[i]>cur_min) st=i;
        }
        for(int i=0;i<a.size();i++) {
            cur_max=max(cur_max,a[i]);
            if(a[i]<cur_max) en=i;
        }
        if(st>=0 || en<a.size()) return en-st+1;
        return 0;
    }
};