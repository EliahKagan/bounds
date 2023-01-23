<!-- SPDX-License-Identifier: 0BSD -->

# bounds - lower and upper bound binary search

Classic binary search returns an index when an equivalent item is found, or a
special value if no equivalent item is present.

It can be more useful to use forms of binary search that return either he
lowest or highest index at which the item could be inserted while still
maintaining a sorted array. (Strictly speaking, it is maintaining an array that
is partitioned with respect to the new item. That weaker criterion is
sufficient, and it is not necessary that the data be fully sorted.)

The best way to achieve this varies by language. This shows some demonstration
code in [Python](bounds.py) (usage), [C++](bounds.cpp) (usage), and
[Java](bounds.java) (implementation and usage):

- In Python, they are called
  [`bisect.bisect_left`](https://docs.python.org/3/library/bisect.html#bisect.bisect_left)
  and
  [`bisect.bisect_right`](https://docs.python.org/3/library/bisect.html#bisect.bisect_right).
  (`bisect.bisect` is another name for `bisect.bisect_right`.)

- In C++, these are called
  [`std::lower_bound`](https://en.cppreference.com/w/cpp/algorithm/lower_bound)
  and
  [`std::upper_bound`](https://en.cppreference.com/w/cpp/algorithm/upper_bound).
  ([`std::equal_range`](https://en.cppreference.com/w/cpp/algorithm/equal_range)
  is available if you want both.)

- In Java, the standard library does not offer them. (It offers binary search,
  but not these forms of it.) But they can be implemented without trouble, as
  shown in [`bounds.java`](bounds.java).

## License

[0BSD](https://spdx.org/licenses/0BSD.html). See [**`LICENSE`**](LICENSE).

## See also

[Binary Search - A Different Perspective | Python
Algorithms](https://www.youtube.com/watch?v=tgVSkMA8joQ)\
by [mCoding](https://www.youtube.com/@mCoding) ([James
Murphy](https://github.com/mCodingLLC/))
