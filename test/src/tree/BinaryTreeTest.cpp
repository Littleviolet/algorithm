#include <gtest/gtest.h>
#include <queue>
#include <tree/BinaryTree.h>

using namespace tree;

static TreeNode* CreateTree(std::vector<int>& nums)
{
    if (nums.empty()) {
        return nullptr;
    }

    // 使用队列按层次构建二叉树
    std::queue<TreeNode*> q;
    TreeNode* root = new TreeNode(nums[0]);
    q.push(root);

    for (int i = 1; i < nums.size(); i += 2) {
        TreeNode* current = q.front();
        q.pop();

        // 构建左子节点
        if (nums[i] != INT_MAX) {
            current->left = new TreeNode(nums[i]);
            q.push(current->left);
        }

        // 构建右子节点
        if (i + 1 < nums.size() && nums[i + 1] != INT_MAX) {
            current->right = new TreeNode(nums[i + 1]);
            q.push(current->right);
        }
    }
    return root;
}

TEST(BinaryTreeTest, LowestCommonAncestorCase1)
{
	TreeNode head(1);
	TreeNode left(2);
	head.left = &left;
	BinaryTree bTree;
	TreeNode* node = bTree.LowestCommonAncestor(&head, &head, &left);
	EXPECT_EQ(&head, node);
	ASSERT_TRUE(node != nullptr);
	EXPECT_EQ(node->val, 1);
}

TEST(BinaryTreeTest, LowestCommonAncestorCase2)
{
    std::vector<int> nums = { 3,5,1,6,2,0,8,INT_MAX,INT_MAX,7,4 };
    TreeNode* head = CreateTree(nums);
    BinaryTree bTree;
    bTree.LevelOrderTraversal(head);
    TreeNode* node = bTree.LowestCommonAncestor(head, head->left, head->right);
<<<<<<< HEAD
    ASSERT_TRUE(node != nullptr);
=======
>>>>>>> a62c54dbe9a3ba2addddb1d4c7f98cac5f58d8c2
    EXPECT_EQ(node->val, 3);
}
