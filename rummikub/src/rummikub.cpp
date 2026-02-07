#include "rummikub.h"

RummiKub::RummiKub()
{
}

void RummiKub::Add(Tile const& tile)
{
    hand.push_back(tile);
}

void RummiKub::Solve()
{

}

std::vector<RummiKub::Action> RummiKub::GetOptions(int hand_index)
{
    std::vector < RummiKub::Action > actions;



    for (const std::vector<Tile> & group : groups)
    {

    }



    return std::vector<Action>();
}

bool RummiKub::CanAddToRun(int run_index, const Tile& tile)
{
    if (runs[run_index].empty()) return true;

    if (runs[run_index][0].color != tile.color) return false;

    for (const auto& t : runs[run_index])
        if (t.denomination == tile.denomination) return false;

    return true;
}

bool RummiKub::CanAddToGroup(int group_index, const Tile& tile)
{
    if (groups[group_index].empty()) return true;

    if (groups[group_index][0].denomination != tile.denomination) return false;

    for (const auto& t : groups[group_index])
        if (t.color == tile.color) return false;

    return true;
}

bool RummiKub::IsRunValid(const std::vector<Tile>& run)
{
    if (run.empty()) return false;
    if (run.size() < 3) return false;

    Color run_color = run[0].color;
    for (const auto& tile : run)
        if (tile.color != run_color) return false;

    bool present_denoms[13] = { false };
    for (const auto& tile : run)
    {
        int denom = tile.denomination;
        if (present_denoms[denom]) return false; 
        present_denoms[denom] = true;
    }
    
    int segment_len = 0;
    for (int i = 0; i <= 12; ++i)
    {
        if (present_denoms[i])
        {
            ++segment_len;
        } 
        else
        {
            if (segment_len > 0 && segment_len < 3) return false;
            segment_len = 0;
        }
    }
    if (segment_len > 0 && segment_len < 3) return false;

    return true;
}

bool RummiKub::IsGroupValid(const std::vector<Tile>& group)
{
    if (group.empty()) return false;
    if (group.size() < 3 || group.size() > 4) return false;

    int group_denom = group[0].denomination;
    // enum Color { Red, Green, Blue, Yellow };
    bool used_colors[4] = { false };
    for (const auto& tile : group)
    {
        if (tile.denomination != group_denom) return false;

        if (used_colors[tile.color]) return false;
        else used_colors[tile.color] = true;
    }

    return true;
}

bool RummiKub::solve(int hand_index)
{
   // base case
   // out of tiles - check if runs and groups are legal
   // return true if yest and exit

    //Action actions[] = GetOptions();

    //// for debugging
    //// print current tile and table 
    //std::cout << "\n=====================================================\n";
    //std::cout << "table: current tile " << tile << "\n";
    //for (auto const& g : groups) {
    //    std::cout << "(G( ";
    //    for (auto const& t : g) { std::cout << t << " "; }
    //    std::cout << " )))\n";
    //}
    //for (auto const& r : runs) {
    //    std::cout << "(R( ";
    //    for (auto const& t : r) { std::cout << t << " "; }
    //    std::cout << " )))\n";
    //}


    //for (auto action : actions) {
    //    //if action is legal execute it
    //    //    bool result = solve(...); // recursive call
    //    //if solved - return true; // stop recursion
    //    //undo the action
    //}



    return false; // could not find place for current tile - backtrack
}
