#include <bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
struct TrieNode {
  struct TrieNode *children[ALPHABET_SIZE];
  bool isaLeaf; // represents end of a word
};
struct TrieNode *getNode(void) {
  struct TrieNode *pNode = NULL;
  pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
  if(pNode) {
    int i;
    pNode->isaLeaf = false;
    for (i=0;i < ALPHABET_SIZE;i++) 
      pNode->children[i] = NULL;
  }
  return pNode;
}
void insert(struct TrieNode *root, const char *key) {
  int level;
  int length = strlen(key);
  int index;
  struct TrieNode *pCrawl = root;
  for (level=0;level < length;level++) {
    index = CHAR_TO_INDEX(key[level]);
    if(!pCrawl->children[index])
      pCrawl->children[index] = getNode();

    pCrawl = pCrawl->children[index];
  }
  pCrawl->isaLeaf = true;
}
bool search (struct TrieNode *root, const char *key) {
  int level;
  int length = strlen(key);
  int index;
  struct TrieNode *pCrawl = root;
  for(level=0;level < length;level++) {
    index = CHAR_TO_INDEX(key[level]);
    if(!pCrawl->children[index])
      return false;
    pCrawl = pCrawl->children[index];
  }
  return (pCrawl != NULL && pCrawl->isaLeaf);
}

int main(int argc, char const *argv[])
{
  char keys[][9]  = {"the", "a", "there", "they", "an", "any", "by", "bye", "boy"};  
  char output[][32] = {"Not present in trie", "Present in trie"};
  struct TrieNode *root = getNode();
  int i;
  for (int i = 0; i < ARRAY_SIZE(keys); ++i)
  {
    insert(root, keys[i]);
  }
  cout<<"output[search(root, 'the')]  "<<output[search(root, "the")]<<endl;
  cout<<"output[search(root, 'they')]  "<<output[search(root, "they")]<<endl;
  cout<<"output[search(root, 'bye')]   "<<output[search(root, "bye")]<<endl;
  cout<<"output[search(root, 'be')]   "<<output[search(root, "be")];
  return 0;
}
