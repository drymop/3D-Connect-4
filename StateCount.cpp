#include <iostream>
#include <unordered_set>

#include "Board.h"

using connect4_3d::BoardState;
using std::cout;
using std::endl;

struct HashBoardState
{
  size_t operator()(const BoardState& state) const
  {
    return (state.boards[0] * 0xFFFFFFFFFFFFFFC5ULL + state.boards[1]) & 0xFFFF'FFFFUL;
  }
};

/// @return true it's a duplicate
bool doMove(std::unordered_set<BoardState, HashBoardState>& table, const BoardState& old_state, int move)
{
  BoardState states[8];
  states[0] = connect4_3d::move(old_state, move);
  states[1] = connect4_3d::rotateBoard90(states[0]);
  states[2] = connect4_3d::rotateBoard180(states[0]);
  states[3] = connect4_3d::rotateBoard180(states[1]);
  states[4] = connect4_3d::reflectBoard(states[0]);
  states[5] = connect4_3d::reflectBoard(states[1]);
  states[6] = connect4_3d::reflectBoard(states[2]);
  states[7] = connect4_3d::reflectBoard(states[3]);
  for (int i = 0; i < 8; i++)
    if (table.count(states[i]))
      return true;
  table.insert(states[0]);
  return false;
}


void bfs(const std::unordered_set<BoardState, HashBoardState>& prev_table,
               std::unordered_set<BoardState, HashBoardState>& curr_table)
{
  static const connect4_3d::Bitboard LAST_LAYER_INDEX = 1ULL << 48;

  unsigned long duplicate = 0;
  for (auto& state : prev_table) {
    if (connect4_3d::isWinning(state))
      continue;
    for (int move = 0; move < 16; move++) {
      if (!(state.boards[state.curr_player] & (LAST_LAYER_INDEX << move)))
        duplicate += doMove(curr_table, state, move);
    }
  }
  cout << "Duplicate: " << duplicate << endl;
}


int main(int argc, char const *argv[])
{
  std::unordered_set<BoardState, HashBoardState> table[64];
  
  BoardState inital_state;
  inital_state.curr_player = 0;
  inital_state.boards[0] = 0;
  inital_state.boards[1] = 0;
  table[0].insert(inital_state);

  for (int turn = 1; turn < 64; turn++) {
    cout << "TURN " << turn << endl;
    bfs(table[turn-1], table[turn]);

    cout << "Unique states: " << table[turn].size() << endl;
  }

  return 0;
}