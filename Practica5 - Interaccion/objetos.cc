//**************************************************************************
// Práctica 5
//
// Jose Antonio Ruiz Millan 2017-2018
//
// Camaras, raton y selección
//**************************************************************************


//**************************************************************************
// Ajustes:
//
// IMPORTANTE: Siempre el cubo tiene la cara azul de frente
//
// En la decodificacion de los movimientos se usan los siguientes valores:
// 'K' --> movimiento en sentido agujas del reloj cara 1 (azul)
// 'k' --> movimiento en sentido contrario a las agujas del reloj cara 1 (azul)
// 'L' y 'l' --> idem cara 2 (naranja)
// 'I' e 'i' --> idem cara 3 (verde)
// 'J' y 'j' --> idem cara 4 (roja)
// 'O' y 'o' --> idem cara 5 (amarilla)
// 'U' u 'u' --> idem cara 6 (blanca)
//
// Como se almacenan los cubos:
// IMPORTANTE: La cara azul va de frente a la camara, la amarilla abajo y la blanca arriba.
// -  La numeracion de los cubos empieza desde 0 hasta 26 siendo el primer cubo
//    el del fondo a la izquierda, siguiendo hacia la derecha y avanzando hacia la camara,
//    por lo que tenemos:
//
// -  CARA 1: 6,7,8,15,16,17,24,25,26
// -  CARA 2: 2,5,8,11,14,17,20,23,26
// -  CARA 3: 0,1,2,9,10,11,18,19,20
// -  CARA 4: 0,3,6,9,12,15,18,21,24
// -  CARA 5: 18,19,20,21,22,23,24,25,26
// -  CARA 6: 0,1,2,3,4,5,6,7,8
//
// Cubo de Rubik
//**************************************************************************


//**************************************************************************
// Modos de Uso para el Usuario:
//
// Para mover el cubo podemos usas las siguientes teclas:
// '<' --> Cambia el sentido del movimiento
// 'k' --> Mueve la cara 1 (azul)
// 'l' --> Mueve cara 2 (naranja)
// 'i' --> Mueve cara 3 (verde)
// 'j' --> Mueve cara 4 (roja)
// 'o' --> Mueve cara 5 (amarilla)
// 'u' --> Mueve cara 6 (blanca)
// 'd' --> Realiza x movimientos aleatorios para descolocar el cubo
// 'r' --> Resuelve el cubo automaticamente
//
//**************************************************************************

//**************************************************************************
// Camaras: Para ello debemos arrancar el programa --> ./practica5 c
//
// Tendremos las 4 camaras, 1 con movimiento y otras 3 que seran alzado
// planta y perfil.
//
// Para mover la camara podemos usar las flechas como hasta ahora o el
// raton, dejando el boton derecho pulsado y moviendo el raton.
//
//**************************************************************************

//**************************************************************************
// Seleccion: Para ello debemos arrancar el programa --> ./practica5 s
//
// Podremos seleccionar los objetos y se pondran en verde. Si los volvemos
// a seleccionar, se vuelven a su color.
//
// AVISO: RUBIK
// Para el cubo de rubik hay que dibujarlo en modo RUBIK pulsando la a.
//
//**************************************************************************

#include "objetos.h"
#include "file_ply_stl.h"

_puntos3D::_puntos3D(){}

void _puntos3D::draw_puntos(float r, float g, float b, int grosor){

  //PINTAR CON GLBEGIN
  /*
  glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
  glPointSize(grosor);
  glColor3f(r,g,b);
  glBegin(GL_POINTS);
  for(unsigned int i = 0; i < vertices.size(); i++){
      glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
  }
  glEnd();
  */

  //PINTAR CON VERTEXARRAY
  glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
  glPointSize(grosor);
  glColor3f(r,g,b);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  glDrawArrays(GL_POINTS,0,vertices.size());
}

_triangulos3D::_triangulos3D(){}

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor){

  //PINTAR CON GLBEGIN
  /*
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glLineWidth(grosor);
  glColor3f(r,g,b);
  glBegin(GL_TRIANGLES);
  for(unsigned int i = 0; i < caras.size(); i++){
      glVertex3fv((GLfloat *) &vertices[caras[i].x]);
      glVertex3fv((GLfloat *) &vertices[caras[i].y]);
      glVertex3fv((GLfloat *) &vertices[caras[i].z]);
  }
  glEnd();
  glLineWidth(1);
  */

  //PINTAR CON VERTEXARRAY
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glLineWidth(grosor);
  glColor3f(r,g,b);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&caras[0]);
  glLineWidth(1);
}


