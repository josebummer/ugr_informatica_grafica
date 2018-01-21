//**************************************************************************
// Práctica 5
//
// Jose Antonio Ruiz Millan 2017-2018
//
// Camaras, raton y selección
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include <string>
#include <stack>
#include <queue>

using namespace std;

const float AXIS_SIZE=5000;

enum _modo{
	PUNTOS, LINEAS, AJEDREZ, SOLIDO, MULTIPLE, RUBIK
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
void draw_rubik();
void 	draw(_modo modo , float r1, float g1, float b1, float r2, float g2, float b2, int grosor);

vector<_vertex3i> caras;
vector<_vertex3f> color;
bool renderIsSelect = false,seleccionado = false;
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float ptam=0.5);
	_cubo(const _cubo &otro);

	float tam;

	void rotarColorIzq();
	void rotarColorDer();
	void rotarColorDetr();
	void rotarColorDel();
	void rotarColorDerTapa();
	void rotarColorIzqTapa();
	void reajustarColor();
	_cubo& operator=(const _cubo &otro);

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
// clase tetraedro
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

//*************************************************************************
// clase rotacion
//*************************************************************************

class _rotacion: public _triangulos3D
{
public:

	_rotacion(int pnum);
	void parametros(const vector<_vertex3f> &perfil1, int num1); //perfil son los puntos que forman el objeto para rotarlo.

	vector<_vertex3f> perfil;
	int num; //el numero de caras que tenga
};

//*************************************************************************
// clase barrido
//*************************************************************************

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

//*************************************************************************
// clase cuborubik
//*************************************************************************

class _cuborubik: public _triangulos3D{
public:

	_cuborubik(float plado);			// si ponemos 3, seria una cara 3x3
	_cuborubik(const _cuborubik &otro);
	void draw(_modo modo, float r, float g, float b, int grosor);
	bool esPosibleMovimiento(char giro) const;
	void ajustar();
	_cuborubik realizarMovimiento(char m) const;
	void decodificarMovimiento(char m);
	_cuborubik& operator=(const _cuborubik &otro);


	vector<_cubo> rubik;
	float distancia;					// valdrá el valor total de la cara
	int tamanio = 3;
	float escala;
	bool sentido = true;
	float giro1,giro2,giro3,giro4,giro5,giro6;
	stack<char> solucion;
	char movant = 's';
};

class _camara{
private:
	// variables que definen la posicion de la camara en coordenadas polares
	GLfloat Observer_distance;
	GLfloat Observer_angle_x;
	GLfloat Observer_angle_y;
	bool isOrtho;
public:
	_camara(GLfloat Front_plane,bool ortho);
	_camara(GLfloat x, GLfloat y, GLfloat o, bool ortho);
	void setObservador();
	void setCamara(GLfloat x, GLfloat y);
	void addAngle(const char e);
	void subsAngle(const char e);
	bool getIsOrtho() const;
	float getAngleX() const;
	float getAngleY() const;
};
