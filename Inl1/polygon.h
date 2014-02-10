#ifndef POLYGON_H
#define POLYGON_H

#include "vertex.h"

class Polygon
{
    public:
        Polygon();
        Polygon( Vertex* varray, int antal);
        ~Polygon();
        void add( Vertex nyvert);	                // L�gg till ett h�rn p� polygonen
        double area();				                // Ber�kna arean av polygonen
        int minx();
        int maxx();
        int miny();
        int maxy();
        int numVertices();

        protected:
    private:
        Vertex* m_poly = 0;  		                // Variabel som vid konstruktion tilldelas minnesutrymme f�r en array av vertex
        int m_vertices;				                // Variabel som h�ller koll p� antal h�rn polygonen inneh�ller
};

#endif // POLYGON_H
