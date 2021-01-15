#!/usr/bin/env python3
#!/usr/bin/env python2

import random
print('#include "ft_printf.h"');
print("")

print("int main(void)\n{", end='')
for i in range(25): #NOMBRE DE TESTS A GENERER ICI
    bool_minus = random.randint(0,1)
    bool_double_arg = random.randint(0,1)
    bool_first_arg = random.randint(0,1)
    bool_second_arg = random.randint(0,1)
    print("\n\tprintf(\" <- [%d]\\n\", ft_printf(\"|%",end='')
    if bool_minus != 0:
        print("-", end='')
    if bool_double_arg != 0:
        if bool_first_arg != 0:
            print("*", end='')
        else:
            random1 = random.randint(0,20)
            if random1 != 0:
                print(random1, end='')
        print(".", end='')
        if bool_second_arg != 0:
            print("*", end='')
        else:
            random2 = random.randint(0,20)
            print(random2, end='')
        print("d|\"", end='')
        if bool_first_arg != 0:
            print(", ", end='')
            random3 = random.randint(-20,20)
            print(random3, end='')
        if bool_second_arg != 0:
            print(", ", end='')
            random4 = random.randint(-20,20)
            print(random4, end='')
    else:
        bool_single_arg = random.randint(0,1)
        if bool_single_arg != 0:
            print("*d|\", ", end='')
            random5 = random.randint(-20,20)
            print(random5, end='')
        else:
            random6 = random.randint(20,20)
            if random6 != 0:
                print(random6, end='')
            print("d|\"", end='')
    random7 = random.randint(-20,20)
    print(", ", end='')
    print(random7, end='')
    print("));")
    print("\tprintf(\" <- [%d]\\n\\n\", printf(\"|%",end='')
    if bool_minus != 0:
        print("-", end='')
    if bool_double_arg != 0:
        if bool_first_arg != 0:
            print("*", end='')
        else:
            if random1 != 0:
                print(random1, end='')
        print(".", end='')
        if bool_second_arg != 0:
            print("*", end='')
        else:
            print(random2, end='')
        print("d|\"", end='')
        if bool_first_arg != 0:
            print(", ", end='')
            print(random3, end='')
        if bool_second_arg != 0:
            print(", ", end='')
            print(random4, end='')
    else:
        if bool_single_arg != 0:
            print("*d|\", ", end='')
            print(random5, end='')
        else:
            if random6 != 0:
                print(random6, end='')
            print("d|\"", end='')
    print(", ", end='')
    print(random7, end='')
    print("));")
print("\n\treturn (0);\n}")
