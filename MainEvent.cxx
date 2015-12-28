#include <iostream>
#include <cstdlib>

#include "Riostream.h"
#include "TROOT.h"
#include "TTree.h"
#include "TBranch.h"
#include "TFile.h"
#include "TNetFile.h"
#include "TClonesArray.h"
#include "TStopwatch.h"

#include "Event.h"

//int main(int argc, char* argv[])
int main()
{
  TFile* f = new TFile("test_tree.root", "RECREATE");
  TTree* t = new TTree("t", "A Tree with Event Class");
  Event* event = new Event();
  t->Branch("event", "Event", &event, 16000, 2);

  for(Int_t ev = 0; ev < 100; ev++)
  {
    event->SetX(rand()%100);
    t->Fill();
  }
  f->Write();
  t->Print();
  return 0;
}
