#include <iostream>
#include <memory>
#include <vector>
#include <typeinfo>

template <typename T>
class static_allocator
{
   public:
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using value_type = T;

    static_allocator() {}
    ~static_allocator() {}

    template <class U>
    struct rebind { typedef static_allocator<U> other; };
    template <class U>
    static_allocator(const static_allocator<U>&) {
    }

    pointer address(reference x) const { return &x; }
    const_pointer address(const_reference x) const { return &x; }
    size_type max_size() const throw() { return -1; }

    pointer allocate(size_type n, const_pointer hint = 0) {
        std::cout << "  allocate " << n << std::endl;
        return static_cast<pointer>(malloc(n * sizeof(T))); }

    void deallocate(pointer p, size_type n) {
        std::cout << "  deallocate " << n << std::endl;
        free(p); }

    void construct(pointer p, const T& val)
    {
        std::cout << "  construct " << val << " for "  << typeid(p).name() << std::endl;
        new (static_cast<void*>(p)) T(val);
    }

    void construct(pointer p) {
        std::cout << "  construct" << typeid(p).name() << std::endl;
        new (static_cast<void*>(p)) T();
    }

    void destroy(pointer p) {
        std::cout << "  destroy " << typeid(p).name() << std::endl;
        p->~T(); }
};

int main() {
    std::vector<int, static_allocator<int>> v;
    std::cout << "START" << std::endl;
    for (auto i : std::array<int, 7>{4, 8, 15, 16, 23, 42, 108}) {
        std::cout << "push_back " << i << std::endl;
        v.push_back(i);
    }
    std::cout << "END" << std::endl;
}
