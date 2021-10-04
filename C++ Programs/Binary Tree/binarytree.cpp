#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class TreeNode{
public:
	int data;
	TreeNode *leftChild;
	TreeNode *rightChild;

	TreeNode(){data = 0; this->leftChild = nullptr; this->rightChild = nullptr;};
	TreeNode(int data){this->data = data; this->leftChild = nullptr; this->rightChild = nullptr;};
};

class Node{
public:
	int data;
	Node* next;

	Node(){data = 0; this->next = nullptr;};
	Node(int data){this->data = data;this->next=nullptr;};
};

TreeNode* buildTree(){
	int d;
	cin >> d;
	if(d==-1){
		return nullptr;
	}
	TreeNode* root = new TreeNode(d);
	root->leftChild = buildTree();
	root->rightChild=buildTree();

	return root;
}

void inOrder(TreeNode* root){
	if(root==nullptr)
		return;
	inOrder(root->leftChild);
	cout << root->data << " ";
	inOrder(root->rightChild);
}

int heightTree(TreeNode* root){
	if(root == nullptr)
		return 0;

	int leftheight = heightTree(root->leftChild);
	int rightheight = heightTree(root->rightChild);

	return 1 + max(leftheight, rightheight);
}


int countNodes(TreeNode* root){
	if(root == nullptr)
		return 0;

	int leftCount = countNodes(root->leftChild);
	int rightCount = countNodes(root->rightChild);

	return 1 + leftCount + rightCount;
}

int sumNodes(TreeNode* root){
	if(root == nullptr)
		return 0;

	int leftSum = sumNodes(root->leftChild);
	int rightSum = sumNodes(root->rightChild);

	return root->data + leftSum + rightSum;
}

int diameter(TreeNode* root){
	if(root == nullptr)
		return 0;

	int passRoot = heightTree(root->leftChild) + heightTree(root->rightChild);
	int onlyLeft = diameter(root->leftChild);
	int onlyRight = diameter(root->rightChild);

	return max(passRoot, max(onlyRight, onlyLeft));
}

pair<int, int> diameterOn(TreeNode* root){
	if(root == nullptr)
		return {0,0};
	pair<int, int> passRoot, onlyLeft, onlyRight;
	onlyLeft = diameterOn(root->leftChild);
	onlyRight = diameterOn(root->rightChild);
	passRoot.first = onlyLeft.second + onlyRight.second;
	passRoot.second = max(onlyLeft.second, onlyRight.second);


	return  { max(passRoot.first, max(onlyLeft.first, onlyRight.first)), passRoot.second+1};
}

int countKthLevel(TreeNode* root, int level){

	if(root == nullptr){
		return 0;
	}
	if(level == 1){
		return 1;
	}
	int cnt=0;
	cnt += countKthLevel(root->leftChild, level-1);
	cnt += countKthLevel(root->rightChild, level-1);
	return cnt;
}

int levelOrder(TreeNode* root){
	if(root == nullptr){
		return 0;
	}
	int maxwidth = 0;
	for(int i=1;i<=heightTree(root);i++){
		int cnt = countKthLevel(root, i);
		maxwidth = max(maxwidth, cnt);
	}
	return maxwidth;
}

pair<bool, int> checkBalance(TreeNode* root){
	if(!root){
		return {true, 0};
	}
	pair<bool, int> left = {true, 0}, right={true, 0};
	if(root->leftChild){
		left = checkBalance(root->leftChild);
	}
	if(root->rightChild){
		right = checkBalance(root->rightChild);
	}
	if(abs(left.second-right.second) > 1){
		return { false,  1+max(left.second, right.second) };
	}

	return { (left.first and right.first),  1+max(left.second, right.second) };
}


void breadthFirstIterate(TreeNode* root){
	queue<TreeNode*> q;
	if(root==nullptr)
		return;
	q.push(root);
	q.push(nullptr);
	int level=1;
	while(!q.empty()){
		TreeNode* temp = q.front();
		if(temp==nullptr){
			cout << endl;
			q.pop();
			if(q.empty())
				break;
			q.push(nullptr);
			continue;
		}
		if(temp->leftChild!=nullptr)
			q.push(temp->leftChild);
		if(temp->rightChild!=nullptr)
			q.push(temp->rightChild);


		cout << temp->data << " ";
		q.pop();
	}
}

int sumReplaceNodes(TreeNode* &root){
	if(root->leftChild==nullptr and root->rightChild==nullptr)
		return root->data;
	// root->data = 0;
	int leftData=0,rightData=0;
	if(root->leftChild){
		leftData += sumReplaceNodes(root->leftChild);
	}
	if(root->rightChild){
		rightData += sumReplaceNodes(root->rightChild);
	}
	int currdata = root->data;
	root->data = leftData+rightData;
	return currdata+root->data;
}

