#ifndef BOARD_H_
#define BOARD_H_

#include <cstdint>

namespace connect4_3d
{
  typedef uint_fast64_t Bitboard;

  typedef bool Player;

  typedef struct BoardState
  {
    Player   curr_player;
    Bitboard boards[2];

    bool operator==(const BoardState& other) const
    {
      return (boards[0] == other.boards[0] && boards[1] == other.boards[1]);
    }

  } BoardState;

  //////////////////////////////////////////////////////////////////////////////
  /// @param  _state the current state of the board
  /// @param  _move  the move made, range between 0 to 15
  /// @return the new state of the board
  //////////////////////////////////////////////////////////////////////////////
  BoardState move(const BoardState& _state, int _move);

  bool isWinning(const BoardState& _state);

  BoardState rotateBoard90(const BoardState& state);

  BoardState rotateBoard180(const BoardState& state);

  BoardState reflectBoard(const BoardState& state);
}


#endif
