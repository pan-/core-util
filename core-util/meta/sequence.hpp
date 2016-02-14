#ifndef MBED_META_SEQUENCE_H_
#define MBED_META_SEQUENCE_H_

namespace mbed { namespace meta {

// Box a template parameter pack
template<typename... Ts>
struct sequence {
    // this type
    using type = sequence;
};

}} // namespace mbed::meta

#endif /* MBED_META_SEQUENCE_H_ */
