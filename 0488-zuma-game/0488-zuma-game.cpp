class Solution {
public:
    string reducing(string s){
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(j < s.size() && s[j] == s[i]) j++;

            if(j-i >= 3){
                s.erase(i, j-i);
                i=0;
            }
            else i++;
        }
        return s;
    }

    int findMinStep(string board, string hand) {
        sort(hand.begin(), hand.end());

        queue<tuple<string, string, int>> q; //{board, hand, steps}
        q.push({board, hand, 0});

        unordered_set<string> vis;
        vis.insert(board+"#"+hand); //mark visited

        while(!q.empty()){
            auto [cur_board, cur_hand, steps] = q.front();
            q.pop();

            for(int i = 0; i < cur_hand.size(); i++){
                if(i > 0 && cur_hand[i] == cur_hand[i-1]) continue;

                char c = cur_hand[i];
                string nxt_hand = cur_hand.substr(0, i) + cur_hand.substr(i+1);

                for(int j = 0; j <= cur_board.size(); j++){
                    bool same = (j < cur_board.size() && cur_board[j] == c);

                    bool split_two = (j > 0 && j < cur_board.size() && cur_board[j-1] == cur_board[j] && cur_board[j] != c);

                    if(!same && !split_two) continue;

                    string nxt_board = cur_board.substr(0, j) + c + cur_board.substr(j);
                    nxt_board = reducing(nxt_board);

                    if(nxt_board.empty()) return steps+1;

                    string state = nxt_board + "#" + nxt_hand;
                    if(!vis.count(state)){
                        vis.insert(state);
                        q.push({nxt_board, nxt_hand, steps+1});
                    }
                }
            }
        }

        return -1;
    }
};