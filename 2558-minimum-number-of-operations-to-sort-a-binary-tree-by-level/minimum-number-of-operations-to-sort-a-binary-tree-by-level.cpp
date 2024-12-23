class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        int swaps = 0;

        // Process tree level by level using BFS
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<pair<int, int>> nodes(levelSize);

            // Store node values with their original positions
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();

                // Store the value and its position in the pair
                nodes[i] = {node->val, i};

                if (node->left != nullptr) queue.push(node->left);
                if (node->right != nullptr) queue.push(node->right);
            }

            // Sort nodes by their values
            sort(nodes.begin(), nodes.end());

            // Count swaps needed to match indices with original positions
            for (int i = 0; i < levelSize; i++) {
                while (nodes[i].second != i) {
                    // Swap the current element with the one at its target position
                    swap(nodes[i], nodes[nodes[i].second]);
                    swaps++;
                }
            }
        }
        return swaps;
    }
};
