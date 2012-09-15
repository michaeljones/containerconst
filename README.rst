
vectorconst
===========

This is an attempt to solve the problem when you want to return a const version
of ``std::vector< T* >``, such that the items being pointed to by the pointers
in the ``std::vector`` cannot be altered.

Unfortunately, returning a ``const std::vector< T* >`` means that access methods
for getting at items in the ``std::vector`` all return ``T* const``, ie.
const-pointers not pointers to const-objects.

So my proposal is to return a custom class called ``vectorconst< T* >`` wrapped
around a reference to the ``std::vector< T* >``.  The ``vectorconst`` has only
const-access methods on it and more general methods like ``size()`` and
``empty()``.

The access methods all return the appropriate ``const T*`` instead of ``T*
const``.

Feedback
--------

Thoughts & feedback would be welcome.  I assume there are other approaches to
solving this.  Probably better than mine.
