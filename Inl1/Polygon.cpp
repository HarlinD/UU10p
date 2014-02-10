#include "polygon.h"
#include <cmath>
#include <iostream>

Polygon::Polygon()
{
    //allokera utrymme f�r poly n�r inga h�rn anges
    m_poly = new Vertex[2];

    // ha koll p� antal h�rn
    m_vertices = 0;
}

Polygon::Polygon( Vertex* varray, int antal)
{

	//allokera utrymme f�r poly
    m_poly = new Vertex[antal];

    // registrera antal h�rn
    m_vertices = antal;

    //spara polygonen
    for (int i=0;i < antal;i++)
    {
            m_poly[i].x = varray[i].x;
            m_poly[i].y = varray[i].y;
    }

}

Polygon::~Polygon()
{
    delete [] m_poly;
}

 void Polygon::add(Vertex nyvert)
 {

    // Allokera minne f�r temp array
   	Vertex *tmp = new Vertex[m_vertices];

    // kopiera nuvarande poly till temp arr
    for (int i=0;i < m_vertices;i++)
            {
            	tmp[i].x = m_poly[i].x;
                tmp[i].y = m_poly[i].y;
        	}

    //frig�r poly minne
    delete[] m_poly;

    //L�gg till ett h�rn i polygonen
    m_vertices++;

    //Skapa utrymme f�r nya polygonen
    m_poly = new Vertex[m_vertices];


    // L�t m_poly peka p� kopian
    //m_poly = tmp;
    // kopiera nuvarande tillbaka poly
    for (int i=0;i < (m_vertices-1) ;i++)
            {
                m_poly[i].x = tmp[i].x;
                m_poly[i].y = tmp[i].y;
        	}

    //L�gg till det senaste h�rnet OBS nollr�kning
    m_poly[m_vertices-1].x = nyvert.x;
    m_poly[m_vertices-1].y = nyvert.y;

    //Frig�r minnet fr�n tmp
    delete[] tmp;

 }

double Polygon::area()
{
    // Ber�kna arean p� polygonen
    double calcArea = 0;

    // Minst tre h�rn...
    if (m_vertices>2)
    {
            for (int i=0;i < (m_vertices-1) ;i++)
            {
                calcArea +=  (m_poly[i].x * m_poly[i+1].y - m_poly[i+1].x * m_poly[i].y);

            }


            calcArea += (m_poly[m_vertices-1].x * m_poly[0].y - m_poly[0].x * m_poly[m_vertices-1].y);
            calcArea = calcArea / 2;

    }


    return std::abs(calcArea);

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
