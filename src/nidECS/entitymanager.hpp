#include <nidECS/Entity.hpp>
#include <tuple>

template <typename Entity, typename Components...>
class EntityManager
{
public:
    EntityManager() = default;
    ~EntityManager() = default;
    //Non-copyable but movable
    EntityManager(const EntityManager &) = delete;
    EntityManager &operator=(const EntityManager &) = delete;
    EntityManager(EntityManager &&) = default;
    EntityManager &operator=(EntityManager &&) = default;

private:
    using component_vs = std::tuple<std::vector<Components>...>;

    template <typename T>
    struct SameType<T, T>
    {
        constexpr static bool value = true;
    }

    template <typename T1, typename T2>
    struct SameType
    {
        constexpr static bool value = false;
    }

    template <int N, typename T>
    struct ComponentVector : SameType<T, typename std::tuple_element<n, component_vs>::type::value_type>
    {
    };
    // non-match overload
    template <int N, class T, class Tuple, bool IsMatch = false>
    struct Match
    {
        static vector<T> &get(Tuple &tp)
        {
            return Match<N + 1, T, Tuple, ComponentVector<N + 1, T>::value>::get(tp);
        }
    };

    // match overload
    template <int N, class T, class Tuple, true>
    struct Match
    {
        static vector<T> &get(Tuple &tp)
        {
            return std::get<N>(tp);
        }
    };

public:
    template <typename Component>
    vector<Component> &
    getVector()
    {
        return Match<0, Component, component_vs, ComponentVector<0, Component>::value>::get(m_components);
    }

private:
    component_vs m_components;
}