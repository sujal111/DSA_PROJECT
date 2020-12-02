#include <bits/stdc++.h>
using namespace std;
class Leaderboard {
public:
   priority_queue< pair <int,int> > pq;
   map < int, int > m;
   Leaderboard() {
      m.clear();
      while(!pq.empty())pq.pop();
   }
   void addScore(int playerId, int score) {
      if(m.find(playerId)!=m.end()){
         m[playerId] += score;
      }
      else m[playerId] = score;;
         pq.push({m[playerId], playerId});
   }
   int top(int k) {
      vector < pair <int,int> > temp;
      int sum = 0;
      while(k){
         pair <int, int> curr = pq.top();
         pq.pop();
         if(m[curr.second] == curr.first){
            k--;
            sum += curr.first;
            temp.push_back(curr);
         }
      }
      for(int i = 0; i < temp.size(); i++)pq.push(temp[i]);
      return sum;
   }
   void reset(int playerId) {
      m[playerId] = 0;
   }
};
main(){
   Leaderboard ob;
   ob.addScore(1,73);
   ob.addScore(2,56);
   ob.addScore(3,39);
   ob.addScore(4,51);
   ob.addScore(5,4);
   cout <<ob.top(1) << endl;
   ob.reset(1);
   ob.reset(2);
   ob.addScore(2,51);
   cout <<ob.top(2) << endl;
}