class Solution {
public:
    // Run-time: O(n) (each vertex visited only once)
	//
    // Memory: O(n) (at most n items in stack; this also applies to recursive DFS solutions 
	// except they also have stack frames stored on the stack)
	//
    // Beats 97% for run-time and 90% for memory usage.
    int numOfMinutes(const int n, const int headID, 
                     vector<int>& managers, vector<int>& informTime) {
        
        // This DFS stores a pair of (employee, subordinate).
        std::stack<std::pair<int, int>> s;
        
        auto total_time = 0;
        
        for (auto i = 0; i < n; ++i) {
            // We use the managers array as a "visited" array. 
			// (-1) indicates that we have already visited.
            // We could also use a vector of our own or an unordered_set 
			// to preserve the input, at the cost of extra memory and a slower program.
            if (managers[i] < 0) {
                continue;
            }
            
            s.push({i, -1});
            
            // We visit in depth-first order, getting to the highest-level manager who has
            // a correct inform time. Once we do, we add the inform time in reverse order using
            // the stack until we reach the employee we started with.
            while (!s.empty()) {
                const auto [employee, _] = s.top();
                const auto manager = managers[employee];
                
                if (manager != -1) {
                    s.push({manager, employee});
                    continue;
                }
                
                while (true) {
                    const auto [employee, subordinate] = s.top();
                    s.pop();
                    // Mark as visited using managers array
                    managers[employee] = -1;
                    // If this is the bottom level, we should break since there are
                    // no more subordinates.
                    if (s.empty()) {
                        break;
                    }
                    // Otherwise, add this employee's adjusted inform time to their
                    // subordinate.
                    informTime[subordinate] += informTime[employee];
                }
            }
            
            // Update the total time using the bottom-level employee we start with.
            total_time = max(informTime[i], total_time);
        }
        
        return total_time;
    }
};


















1376. Time Needed to Inform All Employees
Medium

2334

153

Add to List

Share
A company has n employees with a unique ID for each employee from 0 to n - 1. The head of the company is the one with headID.

Each employee has one direct manager given in the manager array where manager[i] is the direct manager of the i-th employee, manager[headID] = -1. Also, it is guaranteed that the subordination relationships have a tree structure.

The head of the company wants to inform all the company employees of an urgent piece of news. He will inform his direct subordinates, and they will inform their subordinates, and so on until all employees know about the urgent news.

The i-th employee needs informTime[i] minutes to inform all of his direct subordinates (i.e., After informTime[i] minutes, all his direct subordinates can start spreading the news).

Return the number of minutes needed to inform all the employees about the urgent news.

 

Example 1:

Input: n = 1, headID = 0, manager = [-1], informTime = [0]
Output: 0
Explanation: The head of the company is the only employee in the company.
Example 2:


Input: n = 6, headID = 2, manager = [2,2,-1,2,2,2], informTime = [0,0,1,0,0,0]
Output: 1
Explanation: The head of the company with id = 2 is the direct manager of all the employees in the company and needs 1 minute to inform them all.
The tree structure of the employees in the company is shown.
 

Constraints:

1 <= n <= 105
0 <= headID < n
manager.length == n
0 <= manager[i] < n
manager[headID] == -1
informTime.length == n
0 <= informTime[i] <= 1000
informTime[i] == 0 if employee i has no subordinates.
It is guaranteed that all the employees can be informed.
