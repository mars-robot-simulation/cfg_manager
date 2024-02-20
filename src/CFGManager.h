#pragma once

#include "CFGManagerInterface.h"

#include <istream>
#include <string>
#include <vector>
#include <map>

#include <mars_utils/Mutex.h>

namespace YAML
{
    class Node;
}

namespace mars
{
    namespace cfg_manager
    {

        class CFGParam;
        class CFGProperty;

        typedef std::map<std::string, CFGParam*> mapStringToParam;
        typedef std::map<cfgParamId, CFGParam*> mapIdToParam;

        class CFGManager : public CFGManagerInterface
        {

        public:
            CFGManager(lib_manager::LibManager *theManager,
                       const char *filename = "mars_default.yaml");
            ~CFGManager();

            // LibInterface methods
            virtual int getLibVersion() const
                { return 1; }
            virtual const std::string getLibName() const
                { return "cfg_manager"; }
            CREATE_MODULE_INFO();

            // CFGInterface methods
            virtual bool loadConfigFromStream(std::istream &in, const char *group);
            virtual bool loadConfig(const char *filename);
            virtual bool loadConfig(const char *filename, const char *group);
            virtual bool loadConfigFromString(const std::string &configString);

            virtual void writeConfig(const char *filename, const char *group = NULL,
                                     const unsigned char saveOption = saveOnClose) const;
            virtual const std::string writeConfigToString(const char *group = NULL,
                                                          const unsigned char saveOption = saveOnClose) const;

            virtual cfgParamId createParam(const std::string &_group,
                                           const std::string &_name,
                                           const cfgParamType &_paramType);

            virtual bool removeParam(const cfgParamId &_id);
            virtual bool removeParam(const std::string &_group, const std::string &_name);

            virtual bool setProperty(const CFGProperty &_property);
            virtual bool getProperty(CFGProperty *_property) const;

            virtual bool setProperty(const cfgPropertyStruct &_propertyS);
            virtual bool getProperty(cfgPropertyStruct *_propertyS) const;

            using CFGManagerInterface::getPropertyValue;
            virtual bool getPropertyValue(cfgParamId paramId,
                                          const std::string &_propertyName,
                                          double *rValue) const;
            virtual bool getPropertyValue(cfgParamId paramId,
                                          const std::string &_propertyName,
                                          int *rValue) const;
            virtual bool getPropertyValue(cfgParamId paramId,
                                          const std::string &_propertyName,
                                          bool *rValue) const;
            virtual bool getPropertyValue(cfgParamId paramId,
                                          const std::string &_propertyName,
                                          std::string *rValue) const;

            virtual bool setPropertyValue(const std::string &_group,
                                          const std::string &_name,
                                          const std::string &_propertyName,
                                          const double rValue);
            virtual bool setPropertyValue(const std::string &_group,
                                          const std::string &_name,
                                          const std::string &_propertyName,
                                          const int rValue);
            virtual bool setPropertyValue(const std::string &_group,
                                          const std::string &_name,
                                          const std::string &_propertyName,
                                          const bool rValue);
            virtual bool setPropertyValue(const std::string &_group,
                                          const std::string &_name,
                                          const std::string &_propertyName,
                                          const std::string &rValue);
            virtual bool setPropertyValue(const std::string &_group,
                                          const std::string &_name,
                                          const std::string &_propertyName,
                                          const char *rValue);

            virtual cfgParamId getParamId(const std::string &_group,
                                          const std::string &_name) const;

            virtual const cfgParamInfo getParamInfo(const cfgParamId &_id) const;
            virtual const cfgParamInfo getParamInfo(const std::string &_group,
                                                    const std::string &_name) const;

            virtual cfgParamId registerToParam(const std::string &_group,
                                               const std::string &_name,
                                               CFGClient *client);
            virtual bool registerToParam(const cfgParamId &_id, CFGClient *client);

            virtual bool unregisterFromParam(const std::string &_group,
                                             const std::string &_name, CFGClient *client);
            virtual bool unregisterFromParam(const cfgParamId &_id, CFGClient *client);

            virtual bool registerToCFG(CFGClient *client);
            virtual bool unregisterFromCFG(CFGClient *client);

            virtual bool getAllParams(std::vector<cfgParamInfo> *allParams) const;

            // specific methods that make life easier
            virtual const cfgPropertyStruct getOrCreateProperty(const std::string &_group,
                                                                const std::string &_name,
                                                                bool val,
                                                                CFGClient *newClient = NULL);
            virtual const cfgPropertyStruct getOrCreateProperty(const std::string &_group,
                                                                const std::string &_name,
                                                                double val,
                                                                CFGClient *newClient = NULL);
            virtual const cfgPropertyStruct getOrCreateProperty(const std::string &_group,
                                                                const std::string &_name,
                                                                int val,
                                                                CFGClient *newClient = NULL);
            virtual const cfgPropertyStruct getOrCreateProperty(const std::string &_group,
                                                                const std::string &_name,
                                                                const std::string &val,
                                                                CFGClient *newClient = NULL);
            virtual const cfgPropertyStruct getOrCreateProperty(const std::string &_group,
                                                                const std::string &_name,
                                                                const char *val,
                                                                CFGClient *newClient = NULL);

            virtual void setProperty(const std::string &_group,
                                     const std::string &_name, bool val);
            virtual void setProperty(const std::string &_group,
                                     const std::string &_name, double val);
            virtual void setProperty(const std::string &_group,
                                     const std::string &_name, int val);
            virtual void setProperty(const std::string &_group,
                                     const std::string &_name,
                                     const std::string &val);
            virtual void setProperty(const std::string &_group,
                                     const std::string &_name, const char *val);

        private:
            cfgParamId nextId;
            mutable mars::utils::Mutex mutexNextId;

            cfgParamId getNextId();

            mapStringToParam cfgParamsByString;
            mapIdToParam cfgParamsById;
            mutable mars::utils::Mutex mutexCFGParams;

            std::vector<CFGClient*> vecClients;
            mutable mars::utils::Mutex mutexVecClients;

            inline void insertParam(CFGParam *newParam);
            inline void deleteParam(CFGParam *param);

            inline bool getParam(CFGParam **param, const std::string &_group,
                                 const std::string &_name) const;
            inline bool getParam(CFGParam **param, const cfgParamId &_id) const;

            inline const cfgParamInfo getParamInfo(const CFGParam *param) const;

            inline void addedCFGParam(const cfgParamId &_id) const;
            inline void removedCFGParam(const cfgParamId &_id) const;

            bool fileExists(const std::string &strFilename) const;


            void readGroup(const std::string &group, const YAML::Node &paramNodes);


        }; // end class CFGManager

    } // end namesapce cfg_manager
} // end namesapce mars
