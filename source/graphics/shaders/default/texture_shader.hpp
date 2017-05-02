//
//  texture_shader.hpp
//  GameEngine
//
//  Created by Angel Land on 11/3/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_TEXTURESHADER_HPP__
#define __GAMEENGINE_TEXTURESHADER_HPP__

#include "../../../utils/helpers.hpp"

NAMESPACE_BEGIN(GameEngine);

const std::string TEXTURE_VERTEXSHADER = R"(

#version 330

layout(location = 0)in vec3 Position;
layout(location = 1)in vec4 Color;
layout(location = 2)in vec2 TextCoord;
layout(location = 3)in vec3 Normal;

uniform mat4 projection;
uniform mat4 view;

uniform mat4 transform;

out vec2 vs_uv;

void main(  ){
  vec4 worldPosition = transform * vec4(Position,1.0f);
  vec4 poisitionRelativeToCamera = view * worldPosition;
  
  vec4 pos = projection * poisitionRelativeToCamera;
  gl_Position = pos;
  vs_uv = TextCoord;
}


)";

const std::string TEXTURE_FRAGMENTSHADER = R"(


#version 330

uniform sampler2D textData;

out vec4 fragColor;

in vec2 vs_uv;

void main(){
  fragColor = texture( textData,vs_uv );
}

)";

NAMESPACE_END(GameEngine);

#endif /* __GAMEENGINE_TEXTURESHADER_HPP__ */
