#include "map.hpp"

bool map::is_valid(const int & i, const int & j) {
    return (i > 0 && i < size) && (j > 0 && j < size); 
}

map::map(const int size): size(size) {

    for(int i = 0; i < size; i++) {
        vector<node*> column;
        this->internal_map.push_back(column);
        for(int j = 0; j < size; j++) {
            column.push_back(new node(i, j));
        }
    }

    //The positions relative to each node that are considered 'adjacent'
    using P = std::pair<int, int>;
    vector< P > views = {
        P(1, 0),
        P(0, 1),
        P(-1, 0),
        P(0, -1)
    };

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            node* p_node = get_node(i, j);
            int i = 0;
            for( P v : views ) {
                node* c_node = get_node(i + v.first, j + v.second);
                p_node->set_adj(c_node, ++i);
            }
        }
    }

}

map::~map() {
    for(vector<node*> a : this->internal_map) {
        a.erase(a.begin(), a.end());
    }
}

node* map::get_node(int i, int j) {
    if(!is_valid(i, j)) {
        return nullptr;
    }
    return this->internal_map.at(i).at(j);
}