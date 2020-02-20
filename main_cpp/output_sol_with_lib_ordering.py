
import numpy as np

# for name in ["a_example", "b_read_on", "c_incunabula", "d_tough_choices", "e_so_many_books", "f_libraries_of_the_world"]:
for name in ["b_read_on", "e_so_many_books", "f_libraries_of_the_world"]:

# for name in ["a_example"]:

    with open(name + '.txt', 'r') as f:

        libs_ordering = list(map(int, open(name + "_libs.txt", "r").read().split()))

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

        # print ("lib ind total_sum time book_per_day")
        #
        # lib_stats = []
        # for libi in range(len(libs)):
        #     lib = libs[libi]
        #     total_sum = sum([book_values[book_ind] for book_ind in lib])
        #     #print("lib ", libi, total_sum, lib_ts[libi], lib_ms[libi])
        #     lib_stats += [(lib_ts[libi], total_sum, libi)]
        #
        # lib_stats = sorted(lib_stats, key= lambda x: x[0] * 100000 - x[1])
        # print(lib_stats[:100])

        outf = open(name + "_out.txt", 'w')

        books_seen_already = [False] * len(book_values)

        outf.write(str(len(libs_ordering)) + "\n")
        for libi in libs_ordering:
            outf.write(str(libi) + " " + str(len(libs[libi])) + "\n")

            books_this_lib = libs[libi]

            books_this_lib = sorted(books_this_lib, key= lambda x: -book_values[x] if not books_seen_already[x] else 0)

            outf.write(" ".join(map(str,books_this_lib)) + "\n")

            for book in libs[libi]:
                books_seen_already[book] = True


