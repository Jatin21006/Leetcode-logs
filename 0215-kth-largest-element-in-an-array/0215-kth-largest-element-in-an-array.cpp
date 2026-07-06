class Solution {
public:
    
    int findKthLargest(const std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            
            // The VIP club is full, kick out the smallest member at the door
            if (minHeap.size() > k) {
                minHeap.pop(); 
            }
        }
        
        // The smallest member of the top k is the kth largest overall
        return minHeap.top();
    }
};

