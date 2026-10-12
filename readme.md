[readme на русском](readme-ru.md)

# Examples of programs demonstrating the capabilities of procedural-parametric programming

The repository is currently undergoing refactoring, with programs being categorized according to programming paradigms and languages.

Alongside examples of procedural-parametric programs, the repository includes examples written using other programming paradigms for comparison. The programs are organized by paradigm and language, and a consistent directory structure is used for examples implemented across different languages ​​and paradigms. This structure is intended to facilitate working with the various paradigms and programming languages.

## evolution

The [evolution](evolution) directory contains examples demonstrating the possibilities of evolutionary program expansion. That is, adding new functionality and data without changing the previously written code. The main idea is to compare the PP paradigm with other programming paradigms.

They are considered as options that provide direct extension using the techniques that this or that paradigm provides. In this situation, where direct solutions do not provide evolutionary extension, an extension with changes is implemented.

In addition, examples are located separately in which, due to additional code, an attempt is made to implement an evolutionary extension of previously written code. A more detailed description of the catalog is provided in the [accompanying description](evolution/readme.md).

## oo-patterns

Programs that implement the OO design patterns discussed in the book the Gang of Four (GoF). They are located in the [oo-patterns](oo-patterns) directory. A more detailed description of the catalog is provided in the [accompanying description](oo-patterns/readme.md). The OO versions of the patterns are implemented in C++. PP pattern simulation is performed on PPC. The main idea is to show that the PP paradigm provides equivalent solutions. These solutions are often more diverse and effective.

## other

Various programs written using the PP approach. In some cases, similar programs implemented using other programming paradigms are given.

## problems

Programs demonstrating various problems associated with compiler errors and shortcomings, as well as demonstrating situations where one or another solution turned out to be erroneous, but can be implemented in the PP programming language of a higher level.

## technics

Basic techniques of procedural-parametric programming in comparison with techniques used in other paradigms. The main idea is to demonstrate basic capabilities equivalent to those of other paradigms, options and solutions that provide algorithmic and compositional solutions when one or another technique cannot be implemented directly, as well as techniques that are present in the PP paradigm but are absent in other paradigms.

Alternative approaches include: OOP (C++), Pure procedural approach, Go and Rust language capabilities.

## container

The catalog is planned to include containers similar in functionality to C++ container classes. The absence of templates in the C language prevents the full capabilities of C++ from being covered. However, procedural-parametric polymorphism allows for the creation of containers with similar value type substitution. Currently, an equivalent of the std::vector class has been implemented.

## tmp
The catalog contains raw and unfinished programs. It also contains templates for creating catalogs and old programs that can be modified for placement in various thematic catalogs.
