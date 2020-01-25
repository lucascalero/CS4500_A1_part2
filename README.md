This is a repository that hosts all the files for part 2 of Assignment 1 for Northeastern University's CS4500 Software Development.

This Assignment was done by James Devlin and Lucas Calero Forero.


## Array Implementation

The biggest design decision we made for our Array API is that when you add an Object into a specific index, the array moves all objects to create an empty space for this object to be able to be placed at that index.

Likewise for removing objects, we shift all objects to fill up the empty space left by the removed object.

We created two constructors, one for Object* and another for String*. This ensures that our Array only accepts objects of that type.

This also means that when the first item is added, it will decide the type of this array dynamically.

Which means that after clear is called, the type also has to be cleared. 
