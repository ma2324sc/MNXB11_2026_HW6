#include "MovingObject.h"
#include <cmath>


//ClassImp is a ROOT framework macro
ClassImp(MovingObject)

    //default constructor 
    MovingObject::MovingObject() :
    fVx(0),
    fVy(0),
    fVz(0) {};
    //constructor for velocity values
    MovingObject::MovingObject(Double_t vx, Double_t vy, Double_t vz) : 
    fVx(vx),
    fVy(vy),
    fVz(vz) {};
    //deconstructor 
    MovingObject::~MovingObject(){};
    
    //getters 
    Double_t MovingObject::Vx(){
        return fVx;
    };
    Double_t MovingObject::Vy(){
        return fVy;
    };
    Double_t MovingObject::Vz(){
        return fVz;
    };

    Double_t MovingObject::Speed(){
        return std::sqrt(fVx*fVx + fVy*fVy + fVz*fVz);
    };
    Double_t MovingObject::HorizontalSpeed(){
        return std::sqrt(fVx*fVx + fVy*fVy);
    };


    //set velocity to change 
    void MovingObject::SetVelocity(Double_t vx, Double_t vy, Double_t vz){
        fVx = vx;
        fVy = vy;
        fVz = vz;
    };