void _triangulos3D::draw_solido(float r, float g, float b){

  //PINTAR CON GLBEGIN
  /*
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor3f(r,g,b);
  glBegin(GL_TRIANGLES);
  for(unsigned int i = 0; i < caras.size(); i++){
      glVertex3fv((GLfloat *) &vertices[caras[i].x]);
      glVertex3fv((GLfloat *) &vertices[caras[i].y]);
      glVertex3fv((GLfloat *) &vertices[caras[i].z]);
  }
  glEnd();


  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glColor3f(0,0,0);
  glLineWidth(2);
  glBegin(GL_TRIANGLES);
  for(unsigned int i = 0; i < caras.size(); i++){
      glVertex3fv((GLfloat *) &vertices[caras[i].x]);
      glVertex3fv((GLfloat *) &vertices[caras[i].y]);
      glVertex3fv((GLfloat *) &vertices[caras[i].z]);
  }
  glEnd();
  glLineWidth(1);
  */

  //PINTAR CON VERTEXARRAY
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor3f(r,g,b);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&caras[0]);

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glLineWidth(2);
  glColor3f(0,0,0);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3,GL_FLOAT,0,&vertices[0]);
  glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&caras[0]);
  glLineWidth(1);

}

void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2){
  int n = 0;
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_TRIANGLES);
  if(caras.size() == 0) n++;
  else n = caras.size();
  for(int i = 0; i < n-1; i+=2){
    glColor3f(r1,g1,b1);
    glVertex3fv((GLfloat *) &vertices[caras[i].x]);
    glVertex3fv((GLfloat *) &vertices[caras[i].y]);
    glVertex3fv((GLfloat *) &vertices[caras[i].z]);
    glColor3f(r2,g2,b2);
    glVertex3fv((GLfloat *) &vertices[caras[i+1].x]);
    glVertex3fv((GLfloat *) &vertices[caras[i+1].y]);
    glVertex3fv((GLfloat *) &vertices[caras[i+1].z]);
  }
  glEnd();

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glColor3f(0,0,0);
  glLineWidth(2);
  glBegin(GL_TRIANGLES);
  for(unsigned int i = 0; i < caras.size(); i++){
      glVertex3fv((GLfloat *) &vertices[caras[i].x]);
      glVertex3fv((GLfloat *) &vertices[caras[i].y]);
      glVertex3fv((GLfloat *) &vertices[caras[i].z]);
  }
  glEnd();
  glLineWidth(1);
}

_cubo::_cubo(float ptam){
  tam = ptam;
  caras.reserve(12);
  vertices.reserve(8);
  color.reserve(6);

  color.push_back(_vertex3f(0,0,1));                                    // 0: azul
  color.push_back(_vertex3f(0,1,0));                                    // 1: verde
  color.push_back(_vertex3f(1,0.9,0));                                  // 2: amarillo
  color.push_back(_vertex3f(1,1,1));                                    // 3: blanco
  color.push_back(_vertex3f(1,0,0));                                    // 4: rojo
  color.push_back(_vertex3f(1,0.4,0));                                  // 5:naranja

  vertices.push_back(_vertex3<float>(-tam/2, -tam/2, tam/2));
  vertices.push_back(_vertex3<float>(tam/2, -tam/2, tam/2));
  vertices.push_back(_vertex3<float>(-tam/2, tam/2, tam/2));
  vertices.push_back(_vertex3<float>(tam/2, tam/2, tam/2));
  vertices.push_back(_vertex3<float>(-tam/2, -tam/2, -tam/2));
  vertices.push_back(_vertex3<float>(tam/2, -tam/2, -tam/2));
  vertices.push_back(_vertex3<float>(-tam/2, tam/2, -tam/2));
  vertices.push_back(_vertex3<float>(tam/2, tam/2, -tam/2));

  caras.push_back(_vertex3<int>(0, 1, 2));
  caras.push_back(_vertex3<int>(1, 2, 3));

  caras.push_back(_vertex3<int>(4,5,6));
  caras.push_back(_vertex3<int>(5,6,7));

  caras.push_back(_vertex3<int>(0,1,4));
  caras.push_back(_vertex3<int>(1,4,5));

  caras.push_back(_vertex3<int>(2,3,6));
  caras.push_back(_vertex3<int>(3,6,7));

  caras.push_back(_vertex3<int>(0,2,4));
  caras.push_back(_vertex3<int>(2,4,6));

  caras.push_back(_vertex3<int>(1,3,5));
  caras.push_back(_vertex3<int>(3,5,7));
}

void _cubo::reajustarColor(){
  color.clear();

  color.push_back(_vertex3f(0,0,1));                                    // 0: azul
  color.push_back(_vertex3f(0,1,0));                                    // 1: verde
  color.push_back(_vertex3f(1,0.9,0));                                  // 2: amarillo
  color.push_back(_vertex3f(1,1,1));                                    // 3: blanco
  color.push_back(_vertex3f(1,0,0));                                    // 4: rojo
  color.push_back(_vertex3f(1,0.4,0));                                  // 5:naranja
}

_cubo::_cubo(const _cubo &otro){
  *this = otro;
}

