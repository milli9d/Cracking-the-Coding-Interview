#include <iostream>
#include <array>
#include <memory>
#include <iomanip>

namespace ctci {

template<typename T>
class binary_search_tree
{
  public:
    class node_t
    {
      public:
        T data;
        std::shared_ptr<node_t> left{ nullptr };
        std::shared_ptr<node_t> right{ nullptr };

        node_t(const T& data, const std::shared_ptr<node_t>& left,
               const std::shared_ptr<node_t> right)
            : data(data), left(left), right(right)
        {
            /* do nothing */
        }
    };

    typedef std::shared_ptr<node_t> node_ptr_t;

    static void swap(node_ptr_t a, node_ptr_t b)
    {
        T temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

  private:
    size_t _sz{ 0u };
    node_ptr_t _root{ nullptr };

  public:
    void print_post_order(std::ostream& os, const node_ptr_t& node) const
    {
        if (!node) {
            return;
        }
        print_post_order(os, node->left);        // Visit left subtree
        print_post_order(os, node->right);       // Visit right subtree
        os << std::setw(2) << node->data << " "; // Print current node
    }

    void print_pre_order(std::ostream& os, const node_ptr_t& node) const
    {
        if (!node) {
            return;
        }
        os << std::setw(2) << node->data << " "; // Print current node
        print_post_order(os, node->left);        // Visit left subtree
        print_post_order(os, node->right);       // Visit right subtree
    }

    /**
     * @brief
     * @param os
     * @param node
     */
    void print_in_order(std::ostream& os, const node_ptr_t& node) const
    {
        if (!node) {
            return;
        }
        print_in_order(os, node->left);          // Visit left subtree
        os << std::setw(2) << node->data << " "; // Print current node
        print_in_order(os, node->right);         // Visit right subtree
    }

    /**
     * @brief
     * @param os
     * @param node
     */
    void print_bfs(std::ostream& os, const node_ptr_t& node) const
    {
        if (!node) {
            return;
        }
        std::queue<node_ptr_t> _next_level{};
        _next_level.push(node);
        while (!_next_level.empty()) {
            auto curr = _next_level.front();
            os << std::setw(2) << curr->data << " ";
            _next_level.pop();
            if (curr->left) {
                _next_level.push(curr->left);
            }
            if (curr->right) {
                _next_level.push(curr->right);
            }
        }
    }

    /**
     * @brief Pretty print BST
     * @param os
     * @param tree
     * @return
     */
    friend std::ostream& operator<<(std::ostream& os,
                                    const binary_search_tree& tree)
    {
        os << "IN_ORDER\t[ ";
        tree.print_in_order(os, tree._root);
        os << "]\n";

        os << "PRE_ORDER\t[ ";
        tree.print_pre_order(os, tree._root);
        os << "]\n";

        os << "POST_ORDER\t[ ";
        tree.print_post_order(os, tree._root);
        os << "]\n";

        os << "BFS\t\t[ ";
        tree.print_bfs(os, tree._root);
        os << "]\n";

        return os;
    }

    /**
     * @brief insert a value in the BST
     * @param val
     * @return
     */
    int32_t insert(const T& val)
    {
        /* if root is empty, replace root */
        if (!_root) {
            _root = std::make_shared<node_t>(val, nullptr, nullptr);
            return 0;
        }

        /* find next suitable location */
        node_ptr_t curr = _root;
        while (curr) {
            /* don't allow duplicates */
            if (curr->data == val) {
                return -EALREADY;
            }
            if (val > curr->data) {
                if (curr->right == nullptr) {
                    curr->right =
                        std::make_shared<node_t>(val, nullptr, nullptr);
                    _sz++;
                    return 0;
                }
                curr = curr->right;
            } else {
                if (curr->left == nullptr) {
                    curr->left =
                        std::make_shared<node_t>(val, nullptr, nullptr);
                    _sz++;
                    return 0;
                }
                curr = curr->left;
            }
        }

        /* we didn't insert */
        return -ENOMEM;
    }

    /**
     * @brief find a value in the BST O(log n)
     * @param val value to search for
     * @return true if found
     */
    node_ptr_t find(const T& val)
    {
        node_ptr_t curr = _root;
        while (curr) {
            if (curr->data == val) {
                return curr;
            }
            if (val > curr->data) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
        return nullptr;
    }

    void successor(node_ptr_t* node)
    {
        if (!node || !(*node)) {
            return;
        }

        if (!(*node)->right) {
            printf("No successor in the sub-tree i.e. is above the current "
                   "node\n");
            return;
        }

        *node = (*node)->right;
        while (*node && (*node)->left) {
            *node = (*node)->left;
        }
    }

    void predecessor(node_ptr_t* node)
    {
        if (!node || !(*node)) {
            return;
        }

        if (!(*node)->left) {
            printf("No predecessor in the sub-tree i.e. is above the current "
                   "node\n");
            return;
        }

        *node = (*node)->left;
        while (*node && (*node)->right) {
            *node = (*node)->right;
        }
    }

    int32_t delete_node(const T& val)
    {
        /* find node to delete and it's parent */
        node_ptr_t* curr = &_root;
        while (*curr != nullptr) {
            if (val == (*curr)->data) {
                break;
            }
            if (val > (*curr)->data) {
                curr = &(*curr)->right;
            } else {
                curr = &(*curr)->left;
            }
        }

        /* curr is the node to delete */
        if (!curr) {
            printf("ERROR: not found %d\n", val);
            return -ENODATA;
        }

        while (*curr) {
            /* if a leaf node, just delete */
            if (!(*curr)->left && !(*curr)->right) {
                *curr = nullptr;
                return 0;
            }

            /* find predecessor and swap and delete that guy */
            if ((*curr)->left && !(*curr)->right) {
                node_ptr_t* succ = curr;
                predecessor(curr);
                binary_search_tree::swap(*curr, *succ);
            }
            /* find successor and swap and delete that guy */
            else {
                node_ptr_t* pred = curr;
                successor(curr);
                binary_search_tree::swap(*pred, *curr);
            }
        }

        return 0;
    }
};

} // namespace ctci