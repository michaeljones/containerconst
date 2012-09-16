
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

Example
-------

This is the awkward case with ``std::vector< T* >``.

   class Node
   {
   public:

      const std::vector< Node* >& getConstChildren() const
      {
         return m_children;
      }

      void setName( const std::string& name )
      {
         m_name = name;
      }

   private:

      std::string m_name;
      std::vector< Node* > m_children;
   };

   void func( const Node* node )
   {
      const std::vector< T* >& children = node->getConstChildren();

      // Will not compile because the vector is const, good.
      // children.push_back( new Node );


      // Will not compile because the Node*s in the vector are const, so you
      // can't change them to point at another address, good.
      // children[ 0 ] = new Node;


      // Compiles fine as the pointer returned by childre[1] is to a non-const
      // Node. This is bad as we don't want to be changing anything about the
      // node or the children given that we're trying to get const versions of
      // them
      children[1].setName( "a differnet name" );
   }

This is the general designed use case::

   typedef vectorconst< Node > ConstNodePtrArray;

   class Node
   {
   public:

      ConstNodePtrArray getConstChildren() const
      {
         return ConstNodePtrArray( m_children );
      }

      void setName( const std::string& name )
      {
         m_name = name;
      }

   private:

      std::string m_name;
      std::vector< Node* > m_children;
   };

   void func( const Node* node )
   {
      ConstNodePtrArray children = node->getConstChildren();

      // Compiles fine as we're requesting a pointer to a const object
      const Node* child = children[0];

      // Does not compile due to const incorrectness, good.
      // Node* child = children[1];

      // Does not compile due to const incorrectness, good.
      // children[1].setName( "a different name" );
   }


Feedback
--------

Thoughts & feedback would be welcome.  I assume there are other approaches to
solving this.  Probably better than mine.

