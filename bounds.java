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

import java.util.*;
import java.util.stream.*;

class Scratch {
    public static void main(String[] args) {
        var words = Stream.of(
                "foo", "bar", "baz", "quux", "foobar", "ham", "spam", "eggs", "speggs")
                .collect(Collectors.toCollection(ArrayList::new));
        words.sort(Comparator.naturalOrder());
        System.out.println(words);

        var bsIndex = Collections.binarySearch(words, "spam");
        System.out.println("Binary search: " + bsIndex);

        test(words, "abracadabra");
        test(words, "bar");
        test(words, "spal");
        test(words, "spam");
        test(words, "span");
        test(words, "speggs");
        test(words, "speggt");
    }

    private static <T> void test(List<? extends Comparable<? super T>> items, T key) {
        var lbIndex = lowerBound(items, key);
        System.out.format("Lower bound for \"%s\": %d%n", key, lbIndex);

        var ubIndex = upperBound(items, key);
        System.out.format("Upper bound for \"%s\": %d%n", key, ubIndex);
    }

    private static <T> int lowerBound(List<? extends Comparable<? super T>> items, T key) {
        var low = 0;
        var high = items.size();

        while (low < high) {
            var mid = low + (high - low) / 2;

            if (items.get(mid).compareTo(key) < 0) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }

    private static <T> int upperBound(List<? extends Comparable<? super T>> items, T key) {
        var low = 0;
        var high = items.size();

        while (low < high) {
            var mid = low + (high - low) / 2;

            if (items.get(mid).compareTo(key) <= 0) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
}
