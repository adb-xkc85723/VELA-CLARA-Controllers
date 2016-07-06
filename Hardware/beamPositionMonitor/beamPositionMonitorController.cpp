#include "beamPositionMonitorController.h"
// stl
#include <iostream>
// djs
#include "beamPositionMonitorInterface.h"

//______________________________________________________________________________
beamPositionMonitorController::beamPositionMonitorController( const std::string configFileLocation, const  bool show_messages, const bool show_debug_messages )
: controller( show_messages, show_debug_messages ), localInterface( configFileLocation, &SHOW_MESSAGES, &SHOW_DEBUG_MESSAGES )
{
    initialise();
}
//______________________________________________________________________________
beamPositionMonitorController::beamPositionMonitorController( const  bool show_messages, const bool show_debug_messages  )
: controller( show_messages, show_debug_messages ), localInterface( &SHOW_MESSAGES, &SHOW_DEBUG_MESSAGES )
{
    initialise();
}
//______________________________________________________________________________
void beamPositionMonitorController::initialise()
{
    if( localInterface.interfaceInitReport() )
        message("beamPositionMonitorController instantiation success.");
}
//______________________________________________________________________________
beamPositionMonitorController::~beamPositionMonitorController(){}    //dtor
//______________________________________________________________________________
beamPositionMonitorStructs::rawDataStruct beamPositionMonitorController::getAllBPMData( const std::string & name, size_t N )
{
    return localInterface.getAllBPMData( name, N );
}
//______________________________________________________________________________
std::vector< std::vector< double > > beamPositionMonitorController::getBPMRawData( const std::string & name )
{
    return localInterface.getBPMRawData( name );
}
//______________________________________________________________________________
std::vector< double > beamPositionMonitorController::getBPMXVec( const std::string & name )
{
    return localInterface.getBPMXVec( name );
}
//______________________________________________________________________________
std::vector< double > beamPositionMonitorController::getBPMYVec( const std::string & name )
{
    return localInterface.getBPMYVec( name );
}
//______________________________________________________________________________
std::vector< double > beamPositionMonitorController::getBPMQVec( const std::string & name )
{
    return localInterface.getBPMQVec( name );
}
//______________________________________________________________________________
std::vector< double > beamPositionMonitorController::getTimeStamps( const std::string & name )
{
    return localInterface.getTimeStamps( name );
}
//______________________________________________________________________________
std::vector< std::string > beamPositionMonitorController::getStrTimeStamps( const std::string & name )
{
    return localInterface.getStrTimeStamps( name );
}
//______________________________________________________________________________
void beamPositionMonitorController::monitorDataForNShots( size_t N, const std::string & bpmNames )
{
    localInterface.monitorDataForNShots( N, bpmNames );
}
//______________________________________________________________________________
void beamPositionMonitorController::reCalAtt( const std::string & name, double qScope )
{
    localInterface.reCalAtt( name, qScope );
}
//______________________________________________________________________________
double beamPositionMonitorController::getX( const std::string & name )
{
    return localInterface.getX( name );
}
//______________________________________________________________________________
double beamPositionMonitorController::getY( const std::string & name )
{
    return localInterface.getY( name );
}
//______________________________________________________________________________
double beamPositionMonitorController::getQ( const std::string & name )
{
    return localInterface.getQ( name );
}
//______________________________________________________________________________
double beamPositionMonitorController::getXFromPV( const std::string & name )
{
    return localInterface.getXFromPV( name );
}
//______________________________________________________________________________
double beamPositionMonitorController::getYFromPV( const std::string & name )
{
    return localInterface.getYFromPV( name );
}
//______________________________________________________________________________
long beamPositionMonitorController::getRA1( const std::string & name )
{
    return localInterface.getRA1( name );
}
//______________________________________________________________________________
long beamPositionMonitorController::getRA2( const std::string & name )
{
    return localInterface.getRA2( name );
}
//______________________________________________________________________________
long beamPositionMonitorController::getRD1( const std::string & name )
{
    return localInterface.getRD1( name );
}
//______________________________________________________________________________
long beamPositionMonitorController::getRD2( const std::string & name )
{
    return localInterface.getRD2( name );
}
//______________________________________________________________________________
void beamPositionMonitorController::setSA1( const std::string & bpmName, long sa1 )
{
    localInterface.setSA1( bpmName, sa1 );
}
//______________________________________________________________________________
void beamPositionMonitorController::setSA2( const std::string & bpmName, long sa2 )
{
    localInterface.setSA2( bpmName, sa2 );
}
//______________________________________________________________________________
void beamPositionMonitorController::setSD1( const std::string & bpmName, long sd1 )
{
    localInterface.setSD1( bpmName, sd1 );
}
//______________________________________________________________________________
void beamPositionMonitorController::setSD2( const std::string & bpmName, long sd2 )
{
    localInterface.setSD2( bpmName, sd2 );
}
////______________________________________________________________________________
std::vector< std::string > beamPositionMonitorController::getBPMNames()
{
    return localInterface.getBPMNames();
}
////______________________________________________________________________________
//bool beamPositionMonitorController::hasTrig( const std::string & name )
//{
//    return localInterface.hasTrig( name );
//}
////______________________________________________________________________________
//bool beamPositionMonitorController::hasNoTrig( const std::string & name )
//{
//    return localInterface.hasNoTrig( name );
//}
////______________________________________________________________________________
//VELA_ENUM::TRIG_STATE  beamPositionMonitorController::getBPMState( const std::string & name )
//{
//    return localInterface.getBPMState( name );
//}
////______________________________________________________________________________
//std::string beamPositionMonitorController::getBPMStateStr( const std::string & name )
//{
//    return ENUM_TO_STRING(localInterface.getBPMState( name ));
//}
//______________________________________________________________________________
std::map< VELA_ENUM::ILOCK_NUMBER, VELA_ENUM::ILOCK_STATE > beamPositionMonitorController::getILockStates( const std::string & objName )
{
    return localInterface.getILockStates( objName );
}
//______________________________________________________________________________
std::map< VELA_ENUM::ILOCK_NUMBER, std::string > beamPositionMonitorController::getILockStatesStr( const std::string & objName )
{
    return localInterface.getILockStatesStr( objName );
}
//______________________________________________________________________________
double beamPositionMonitorController::get_CA_PEND_IO_TIMEOUT()
{
    return localInterface.get_CA_PEND_IO_TIMEOUT( );
}
//______________________________________________________________________________
void beamPositionMonitorController::set_CA_PEND_IO_TIMEOUT( double val )
{
    localInterface.set_CA_PEND_IO_TIMEOUT( val );
}