_cubo& _cubo::operator=(const _cubo &otro){
  vertices = otro.vertices;
  color = otro.color;
  caras = otro.caras;
  return (*this);
}
//
void _cubo::rotarColorDer(){
  _vertex3f aux;
    aux = color[3];
    color[3] = color[4];
    color[4] = color[2];
    color[2] = color[5];
    color[5] = aux;
}
//
void _cubo::rotarColorIzq(){
  _vertex3f aux;
    aux = color[2];
    color[2] = color[4];
    color[4] = color[3];
    color[3] = color[5];
    color[5] = aux;

}

void _cubo::rotarColorDel(){
  _vertex3f aux;
    aux = color[0];
    color[0] = color[3];
    color[3] = color[1];
    color[1] = color[2];
    color[2] = aux;


}

void _cubo::rotarColorDetr(){
  _vertex3f aux;
    aux = color[1];
    color[1] = color[3];
    color[3] = color[0];
    color[0] = color[2];
    color[2] = aux;

}

void _cubo::rotarColorDerTapa(){
  _vertex3f aux;
    aux = color[0];
    color[0] = color[4];
    color[4] = color[1];
    color[1] = color[5];
    color[5] = aux;
}
//
void _cubo::rotarColorIzqTapa(){
  _vertex3f aux;
    aux = color[0];
    color[0] = color[5];
    color[5] = color[1];
    color[1] = color[4];
    color[4] = aux;

}



_piramide::_piramide(float tam, float al){
  vertices.reserve(4);
  caras.reserve(6);
  color.reserve(6);

  for(int i = 0; i < 6; i++){
    color.push_back(_vertex3<float>(rand()%255/(1.0*255),rand()%255/(1.0*255),rand()%255/(1.0*255)));
  }

  vertices.push_back(_vertex3<float>(-tam/2,0.0,tam/2));
  vertices.push_back(_vertex3<float>(tam/2,0.0,tam/2));
  vertices.push_back(_vertex3<float>(tam/2,0.0,-tam/2));
  vertices.push_back(_vertex3<float>(-tam/2,0.0,-tam/2));
  vertices.push_back(_vertex3<float>(0.0,al,0.0));


  caras.push_back(_vertex3<int>(0,1,3));
  caras.push_back(_vertex3<int>(1, 2, 3));

  caras.push_back(_vertex3<int>(0,1, 4));

  caras.push_back(_vertex3<int>(1, 2, 4));

  caras.push_back(_vertex3<int>(2,3, 4));

  caras.push_back(_vertex3<int>(0, 3, 4));

}

_tetraedro::_tetraedro(float tam, float al){
  vertices.reserve(4);
  caras.reserve(4);
  color.reserve(4);

  for(int i = 0; i < 4; i++){
    color.push_back(_vertex3<float>(rand()%255/(1.0*255),rand()%255/(1.0*255),rand()%255/(1.0*255)));
  }

  vertices.push_back(_vertex3<float>(al/2,0.0,tam/2));
  vertices.push_back(_vertex3<float>(al/2,0.0,-tam/2));
  vertices.push_back(_vertex3<float>(-al/2,0.0,0.0));
  vertices.push_back(_vertex3<float>(0.0,al,0.0));

  caras.push_back(_vertex3<int>(0, 1, 3));

  caras.push_back(_vertex3<int>(1,2, 3));

  caras.push_back(_vertex3<int>(0, 2, 3));

  caras.push_back(_vertex3<int>(0,1,2));


}

_rombo::_rombo(float tam, float al){
  vertices.reserve(6);
  caras.reserve(8);
  color.reserve(8);

  for(int i = 0; i < 8; i++){
    color.push_back(_vertex3<float>(rand()%255/(1.0*255),rand()%255/(1.0*255),rand()%255/(1.0*255)));
  }

  vertices.push_back(_vertex3<float>(0.0,0.0,0.0));
  vertices.push_back(_vertex3<float>(-tam/2, al/2,tam/2));
  vertices.push_back(_vertex3<float>(tam/2,al/2,tam/2));
  vertices.push_back(_vertex3<float>(tam/2,al/2,-tam/2));
  vertices.push_back(_vertex3<float>(-tam/2,al/2,-tam/2));
  vertices.push_back(_vertex3<float>(0.0,al,0.0));

  caras.push_back(_vertex3<int>(0, 1, 2));

  caras.push_back(_vertex3<int>(0, 2, 3));

  caras.push_back(_vertex3<int>(0, 3, 4));

  caras.push_back(_vertex3<int>(0, 1, 4));

  caras.push_back(_vertex3<int>(2, 3, 5));

  caras.push_back(_vertex3<int>(1, 2, 5));

  caras.push_back(_vertex3<int>(1, 4, 5));

  caras.push_back(_vertex3<int>(3, 4, 5));

}

