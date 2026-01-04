# ---------- To Decimal ----------
def binary_to_decimal(b):
    dec = 0
    power = 0
    for digit in reversed(b):
        dec += int(digit) * (2 ** power)
        power += 1
    return dec


def octal_to_decimal(o):
    dec = 0
    power = 0
    for digit in reversed(o):
        dec += int(digit) * (8 ** power)
        power += 1
    return dec


def hex_to_decimal(h):
    dec = 0
    power = 0
    h = h.upper()

    for ch in reversed(h):
        if ch.isdigit():
            value = int(ch)
        else:
            value = ord(ch) - ord('A') + 10
        dec += value * (16 ** power)
        power += 1

    return dec


# ---------- From Decimal ----------
def decimal_to_binary(n):
    if n == 0:
        return "0"
    result = ""
    while n > 0:
        result = str(n % 2) + result
        n //= 2
    return result


def decimal_to_octal(n):
    if n == 0:
        return "0"
    result = ""
    while n > 0:
        result = str(n % 8) + result
        n //= 8
    return result


def decimal_to_hex(n):
    if n == 0:
        return "0"
    digits = "0123456789ABCDEF"
    result = ""
    while n > 0:
        result = digits[n % 16] + result
        n //= 16
    return result


# ---------- MAIN MENU ----------
print("===== Base Conversion Menu =====")
print("1. Binary")
print("2. Decimal")
print("3. Octal")
print("4. Hexadecimal")

source = int(input("Choose source base: "))
target = int(input("Choose target base (1-Bin, 2-Dec, 3-Oct, 4-Hex): "))
number = input("Enter number: ")

# Convert source to decimal
if source == 1:
    decimal_value = binary_to_decimal(number)
elif source == 2:
    decimal_value = int(number)
elif source == 3:
    decimal_value = octal_to_decimal(number)
elif source == 4:
    decimal_value = hex_to_decimal(number)
else:
    print("Invalid source base!")
    exit()

# Convert decimal to target
print("Result: ", end="")

if target == 1:
    print(decimal_to_binary(decimal_value))
elif target == 2:
    print(decimal_value)
elif target == 3:
    print(decimal_to_octal(decimal_value))
elif target == 4:
    print(decimal_to_hex(decimal_value))
else:
    print("Invalid target base!")
