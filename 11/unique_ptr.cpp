#include <cstddef> // std::nullptr_t
#include <utility> // std::move, std::swap

// Deleter par défaut pour un objet simple
template <typename T> struct default_delete {
  void operator()(T *ptr) const noexcept {
    static_assert(sizeof(T) > 0, "cannot delete pointer to incomplete type");
    delete ptr;
  }
};

// unique_ptr pour un objet simple T
template <typename T, typename Deleter = default_delete<T>> 
class unique_ptr {
public:
  using pointer = T *;
  using element_type = T;
  using deleter_type = Deleter;

  // 1) Constructeurs
  constexpr unique_ptr() noexcept : ptr_(nullptr), deleter_(Deleter()) {}

  explicit unique_ptr(pointer p) noexcept : ptr_(p), deleter_(Deleter()) {}

  unique_ptr(pointer p, const Deleter &d) noexcept : ptr_(p), deleter_(d) {}

  // non copiable
  unique_ptr(const unique_ptr &) = delete;
  unique_ptr &operator=(const unique_ptr &) = delete;

  // déplaçable
  unique_ptr(unique_ptr &&other) noexcept
      : ptr_(other.release()), deleter_(std::move(other.deleter_)) {}

  unique_ptr &operator=(unique_ptr &&other) noexcept {
    if (this != &other) {
      reset(other.release());
      deleter_ = std::move(other.deleter_);
    }
    return *this;
  }

  // 2) Destructeur
  ~unique_ptr() { reset(); }

  // 3) Accès
  T &operator*() const { return *ptr_; }

  pointer operator->() const noexcept { return ptr_; }

  pointer get() const noexcept { return ptr_; }

  deleter_type &get_deleter() noexcept { return deleter_; }

  const deleter_type &get_deleter() const noexcept { return deleter_; }

  explicit operator bool() const noexcept { return ptr_ != nullptr; }

  // 4) Modificateurs
  pointer release() noexcept {
    pointer old = ptr_;
    ptr_ = nullptr;
    return old;
  }

  void reset(pointer p = pointer()) noexcept {
    if (ptr_ != p) {
      if (ptr_) {
        deleter_(ptr_);
      }
      ptr_ = p;
    }
  }

  void swap(unique_ptr &other) noexcept {
    using std::swap;
    swap(ptr_, other.ptr_);
    swap(deleter_, other.deleter_);
  }

private:
  pointer ptr_;
  deleter_type deleter_;
};

// fonction utilitaire swap
template <typename T, typename D>
void swap(unique_ptr<T, D> &a, unique_ptr<T, D> &b) noexcept {
  a.swap(b);
}
