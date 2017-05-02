#ifndef __BLUEPRINT_TEXTURE_H__
#define __BLUEPRINT_TEXTURE_H__

#include <iostream>
#include <fstream>

#include "../utils/helpers.hpp"
#include "../utils/file.hpp"
#include "../../extern/glfw3/glfw3.h"

#include "../maths/color.hpp"

NAMESPACE_BEGIN( GameEngine );

struct Texture{
  std::string _mPath;
  short int _mWidth,_mHeight,_mXOrigin,_mYOrigin;
  short int _mBpp;
  uint _mDataSize;
  GLubyte* _mImageData;
  GLuint _mTextureID;
  
  Texture(  );
  virtual ~Texture(  );
  
  void bind( uint i ) const;
  void unBind(  ) const;
};

NAMESPACE_END( GameEngine );

#endif
