struct Node{
    Node* links[2];
};
class Trie {
    public:
    Node *root=new Node();
    void insert(int a){
        vector<int>bit(32);
        for(int i=31;i>=0;i--){
            if(a&1){
                bit[i]=1;
            }
            a/=2;
            if(a==0)break;
        }
        Node *nd=root;
        for(int i=0;i<32;i++){
               if(nd->links[bit[i]]==NULL)
               nd->links[bit[i]]=new Node();
               nd=nd->links[bit[i]];
        }
    }
    int search(int a){
        vector<int>bit(32,1);
        for(int i=31;i>=0;i--){
            if(a&1){
                bit[i]=0;
            }
            a/=2;
            if(a==0)break;
        }
        Node *nd=root;
        int val=0;
        for(int i=0;i<32;i++){
             if(nd->links[bit[i]]!=NULL){
                val+=bit[i]*(1<<(31-i));
                nd=nd->links[bit[i]];
             }
             else{
                val+=(1-bit[i])*(1<<(31-i));
                nd=nd->links[1-bit[i]];
             }
        }
        return val;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie tr;
        for(int i=0;i<n;i++){
            tr.insert(nums[i]);
        }
        int mx=0;
        for(int i=0;i<n;i++){
            int v=tr.search(nums[i]);
            mx=max(mx,v^nums[i]);
        }
        return mx;
    }
};