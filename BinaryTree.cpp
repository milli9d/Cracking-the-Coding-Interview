#pragma once
#include <iostream>
#include <vector>
#include <assert.h>

template <typename T>
class BSTree {
	// Member Structures
public:
	typedef struct TreeNode {
		TreeNode* left;
		TreeNode* right;
		T val;

		TreeNode(T val) : val(val), left(nullptr), right(nullptr) {
		}
	} TreeNode;

	// Default Constructor
	BSTree() : root(nullptr), size(0) {}

	// Member Functions
public:
	void insert(T val) {
		// Prepare new node
		TreeNode* temp = new TreeNode(val);

		// Decide where the new node goes
		// If root is empty  ,then make this node root
		if (root == nullptr) {
			root = temp;
			size++;
		}
		// if root is not empty , then search for next leaf node
		else if (root != nullptr) {
			TreeNode* insertPtr = root;
			// Find Leaf Node
			while (insertPtr != NULL) {
				if (val > insertPtr->val) {
					if (insertPtr->right == NULL) {
						insertPtr->right = temp;
						size++;
						return;
					}
					else {
						insertPtr = insertPtr->right;
					}
				}
				else if (val < insertPtr->val) {
					if (insertPtr->left == NULL) {
						insertPtr->left = temp;
						size++;
						return;
					}
					else {
						insertPtr = insertPtr->left;
					}
				}
				else if (val == insertPtr->val) {
					return;
				}
			}
		}
	}

	// BST search
	TreeNode* find(T val)const {
		// Sanity check
		if (root != NULL) {
			TreeNode* searchPtr = root;
			while (searchPtr != NULL) {
				if (val == searchPtr->val) {
					return searchPtr;
				}
				searchPtr = (val > searchPtr->val) ? (searchPtr->right) : (searchPtr->left);
			}
		}
	}

	// Calculate Tree Height
	int treeHeight() {
		return treeHeight(root);
	}
private:
	int treeHeight(TreeNode* root) {
		if (root == NULL) { return 0; }
		return 1 + std::max(treeHeight(root->left), treeHeight(root->right));
	}
public:
	// Generate Random values in the tree
	void generateRandomInt(size_t count, int mod) {
		srand(time(NULL));
		for (int i = 0; i < count; i++) {
			int val = rand() % mod;
			insert(val);
		}
	}

	// Traversals Calls
public:

	TreeNode* minElement() {
		TreeNode* searchPtr = root;
		while (searchPtr->left != NULL && searchPtr != NULL) {
			searchPtr = searchPtr->left;
		}
		std::cout << "MIN: " << searchPtr->val << std::endl;
		return searchPtr;
	}

	TreeNode* maxElement() {
		TreeNode* searchPtr = root;
		while (searchPtr->right != NULL && searchPtr != NULL) {
			searchPtr = searchPtr->right;
		}
		std::cout << "MAX: " << searchPtr->val << std::endl;
		return searchPtr;
	}

	void inOrderBST() {
		inOrderBST(root);
		printf("\n");
	}

	void postOrderBST() {
		postOrderBST(root);
		printf("\n");
	}

	void preOrderBST() {
		preOrderBST(root);
		printf("\n");
	}

	void breadthFirstBST() {
		std::vector<std::vector<TreeNode*>> temp;
		breadthFirstBST(temp, root, 0);
		BFSPrint(temp);
	}

	// Traversal Helpers
private:
	void BFSPrint(std::vector<std::vector<TreeNode*>>& arr) {
		for (std::vector<TreeNode*> sub : arr) {
			for (TreeNode* node : sub) {
				printf("%3d | ", node->val);
			}
			std::cout << std::endl;
		}
	}

	void breadthFirstBST(std::vector<std::vector<TreeNode*>>& arr, TreeNode* root, int level) {
		if (root == NULL) { return; }
		if (level >= arr.size()) {
			std::vector<TreeNode*> temp;
			arr.push_back(temp);
		}
		arr[level].push_back(root);
		breadthFirstBST(arr, root->left, level + 1);
		breadthFirstBST(arr, root->right, level + 1);
	}

	// In Order means left , then root , then child
	void inOrderBST(TreeNode* root) {
		if (root == NULL) { return; }
		inOrderBST(root->left);
		printf("%3d | ", root->val);
		inOrderBST(root->right);
	}

	// Left , Right , Root
	void postOrderBST(TreeNode* root) {
		if (root == NULL) { return; }
		postOrderBST(root->left);
		postOrderBST(root->right);
		printf("%3d | ", root->val);
	}

	// Left , Right , Root
	void preOrderBST(TreeNode* root) {
		if (root == NULL) { return; }
		printf("%3d | ", root->val);
		preOrderBST(root->left);
		preOrderBST(root->right);
	}

private:
	TreeNode* root = nullptr;
	size_t size = 0;
};

int main() {
	using DATA_TYPE = int;

	BSTree<DATA_TYPE> test;
	test.generateRandomInt(100, 20);
	const BSTree<DATA_TYPE>::TreeNode* temp = test.find(2);
	test.inOrderBST();
	printf("\n\n");
	test.preOrderBST();
	printf("\n\n");
	test.postOrderBST();
	printf("\n\n");
	test.breadthFirstBST();
	printf("\n\n");
	temp = test.minElement();
	temp = test.maxElement();
	int h = test.treeHeight();
	return 0;
}