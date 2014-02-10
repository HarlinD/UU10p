#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>

class Vertex
{
    public:
        Vertex();
        Vertex(int x, int y);
        ~Vertex();
        int x;
        int y;
    friend std::ostream& operator<<( std::ostream& out, const Vertex& vec );
    protected:
    private:

};

#endif // VERTEX_H
