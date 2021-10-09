template <typename T>
class Unique 
{
    T* data_;
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
        if (this != other) {
            // TO DO
        }
        return *this;
    }
};