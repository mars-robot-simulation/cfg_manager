#include "CFGProperty.h"

#include <iostream>

namespace mars
{
    namespace cfg_manager
    {
  
        using std::string;

        CFGProperty::CFGProperty()
        {
            //cout << "create CFGProperty" << endl;
            paramId = 0;
            propertyIndex = 0;
            propertyType = noTypeSet;
            propertyState = nothingSet;

            bValue = false;
            dValue = 0.0;
            iValue = 0;
            sValue = "";
        }


        CFGProperty::~CFGProperty()
        {
            //cout << "destroy CFGProperty" << endl;
        }


        // PUBLIC

        const cfgParamId& CFGProperty::getParamId() const
        {
            return paramId;
        }


        bool CFGProperty::setParamId(const cfgParamId &_id)
        {
            if( (propertyState & paramIdSet) || _id == 0 )
            {
                return false;
            } else
            {
                paramId = _id;
                propertyState |= paramIdSet;
                return true;
            }
        }


        cfgPropertyStruct CFGProperty::getAsStruct() const
        {
            cfgPropertyStruct tmpS;

            tmpS.paramId = paramId;
            tmpS.propertyIndex = propertyIndex;
            tmpS.propertyType  = propertyType;
            tmpS.propertyState = propertyState;

            tmpS.bValue = bValue;
            tmpS.dValue = dValue;
            tmpS.iValue = iValue;
            tmpS.sValue = sValue;

            return tmpS;
        }


        bool CFGProperty::changeParamId(const cfgParamId &_id)
        {
            if( (propertyState & paramIdSet) && _id != 0 )
            {
                paramId = _id;
                return true;
            } else
            {
                return false;
            }
        }


        unsigned int CFGProperty::getPropertyIndex() const
        {
            return propertyIndex;
        }


        bool CFGProperty::setPropertyIndex(const unsigned int _propertyIndex)
        {
            if( propertyState & propertyIndexSet )
            {
                return false;
            } else
            {
                propertyIndex = _propertyIndex;
                propertyState |= propertyIndexSet;
                return true;
            }
        }


        const cfgPropertyType& CFGProperty::getPropertyType() const
        {
            return propertyType;
        }


        bool CFGProperty::setPropertyType(const cfgPropertyType &_propertyType)
        {
            if( propertyState & propertyTypeSet )
            {
                return false;
            } else
            {
                propertyType = _propertyType;
                propertyState |= propertyTypeSet;
                return true;
            }
        }


        unsigned int CFGProperty::getState() const
        {
            return propertyState;
        }


        bool CFGProperty::isSameAs(const CFGProperty &property) const
        {
            if( paramId       == property.getParamId() &&
                propertyIndex == property.getPropertyIndex() &&
                propertyType  == property.getPropertyType() )
            {
                return true;
            } else
            {
                return false;
            }
        }


        bool CFGProperty::isValueSet() const
        {
            if(propertyState & propertyValueSet)
            {
                return true;
            } else
            {
                return false;
            }
        }


        bool CFGProperty::setValue(const int _iValue)
        {
            if( (propertyState & propertyTypeSet) && propertyType == intProperty )
            {
                iValue = _iValue;
                propertyState |= propertyValueSet;
                return true;
            } else
            {
                return false;
            }
        }


        bool CFGProperty::setValue(const bool _bValue)
        {
            if( (propertyState & propertyTypeSet) && propertyType == boolProperty )
            {
                bValue = _bValue;
                propertyState |= propertyValueSet;
                return true;
            } else
            {
                return false;
            }
        }


        bool CFGProperty::setValue(const double _dValue)
        {
            if( (propertyState & propertyTypeSet) && propertyType == doubleProperty )
            {
                dValue = _dValue;
                propertyState |= propertyValueSet;
                return true;
            } else
            {
                return false;
            }
        }


        bool CFGProperty::setValue(const string &_sValue)
        {
            if( (propertyState & propertyTypeSet) && propertyType == stringProperty )
            {
                sValue = _sValue;
                propertyState |= propertyValueSet;
                return true;
            } else
            {
                return false;
            }
        }


        bool CFGProperty::getValue(int *value) const
        {
            if( (propertyState & propertyTypeSet) &&
                propertyType == intProperty &&
                (propertyState & propertyValueSet) )
            {
                *value = iValue;
                return true;
            } else
            {
                return false;
            }
        }


        bool CFGProperty::getValue(bool *value) const
        {
            if( (propertyState & propertyTypeSet) &&
                propertyType == boolProperty &&
                (propertyState & propertyValueSet) )
            {
                *value = bValue;
                return true;
            } else
            {
                return false;
            }
        }


        bool CFGProperty::getValue(double *value) const
        {
            if( (propertyState & propertyTypeSet) &&
                propertyType == doubleProperty &&
                (propertyState & propertyValueSet) )
            {
                *value = dValue;
                return true;
            } else
            {
                return false;
            }
        }


        bool CFGProperty::getValue(string *value) const
        {
            if( (propertyState & propertyTypeSet) &&
                propertyType == stringProperty &&
                (propertyState & propertyValueSet) )
            {
                *value = sValue;
                return true;
            } else
            {
                return false;
            }
        }

    } // end namespace cfg_manager
} // end namespace mars
