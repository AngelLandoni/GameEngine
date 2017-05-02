//
//  vec3.cpp
//  GameEngine
//
//  Created by Angel Land on 7/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifdef __GAMEENGINE_VEC3_HPP__

NAMESPACE_BEGIN( GameEngine );

template <typename T>
Vec3<T>::Vec3() :
x( 0 ),
y( 0 ),
z( 0 )
{}

template <typename T>
Vec3<T>::Vec3( T _x, T _y, T _z ) :
x( _x ),
y( _y ),
z( _z )
{}

template <typename T>
Vec3<T> Vec3<T>::operator+( const Vec3<T>& _v ) const{
  return Vec3<T>( x+_v.x,y+_v.y,z+_v.z );
}

template <typename T>
void Vec3<T>::operator+=( const Vec3<T> &_v ) const{
  x += _v.x;
  y += _v.y;
  z += _v.z;
}

template <typename T>
Vec3<T> Vec3<T>::operator-( const Vec3<T> &_v ) const{
  return Vec3<T>( x-_v.x,y-_v.y,z-_v.z );
}

template <typename T>
void Vec3<T>::operator-=( const Vec3<T> &_v ) const{
  x -= _v.x;
  y -= _v.y;
  z -= _v.z;
}

template <typename T>
bool Vec3<T>::operator==( const Vec3<T> &_v ) const{
  if( x == _v.x && y == _v.y && z == _v.z )
    return true;
  return false;
}

template <typename T>
bool Vec3<T>::operator!=( const Vec3<T> &_v ) const{
  if( x != _v.x && y != _v.y && z != _v.z )
    return true;
  return false;
}

NAMESPACE_END( GameEngine );

#endif