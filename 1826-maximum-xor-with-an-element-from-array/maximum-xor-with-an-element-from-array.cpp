
struct Node{
    Node* links[2];
};
class Trie {
    public:
    Node *root;
    Trie(){
root=new Node();
    }
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<tuple<int,int,int>>v;
        for(int i=0;i<queries.size();i++){
            v.push_back(make_tuple(queries[i][1],queries[i][0],i));
        }
        sort(v.begin(),v.end());
        Trie tr;
        vector<int>ans(queries.size());
        int j=0;
        for(int i=0;i<v.size();i++){
            while(j<n&&get<0>(v[i])>=nums[j]){
                tr.insert(nums[j]);
                j++;
            }
            if(j!=0){
           int val= tr.search(get<1>(v[i]));
           ans[get<2>(v[i])]=val^get<1>(v[i]);}
           else
           ans[get<2>(v[i])]=-1;
        }
        return ans;
    }
};