//
//  vec2.cpp
//  GameEngine
//
//  Created by Angel Land on 9/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifdef __GAMEENGINE_VEC2_HPP__

NAMESPACE_BEGIN( GameEngine );

template<typename T>
Vec2<T>::Vec2() :
x(0),
y(0)
{}

template<typename T>
Vec2<T>::~Vec2(  ){  }

template <typename T>
Vec2<T> Vec2<T>::operator+( const Vec2<T>& _v ) const{
  return Vec2<T>( x+_v.x,y+_v.y );
}

template <typename T>
void Vec2<T>::operator+=( const Vec2<T> &_v ){
  x += _v.x;
  y += _v.y;
}

template <typename T>
Vec2<T> Vec2<T>::operator-( const Vec2<T> &_v ) const{
  return Vec2<T>( x-_v.x,y-_v.y );
}

template <typename T>
void Vec2<T>::operator-=( const Vec2<T> &_v ){
  x -= _v.x;
  y -= _v.y;
}

template <typename T>
bool Vec2<T>::operator==( const Vec2<T>& _v ) const{
  if( x == _v.x && y == _v.y )
    return true;
  return false;
}

template <typename T>
bool Vec2<T>::operator!=( const Vec2<T> &_v ) const{
  if( x != _v.x && y != _v.y )
    return true;
  return false;
}

NAMESPACE_END( GameEngine );

#endif