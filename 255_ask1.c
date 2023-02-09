#include <stdio.h>

/* Edo einai ta ascii ton grammaton pou tha
 * xrisimopoiisoume stis katastaseis, oi opoies einai
 * gia tis periptoseis
 * nt -> d
 * mp -> b
 * kai gia otidipote allo (stis parapano periptoseis iparxoyn kai diaforoi
 * sindiasmoi kefalaion kai pezon)
 * Ta Ascii ta brika me printf("\n%d\n", c); opou c to xaraktira pou theloume
 * */

#define tonos 39
#define dialitika 34

#define M_GR 204
#define m_GR 236
#define N_GR 205
#define n_GR 237

#define T_GR 212
#define t_GR 244

#define P_GR 208
#define p_GR 240

#define B_ENG 66
#define b_ENG 98

#define D_ENG 68
#define d_ENG 100


enum state {
    state_anything_else, state_M, state_N, state_m, state_n
};

void fill_array(char array_with_characters[256][3]) { /*arxikopoiisi pinaka metafrasis */
    int i, j;
    char smalls[] = "avgdezh8iklmn-oprsstyfx-w";    /*ta antistoixa peza ellinika se agglika*/
    char capitals[] = "AVGDEZH8IKLMN-OPR-STYFX-W";  /*ta antistoixa kefalaia ellinika se agglika*/

    for (i = 0; i < 256; i++) {
        array_with_characters[i][0] = i;
        array_with_characters[i][1] = '\0';
        array_with_characters[i][2] = '\0';
    }

    /*peza (ta peza ellinika sto Ascii einai apo 225 mexri to 249)*/
    j = 0;
    for (i = 225; i <= 249; i++) {
        array_with_characters[i][0] = smalls[j];
        j++;
    }

    /*kefalaia (ta kefalaia ellinika sto Ascii einai apo 193 mexri to 217)*/
    j = 0;
    for (i = 193; i <= 217; i++) {
        array_with_characters[i][0] = capitals[j];
        j++;
    }

    /*peza me tonous*/
    array_with_characters[220][0] = 'a';
    array_with_characters[220][1] = tonos;
    array_with_characters[221][0] = 'e';
    array_with_characters[221][1] = tonos;
    array_with_characters[222][0] = 'h';
    array_with_characters[222][1] = tonos;
    array_with_characters[223][0] = 'i';
    array_with_characters[223][1] = tonos;
    array_with_characters[252][0] = 'o';
    array_with_characters[252][1] = tonos;
    array_with_characters[253][0] = 'u';
    array_with_characters[253][1] = tonos;
    array_with_characters[254][0] = 'w';
    array_with_characters[254][1] = tonos;

    /*kefalaia me tonous*/
    array_with_characters[182][0] = tonos;
    array_with_characters[182][1] = 'A';
    array_with_characters[184][0] = tonos;
    array_with_characters[184][1] = 'E';
    array_with_characters[185][0] = tonos;
    array_with_characters[185][1] = 'H';
    array_with_characters[186][0] = tonos;
    array_with_characters[186][1] = 'I';
    array_with_characters[188][0] = tonos;
    array_with_characters[188][1] = 'O';
    array_with_characters[190][0] = tonos;
    array_with_characters[190][1] = 'Y';
    array_with_characters[191][0] = tonos;
    array_with_characters[191][1] = 'W';

    /*grammata me dialitika*/
    array_with_characters[218][0] = 'I';
    array_with_characters[218][1] = dialitika;
    array_with_characters[219][0] = 'Y';
    array_with_characters[219][1] = dialitika;
    array_with_characters[250][0] = 'i';
    array_with_characters[250][1] = dialitika;
    array_with_characters[251][0] = 'u';
    array_with_characters[251][1] = dialitika;
    array_with_characters[192][0] = 'i';
    array_with_characters[192][1] = tonos;
    array_with_characters[192][2] = dialitika;
    array_with_characters[224][0] = 'u';
    array_with_characters[224][1] = tonos;
    array_with_characters[224][2] = dialitika;

    /*sindiasmoi grammaton*/
    array_with_characters[238][0] = 'k';
    array_with_characters[238][1] = 's'; /*einai gia to ks*/

    array_with_characters[248][0] = 'p';
    array_with_characters[248][1] = 's'; /*einai gia to ps*/

    array_with_characters[206][0] = 'K';
    array_with_characters[206][1] = 'S'; /*einai gia to KS*/

    array_with_characters[216][0] = 'P';
    array_with_characters[216][1] = 'S'; /*einai gia to PS*/
}

