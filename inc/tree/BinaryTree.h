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
			TreeNode* result = nullptr;
			Traversal(root, p, q, &result);
			return result;
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
		bool Traversal(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** result)
		{
			if (root == nullptr)
			{
				return root;
			}
	
			bool leftFound = Traversal(root->left, p, q, result);
			bool rightFound = Traversal(root->right, p, q, result);
			
			//std::cout << root->val << std::endl;
			bool currentFound = (root == p || root == q);
			if ((leftFound && rightFound) || ((leftFound || rightFound) && currentFound))
			{
				*result = root;
			}
			return leftFound || rightFound || currentFound;
		}
	};
}
#endif // !BINARYTREE_H
