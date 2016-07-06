///
/// Duncan Scott July 2015
///
/// For reading in parameters
/// Input files will be plain text
///
#ifndef scopeConfigReader_H_
#define scopeConfigReader_H_
// stl
#include <string>
#include <vector>
#include <map>
#include <iostream>
// me
#include "configReader.h"
#include "scopeStructs.h"


class scopeConfigReader : public configReader
{
    public:
        scopeConfigReader( const bool* show_messages_ptr, const bool * show_debug_messages_ptr );
        scopeConfigReader( const std::string configFileLocation1,
                           const std::string configFileLocation2,  const bool * showMessages, const  bool * showDebugMessages );
        ~scopeConfigReader();

        bool readConfigFiles( );
        scopeStructs::scopeObject scopeConfigReader::getScopeObject();

    private:


        /// for RF object there are 3 types of hardware, we should be able to read in
        /// the conig files with 1 function and function pointers, this can't go in the
        /// base as the functions addToObjectsV1() etc. are in derived classes
        /// This seems like a "nice" use of function pointers

        typedef void (scopeConfigReader::*aKeyValMemFn)( const std::vector<std::string> &keyVal );
        bool readConfig( scopeConfigReader & obj, const std::string fn, aKeyValMemFn f1, aKeyValMemFn f2, aKeyValMemFn f3 );

        /// These are read into vectors as you can use the .back() member function, which i find handy.
        /// once all the data is read in we can construct the final map of objects

        // TRACE objects
        std::vector< scopeStructs::scopeTraceData > scopeTraceDataObjects;
        std::vector< scopeStructs::pvStruct > scopeTraceDataMonStructs;
        void addToScopeTraceDataObjectsV1( const std::vector<std::string> &keyVal );
        void addToScopeTraceDataMonStructsV1( const std::vector<std::string> &keyVal );
        // NUM objects
        std::vector< scopeStructs::pvStruct > scopeNumMonStructs;
        scopeStructs::scopeNumObject scopeNumObject;
        void addToScopeNumObjectsV1( const std::vector<std::string> &keyVal );
        void addToScopeNumMonStructsV1( const std::vector<std::string> &keyVal );

        void addToPVStruct( std::vector< scopeStructs::pvStruct > & pvStruct_v, const  std::vector<std::string> &keyVal );
        void addCOUNT_MASK_OR_CHTYPE(  std::vector< scopeStructs::pvStruct >  & pvStruct_v, const std::vector<std::string> &keyVal );

        VELA_ENUM::DIAG_TYPE getDiagType( const std::string & val );

        std::vector< double >                tstamps;
        std::vector< std::string >           strtstamps;
        std::vector< std::vector< double > > traces;
        int                                  shotcounts;
};
#endif //scopeConfigReader2_H_