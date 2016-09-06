//              This file is part of VELA-CLARA-Controllers.                          //
//------------------------------------------------------------------------------------//
//    VELA-CLARA-Controllers is free software: you can redistribute it and/or modify  //
//    it under the terms of the GNU General Public License as published by            //
//    the Free Software Foundation, either version 3 of the License, or               //
//    (at your option) any later version.                                             //
//    VELA-CLARA-Controllers is distributed in the hope that it will be useful,       //
//    but WITHOUT ANY WARRANTY; without even the implied warranty of                  //
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                   //
//    GNU General Public License for more details.                                    //
//                                                                                    //
//    You should have received a copy of the GNU General Public License               //
//    along with VELA-CLARA-Controllers.  If not, see <http://www.gnu.org/licenses/>. //

#include "scopeController.h"
// stl
#include <iostream>
// djs
#include "scopeInterface.h"

//______________________________________________________________________________
scopeController::scopeController( const std::string configFileLocation1,
                                  const std::string configFileLocation2, const  bool show_messages, const bool show_debug_messages )
: controller( show_messages, show_debug_messages ), localInterface( configFileLocation1, configFileLocation2, &SHOW_MESSAGES, &SHOW_DEBUG_MESSAGES )
{
    initialise();
}
//______________________________________________________________________________
scopeController::scopeController( const  bool show_messages, const bool show_debug_messages  )
: controller( show_messages, show_debug_messages ), localInterface( &SHOW_MESSAGES, &SHOW_DEBUG_MESSAGES )
{
    initialise();
}
//______________________________________________________________________________
void scopeController::initialise()
{
    if( localInterface.interfaceInitReport() )
        message("scopeController instantiation success.");
}
//______________________________________________________________________________
scopeController::~scopeController(){}    //dtor
//______________________________________________________________________________
//std::vector< std::vector< double > > scopeController::monitorForNCounts( const std::string & scopeName, int numcounts )
//{
//    return localInterface.monitorForNCounts( scopeName, numcounts );
//}
//______________________________________________________________________________
void scopeController::monitorTracesForNShots( size_t N )
{
    localInterface.monitorTracesForNShots( N );
}
//______________________________________________________________________________
void scopeController::monitorNumsForNShots( size_t N )
{
    localInterface.monitorNumsForNShots( N );
}
//______________________________________________________________________________
bool scopeController::isMonitoringScopeTraces()
{
    return localInterface.isMonitoringScopeTraces();
}
//______________________________________________________________________________
bool scopeController::isNotMonitoringScopeTraces()
{
    return localInterface.isNotMonitoringScopeTraces();
}
//______________________________________________________________________________
bool scopeController::isMonitoringScopeNums()
{
    return localInterface.isMonitoringScopeNums();
}
//______________________________________________________________________________
bool scopeController::isNotMonitoringScopeNums()
{
    return localInterface.isNotMonitoringScopeNums();
}
//______________________________________________________________________________
std::vector< std::vector< double > > scopeController::getScopeTraces( const std::string & name, scopeStructs::SCOPE_PV_TYPE pvType )
{
    return localInterface.getScopeTraces( name, pvType );
}
//______________________________________________________________________________
std::vector< double > scopeController::getScopeNums( const std::string & name, scopeStructs::SCOPE_PV_TYPE pvType )
{
    return localInterface.getScopeNums( name, pvType );
}
//______________________________________________________________________________
std::vector< double > scopeController::getScopeP1Vec( const std::string & name )
{
    return localInterface.getScopeP1Vec( name );
}
//______________________________________________________________________________
std::vector< double > scopeController::getScopeP2Vec( const std::string & name )
{
    return localInterface.getScopeP2Vec( name );
}
//______________________________________________________________________________
std::vector< double > scopeController::getScopeP3Vec( const std::string & name )
{
    return localInterface.getScopeP3Vec( name );
}
//______________________________________________________________________________
std::vector< double > scopeController::getScopeP4Vec( const std::string & name )
{
    return localInterface.getScopeP4Vec( name );
}
//______________________________________________________________________________
std::vector< double > scopeController::getMinOfTraces( const std::string & name, scopeStructs::SCOPE_PV_TYPE pvType )
{
    return localInterface.getMinOfTraces( name, pvType );
}
//______________________________________________________________________________
std::vector< double > scopeController::getMaxOfTraces( const std::string & name, scopeStructs::SCOPE_PV_TYPE pvType )
{
    return localInterface.getMaxOfTraces( name, pvType );
}
//______________________________________________________________________________
std::vector< double > scopeController::getAreaUnderTraces( const std::string & name, scopeStructs::SCOPE_PV_TYPE pvType )
{
    return localInterface.getAreaUnderTraces( name, pvType );
}
//______________________________________________________________________________
std::vector< double > scopeController::getTimeStamps( const std::string & name, scopeStructs::SCOPE_PV_TYPE pvType )
{
    return localInterface.getTimeStamps( name, pvType );
}
//______________________________________________________________________________
std::vector< std::string > scopeController::getStrTimeStamps( const std::string & name, scopeStructs::SCOPE_PV_TYPE pvType )
{
    return localInterface.getStrTimeStamps( name, pvType );
}
//______________________________________________________________________________
double scopeController::getScopeP1( const std::string & name )
{
    return localInterface.getScopeP1( name );
}
//______________________________________________________________________________
double scopeController::getScopeP2( const std::string & name )
{
    return localInterface.getScopeP2( name );
}
//______________________________________________________________________________
double scopeController::getScopeP3( const std::string & name )
{
    return localInterface.getScopeP3( name );
}
//______________________________________________________________________________
double scopeController::getScopeP4( const std::string & name )
{
    return localInterface.getScopeP4( name );
}
//______________________________________________________________________________
double scopeController::getWCMQ()
{
    return localInterface.getWCMQ();
}
//______________________________________________________________________________
double scopeController::getICT1Q()
{
    return localInterface.getICT1Q();
}
//______________________________________________________________________________
double scopeController::getICT2Q()
{
    return localInterface.getICT2Q();
}
//______________________________________________________________________________
double scopeController::getFCUPQ()
{
    return localInterface.getFCUPQ();
}
//______________________________________________________________________________
double scopeController::getEDFCUPQ()
{
    return localInterface.getEDFCUPQ();
}
//______________________________________________________________________________
std::vector< std::string > scopeController::getScopeNames()
{
    return localInterface.getScopeNames();
}
//______________________________________________________________________________
//bool scopeController::hasTrig( const std::string & name )
//{
//    return localInterface.hasTrig( name );
//}
////______________________________________________________________________________
//bool scopeController::hasNoTrig( const std::string & name )
//{
//    return localInterface.hasNoTrig( name );
//}
////______________________________________________________________________________
//VELA_ENUM::TRIG_STATE  scopeController::getScopeState( const std::string & name )
//{
//    return localInterface.getScopeState( name );
//}
////______________________________________________________________________________
//std::string scopeController::getScopeStateStr( const std::string & name )
//{
//    return ENUM_TO_STRING(localInterface.getScopeState( name ));
//}
//______________________________________________________________________________
std::map< VELA_ENUM::ILOCK_NUMBER, VELA_ENUM::ILOCK_STATE > scopeController::getILockStates( const std::string & objName )
{
    return localInterface.getILockStates( objName );
}
//______________________________________________________________________________
std::map< VELA_ENUM::ILOCK_NUMBER, std::string > scopeController::getILockStatesStr( const std::string & objName )
{
    return localInterface.getILockStatesStr( objName );
}
//______________________________________________________________________________
double scopeController::get_CA_PEND_IO_TIMEOUT()
{
    return localInterface.get_CA_PEND_IO_TIMEOUT( );
}
//______________________________________________________________________________
void scopeController::set_CA_PEND_IO_TIMEOUT( double val )
{
    localInterface.set_CA_PEND_IO_TIMEOUT( val );
}
//______________________________________________________________________________
