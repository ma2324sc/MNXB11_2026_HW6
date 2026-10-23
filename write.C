#include "MovingObject.h"
#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>
#include <iostream>


void write(){
    TFile file("tree_file.root", "RECREATE");
    TTree* tree = new TTree ("tree", "Object Velocity");

    Double_t vx;
    Double_t vy;
    Double_t vz;
    MovingObject object;

    tree->Branch("object", &object);
    tree->Branch("vx", &vx);
    tree->Branch("vy", &vy);
    tree->Branch("vz", &vz);

    gRandom->SetSeed(12345);



    for(Int_t i=0; i<10000; i++){
        vx = gRandom->Gaus(0.0, 0.30);
        vy = gRandom->Gaus(0.0, 0.30);
        vz = gRandom->Gaus(0.0, 0.30);

        object.SetVelocity(vx, vy, vz);

        tree->Fill();

    }
file.Write();
file.Close();

}

void testMovingObject(){
    //initialize with values
    MovingObject object(0.3, 0.4, 0.0);

    //test getters
    std::cout<< "Initial velocity:" << std::endl;
    std::cout<< "Vx = " << object.Vx() << std::endl;
    std::cout<< "Vy = " << object.Vy() << std::endl;
    std::cout<< "Vz = " << object.Vz() << std::endl;
    std::cout<< "Speed = " << object.Speed() << std::endl;
    std::cout<< "Horizontal Speed = " << object.HorizontalSpeed() << std::endl;

    //change velocity
    object.SetVelocity(0.3, 0.4, 0.5);
    std::cout<< "Changed velocity:" << std::endl;
    std::cout<< "Vx = " << object.Vx() << std::endl;
    std::cout<< "Vy = " << object.Vy() << std::endl;
    std::cout<< "Vz = " << object.Vz() << std::endl;
    std::cout<< "Speed = " << object.Speed() << std::endl;
    std::cout<< "Horizontal Speed = " << object.HorizontalSpeed() << std::endl;


}




