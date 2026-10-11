[readme на русском](readme-ru.md)

[start page](../readme.md)


# Situations of evolutionary expansion of the basic program, implemented using various programming languages.

Each language uses a typical programming paradigm.
The direct solution does not use specially written additional code that specifically provides the necessary evolutionary extensions. For the painless expansion of the program, only those tools that are available in the programming language are used. In their absence, the previously written code is modified.

## Situations considered in the framework of evolutionary expansion

1. The initial solution used for further expansion in various directions. The problem is solved in which various alternative situations are written to a container with generalized figures from a file in which the data is presented in a form that is easy to read by a computer. After that, the generalized figures are copied to another file in a form that is easy for humans to read.

2. Adding a new alternative that expands the set of alternatives. In this case, a circle and functions providing its input and output are added.

3. Adding a new function that provides processing of all available alternatives. In this case, it is a function of calculating the perimeter of the figure.

4. Adding an additional field to the summary, accessible to all alternatives, and organizing input and output for it. A field is added that specifies the color of the shape.

5. Adding a function that works with only one of the alternatives. The output of only rectangles from the contents of the container is added.

6. Adding a multimethod that outputs information about the combination for the two figures under consideration. The multimethod outputs a phrase specific to each of the combinations, which differs in structure from other phrases so that it is not possible to build it automatically.

7. Adding a new alternative to the multimode program and using it in all previously created functions. A circle is a new alternative.

8. Evolutionary expansion at the level of specialized interfaces, aimed at creating different generalizations using the same specialization bases (perhaps it should be linked to one of the SOLID principles related to separation). Still under consideration: is it worth implementing?

## A diagram that defines the relationship between programs that implement different situations.

- 1 -> 2

- 1 -> 3

- 1 -> 4

- 1 -> 5

- 1 -> 6 -> 7

- 1 -> 8

# Code generation options.

1. A direct solution related to the incremental expansion of the original program, which initially does not take into account the possibilities of its further development. In this situation, the flexibility of various programming paradigms and languages is being tested.

2. Indirect solution, when creating the initial program, the possibilities of its incremental expansion are planned in the future. In this case, an additional wrapper can be formed in the source program, which provides further expansion without changing the previously written code, if possible. It is assumed that such a wrapper should not be redundant. That is, it directly includes extension options that will need to be added in the future.