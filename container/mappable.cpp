#include "mappable.hpp"

namespace lasd {

    template<typename Data>
    void PreOrderMappableContainer<Data>::Map(MapFun& fun) const
    {
        PreOrderMap(fun);
    }

    /* ************************************************************************** */

    template<typename Data>
    void PostOrderMappableContainer<Data>::Map(MapFun& fun) const
    {
        PostOrderMap(fun);
    }

}
