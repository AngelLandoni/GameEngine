//
//  normal_shader.hpp
//  GameEngine
//
//  Created by Angel Land on 7/2/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_NORMALSHADER_HPP__
#define __GAMEENGINE_NORMALSHADER_HPP__

#include "../../../utils/helpers.hpp"

NAMESPACE_BEGIN(GameEngine);

const std::string NORMAL_VERTEXSHADER = R"(

#version 330

layout(location = 0)in vec3 Position;
layout(location = 1)in vec4 Color;
layout(location = 2)in vec2 TextCoord;
layout(location = 3)in vec3 Normal;

uniform mat4 projection;
uniform mat4 view;

uniform mat4 transform;

// Light
uniform vec3 light_position = vec3(0,0,0);

out vec2 vs_uv;
out vec3 vs_normal;
out vec3 lightVector;

out vec4 vs_posititon;

out vec3 cameraVector;

void main(  ){
  vec4 worldPosition = transform * vec4(Position,1.0f);
  vec4 poisitionRelativeToCamera = view * worldPosition;
  
  vec4 pos = projection * poisitionRelativeToCamera;
  gl_Position = pos;
  vs_uv = TextCoord;

  vs_normal = (transform * vec4(Normal,1.0)).xyz;
  
  lightVector = light_position - worldPosition.xyz;
  
  vs_posititon = worldPosition;
  
  
  cameraVector = (inverse(view)*vec4(0.0,0.0,0.0,1.0f)).xyz - worldPosition.xyz;
}
)";

const std::string NORMAL_FRAGMENTSHADER = R"(

#version 330

out vec4 fragColor;

in vec2 vs_uv;
in vec3 vs_normal;
in vec3 lightVector;

in vec4 vs_posititon;

in vec3 cameraVector;

uniform sampler2D textData;

uniform vec3 light_color = vec3(1.0,1.0,1.0);
uniform float atenuation = 5;
uniform float reflective = 0.9;

void main(){

  // DIFFUSE BEGIN
  vec3 unitNormal = normalize(vs_normal);
  vec3 unitLightDir = normalize(lightVector);
  
  float lengthLight = length(lightVector);

  vec4 finalColor;

  float brightness = max( dot( unitNormal,unitLightDir ),0.0 );
  vec3 lightColorI = (brightness * light_color)/lengthLight*atenuation;
    
  finalColor = texture( textData,vs_uv ) * vec4( lightColorI, 1.0 );
  // DIFFUSE END
  
  
  // SPECULAR BEGIN
  vec3 normalCamera = normalize(cameraVector);
  
  vec3 lightDirection = -unitLightDir;
  vec3 reflectedLightDir = reflect( lightDirection,unitNormal );
  
  float specularFactor = dot(reflectedLightDir,normalCamera);
  specularFactor = max(specularFactor,0.0);
  
  
  float specularLight = pow( specularFactor,10.0f );
  
  vec3 specularFinal = specularLight * light_color;
  
  finalColor += vec4( specularFinal, 1.0) * reflective ;
  // SPECULAR END

  fragColor = finalColor;
}

)";

NAMESPACE_END(GameEngine);

#endif /* __GAMEENGINE_NORMALSHADER_HPP__ */
