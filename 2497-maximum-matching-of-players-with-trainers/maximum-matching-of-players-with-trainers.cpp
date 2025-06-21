class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int p = 0;  // pointer for players
        int t = 0;  // pointer for trainers
        int count = 0; 
        while(p < players.size() && t < trainers.size())
        {
            if(players[p] <= trainers[t]) 
            {
                count++;
                p++;
            }
            t++;
        }

        return count;
    }
};