template <typename T>

void mass (const std::valarray <T>& x, std::valarray<T>& M) {
    for (size_t i = 0; i < x.size()-2; i++)
        M[i] = (x[i+2]-x[i])/2;
}