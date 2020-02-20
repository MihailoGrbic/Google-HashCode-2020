import matplotlib.pyplot as plt
import numpy as np
import imageio

for name in ["a_example", "b_read_on", "c_incunabula", "d_tough_choices", "e_so_many_books", "f_libraries_of_the_world"]:

# for name in ["c_incunabula"]:

    with open(name + '.txt', 'r') as f:

        b, l, d = [int(x) for x in next(f).split()]
        print("books ", b)
        print("libs ", l)

        book_values = [int(x) for x in next(f).split()]

        libs = []
        lib_ts = []
        lib_ms = []
        for il in range(l):
            n, t, m = [int(x) for x in next(f).split()]
            indencies = [int(x) for x in next(f).split()]
            libs += [indencies]
            lib_ts += [t]
            lib_ms += [m]

        print ("lib ind total_sum time book_per_day")

        lib_stats = []
        for libi in range(len(libs)):
            lib = libs[libi]
            total_sum = sum([book_values[book_ind] for book_ind in lib])
            #print("lib ", libi, total_sum, lib_ts[libi], lib_ms[libi])
            lib_stats += [(lib_ts[libi], total_sum, libi)]

        lib_stats = sorted(lib_stats, key= lambda x: x[0] * 100000 - x[1])
        print(lib_stats[:100])

        outf = open(name + "_out.txt", 'w')

        books_seen_already = [false] * len(book_values)

        outf.write(str(len(lib_stats)) + "\n")
        for lib in lib_stats:
            libi = lib[2]
            outf.write(str(libi) + " " + str(len(libs[libi])) + "\n")


            outf.write(" ".join(map(str,libs[libi])) + "\n")


