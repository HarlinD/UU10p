#include "vertex.h"

#include <iostream>
#include <ostream>


Vertex::Vertex() : x(0), y(0)
{ }

Vertex::Vertex(int ny_x, int ny_y) : x(ny_x), y(ny_y)
{ std::cout << "\t" << "Ny vertex" << x << " " << y << std::endl; }

Vertex::~Vertex()
{
    //dtor
}

std::ostream& operator<<( std::ostream& out, const Vertex& vec )
{
    out << "Utskrift av vertex-innehåll (" << vec.x << ", " << vec.y << ")" << std::endl;

    return out;
}