TreeNode* buildBalancedTree(vector<int> a, int l, int r){
	if(l>r){
		return nullptr;
	}
	int mid = (l+r)/2;
	TreeNode* root = new TreeNode(a[mid]);
	root->leftChild = buildBalancedTree(a, l, mid-1);
	root->rightChild = buildBalancedTree(a, mid+1, r);

	return root;
}

TreeNode* buildPreInTree(vector<int> pre, vector<int> ino, int inl, int inr){
	static int prei = 0;
	if(inl > inr || prei>=pre.size()){
		return nullptr;
	}
	int ipre;
	for(int i=inl; i<=inr;i++){
		if(ino[i] == pre[prei]){
			ipre = i;
			break;
		}
	}
	TreeNode* root = new TreeNode(pre[prei]);
	prei++;
	root->leftChild = buildPreInTree(pre, ino, inl, ipre-1);
	root->rightChild = buildPreInTree(pre, ino, ipre+1, inr);

	return root;
}

void preOrderIterative(TreeNode* root){
	stack<TreeNode*> st;
	TreeNode* curr=root;
	st.push(root);
	while(!st.empty()){
		curr = st.top();
		st.pop();
		cout << curr->data << " ";
		if(curr->rightChild!= nullptr)
			st.push(curr->rightChild);
		if(curr->leftChild!= nullptr)
			st.push(curr->leftChild);
	}
}

void inOrderIterativept2(TreeNode* root){
	stack<TreeNode*> st;
	TreeNode* curr=root;
	while(!st.empty() || curr!=nullptr){
		if(curr==nullptr){
			curr = st.top();
			cout << curr->data << " ";
			st.pop();
			curr = curr->rightChild;
		}
		else {
			
			st.push(curr);
			curr = curr->leftChild;
		}
	}
}



void rightView(TreeNode* root, int lev, int &maxlev){
	if(root == nullptr)
		return;
	if(lev>maxlev){
		cout << root->data << endl;
		maxlev = lev;
	}
	rightView(root->rightChild, lev+1, maxlev);
	rightView(root->leftChild, lev+1, maxlev);
}

void printAtLevelK(TreeNode* root, int k){
	if(root == nullptr)
		return;
	if(k==0){
		cout << root->data << " ";
		return;
	}
	printAtLevelK(root->leftChild, k-1);
	printAtLevelK(root->rightChild, k-1);

}

int printAtDistanceK(TreeNode* root, TreeNode* target, int k){
	if(root==nullptr){
		return -1;
	}
	if(root == target){
		printAtLevelK(target, k);
		return 0;
	}
	int DL = printAtDistanceK(root->leftChild, target, k);
	if(DL != -1){
		if(DL+1 == k){
			cout << root->data << " ";
		}
		else{
			printAtLevelK(root->rightChild, k-DL-2);
		}
		return DL+1;
	}
	int DR = printAtDistanceK(root->rightChild, target, k);
	if(DR != -1){
		if(DR+1 == k)
			cout << root->data << " ";
		else
			printAtLevelK(root->leftChild, k-DR-2);
		return DR+1;
	}
	return -1;
}

bool contains(TreeNode* root, TreeNode* node){
	if(root==nullptr)
		return false;
	if(root == node){
		return true;
	}
	bool leftpart = contains(root->leftChild, node);
	bool rightpart = contains(root->rightChild, node);
	return (leftpart||rightpart);
}

void leastCommonAncestor(TreeNode* root, TreeNode* node1, TreeNode* node2, TreeNode*& LCA){
	if(root == nullptr)
		return ;
	bool leftcontain1 = contains(root->leftChild, node1);
	bool leftcontain2 = contains(root->leftChild, node2);
	bool rightcontain1 = contains(root->rightChild, node1);
	bool rightcontain2 = contains(root->rightChild, node2);

	if(leftcontain1&&rightcontain2 || leftcontain2&&rightcontain1 || root==node1&&(leftcontain2||rightcontain2) || root==node2&&(leftcontain1||rightcontain1) || node1==node2&&root==node1){
		LCA = root;
		return ;
	}
	leastCommonAncestor(root->leftChild, node1, node2, LCA);
	leastCommonAncestor(root->rightChild, node1, node2, LCA);
}

TreeNode* lca(TreeNode* root, int a, int b){
	if(root == nullptr){
		return root;
	}
	if(root->data == a or root->data == b)
		return root;
	TreeNode* leftans = lca(root->leftChild, a, b);
	TreeNode* rightans = lca(root->rightChild, a, b);
	if(leftans and rightans)
		return root;
	return (leftans!=nullptr?leftans:rightans);
}

