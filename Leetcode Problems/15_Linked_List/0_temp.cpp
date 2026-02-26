

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class BrowserHistory
{
private:
    vector<string> history;
    int current;

public:
    BrowserHistory(string homepage)
    {
        history.push_back(homepage);
        current = 0;
    }

    void visit(string url)
    {
        // Remove forward history
        history.erase(history.begin() + current + 1, history.end());

        history.push_back(url);
        current++;
    }

    string back(int steps)
    {
        current = max(0, current - steps);
        return history[current];
    }

    string forward(int steps)
    {
        current = min((int)history.size() - 1, current + steps);
        return history[current];
    }
};