#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H
#include <TObject.h>


class MovingObject : public TObject {
    public: 
    MovingObject();
    MovingObject(Double_t vx, Double_t vy, Double_t vz);
    virtual ~MovingObject();
    

    Double_t Vx();
    Double_t Vy();
    Double_t Vz();

    Double_t Speed();
    Double_t HorizontalSpeed();

    void SetVelocity(Double_t vx, Double_t vy, Double_t vz);

    private:
    Double_t fVx;
    Double_t fVy;
    Double_t fVz;


    ClassDef(MovingObject, 1);   //Event class
};


#endif
