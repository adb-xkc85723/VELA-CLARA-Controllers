#ifndef VELA_SCOPE_INTERFACE_H
#define VELA_SCOPE_INTERFACE_H
// djs
#include "interface.h"
#include "scopeStructs.h"
#include "scopeConfigReader.h"
//stl
#include <vector>
#include <string>

class scopeInterface : public interface
{
    public:

        /// Not a singleton, two construction methods....

        scopeInterface(const bool* show_messages_ptr, const  bool * show_debug_messages_ptr  );
        scopeInterface( const std::string configFileLocation1,
                        const std::string configFileLocation2, const bool* show_messages_ptr, const  bool * show_debug_messages_ptr  );

        bool monitoringTraces = false;
        bool monitoringNums = false;

        ~scopeInterface();

        void getScopeNames( std::vector< std::string >  & scopeNames );
        double getScopeP1( const std::string & scope );
        double getScopeP2( const std::string & scope );
        double getScopeP3( const std::string & scope );
        double getScopeP4( const std::string & scope );
        double getWCMQ()   ;
        double getICT1Q()  ;
        double getICT2Q()  ;
        double getFCUPQ()  ;
        double getEDFCUPQ();
        std::vector< std::vector< double > > getScopeTraces( const std::string & name, scopeStructs::SCOPE_PV_TYPE pvType );
        std::vector< double > getMinOfTraces( const std::string & name, scopeStructs::SCOPE_PV_TYPE pvType );
        std::vector< double > getMaxOfTraces( const std::string & name, scopeStructs::SCOPE_PV_TYPE pvType );
        std::vector< double > getAreaUnderTraces( const std::string & name, scopeStructs::SCOPE_PV_TYPE pvType );
        std::vector< double > getTimeStamps( const std::string & name, scopeStructs::SCOPE_PV_TYPE pvType );
        std::vector< std::string > getStrTimeStamps( const std::string & name, scopeStructs::SCOPE_PV_TYPE pvType );
        void updateTrace( scopeStructs::monitorStruct * ms, const event_handler_args args );
        void updateValue( scopeStructs::monitorStruct * ms, const event_handler_args args );
        void monitorTracesForNShots( size_t N );
        void monitorNumsForNShots( size_t N );
        void cancelDataMonitors();
        std::vector< double > getAvgNoise( const std::string & name, scopeStructs::SCOPE_PV_TYPE & pvType );
        std::vector< std::string > getScopeNames();
//        char getTimestamp( std::string & scope );
//        bool hasTrig( const std::string & scope );
//        bool hasNoTrig( const std::string & scope );

        void addToMonitorStructs( std::vector< scopeStructs::monitorStruct * > & msv, scopeStructs::pvStruct & pv,  scopeStructs::scopeTraceData * traobj );

        scopeStructs::scopeObject getScopeObject( const std::string & scopeName );

        VELA_ENUM::TRIG_STATE getScopeState( const std::string & scopeName );
        scopeStructs::scopeObject scopeObject;

        void killCallBack( scopeStructs::monitorStruct * ms, scopeStructs::scopeTraceData * td );
        bool killTraceMonitors();

        /// This is a pure virtual method in the base class and MUST be overwritten in the derived interface...

        std::map< VELA_ENUM::ILOCK_NUMBER, VELA_ENUM::ILOCK_STATE > getILockStates( const std::string & scopeName );
        std::map< VELA_ENUM::ILOCK_NUMBER, std::string  >        getILockStatesStr( const std::string & scopeName );

    protected:
    private:

        /// called from constructor to set-up chids, montiros, etc.

        void initialise();

        scopeConfigReader configReader;

        void initScopeObjects();
        void initScopeChids();
        //void addChannel( std::map< std::string, scopeStructs::scopeObject >::iterator & it1, std::map< scopeStructs::SCOPE_PV_TYPE, std::string >::const_iterator & it2 );
        void addChannel( const std::string & pvRoot, scopeStructs::pvStruct & pv );

        void monitorScopes();

        /// As an overly complicated example let's try some function pointers. Toggling (open / close ) the scope is now easy
        /// https://isocpp.org/wiki/faq/pointers-to-members

        typedef  bool (scopeInterface::*isOCMemFn)(const std::string & );
        typedef  void (scopeInterface::*OCMemFn)  (const std::string & );
        bool toggleAndWait( isOCMemFn f1, isOCMemFn f2, OCMemFn f3, const std::string & name, const time_t waitTime, scopeInterface & obj );

        /// static function that can be called back from epics to update values

//        static void staticEntryScopeMonitor( const event_handler_args args );
        static void staticEntryrMonitor( const event_handler_args args );

        bool isATracePV( scopeStructs::SCOPE_PV_TYPE pv );
        bool isANumPV( scopeStructs::SCOPE_PV_TYPE pv );
        void resetTraceVectors( size_t N );
        void resetNumVectors( size_t N );

        scopeStructs::scopeObject scopeObj;

        std::vector< scopeStructs::monitorStruct* > numMonitorStructs;
        std::vector< scopeStructs::monitorStruct* > traceMonitorStructs;
        void addTraceMonitorStructs( const std::string &scopeName );


        /// This is a vector of pointers... no you say !! let's follow  Bjarne Stroustrup's advice and "Store many objects in a container by value." ?
        /// http://stackoverflow.com/questions/24085931/is-using-stdvector-stdshared-ptrconst-t-an-antipattern
        /// tough... maybe one day we re-factor, for now remember to delete in the destructor

        std::vector< scopeStructs::monitorStruct * > continuousMonitorStructs;

        std::map< std::string, scopeStructs::scopeObject > allScopeData; /// All the scope data is stored in this map, keyed by the scope name

        std::vector< std::vector< double > > allScopeMonitorData;

        std::vector< std::vector< double > > traceMonitorData;
        std::map< bool, scopeStructs::scopeObject* > isMonitoringMap;
};
#endif // VELA_PyIL_SHUTTER_INTERFACE_H