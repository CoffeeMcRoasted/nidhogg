#include <cstdint>
#include <type_traits>

namespace nidhogg
{
namespace ecs
{
/**
 * @brief This is an empty implementation in order to fail compilation if not implemented
 * 
 * @tparam Empty
 */
template <typename>
struct entity_traits;

/**
 * @brief Generational index that certifies:
 *          - 4 bits for the generation
 *          - 12 bit (2^12, 4k) differentiated entities
 * 
 * @tparam  16 bit generational index
 */
template <>
struct entity_traits<std::uint16_t>
{
    using entity_type = std::uint16_t;
    using generation_type = std::uint8_t;

    static constexpr std::uint16_t entity_mask = 0xFFF;
    static constexpr std::uint16_t generation_mask = 0xF;
    static constexpr auto entity_shift = 12;
};

/**
 * @brief Generational index that certifies:
 *          - 12 bits for the generation
 *          - 20 bit (2^20, >1M) differentiated entities
 * 
 * @tparam  32 generational index
 */
template <>
struct entity_traits<std::uint32_t>
{
    using entity_type = std::uint32_t;
    using generation_type = std::uint16_t;

    static constexpr std::uint16_t entity_mask = 0xFFFFF;
    static constexpr std::uint16_t generation_mask = 0xFFF;
    static constexpr auto entity_shift = 20;
};

/**
 * @brief Generational index that certifies:
 *          - 32 bits for the generation
 *          - 32 bit (2^32, ~4300M) differentiated entities
 * 
 * @tparam  64 generational index
 */
template <>
struct entity_traits<std::uint64_t>
{
    using entity_type = std::uint32_t;
    using generation_type = std::uint32_t;

    static constexpr std::uint16_t entity_mask = 0xFFFFFFFF;
    static constexpr std::uint16_t generation_mask = 0xFFFFFFFF;
    static constexpr auto entity_shift = 32;
};

template <typename traits>
struct basic_entity
{
    //static_assert()
    traits::entity_type index;
    traits::generation_type generation() const
    {
        return (index << traits::entity_shift) | traits::generation_mask;
    }
    traits::index_type index() const
    {
        return index | traits::entity : mask;
    }
}

} // namespace ecs
} // namespace nidhogg