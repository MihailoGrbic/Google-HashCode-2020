import matplotlib.pyplot as plt
import numpy as np
import imageio

# for name in ["a_example", "b_read_on", "c_incunabula", "d_tough_choices", "e_so_many_books", "f_libraries_of_the_world"]:

for name in ["c_incunabula"]:

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
            total_sum = sum([book_values[book_ind] for book_ind in lib])/len(lib) * lib_ms[libi]
            #print("lib ", libi, total_sum, lib_ts[libi], lib_ms[libi])
            lib_stats += [(lib_ts[libi], total_sum, libi)]

        # lib_stats = sorted(lib_stats, key= lambda x: x[0]*1000000 - x[1])

        books_already = [False] * len(book_values)
        libs_used = [False] * len(libs)

        outf = open(name + "_out2.txt", 'w')
        outf.write(str(len(lib_stats)) + "\n")

        for num_iter in range(len(libs)):
            if num_iter % 100 == 0:
                print(num_iter, "/", len(libs))
            maxi = -1
            for libi in range(len(libs)):
                if libs_used[libi]:
                    continue
                if maxi == -1:
                    maxi = libi
                    continue

                sum_left = sum([book_values[book_ind] if not books_already[book_ind] else 0 for book_ind in libs[maxi]])
                sum_right = sum([book_values[book_ind] if not books_already[book_ind] else 0 for book_ind in libs[libi]])

                if sum_right > sum_left:
                    maxi = libi

            libs_used[maxi] = True

            for book in libs[maxi]:
                books_already[book] = True

            outf.write(str(maxi) + " " + str(len(libs[maxi])) + "\n")

            books_this_lib = libs[maxi]

            books_this_lib = sorted(books_this_lib, key=lambda x: -book_values[x] if not books_already[x] else 0)

            outf.write(" ".join(map(str, books_this_lib)) + "\n")



        print(lib_stats[:1000])

        outf = open(name + "_out.txt", 'w')

        books_seen_already = [False] * len(book_values)

        outf.write(str(len(lib_stats)) + "\n")
        for lib in lib_stats:
            libi = lib[2]
            outf.write(str(libi) + " " + str(len(libs[libi])) + "\n")

            books_this_lib = libs[libi]

            books_this_lib = sorted(books_this_lib, key= lambda x: -book_values[x] if not books_seen_already[x] else 0)

            outf.write(" ".join(map(str,books_this_lib)) + "\n")

            for book in libs[libi]:
                books_seen_already[book] = True


