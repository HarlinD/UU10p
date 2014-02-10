#include "..\include\polygon.h"
#include <cmath>
#include <iostream>

Polygon::Polygon( const Polygon& poly)
{
    // ha koll på antal hörn
    mVertices = poly.mVertices;
    mPolArea = poly.mPolArea;

    //allokera utrymme för poly
    mVecPoly = new Vertex[mVertices];

    for( int i=0; i < mVertices; i++)
    {
        mVecPoly[i] = poly.mVecPoly[i];
        std::cout << "\t" << "Kopiera polygon " << mVecPoly[i] << std::endl;
    }


}

Polygon::Polygon( Vertex* varray, int antal)
{

    //allokera utrymme för poly
    mVecPoly = new Vertex[antal];

    // registrera antal hörn
    mVertices = antal;

    //spara polygonen
    for (int i=0; i < antal; i++)
    {
        mVecPoly[i] = varray[i];
        std::cout << "\t" << "Ny polygon" << mVecPoly[i] << std::endl;
    }
    calcPolArea();
    std::cout << "\t" << "Polygons area" << mPolArea << std::endl;
}

Polygon::~Polygon()
{
    delete [] mVecPoly;
}

void Polygon::add(Vertex nyvert)
{

    // Allokera minne för temp array
    Vertex *tmp = new Vertex[mVertices];

    // kopiera nuvarande poly till temp arr
    for (int i=0; i < mVertices; i++)
    {
        tmp[i] = mVecPoly[i];
    }

    //frigör poly minne
    delete[] mVecPoly ;

    //Lägg till ett hörn i polygonen
    mVertices++;

    //Skapa utrymme för nya polygonen
    mVecPoly = new Vertex[mVertices];


    // Låt m_poly peka på kopian
    mVecPoly = tmp;

    //Lägg till det senaste hörnet OBS nollräkning
    mVecPoly[mVertices-1] = nyvert;


    //Frigör minnet från tmp
    delete[] tmp;

    calcPolArea();
}

double Polygon::calcPolArea()
{
    // Beräkna arean på polygonen
    double calcArea = 0;

    // Minst tre hörn...
    if (mVertices>2)
    {
        // ha koll på antal hörn

        for (int i=0; i < (mVertices-1) ; i++)
        {
            calcArea +=  (mVecPoly[i].x * mVecPoly[i+1].y - mVecPoly[i+1].x * mVecPoly[i].y);

        }


        calcArea += (mVecPoly[mVertices-1].x * mVecPoly[0].y - mVecPoly[0].x * mVecPoly[mVertices-1].y);
        calcArea = calcArea / 2;

    }


    mPolArea = std::abs(calcArea);

}

int Polygon::minx()
{


    int m = 0;
    for (int i=0; i < mVertices; i++ )
    {
        if (mVecPoly[i].x < m)
            m = mVecPoly[i].x;
    }

    return m;

}

int Polygon::maxx()
{
    int m = 0;
    for (int i=0; i < mVertices; i++)
    {
        if (mVecPoly[i].x > m)
            m = mVecPoly[i].x;
    }

    return m;

}

int Polygon::miny()
{
    int m = 0;
    for (int i=0; i < mVertices; i++)
    {
        if (mVecPoly[i].y < m)
            m = mVecPoly[i].y;
    }

    return m;

}

int Polygon::maxy()
{
    int m = 0;
    for (int i=0; i < mVertices; i++)
    {
        if (mVecPoly[i].y > m)
            m = mVecPoly[i].y;
    }

    return m;
}

int Polygon::numVertices()
{

    return mVertices;
}

const Polygon & Polygon::operator=( const Polygon & poly)
{
    if ( &poly != this )
    {
        mVertices = poly.mVertices;
        mPolArea = poly.mPolArea;
        delete[] mVecPoly;
        mVecPoly = new Vertex[mVertices];
        for( int i=0; i < mVertices; i++)
        {
            mVecPoly[i] = poly.mVecPoly[i];

        }

    }
    return *this;
}

bool Polygon::operator<( const Polygon & poly ) const
{
    if( mPolArea < poly.mPolArea )
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
    return poly.mPolArea == mPolArea;
}

std::ostream& operator<<( std::ostream& out, const Polygon& poly)
{
    // Skriv innehållet i polygonen till out
    for( int i = 0; i < poly.mVertices; i++ )
    {
        out << poly.mVecPoly[i].x << " " << poly.mVecPoly[i].y;
    }
    //Lägg till arean
    out << '\t' << " area = " << poly.mPolArea;

    return out;
}
