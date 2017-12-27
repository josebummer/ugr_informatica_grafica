//**************************************************************************
// Práctica 2
//
// Jose Antonio Ruiz Millan 2017-2018
//
// Revolucion y Barrido
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include <string>

using namespace std;

const float AXIS_SIZE=5000;

enum _modo{
	PUNTOS, LINEAS, AJEDREZ, SOLIDO, MULTIPLE
};

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
void  draw_solido(float r, float g, float b);
void 	draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);
void 	draw_solido_color();
void 	draw(_modo modo , float r1, float g1, float b1, float r2, float g2, float b2, int grosor);

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

//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
	_objeto_ply();

	int parametros(const string &archivo);
};

class _rotacion: public _triangulos3D
{
public:

	_rotacion(int pnum);
	void parametros(const vector<_vertex3f> &perfil1, int num1); //perfil son los puntos que forman el objeto para rotarlo.

	vector<_vertex3f> perfil;
	int num; //el numero de caras que tenga
};

class _barrido: public _triangulos3D
{
public:

	_barrido(int pnum, int pnumb, float paltura=6.0, float pradio = 1.0);
	void parametros(const vector<_vertex3f> &perfil1, const vector<_vertex3f> &pperfila,  int num1); //perfil son los puntos que forman el objeto para rotarlo.

	vector<_vertex3f> perfil;
	vector<_vertex3f> perfila;
	int num; //el numero de caras que tenga
	int numb;
	float radio;
	float altura;
};
