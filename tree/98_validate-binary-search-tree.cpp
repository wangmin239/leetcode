class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        deque<TreeNode*> level;
        level.push(root);
		
		while (level.empty() != true) {
			int size = level.size();
			res.emplace_back({});
			while (size-- > 0) {
				auto node = level.front();
				level.pop_front();
				auto [val, left, right] = *node;
				res.back().push_back(val);
				
				if (left != nullptr) {
					level.push_back(left);
				}

				if (right != nullptr) {
					level.push_back(right);
				}
				
			}
		}
		return res;
    }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
		ListNode dummyHead(INT_MIN);
		
		while (head != nullptr) {
			ListNode *node = new ListNode(head->val);
			ListNode *pre = &dummyHead;	
			ListNode *p = pre;
			while (p != nullptr) {
				if (head->val > p->val) {
					pre = p;
					p = p->next;
				} else {
					break;
				}					
			}
			node->next = p;
			pre->next = node;
			head = head->next;
		}
		
		return dummyHead.next;
    }
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
		stack<TreeNode*> st;
		int preVal = INT_MIN;
		while (root != nullptr || st.empty() != true) {
			if (root != nullptr) {
				st.push(root);
				root = root->left;
			} else {
				root = st.top();
				st.pop();
				auto [val, left, right] = *root;
				if (preVal >= val) {
					return false;
				} else {
					preVal = val;
				}
				root = right;			
			}
		}
		return true;
    }
};

class Solution {
public:
    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || root -> val >= upper) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}
		auto [val, left, right] = *root;
		bool bigThanLeft = true;
		bool lessThanRight = true;
		if (left != nullptr) {
			bigThanLeft = val > left->val;
		}
		if (right != nullptr) {
			lessThanRight = val < right->val;
		}
		
		return bigThanLeft && lessThanRight && isValidBST(left) && isValidBST(right);
    }
};