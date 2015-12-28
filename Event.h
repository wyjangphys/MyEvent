#include "TObject.h"
#include "TClonesArray.h"
#include "TRefArray.h"
#include "TRef.h"
#include "TH1.h"
#include "TBits.h"
#include "TMath.h"

class TDirectory;

class Event : public TObject
{
  private:
    float x;
    Bool_t fIsValid;
  public:
    Event();
    virtual ~Event();
    void SetX(float vx);

    ClassDef(Event,1)
};
