#include<stdio.h>

// Function to convert decimal integer to binary string
char* decimalToBinary(int num) {
    char* binary = (char*)malloc(sizeof(char) * 33);
    binary[32] = '\0';
    int i = 31;
    while (i >= 0) {
        binary[i] = (num % 2) + '0';
        num = num / 2;
        i--;
    }
    return binary;
}

char* reduceBinary(char* binary) {
    int length = strlen(binary);
    int start = 0;
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            start = i;
            break;
        }
    }
    return binary + start;
}

// Function to convert decimal integer to octal string
char* decimalToOctal(int num) {
    char* octal = (char*)malloc(sizeof(char) * 12);
    int i = 0;
    while (num != 0) {
        int remainder = num % 8;
        octal[i] = remainder + '0';
        i++;
        num = num / 8;
    }
    octal[i] = '\0';
    // Reverse the string
    int len = i;
    for (int j = 0; j < len / 2; j++) {
        char temp = octal[j];
        octal[j] = octal[len - j - 1];
        octal[len - j - 1] = temp;
    }
    return octal;
}

// Function to convert decimal integer to hexadecimal string
char* decimalToHexa(int num) {
    char* hexa = (char*)malloc(sizeof(char) * 100); // allocate memory for the string
    int i = 0;
    while (num != 0) {
        int remainder = num % 16;
        if (remainder < 10) {
            hexa[i] = remainder + 48;
        } else {
            hexa[i] = remainder + 55;
        }
        i++;
        num = num / 16;
    }
    hexa[i] = '\0';
    // Reverse the string
    int len = strlen(hexa);
    for (int j = 0; j < len / 2; j++) {
        char temp = hexa[j];
        hexa[j] = hexa[len - j - 1];
        hexa[len - j - 1] = temp;
    }
    return hexa;
}

// Function to convert binary string to decimal integer
int binaryToDecimal(int binary) {
    int decimal = 0;
    int power = 0;
    while (binary > 0) {
        int digit = binary % 10;
        decimal += digit * pow(2, power);
        binary /= 10;
        power++;
    }
    return decimal;
}

// Function to convert octal string to decimal integer
int octalToDecimal(int octal) {
    int decimal = 0;
    int power = 0;
    while (octal > 0) {
        int digit = octal % 10;
        decimal += digit * pow(8, power);
        octal /= 10;
        power++;
    }
    return decimal;
}
// Function to convert hexadecimal string to decimal integer
int hexaToDecimal(char *hex) {
    int decimal = 0;
    int length = strlen(hex);
    for (int i = 0; i < length; i++) {
        int digit = 0;
        if (hex[i] >= '0' && hex[i] <= '9') {
            digit = hex[i] - '0';
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            digit = hex[i] - 'a' + 10;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            digit = hex[i] - 'A' + 10;
        }
        decimal += digit * pow(16, length - i - 1);
    }
    return decimal;
}

int isBinary(int num) {
    while (num != 0) {
        if (num % 10 > 1) {
            return 0;
        }
        num /= 10;
    }
    return 1;
}

int isOctal(int num) {
    while (num != 0) {
        int digit = num % 10;
        if (digit >= 8) {
            return 0;
        }
        num /= 10;
    }
    return 1;
}

int isHexadecimal(char *str) {
    int i = 0;

    // Check if the string starts with "0x" or "0X"
    if (str[i] == '0' && (str[i+1] == 'x' || str[i+1] == 'X')) {
        i += 2;
    }

    // Check each character in the string
    for (; str[i] != '\0'; i++) {
        if (!isxdigit(str[i])) {
            return 0;
        }
    }

    return 1;
}

