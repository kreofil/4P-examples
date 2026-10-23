[readme на русском](readme-ru.md)

# Various implementations of John Conway's Game of Life

Various approaches to implementation are presented.
In the `plane` directory, life is simulated on a bounded plane.
In the `tor` directory, a toroidal space is used.
Three variants are implemented in each case:

1. Traditional procedural programming in C is used, in which the cell state is specified by an enumeration type (projects `conway-life-c`, `conway-life-c-tor`).
2. Instead of an enumeration type, a generalization is used, extended by specializations that simulate an evolutionarily extendable enumeration type. This involves direct transformations of field cells using the functions `cmp_spec` and `init_spec`, which simulate comparison and explicit modification of specializations in a procedural style (projects `conway-life-ppc-cmp`, `conway-life-ppc-cmp-tor`).
3. To handle alternative states, procedural-parametric polymorphism is used, in which each alternative uses its own specialization handler (projects `conway-life-ppc-poly`, `conway-life-ppc-poly-tor`).