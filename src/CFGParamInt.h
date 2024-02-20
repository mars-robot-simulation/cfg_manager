#pragma once

#include "CFGParam.h"

namespace mars
{
    namespace cfg_manager
    {

        class CFGParamInt : public CFGParam
        {

        public:
            enum paramProperty
            {
                value = 0,
                min,
                max,
                stepsize,
                dstNrOfParamPropertys
            };

            static const std::string paramPropertyName[dstNrOfParamPropertys];
            static const cfgPropertyType paramPropertyType[dstNrOfParamPropertys];

        public:
            CFGParamInt(const cfgParamId &_id, const std::string &_group,
                        const std::string &_name);
            ~CFGParamInt();

            virtual bool setProperty(const CFGProperty &_property);

            virtual const std::string& getPropertyNameByIndex(unsigned int _index) const ;
            virtual const cfgPropertyType& getPropertyTypeByIndex(unsigned int _index) const;
            virtual unsigned int getPropertyIndexByName(const std::string &_name) const;

            virtual unsigned int getNrOfPropertys() const;

            static CFGParam* createParam(const cfgParamId &_id, const std::string &_group,
                                         const YAML::Node &node);


        private:
            bool setPropertyValue(const CFGProperty &_property) const;
            bool setPropertyMin(const CFGProperty &_property) const;
            bool setPropertyMax(const CFGProperty &_property) const;
            bool setPropertyStepsize(const CFGProperty &_property) const;

        }; // end class CFGParamInt

    } // end namespace cfg_manager
} // end namespace mars
