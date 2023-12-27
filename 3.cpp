#include <iostream>
#include <set>

class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (smaller.empty() || num <= *smaller.rbegin()) {
            smaller.insert(num);
        } else {
            larger.insert(num);
        }

        if (smaller.size() > larger.size() + 1) {
            larger.insert(*smaller.rbegin());
            smaller.erase(std::prev(smaller.end()));
        } else if (larger.size() > smaller.size()) {
            smaller.insert(*larger.begin());
            larger.erase(larger.begin());
        }
    }

    double findMedian() {
        if (smaller.size() == larger.size()) {
            return (static_cast<double>(*smaller.rbegin()) + *larger.begin()) / 2;
        } else {
            return *smaller.rbegin();
        }
    }

private:
    std::multiset<int> smaller, larger;
};

int main() {
    MedianFinder mf;
    mf.addNum(2);
    mf.addNum(3);
    std::cout << mf.findMedian() << std::endl;
    mf.addNum(4);
    std::cout << mf.findMedian() << std::endl;

    return 0;
}