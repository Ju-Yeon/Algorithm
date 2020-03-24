#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class node{
public:
    int x, y, idx;
    node *left, *right;
private:
    node(int x, int y, int idx): x(x), y(y), idx(idx), left(NULL), right(NULL){}
    friend class binary_tree ;
};

class binary_tree{
public:
    node * root;
    vector<vector<int>> answer = {{},{}};

    binary_tree(vector<vector<int>> nodeinfo):root(NULL){
        for(int i = 0; i< nodeinfo.size(); i++) {
            //cout << nodeinfo[i][2] << " : " << nodeinfo[i][0] << ", " << nodeinfo[i][1] << endl;
            insert(nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2]);
        }
    }

private:
    void insert(int x, int y, int idx){
        node *elem = new node(x, y, idx);
        if(!this->root){
            root = elem;
        }else{
            subInsert(this->root, elem);
        }
        return;
    }

    void subInsert(node *root, node *elem){

        if(root->x > elem->x){
            if(root->left == NULL)root->left = elem;
            else subInsert(root->left, elem);
        }else{
            if(root->right == NULL)root->right = elem;
            else subInsert(root->right, elem);
        }
        return ;
    }

public:
    void preorder(node *elem){
        //cout<<elem->idx<<endl;
        this->answer[0].push_back(elem->idx);
        if(elem->left) preorder(elem->left);
        if(elem->right) preorder(elem->right);
    }

    void postorder(node *elem){
        if(elem->left)postorder(elem->left);
        if(elem->right)postorder(elem->right);
        //cout<<elem->idx<<endl;
        this->answer[1].push_back(elem->idx);
    }
    friend class node ;
};

bool compare(vector<int> a, vector<int> b){

    if(a[1]>b[1]){
        return true;
    }else if(a[1]<b[1]){
        return false;
    }else{
        if(a[0]<b[0]) return true;
        else return false;
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    for(int i = 0; i < nodeinfo.size(); i++)
        nodeinfo[i].push_back(i+1);

    sort(nodeinfo.begin(), nodeinfo.end(), compare);
    binary_tree BT(nodeinfo);

    BT.preorder(BT.root);
    BT.postorder(BT.root);

    return BT.answer;
}

 int main(){
     vector<vector<int>> nodeinfo = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
     solution(nodeinfo);
 }