void print_element_from_array(int c) {  /*ektiposi xaraktira apo ton pinaka metafrasis*/
    char array_with_characters[256][3]; /*pinakas metafrasis 256 theseon logo tou ASCII kai 3 theseis dioti
                                        * stin xeiroteri periptosi na einai px to a'" pou einai 3 theseon*/

    fill_array(array_with_characters);  /*kaloume tin fill_array gia na gemisoume ton pinaka metafrasis*/

    if (array_with_characters[c][0] != '\0')    /*an i prwti thesei tou pinaka metafrasis den einai keni tote ektipwnoume*/
        putchar(array_with_characters[c][0]);

    if (array_with_characters[c][1] != '\0')    /*an i deuteri thesei tou pinaka metafrasis den einai keni tote ektipwnoume*/
        putchar(array_with_characters[c][1]);

    if (array_with_characters[c][2] != '\0')    /*an i triti thesei tou pinaka metafrasis den einai keni tote ektipwnoume*/
        putchar(array_with_characters[c][2]);
}

enum state current_letter_is_anything_else(int c) { /*an exoume opoiodipote xaraktira ektos m kai n*/
    switch (c) {
        case M_GR:
            return state_M; /*an einai M tote epistrefoume katastasi M*/
        case m_GR:
            return state_m; /*an einai m tote epistrefoume katastasi m*/
        case N_GR:
            return state_N; /*an einai N tote epistrefoume katastasi N*/
        case n_GR:
            return state_n; /*an einai n tote epistrefoume katastasi n*/
        default:
            print_element_from_array(c); /*an den einai kapoia apo tis periptwseis tote typwnoume ton xaraktira*/
            return state_anything_else;
    }
}

enum state current_letter_is_M(int c) { /*periptwsi katastasis M*/
    switch (c) {
        case P_GR:  /*an einai P tote to MP ginetai B kai pame stin katastasi anything_else*/
            print_element_from_array(B_ENG);
            return state_anything_else;
        case p_GR:  /*an einai p tote to mp ginetai b kai pame stin katastasi anything_else*/
            print_element_from_array(B_ENG);
            return state_anything_else;
        case M_GR:  /*an einai M tote to MM ginetai M kai pame stin katastasi M*/
            print_element_from_array(M_GR);
            return state_M;
        case m_GR:  /*an einai m tote exoume to mm kai ektiponoume to m kai pame stin katastasi m*/
            print_element_from_array(M_GR);
            return state_m;
        case N_GR:  /*an einai N tote exoume to MN kai ektiponoume to M kai pame stin katastasi N*/
            print_element_from_array(M_GR);
            return state_N;
        case n_GR:  /*an einai n tote exoume to mn kai ektiponoume to M kai pame stin katastasi n*/
            print_element_from_array(M_GR);
            return state_n;
        default:    /*an den einai kapoia apo tis periptwseis tote typwnoume to M kai pame stin katastasi anything_else*/
            print_element_from_array(M_GR);
            print_element_from_array(c);
            return state_anything_else;
    }
}


