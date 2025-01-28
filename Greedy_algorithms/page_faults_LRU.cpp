int pageFaults(int N, int C, int pages[]){
        deque<int> cache; // Deque to act as an LRU cache
    int Faults = 0;

    for (int i = 0; i < N; i++) {
        int currentPage = pages[i];
        bool found = false;

        // Check if the current page is already in the cache
        for (auto it = cache.begin(); it != cache.end(); it++) {
            if (*it == currentPage) {
                found = true;

                // Move the accessed page to the front (most recently used)
                cache.erase(it);
                cache.push_front(currentPage);
                break;
            }
        }

        if (!found) {
            // Page is not in the cache -> page fault occurs
            Faults++;

            // If the cache is full, remove the least recently used page (from the back)
            if (cache.size() == C) {
                cache.pop_back();
            }

            // Add the new page to the front (most recently used)
            cache.push_front(currentPage);
        }
    }

    return Faults;
    }