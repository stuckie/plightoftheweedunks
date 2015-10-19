#include "MEntity.h"

MEntity::MEntity()
{
    /** Constructor */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    MaxEntities = 0;
}

MEntity::~MEntity()
{
    /** Destructor */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();

    EntityListITR.Start();
    while (EntityListITR.Valid())
    {
        EntityList.Remove(EntityListITR);
        EntityListITR.Forth();
    }
}

int MEntity::EntityCount( void )
{
    return EntityList.Size();
}

void MEntity::SetMaxEntities( int value )
{
    MaxEntities = value;
}

int MEntity::CurrentMax ( void )
{
    return MaxEntities;
}

bool MEntity::AddEntity(IEntity *Entity)
{
    /** Add an Entity */
    EntityList.Append(Entity);

    return true;
}

bool MEntity::UpdateEntities( void )
{
    /** Update Entities */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        EntityListITR.Item()->Update();

    return true;
}

bool MEntity::CheckExist(std::string Name)
{
    /** Check an Entity */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return true;

    return false;
}

bool MEntity::DelEntity(std::string Name)
{
    /** Remove an Entity */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityList.Remove(EntityListITR);
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::MoveTo ( std::string Name, SGZVECTOR vector )
{
    /** Move to direct co-ordinates */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->MoveTo( vector );
            return true;
        }
    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::LookTo ( std::string Name, SGZVECTOR vector )
{
    /** Direction to look at ( move towards ) */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->LookTo( vector );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::MoveDeltaX ( std::string Name, SGZVECTORVAL amount )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->MoveDeltaX( amount );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::MoveDeltaY ( std::string Name, SGZVECTORVAL amount )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->MoveDeltaY( amount );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::MoveDeltaZ ( std::string Name, SGZVECTORVAL amount )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->MoveDeltaZ( amount );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::Scale ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->Scale( value );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::ScaleX ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->ScaleX( value );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::ScaleY ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->ScaleY( value );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::ScaleZ ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->ScaleZ( value );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::RotateX ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->RotateX( value );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::RotateY ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->RotateY( value );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::RotateZ ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->RotateZ( value );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::MaxAccel ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->MaxAccel( value );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::SetAccel ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->SetAccel( value );
            return false;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::SetWidth ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->SetWidth( value );
            return false;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::SetHeight ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->SetHeight( value );
            return false;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::SetDepth ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->SetDepth( value );
            return false;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::MaxSpeed ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->MaxSpeed( value );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::SetSpeed ( std::string Name, SGZSCALER value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->SetSpeed( value );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::Stop ( std::string Name )
{
    /** Stop moving/rotating/scaling immediately */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->Stop( );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::SetCollisionGeom ( std::string Name, int type )
{
    /** Set the collision type */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->SetCollisionGeom( type );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::SetAnimation( std::string Name, std::string AnimName )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->SetAnimation( AnimName );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::CreateAnimation( std::string Name, std::string AnimName )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->CreateAnimation( AnimName );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::DeleteAnimation( std::string Name, std::string AnimName )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->DeleteAnimation( AnimName );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}


bool MEntity::LoadFrame ( std::string Name, std::string AnimName, std::string TexName, std::string MaskName, int FrameDelay, int u, int v, SGZCOLOUR ColourKey )
{
    /** Load up a Texture into an Animation*/
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->LoadFrame( AnimName, TexName, MaskName, FrameDelay, u, v, ColourKey );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

SGZSCALER MEntity::GetX ( std::string Name )
{
    /** Return the current X Position */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return EntityListITR.Item()->GetX();

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return 0;
}

SGZSCALER MEntity::GetY ( std::string Name )
{
    /** Return the current X Position */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return EntityListITR.Item()->GetY();

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return 0;
}

SGZSCALER MEntity::GetZ ( std::string Name )
{
    /** Return the current X Position */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return EntityListITR.Item()->GetZ();

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return 0;
}

SGZSCALER MEntity::GetWidth ( std::string Name )
{
    /** Return the current width */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return EntityListITR.Item()->GetWidth();

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return 0;
}

SGZSCALER MEntity::GetHeight ( std::string Name )
{
    /** Return the current width */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return EntityListITR.Item()->GetHeight();

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return 0;
}

SGZSCALER MEntity::GetDepth ( std::string Name )
{
    /** Return the current width */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return EntityListITR.Item()->GetDepth();

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return 0;
}


SGZSCALER MEntity::GetLookX ( std::string Name )
{
    /** Return the current X Position */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return EntityListITR.Item()->GetLookX();

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return 0;
}

SGZSCALER MEntity::GetLookY ( std::string Name )
{
    /** Return the current X Position */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return EntityListITR.Item()->GetLookY();

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return 0;
}

SGZSCALER MEntity::GetLookZ ( std::string Name )
{
    /** Return the current X Position */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return EntityListITR.Item()->GetLookZ();

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return 0;
}

SGZSCALER MEntity::GetSpeed ( std::string Name )
{
    /** Return the current X Position */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return EntityListITR.Item()->GetSpeed();

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return 0;
}

SGZSCALER MEntity::GetAccel ( std::string Name )
{
    /** Return the current X Position */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return EntityListITR.Item()->GetAccel();

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return 0;
}

std::string MEntity::GetAnimation( std::string Name )
{
    /** Return the current X Position */
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return EntityListITR.Item()->GetAnimation();

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return "none";
}

bool MEntity::Colour ( std::string Name, SGZCOLOUR col )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->Colour( col );
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::NewVar ( std::string Name, std::string VarName )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->NewVar(VarName);
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::DeleteVar ( std::string Name, std::string VarName )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->DeleteVar(VarName);
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

bool MEntity::ChangeVar ( std::string Name, std::string VarName, std::string Value )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
        {
            EntityListITR.Item()->ChangeVar(VarName, Value);
            return true;
        }

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return false;
}

std::string MEntity::CheckVar ( std::string Name, std::string VarName )
{
    SListIterator<IEntity*> EntityListITR = EntityList.GetIterator();
    for( EntityListITR.Start(); EntityListITR.Valid(); EntityListITR.Forth() )
        if(EntityListITR.Item()->GetName().compare(Name)==0)
            return EntityListITR.Item()->CheckVar(VarName);

    SGZLogger.warn("Entity %s does not exist!\n", Name.c_str());
    return "none";
}