void _triangulos3D::draw_solido_color(){
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_TRIANGLES);
  for(unsigned int i = 0; i < caras.size(); i++){
      glColor3f(color[i].x,color[i].y,color[i].z);
      glVertex3fv((GLfloat *) &vertices[caras[i].x]);
      glVertex3fv((GLfloat *) &vertices[caras[i].y]);
      glVertex3fv((GLfloat *) &vertices[caras[i].z]);
  }
  glEnd();

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glColor3f(0,0,0);
  glLineWidth(2);
  glBegin(GL_TRIANGLES);
  for(unsigned int i = 0; i < caras.size(); i++){
      glVertex3fv((GLfloat *) &vertices[caras[i].x]);
      glVertex3fv((GLfloat *) &vertices[caras[i].y]);
      glVertex3fv((GLfloat *) &vertices[caras[i].z]);
  }
  glEnd();
  glLineWidth(1);
}

_objeto_ply::_objeto_ply(){}

int _objeto_ply::parametros(const string &archivo){

  _file_ply File_ply;

  if (File_ply.open(archivo)){
    File_ply.read(vertices,caras);
    std::cout << "File read correctly" << std::endl;
  }
  else{
    std::cout << "File can't be opened" << std::endl;
    return -1;
  }
  File_ply.close();

  color.reserve(caras.size());

  for(unsigned int i = 0; i < caras.size(); i++){
    color.push_back(_vertex3<float>(rand()%255/(1.0*255),rand()%255/(1.0*255),rand()%255/(1.0*255)));
  }

  return 0;
}

_rotacion::_rotacion(int pnum){
  num = pnum;
  perfil = (vector<_vertex3f>){
    //lampara
    // {3.0,0.0,0.0},
    // {6.0,2.0,0.0},
    // {1.0,4.0,0.0},
    // {0.0,6.0,0.0}

    //cilindro
    // {0.1,0.0,0.0},
    // {4.0,0.0,0.0},
    // {4.0,6.0,0.0},
    // {0.1,6.0,0.0}

    //peon
    {1.0, -1.4, 0.0},
    {1.0, -1.1, 0.0},
    {0.5, -0.7, 0.0},
    {0.4, -0.4, 0.0},
    {0.4, 0.5, 0.0},
    {0.5, 0.6, 0.0},
    {0.3, 0.6, 0.0},
    {0.5, 0.8, 0.0},
    {0.55, 1.0, 0.0},
    {0.5, 1.2, 0.0},
    {0.3, 1.4, 0.0},
  };

  if(num > 2) this->parametros(perfil, num);
  else this->parametros(perfil, 3);


}

void _rotacion::parametros(const vector<_vertex3f> &perfil1, int num1){
  perfil = perfil1;
  num = num1;
  vertices.reserve(perfil.size()*num);
  for(int i = 0; i < num; i++){
    for (unsigned int j = 0; j < perfil.size(); j++) {
      vertices.push_back(_vertex3f(
        perfil[j].x*cos(2.0*M_PI*i/(1.0*num))+ perfil[j].z*sin(2.0*M_PI*i/(1.0*num)),   // valor de x
        perfil[j].y,                                                                    // valor de y
        perfil[j].x*(-sin(2.0*M_PI*i/(1.0*num)))+perfil[j].z*cos(2.0*M_PI*i/(1.0*num))  //valor de z
      ));
    }
  }
  caras.reserve(2*num*perfil.size());
  color.reserve(2*num*perfil.size());
  for(int i = 0; i < num; i++){
    unsigned int ini = i*perfil.size();
    unsigned int fin = ini+perfil.size();
    for(unsigned int j = ini+1, k = (fin+1)%vertices.size() ; j < fin; j++,k++){
      caras.push_back(_vertex3i(j-1, k-1, k));
      caras.push_back(_vertex3i(j-1, k,   j));
    }
  }

  for(unsigned int i = 0; i < caras.size(); i++){
    color.push_back(_vertex3<float>(rand()%255/(1.0*255),rand()%255/(1.0*255),rand()%255/(1.0*255)));
  }
}

