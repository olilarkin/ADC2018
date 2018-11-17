#include "processor.h"

using namespace WAM;


class MyWAM : public Processor
{
public:
  MyWAM();

  const char* init(uint32_t bufsize, uint32_t sr, void* pDesc) override;
  void onProcess(WAM::AudioBus* pAudio, void* pData) override;
  void onParam(uint32_t idparam, double value) override;

private:
  float mGain = 1.f;
};
