import java.util.Scanner;

public class BaseConversion {

    // ---------- Binary to Decimal ----------
    static int binaryToDecimal(String bin) {
        int dec = 0;
        int power = 0;

        for (int i = bin.length() - 1; i >= 0; i--) {
            dec += (bin.charAt(i) - '0') * Math.pow(2, power++);
        }
        return dec;
    }

    // ---------- Octal to Decimal ----------
    static int octalToDecimal(String oct) {
        int dec = 0;
        int power = 0;

        for (int i = oct.length() - 1; i >= 0; i--) {
            dec += (oct.charAt(i) - '0') * Math.pow(8, power++);
        }
        return dec;
    }

    // ---------- Hexadecimal to Decimal ----------
    static int hexToDecimal(String hex) {
        int dec = 0;
        int base = 1;
        hex = hex.toUpperCase();

        for (int i = hex.length() - 1; i >= 0; i--) {
            char c = hex.charAt(i);

            if (c >= '0' && c <= '9')
                dec += (c - '0') * base;
            else
                dec += (c - 'A' + 10) * base;

            base *= 16;
        }
        return dec;
    }

    // ---------- Decimal to Binary ----------
    static String decimalToBinary(int n) {
        if (n == 0) return "0";
        String result = "";

        while (n > 0) {
            result = (n % 2) + result;
            n /= 2;
        }
        return result;
    }

    // ---------- Decimal to Octal ----------
    static String decimalToOctal(int n) {
        if (n == 0) return "0";
        String result = "";

        while (n > 0) {
            result = (n % 8) + result;
            n /= 8;
        }
        return result;
    }

    // ---------- Decimal to Hex ----------
    static String decimalToHex(int n) {
        if (n == 0) return "0";
        String digits = "0123456789ABCDEF";
        String result = "";

        while (n > 0) {
            result = digits.charAt(n % 16) + result;
            n /= 16;
        }
        return result;
    }

    // ---------- MAIN ----------
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("===== Base Conversion Menu =====");
        System.out.println("1. Binary");
        System.out.println("2. Decimal");
        System.out.println("3. Octal");
        System.out.println("4. Hexadecimal");

        System.out.print("Choose source base: ");
        int source = sc.nextInt();

        System.out.print("Choose target base (1-Bin, 2-Dec, 3-Oct, 4-Hex): ");
        int target = sc.nextInt();

        System.out.print("Enter number: ");
        String input = sc.next();

        int decimalValue;

        // Source → Decimal
        switch (source) {
            case 1:
                decimalValue = binaryToDecimal(input);
                break;
            case 2:
                decimalValue = Integer.parseInt(input);
                break;
            case 3:
                decimalValue = octalToDecimal(input);
                break;
            case 4:
                decimalValue = hexToDecimal(input);
                break;
            default:
                System.out.println("Invalid source base!");
                return;
        }

        // Decimal → Target
        System.out.print("Result: ");
        switch (target) {
            case 1:
                System.out.println(decimalToBinary(decimalValue));
                break;
            case 2:
                System.out.println(decimalValue);
                break;
            case 3:
                System.out.println(decimalToOctal(decimalValue));
                break;
            case 4:
                System.out.println(decimalToHex(decimalValue));
                break;
            default:
                System.out.println("Invalid target base!");
        }

        sc.close();
    }
}
