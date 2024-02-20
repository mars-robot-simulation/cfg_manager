#pragma once
#include "CFGDefs.h"

namespace mars
{
    namespace cfg_manager
    {

        class CFGClient
        {

        public:
            CFGClient() {}
            virtual ~CFGClient() {}

            virtual void cfgUpdateProperty(cfgPropertyStruct _propertyS)
                {
                    (void) _propertyS;
                }
            virtual void cfgParamCreated(cfgParamId _id) { (void) _id; }
            virtual void cfgParamRemoved(cfgParamId _id) { (void) _id; }

        }; // end class CFGClient

    } // end namespace cfg_manager
} // end namespace mars

