import random


def generate_array_with_patterns(size, sequence_length):
    array = []
    for i in range(size // sequence_length):
        if i % 2 == 0:
            array.extend(range(i * sequence_length, (i + 1) * sequence_length))  # Ascending sequence
        else:
            array.extend(range((i + 1) * sequence_length - 1, i * sequence_length - 1, -1))  # Descending sequence
    array.extend(range(size // sequence_length * sequence_length , size // sequence_length * sequence_length + size % sequence_length))
    return array


n = 15_000_000
mx = 1_000_000

#random_numbers = [random.randrange(0, mx) for _ in range(n)]
#random_numbers = generate_array_with_patterns(n, 500)

tests = []

#tests.append([random.randrange(0, mx) for _ in range(n)])
#tests.append([random.uniform(0,mx) for _ in range(n)])
tests.append(generate_array_with_patterns(n, 500))

out = open("tests.in", "w")
out.write(str(len(tests)))
for test in tests:
    out.write("\n")
    out.write(str(len(test)))
    out.write(" ")
    out.write(str(max(test)))
    out.write("\n")
    out.write(str(test).replace(",", "").replace("[", "").replace("]", ""))

