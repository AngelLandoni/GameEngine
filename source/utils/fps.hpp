//
//  fps.hpp
//  GameEngine
//
//  Created by Angel Land on 21/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_FPS_HPP__
#define __GAMEENGINE_FPS_HPP__

#include <iostream>

#include <chrono>
#include <thread>

#include "helpers.hpp"
#include "timer.hpp"

NAMESPACE_BEGIN(GameEngine);

#define FPS_DEFAULT_FRAME_LIMIT 60
#define FPS_UPDATE_RATE 1.0

class Fps{
  Timer _mTime;
  uint _mFrameCount;
  uint _mFrameLimit;
  double _mTimeElapsed;
  
  uint _mFinalFps;
public:
  Fps(  );
  Fps( uint _limit );
  virtual ~Fps(  );
  
  void update(  );
  
  void setFrameLimit( uint _limit);
  
  const double getDelta(  );
  const uint& getCurrentFrames(  );
};


NAMESPACE_END(GameEngine);

#endif /* __GAMEENGINE_FPS_HPP__ */
