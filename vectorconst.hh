#ifndef VECTORCONST_HH
#define VECTORCONST_HH

#include <iterator>
#include <vector>

namespace vectorconstiterator {

// Implement random access iterator which only provides const access
//
// It simply wraps a standard std::vector< T* >::const_iterator converting any required return
// types to "const T*" instead of "T* const"
//
// Based on the specification:
//
//  http://www.cplusplus.com/reference/std/iterator/RandomAccessIterator
//
template< typename T >
class const_iterator : public std::iterator< std::random_access_iterator_tag, T >
{
public:

    typedef typename std::vector< T* >::const_iterator core_type;

    typedef typename std::iterator< std::random_access_iterator_tag, T >::difference_type difference_type;

    const_iterator() : m_iterator() {}
    const_iterator( core_type iterator ) : m_iterator( iterator ) {}

    // Dereferencing
    inline const T* operator*() const
    {
        return *m_iterator;
    }

    inline const T* operator->() const
    {
        return *m_iterator;
    }

    inline const T* operator[]( const difference_type& n )
    {
        return m_iterator[ n ];
    }

    // Prefix increment
    inline const_iterator& operator++()
    {
        ++m_iterator;
        return *this;
    }

    // Postfix increment
    inline const_iterator operator++(int)
    {
        return const_iterator( m_iterator++ );
    }

    // Prefix decrement
    inline const_iterator& operator--()
    {
        --m_iterator;
        return *this;
    }

    // Postfix decrement
    inline const_iterator operator--(int)
    {
        return const_iterator( m_iterator-- );
    }

    inline const_iterator& operator+=( const difference_type& n )
    {
        m_iterator += n;
        return *this;
    }

    inline const_iterator& operator-=( const difference_type& n )
    {
        m_iterator -= n;
        return *this;
    }

    // Comparison friend functions
    template< typename U, typename V >
    friend bool operator==( const const_iterator< U >& lhs, const const_iterator< V >& rhs );
    template< typename U, typename V >
    friend bool operator!=( const const_iterator< U >& lhs, const const_iterator< V >& rhs );
    template< typename U, typename V >
    friend bool operator<( const const_iterator< U >& lhs, const const_iterator< V >& rhs );
    template< typename U, typename V >
    friend bool operator>( const const_iterator< U >& lhs, const const_iterator< V >& rhs );
    template< typename U, typename V >
    friend bool operator<=( const const_iterator< U >& lhs, const const_iterator< V >& rhs );
    template< typename U, typename V >
    friend bool operator>=( const const_iterator< U >& lhs, const const_iterator< V >& rhs );

    // Arithmetic friend functions
    template< typename U >
    friend const_iterator< U > operator+(
            const const_iterator< U >& lhs,
            const typename const_iterator< U >::difference_type& n
            );
    template< typename U >
    friend const_iterator< U > operator-(
            const const_iterator< U >& lhs,
            const typename const_iterator< U >::difference_type& n
            );
    template< typename U >
    friend typename const_iterator< U >::difference_type operator-(
            const const_iterator< U >& lhs,
            const const_iterator< U >& rhs
            );
private:

    core_type m_iterator;
};

// Comparisons
template< typename U, typename V >
inline bool operator==( const const_iterator< U >& lhs, const const_iterator< V >& rhs )
{
    return lhs.m_iterator == rhs.m_iterator;
}

template< typename U, typename V >
inline bool operator!=( const const_iterator< U >& lhs, const const_iterator< V >& rhs )
{
    return lhs.m_iterator != rhs.m_iterator;
}

template< typename U, typename V >
inline bool operator<( const const_iterator< U >& lhs, const const_iterator< V >& rhs )
{
    return lhs.m_iterator < rhs.m_iterator;
}

template< typename U, typename V >
inline bool operator>( const const_iterator< U >& lhs, const const_iterator< V >& rhs )
{
    return lhs.m_iterator > rhs.m_iterator;
}

template< typename U, typename V >
inline bool operator<=( const const_iterator< U >& lhs, const const_iterator< V >& rhs )
{
    return lhs.m_iterator <= rhs.m_iterator;
}

template< typename U, typename V >
inline bool operator>=( const const_iterator< U >& lhs, const const_iterator< V >& rhs )
{
    return lhs.m_iterator >= rhs.m_iterator;
}

// Arithmetic
template< typename U >
inline const_iterator< U > operator+(
        const const_iterator< U >& lhs,
        const typename const_iterator< U >::difference_type& n
        )
{
    return const_iterator< U >( lhs.m_iterator + n );
}

template< typename U >
inline const_iterator< U > operator-(
        const const_iterator< U >& lhs,
        const typename const_iterator< U >::difference_type& n
        )
{
    return const_iterator< U >( lhs.m_iterator - n );
}

template< typename U >
inline typename const_iterator< U >::difference_type operator-(
        const const_iterator< U >& lhs,
        const const_iterator< U >& rhs
        )
{
    return lhs.m_iterator - rhs.m_iterator;
}

} // end namespace vectorconstiterator

template < typename T >
class vectorconst
{
public:

    // Constructor
    vectorconst( const std::vector< T* >& v )
     : m_vector( v ) {}

    // Const member access methods
    inline const T*
    at( typename std::vector< T* >::size_type pos ) const
    {
        return m_vector.at( pos );
    }

    inline const T*
    operator[]( typename std::vector< T* >::size_type pos ) const
    {
        return m_vector[ pos ];
    }

    inline const T*
    front() const
    {
        return m_vector.front();
    }

    inline const T*
    back() const
    {
        return m_vector.back();
    }

    // General information methods
    inline typename std::vector< T* >::size_type size() const
    {
        return m_vector.size();
    }

    inline typename std::vector< T* >::size_type max_size() const
    {
        return m_vector.max_size();
    }

    inline typename std::vector< T* >::size_type capacity() const
    {
        return m_vector.capacity();
    }

    inline bool empty() const
    {
        return m_vector.empty();
    }

    typedef vectorconstiterator::const_iterator< T > const_iterator;

    // Const iterator methods
    inline const_iterator begin() const
    {
        return const_iterator( m_vector.begin() );
    }

    inline const_iterator end() const
    {
        return const_iterator( m_vector.end() );
    }

private:

    const std::vector< T* >& m_vector;

};


#endif // VECTORCONST_HH


