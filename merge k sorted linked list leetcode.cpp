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

typedef pair<int , ListNode *> p;
class Solution {
public:
    ListNode *buildList(vector<int> ans , int idx){
        if(idx >= ans.size()){
            return NULL;
        }
        ListNode *root = new ListNode(ans[idx]);
        root->next = buildList(ans , idx+1);
        return root;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() <= 0){
            return NULL;
        }
        priority_queue<p , vector<p> , greater<p>> pq;
        for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i] != NULL)
                pq.push( {lists[i]->val , lists[i]->next} );
        }
        vector<int> ans;
        while(!pq.empty()){
            p x = pq.top();
            pq.pop();
            ans.push_back(x.first);
            if(x.second != NULL){
                pq.push({x.second->val , x.second->next});
            }
        }
        
        ListNode *root = buildList(ans , 0);
        return root;
    }
};
