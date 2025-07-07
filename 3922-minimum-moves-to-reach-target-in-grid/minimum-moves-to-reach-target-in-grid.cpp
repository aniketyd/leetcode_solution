class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        int cnt=0;
        while(tx>=sx&&ty>=sy){
            if(tx==sx&&ty==sy)return cnt;
            if(tx>=ty*2){
                if(tx%2==1)return -1;
                tx/=2;
            }
            else if(ty>=tx*2){
                if(ty%2==1)return -1;
                ty/=2;
            }
            else if(tx>ty){
                tx-=ty;
            }
            else if(ty>tx)
            ty-=tx;
            else{
                if(sx==0)
                tx=0;
                else if(sy==0)
                ty=0;
                else
                return -1;
            }
            cnt++;
        }
        return -1;
    }
};