enum state current_letter_is_N(int c) { /*periptwsi katastasis N*/
    switch (c) {
        case T_GR:  /*an einai T tote to NT ginetai D kai pame stin katastasi anything_else*/
            print_element_from_array(D_ENG);
            return state_anything_else;
        case t_GR:  /*an einai t tote to nt ginetai d kai pame stin katastasi anything_else*/
            print_element_from_array(D_ENG);
            return state_anything_else;
        case N_GR:  /*an einai N tote exoume to NN kai ektiponoume to N kai pame stin katastasi N*/
            print_element_from_array(N_GR);
            return state_N;
        case n_GR:  /*an einai n tote exoume to nn kai ektiponoume to N kai pame stin katastasi n*/
            print_element_from_array(N_GR);
            return state_n;
        case M_GR:  /*an einai M tote exoume to MN kai ektiponoume to N kai pame stin katastasi M*/
            print_element_from_array(N_GR);
            return state_M;
        case m_GR:  /*an einai m tote exoume to mn kai ektiponoume to N kai pame stin katastasi m*/
            print_element_from_array(N_GR);
            return state_m;
        default:    /*an den einai kapoia apo tis periptwseis tote typwnoume to N kai pame stin katastasi anything_else*/
            print_element_from_array(N_GR);
            print_element_from_array(c);
            return state_anything_else;
    }
}


enum state current_letter_is_m(int c) { /*periptwsi katastasis m*/
    switch (c) {
        case P_GR:  /*an einai P tote to mp ginetai b kai pame stin katastasi anything_else*/
            print_element_from_array(b_ENG);
            return state_anything_else;
        case p_GR:  /*an einai p tote to mp ginetai b kai pame stin katastasi anything_else*/
            print_element_from_array(b_ENG);
            return state_anything_else;
        case M_GR:  /*an einai M tote exoume to mm kai ektiponoume to m kai pame stin katastasi M*/
            print_element_from_array(m_GR);
            return state_M;
        case m_GR:  /*an einai m tote exoume to mm kai ektiponoume to m kai pame stin katastasi m*/
            print_element_from_array(m_GR);
            return state_m;
        case N_GR:  /*an einai N tote exoume to mn kai ektiponoume to m kai pame stin katastasi N*/
            print_element_from_array(m_GR);
            return state_N;
        case n_GR:  /*an einai n tote exoume to mn kai ektiponoume to m kai pame stin katastasi n*/
            print_element_from_array(m_GR);
            return state_n;
        default:    /*an den einai kapoia apo tis periptwseis tote typwnoume to m kai pame stin katastasi anything_else*/
            print_element_from_array(m_GR);
            print_element_from_array(c);
            return state_anything_else;
    }
}

enum state current_letter_is_n(int c) { /*periptwsi katastasis n*/
    switch (c) {
        case T_GR:  /*an einai T tote to nt ginetai d kai pame stin katastasi anything_else*/
            print_element_from_array(d_ENG);
            return state_anything_else;
        case t_GR:  /*an einai t tote to nt ginetai d kai pame stin katastasi anything_else*/
            print_element_from_array(d_ENG);
            return state_anything_else;
        case M_GR:  /*an einai M tote exoume to mn kai ektiponoume to n kai pame stin katastasi M*/
            print_element_from_array(n_GR);
            return state_M;
        case m_GR:  /*an einai m tote exoume to mn kai ektiponoume to n kai pame stin katastasi m*/
            print_element_from_array(n_GR);
            return state_m;
        case N_GR:  /*an einai N tote exoume to nn kai ektiponoume to n kai pame stin katastasi N*/
            print_element_from_array(n_GR);
            return state_N;
        case n_GR:  /*an einai n tote exoume to nn kai ektiponoume to n kai pame stin katastasi n*/
            print_element_from_array(n_GR);
            return state_n;
        default:    /*an den einai kapoia apo tis periptwseis tote typwnoume to n kai pame stin katastasi anything_else*/
            print_element_from_array(n_GR);
            print_element_from_array(c);
            return state_anything_else;
    }
}

int main() {
    int c;
    enum state current_state = state_anything_else;

    enum state (*transition[])(int c) = {current_letter_is_anything_else, current_letter_is_M, current_letter_is_N,
                                     current_letter_is_m, current_letter_is_n};

    while ((c = getchar()) != EOF) {
        current_state = (transition[current_state])(c);
    }

    return 0;
}
