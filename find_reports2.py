

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
    ),

    # dual reporting
    (
        [
            ('A', 'B'),
            ('C', 'B'),
            ('C', 'D')
        ],
        []
    ),

    # circular reporting
    (
        [
            ('A', 'B'),
            ('B', 'C'),
            ('C', 'D'),
            ('D', 'A')
        ],
        ['A']
    )
]

class Person:
    def __init__(self, name, manager):
        self._name = name
        self._manager = manager
        self._reports = []

def count_num_reports(person, mgmt_chain):
    if person._name in mgmt_chain:
        mgmt_chain.append(person._name)
        raise Exception('circular reporting structure detected: %s' % ' -> '.join(mgmt_chain))

    mgmt_chain.append(person._name)
    cnt = 1
    for c in person._reports:
        cnt += count_num_reports(c, mgmt_chain)

    mgmt_chain.remove(person._name)
    return cnt


def run(data, tests):
    name_map = {}

    # build tree
    for (a, b) in data:
        if b not in name_map:
            name_map[b] = Person(b, None)
        if a not in name_map:
            name_map[a] = Person(a, b)
        elif name_map[a]._manager is not None and name_map[a]._manager != b:
            raise Exception('%s has more than one manager: %s, %s' % (a, name_map[a]._manager, b))

        name_map[b]._reports.append(name_map[a])

    # find number of reports
    for test in tests:
        print test, count_num_reports(name_map[test], []) - 1

def main():
    for (data, tests) in test_cases:
        try:
            run(data, tests)
        except Exception as e:
            print e.message

if __name__ == '__main__':
    main()
