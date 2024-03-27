import random


def generate_array_with_patterns(size, sequence_length):
    array = []
    for i in range(size // sequence_length):
        if i % 2 == 0:
            array.extend(range(i * sequence_length, (i + 1) * sequence_length))  # Ascending sequence
        else:
            array.extend(range((i + 1) * sequence_length - 1, i * sequence_length - 1, -1))  # Descending sequence
    return array


n = 1000000
mx = 100000

#random_numbers = [random.randrange(0, mx) for _ in range(n)]
random_numbers = generate_array_with_patterns(n, 500)


out = open("tests.in", "w")
out.write("1")
out.write(" ")
out.write(str(n))
out.write(" ")
out.write(str(mx))
out.write("\n")
out.write(str(random_numbers).replace(",", "").replace("[", "").replace("]", ""))

