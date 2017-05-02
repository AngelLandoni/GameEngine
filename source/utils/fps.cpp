//
//  fps.cpp
//  GameEngine
//
//  Created by Angel Land on 21/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "fps.hpp"

NAMESPACE_BEGIN(GameEngine);

Fps::Fps(  ) :
_mFrameCount(0),
_mFrameLimit(FPS_DEFAULT_FRAME_LIMIT),
_mTimeElapsed(0)
{
  _mTime.init(  );
}

Fps::Fps( uint _limit ):
_mFrameLimit(_limit)
{}

Fps::~Fps(  ){}

void Fps::update(  ){
  _mFrameCount++;
  const double elapsed = _mTime.elapsed(  ) - _mTimeElapsed;
  
  if( elapsed >= FPS_UPDATE_RATE ){
    _mTimeElapsed += 1.0;
    _mFinalFps = _mFrameCount;
    
    if( _mFrameCount >= _mFrameLimit ){
      std::this_thread::sleep_for(std::chrono::milliseconds(1000/_mFrameCount));
      std::cout<<"LÑIMIT"<<1000/_mFrameCount<<" "<<_mFrameCount<<" "<<_mFrameLimit<<std::endl;
      std::cout.flush();
    }
    _mFrameCount = 0;
  }
}

void Fps::setFrameLimit( uint _limit){
  _mFrameLimit = _limit;
}

const double Fps::getDelta(  ){
  return _mTime.delta(  );
}

const uint& Fps::getCurrentFrames(){
  return _mFinalFps;
}


NAMESPACE_END(GameEngine);