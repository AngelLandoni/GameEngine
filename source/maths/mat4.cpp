//
//  mat4.cpp
//  MushRoom
//
//  Created by Angel Land on 7/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifdef __GAMEENGINE_MAT4_HPP__

NAMESPACE_BEGIN( GameEngine );

template<typename T>
Mat4<T>::Mat4(  ){
  for( int i=0; i<4; i++ )
    for( int j=0;j<4;j++ )
      _mElements[i][j] = 0.0f;
}

template<typename T>
Mat4<T>::Mat4( T _diagonal ){
  for( int i=0;i<4;i++ ) for( int j=0;j<4;j++ )
    if( j-i == 0 ) _mElements[i][j] = _diagonal;
    else _mElements[i][j] = 0.0;
}

template<typename T>
Mat4<T> Mat4<T>::identity( ){
  return Mat4<T>( 1.0f );
}

template<typename T>
void Mat4<T>::set( const T _value ){
  for( int i=0;i<4;i++ )
    for( int j=0;j<4;j++ )
      _mElements[i][j] = _value;
}

template<typename T>
void Mat4<T>::multiply( const Mat4<T>& _mat ){
  unsigned int i=0,j=0,l=0;
  Mat4<T> result;
  T sum = 0;
  
  for( i=0;i<4;i++ ) for( j=0;j<4;j++ ){
    for( l=0;l<4;l++ )
      sum += ( _mElements[i][l] * _mat._mElements[l][j] );
    result._mElements[i][j] = sum;
    sum = 0;
  }
  
  for( i=0;i<4;i++ ) for( j=0;j<4;j++ )
    _mElements[i][j] = result._mElements[i][j];
}

template<typename T>
Mat4<T> Mat4<T>::operator*( const Mat4<T>& _mat ){
  return multiply( _mat );
}

template<typename T>
void Mat4<T>::operator=( const Mat4<T>& _mat ){
  unsigned i=0,j=0;
  for( i=0;i<4;i++ ) for( j=0;j<4;j++ )
    _mElements[i][j] = _mat._mElements[i][j];
}

template<typename T>
void Mat4<T>::operator()( const Mat4<T>& _mat ){
  unsigned int i=0,j=0;
  for( i=0;i<4;i++ )
    for( j=0;j<4;j++ )
      _mElements[i][j] = _mat._mElements[i][j];
}

template<typename T>
Mat4<T> Mat4<T>::orthographic( T _left,T _right,T _top,T _bottom, T _near,T _far ){
  Mat4<T> result( 1.0 );
  
  result._mElements[0][0] = 2.0 / ( _right - _left );
  result._mElements[1][1] = 2.0 / ( _top - _bottom );
  result._mElements[2][2] = 2.0 / ( _far - _near );
  
  result._mElements[0][3] = -1*( ( _right+_left ) / ( _right-_left ) );
  result._mElements[1][3] = -1*( ( _top+_bottom ) / ( _top-_bottom ) );
  result._mElements[2][3] = -1*( ( _far+_near ) / ( _far-_near ) );
  
  return result;
}

template<typename T>
Mat4<T> Mat4<T>::perspective( T _fov, T _aspectRatio, T _near, T _far ){
  Mat4<T> result( 0.0 );
  
  result._mElements[0][0] = 1/( _aspectRatio*std::tan( TORADIAN*(_fov/2) ) );
  result._mElements[1][1] = 1/( std::tan( TORADIAN*( _fov/2 ) ) );
  result._mElements[2][2] = -1*( ( _far+_near )/( _far-_near ) );
  
  result._mElements[3][2] = -1;
  
  result._mElements[2][3] = -1*( (2*_far*_near)/(_far-_near) );
  
  return result;
}

template<typename T>
Mat4<T> Mat4<T>::translation( const Vec3<T>& _translation ){
  Mat4<T> result(1.0);
  result._mElements[0][3] = _translation._mX;
  result._mElements[1][3] = _translation._mY;
  result._mElements[2][3] = _translation._mZ;
  result.log(  );
  return result;
}

template<typename T>
Mat4<T> Mat4<T>::scale( const Vec3<T> &_axis ){
  Mat4<T> result( 1.0 );
  result._mElements[0][0] = _axis._mX;
  result._mElements[1][1] = _axis._mY;
  result._mElements[2][2] = _axis._mZ;
  return result;
}

template<typename T>
void Mat4<T>::log(  ){
  for( int i=0; i<4; i++ ){
    for( int j=0;j<4;j++ ){
      std::cout<<_mElements[i][j]<<" ";
    }
    std::cout<<std::endl;
  }
}

NAMESPACE_END( GameEngine );

#endif