_barrido::_barrido(int pnum, int pnumb, float paltura, float pradio){
  num = (pnum > 2)?pnum:3;
  numb = (pnumb > 2)?pnumb:3;
  altura = paltura;
  radio = pradio;

  for(int i = 0; i < numb; i++){
    perfil.push_back(_vertex3f(
      radio*cos(2.0*M_PI*i/(1.0*numb)),   // valor de x
      0.0,                               // valor de y
      radio*sin(2.0*M_PI*i/(1.0*numb))  //valor de z
    ));
  }

  vector<_vertex3f> perfilaux = (vector<_vertex3f>){
    {1.0,0.0,1.0},
    {3.0,3.0,1.0},
    {1.0,6.0,1.0}
  };

  if(perfilaux.size() != 0){
    for(unsigned int i = 0; i < perfilaux.size()-1;i++){
      perfila.push_back(perfilaux[i]);
      if( perfilaux[i].x < perfilaux[i+1].x ){
        for(int j = 1; j < num;j++){
          perfila.push_back(_vertex3f(
            perfilaux[i].x+fabs(perfilaux[i+1].x-perfilaux[i].x)/(1.0*num)*(1.0*j),
            perfilaux[i].y+fabs(perfilaux[i+1].y-perfilaux[i].y)/(1.0*num)*(1.0*j),
            perfilaux[i].z
          ));
        }
      }
      else if(perfilaux[i].x > perfilaux[i+1].x){
        for(int j = 1; j < num;j++){
          perfila.push_back(_vertex3f(
            perfilaux[i].x-fabs(perfilaux[i+1].x-perfilaux[i].x)/(1.0*num)*(1.0*j),
            perfilaux[i].y+fabs(perfilaux[i+1].y-perfilaux[i].y)/(1.0*num)*(1.0*j),
            perfilaux[i].z
          ));
        }
      }
    }
    perfila.push_back(perfilaux[perfilaux.size()-1]);
  }

  this->parametros(perfil, perfila, num);

}

void _barrido::parametros(const vector<_vertex3f> &perfil1, const vector<_vertex3f> &pperfila, int num1){
  num = (pperfila.size() == 0)?num1+1:pperfila.size();
  perfil = perfil1;
  perfila=pperfila;


  if(perfila.size() != 0){
    for(int i = 0; i < num; i++){
      for(unsigned int j = 0; j < perfil.size(); j++){
        if(i==0){
          vertices.push_back(_vertex3f(
            perfil[j].x,
            perfil[j].y,
            perfil[j].z
          ));
        }
        else{
          vertices.push_back(_vertex3f(
            perfil[j].x+(perfila[i].x-perfila[0].x),
            perfila[i].y,
            perfil[j].z
          ));
        }
      }
    }
  }
  else{
    float dist = altura/(1.0*(num-1));

    for(int i = 0; i < num; i++){
      for(unsigned int j = 0; j < perfil.size(); j++){
        vertices.push_back(_vertex3f(
          perfil[j].x,
          perfil[j].y+dist*i,
          perfil[j].z
        ));
      }
    }
  }

  caras.reserve(2*(num-1)*perfil.size()+2);
  color.reserve(2*(num-1)*perfil.size()+2);
  for(int i = 0; i < num-1; i++){
    unsigned int ini = i*perfil.size();
    unsigned int fin = ini+perfil.size();
    for(unsigned int j = ini+1, k = (fin+1)%vertices.size() ; j < fin; j++,k++){
      caras.push_back(_vertex3i(j-1, j, k));
      caras.push_back(_vertex3i(j-1, k,   k-1));
    }
    caras.push_back(_vertex3i(fin-1, ini, fin));
    caras.push_back(_vertex3i(fin-1, fin,   fin+perfil.size()-1));
  }

  for(unsigned int i = 0; i < caras.size(); i++){
    color.push_back(_vertex3<float>(rand()%255/(1.0*255),rand()%255/(1.0*255),rand()%255/(1.0*255)));
  }

}

void _triangulos3D::draw(_modo modo, float r1, float g1, float b1, float r2, float g2, float b2, int grosor){
  switch (modo) {
    case PUNTOS:
      this->draw_puntos(r1, g1, b1, grosor);
    break;
    case LINEAS:
      this->draw_aristas(r1, g1, b1, grosor);
    break;
    case AJEDREZ:
      this->draw_solido_ajedrez(r1, g1, b1, r2, g2, b2);
    break;
    case SOLIDO:
      this->draw_solido(r1,g1,b1);
    break;
    case MULTIPLE:
      this->draw_solido_color();
    break;
    case RUBIK:
      this->draw_rubik();
    break;
  }
}

_cuborubik::_cuborubik(const _cuborubik &otro){
  *this = otro;
}


_cuborubik::_cuborubik(float plado){
  escala = plado;
  giro1 = giro2 = giro3 = giro4 = giro5 = giro6 = 0;
  distancia = escala*tamanio;

  for(int i = 0; i < tamanio*tamanio*tamanio; i++){
    rubik.push_back(_cubo(1));
  }
}

bool esCara3(int c){
  return (c == 0 || c == 1 || c == 2 || c == 9|| c == 10|| c == 11|| c == 18|| c == 19 || c == 20);
}

bool esCara1(int c){
  return (c == 6 || c == 7 || c == 8 || c == 15 || c == 16 || c == 17 || c == 24 || c == 25 || c == 26);
}

bool esCara2(int c){
  return (c == 2 || c == 5 || c == 8 || c == 11 || c == 14 || c == 17 || c == 20 || c == 23 || c == 26);
}

bool esCara4(int c){
  return (c == 0 || c == 3 || c == 6 || c == 9 || c == 12 || c == 15 || c == 18 || c == 21 || c == 24);
}

