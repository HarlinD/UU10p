#include <iostream>

#include "vertex.h"
#include "polygon.h"

using namespace std;

int main()
{
  Vertex varr[] = { Vertex(0,0), Vertex(6,0),
                    Vertex(6,6), Vertex(0,6) };
  Polygon pol( varr, 4 );

  std::cout << "num:  " <<  pol.numVertices() << endl;
  std::cout << "yta:  " <<  pol.area() << endl;
  std::cout << "minx: " <<  pol.minx() << endl;
  std::cout << "maxx: " <<  pol.maxx() << endl;
  std::cout << "miny: " <<  pol.miny() << endl;
  std::cout << "maxy: " <<  pol.maxy() <<  endl;

  pol.add( Vertex(-1,3) );
  std::cout << "num:  " <<  pol.numVertices() << endl;
  std::cout << "yta:  " <<  pol.area() << endl;
  std::cout << "minx: " <<  pol.minx() << endl;

  Polygon pol1;
  pol1.add( Vertex(0,0) );
  pol1.add( Vertex(3,3) );
  pol1.add( Vertex(3,0) );

  cout << "triangelyta: " << pol1.area() << endl;

  return 0;
}
