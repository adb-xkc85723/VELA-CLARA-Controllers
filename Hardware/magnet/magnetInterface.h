#ifndef VELA_MAG_INTERFACE_H
#define VELA_MAG_INTERFACE_H
// djs
#include "interface.h"
#include "magnetStructs.h"
#include "structs.h"
#include "magnetConfigReader.h"
//stl
#include <vector>
#include <string>
#include <atomic>
#include <map>

class magnetInterface : public interface
{
    public:

        typedef std::vector< bool > vec_b;
        typedef std::vector< std::string > vec_s;
        typedef std::vector< double > vec_d;

        /// Not a singleton, two construction methods....

        magnetInterface( const bool* show_messages_ptr, const bool* show_debug_messages_ptr  );
        magnetInterface( const std::string configFileLocation1,
                         const std::string configFileLocation2,
                         const std::string configFileLocation3, const bool* show_messages_ptr, const bool* show_debug_messages_ptr  );
        ~magnetInterface();
      //  magnetInterface(const magnetInterface& origin, const bool* show_messages_ptr, const bool * show_debug_messages_ptr); // add this line

                /// These are pure virtual methods, so need to have some implmentation in derived classes

        std::map< VELA_ENUM::ILOCK_NUMBER, VELA_ENUM::ILOCK_STATE >  getILockStates( const std::string & name ) {
            std::map< VELA_ENUM::ILOCK_NUMBER, VELA_ENUM::ILOCK_STATE > r;
            return r;}
        std::map< VELA_ENUM::ILOCK_NUMBER, std::string  >  getILockStatesStr( const std::string & name ) {
            std::map< VELA_ENUM::ILOCK_NUMBER, std::string > r;
            return r;}

        bool isAQuad( const std::string & magName );
        bool isABSol( const std::string & magName );
        bool isAHCor( const std::string & magName );
        bool isAVCor( const std::string & magName );
        bool isADip ( const std::string & magName );
        bool isASol ( const std::string & magName );
        bool isACor ( const std::string & magName );

        bool isBipolar( const std::string & magName );
        bool isNR( const std::string & magName );
        bool isNRGanged( const std::string & magName );
        bool isNRorNRGanged( const std::string & magName );

        bool isDegaussing( const std::string & magName );
        bool isNotDegaussing( const std::string & magName );

        bool entryExistsAndIsDegaussing( const std::string & magName );
        bool entryExistsAndIsNotDegaussing( const std::string & magName );

        bool isON_psuN( const std::string & magName );
        bool isON_psuR( const std::string & magName );
        bool isON ( const std::string & magName );
        bool isOFF_psuN( const std::string & magName );
        bool isOFF_psuR( const std::string & magName );
        bool isOFF ( const std::string & magName );


        void setRITolerance( const std::string & magName, double val);

        void showMagRevType();

        double getSI( const std::string & magName );
        double getRI( const std::string & magName );

        vec_d getSI( const vec_s & magNames );
        vec_d getRI( const vec_s & magNames );

        vec_s getMagnetNames();
        vec_s getQuadNames();
        vec_s getHCorNames();
        vec_s getVCorNames();
        vec_s getDipNames();
        vec_s getSolNames();

        bool setSI( const std::string & magName, const double value);
        bool setSI( const  vec_s & magNames, const vec_d& values );
        bool setSI( const std::string & magName, const double value, const double tolerance, const size_t timeOUT );
        vec_s setSI( const vec_s & magNames, const vec_d & values, const vec_d & tolerances, const size_t timeOUT );

        /// These functions return wether the commands were sent to EPICS correctly, not if the oiperation was succesful

        bool switchONpsu ( const std::string & magName  );
        bool switchOFFpsu( const std::string & magName  );
        bool switchONpsu ( const vec_s     & magNames );
        bool switchOFFpsu( const vec_s     & magNames );

        size_t deGauss( const std::string & mag, bool resetToZero = true );
        size_t deGauss( const vec_s & mag, bool resetToZero = true );
        size_t degaussAll( bool resetToZero = true );

        //
        void killDegaussThread( size_t N );

        magnetStructs::magnetStateStruct getCurrentMagnetState();
        magnetStructs::magnetStateStruct getCurrentMagnetState( vec_s & s );

        void applyMagnetStateStruct( const magnetStructs::magnetStateStruct & ms  );

        magnetStructs::magnetStateStruct getDBURT( const std::string & fileName );
        magnetStructs::magnetStateStruct getDBURTCorOnly( const std::string & fileName );
        magnetStructs::magnetStateStruct getDBURTQuadOnly( const std::string & fileName );


