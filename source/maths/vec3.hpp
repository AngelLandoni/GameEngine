//
//  vec3.hpp
//  GameEngine
//
//  Created by Angel Land on 7/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_VEC3_HPP__
#define __GAMEENGINE_VEC3_HPP__

#include "../utils/helpers.hpp"

NAMESPACE_BEGIN( GameEngine );

template <typename T>
struct Vec3{
  T x,y,z;
  Vec3(  );
  Vec3( T _x,T _y,T _z );
  
  Vec3 operator+( const Vec3& _v ) const;
  void operator+=( const Vec3& _v ) const;
  Vec3 operator-( const Vec3& _v ) const;
  void operator-=( const Vec3& _v ) const;

  bool operator==( const Vec3& _v ) const;
  bool operator!=( const Vec3<T>& _v ) const;
};

NAMESPACE_END( GameEngine );

#include "vec3.cpp"

#endif /* __GAMEENGINE_VEC3_HPP__ */
