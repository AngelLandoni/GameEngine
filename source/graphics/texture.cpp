#include "texture.hpp"

NAMESPACE_BEGIN( GameEngine );

Texture::Texture(  ):
_mPath(""),
_mWidth(0),_mHeight(0),
_mXOrigin(0),_mYOrigin(0),
_mBpp(0),
_mDataSize(0),
_mTextureID(0),
_mImageData(nullptr)
{  }

Texture::~Texture(  ){
  if( _mImageData != nullptr )
    delete _mImageData;
}

void Texture::bind( uint i )const{
  glActiveTexture( GL_TEXTURE0 + i );
  glBindTexture( GL_TEXTURE_2D,_mTextureID );
}

void Texture::unBind(  )const{
  glBindTexture( GL_TEXTURE_2D, 0);
  
}

NAMESPACE_END( GameEngine );
