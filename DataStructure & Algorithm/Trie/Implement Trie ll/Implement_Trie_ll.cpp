#include <bits/stdc++.h>
using namespace std;

// define a trie node
class Node
{
public:
    Node *links[26];
    // indicates whether the word is an ending one in Trie
    int endWord;
    // indicates whether the prefix of this node is an ending one in Trie
    int countPrefix;

    Node()
    {
        endWord = 0;
        countPrefix = 0;
    }
    // check a character is already exist or not
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    //  insert a new key to the Trie
    void insert(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // get node address with given character
    Node *getNode(char ch)
    {
        return links[ch - 'a'];
    }

    // update character prefix
    void increasePrefix()
    {
        countPrefix++;
    }

    // update existing of given word
    void countWord()
    {
        endWord++;
    }

    // return current word count
    int getEnd()
    {
        return endWord;
    }

    // get no of matching prefixes of given word
    int getPrefix()
    {
        return countPrefix;
    }

    // removed prefix count
    void reducePrefix(char ch)
    {
        countPrefix--;
    }

    // reduce word count
    void reduceWordCount()
    {
        endWord--;
    }
};

class Trie
{
    // define root node
    Node *root;

public:
    Trie()
    {
        // initialize a new root node for this template.
        root = new Node();
    }

    void insert(string &word)
    {
        // Write your code here.
        int n = word.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            // check whether the element of given word is already
            // present in the trie
            if (!node->containsKey(word[i]))
            {
                // insert new element
                node->insert(word[i], new Node());
            }
            // update node pointer with next node pointer
            node = node->getNode(word[i]);

            // update element prefix count
            node->increasePrefix();
        }
        // update word count
        node->countWord();
    }

    int countWordsEqualTo(string &word)
    {
        // Write your code here.
        int n = word.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            if (node->containsKey(word[i]))
                node = node->getNode(word[i]);
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        // Write your code here.
        int n = word.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            if (node->containsKey(word[i]))
                node = node->getNode(word[i]);
            else
                return 0;
        }
        return node->getPrefix();
    }

    void erase(string &word)
    {
        // Write your code here.
        int n = word.size();
        Node *node = root;

        for (int i = 0; i < n; i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->getNode(word[i]);
                node->reducePrefix(word[i]);
            }

            else
                return;
        }

        node->reduceWordCount();
    }
};

int main(void)
{
    Trie T;
    vector<string> arr = {"apple", "apple", "apps", "apps"};

    for (auto item : arr)
        T.insert(item);

    string word1 = "apps";
    cout << "Count Words Equal to " << word1 << " " << T.countWordsEqualTo(word1) << endl;
    string word2 = "abc";
    cout << "Count Words Equal to " << word2 << " " << T.countWordsEqualTo(word2) << endl;
    string word3 = "ap";
    cout << "Count Words Starting With " << word3 << " " << T.countWordsStartingWith(word3)
         << endl;
    string word4 = "appl";
    cout << "Count Words Starting With " << word4 << " " << T.countWordsStartingWith(word4)
         << endl;
    T.erase(word1);
    cout << "Count Words equal to " << word1 << " " << T.countWordsEqualTo(word1) << endl;

    return 0;
}
