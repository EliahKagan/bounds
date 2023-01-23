// Copyright (c) 2021 Eliah Kagan
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
// OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
// CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

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
