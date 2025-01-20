void generateBinaryStrings(int n, string current, int i) {
    // Base case: if the length of the current string reaches n, print it
    if (i == n) {
        cout << current << endl;
        return;
    }

    // Add '0' and recurse for the next index
    generateBinaryStrings(n, current + "0", i + 1);

    // Add '1' only if it won't violate the rule, and recurse for i + 2
    if (i == 0 || current.back() != '1') {
        generateBinaryStrings(n, current + "1", i + 1);
    }
}