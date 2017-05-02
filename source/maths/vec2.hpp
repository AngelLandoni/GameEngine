//
//  vec2.hpp
//  GameEngine
//
//  Created by Angel Land on 9/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_VEC2_HPP__
#define __GAMEENGINE_VEC2_HPP__

#include "../utils/helpers.hpp"

NAMESPACE_BEGIN( GameEngine );

template<typename T>
struct Vec2{
  T x,y;
  Vec2(  );
  Vec2( const Vec2<T>& _vec );
  Vec2( T _x, T _y );
  virtual ~Vec2(  );
  
  Vec2 operator+( const Vec2& _v ) const;
  void operator+=( const Vec2& _v );
  Vec2 operator-( const Vec2& _v ) const;
  void operator-=( const Vec2& _v );
  
  bool operator==( const Vec2& _v ) const;
  bool operator!=( const Vec2& _v ) const;
};

NAMESPACE_END( GameEngine );

#include "vec2.cpp"

#endif /* __GAMEENGINE_VEC2_HPP__ */
