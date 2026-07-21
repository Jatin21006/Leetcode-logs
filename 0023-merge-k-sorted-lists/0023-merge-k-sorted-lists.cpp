class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr; // Handle completely empty input
        
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        
        while (true) {
            int mini = INT_MAX;
            int toadd = -1; // Use -1 to flag if no valid node is found
            
            for (int i = 0; i < lists.size(); i++) {        
                if (lists[i] != nullptr) {
                    if (mini > lists[i]->val) {
                        mini = lists[i]->val;
                        toadd = i;
                    }
                }
            }    
            
            // If toadd is still -1, all lists are exhausted. Break immediately.
            if (toadd == -1) break; 
            
            // Assign and move pointers
            tail->next = lists[toadd];
            tail = tail->next;
            lists[toadd] = lists[toadd]->next;
        }     
          
        return dummy->next;
    }
};