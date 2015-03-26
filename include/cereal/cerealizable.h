#ifndef CEREAL_CEREALIZABLE_H
#define CEREAL_CEREALIZABLE_H

#include "lms/serializable.h"
#include "cereal/archives/portable_binary.hpp"

namespace cereal {

template<class OArchive, class IArchive>
class Cerealizable : public lms::Serializable {
    virtual void serialize(std::ostream &os) const {
        OArchive oarchive(os);
        oarchive(this);
    }

    virtual void deserialize(std::istream &is) {
        IArchive iarchive(is);
        iarchive(this);
    }
};

typedef Cerealizable<cereal::PortableBinaryOutputArchive,cereal::PortableBinaryInputArchive>
    PortableBinaryCerealizable;

}  // namespace cereal

#endif /* CEREAL_CEREALIZABLE_H */
