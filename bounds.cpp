#include <algorithm>
#include <iostream>
#include <vector>

namespace {
    template<typename Container, typename Key>
    void test(const Container& c, const Key& k) noexcept
    {
        const auto lb = std::lower_bound(cbegin(c), cend(c), k) - cbegin(c);
        std::cout << "Lower bound for \"" << k << "\": " << lb << '\n';

        const auto ub = std::upper_bound(cbegin(c), cend(c), k) - cbegin(c);
        std::cout << "Upper bound for \"" << k << "\": " << ub << '\n';
    }
}

int main()
{
    auto words = std::vector<std::string>{
        "foo", "bar", "baz", "quux", "foobar", "ham", "spam", "eggs", "speggs"
    };

    std::sort(begin(words), end(words));

    test(words, "abracadabra");
    test(words, "bar");
    test(words, "spal");
    test(words, "spam");
    test(words, "span");
    test(words, "speggs");
    test(words, "speggt");
}
