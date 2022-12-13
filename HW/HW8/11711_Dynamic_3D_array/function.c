
unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k)
{
    unsigned ***p_to_2d_arrays = (unsigned**) malloc(n*sizeof(unsigned**)
                                                    + n*m*sizeof(unsigned*)
                                                    + n*m*k*sizeof(unsigned));

    unsigned **p_to_1d_arrays = (unsigned**) (p_to_2d_arrays + n);
    unsigned *p_to_elements = (unsigned*) (p_to_1d_arrays + n*m);

    for (int i = 0; i < n; i++) {
        *(p_to_2d_arrays + i) = p_to_1d_arrays + m*i;

        for (int j = 0; j < m; j++) {
            *(*(p_to_2d_arrays + i) + j) = p_to_elements + m*k*i + k*j;
        }
    }

    return p_to_2d_arrays;
}

void delete_3d_array(unsigned ***arr)
{
    free(arr);
}
