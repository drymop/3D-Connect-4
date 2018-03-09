#include<iostream>
#include<vector>
#include<chrono>
#include<random>

using namespace std;

int main(int argc, char const *argv[])
{

	vector<vector<vector<int> > > environment;
	string players[2];
	vector<vector<int> > moves;
	vector<int> who_played;

	cout	<< "Welcome to 3D connect-4 (R)!"
		<< "\nPlease input the username of players 1 & 2 separated by whitespace.";

	cin	>> players[0] >> players[1];

	cout	<< "Making arbitrary choice of who goes first.\n\t"
		<< players[rand()%2] << " gets to go.";

	while (! false /* bool won(environment)*/)
		//get_next_move(who_played.last()+1 % 2)

		vector<int> last_move;

		// code to generate 3D rendering here

	//	moves.add()
	//	cout	<<

	return 0;
}
