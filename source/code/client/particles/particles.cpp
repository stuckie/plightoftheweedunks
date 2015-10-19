#include "particles.h"
#include "arch.h"
#include "CDebug.h"

void CParticles::reset(void)
{
    SListIterator<ParticleEmitter*> EmitterListITR = EmitterList.GetIterator();
    EmitterListITR.Start();
    while (EmitterListITR.Valid())
    {
        EmitterList.Remove(EmitterListITR);
        EmitterListITR.Forth();
    }
    random.Randomise();
}

int CParticles::addStream(const NodeHandle _obj, const ResHandle _particles)
{
    ParticleEmitter *emitter = new ParticleEmitter;
    emitter->node = Horde3D::addNodes(_obj, _particles);
    EmitterList.Append(emitter);

    return emitter->node;
}

int CParticles::addStream(const char* _obj, const ResHandle _particles)
{
    Horde3D::findNodes(RootNode, _obj, SceneNodeTypes::Undefined);
    int nodeIndex = Horde3D::getNodeFindResult(0);
    if (nodeIndex>0)
    {
        ParticleEmitter *emitter = new ParticleEmitter;
        emitter->node = Horde3D::addNodes(nodeIndex, _particles);
        EmitterList.Append(emitter);

        return emitter->node;
    }
    else
        return 0;
}

int CParticles::addStream(const SGZVECTOR _pos, const ResHandle _particles)
{
    ParticleEmitter *emitter = new ParticleEmitter;
    emitter->node = Horde3D::addNodes(RootNode, _particles);
    Horde3D::setNodeTransform(emitter->node, _pos.x,_pos.y,_pos.z, 0,0,0, 1,1,1);
    EmitterList.Append(emitter);

    return emitter->node;
}

void CParticles::addBox(const SGZVECTOR _pos, const SGZVECTOR _size, const int _numStreams, const ResHandle _particles)
{
    SGZVECTOR min;
    min.x = _pos.x - (0.5*_size.x);
    min.y = _pos.y - (0.5*_size.y);
    min.z = _pos.z - (0.5*_size.z);

    for (int cnt = 0; cnt < _numStreams; cnt++)
    {
        float x = min.x + (random.Random()*_size.x);
        float y = min.y + (random.Random()*_size.y);
        float z = min.z + (random.Random()*_size.z);

        ParticleEmitter *emitter = new ParticleEmitter;
        emitter->node = Horde3D::addNodes(RootNode, _particles);
        Horde3D::setNodeTransform(emitter->node, x,y,z, 0,0,0, 1,1,1);
        EmitterList.Append(emitter);
    }
}

void CParticles::updateParticles(void)
{
    SListIterator<ParticleEmitter*> EmitterListITR = EmitterList.GetIterator();
    EmitterListITR.Start();
    while (EmitterListITR.Valid())
    {
        int parts = Horde3D::findNodes( EmitterListITR.Item()->node, "", SceneNodeTypes::Emitter );

        for (int part=0; part<parts; part++ )   // running through backward so killThese is filled with index's from highest to lowest
        {
            NodeHandle node = Horde3D::getNodeFindResult(part);
            if (node>0)
            {
                Horde3D::advanceEmitterTime(node, 1.0f / SGZ_FRAME_LOCK );
                if (Horde3D::hasEmitterFinished(node))
                {
                    EmitterList.Remove(EmitterListITR);
                    Horde3D::removeNode(node);
                }
            }
        }
        EmitterListITR.Forth();
    }
}
