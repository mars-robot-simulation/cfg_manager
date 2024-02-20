#pragma once

#include "CFGParam.h"

namespace mars
{
    namespace cfg_manager
    {

        class CFGParamBool : public CFGParam
        {

        public:
            enum paramProperty
            {
                value = 0,
                dstNrOfParamPropertys
            };

            static const std::string paramPropertyName[dstNrOfParamPropertys];
            static const cfgPropertyType paramPropertyType[dstNrOfParamPropertys];


        public:
            CFGParamBool(const cfgParamId &_id, const std::string &_group,
                         const std::string &_name);
            ~CFGParamBool();

            virtual bool setProperty(const CFGProperty &_property);

            virtual const std::string& getPropertyNameByIndex(unsigned int _index) const ;
            virtual const cfgPropertyType& getPropertyTypeByIndex(unsigned int _index) const;
            virtual unsigned int getPropertyIndexByName(const std::string &_name) const;

            virtual unsigned int getNrOfPropertys() const;

            static CFGParam* createParam(const cfgParamId &_id, const std::string &_group,
                                         const YAML::Node &node);


        private:
            bool setPropertyValue(const CFGProperty &_property) const;

        }; // end class CFGParamBool

    } // end namespace cfg_manager
} // end namespace mars

