#ifndef ADAPT_PRIORITY_QUEUE_H
#define ADAPT_PRIORITY_QUEUE_H

#include<list>

template<typename E>
class IsLess {
    public:
        bool operator()(const E a, const E b) {
            return a < b;
        } 
}

template<typename E, typename C>
class AdaptPriorityQueue {
    private:
        ElementList L;
        C isLess;
    protected:
        typedef std::list<E> ElementList;
    public:
        class Position {
            private:
                typename ElementList::iterator q;
            public:
                const E& operator*() {return *q;}
                friend class AdaptPriorityQueue;
        };
    public:
        int size() const;
        bool empty() const;
        const E& min() const;
        Position insert(const E& e);
        void removeMin();
        void remove(const Position& p);
        Position replace(const Position& p, const E& e);
};

#endif