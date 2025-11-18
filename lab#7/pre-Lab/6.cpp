#include <iostream>

// Function demonstrating static local variable caching behavior
int computeOnce(int x) {
    static int cache = x;  
    // First call: cache initializes to x.
    // Later calls: cache keeps its old value (NOT reinitialized).

    std::cout << "Current cached value = " << cache << std::endl;

    // After printing, update cache to a fixed value
    cache = 10;

    return cache;
}

/*
Thread-safety note:
-------------------------------------------
In C++11 and later, static local initialization is guaranteed to be
thread-safe automatically.

Meaning: the first time 'computeOnce' is called, the initialization
of `cache` happens exactly once, even in multi-threaded programs.

If we wanted to control this manually, we could use std::call_once,
but that is NOT needed here because C++11 already guarantees it.
*/

//.cpp
#include <iostream>

// Declare computeOnce from cache.cpp
int computeOnce(int x);

int main() {

    std::cout << "=== Task 6 Tests ===\n";

    int a = computeOnce(5);   // First call → cache = 5
    std::cout << "Returned: " << a << "\n\n";

    int b = computeOnce(7);   // Second call → cache remains 10 (NOT 7)
    std::cout << "Returned: " << b << "\n\n";

    return 0;
}
