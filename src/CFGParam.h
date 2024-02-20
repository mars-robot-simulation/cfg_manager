#prama once

#include "CFGDefs.h"
#include "CFGProperty.h"
#include "CFGClient.h"

#include <yaml-cpp/yaml.h>

#include <mars_utils/Mutex.h>

#include <string>
#include <vector>


namespace mars
{
    namespace cfg_manager
    {

        class CFGParam
        {

        public:
            CFGParam(const cfgParamId &_id, const std::string &_group,
                     const std::string &_name, const cfgParamType &_type);
            ~CFGParam();

            const cfgParamType& getParamType() const;
            const cfgParamId& getId() const;
            const std::string& getGroup() const;
            const std::string& getName() const;

            virtual bool getProperty(CFGProperty *property) const;
            virtual bool setProperty(const CFGProperty &_property) = 0;

            virtual const std::string& getPropertyNameByIndex(unsigned int _index) const = 0;
            virtual const cfgPropertyType& getPropertyTypeByIndex(unsigned int _index) const = 0;
            virtual unsigned int getPropertyIndexByName(const std::string &_name) const = 0;

            virtual unsigned int getNrOfPropertys() const = 0;

            virtual unsigned char getOption() const;
            virtual void setOption(const unsigned char _newOption);
            virtual void unsetOption(const unsigned char _newOption);

            void addClient(CFGClient *client);
            void removeClient(CFGClient *client);

            void writeToYAML(YAML::Emitter &out) const;


        private:
            cfgParamId id;
            std::string group;
            std::string paramName;
            cfgParamType paramType;

            std::vector<CFGClient*> cfgClients;
            utils::Mutex mutexCFGClients;


        protected:
            std::vector<CFGProperty*> propertys;
            mutable utils::Mutex mutexPropertys;

            unsigned char options;

            void updateClients(const CFGProperty &property);

            void readFromYAML(const YAML::Node &node);
            void readPropertyFromYAML(unsigned int index, const YAML::Node &node) const;
            void readSaveSettingFromYAML(const YAML::Node &node);

            bool writeProperty(const CFGProperty &property) const;
            const std::string emptyString;
            const cfgPropertyType noType;

        }; // end class CFGParam

    } // end namespace cfg_manager
} // end namespace mars
