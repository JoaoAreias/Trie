/*
Author: Joao Areias
Last modified: July 17, 2017

MIT License

Copyright (c) 2017 Joao Pedro Areias de Moraes

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <unordered_map>
#include "Trie.h"

using namespace std;

Trie::Trie(){
	root = new Node();
}

Trie::~Trie(){
	remove(root);
}

void Trie::remove(Node *n){
    // Loop thru every child node visiting it recursivelly
    for(pair<char,Node*> p: n->children)
        remove(p.second);
    // Delete current node
    delete n;
}

void Trie::insert(string str){
    Node* node = root; // Current node being visited
    // Loop thru every letter on the String
    for(char c: str){
        // Adds a children node if it doesn't find any with that key
        if(node->children.find(c) == node->children.end()){
            node->children[c] = new Node();
            node->isLeaf = false;
        }
        // Visit next node
        node = node->children[c];
    }
    // Sets the end of the word
    node->endOfWord = true;
}

bool Trie::search(string str){
    Node *node = root; // Current node
    // Loop thru every character on the string
    for(char c:str){
        // Return false if key is not found or reach a leaf node
        if(node->children.find(c) == node->children.end() || node->isLeaf)
            return false;
        // Visit next node
        node = node->children[c];
    }
    // Once all charachters matched, returns true
    return true;
}