void calculation(){
    int choice = 0;
    printf("\n\nSelect your desired calculation by serial number: \n\n");
    printf("=====================================================\n");
    printf("1. Decimal to Others\n");
    printf("2. Binary to Others\n");
    printf("3. Octal to Others\n");
    printf("4. Hexadecimal to Others\n\n");
    printf("==========================================\n");

    choice_T:
        scanf("%d", &choice);
    printf("==========================================\n\n");

        int input = 0;
        int decimal;
        char hexInput[20];
        char* binary;
        char* hexa ;
        char* octal;
        char* reduceB;
        switch(choice){
        case 1:
            decimalC:

                printf("\nEnter the Decimal Value:\n");
                scanf("%d", &input);
                if(input<=0){
                    printf("Please Enter valid Value:\n");
                    goto decimalC;
                } else{

                    binary = decimalToBinary(input);
                    reduceB = reduceBinary(binary);

                    hexa = decimalToHexa(input);
                    octal = decimalToOctal(input);

                    printf("\n==========Result==========\n");
                    printf("Binary: %s\n", reduceB);
                    printf("Octal: %s\n", octal);
                    printf("Hexadecimal: %s\n", hexa);

                    printf("\n\n==========Thank you==========\n\n");
                }
        break;
        case 2:
            binaryC:
                printf("Enter the Binary Value:\n");
                scanf("%d", &input);
                if(!isBinary(input)){
                    printf("Please Enter valid Value:\n");
                    goto binaryC;
                } else{
                    decimal = binaryToDecimal(input);

                    hexa = decimalToHexa(decimal);
                    octal = decimalToOctal(decimal);

                    printf("\n==========Result==========\n");
                    printf("Decimal: %d\n", decimal);
                    printf("Octal: %s\n", octal);
                    printf("Hexadecimal: %s\n", hexa);
                    printf("\n\n==========Thank you==========\n\n");
                }
        break;
        case 3:
            OctalC:
                printf("Enter the Octal Value:\n");
                scanf("%d", &input);
                if(!isOctal(input)){
                    printf("Please Enter valid Value:\n");
                    goto OctalC;
                } else{
                    decimal = octalToDecimal(input);

                    binary = decimalToBinary(decimal);
                    reduceB = reduceBinary(binary);

                    hexa = decimalToHexa(decimal);

                    printf("\n==========Result==========\n");
                    printf("Decimal: %d\n", decimal);
                    printf("Binary: %s\n", reduceB);
                    printf("Hexadecimal: %s\n",hexa);
                    printf("\n\n==========Thank you==========\n\n");
                }
        break;
        case 4:
            hexaC:
                printf("Enter the Hexadecimal Value:\n");
                scanf("%s", &hexInput);

                if(!isHexadecimal(hexInput)){
                    printf("Please Enter valid Value:\n");
                    goto hexaC;
                } else{
                    decimal = hexaToDecimal(hexInput);

                    binary = decimalToBinary(decimal);
                    reduceB = reduceBinary(binary);
                    octal = decimalToOctal(decimal);

                    printf("\n==========Result==========\n");
                    printf("Decimal: %d\n", decimal);
                    printf("Binary: %s\n", reduceB);
                    printf("Octal: %s\n", octal);
                    printf("\n\n==========Thank you==========\n\n");
                }
        break;
        default:
            printf("Please Enter valid choice\n\n\n");
            goto choice_T;
            break;
    }
}

int main(){

printf("==========================================\n");
printf("=======Welcome to Number Converter========\n");
printf("==========================================\n\n");
printf("================Powered By================\n");
printf("========Team Alpha of NUB ECSE 2A=========\n");
printf("===Hridoy, Hasin, Evan, Sumaiya, Tonima===\n");
printf("==========================================\n\n");

//Calculation Section
calculation:
    calculation();

//Ask For More Calculation Section
int more = 0;
ask_again:

    printf("Can you need more calculation?\nYes = 1\nNo = 0\n");
    scanf("%d", &more);
    if (more == 1){
        goto calculation;
    } else if (more != 0){
        printf("Wrong Input: \n");
        goto ask_again;
    }


return 0;
}
