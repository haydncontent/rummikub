#include "rummikub.h"

RummiKub::RummiKub()
{
}

void RummiKub::Add(Tile const&)
{

}

void RummiKub::Solve()
{

}

std::vector<std::vector<Tile>> RummiKub::GetGroups() const
{
	return std::vector<std::vector<Tile>>();
}

std::vector<std::vector<Tile>> RummiKub::GetRuns() const
{
	return std::vector<std::vector<Tile>>();
}

bool RummiKub::solve()
{
   // base case
   // out of tiles - check if runs and groups are legal
   // return true if yest and exit

    Action actions[] = GetOptions();

    // for debugging
    // print current tile and table 
    std::cout << "\n=====================================================\n";
    std::cout << "table: current tile " << tile << "\n";
    for (auto const& g : groups) {
        std::cout << "(G( ";
        for (auto const& t : g) { std::cout << t << " "; }
        std::cout << " )))\n";
    }
    for (auto const& r : runs) {
        std::cout << "(R( ";
        for (auto const& t : r) { std::cout << t << " "; }
        std::cout << " )))\n";
    }


    for (auto action : actions) {
        //if action is legal execute it
        //    bool result = solve(...); // recursive call
        //if solved - return true; // stop recursion
        //undo the action
    }

    return false; // could not find place for current tile - backtrack
}
