#include <bits/stdc++.h>
using namespace std;

// Huffman tree node
struct MinHeapNode
{
    char data;
    int freq;

    MinHeapNode *left, *right;

    MinHeapNode(char data, int freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

// For comparison of two nodes.
struct compare
{

    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->freq > r->freq);
    }
};

// Print Huffman Codes
void printCodes(struct MinHeapNode *root, string str, map<char, string> &mapp)
{
    // If root is Null then return.
    if (!root)
    {
        return;
    }
    // If the node's data is not '$' that means it's not an internal node and print the string.
    if (root->data != '$')
    {
        cout << root->data << ": " << str << endl;
        mapp.insert({root->data, str});
    }

    printCodes(root->left, str + "0", mapp);
    printCodes(root->right, str + "1", mapp);
}

// Build Huffman Tree
void HuffmanCodes(char data[], int freq[], int size, map<char, string> &mapp)
{

    struct MinHeapNode *left, *right, *top;

    // create a min heap.
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minheap;

    // For each character create a leaf node and insert each leaf node in the heap.
    for (int i = 0; i < size; i++)
    {
        minheap.push(new MinHeapNode(data[i], freq[i]));
    }

    // Iterate while size of min heap doesn't become 1
    while (minheap.size() != 1)
    {
        // Extract two nodes from the heap.
        left = minheap.top();
        minheap.pop();

        right = minheap.top();
        minheap.pop();

        // Create a new internal node having frequency equal to the sum of
        //  two extracted nodes.Assign '$' to this node and make the two extracted
        //  node as left and right children of this new node.Add this node to the
        //  heap.

        auto tmp = new MinHeapNode('$', left->freq + right->freq);
        tmp->left = left;
        tmp->right = right;

        minheap.push(tmp);
    }
    // Calling function to print the codes.
    printCodes(minheap.top(), " ", mapp);
}

void printKey(map<char, string> &Map,
              char K)
{

    // Traverse the map
    for (auto &it : Map)
    {

        // If mapped value is K,
        // then print the key value
        if (it.first == K)
        {
            cout << it.second << ' ';
            // a = false;
        }
    }
}

int main()
{
    fstream file;
    string word, t, q, filename, completeFile = "";
    map<char, string> mapp;

    // filename of the file
    filename = "./inputFile.txt";

    // opening file
    file.open(filename.c_str());

    // extracting words from the file
    cout << "Given String: \n";
    cout << "Huffman Encoding: \n";
    while (file >> word)
    {
        // displaying content
        cout << word << endl;
        completeFile += word;
    }

    // char arr[completeFile.length()];
    // int freq[completeFile.length()];

    // for (int i = 0; i < completeFile.length(); i++)
    // {
    //     arr[i] = completeFile[i];
    // }

    // for (int i = 0; i < completeFile.length(); i++)
    // {
    //     freq[arr[i]];
    // }

    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int freq[26] = {0};

    for (int i = 0; i < completeFile.length(); i++)
    {
        freq[completeFile[i] - 'a']++;
    }
    cout << "The Freq of a in given string is " << freq[0] << endl;
    // for (int i = 0; i < 26; i++)
    // {
    //     f;

    // }

    int size = 26;
    HuffmanCodes(arr, freq, size, mapp);

    cout << "\nFinal Encoding\n";
    cout << completeFile << " : ";

    for (int i = 0; i < completeFile.length(); i++)
    {
        printKey(mapp, completeFile[i]);
    }

    cout << endl;

    return 0;
}