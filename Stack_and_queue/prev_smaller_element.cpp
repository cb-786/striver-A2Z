#include <bits/stdc++.h>
using namespace std;

int main() {
	 int t; // number of test cases
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        // Call your function or write logic here
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }
            ans[i] = s.empty() ? -1 : s.top();
            s.push(arr[i]);
        }

        
        for (int x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;

}