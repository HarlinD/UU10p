#include "polygon.h"
#include <cmath>
#include <iostream>

Polygon::Polygon( const Polygon& poly)
{
    // ha koll p� antal h�rn
    m_vertices = poly.m_vertices;
    polarea = poly.polarea;

    //allokera utrymme f�r poly
    m_vec = new Vertex[m_vertices];

    for( int i=0; i < m_vertices; i++)
    {
        m_vec[i] = poly.m_vec[i];
        std::cout << "\t" << "Kopiera polygon " << m_vec[i] << std::endl;
    }


}

Polygon::Polygon( Vertex* varray, int antal)
{

    //allokera utrymme f�r poly
    m_vec = new Vertex[antal];

    // registrera antal h�rn
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

    // Allokera minne f�r temp array
    Vertex *tmp = new Vertex[m_vertices];

    // kopiera nuvarande poly till temp arr
    for (int i=0; i < m_vertices; i++)
    {
        tmp[i] = m_vec[i];
    }

    //frig�r poly minne
    delete[] m_vec ;

    //L�gg till ett h�rn i polygonen
    m_vertices++;

    //Skapa utrymme f�r nya polygonen
    m_vec = new Vertex[m_vertices];


    // L�t m_poly peka p� kopian
    m_vec = tmp;

    //L�gg till det senaste h�rnet OBS nollr�kning
    m_vec[m_vertices-1] = nyvert;


    //Frig�r minnet fr�n tmp
    delete[] tmp;

    calcPolArea();
}

double Polygon::calcPolArea()
{
    // Ber�kna arean p� polygonen
    double calcArea = 0;

    // Minst tre h�rn...
    if (m_vertices>2)
    {
        // ha koll p� antal h�rn

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
    // Skriv inneh�llet i polygonen till out
    for( int i = 0; i < poly.m_vertices; i++ )
    {
        out << poly.m_vec[i].x << " " << poly.m_vec[i].y;
    }
    //L�gg till arean
    out << '\t' << " area = " << poly.polarea;

    return out;
}
