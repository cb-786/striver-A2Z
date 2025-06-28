int findUnion(vector<int>& a, vector<int>& b) {
    // code here
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  
  int i = 0, j = 0;
  int count = 0;
  
  // Traverse both arrays with two pointers
  while (i < a.size() && j < b.size()) {
      if (a[i] < b[j]) {
          count++;
          int temp = a[i];
          // Skip duplicates in a
          while (i < a.size() && a[i] == temp) i++;
      } else if (b[j] < a[i]) {
          count++;
          int temp = b[j];
          // Skip duplicates in b
          while (j < b.size() && b[j] == temp) j++;
      } else {
          count++;
          int temp = a[i];
          // Skip duplicates in both arrays
          while (i < a.size() && a[i] == temp) i++;
          while (j < b.size() && b[j] == temp) j++;
      }
  }
  
  // Handle remaining elements in a
  while (i < a.size()) {
      count++;
      int temp = a[i];
      while (i < a.size() && a[i] == temp) i++;
  }
  
  // Handle remaining elements in b
  while (j < b.size()) {
      count++;
      int temp = b[j];
      while (j < b.size() && b[j] == temp) j++;
  }
  
  return count;
  
}