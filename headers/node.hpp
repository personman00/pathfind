
class node;

#ifndef _NODE_H
#define _NODE_H

class node {

    public:
        int x, y;
        node(int x, int y);
        ~node();
        node * get_adj(int ind);
        void set_adj(node * ptr, int ind);
    private:
        //Adjacent nodes, not always garanteed to be initialized, up to user.
        //Also, this class does not handle the stored pointers here, rather wherever they are stored
        node * adj[8];

};

#endif