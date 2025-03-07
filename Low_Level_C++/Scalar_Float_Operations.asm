section .text
    global add_floats, sub_floats, mul_floats, div_floats

add_floats:
    addsd xmm0, xmm1
    addsd xmm0, xmm2
    addsd xmm0, xmm3
    ret

sub_floats:
    subsd xmm0, xmm1
    subsd xmm0, xmm2
    subsd xmm0, xmm3
    ret

mul_floats:
    mulsd xmm0, xmm1
    mulsd xmm0, xmm2
    mulsd xmm0, xmm3
    ret

div_floats:
    divsd xmm0, xmm1
    divsd xmm0, xmm2
    divsd xmm0, xmm3
    ret