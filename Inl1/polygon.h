#ifndef POLYGON_H
#define POLYGON_H

#include "vertex.h"

class Polygon
{
    public:
        Polygon();
        Polygon( Vertex* varray, int antal);
        ~Polygon();
        void add( Vertex nyvert);	                // Lägg till ett hörn på polygonen
        double area();				                // Beräkna arean av polygonen
        int minx();
        int maxx();
        int miny();
        int maxy();
        int numVertices();

        protected:
    private:
        Vertex* m_poly = 0;  		                // Variabel som vid konstruktion tilldelas minnesutrymme för en array av vertex
        int m_vertices;				                // Variabel som håller koll på antal hörn polygonen innehåller
};

#endif // POLYGON_H
