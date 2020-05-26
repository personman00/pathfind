
class map;

#ifndef _MAP_H
#define _MAP_H

#include <vector>
#include "node.hpp"
#include <cstdlib>

using namespace std;

//Basic "map" implementation, basically stores a bunch of nodes.
//Also ensures nodes have the correct adjacent nodes
//Implies that all nodes are constant in their placement
class map {
    public:
        map(int size); 
        ~map();
        node* get_node(int i, int j);
        bool is_valid(const int & i, const int & j);
    private:
        const int size;
        vector<vector<node*>> internal_map;
};

#endif