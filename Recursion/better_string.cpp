 void generateUniqueSubsequences(set<string>& uniqueSubsequences, string sub, string str, int i) {
    if (i == str.size()) {
        uniqueSubsequences.insert(sub); // Add the current subsequence to the set
        return;
    }

    // Exclude the current character
    generateUniqueSubsequences(uniqueSubsequences, sub, str, i + 1);

    // Include the current character
    generateUniqueSubsequences(uniqueSubsequences, sub + str[i], str, i + 1);
}

// Function to determine the better string
string betterString(string str1, string str2) {
    set<string> uniqueSubsequences1, uniqueSubsequences2;

    // Generate unique subsequences for both strings
    generateUniqueSubsequences(uniqueSubsequences1, "", str1, 0);
    generateUniqueSubsequences(uniqueSubsequences2, "", str2, 0);

    // Compare the sizes of unique subsequences
    if (uniqueSubsequences1.size() >= uniqueSubsequences2.size()) {
        return str1;
    } else {
        return str2;
    }
}