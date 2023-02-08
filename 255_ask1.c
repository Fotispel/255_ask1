#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

char *get_string() {
    char c, *str = NULL;
    int len = 0;

    printf("Enter a string: ");
    while ((c = getchar()) != '\n' && c != EOF) {
        str = (char*) realloc(str, sizeof(char) * (len + 1));
        str[len++] = c;
    }
    str = (char*) realloc(str, sizeof(char) * (len + 1));
    str[len] = '\0';
    return str;
}

void print_string(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        putchar(str[i]);
        i++;
    }
    printf("\n");
}

bool is_capital(char c) {
    printf("%d", c);
    return c == 'Α' || c == -74 || c == 'Β' || c == 'Γ' || c == 'Δ' || c == 'Ε' || c == 'Έ' || c == 'Ζ' || c == 'Η' || c == 'Ή' || c == 'Θ' || c == 'Ι' || c == 'Ί' || c == 'Κ' || c == 'Λ' || c == 'Μ' || c == 'Ν' || c == 'Ξ'
    || c == 'Ο' || c == 'Ό' || c == 'Π' || c == 'Ρ' || c == 'Σ' || c == 'Τ' || c == 'Υ' || c == 'Ύ' || c == 'Φ' || c == 'Χ' || c == 'Ψ' || c == 'Ω' || c == 'Ώ';
}

bool is_letter(char c) {
    return is_capital(c) || c == 'α' || c == 'ά' || c == 'β' || c == 'γ' || c == 'δ' || c == 'ε' || c == 'έ' || c == 'ζ' || c == 'η' || c == 'ή' || c == 'θ' || c == 'ι' || c == 'ί' || c == 'ϊ' || c == 'ΐ' || c == 'κ' || c == 'λ' || c == 'μ' || c == 'ν' 
    || c == 'ξ' || c == 'ο' || c == 'ό' || c == 'π' || c == 'ρ' || c == 'σ' || c == 'ς' || c == 'τ' || c == 'υ' || c == 'ύ' || c == 'ϋ' || c == 'ΰ' || c == 'φ' || c == 'χ' || c == 'ψ' || c == 'ω' || c == 'ώ';
}


char *convert_capital(char current_char, char next_char) {
    switch(current_char)
    {
        case 'Α':
            return "A";
        case -74:
            return "A'";
        case 'Β': 
            return "B";
        case 'Γ': 
            return "G";
        case 'Δ': 
            return "D";
        case 'Ε': 
            return "E";
        case 'Έ':
            return "E'";
        case 'Ζ':
            return "Z";
        case 'Η':
            return "H";
        case 'Ή':
            return "H'";
        case 'Θ':
            return "8";
        case 'Ι':
            return "I";
        case 'Ί':
            return "I'";
        case 'Κ':
            return "K";
        case 'Λ':
            return "L";
        case 'Μ':
            if (next_char != 'Π' && next_char != 'π')
                return "M";
            else
                return "B";
        case 'Ν':
            if (next_char != 'Τ' && next_char != 'τ')
                return "N";
            else
                return "D";
        case 'Ξ':
            return "KS";
        case 'Ο':
            return "O";
        case 'Ό':
            return "O'";
        case 'Π':
            return "P";
        case 'Ρ':
            return "R";
        case 'Σ':
            return "S";
        case 'Τ':
            return "T";
        case 'Υ':
            return "Y";
        case 'Ύ':
            return "Y'";
        case 'Φ':
            return "F";
        case 'Χ':
            return "X";
        case 'Ψ':
            return "PS";
        case 'Ω':
            return "W";
        case 'Ώ':
            return "W'";
        default:
            return "@";
    }
}char *convert_small_letter(char current_char,char next_char) {
    switch(current_char)
    {
        case 'α':
            return "a";
        case 'ά':
            return "a'";
        case 'β': 
            return "b";
        case 'γ': 
            return "g";
        case 'δ': 
            return "d";
        case 'ε': 
            return "e";
        case 'έ':
            return "e'";
        case 'ζ':
            return "z";
        case 'η':
            return "h";
        case 'ή':
            return "h'";
        case 'θ':
            return "8";
        case 'ι':
            return "i";
        case 'ί':
            return "i'";
        case 'ϊ':
            return "i\"";
        case 'ΐ':
            return "i'\"";
        case 'κ':
            return "k";
        case 'λ':
            return "l";
        case 'μ':
            if (next_char != 'π' && next_char != 'Π')
                return "m";
            else
                return "b";
        case 'ν':
            if (next_char != 'τ' && next_char != 'Τ')
                return "n";
            else
                return "d";
        case 'ξ':
            return "ks";
        case 'ο':
            return "o";
        case 'ό':
            return "o'";
        case 'π':
            return "p";
        case 'ρ':
            return "r";
        case 'σ':
            return "s";
        case 'ς':
            return "s";
        case 'τ':
            return "t";
        case 'υ':
            return "y";
        case 'ύ':
            return "y'";
        case 'ϋ':
            return "y\"";
        case 'ΰ':
            return "y'\"";
        case 'φ':
            return "f";
        case 'χ':
            return "x";
        case 'ψ':
            return "ps";
        case 'ω':
            return "w";
        case 'ώ':
            return "w'";
        default:
            return "!";
    }
}

char *conversion(char *str)
{
    int i;
    char* converted_str = NULL;
    converted_str = (char*)malloc(2 * strlen(str) * sizeof(char));
    for (i = 0; i < strlen(str); i++)
    {
        if (is_letter(str[i]) && is_capital(str[i]))
        {
                if (str[i+1]) strcat(converted_str, convert_capital(str[i], str[i+1]));
                else strcat(converted_str, convert_capital(str[i], ' '));

                if (str[i] == 'Μ' && (str[i+1] == 'Π' || str[i+1] == 'π')) i++;
                else if (str[i] == 'Ν' && (str[i+1] == 'Τ' || str[i+1] == 'τ')) i++;
        }
        if (is_letter(str[i]) && !is_capital(str[i]))
        {
            if (str[i+1]) strcat(converted_str, convert_small_letter(str[i], str[i+1]));
            else strcat(converted_str, convert_small_letter(str[i], ' '));

            if (str[i] == 'μ' && (str[i+1] == 'Π' || str[i+1] == 'π')) i++;
            else if (str[i] == 'ν' && (str[i+1] == 'Τ' || str[i+1] == 'τ')) i++;
        }

        if (!is_letter(str[i]))
        {
            strncat(converted_str, &str[i],1);
        }
    }
    return converted_str;
}


int main() {
    char *str = NULL;
    char *converted_str = NULL;

    str = get_string();
    printf("You entered: %s\n", str);

    converted_str = (char*) malloc(sizeof(char) * strlen(str));
    converted_str = conversion(str);

    printf("\nConverted string: ");
    print_string(converted_str);


    free(str);
    return 0;
}
