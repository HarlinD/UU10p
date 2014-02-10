#include "polygon.h"
#include <cmath>
#include <iostream>

Polygon::Polygon( const Polygon& poly)
{
    // ha koll på antal hörn
    m_vertices = poly.m_vertices;
    polarea = poly.polarea;

    //allokera utrymme för poly
    m_vec = new Vertex[m_vertices];

    for( int i=0; i < m_vertices; i++)
    {
        m_vec[i] = poly.m_vec[i];
        std::cout << "\t" << "Kopiera polygon " << m_vec[i] << std::endl;
    }


}

Polygon::Polygon( Vertex* varray, int antal)
{

    //allokera utrymme för poly
    m_vec = new Vertex[antal];

    // registrera antal hörn
    m_vertices = antal;

    //spara polygonen
    for (int i=0; i < antal; i++)
    {
        m_vec[i] = varray[i];
        std::cout << "\t" << "Ny polygon" << m_vec[i] << std::endl;
    }
    calcPolArea();
    std::cout << "\t" << "Polygons area" << polarea << std::endl;
}

Polygon::~Polygon()
{
    delete [] m_vec;
}

void Polygon::add(Vertex nyvert)
{

    // Allokera minne för temp array
    Vertex *tmp = new Vertex[m_vertices];

    // kopiera nuvarande poly till temp arr
    for (int i=0; i < m_vertices; i++)
    {
        tmp[i] = m_vec[i];
    }

    //frigör poly minne
    delete[] m_vec ;

    //Lägg till ett hörn i polygonen
    m_vertices++;

    //Skapa utrymme för nya polygonen
    m_vec = new Vertex[m_vertices];


    // Låt m_poly peka på kopian
    m_vec = tmp;

    //Lägg till det senaste hörnet OBS nollräkning
    m_vec[m_vertices-1] = nyvert;


    //Frigör minnet från tmp
    delete[] tmp;

    calcPolArea();
}

double Polygon::calcPolArea()
{
    // Beräkna arean på polygonen
    double calcArea = 0;

    // Minst tre hörn...
    if (m_vertices>2)
    {
        // ha koll på antal hörn

        for (int i=0; i < (m_vertices-1) ; i++)
        {
            calcArea +=  (m_vec[i].x * m_vec[i+1].y - m_vec[i+1].x * m_vec[i].y);

        }


        calcArea += (m_vec[m_vertices-1].x * m_vec[0].y - m_vec[0].x * m_vec[m_vertices-1].y);
        calcArea = calcArea / 2;

    }


    polarea = std::abs(calcArea);

}

int Polygon::minx()
{


    int m = 0;
    for (int i=0; i < m_vertices; i++ )
    {
        if (m_vec[i].x < m)
            m = m_vec[i].x;
    }

    return m;

}

int Polygon::maxx()
{
    int m = 0;
    for (int i=0; i < m_vertices; i++)
    {
        if (m_vec[i].x > m)
            m = m_vec[i].x;
    }

    return m;

}

int Polygon::miny()
{
    int m = 0;
    for (int i=0; i < m_vertices; i++)
    {
        if (m_vec[i].y < m)
            m = m_vec[i].y;
    }

    return m;

}

int Polygon::maxy()
{
    int m = 0;
    for (int i=0; i < m_vertices; i++)
    {
        if (m_vec[i].y > m)
            m = m_vec[i].y;
    }

    return m;
}

int Polygon::numVertices()
{

    return m_vertices;
}

const Polygon & Polygon::operator=( const Polygon & poly)
{
    if ( &poly != this )
    {
        m_vertices = poly.m_vertices;
        polarea = poly.polarea;
        delete[] m_vec;
        m_vec = new Vertex[m_vertices];
        for( int i=0; i < m_vertices; i++)
        {
            m_vec[i] = poly.m_vec[i];

        }

    }
    return *this;
}

bool Polygon::operator<( const Polygon & poly ) const
{
    if( polarea < poly.polarea )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Polygon::operator==( const Polygon & poly ) const
{
    return poly.polarea == polarea;
}

std::ostream& operator<<( std::ostream& out, const Polygon& poly)
{
    // Skriv innehållet i polygonen till out
    for( int i = 0; i < poly.m_vertices; i++ )
    {
        out << poly.m_vec[i].x << " " << poly.m_vec[i].y;
    }
    //Lägg till arean
    out << '\t' << " area = " << poly.polarea;

    return out;
}
