template <typename T>
class Unique 
{
    T* data_{};
public:
    explicit Unique(T* ptr = nullptr) : data_(ptr) {};
    ~Unique() {
        delete data_;
    }
    Unique(const Unique<T>&) = delete;
    Unique<T>& operator=(const Unique<T>&) = delete;

    Unique(Unique&& other) noexcept {
        data_ = other.data_;
        other.data_ = nullptr;
    }
    Unique<T>& operator=(Unique&& other) {
        if (this != &other) {
            delete data_;
            data_ = other.data_;
            other.data_ = nullptr;
        }
        return *this;
    }

    T& operator*() const {
        return *data_;
    }

    T* operator->() const {
        return data_;
    }

    T* get() const {
        return data_;
    }

    T* release() {
        T* temp = data_;
        data_ = nullptr;
        return temp;
    }

    void reset(T* ptr = nullptr) {
        delete data_;
        data_ = ptr;       
    }
};