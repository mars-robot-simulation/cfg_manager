#pragma once
#include <string>

// defines for the CFGInterface-class

namespace mars
{
    namespace cfg_manager
    {

        typedef unsigned long cfgParamId;

        enum cfgParamType
        {
            doubleParam = 0,
            intParam,
            boolParam,
            stringParam,
            noParam,
            dstNrOfParamTypes
        };

        static const std::string cfgParamTypeString[dstNrOfParamTypes] = {
            "double",
            "int",
            "bool",
            "string",
            "noParam"
        };

        struct cfgParamInfo
        {
            cfgParamId id;
            std::string group;
            std::string name;
            cfgParamType type;
        };

        enum cfgPropertyType
        {
            noTypeSet = 0,
            intProperty,
            doubleProperty,
            boolProperty,
            stringProperty
        };

        enum cfgParamOption
        {
            noParamOption = 0,
            userSave = 1,
            saveOnClose = 2
        };

        struct cfgPropertyStruct
        {
            cfgParamId paramId;
            unsigned int propertyIndex;
            cfgPropertyType propertyType;

            int    iValue;
            bool   bValue;
            double dValue;
            std::string sValue;

            unsigned int propertyState;
        };

    } // namespace cfg_manager
} // namespace mars
