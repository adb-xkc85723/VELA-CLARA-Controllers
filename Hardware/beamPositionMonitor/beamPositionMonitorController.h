#ifndef vela_BPM_CONTROLLER_H
#define vela_BPM_CONTROLLER_H

// project
#include "beamPositionMonitorStructs.h"
#include "beamPositionMonitorInterface.h"
#include "controller.h"
// stl
#include <string>
#include <vector>

class beamPositionMonitorController : public controller
{
    public:

        /// we have overloaded constructors to specify config-file location

        beamPositionMonitorController( const bool show_messages = true, const bool show_debug_messages = true );
        beamPositionMonitorController( const std::string configFileLocation, const  bool show_messages = true, const bool show_debug_messages = true );
        ~beamPositionMonitorController();

        double getX( const std::string & bpm );
        double getY(  const std::string & bpm  );
        double getQ(  const std::string & bpm  );
        double getXFromPV(  const std::string & bpm  );
        double getYFromPV(  const std::string & bpm  );
        beamPositionMonitorStructs::rawDataStruct getAllBPMData( const std::string & name, size_t N );
        std::vector< std::vector< double > > getBPMRawData( const std::string & bpmName );
        std::vector< double > getBPMXVec( const std::string & bpmName );
        std::vector< double > getBPMYVec( const std::string & bpmName );
        std::vector< double > getBPMQVec( const std::string & bpmName );
        std::vector< double > getTimeStamps( const std::string & bpmName );
        std::vector< std::string > getStrTimeStamps( const std::string & bpmName );
        long getRA1(  const std::string & bpmName           );
        long getRA2(  const std::string & bpmName           );
        long getRD1(  const std::string & bpmName           );
        long getRD2(  const std::string & bpmName           );
        void setSA1(  const std::string & bpmName, long sa1 );
        void setSA2(  const std::string & bpmName, long sa2 );
        void setSD1(  const std::string & bpmName, long sd1 );
        void setSD2(  const std::string & bpmName, long sd2 );
        void reCalAtt( const std::string & bpmName, double qScope );
        void monitorDataForNShots( size_t N, const std::string & bpmNames );

        std::vector< std::string > getBPMNames();

        bool hasTrig( const std::string & bpmName );
        bool hasNoTrig( const std::string & bpmName );

        /// write a method that returns string version of enums using ENUM_TO_STRING

        VELA_ENUM::TRIG_STATE getBPMState( const std::string & bpmName );
        std::string getBPMStateStr( const std::string & name );

        double get_CA_PEND_IO_TIMEOUT();
        void set_CA_PEND_IO_TIMEOUT( double val );

        /// These are pure virtual method in the base class and MUST be overwritten in the derived Controller...
        /// write a method that returns string version of enums using ENUM_TO_STRING

        std::map< VELA_ENUM::ILOCK_NUMBER, VELA_ENUM::ILOCK_STATE > getILockStates( const std::string & name );
        std::map< VELA_ENUM::ILOCK_NUMBER, std::string > getILockStatesStr( const std::string & objName );




    protected:
    private:

        void initialise();

        /// No singletons, no pointers, let's just have an object

        beamPositionMonitorInterface localInterface;

        std::vector< std::string > bpmNames;
};

#endif // beamPositionMonitorController_H