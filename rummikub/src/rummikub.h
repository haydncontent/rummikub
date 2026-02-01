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
    os << "{ "<< t.denomination << ",";
    switch ( t.color ) {
        case Red:      os << "R"; break;
        case Green:    os << "G"; break;
        case Blue:     os << "B"; break;
        case Yellow:   os << "Y"; break;
    }
    os << " }";
    return os;
}

/*
Group: a sequence
1) of 3 or 4 tiles
2) same denominations
3) no tiles of the same color
Legal
3 - R 3 - B 3 - G
12 - R 12 - B 12 - G 12 - Y
Illegal
3 - R 3 - B too short
3 - R 3 - B 4 - G not the same denomination
12 - R 12 - B 12 - G 12 - G - same color used twice or more times
*/

/*
Run (classical): a sequence
1) of 3 or more tiles
2) all tiles have the same color
3) denomination are consecutive
Examples:
Legal
2-R 3-R 4-R
4-B 5-B 6-B 7-B 8-B
Illegal
2-R 3-R - too short
4-B 5-B 6-B 7-R - not the same color

I'll use a slightly generalized definition of a run:
a run is a sequence that is made of several classical runs of the same color.

Legal:
2-R 3-R 4-R 7-R 8-R 9-R (two classical runs)
Illegal
2-R 3-R 4-R 7-G 8-G 9-G (not same color)
*/

/*
Algorithm:
brute-force recursion: for each next tile you have the following options
1) add it to an existing run with the same color as tile and tile's denomination is not yet in the run
2) add it to an existing group with the same denomiation as tile and tile's color is not yet in the group
3) create a new run
4) create a new group
*/

class RummiKub {
    public:
        RummiKub(); // empty hand
        void Add( Tile const& ); // add a tile to hand

        void Solve(); // solve

        // get solution - groups
        std::vector< std::vector< Tile > > GetGroups() const;
        // get solution - runs
        std::vector< std::vector< Tile > > GetRuns() const;
        // if both vectors are empty - no solution possible
    private:
        bool solve();

    private:
        std::vector< std::vector< Tile > > groups;
        std::vector< std::vector< Tile > > runs;

};

#endif
