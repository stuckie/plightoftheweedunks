#ifndef _PARTICLES_H_
#define _PARTICLES_H_

#include "Horde3D.h"
#include <vector>
#include "typedefs.h"
#include "CRandom.h"
#include "CSLinkedlist.h"

using namespace std;

struct ParticleEmitter
{
    NodeHandle node;
};

class CParticles
{
public:
    void reset(void);
    int addStream(const NodeHandle _obj, const ResHandle _particles);
    int addStream(const char* _obj, const ResHandle _particles);
    int addStream(const SGZVECTOR _pos, const ResHandle _particles);
    void addBox(const SGZVECTOR _pos, const SGZVECTOR _size, const int _numStreams, const ResHandle _particles);
    void updateParticles(void);
protected:
    SLinkedList<ParticleEmitter*> EmitterList;         //!< List of Emitters
	SListIterator<ParticleEmitter*> EmitterListITR;    //!< Iterator to the Emitter List
    CRandom random;
};

#endif // _PARTICLES_H_
