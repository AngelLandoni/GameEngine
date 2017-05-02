//
//  mesh.cpp
//  GameEngine
//
//  Created by Angel Land on 15/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "mesh.hpp"

NAMESPACE_BEGIN( GameEngine );

Mesh::Mesh(  ) :
_mVertices(nullptr),
_mUVs(nullptr),
_mNormals(nullptr),
_mColors(nullptr),
_mIndices(nullptr)
{
  glGenVertexArrays( 1,&_mVao );
}

Mesh::Mesh(std::vector<float> _vertices,
           std::vector<float> _uvs,
           std::vector<float> _colors,
           std::vector<float> _normals,
           std::vector<GLushort> _indices ):
_mVertices(new std::vector<float>( _vertices )),
_mUVs(new std::vector<float>( _uvs )),
_mColors(new std::vector<float>( _colors )),
_mNormals(new std::vector<float>(_normals)),
_mIndices(new std::vector<GLushort>( _indices )){}

Mesh::~Mesh(  ){
  if( _mVertices != nullptr )
    delete _mVertices;
  if( _mColors != nullptr )
    delete _mColors;
  if( _mIndices != nullptr )
    delete _mIndices;
  if( _mUVs != nullptr )
    delete _mUVs;
  
  glDeleteBuffers( NUMBER_VERTEXBUFFER,_mVbo );
  glDeleteVertexArrays( 1,&_mVao );
}

void Mesh::setVertices( std::vector<float> _v ){
  if( _mVertices == nullptr ) _mVertices = new std::vector<float>( _v );
  // FIX IT? swap vs *
  else _mVertices->swap(_v);
}

void Mesh::setUVs( std::vector<float> _uvs ){
  if( _mUVs == nullptr ) _mUVs = new std::vector<float>( _uvs );
  else _mUVs->swap(_uvs);
}

void Mesh::setNormals( std::vector<float> _n ){
  if( _mNormals == nullptr ){
    _mNormals =  new std::vector<float>( _n );
  }else{
    _mNormals->swap( _n );
  }
}

void Mesh::setColors( std::vector<float> _c ){
  if( _mColors == nullptr ) _mColors = new std::vector<float>( _c );
  else _mColors->swap(_c);
}

void Mesh::setIndices( std::vector<GLushort> _i ){
  if( _mIndices == nullptr ) _mIndices = new std::vector<GLushort>( _i );
  else _mIndices->swap(_i);
}

void Mesh::freeLocalMemory(  ){
  if( _mVertices != nullptr )
    delete _mVertices;
  if( _mUVs != nullptr )
    delete _mVertices;
  if( _mNormals != nullptr )
    delete _mNormals;
  if( _mColors != nullptr )
    delete _mVertices;
}

void Mesh::init(  ){
  if( _mVertices == nullptr || _mUVs == nullptr || _mColors == nullptr || _mIndices == nullptr || _mNormals == nullptr ){
    std::cerr<<"[MESH] Warning: Buffer doesn't seted!."<<std::endl;
    std::cerr.flush(  );
  }
  
  // Bindeo el vao
  glBindVertexArray(_mVao);

    // VERTICES
  
    // make and bind the VBO
    glGenBuffers(1, &_mVbo[POSITION_VERTEXBUFFER]);
    glBindBuffer(GL_ARRAY_BUFFER, _mVbo[POSITION_VERTEXBUFFER]);
    // Seteo el buffer de datos
    glBufferData(GL_ARRAY_BUFFER, _mVertices->size(  )*sizeof(GLfloat), _mVertices->data(  ), GL_STATIC_DRAW);
    
    // Setela los datos en la variable con location = 0
    glEnableVertexAttribArray(POSITION_VERTEXBUFFER);
    glVertexAttribPointer(POSITION_VERTEXBUFFER, 3, GL_FLOAT, GL_FALSE, 0, 0);

    // TEXTURA
    
    // make and bind the VBO
    glGenBuffers(1, &_mVbo[TEXTURE_VERTEXBUFFER]);
    glBindBuffer(GL_ARRAY_BUFFER, _mVbo[TEXTURE_VERTEXBUFFER]);
    // Seteo el buffer de datos
    glBufferData(GL_ARRAY_BUFFER, _mUVs->size(  )*sizeof(GLfloat), _mUVs->data(  ), GL_STATIC_DRAW);
    
    // Setela los datos en la variable con location = 1
    glEnableVertexAttribArray(TEXTURE_VERTEXBUFFER);
    glVertexAttribPointer(TEXTURE_VERTEXBUFFER, 2, GL_FLOAT, GL_FALSE, 0,0 );
    
    // NORMAL

    // memalloc
    glGenBuffers(1,&_mVbo[NORMAL_VERTEXBUFFER]);
    glBindBuffer(GL_ARRAY_BUFFER,_mVbo[NORMAL_VERTEXBUFFER]);
    // Setea el buffer en la memoria de la gpu
    glBufferData(GL_ARRAY_BUFFER,_mNormals->size( )*sizeof(GLfloat),_mNormals->data(  ),GL_STATIC_DRAW );
    
    // Setea los datos para poder acceder desde glsl
    glEnableVertexAttribArray( NORMAL_VERTEXBUFFER );
    glVertexAttribPointer(NORMAL_VERTEXBUFFER,3,GL_FLOAT,GL_FALSE,0,0);

    // COLORES
  
    // make and bind the VBO
    glGenBuffers(1, &_mVbo[COLOR_VERTEXBUFFER]);
    glBindBuffer(GL_ARRAY_BUFFER, _mVbo[COLOR_VERTEXBUFFER]);
    // Seteo el buffer de datos
    glBufferData(GL_ARRAY_BUFFER, _mColors->size(  )*sizeof(GLfloat), _mColors->data(  ), GL_STATIC_DRAW);
  
    // Setela los datos en la variable con location = 1
    glEnableVertexAttribArray(COLOR_VERTEXBUFFER);
    glVertexAttribPointer(COLOR_VERTEXBUFFER, 4, GL_FLOAT, GL_FALSE, 0,0 );
  
    // INDICES
  
    // make and bind the VBO
    glGenBuffers(1, &_mVbo[INDEX_VERTEXBUFFER]);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _mVbo[INDEX_VERTEXBUFFER]);
    // Seteo el buffer de datos
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _mIndices->size(  )*sizeof(GLushort), _mIndices->data(  ), GL_STATIC_DRAW);
  
  
  // unbind the VAO
  glBindVertexArray(0);
}

void Mesh::draw(  ){
  
  _mProgram->setUniform( "transform",_mTransform.getTransformation(  ) );
  
  
  _mProgram->enable( );
  
  
  glBindVertexArray(_mVao);
  
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER,_mVbo[INDEX_VERTEXBUFFER] );
 
  glDrawElements(GL_TRIANGLES, (uint)_mIndices->size(  ), GL_UNSIGNED_SHORT, 0);
  
  glBindBuffer( GL_ELEMENT_ARRAY_BUFFER,0 );
  
  glBindVertexArray(0);
  _mProgram->disable(  );
}



void Mesh::update(  ){
  
}

void Mesh::destroy(  ){
  
}

NAMESPACE_END( GameEngine );