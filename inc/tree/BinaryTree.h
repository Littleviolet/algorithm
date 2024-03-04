#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <queue>

namespace tree
{
	// Definition for a binary tree node.
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};

	class BinaryTree
	{
	public:
		BinaryTree() = default;
		~BinaryTree() = default;
		TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
		{
			bool pFound = false, qFound = false;
			return LowestCommonAncestor(root, p, q, pFound, qFound);
		}

		void LevelOrderTraversal(TreeNode* root)
		{
			std::queue<TreeNode*> nodes;
			nodes.push(root);
			while (!nodes.empty())
			{
				auto current = nodes.front();
				nodes.pop();
				if (current == nullptr)
				{
					continue;
				}
				std::cout << current->val << ",";
				nodes.push(current->left);
				nodes.push(current->right);
			}
			std::cout << std::endl;
		}
	private:
		TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q,bool& pFound, bool& qFound)
		{
			if (root == nullptr)
			{
				return root;
			}
			TreeNode* ancestor = nullptr;
			ancestor = LowestCommonAncestor(root->left, p, q, pFound, qFound);
			
			if (ancestor == nullptr)
			{
				ancestor = LowestCommonAncestor(root->right, p, q, pFound, qFound);
			}
			if (ancestor != nullptr)
			{
				return ancestor;
			}

			std::cout << root->val << std::endl;
			if (pFound && qFound)
			{
				return root;
			}
			else
			{
				pFound = pFound || (root == p);
				qFound = qFound || (root == q);
				return nullptr;
			}
		}
	};
}
#endif // !BINARYTREE_H
