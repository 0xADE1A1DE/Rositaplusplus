import sys

asm_tmpl="""@ ---- {section}
    ldr r5, [r1, #{off_x20}] @ b20
    ldr r3, [r0, #{off_x10}] @ a10
    ldr r4, [r0, #{off_x20}] @ a20
    ldr r6, [r1, #{off_x10}] @ b10
    mov r8, r5
    mov r9, r6
    ands r5, r3 @ a10 & b20
    ands r6, r4 @ b10 & a20
    bics r4, r3 @ ~a10 & a20
    ldr r3, [r0, #{off_x00}] @ a00
    eors r4, r3
    eors r4, r5
    eors r4, r6
    str r4, [r0, #{off_x00}]

    ldr r5, [r2, #{off_x20}] @ c20
    ldr r6, [r2, #{off_x10}] @ c10
    mov r3, r8 @ b20
    mov r4, r9 @ b10
    mov r8, r5
    mov r9, r6
    ands r6, r3 @ c10 & b20
    ands r5, r4 @ b10 & c20
    bics r3, r4 @ ~b10 & b20
    ldr r4, [r1, #{off_x00}] @ b00
    eors r3, r4
    eors r3, r5
    eors r3, r6
    str r3, [r1, #{off_x00}]

    ldr r5, [r0, #{off_x20}] @ a20
    ldr r6, [r0, #{off_x10}] @ a10
    mov r3, r8 @ c20
    mov r4, r9 @ c10
    mov r8, r5
    mov r9, r6
    ands r6, r3 @ a10 & c20
    ands r5, r4 @ c10 & a20
    bics r3, r4 @ ~c10 & c20
    ldr r4, [r2, #{off_x00}] @ c00
    eors r3, r4
    eors r3, r5
    eors r3, r6
    str r3, [r2, #{off_x00}]"""
def sec(r,c):

    r_1 = (r+1) % 3
    r_2 = (r+2) % 3
    sec = "%s,%s"%(r, c)
    print(asm_tmpl.format(section=sec,off_x00=16*r + 4*c,
        off_x20=16*r_2 + 4*c,
        off_x10=16*r_1 + 4*c
        ))

for r in range(0, 3):
    for c in range(0, 4):
        sec(r,c)