pair<int, int> maximumWeightInPath(TreeNode *root){
	if(root == nullptr){
		return {0, 0};
	}
	pair<int,int> left = maximumWeightInPath(root->leftChild);
	pair<int,int> right = maximumWeightInPath(root->rightChild);
	int case1 = left.second+root->data;
	int case2 = right.second+root->data;
	int case3 = left.second+root->data+right.second;
	int case4 = root->data;
	int maxi = max(case1, max(case2, max(case3, case4)));
	maxi = max(maxi, max(left.first, right.first));
	int maxbranch = max(case1, (case2, case4));
	return {maxi, maxbranch};
}
void preOrder(TreeNode* root){
	if(root == nullptr)
		return;
	cout << root->data << " ";
	preOrder(root->leftChild);
	preOrder(root->rightChild);
}

void postOrderIterative(TreeNode* root){
	stack<pair<TreeNode*, int>> st;
	pair<TreeNode*, int> curr = {root, 0};
	while(!st.empty() || curr.first!=nullptr){
		if(curr.first!=nullptr) {
			st.push({curr.first, 0});
			curr = {curr.first->leftChild, 0};
		}
		else{
			curr = st.top();
			if(curr.second == -1){
				cout << st.top().first->data << " ";
				st.pop();
				continue;
			}
			st.pop();
			st.push({curr.first, -1});
			curr = {curr.first->rightChild, 0};
		}
	}
}

bool isBST(TreeNode* root, int minv = INT_MIN, int maxv = INT_MAX){
	if(root == nullptr){
		return true;
	}
	return ((root->data>=minv and root->data<=maxv) 
		and isBST(root->leftChild, minv, root->data) 
		and isBST(root->rightChild, root->data, maxv));
}

pair<Node*, Node*> flatten(TreeNode* root){
	if(root == nullptr){
		return {nullptr, nullptr};
	}
	pair<Node*, Node*> lll = flatten(root->leftChild);
	pair<Node*, Node*> rll = flatten(root->rightChild);
	Node* node = new Node(root->data);
	if(lll.first == nullptr and rll.first == nullptr){
		return {node, node};
	}
	if(lll.first == nullptr){
		node->next = rll.first;
		return {node, rll.second};
	}
	if(rll.first == nullptr){
		lll.second->next = node;
		return {lll.first, node};
	}
	node->next = rll.first;
	lll.second->next = node;
	return {lll.first, rll.second};
}

void printLL(Node* head){
	while(head!=nullptr){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main(){

	int n;
	cin>>n;
	vector<int> a(n), b(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		// cout << a[i] << " ";
	}
	// for(int i=0;i<n;i++){
	// 	cin >> b[i];
	// 	cout << b[i] << " ";
	// }
	cout << endl << endl;
	TreeNode* root = buildBalancedTree(a, 0, n-1);
	// TreeNode* root = buildPreInTree(a, b, 0, n-1);
	inOrder(root);

	cout << endl << heightTree(root) << endl;
	// levelOrder(root);
	cout << endl;
	breadthFirstIterate(root);
	cout << endl;
	cout << endl;
	// cout << countNodes(root) << endl;
	// cout << sumNodes(root) << endl;
	// cout << levelOrder(root) << endl;

	// cout << diameter(root) << endl;
	// pair<int, int> p = diameterOn(root);
	// cout << p.first << " " << p.second << endl;

	// sumReplaceNodes(root);
	// breadthFirstIterate(root);
	// cout << checkBalance(root).first << " " << checkBalance(root).second << endl << endl;
	// int maxlev = 0;
	// rightView(root, 1, maxlev);
	// printAtDistanceK(root, root->leftChild->leftChild, 3);
	// TreeNode *node1 = root->rightChild->rightChild->rightChild->leftChild, *node2 = root->leftChild->rightChild->rightChild->leftChild, *LCA = nullptr;
	// leastCommonAncestor(root, node1, node2, LCA);
	// cout << node1->data << " " << node2->data;
	// cout << endl << LCA->data << endl;
	// cout << maximumWeightInPath(root).first << endl;
	// preOrder(root);
	cout << endl << endl;
	// postOrderIterative(root);
	cout << isBST(root) << endl;
	Node* head = flatten(root).first;
	printLL(head);
	return 0;
}



// 3 4 5 -1 -1 6 -1 -1 9 15 4 -1 -1 -1 -1
// 8 1 3 9 12 -1 -1 -1 13 -1 -1 4 17 -1 7 -1 -1 -1 22 14 -1 25 19 -1 -1 -1 15 -1 28 -1 -1

//1 2 3 4 8 5 6 7
// 3 2 8 4 1 6 7 5
