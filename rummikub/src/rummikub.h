#ifndef RUMMIKUB_H
#define RUMMIKUB_H
#include <fstream>
#include <vector>
#include <iostream>

enum Color { Red, Green, Blue, Yellow };


struct Tile {
	int     denomination;
	Color   color;
};

std::ostream& operator<<(std::ostream& os, Tile const& t) {
	os << "{ " << t.denomination << ",";
	switch (t.color) {
	case Red:      os << "R"; break;
	case Green:    os << "G"; break;
	case Blue:     os << "B"; break;
	case Yellow:   os << "Y"; break;
	}
	os << " }";
	return os;
}


class RummiKub {
public:
	enum class ActionType
	{
		  ADD_TO_RUN
		, ADD_TO_GROUP
		, NEW_RUN
		, NEW_GROUP
	};
	struct Action
	{
		ActionType type;
		int index; 
	};

	RummiKub(); // empty hand
	void Add(Tile const&); // add a tile to hand

	void Solve(); // solve

	std::vector<Action> GetOptions(int hand_index);

	// get solution - groups
	std::vector< std::vector< Tile > > GetGroups() const { return groups; }
	// get solution - runs
	std::vector< std::vector< Tile > > GetRuns() const { return runs; }
	// if both vectors are empty - no solution possible
private:
	bool CanAddToRun(int run_index, const Tile& tile);
	bool CanAddToGroup(int group_index, const Tile& tile);
	bool IsRunValid(const std::vector<Tile>& run);
	bool IsGroupValid(const std::vector<Tile>& group);

	bool solve(int hand_index);

	std::vector< Tile > hand;

	std::vector<std::vector< Tile >> groups;
	std::vector<std::vector< Tile >> runs;

};

#endif
