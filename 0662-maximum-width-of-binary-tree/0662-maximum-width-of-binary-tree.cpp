/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {     
        if(!root)
            return 0;
        
        int answer = 0;

        //Queue to store current level's nodes and their indices
        queue<pair<TreeNode*, int>> nodesQueue;
        //we'll be using 0-based indexing
        nodesQueue.push({root, 0});

        while(!nodesQueue.empty()){
            int queueSize = nodesQueue.size();

            //save the minimum index of the current level
            int minIndex = nodesQueue.front().second;

            //used to calculate width of the current level
            int firstIndex, lastIndex;

            //iterate over all nodes of the current level
            for(int levelIndex=0; levelIndex<queueSize; levelIndex++)
            {
                //(Only) This needs to be long long because it'll be multiplied with 2
                long long currIndex = nodesQueue.front().second - minIndex;

                //save index of the first node of this level
                if(levelIndex == 0)
                    firstIndex = currIndex;

                //save index of the last node of this level
                if(levelIndex == queueSize-1)
                    lastIndex = currIndex;

                TreeNode* currNode = nodesQueue.front().first;
                nodesQueue.pop();

                if(currNode->left)
                    nodesQueue.push({currNode->left, 2*currIndex+1});

                if(currNode->right)
                    nodesQueue.push({currNode->right, 2*currIndex+2});
            }

            //save the longest width amongst all level's widths
            answer = max(answer, lastIndex - firstIndex + 1);
        }

        return answer;

    }
};