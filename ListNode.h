#ifndef LISTNODE_H
#define LISTNODE_H

template< typename NODETYPE, bool isCircular> class List;


template <typename NODETYPE >
class ListNode{
    friend class List< NODETYPE, true >;
    friend class List< NODETYPE, false >;

    public:
        ListNode(const NODETYPE &);
        NODETYPE getData() const;
    private:
        NODETYPE data;
        ListNode <NODETYPE> *nextPtr;
        ListNode <NODETYPE> *prevPtr;

};

template <typename NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &info)
    : data(info), nextPtr(0), prevPtr(0)
{
}

template <typename NODETYPE>
NODETYPE ListNode< NODETYPE >::getData() const{
    return data;
}

#endif