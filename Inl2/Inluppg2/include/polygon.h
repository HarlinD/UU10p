#ifndef POLYGON_H
#define POLYGON_H

#include "vertex.h"

class Polygon
{
    public:
        Polygon() : m_poly(0), m_vertices(0), polarea(0) {};
        Polygon( Vertex* varray, int antal);
        Polygon( const Polygon& poly);
        ~Polygon();

        void add( Vertex nyvert);	                                                                    // L�gg till ett h�rn p� polygonen
        double area() const { return polarea; };                                               // Returnera arean av polygonen
        const Polygon & operator=( const Polygon & poly);
        bool operator<( const Polygon & poly) const;
        bool operator==( const Polygon & poly) const;
        bool operator!=( const Polygon & poly) const { return !(*this == poly); }
        bool operator>( const Polygon & poly) const { return poly < *this; }
        bool operator>=( const Polygon & poly) const { return !(*this<poly); }
        bool operator<=( const Polygon & poly) const { return !(poly<*this); }
        friend ostream& operator<<(ostream& out, const Polygon& poly);

        int minx();
        int maxx();
        int miny();
        int maxy();
        int numVertices();

        protected:
    private:
        Vertex* m_poly = 0;  		                // Variabel som vid konstruktion tilldelas minnesutrymme f�r en array av vertex
        int m_vertices;				                // Variabel som h�ller koll p� antal h�rn polygonen inneh�ller
        double polarea;
        void calcPolArea();
};

#endif // POLYGON_H
