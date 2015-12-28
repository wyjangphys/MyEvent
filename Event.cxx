#include <iostream>

#include "RVersion.h"
#include "TRandom.h"
#include "TDirectory.h"
#include "TProcessID.h"

#include "Event.h"

ClassImp(Event)

Event::Event() : fIsValid(kFALSE)
{
}

Event::~Event()
{
}

void Event::SetX(float vx)
{
  x = vx;
}
