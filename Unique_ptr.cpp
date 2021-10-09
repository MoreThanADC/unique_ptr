template <typename T>
class Unique 
{
    T* data_{};
public:
    explicit Unique(T* ptr) : data_(ptr) {};
    ~Unique() {
        delete data_;
    }
    Unique(const Unique&) = delete;
    Unique& operator=(const Unique&) = delete;

    Unique(Unique&& other) noexcept {
        data_ = other.data_;
        other.data_ = nullptr;
    }
    Unique&& operator=(Unique&& other) {
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

    void reset(T* ptr) {
        data_ = ptr;
        ptr = nullptr;
    }
};