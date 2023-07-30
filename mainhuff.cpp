#include<bits/stdc++.h>
using namespace std;

unordered_map<char,string> encoded;//map to store the encode results.
string ans="";
string destr="";

class Node{
    public:
        int freq;
        Node* left;
        Node* right;
        char val;
        Node(char c,int f,Node* l,Node* r){
            val = c;
            freq = f;
            left=l;
            right=r;
        }
        
};
class cmp{
    public:
    bool operator()(Node* a,Node* b){
        return a->freq > b->freq;
    }
};

void encode(Node* root,string str,unordered_map<char,string>&encoded){
    if(!root) return;
    if(root->left == NULL && root->right == NULL){
        encoded[root->val] = str;
        return;
    }
    encode(root->left, str +"0",encoded);
    encode(root->right, str +"1",encoded);
}

void decode(Node* root,string enstr,int &index){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        destr+=root->val;
        return;
    }
    index++;
    if(enstr[index] == '0'){
        decode(root->left,enstr,index);
    }
    else{
        decode(root->right,enstr,index);
    }
}

Node* huffmancoding(unordered_map<char,int> &count){

    priority_queue<Node*,vector<Node*>,cmp> pq;
    for(auto it :count){
        Node* n = new Node(it.first,it.second,NULL,NULL);//push every char along with their fq 
        pq.push(n);
    }
    while(pq.size()!=1){
        Node* lf1 = pq.top();///least frequency 1; left node
        pq.pop();
        Node* lf2 = pq.top();//least frequency 2; right node
        pq.pop();
       // cout<<lf1->val<<" "<<lf2->val<<endl;
        Node* n1 = new Node('a',lf1->freq+lf2->freq,lf1,lf2);
        pq.push(n1);
    }
    Node* root = pq.top();
    string str = "";
    encode(root,str,encoded);

    //endoded results
    
   // ofstream out("output.txt");
    for(auto i : encoded){
        cout<<i.first<<" "<<i.second<<endl;
        //out<<i.first<<" "<<i.second<<endl;
    }
    ofstream out("encodedstring.txt");
    for(auto i:ans){
        out<<encoded[i];
        //enstr+=encoded[i];
    }

    return root;
}

void decoding(Node* root){
    string enstr;
    ifstream en("encodedstring.txt");
    en>>enstr;
    int index = -1;
    while(index<(int)enstr.length()-1){
       decode(root,enstr,index);
    }
    //cout<<destr<<endl;
    ofstream ou("outstring.txt");
    ou<<destr;

}

int main(){
    ifstream infile;
    infile.open("input.txt");
    unordered_map<char,int> count;
//programe to count each char in the text file including spaces 
    if(infile.is_open()){
        string x;
        while(getline(infile,x)){
            ans+=x;
            for(auto i:x){
                count[i]++;
            }
        }
    }
    cout<<"***************original data***************"<<endl;
    cout<<endl;
    cout<<ans<<endl;
    cout<<endl;
    cout<<"****************CHAR AND FREQ***************"<<endl;
    cout<<endl;
    ofstream freq("charfreq.txt");

    for(auto i: count){
        cout<<i.first<<" "<<i.second<<endl;
        freq<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;
    cout<<"*******************************HUFFMAN CODING********************************"<<endl;
    Node* huff_man = huffmancoding(count);

    decoding(huff_man);
    cout<<endl;
    cout<<endl;
    cout<<"************encoded string is strored in file name 'encodedstring.txt'**************"<<endl;
    cout<<endl;
    cout<<"********The decoded string is also available in file name 'outstring.txt'***********"<<endl;
    cout<<endl;
    cout<<"************************************THANK YOU***************************************"<<endl;
    cout<<endl;
}