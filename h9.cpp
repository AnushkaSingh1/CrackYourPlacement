class Solution {
public:
    void insert(map<int, int>& qs, double& sumq, int K, int q, bool rm) {
        qs[q]++;
        sumq += q;
        if (rm) {
            auto it = prev(qs.end()); // remove the largest value, to keep the size of BST
            it->second--;
            sumq -= it->first;
            if (!it->second) qs.erase(it);
        }
    }
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        int len = quality.size();
        vector<pair<double, double>> qw(len);
        for (int i = 0; i < len; i++) qw[i] = make_pair(double(quality[i]) / wage[i], quality[i]);
        sort(qw.begin(), qw.end(), greater<pair<double, double>>());
        map<int, int> qs;
        double sumq = 0;
        for (int i = 0; i < K - 1; i++) {
            insert(qs, sumq, K, qw[i].second, false);
        }
        double result = 1e30;
        for (int t = K - 1; t <= len - 1; t++) {
            insert(qs, sumq, K, qw[t].second, t != K - 1);
            result = min(result, sumq / qw[t].first);
        }
        return result;
    }
};


















857. Minimum Cost to Hire K Workers
Hard
1.9K
233
Companies
There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0th worker and 35 to 2nd worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0th worker, 13.33333 to 2nd and 3rd workers separately.
 

Constraints:

n == quality.length == wage.length
1 <= k <= n <= 104
1 <= quality[i], wage[i] <= 104
