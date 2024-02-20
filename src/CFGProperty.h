#pragma once

#include "CFGDefs.h"

#include <string>

namespace mars
{
    namespace cfg_manager
    {

        class CFGProperty
        {

        public:
            enum propertyOption
            {
                nothingSet = 0,
                paramIdSet = 1,
                propertyIndexSet = 2,
                propertyTypeSet = 4,
                propertyValueSet = 8,
                allSetButValue = 7,
                allSet = 15
            };

        public:
            CFGProperty();
            ~CFGProperty();

            const cfgParamId& getParamId() const;
            bool setParamId(const cfgParamId &_id);
            bool changeParamId(const cfgParamId &_id);

            unsigned int getPropertyIndex() const;
            bool setPropertyIndex(const unsigned int _propertyIndex);

            const cfgPropertyType& getPropertyType() const;
            bool setPropertyType(const cfgPropertyType &_propertyType);

            unsigned int getState() const;

            cfgPropertyStruct getAsStruct() const;

            bool isSameAs(const CFGProperty &property) const;

            bool isValueSet() const;

            bool setValue(const int    _iValue);
            bool setValue(const bool   _bValue);
            bool setValue(const double _dValue);
            bool setValue(const std::string &_sValue);

            bool getValue(int    *value) const;
            bool getValue(bool   *value) const;
            bool getValue(double *value) const;
            bool getValue(std::string *value) const;

        private:
            cfgParamId paramId;
            unsigned int propertyIndex;
            cfgPropertyType propertyType;

            int    iValue;
            bool   bValue;
            double dValue;
            std::string sValue;

            unsigned int propertyState;

        }; // end class CFGProperty

    } // end namespace cfg_manager
} // end namespace mars
