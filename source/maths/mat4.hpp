//
//  mat4.hpp
//  MushRoom
//
//  Created by Angel Land on 7/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_MAT4_HPP__
#define __GAMEENGINE_MAT4_HPP__

#include <cmath>

#include "../utils/helpers.hpp"

#include "vec3.hpp"

#define TORADIAN (3.1415/180)

NAMESPACE_BEGIN( GameEngine );

template<typename T>
struct Mat4{
  T _mElements[4][4];
  Mat4(  );
  Mat4( T _diagonal );
  
  void set( const T _value );
  
  void multiply( const Mat4& _mat );
  Mat4 operator*( const Mat4& _mat );
  
  void operator=( const Mat4& _mat );
  
  void operator()( const Mat4& _mat );
  
  static Mat4 identity(  );
  
  static Mat4 orthographic( T _left,T _right,T _top,T _bottom, T _near,T _far );
  static Mat4 perspective( T _fov, T _aspectRatio, T _near, T _far );

  static Mat4 translation( const Vec3<T>& _translation  );
  static Mat4 rotation( const T& _angle,const Vec3<bool>& _axis );
  static Mat4 scale( const Vec3<T>& _axis );
  
  void log(  );
};

NAMESPACE_END( GameEngine );

#include "mat4.cpp"

#endif /* __GAMEENGINE_MAT4_HPP__ */
