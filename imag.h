typedef struct cplx tipo_cplx;

tipo_cplx* cria_complexo(float real, float imag);
void libera_complexo(tipo_cplx *c);
void soma_complexo(tipo_cplx *c1, tipo_cplx *c2, tipo_cplx *soma);
void subt_complexo(tipo_cplx *c1, tipo_cplx *c2, tipo_cplx *subt);
void multip_complexo(tipo_cplx *c1, tipo_cplx *c2, tipo_cplx *mult);
void div_complexo(tipo_cplx *c1, tipo_cplx *c2, tipo_cplx *div);
void exibe_complexo(tipo_cplx *c);

