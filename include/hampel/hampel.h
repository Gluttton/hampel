#ifndef HAMPEL_H
#define HAMPEL_H

#include <algorithm>
#include <vector>



namespace Hampel
{

template <class RandomAccessIterator, class T = typename RandomAccessIterator::value_type>
T Hampel (RandomAccessIterator first, RandomAccessIterator last, T n = 5.2)
{
    // Make a copy of the original data and perform some preparation.
    std::vector <T> s (first, last);
    const size_t halfsize = s.size () / 2;
    const auto center = s.begin () + halfsize;

    // Find median in the original sequence.
    std::nth_element (s.begin (), center, s.end () );
    const T med = * center;

    // Find residuals with median value.
    s.resize (0);
    std::transform (first, last, std::back_inserter (s), [=](T x){return std::abs (x - med);});

    // Find a mad and standard deviation.
    constexpr T k = 1.4826;
    std::nth_element (s.begin (), center/*mad*/, s.end () );
    const T sdev = * center * k;

    // Return filtered value for central element in the window.
    return std::abs (* (first + halfsize) - med) <= n * sdev
                   ? * (first + halfsize) : med;
}

}//namespace Hampel

#endif//HAMPEL_H
