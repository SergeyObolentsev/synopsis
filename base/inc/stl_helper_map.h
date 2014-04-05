#ifndef STL_HELPER_MAP_H
#define STL_HELPER_MAP_H

#include <map>

namespace synopsis {

template <typename TMap, typename TKey, typename TVal>
typename TMap::iterator EfficientAddUpdate(TMap& tMap, const TKey& tKey, const TVal& tVal)
{
    typename TMap::iterator lb = tMap.lower_bound(tKey);

    if(lb != tMap.end()){
        lb->second = tVal;
        return lb;
    }else{
        return tMap.insert(lb,typename TMap::value_type(tKey, tVal));
    }
}


} //synopsis

#endif // STL_HELPER_MAP_H
