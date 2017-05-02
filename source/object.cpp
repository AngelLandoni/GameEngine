//
//  object.cpp
//  GameEngine
//
//  Created by Angel Land on 27/12/15.
//  Copyright © 2015 Angel Land. All rights reserved.
//

#include "object.hpp"

NAMESPACE_BEGIN( GameEngine );

Object::Object(  ){
  // Asigno un id al objeto
  _mId = ( unsigned int )numberObjects;
  // Aumento el contador de objetos
  numberObjects++;
}

Object::~Object(  ){
  // Decremento la cantidad de objetos
  numberObjects--;
}

// Retorna el id del objeto
unsigned int Object::getId(  ){
  return _mId;
}

unsigned int Object::getNumObjects(  ) const{
  return numberObjects;
}

// Inicializo el contador de objetos en 0
std::atomic<unsigned int> Object::numberObjects( 0 );

NAMESPACE_END( GameEngine );