bool esCara5(int c){
  return (c == 18 || c == 19 || c == 20 || c == 21 || c == 22 || c == 23 || c == 24 || c == 25 || c == 26);
}

bool esCara6(int c){
  return (c == 0 || c == 1 || c == 2 || c == 3 || c == 4 || c == 5 || c == 6 || c == 7 || c == 8);
}

void _cuborubik::draw(_modo modo, float r, float g, float b, int grosor){
  float k1,k2,k3;
  int k = 1;
  k3 = -distancia/tamanio;
  k2 = distancia/tamanio;
  k1 = -distancia/tamanio;
  int c = 0;
  float q1 = -0.1 ,q2 = -0.1;
  float q3 = 0.1;

  for(int i = 0; i < tamanio;i++,k2-=escala,q3-=0.1){
    for(int j = 0; j < tamanio;j++,k3+=escala,q2+=0.1){
      for(int h = 0;h < tamanio;h++,k1+=escala,c++,q1+=0.1){
        glPushMatrix();
        if(esCara1(c)){
          glRotatef(giro1, 0, 0, 1);
        }
        if(esCara2(c)){
          glRotatef(giro2, 1, 0, 0);
        }
        if(esCara3(c)){
          glRotatef(giro3, 0, 0, 1);
        }
        if(esCara4(c)){
          glRotatef(giro4, 1, 0, 0);
        }
        if(esCara5(c)){
          glRotatef(giro5, 0, 1, 0);
        }
        if(esCara6(c)){
          glRotatef(giro6, 0, 1, 0);
        }
        if(renderIsSelect)glLoadName(k);        
        glTranslatef(k1+q1, k2+q3, k3+q2);
        glScalef(escala,escala,escala);
        rubik[c].draw(modo, r, g, b, 0, 0, 0, grosor);
        // rubik[c].draw(modo, 0, 1, 0, 0, 0, 0, grosor);
        glPopMatrix();
        k++;
      }
      q1 = -0.1;
      k1 = -distancia/tamanio;
    }
    q2 = -0.1;
    k3 = -distancia/tamanio;
  }

  if((int)giro1 > 60){
    giro1 = -30;
    _cubo aux = rubik[6];
    rubik[6] = rubik[8];
    rubik[8] = rubik[26];
    rubik[26] = rubik[24];
    rubik[24] = aux;
    aux = rubik[7];
    rubik[7] = rubik[17];
    rubik[17] = rubik[25];
    rubik[25] = rubik[15];
    rubik[15] = aux;

    c = 6;
    for(int i = 0; i < tamanio; i++){
      for(int j = 0; j < tamanio; j++,c++){
        rubik[c].rotarColorIzq();
      }
      c+=tamanio*2;
    }
    solucion.push('k');
  }
  else if((int)giro1 < -60){
    giro1 = 30;
    _cubo aux = rubik[8];
    rubik[8] = rubik[6];
    rubik[6] = rubik[24];
    rubik[24] = rubik[26];
    rubik[26] = aux;
    aux = rubik[7];
    rubik[7] = rubik[15];
    rubik[15] = rubik[25];
    rubik[25] = rubik[17];
    rubik[17] = aux;

    c = 6;
    for(int i = 0; i < tamanio; i++){
      for(int j = 0; j < tamanio; j++,c++){
        rubik[c].rotarColorDer();
      }
      c+=tamanio*2;
    }
    solucion.push('K');
  }
  else if((int)giro2 > 60){
    giro2 = -30;
    _cubo aux = rubik[2];
    rubik[2] = rubik[20];
    rubik[20] = rubik[26];
    rubik[26] = rubik[8];
    rubik[8] = aux;
    aux = rubik[5];
    rubik[5] = rubik[11];
    rubik[11] = rubik[23];
    rubik[23] = rubik[17];
    rubik[17] = aux;

    c = 2;
    for(int i = 0; i < tamanio; i++){
      for(int j = 0; j < tamanio; j++,c+=tamanio){
        rubik[c].rotarColorDel();
      }
    }
    solucion.push('l');
  }
  else if((int)giro2 < -60){
    giro2 = 30;
    _cubo aux = rubik[2];
    rubik[2] = rubik[8];
    rubik[8] = rubik[26];
    rubik[26] = rubik[20];
    rubik[20] = aux;
    aux = rubik[5];
    rubik[5] = rubik[17];
    rubik[17] = rubik[23];
    rubik[23] = rubik[11];
    rubik[11] = aux;

    c = 2;
    for(int i = 0; i < tamanio; i++){
      for(int j = 0; j < tamanio; j++,c+=tamanio){
        rubik[c].rotarColorDetr();
      }
    }
    solucion.push('L');
  }
  else if((int)giro3 > 60){
    giro3 = -30;
    _cubo aux = rubik[20];
    rubik[20] = rubik[18];
    rubik[18] = rubik[0];
    rubik[0] = rubik[2];
    rubik[2] = aux;
    aux = rubik[1];
    rubik[1] = rubik[11];
    rubik[11] = rubik[19];
    rubik[19] = rubik[9];
    rubik[9] = aux;

    c = 0;
    for(int i = 0; i < tamanio; i++){
      for(int j = 0; j < tamanio; j++,c++){
        rubik[c].rotarColorIzq();
      }
      c+=tamanio*2;
    }
    solucion.push('i');
  }
  else if((int)giro3 < -60){
    giro3 = 30;
    _cubo aux = rubik[0];
    rubik[0] = rubik[18];
    rubik[18] = rubik[20];
    rubik[20] = rubik[2];
    rubik[2] = aux;
    aux = rubik[1];
    rubik[1] = rubik[9];
    rubik[9] = rubik[19];
    rubik[19] = rubik[11];
    rubik[11] = aux;

    c = 0;
    for(int i = 0; i < tamanio; i++){
      for(int j = 0; j < tamanio; j++,c++){
        rubik[c].rotarColorDer();
      }
      c+=tamanio*2;
    }
    solucion.push('I');
  }
  else if((int)giro4 > 60){
    giro4 = -30;
    _cubo aux = rubik[6];
    rubik[6] = rubik[0];
    rubik[0] = rubik[18];
    rubik[18] = rubik[24];
    rubik[24] = aux;
    aux = rubik[3];
    rubik[3] = rubik[9];
    rubik[9] = rubik[21];
    rubik[21] = rubik[15];
    rubik[15] = aux;

    c = 0;
    for(int i = 0; i < tamanio; i++){
      for(int j = 0; j < tamanio; j++,c+=tamanio){
        rubik[c].rotarColorDel();
      }
    }
    solucion.push('j');
  }
  else if((int)giro4 < -60){
    giro4 = 30;
    _cubo aux = rubik[0];
    rubik[0] = rubik[6];
    rubik[6] = rubik[24];
    rubik[24] = rubik[18];
    rubik[18] = aux;
    aux = rubik[3];
    rubik[3] = rubik[15];
    rubik[15] = rubik[21];
    rubik[21] = rubik[9];
    rubik[9] = aux;

    c = 0;
    for(int i = 0; i < tamanio; i++){
      for(int j = 0; j < tamanio; j++,c+=tamanio){
        rubik[c].rotarColorDetr();
      }
    }
    solucion.push('J');
  }
  else if((int)giro5 > 60){
    giro5 = -30;
    _cubo aux = rubik[18];
    rubik[18] = rubik[20];
    rubik[20] = rubik[26];
    rubik[26] = rubik[24];
    rubik[24] = aux;
    aux = rubik[19];
    rubik[19] = rubik[23];
    rubik[23] = rubik[25];
    rubik[25] = rubik[21];
    rubik[21] = aux;

    c = 18;
    for(int i = 0; i < tamanio; i++){
      for(int j = 0; j < tamanio; j++,c++){
        rubik[c].rotarColorDerTapa();
      }
    }
    solucion.push('o');
  }
  else if((int)giro5 < -60){
    giro5 = 30;
    _cubo aux = rubik[18];
    rubik[18] = rubik[24];
    rubik[24] = rubik[26];
    rubik[26] = rubik[20];
    rubik[20] = aux;
    aux = rubik[19];
    rubik[19] = rubik[21];
    rubik[21] = rubik[25];
    rubik[25] = rubik[23];
    rubik[23] = aux;

    c = 18;
    for(int i = 0; i < tamanio; i++){
      for(int j = 0; j < tamanio; j++,c++){
        rubik[c].rotarColorIzqTapa();
      }
    }
    solucion.push('O');
  }
  else if((int)giro6 > 60){
    giro6 = -30;
    _cubo aux = rubik[0];
    rubik[0] = rubik[2];
    rubik[2] = rubik[8];
    rubik[8] = rubik[6];
    rubik[6] = aux;
    aux = rubik[1];
    rubik[1] = rubik[5];
    rubik[5] = rubik[7];
    rubik[7] = rubik[3];
    rubik[3] = aux;

    c = 0;
    for(int i = 0; i < tamanio; i++){
      for(int j = 0; j < tamanio; j++,c++){
        rubik[c].rotarColorDerTapa();
      }
    }
    solucion.push('u');
  }
  else if((int)giro6 < -60){
    giro6 = 30;
    _cubo aux = rubik[0];
    rubik[0] = rubik[6];
    rubik[6] = rubik[8];
    rubik[8] = rubik[2];
    rubik[2] = aux;
    aux = rubik[1];
    rubik[1] = rubik[3];
    rubik[3] = rubik[7];
    rubik[7] = rubik[5];
    rubik[5] = aux;

    c = 0;
    for(int i = 0; i < tamanio; i++){
      for(int j = 0; j < tamanio; j++,c++){
        rubik[c].rotarColorIzqTapa();
      }
    }
    solucion.push('U');
  }
}

