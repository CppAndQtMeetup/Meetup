% Cppcon 2017 - Trip Report
% Tobias Langner
% C++/QtMeetup Ludwigsburg, 2017-10-05

---------------------

## CppCon
C++ Conference

Bellevue, Washington

USA

---------------------

## Links
- [CppCon](https://cppcon.org)
- [Schedule](https://cppcon2017.sched.org)
- [Slides](https://github.com/CppCon/CppCon2017)
- [Videos](https://youtube.com/user/CppCon)
- [unofficial notes collection](https://www.reddit.com/r/cpp/comments/74e9s0/share_your_notes_from_cppcon_2017_talks/)

---------------------

## Keynotes
> - Learning and Teaching Modern C++ (Bjarne Stroustrup)
> - C++ as "Live at Head" Language (Titus Winters)
> - Meta: thoughts on generative C++ (Herb Sutter)
> - Qt as a C++ Framework: History, present state and future (Lars Knoll)
> - Unbolting the compiler lid - What has my compiler done for me lately (Matt Godbolt)

---------------------

## Noteworthy Talks that I have seen (1/2)
> - Time Travel Debugging
> - C++/WinRT and the future of C++ on Windows
> - vcpkg
> - Fuzz or lose: why and how to make fuzzing a standard practice for C++ 
> - Mocking Frameworks - considered harmful
> - Reflection
> - Emulating a BBC Micro in Javascript

---------------------

## Noteworthy Talks that I have seen (2/2)
> - Runtime Polymorphism
> - Naked Coroutines
> - Finding good Algorithms
> - Allocators - the good parts
> - Curiously Recurring C++ Bugs

---------------------

## Noteworthy Lightning Talks
> - The perils of implementing code from PDFs
> - a C++20 preview: operator <=>
> - Capturing & translating C++ videos [http://cppvap.wikidot.com](http://cppvap.wikidot.com)
> - Regular Expressions Redefined in C++ [https://cpp.fail/re](https://cpp.fail/re)

---------------------


## C++ as "Live at Head" Language

first have is an interesting introduction the the problems of breaking changes and the differences between programming & software engineering.

---------------------

## vcpkg

This talk shows the philosophy behind Microsofts attempt to provide a package manager for windows that fits the developers needs.

- VS2017 & cmake integration
- multiple installations possible
- not invasive (any buildsystem can be used)
- not portable (as others provide better solutions for their platform)

---------------------

## Fuzz or lose

short and gentle introduction on fuzzy. Why it is useful & some references to (Linux/Mac) tools that are available.

---------------------

## Runtime Polymorphism

Based on the observation that runtime polymorphism in C++ using inheritance ties multiple concepts together.
- reference semantics
- heap storage
The talk contains ideas how this can be changed based on [DYNO](https://github.com/ldionne/dyno)

---------------------

## Mocking Frameworks - considered harmful

- Mocking vs. Stubs. Mocks allow the verification of a tested client.
- Frameworks like google mock force you to specify expected behavior together with the mock setup
- verification is usually done on destruction which changes the order of test verification calls
- those frameworks lead to overspecification in tests. This increases refactoring efforts

---------------------

## Naked Coroutines

live coding of a coroutine to send & receive data from the asio example (aka Networking TS). Good example to get started with Coroutines (stackless as implemented in MSVC or Clang 5)

---------------------

## Allocators - the good parts

Tutorial style talk that focusses simple allocator usecases. Includes a simple debugging allocator + containers that use the allocator.

---------------------

## Curiously Recurring C++ Bugs

6 common bugs that appear regularly in Facebooks code base. Includes hints how they can be mitigated or eliminated.

---------------------

## Little tricks 1 - erased ownership

How to erase ownership?

> - create a unique_ptr<> with custom deleter
> - deleter has the signature void(void)
> - if the unique_ptr should own, pass a lambda that calls the destructor
> - if the unique_ptr should not own, pass a function that does nothing

---------------------

## Little tricks 2 - std::endl

What does std::endl do?

> - it does not adapt end line to the OS standard
> - it does '\\n' << std::flush

. . .

**Don't write std::endl. Make it easier for the beginners and write '\\n' << std::flush**

## Already on video - Programming with C++ Constraints: Background, Utility, and Gotchas

A simple introduction into the concepts behind run & compile time contracts. Watch it if you are mildly interested in:

> - constexpr if vs. SFINAE
> - concepts
> - requires


