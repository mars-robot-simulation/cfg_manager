#pragma once

#include "CFGDefs.h"
#include "CFGClient.h"

#include <lib_manager/LibManager.hpp>

#include <string>
#include <vector>

namespace mars
{
    namespace cfg_manager
    {

        class CFGManagerInterface : public lib_manager::LibInterface
        {

        public:
            CFGManagerInterface(lib_manager::LibManager *theManager) :
                lib_manager::LibInterface(theManager) {}
            ~CFGManagerInterface() {}

            // LibInterface methods
            virtual int getLibVersion() const = 0;
            virtual const std::string getLibName() const = 0;
            virtual void createModuleInfo() {}

            // CFGInterface methods
            virtual cfgParamId createParam(const std::string &_group,
                                           const std::string &_name,
                                           const cfgParamType &_paramType) = 0;

            virtual bool loadConfig(const char *filename) = 0;
            virtual bool loadConfig(const char *filename, const char *group) = 0;

            virtual bool loadConfigFromString(const std::string &configString) = 0;

            virtual void writeConfig(const char *filename, const char *group,
                                     const unsigned char saveOption = saveOnClose) const = 0;
            virtual const std::string writeConfigToString(const char *group = 0,
                                                          const unsigned char saveOption = saveOnClose) const = 0;

            virtual bool removeParam(const cfgParamId &_id) = 0;
            virtual bool removeParam(const std::string &_group,
                                     const std::string &_name) = 0;

            //virtual bool setProperty(const CFGProperty _property) = 0;
            //virtual bool getProperty(CFGProperty &_property) const = 0;

            virtual bool setProperty(const cfgPropertyStruct &_propertyS) = 0;
            virtual bool getProperty(cfgPropertyStruct *_propertyS) const = 0;

            template <typename T>
            bool getPropertyValue(const std::string &_group, const std::string &_name,
                                  const std::string &_propertyName, T *rValue) const {
                return getPropertyValue(getParamId(_group, _name), _propertyName, rValue);
            }
      
            virtual bool getPropertyValue(cfgParamId paramId,
                                          const std::string &_propertyName,
                                          double *rValue) const = 0;
            virtual bool getPropertyValue(cfgParamId paramId,
                                          const std::string &_propertyName,
                                          int *rValue) const = 0;
            virtual bool getPropertyValue(cfgParamId paramId,
                                          const std::string &_propertyName,
                                          bool *rValue) const = 0;
            virtual bool getPropertyValue(cfgParamId paramId,
                                          const std::string &_propertyName,
                                          std::string *rValue) const = 0;

            virtual bool setPropertyValue(const std::string &_group,
                                          const std::string &_name,
                                          const std::string &_propertyName,
                                          const double rValue) = 0;
            virtual bool setPropertyValue(const std::string &_group,
                                          const std::string &_name,
                                          const std::string &_propertyName,
                                          const int rValue) = 0;
            virtual bool setPropertyValue(const std::string &_group,
                                          const std::string &_name,
                                          const std::string &_propertyName,
                                          const bool rValue) = 0;
            virtual bool setPropertyValue(const std::string &_group,
                                          const std::string &_name,
                                          const std::string &_propertyName,
                                          const std::string &rValue) = 0;
            virtual bool setPropertyValue(const std::string &_group,
                                          const std::string &_name,
                                          const std::string &_propertyName,
                                          const char *rValue) = 0;

            virtual cfgParamId getParamId(const std::string &_group,
                                          const std::string &_name) const = 0;

            virtual const cfgParamInfo getParamInfo(const cfgParamId &_id) const = 0;
            virtual const cfgParamInfo getParamInfo(const std::string &_group,
                                                    const std::string &_name) const = 0;

            virtual cfgParamId registerToParam(const std::string &_group,
                                               const std::string &_name,
                                               CFGClient *client) = 0;
            virtual bool registerToParam(const cfgParamId &_id, CFGClient *client) = 0;

            virtual bool unregisterFromParam(const std::string &_group,
                                             const std::string &_name,
                                             CFGClient *client) = 0;
            virtual bool unregisterFromParam(const cfgParamId &_id,
                                             CFGClient *client) = 0;

            virtual bool registerToCFG(CFGClient *client) = 0;
            virtual bool unregisterFromCFG(CFGClient *client) = 0;

            virtual bool getAllParams(std::vector<cfgParamInfo> *allParams) const = 0;

            // specific methods that make life easier
            virtual const cfgPropertyStruct getOrCreateProperty(const std::string &_group,
                                                                const std::string &_name,
                                                                bool val,
                                                                CFGClient *newClient = 0) = 0;
            virtual const cfgPropertyStruct getOrCreateProperty(const std::string &_group,
                                                                const std::string &_name,
                                                                double val,
                                                                CFGClient *newClient = 0) = 0;
            virtual const cfgPropertyStruct getOrCreateProperty(const std::string &_group,
                                                                const std::string &_name,
                                                                int val,
                                                                CFGClient *newClient = 0) = 0;
            virtual const cfgPropertyStruct getOrCreateProperty(const std::string &_group,
                                                                const std::string &_name,
                                                                const std::string &val,
                                                                CFGClient *newClient = 0) = 0;
            virtual const cfgPropertyStruct getOrCreateProperty(const std::string &_group,
                                                                const std::string &_name,
                                                                const char *val,
                                                                CFGClient *newClient = 0) = 0;

            virtual void setProperty(const std::string &_group,
                                     const std::string &_name, bool val) = 0;
            virtual void setProperty(const std::string &_group,
                                     const std::string &_name, double val) = 0;
            virtual void setProperty(const std::string &_group,
                                     const std::string &_name, int val) = 0;
            virtual void setProperty(const std::string &_group,
                                     const std::string &_name,
                                     const std::string &val) = 0;
            virtual void setProperty(const std::string &_group,
                                     const std::string &_name, const char *val) = 0;

        }; // end class CFGManagerInterface

    } // end namespace cfg_manager
} // end namespace mars

