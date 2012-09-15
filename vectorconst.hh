#ifndef VECTORCONST_HH
#define VECTORCONST_HH

#include <vector>

template < typename T >
class vectorconst
{
public:

    /* This might not be the best solution but having the result value of at, [], front & back as
       const T& seems to mean that when T is a pointer type it returns a "T* const" instead of a
       "const T*" so we require some simple type trait work to figure out when a pointer type is
       being used and to require "const T*" in that case and "const T&" in others

       After a little more thought, this is the whole reason we're writing this class in the first
       place. A const std::vector< T* > upon operator[] access returns "T* const" rather than "const
       T*", where the former allows you to change the object being pointed to which is doesn't feel
       very const, but the std::vector is only worried about the pointer address values not the
       const-ness of what is being pointed to. */
    template< class U >
    struct TypeTraits
    {
        typedef const U& constReturn;
    };

    template< class U >
    struct TypeTraits< U* >
    {
        typedef const U* constReturn;
    };

    // Constructor
    vectorconst( const std::vector< T >& v )
     : m_vector( v ) {}

    // Const member access methods
    inline typename TypeTraits< T >::constReturn
    at( typename std::vector< T >::size_type pos ) const
    {
        return m_vector.at( pos );
    }

    inline typename TypeTraits< T >::constReturn
    operator[]( typename std::vector< T >::size_type pos ) const
    {
        return m_vector[ pos ];
    }

    inline typename TypeTraits< T >::constReturn
    front() const
    {
        return m_vector.front();
    }

    inline typename TypeTraits< T >::constReturn
    back() const
    {
        return m_vector.back();
    }

    // General information methods
    inline typename std::vector< T >::size_type size() const
    {
        return m_vector.size();
    }

    inline typename std::vector< T >::size_type max_size() const
    {
        return m_vector.max_size();
    }

    inline typename std::vector< T >::size_type capacity() const
    {
        return m_vector.capacity();
    }

    inline bool empty() const
    {
        return m_vector.empty();
    }

    // Only provide a const-iterator
    typedef typename std::vector< T >::const_iterator const_iterator;

    // Const iterator methods
    inline const_iterator begin() const
    {
        return m_vector.begin();
    }

    inline const_iterator end() const
    {
        return m_vector.end();
    }

private:

    const std::vector< T >& m_vector;

};


#endif // VECTORCONST_HH


