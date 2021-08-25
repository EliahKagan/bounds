#!/usr/bin/env python3


def lower_bound(items, key):
    low = 0
    high = len(items)

    while low < high:
        mid = (low + high) // 2

        if key > items[mid]:
            low = mid + 1
        else:
            high = mid

    return low


def upper_bound(items, key):
    low = 0
    high = len(items)

    while low < high:
        mid = (low + high) // 2

        if key < items[mid]:
            high = mid
        else:
            low = mid + 1

    return low


def test(items, key):
    lb_index = lower_bound(items, key)
    print(f'Lower bound for "{key}": {lb_index}')

    ub_index = upper_bound(items, key)
    print(f'Upper bound for "{key}": {ub_index}')


def run():
    words = ['foo', 'bar', 'baz', 'quux', 'foobar', 'ham', 'spam', 'eggs', 'speggs']
    words.sort()

    test(words, "abracadabra")
    test(words, "bar")
    test(words, "spal")
    test(words, "spam")
    test(words, "span")
    test(words, "speggs")
    test(words, "speggt")


if __name__ == '__main__':
    run()
