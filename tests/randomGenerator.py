import random


random_numbers = [random.randrange(0, 1000) for _ in range(1000)]

out = open("tests.in", "w")
out.write(str(random_numbers).replace(",","").replace("[", "").replace("]", ""))

