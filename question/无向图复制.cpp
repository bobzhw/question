#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;
//Definition for undirected graph.
 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };


 
 
 class Solution {

 public:
	 //…Ó∂»±È¿˙
	 UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		 return dfs(node);
	 }
 private:
	 unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
	 UndirectedGraphNode* dfs(UndirectedGraphNode* root)
	 {
		 if (root == nullptr)
			 return nullptr;
		 UndirectedGraphNode* cloneroot = new UndirectedGraphNode(root->label);
		 m[root] = cloneroot;

		 for (auto node : root->neighbors)
		 {
			 if (m.find(node) != m.end())
			 {
				 cloneroot->neighbors.push_back(m[node]);
			 }
			 else
			 {
				 UndirectedGraphNode* newnode = dfs(node);
				 cloneroot->neighbors.push_back(newnode);
			 }
		 }
		 return cloneroot;

	 }
 };