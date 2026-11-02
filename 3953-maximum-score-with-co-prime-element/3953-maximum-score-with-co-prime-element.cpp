class Solution {
public:
    vector<int> cntMultiples;

    // Generate all non-empty subsets of prime factors
    void generate(int index, vector<int>& primes,
                  int product, int count, int& badCount) {

        if (index == primes.size()) {
            if (count == 0) return;

            if (count % 2 == 1) {
                badCount += cntMultiples[product];
            } else {
                badCount -= cntMultiples[product];
            }

            return;
        }

        // Don't include current prime
        generate(index + 1, primes, product, count, badCount);

        // Include current prime
        generate(index + 1, primes,
                 product * primes[index], count + 1, badCount);
    }

    int maxScore(vector<int>& nums, int maxVal) {
        int n = nums.size();

        int M = maxVal;

        for (int x : nums) {
            M = max(M, x);
        }

        // Step 1: Frequency array
        vector<int> freq(M + 1, 0);

        for (int x : nums) {
            freq[x]++;
        }

        // Step 2: Count multiples of every number
        cntMultiples.assign(M + 1, 0);

        for (int d = 1; d <= M; d++) {
            for (int j = d; j <= M; j += d) {
                cntMultiples[d] += freq[j];
            }
        }

        // Step 3: Smallest Prime Factor sieve
        vector<int> spf(M + 1);

        for (int i = 0; i <= M; i++) {
            spf[i] = i;
        }

        for (int i = 2; i * i <= M; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= M; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }

        int ans = 0;

        // Step 4: Try every possible selected value
        for (int x = 1; x <= M; x++) {

            // Values greater than maxVal cannot be created
            if (x > maxVal && freq[x] == 0) {
                continue;
            }

            // Step 5: Find distinct prime factors of x
            vector<int> primes;

            int temp = x;

            while (temp > 1) {
                int p = spf[temp];

                primes.push_back(p);

                while (temp % p == 0) {
                    temp /= p;
                }
            }

            // Step 6: Calculate badCount
            int badCount = 0;

            generate(0, primes, 1, 0, badCount);

            // Step 7: Calculate modification cost
            int cost;

            if (freq[x] > 0) {
                cost = (x == 1) ? 0 : badCount - 1;
            }
            else {
                cost = max(1, badCount);
            }
           

            // Step 8: Calculate score
            int score = x - cost;

            ans = max(ans, score);
        }

        return ans;
    }
};