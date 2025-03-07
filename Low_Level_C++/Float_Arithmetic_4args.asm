section .text
    global add_floats

add_floats:
    addsd xmm0, xmm1
    addsd xmm0, xmm2
    addsd xmm0, xmm3
    ret