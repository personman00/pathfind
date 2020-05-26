#include "node.hpp"

node::node(int x, int y): x(x), y(y) {}
node::~node() {}

bool is_valid(int & ind) {
    return ind > 0 && ind < 6; 
}

node* node::get_adj(int ind) {
    if(!is_valid(ind)) {
        return nullptr;
    }
    return this->adj[ind];
}

void node::set_adj(node* node_ptr, int ind) {
    if(!is_valid(ind)) {
        return; 
    }
    this->adj[ind] = node_ptr; 
}