void _triangulos3D::draw_rubik(){
  int n = 0;
  int c = 0;

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_TRIANGLES);
  if(caras.size() == 0) n++;
  else n = caras.size();
  for(int i = 0; i < n; i++){
    if(i%2 == 0){
      glColor3f(color[c].x, color[c].y, color[c].z);
      c++;
    }
    glVertex3fv((GLfloat *) &vertices[caras[i].x]);
    glVertex3fv((GLfloat *) &vertices[caras[i].y]);
    glVertex3fv((GLfloat *) &vertices[caras[i].z]);
  }
  glEnd();

  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glColor3f(0,0,0);
  glLineWidth(2);
  glBegin(GL_TRIANGLES);
  for(unsigned int i = 0; i < caras.size(); i++){
      glVertex3fv((GLfloat *) &vertices[caras[i].x]);
      glVertex3fv((GLfloat *) &vertices[caras[i].y]);
      glVertex3fv((GLfloat *) &vertices[caras[i].z]);
  }
  glEnd();
  glLineWidth(1);
}

bool _cuborubik::esPosibleMovimiento(char giro) const{
  switch (giro) {
    case 'i':
    case 'k':
      return ((giro2 >= -10 && giro2 <= 10) &&
              (giro4 >= -10 && giro4 <= 10) &&
              (giro5 >= -10 && giro5 <= 10) &&
              (giro6 >= -10 && giro6 <= 10)
              );
    break;
    case 'j':
    case 'l':
    return ((giro1 >= -10 && giro1 <= 10) &&
            (giro3 >= -10 && giro3 <= 10) &&
            (giro5 >= -10 && giro5 <= 10) &&
            (giro6 >= -10 && giro6 <= 10)
            );
    break;
    case 'u':
    case 'o':
    return ((giro1 >= -10 && giro1 <= 10) &&
            (giro3 >= -10 && giro3 <= 10) &&
            (giro2 >= -10 && giro2 <= 10) &&
            (giro4 >= -10 && giro4 <= 10)
            );
    break;
  }
  return false;
}

