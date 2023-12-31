# HUFFMAN-CODING:
Implemented Huffman coding algorithm using min-heap, greedy algorithm, and recursion in C++.

A Huffman code is a particular type of optimal prefix code that is commonly used for lossless data compression. The process of finding or using such a code is Huffman coding,

**INPUT:**
C++ program takes input from an input text file.
We initialize a map data structure to count the frequency of each character in the given input.
We create a class of Node to store the char, frequency of character, and 2 addresses of its child nodes;these addresses of child nodes are crucial to form the huffman binary tree.

**HUFFMAN TREE:**
later the algorithm is as follows:
   1.  Create a leaf node for each symbol and add it to the priority queue.
   2.  While there is more than one node in the queue:
   3.  Remove the two nodes of highest priority (lowest frequency) from the queue. (i.e top two elements)(greedy algorithm)
   4.  Create a new internal node with these two nodes as children and with probability equal to the sum of the two nodes' probabilities.
   5.  Add the new node to the queue.
   6.  The remaining node is the root node and the tree is complete.
The root node obtained above serves as the root the Huffman tree.

**ENCODING:**
We now start with a empty string and the root of the huffman tree and traverse along the tree untill a leaf node is observed.
while traversing if we choose to move to left part of the tree our string is appended with '0' and '1' for the right part at each node.
this traversal is made by recursion.
when we reach the leaf node we store the character in the leaf node along with the string in a map. this is the genrated huffman code for that specific character.
the whole encoded string is stored in a text file genrated by running the code.

**DECODING:**
for decong we start with the encoded string and the map containg the huffman codes.
we traverse through the string if we encounter a '0' we move to left child and to right child if we encounter a '1'.
if we reach a leaf node we store the character in the output file.
so the output file contains the encoded string after running the program.

**time complexity**
let the input text contains M characters in which N are distinct

*  _map to store freq -> **O(M)**_ 
*  _min heap insertion -> **O(NlogN)**_ 
*  _encoding recurission depth(to traverse a binary tree, having N leaf nodes) -> O(N)_
*  _decoding iterates over the length of the string -> **O(M.L.L)**_ 
   * _H(X) ->entropy_
   * _L -> effective lenght(optimum length)_
   * _then the length of encoded string is  M.L_
   * _length of codewords can range from2 to N-1 both inclusive_
   * _so we can consider the averaGe length of code word to be effective length L_







