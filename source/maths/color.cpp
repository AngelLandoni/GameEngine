//
//  color.cpp
//  GameEngine
//
//  Created by Angel Land on 9/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "color.hpp"


NAMESPACE_BEGIN( GameEngine );


Color::Color(  ) :
r(0.0),
g(0.0),
b(0.0),
a(1.0){}


Color::Color( float _r,float _g,float _b,float _a ) :
r( _r ),
g( _g ),
b( _b ),
a( _a ){}

Color::Color( int _hexColor ){
  r = ((_hexColor >> 16) & 0xFF) / 255.0;
  g = ((_hexColor >> 8) & 0xFF) / 255.0;
  b = ((_hexColor) & 0xFF) / 255.0;
  a = 1.0f;
}

Color::~Color(  ){  }

void Color::operator=( const Color& _color ){
  float _r = _color.r;
  float _g = _color.g;
  float _b = _color.b;
  r = _r;
  g = _g;
  b = _b;
}

void Color::operator()( const Color& _color ){
  float _r = _color.r;
  float _g = _color.g;
  float _b = _color.b;
  r = _r;
  g = _g;
  b = _b;
}

void flipRGBData( void* _data,unsigned int _size ){
  char* _dataC = static_cast<char*>(_data);
  unsigned int i=0;
  char temp1[3];
  while( i<=_size-i-3 ){
    memcpy( &temp1,&_dataC[_size-i-3],3 );
    memcpy( &_dataC[_size-i-3],&_dataC[i],3 );
    memcpy( &_dataC[i],&temp1,3 );
    i+=3;
  }
}

void flipRGBAData( void* _data,unsigned int _size ){
  char* _dataC = static_cast<char*>(_data);
  unsigned int i=0;
  char temp1[4];
  while( i<=_size-i-4 ){
    memcpy( &temp1,&_dataC[_size-i-4],4 );
    memcpy( &_dataC[_size-i-4],&_dataC[i],4 );
    memcpy( &_dataC[i],&temp1,4 );
    i+=4;
  }
}

NAMESPACE_END( GameEngine );