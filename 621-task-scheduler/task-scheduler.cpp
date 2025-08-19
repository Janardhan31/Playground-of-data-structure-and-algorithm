class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        for(auto it : tasks){
            mp[it-'A']++;
        }
        priority_queue<int> pq;
        for(auto it : mp){
            if(it > 0){

            pq.push(it);
            }
        }
        int time = 0;
        while(!pq.empty()){
            vector<int> tmp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    tmp.push_back(freq);
                    cout<<freq<<endl;
                }
            }

            for(auto it : tmp){
                if(it > 0){
                    pq.push(it);
                }
            }
            if(pq.empty()){
                time += tmp.size();
            }else{
                time += n+1;
            }
        }
        return time;
    }
};