void _cuborubik::ajustar(){
  giro1 = giro2 = giro3 = giro4 = giro5 = giro6 = 0;
}

_cuborubik& _cuborubik::operator=(const _cuborubik &otro){
  rubik = otro.rubik;
  escala = otro.escala;
  giro1 = otro.giro1;
  giro2 = otro.giro2;
  giro3 = otro.giro3;
  giro4 = otro.giro4;
  giro5 = otro.giro5;
  giro6 = otro.giro6;
  solucion = otro.solucion;
  movant = otro.movant;
  sentido = otro.sentido;
  return (*this);
}

void _cuborubik::decodificarMovimiento(char m){
  switch (m) {
    case 'K':
      giro1+=5;
    break;
    case 'k':
      giro1-=5;
    break;
    case 'L':
      giro2+=5;
    break;
    case 'l':
      giro2-=5;
    break;
    case 'I':
      giro3+=5;
    break;
    case 'i':
      giro3-=5;
    break;
    case 'J':
      giro4+=5;
    break;
    case 'j':
      giro4-=5;
    break;
    case 'O':
      giro5+=5;
    break;
    case 'o':
      giro5-=5;
    break;
    case 'U':
      giro6+=5;
    break;
    case 'u':
      giro6-=5;
    break;
  }
}

_camara::_camara(GLfloat Front_plane, bool ortho){
  Observer_distance=2*Front_plane;
  Observer_angle_x=0;
  Observer_angle_y=0;
  isOrtho = ortho;
}

_camara::_camara(GLfloat x, GLfloat y, GLfloat o, bool ortho){
  Observer_angle_x = x;
  Observer_angle_y = y;
  Observer_distance = 2*o;
  isOrtho = ortho;
}

void _camara::setCamara(GLfloat x, GLfloat y){
  Observer_angle_x = x;
  Observer_angle_y = y;
}

void _camara::setObservador(){
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}

void _camara::addAngle(const char e){
  if(!isOrtho){
    switch(e){
    case 'x':
      Observer_angle_x++;
    break;
    case 'y':
      Observer_angle_y++;
    break;
    case 'o':
      Observer_distance*=1.2;
    break;
    }
  }
}

void _camara::subsAngle(const char e){
  if(!isOrtho){
    switch(e){
    case 'x':
      Observer_angle_x--;
    break;
    case 'y':
      Observer_angle_y--;
    break;
    case 'o':
      Observer_distance/=1.2;
    break;
    }
  }
}

bool _camara::getIsOrtho() const{
  return isOrtho;
}

float _camara::getAngleX() const{
  return Observer_angle_x;
}

float _camara::getAngleY() const{
  return Observer_angle_y;
}