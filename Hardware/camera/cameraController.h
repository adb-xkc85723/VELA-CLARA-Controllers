#ifndef CAM_CONTROLLER_H
#define CAM_CONTROLLER_H
// stl
#include <string>
#include <vector>
#include <map>
// djs
#include "cameraInterface.h"
#include "structs.h"
#include "cameraStructs.h"
#include "controller.h"


class cameraController  : public controller
{
    public:
        /// we have overloaded constructors to specify config-file location
        cameraController( const bool show_messages = true , const bool show_debug_messages = true );
        cameraController( const std::string configFileLocation,  const std::string configIOCFileLocation, const  bool show_messages = true, const bool show_debug_messages = true );
        ~cameraController( );

        /// This pure virtual method MUST be overwritten in the derived controller ( making this an abstract base class)
        /// This also means the destructor need not be protected
        double get_CA_PEND_IO_TIMEOUT();
        void   set_CA_PEND_IO_TIMEOUT( double val );


        bool isON ( const std::string & cam );
        bool isOFF( const std::string & cam );

        bool isMonitoring( const std::string & cam );
        bool isNotMonitoring( const std::string & cam );

        bool start(const std::string & cam );
        bool start( const std::vector< std::string  >  & cam );
        bool stop(const std::string & cam );
        bool stop( const std::vector< std::string  >  & cam );

        bool stopAll();

        bool startAndWait( const std::string & cam, size_t timeout );
        std::vector< std::string > startAndWait( const std::vector< std::string  > & cam, size_t timeout );


        bool startCamDataMonitor( const std::string & cam, size_t N = -1 );

        std::vector< std::vector< cameraStructs::camDataType >> getRawData(const std::string & name  );
        std::vector< double > getRawDataStamp(const std::string & name  );
        std::vector< std::string > getRawDataStampStr( const std::string & name );

    protected:
    private:

    /// The interface to EPICS
        cameraInterface  localInterface;
        void initialise();

        /// This pure virtual method MUST be overwritten in the derived controller ( making this an abstract base class)
        std::map< VELA_ENUM::ILOCK_NUMBER, VELA_ENUM::ILOCK_STATE > getILockStates( const std::string & name );
        std::map< VELA_ENUM::ILOCK_NUMBER, std::string >         getILockStatesStr( const std::string & name );

};

#endif // cameraController_H