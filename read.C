#include "MovingObject.h"
#include <TTree.h>
#include <TFile.h>
#include <TH2D.h>


void read() {

    auto file = TFile::Open("tree_file.root");
    TTree *tree = static_cast<TTree*>(file->Get("tree"));

    MovingObject* object = nullptr;

    tree->SetBranchAddress("object", &object);
    Long64_t N = tree->GetEntries();
    TH2D *hist = new TH2D("hist", "Velocity of Moving Object", 100, -1.5, 1.5, 100, -1.5, 1.5);

    for (Long64_t i=0; i<N; i++){
        tree->GetEntry(i);

        hist->Fill(object->Vx(), object->Vy());
        hist->GetXaxis()->SetTitle("v_{x} (m/s)");
        hist->GetYaxis()->SetTitle("v_{y} (m/s)");
    }
    //uncomment below to get histogram
    //hist->Draw("colz");

    //format: tree->Draw("y-axis values : x-axis values", "selection");
    tree->Draw("sqrt(object.fVx*object.fVx + object.fVy*object.fVy) : object.fVz" ,
        "sqrt(object.fVx*object.fVx + object.fVy*object.fVy + object.fVz*object.fVz) > 0.5");
    hist->GetXaxis()->SetTitle("v_{z} (m/s)");
    hist->GetYaxis()->SetTitle("{sqrt}(v_{x}^{2} + v_{y}^{2})");

}

