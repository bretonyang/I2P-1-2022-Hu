
unsigned ***new_3d_array(unsigned n, unsigned m, unsigned k)
{
    unsigned ***arr = (unsigned ***) malloc(n * sizeof(unsigned **) +
                                            n * m * sizeof(unsigned *) +
                                            n * m * k * sizeof(unsigned));

    // Our goal:
    // first n bytes: an array of unsigned[m][k] arrays (or n unsigned**).
    // next n*m bytes: an array of unsigned[k] arrays (or n*m unsigned*).
    // next n*m*k bytes: an array of k unsigned elements (or n*m*k unsigned).
    unsigned ** pptr = (unsigned **) (arr + n);
    unsigned *ptr = (unsigned *) (arr + n + n*m);

    for (unsigned i = 0; i < n; i++) {
        // make arr[i] point to right place
        arr[i] = pptr + m*i;

        for (unsigned j = 0; j < m; j++) {
            // make arr[i][j] point to right place
            arr[i][j] = ptr + m*k*i + k*j;
        }
    }

    return arr;
}

void delete_3d_array(unsigned ***arr)
{
    free(arr);
}

