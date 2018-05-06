#include "Board.h"


namespace connect4_3d
{
  
  BoardState 
  move(const BoardState& _state, int _move)
  {
    BoardState new_state;
    new_state.curr_player = !_state.curr_player;
    new_state.boards[0] = _state.boards[0];
    new_state.boards[1] = _state.boards[1];

    Bitboard both_board = _state.boards[0] | _state.boards[1];

    for (int i = _move; i < 64; i += 16)
    {
      if ((both_board >> i & 1ULL) == 0)
      {
        new_state.boards[_state.curr_player] |= 1ULL << i;
        return new_state;
      }
    }

    new_state.curr_player = !new_state.curr_player;
    return new_state;
  }

  bool 
  isWinning(const BoardState& _state)
  {
    Bitboard brd = _state.boards[!_state.curr_player];

    return
    // win in a straight line
      // 16 rows
      (brd & brd >> 1  & brd >> 2  & brd >> 3  & 0x1111'1111'1111'1111ULL) | 
      // 16 cols
      (brd & brd >> 4  & brd >> 8  & brd >> 12 & 0x000f'000f'000f'000fULL) |
      // 16 stacks 
      (brd & brd >> 16 & brd >> 32 & brd >> 48 & 0x0000'0000'0000'ffffULL) |
    // win in a diagonal
      // 8 in horizontal planes
      (brd & brd >> 5  & brd >> 10 & brd >> 15 & 0x0001'0001'0001'0001ULL) |
      (brd & brd >> 3  & brd >> 6  & brd >> 9  & 0x0008'0008'0008'0008ULL) |
      // 16 in vertical planes
      (brd & brd >> 17 & brd >> 34 & brd >> 51 & 0x0000'0000'0000'1111ULL) |
      (brd & brd >> 15 & brd >> 30 & brd >> 45 & 0x0000'0000'0000'8888ULL) |
      (brd & brd >> 20 & brd >> 40 & brd >> 60 & 0x0000'0000'0000'000fULL) |
      (brd & brd >> 12 & brd >> 24 & brd >> 36 & 0x0000'0000'0000'f000ULL) |
      // 4 in diagonal planes
      (brd & brd >> 21 & brd >> 42 & brd >> 63 & 0x0000'0000'0000'0001ULL) |
      (brd & brd >> 11 & brd >> 22 & brd >> 33 & 0x0000'0000'0000'8000ULL) |
      (brd & brd >> 19 & brd >> 38 & brd >> 57 & 0x0000'0000'0000'0008ULL) |
      (brd & brd >> 13 & brd >> 26 & brd >> 39 & 0x0000'0000'0000'1000ULL);
  }

}