#include "polygon.h"
#include <cmath>
#include <iostream>

Polygon::Polygon(const Polygon& poly)
{
    // ha koll på antal hörn
    m_vertices = poly.m_vertices;
    polarea = poly.polarea;

    //allokera utrymme för poly
    m_poly = new Vertex[m_vertices];

    for( int i=0; i < m_vertices;i++)
    {
        m_poly[i] = poly.m_poly[i];
    }


}

Polygon::Polygon( Vertex* varray, int antal)
{

	//allokera utrymme för poly
    m_poly = new Vertex[antal];

    // registrera antal hörn
    m_vertices = antal;

    //spara polygonen
    for (int i=0;i < antal;i++)
    {
            m_poly[i] = varray[i];
    }

}

Polygon::~Polygon()
{
    delete [] m_poly;
}

 void Polygon::add(Vertex nyvert)
 {

    // Allokera minne för temp array
   	Vertex *tmp = new Vertex[m_vertices];

    // kopiera nuvarande poly till temp arr
    for (int i=0;i < m_vertices;i++)
            {
            	tmp[i] = m_poly[i];
        	}

    //frigör poly minne
    delete[] m_poly;

    //Lägg till ett hörn i polygonen
    m_vertices++;

    //Skapa utrymme för nya polygonen
    m_poly = new Vertex[m_vertices];


    // Låt m_poly peka på kopian
    m_poly = tmp;

    //Lägg till det senaste hörnet OBS nollräkning
    m_poly[m_vertices-1] = nyvert;


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
    {// ha koll på antal hörn
    m_vertices = poly.size;
            for (int i=0;i < (m_vertices-1) ;i++)
            {
                calcArea +=  (m_poly[i].x * m_poly[i+1].y - m_poly[i+1].x * m_poly[i].y);

            }


            calcArea += (m_poly[m_vertices-1].x * m_poly[0].y - m_poly[0].x * m_poly[m_vertices-1].y);
            calcArea = calcArea / 2;

    }


    polarea = std::abs(calcArea);

}

int Polygon::minx()
{


	int m = 0;
    for (int i=0; i < m_vertices; i++ )
        {
        	if (m_poly[i].x < m)
				m = m_poly[i].x;
		}

    return m;

}

int Polygon::maxx()
{
     int m = 0;
    for (int i=0; i < m_vertices;i++)
        {
        	if (m_poly[i].x > m)
            	m = m_poly[i].x;
    	}

    return m;

}

int Polygon::miny()
{
     int m = 0;
    for (int i=0; i < m_vertices;i++)
        {
        	if (m_poly[i].y < m)
            	m = m_poly[i].y;
    	}

    return m;

}

int Polygon::maxy()
{
    int m = 0;
    for (int i=0; i < m_vertices;i++)
        {
        	if (m_poly[i].y > m)
            	m = m_poly[i].y;
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
        delete[] m_poly;
        m_poly = new Vertex[m_vertices];
        for( int i=0; i < m_vertices; i++)
        {
            m_poly[i] = poly.m_poly[i];

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

    ostream& operator<<(ostream& out, const Polygon& poly)
    {
    // Skriv innehållet i polygonen till out
      for( int i = 0; i < poly.m_vertices; i++ )
      {
        out << poly.m_poly[i] << " ";
      }
      //Lägg till arean
      out << '\t' << " area = " << poly.polarea;

      return out;
    }
