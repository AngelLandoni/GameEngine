//
//  color.hpp
//  GameEngine
//
//  Created by Angel Land on 9/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_COLOR_HPP__
#define __GAMEENGINE_COLOR_HPP__

#include <atomic>
#include <cstring>

#include "../utils/helpers.hpp"

NAMESPACE_BEGIN( GameEngine );

struct Color{
  std::atomic<float> r,g,b,a;
  Color(  );
  Color( float _r,float _g, float _b, float _a );
  Color( int _hexColor );
  virtual ~Color(  );
  
  void operator=( const Color& _color );
  void operator()( const Color& _color );

  enum{
    black = 0x000000,
    red = 0xFF0000,
    green = 0x00FF00,
    blue = 0x0000FF,
    blackLight = 0x242424,
    white=0xFFFFFF
  };

  enum{ R,G,B,A };
};

// Invierte una imagen
void flipRGBData( void* _data,unsigned int _size );
void flipRGBAData( void* _data,unsigned int _size );


NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_COLOR_HPP__ */