        bool writeDBURT( const magnetStructs::magnetStateStruct & ms, const std::string & fileName = "", const std::string & comments = ""  );
        bool writeDBURT( const std::string & fileName = "", const std::string & comments = ""  );

        void applyDBURT( const std::string & fileName );
        void applyDBURTCorOnly( const std::string & fileName );
        void applyDBURTQuadOnly( const std::string & fileName );

        const magnetStructs::magnetObject &getMagObjConstRef( const std::string & magName  );
        const magnetStructs::magnetObject *getMagObjConstPtr( const std::string & magName  );

    private:

        /// AllmagnetData gets a dummy magnet to return
        std::string dummyName;

        void killMonitor( magnetStructs::monitorStruct * ms );

        void initialise();
        bool initObjects();
        void addDummyElementToAllMAgnetData();
        void initChids();
        void addChannel( const std::string & pvRoot, magnetStructs::pvStruct & pv );
        void startMonitors();

        std::map< std::string, magnetStructs::magnetObject > allMagnetData;
        magnetStructs::degaussValues degStruct;
        std::vector<  magnetStructs::monitorStruct* > continuousMonitorStructs; /// vector of monitors to pass along with callback function

        static void staticEntryMagnetMonitor( const event_handler_args args);

        void updateRI( const double value, const std::string & magName );
        void updateSI( const double value, const std::string & magName );

        void updateRI_WithPol( const std::string & magName );
        void updateSI_WithPol( const std::string & magName );
        void updatePSUSta( const unsigned short value, const  std::string & magName, const magnetStructs::MAG_PSU_TYPE psuType );


        void setSI_MAIN( const  vec_s & magNames, const vec_d& values );

        vec_b setSIWithFlip( const vec_s & magNames, const vec_d & values);

        void setNRGangedSIVectors( const vec_s & magNames, const vec_d & values, vec_s & magnetsToSet, vec_s & magnetsToFlipThenSet,
                                                vec_d & magnetsToSetValues, vec_d & magnetsToFlipThenSetValues );
        void setNRSIVectors( const std::string & magName, const double val, vec_s & magnetsToSet, vec_s & magnetsToFlipThenSet,
                                   vec_d & magnetsToSetValues, vec_d & magnetsToFlipThenSetValues);
        bool setSINoFlip( const vec_s & magNames, const vec_d & values);
        bool nrGanged_SI_Vals_AreSensible( const vec_s & magNames, const vec_d & values );


        vec_s waitForMagnetsToSettle(const vec_s & mags, const vec_d & values, const vec_d & tolerances, const time_t waitTime = 45 ); /// MAGIC_NUMBER

        bool isRIequalVal( const std::string & magName, const  double value, const double tolerance );
        bool shouldPolarityFlip( const std::string & magName, const double val );
        bool canNRFlip(const std::string & magName );
        const vec_b flipNR( const vec_s & magNames );

        bool switchONpsu_N( const vec_s & magNames );
        bool switchONpsu_R( const vec_s & magNames );

        std::vector< chid >   getCHIDs( const vec_s & magNames  );
        std::vector< chtype > getCHTYPSES( const vec_s & magNames  );

        bool sendCommand( const std::vector< chtype* > & CHTYPE, const std::vector< chid* > & CHID, const std::string & m1, const std::string & m2  );
        bool togglePSU( const vec_s & magNames, magnetStructs::MAG_PV_TYPE pvtype, magnetStructs::MAG_PSU_TYPE psutype);

        /// DEGAUSS STUFF
        static void staticEntryDeGauss(const magnetStructs::degaussStruct & ds );
        size_t degaussNum;

        std::map< size_t, magnetStructs::degaussStruct > degaussStructsMap;
        std::map< std::string,  std::atomic< bool > > isDegaussingMap; /// std::atomic< bool > are not CopyConstructible, so this is held locally
       // std::map< size_t, std::thread* > degaussThreadMap;

        void killFinishedDegaussThreads();

        void printDegaussResults( const vec_s & magToDegSuccess, const vec_s & magToDegOriginal );
        void getDegaussValues( vec_s & magToDeg, vec_d & values, vec_d & tolerances, size_t step);

        void checkGangedMagnets( vec_s & magToDeg,  vec_s & gangedMagToZero, vec_d & gangedMagToZeroSIValues );
        void printDegauss();
        void printFinish();
        void printVec( const std::string & p1, const vec_s & v, size_t numPerLine );

        magnetConfigReader configReader; /// class member so we can pass in file path in ctor
        ///message
};
#endif // VELA_MAG_INTERFACE_H