#ifndef CEREAL_CEREALIZABLE_H
#define CEREAL_CEREALIZABLE_H

#include "lms/serializable.h"
#include "cereal/archives/portable_binary.hpp"

#define CEREAL_SERIALIZATION() \
void serialize(std::ostream &os) const override { \
	cereal::PortableBinaryOutputArchive oarchive(os); \
	oarchive(*this); \
} \
void deserialize(std::istream &is) override { \
	cereal::PortableBinaryInputArchive iarchive(is); \
	iarchive(*this); \
}

#endif /* CEREAL_CEREALIZABLE_H */
