class Solution {
public:
    int compress(vector<char>& chars) {
        int read = 0;
        int write = 0;
        
        while (read < chars.size()) {
            char currentChar = chars[read];
            int count = 0;
            
            // 1. Count occurrences of the current character
            while (read < chars.size() && chars[read] == currentChar) {
                read++;
                count++;
            }
            
            // 2. Write the character to the write pointer
            chars[write] = currentChar;
            write++;
            
            // 3. Write the count if it's greater than 1
            if (count > 1) {
                // Convert integer count to string to handle multi-digit numbers (like 12 -> '1', '2')
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write] = c;
                    write++;
                }
            }
        }
        
        // The write pointer now represents the new length of the compressed array
        return write;
    }
};