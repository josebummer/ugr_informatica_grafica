//**************************************************************************
// Práctica 2
//
// Jose Antonio Ruiz Millan 2017-2018
//
// Revolucion y Barrido
//**************************************************************************

//**************************************************************************
// Objetos:
//
// '1' --> Tetraedro
// '2' --> Cubo
// '3' --> Piramide
// '4' --> Rombo
// '5' --> Ply
// '6' --> Revolucion
// '7' --> Barrido
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
    //{3.0,0.0,0.0},
    //{6.0,2.0,0.0},
    //{1.0,4.0,0.0},
    //{0.0,6.0,0.0}
     {0.0,0.0,0.0},
     {1.0,0.0,0.0},
     {2.0,2.0,0.0},
     {0.0,2.0,0.0}
     //{4.0,6.0,0.0},
     //{0.0,6.0,0.0}
  };

  if(num > 2) this->parametros(perfil, num);
  else this->parametros(perfil, 3);


}

void _rotacion::parametros(const vector<_vertex3f> &perfil1, int num1){
  perfil = perfil1;
  num = num1;
  float variable;
  vertices.reserve(perfil.size()*num);
  for(int i = 0; i < num; i++){
    for (unsigned int j = 0; j < perfil.size(); j++) {
      vertices.push_back(_vertex3f(
        (perfil[j].x+variable)*cos(2.0*M_PI*i/(1.0*num))+ (perfil[j].z)*sin(2.0*M_PI*i/(1.0*num)),   // valor de x
        perfil[j].y,                                                                    // valor de y
        (perfil[j].x+variable)*(-sin(2.0*M_PI*i/(1.0*num)))+(perfil[j].z)*cos(2.0*M_PI*i/(1.0*num))  //valor de z
      ));
    }
    variable+=0.2;
    
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
  }
}
