

test_cases = [
    (
        [
            ('A', 'B'),
            ('B', 'C'),
            ('D', 'B'),
            ('E', 'B'),
            ('F', 'A')
        ],
        [
            'A',
            'B',
            'C',
            'D',
            'E'
        ]
    )
]


def count_num_reports(tree, key):
    if key not in tree:
        return 0

    cnt = 1
    children = tree[key]
    for c in children:
        cnt += count_num_reports(tree, c)
    return cnt


def run(data, tests):
    tree_map = {}

    # build tree
    for (a, b) in data:
        if b not in tree_map:
            tree_map[b] = []
        if a not in tree_map:
            tree_map[a] = []
        tree_map[b].append(a)

    # find number of reports
    print tests
    for test in tests:
        print test, count_num_reports(tree_map, test)


def main():
    for (data, tests) in test_cases:
        run(data, tests)

if __name__ == '__main__':
    main()
