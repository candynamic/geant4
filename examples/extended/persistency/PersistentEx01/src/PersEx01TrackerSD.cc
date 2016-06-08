
#include "PersEx01TrackerSD.hh"
#include "PersEx01TrackerHit.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Track.hh"
#include "G4ParticleDefinition.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"

PersEx01TrackerSD::PersEx01TrackerSD(G4String name)
:G4VSensitiveDetector(name)
{
  G4String HCname;
  collectionName.insert(HCname="EvenCollection");
  collectionName.insert(HCname="OddCollection");
}

PersEx01TrackerSD::~PersEx01TrackerSD(){;}

void PersEx01TrackerSD::Initialize(G4HCofThisEvent*HCE)
{
  EvenCollection = new 
        PersEx01TrackerHitsCollection(SensitiveDetectorName,collectionName[0]); 
  OddCollection = new 
        PersEx01TrackerHitsCollection(SensitiveDetectorName,collectionName[1]); 
}

G4bool PersEx01TrackerSD::ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist)
{
  const G4VPhysicalVolume* physVol 
    = aStep->GetPreStepPoint()->GetPhysicalVolume();
  G4double edep = aStep->GetTotalEnergyDeposit();

  PersEx01TrackerHit* newHit = new PersEx01TrackerHit();
  newHit->SetEdep( edep );
  newHit->SetPos( aStep->GetPreStepPoint()->GetPosition() );
  if( physVol->GetName() == "TPhys1" )
  { EvenCollection->insert( newHit ); }
  else if( physVol->GetName() == "TPhys2" )
  { OddCollection->insert( newHit ); }
  return true;
}

void PersEx01TrackerSD::EndOfEvent(G4HCofThisEvent*HCE)
{
  static G4int IDe = -1;
  static G4int IDo = -1;
  if(IDe<0)
  { IDe = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); }
  if(IDo<0)
  { IDo = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[1]); }
  HCE->AddHitsCollection( IDe, EvenCollection );
  HCE->AddHitsCollection( IDo, OddCollection ); 
}

void PersEx01TrackerSD::clear()
{
} 

void PersEx01TrackerSD::DrawAll()
{
} 

void PersEx01TrackerSD::PrintAll()
{
} 
