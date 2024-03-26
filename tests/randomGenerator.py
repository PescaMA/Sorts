import random


n = 10000000
mx = 100000

random_numbers = [random.randrange(0, mx) for _ in range(n)]

out = open("tests.in", "w")
out.write("1")
out.write(" ")
out.write(str(n))
out.write(" ")
out.write(str(mx))
out.write("\n")
out.write(str(random_numbers).replace(",","").replace("[", "").replace("]", ""))

