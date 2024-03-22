import random

random_numbers = [random.randint(1, 10**9) for _ in range(1000000)]

out = open("out.out.out", "w")
out.write(str(random_numbers).replace(",",""))

