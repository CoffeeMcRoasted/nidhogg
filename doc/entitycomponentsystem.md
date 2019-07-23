# Nidhogg's Entity Component System

Nidhogg's entity component system is somewhat similar in its core to the concepts proposed in the [EnTT entity component system](https://github.com/skypjack/entt).

What do we want from a Data Oriented ECS
- To be able to store Data contiguously to reduce cache misses.
- To reduce as much as possible the indirections required, which helps in regard of cache misses.
- To be able to generate systems (functions, functors, entire classes) that are able to filter those with a statement similar to a database
- To be able to do inserts, removals and queries efficiently
- To offer an amicable API to do so.

The entities shall be contained within an EntityManager, that will track which entities that exist within the program. The possibility of having several entity managers is yet undefined. This follow the registry pattern.

Entities shall be a generational index. En entity, per se, is just an index to the registry's contained indexes.

To access components filtered, the objective is to offer a view to the component contained within the Registry, which means that 