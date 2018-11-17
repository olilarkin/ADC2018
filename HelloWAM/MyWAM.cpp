#include "MyWAM.h"
#include <cmath>
#include <cstdlib>

MyWAM::MyWAM()
{
}

const char* MyWAM::init(uint32_t bufsize, uint32_t sr, void* pDesc)
{
  //Very ugly JSON cstring could be simplified using a library
  return "{\"audio\": { \"inputs\": [{ \"id\":0, \"channels\":0 }], \"outputs\": [{ \"id\":0, \"channels\":2 }] },\"parameters\": [{\"id\":0, \"name\":\"Gain\", \"type\":\"float\", \"min\":0.000000, \"max\":100.000000, \"default\":100.000000, \"rate\":\"control\"}]";
}

#define BPFRAND() -1. + (2. * rand()/(RAND_MAX+1.) ) // returns random value between -1. and 1.

void MyWAM::onProcess(WAM::AudioBus* pAudio, void* pData)
{
  for (int i = 0; i < 128; i++)
  {
    pAudio->outputs[0][i] = BPFRAND() * mGain;
    pAudio->outputs[1][i] = pAudio->outputs[0][i];
  }
}

void MyWAM::onParam(uint32_t idparam, double value)
{
  switch (idparam) {
    case 0:
      mGain = value / 100.;
      break;
    default:
      break;
  }
}

extern "C" { void* createModule() { return new MyWAM(); } }

