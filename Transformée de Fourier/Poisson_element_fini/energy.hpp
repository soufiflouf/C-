template <typename T>
void energy (const std::valarray <T>& x, std::valarray <T>& D, std::valarray <T>& L) 
{
    for (size_t i = 0; i+2 < x.size(); i++)
        D [i] = 1/(x[i+1]-x[i]) + 1/(x[i+2]-x[i+1]);
    for (size_t i = 0; i+3 < x.size(); i++) L [i] = - 1/(x[i+2]-x[i+1]);
        L [x.size()-3] = 0;
}