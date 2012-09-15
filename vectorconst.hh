#ifndef VECTORCONST_HH
#define VECTORCONST_HH

#include <vector>

template < typename T >
class vectorconst
{
public:

    vectorconst( const std::vector< T >& v )
     : m_vector( v ) {}

    inline const T& at( typename std::vector< T >::size_type pos ) const
    {
        return m_vector.at( pos );
    }

    inline const T& operator[]( typename std::vector< T >::size_type pos ) const
    {
        return m_vector[ pos ];
    }

    inline const T& front() const
    {
        return m_vector.front();
    }

    inline const T& back() const
    {
        return m_vector.back();
    }

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

private:

    const std::vector< T >& m_vector;

};


#endif // VECTORCONST_HH


