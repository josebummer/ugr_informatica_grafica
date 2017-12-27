//**************************************************************************
// Práctica 1
//
// Jose Antonio Ruiz Millan 2017-2018
//
// Objetos basicos (cubo,piramide,tetraedro,rombo)
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>

using namespace std;

const float AXIS_SIZE=5000;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:


	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
/*

*/
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
void 	draw_solido_color();

vector<_vertex3i> caras;
vector<_vertex3f> color;
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=0.75);
};

//*************************************************************************
// clase piramide
//*************************************************************************

class _tetraedro: public _triangulos3D
{
public:

	_tetraedro(float tam=0.5, float al=0.75);
};

//*************************************************************************
// clase rombo
//*************************************************************************

class _rombo: public _triangulos3D
{
public:

	_rombo(float tam=0.5, float al=0.75);
};
