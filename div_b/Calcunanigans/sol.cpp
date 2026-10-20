#include <bits/stdc++.h>
using namespace std;

/*
i miss interpreted the question -> I thought removing from the top meant the oldest in the record
- dont judge me for making my own deque for this


*/

struct Node {
    int val;
    shared_ptr<Node> next, prev;
};

// actually a dq mb
struct Deque {
    shared_ptr<Node> head, tail;
    int size = 0;

    Deque() {
        head = make_shared<Node>();
        tail = make_shared<Node>();
        (*head).next = tail;
        (*tail).prev = head;
    }

    int popLeft() {
        if ((*head).next) {
            int val = (*(*head).next).val;
            (*head).next = (*(*head).next).next;
            (*(*head).next).prev = head;

            --size;
            return val;
        }
        throw out_of_range("Linked lists has no nodes to pop");
    }

    int popRight() {
        if ((*tail).prev) {
            int val = (*(*tail).prev).val;
            (*tail).prev = (*(*tail).prev).prev;
            (*(*tail).prev).next = tail;
            --size;
            return val;
        }
        throw out_of_range("Linked lists has no nodes to pop");
    }

    void appendLeft(int val) {
        shared_ptr<Node> new_node = make_shared<Node>();
        (*new_node).val = val;

        (*new_node).next = (*head).next;
        (*new_node).prev = head;
        (*head).next = new_node;
        (*(*new_node).next).prev = new_node;

        ++size;
    }

    void appendRight(int val) {
        shared_ptr<Node> new_node = make_shared<Node>();
        (*new_node).val = val;

        (*new_node).next = tail;
        (*new_node).prev = (*tail).prev;
        (*(*new_node).prev).next = new_node;
        (*tail).prev = new_node;
        ++size;
    }
};

void solve() {
    int n;
    cin >> n;
    bool early_exit = false;
    Deque dq = Deque();

    for (int i = 0; i < n; i++) {
        char inp;
        cin >> inp;

        if (isdigit(inp)) {
            dq.appendRight((int)inp - '0');

        } else if (inp == '+') {
            if (dq.size < 2) {
                early_exit = true;
                break;
            }
            int first = dq.popRight();
            int second = dq.popRight();

            dq.appendRight(first + second);
        } else if (inp == 'B') {
            if (dq.size < 1) {
                early_exit = true;
                break;
            }

            dq.popRight();
        } else if (inp == 'C') {
            dq = Deque();  // if clearing every element you might as wedq just make a new list
                           // O(1) -> wait no garbage codqector so i need to delete this down i?

        } else if (inp == 'T') {
            if (dq.size < 1) {
                early_exit = true;
                break;
            }

            int top = dq.popRight();
            dq.appendRight((int)top / 3);

        } else if (inp == 'D') {
            if (dq.size < 1) {
                early_exit = true;
                break;
            }

            int top = dq.popRight();
            dq.appendRight(top * 2);
        }
    }

    if (dq.size == 1 && not early_exit) {
        cout << dq.popLeft() << endl;
    } else {
        cout << "INVALID" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solve();

    return 0;
}
