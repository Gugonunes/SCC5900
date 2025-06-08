#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    vector<TrieNode*> next;
    int count;
    int endsHere;
    TrieNode() : next(26, nullptr), count(0), endsHere(0) {}
};

TrieNode* root = new TrieNode();

void insert(const string& s) {
    TrieNode* node = root;
    for (char c : s) {
        int idx = c - 'a';
        if (!node->next[idx])
            node->next[idx] = new TrieNode();
        node = node->next[idx];
        node->count++;
    }
    node->endsHere++;
}

void remove(const string& s) {
    TrieNode* node = root;
    vector<TrieNode*> path;
    for (char c : s) {
        int idx = c - 'a';
        node = node->next[idx];
        path.push_back(node);
    }
    for (TrieNode* n : path)
        n->count--;
    node->endsHere--;
}

int countPrefix(const string& s) {
    TrieNode* node = root;
    for (char c : s) {
        int idx = c - 'a';
        if (!node->next[idx])
            return 0;
        node = node->next[idx];
    }
    return node->count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int t;
        string s;
        cin >> t >> s;
        if (t == 1) {
            insert(s);
        } else if (t == 2) {
            remove(s);
        } else if (t == 3) {
            cout << countPrefix(s) << '\n';
        }
    }
    return 0;
}