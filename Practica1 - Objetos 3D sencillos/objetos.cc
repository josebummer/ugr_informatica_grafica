//**************************************************************************
// Práctica 1
//
// Jose Antonio Ruiz Millan 2017-2018
//
// Objetos basicos (cubo,piramide,tetraedro,rombo)
//**************************************************************************

//**************************************************************************
// Objetos:
//
// '1' --> Tetraedro
// '2' --> Cubo
// '3' --> Piramide
// '4' --> Rombo
//
// Formas de dibujo:
//
// 'f' --> Solido
// 'm' --> Multiples colores aleatorios
// 'n' --> Lineas
// 'p' --> Puntos
// 'c' --> Ajedrez
//
//**************************************************************************

#include "objetos.h"

_puntos3D::_puntos3D(){}

void _puntos3D::draw_puntos(float r, float g, float b, int grosor){
  glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
  glPointSize(grosor);
  glColor3f(r,g,b);
  glBegin(GL_POINTS);
  for(unsigned int i = 0; i < vertices.size(); i++){
      glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
  }
  glEnd();
}

_triangulos3D::_triangulos3D(){}

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor){
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
}

void _triangulos3D::draw_solido(float r, float g, float b){
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
  glLineWidth(3);
  glBegin(GL_TRIANGLES);
  for(unsigned int i = 0; i < caras.size(); i++){
      glVertex3fv((GLfloat *) &vertices[caras[i].x]);
      glVertex3fv((GLfloat *) &vertices[caras[i].y]);
      glVertex3fv((GLfloat *) &vertices[caras[i].z]);
  }
  glEnd();
  glLineWidth(1);
}

void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2){
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glBegin(GL_TRIANGLES);
  for(unsigned int i = 0; i < caras.size()-1; i+=2){
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
  glLineWidth(3);
  glBegin(GL_TRIANGLES);
  for(unsigned int i = 0; i < caras.size(); i++){
      glVertex3fv((GLfloat *) &vertices[caras[i].x]);
      glVertex3fv((GLfloat *) &vertices[caras[i].y]);
      glVertex3fv((GLfloat *) &vertices[caras[i].z]);
  }
  glEnd();
  glLineWidth(1);
}

_cubo::_cubo(float tam){
  caras.reserve(12);
  vertices.reserve(8);
  color.reserve(8);

  for(int i = 0; i < 8; i++){
    color.push_back(_vertex3<float>(rand()%255/(1.0*255),rand()%255/(1.0*255),rand()%255/(1.0*255)));
  }

  vertices.push_back(_vertex3<float>(-tam/2, 0.0, tam/2));
  vertices.push_back(_vertex3<float>(tam/2, 0.0, tam/2));
  vertices.push_back(_vertex3<float>(-tam/2, tam, tam/2));
  vertices.push_back(_vertex3<float>(tam/2, tam, tam/2));
  vertices.push_back(_vertex3<float>(-tam/2, 0.0, -tam/2));
  vertices.push_back(_vertex3<float>(tam/2, 0.0, -tam/2));
  vertices.push_back(_vertex3<float>(-tam/2, tam, -tam/2));
  vertices.push_back(_vertex3<float>(tam/2, tam, -tam/2));

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
  glLineWidth(3);
  glBegin(GL_TRIANGLES);
  for(unsigned int i = 0; i < caras.size(); i++){
      glVertex3fv((GLfloat *) &vertices[caras[i].x]);
      glVertex3fv((GLfloat *) &vertices[caras[i].y]);
      glVertex3fv((GLfloat *) &vertices[caras[i].z]);
  }
  glEnd();
  glLineWidth(1);
}
