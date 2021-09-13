import struct
class statemap():
    def __init__(self, state):
        self.state = state
    def __getitem__(self, key):
        return self.state[key[0]*4 + key[1]]
    def __setitem__(self, key, value):
        self.state[key[0]*4 + key[1]] = value
    def __str__(self):
        rep = ""
        for i in range(0, 3):
            for j in range(0, 4):
                rep += hex(self.state[4*i + j]) + ","
            rep += "\n"
        return rep
def rotl(v, sh):
    shmask = (2**sh-1) << (32-sh)
    shmaskr = (2**(32-sh)-1)
    return ((v & shmask) >> (32 - sh))| ((v & shmaskr) << sh)
def runuptochi(a,b,c):
    va1=0
    va2=0
    vb1=0
    vb2=0
    vc1=0
    vc2=0
    a[0,0] ^= b[0,0] ^ c[0,0]
    a[0,1] ^= b[0,1] ^ c[0,1]
    a[0,2] ^= b[0,2] ^ c[0,2]
    a[0,3] ^= b[0,3] ^ c[0,3]
    a[1,0] ^= b[1,0] ^ c[1,0]
    a[1,1] ^= b[1,1] ^ c[1,1]
    a[1,2] ^= b[1,2] ^ c[1,2]
    a[1,3] ^= b[1,3] ^ c[1,3]
    a[2,0] ^= b[2,0] ^ c[2,0]
    a[2,1] ^= b[2,1] ^ c[2,1]
    a[2,2] ^= b[2,2] ^ c[2,2]
    a[2,3] ^= b[2,3] ^ c[2,3]

    va1 = a[0,3] ^ a[1,3] ^ a[2,3]
    va2 = a[0,0] ^ a[1,0] ^ a[2,0]
    va1 = rotl(va1, 5) ^ rotl(va1, 14)
#    va1 = (((va1) << 5) ^
#           ((va1) >> 27)) ^
#          (((va1) << 14) ^
#           ((va1) >> 18))
    a[0,0] ^= va1
    a[1,0] ^= va1
    a[2,0] ^= va1
    va1 = a[0,1] ^ a[1,1] ^ a[2,1]
    va2 = rotl(va2, 5) ^ rotl(va2, 14)
#    va2 = (((va2) << 5) ^
#           ((va2) >> 27)) ^
#          (((va2) << 14) ^
#           ((va2) >> 18))
    a[0,1] ^= va2
    a[1,1] ^= va2
    a[2,1] ^= va2
    va2 = a[0,2] ^ a[1,2] ^ a[2,2]
    va1 = rotl(va1, 5) ^ rotl(va1, 14)
#    va1 = (((va1) << 5) ^
#           ((va1) >> 27)) ^
#          (((va1) << 14) ^
#           ((va1) >> 18))
    a[0,2] ^= va1
    a[1,2] ^= va1
    a[2,2] ^= va1
    va2 = rotl(va2, 5) ^ rotl(va2, 14)
#    va2 = (((va2) << 5) ^
#           ((va2) >> 27)) ^
#          (((va2) << 14) ^
#           ((va2) >> 18))
    a[0,3] ^= va2
    a[1,3] ^= va2
    a[2,3] ^= va2
    vb1 = b[0,3] ^ b[1,3] ^ b[2,3]
    vb2 = b[0,0] ^ b[1,0] ^ b[2,0]
    vb1 = rotl(vb1, 5) ^ rotl(vb1, 14)
#    vb1 = (((vb1) << 5) ^
#           ((vb1) >> 27)) ^
#          (((vb1) << 14) ^
#           ((vb1) >> 18))
    b[0,0] ^= vb1
    b[1,0] ^= vb1
    b[2,0] ^= vb1
    vb1 = b[0,1] ^ b[1,1] ^ b[2,1]
    vb2 = rotl(vb2, 5) ^ rotl(vb2, 14)
#    vb2 = (((vb2) << 5) ^
#           ((vb2) >> 27)) ^
#          (((vb2) << 14) ^
#           ((vb2) >> 18))
    b[0,1] ^= vb2
    b[1,1] ^= vb2
    b[2,1] ^= vb2
    vb2 = b[0,2] ^ b[1,2] ^ b[2,2]
    vb1 = rotl(vb1, 5) ^ rotl(vb1, 14)
#    vb1 = (((vb1) << 5) ^
#           ((vb1) >> 27)) ^
#          (((vb1) << 14) ^
#           ((vb1) >> 18))
    b[0,2] ^= vb1
    b[1,2] ^= vb1
    b[2,2] ^= vb1
    vb2 = rotl(vb2, 5) ^ rotl(vb2, 14)
#    vb2 = (((vb2) << 5) ^
#           ((vb2) >> 27)) ^
#          (((vb2) << 14) ^
#           ((vb2) >> 18))
    b[0,3] ^= vb2
    b[1,3] ^= vb2
    b[2,3] ^= vb2
    vc1 = c[0,3] ^ c[1,3] ^ c[2,3]
    vc2 = c[0,0] ^ c[1,0] ^ c[2,0]
    vc1 = rotl(vc1, 5) ^ rotl(vc1, 14)
#    vc1 = (((vc1) << 5) ^
#           ((vc1) >> 27)) ^
#          (((vc1) << 14) ^
#           ((vc1) >> 18))
    c[0,0] ^= vc1
    c[1,0] ^= vc1
    c[2,0] ^= vc1
    vc1 = c[0,1] ^ c[1,1] ^ c[2,1]
    vc2 = rotl(vc2, 5) ^ rotl(vc2, 14)
#    vc2 = (((vc2) << 5) ^
#           ((vc2) >> 27)) ^
#          (((vc2) << 14) ^
#           ((vc2) >> 18))
    c[0,1] ^= vc2
    c[1,1] ^= vc2
    c[2,1] ^= vc2
    vc2 = c[0,2] ^ c[1,2] ^ c[2,2]
    vc1 = rotl(vc1, 5) ^ rotl(vc1, 14)
#    vc1 = (((vc1) << 5) ^
#           ((vc1) >> 27)) ^
#          (((vc1) << 14) ^
#           ((vc1) >> 18))
    c[0,2] ^= vc1
    c[1,2] ^= vc1
    c[2,2] ^= vc1
    vc2 = rotl(vc2, 5) ^ rotl(vc2, 14)
#    vc2 = (((vc2) << 5) ^
#           ((vc2) >> 27)) ^
#          (((vc2) << 14) ^
#           ((vc2) >> 18))
    c[0,3] ^= vc2
    c[1,3] ^= vc2
    c[2,3] ^= vc2
    
    a[2,0] = rotl(a[2,0], 11)
#    a[2,0] = (((a[2,0]) << 11) ^
#           ((a[2,0]) >> 21))
    a[2,1] = rotl(a[2,1], 11)
#    a[2,1] = (((a[2,1]) << 11) ^
#           ((a[2,1]) >> 21))
    a[2,2] = rotl(a[2,2], 11)
#    a[2,2] = (((a[2,2]) << 11) ^
#           ((a[2,2]) >> 21))
    a[2,3] = rotl(a[2,3], 11)
#    a[2,3] = (((a[2,3]) << 11) ^
#           ((a[2,3]) >> 21))
    va1 = a[1,3]
    a[1,3] = a[1,2]
    a[1,2] = a[1,1]
    a[1,1] = a[1,0]
    a[1,0] = va1
    b[2,0] = rotl(b[2,0], 11)
#    b[2,0] = (((b[2,0]) << 11) ^
#           ((b[2,0]) >> 21))
    b[2,1] = rotl(b[2,1], 11)
#    b[2,1] = (((b[2,1]) << 11) ^
#           ((b[2,1]) >> 21))
    b[2,2] = rotl(b[2,2], 11)
#    b[2,2] = (((b[2,2]) << 11) ^
#           ((b[2,2]) >> 21))
    b[2,3] = rotl(b[2,3], 11)
#    b[2,3] = (((b[2,3]) << 11) ^
#           ((b[2,3]) >> 21))
    vb1 = b[1,3]
    b[1,3] = b[1,2]
    b[1,2] = b[1,1]
    b[1,1] = b[1,0]
    b[1,0] = vb1
    c[2,0] = rotl(c[2,0], 11)
#    c[2,0] = (((c[2,0]) << 11) ^
#           ((c[2,0]) >> 21))
    c[2,1] = rotl(c[2,1], 11)
#    c[2,1] = (((c[2,1]) << 11) ^
#           ((c[2,1]) >> 21))
    c[2,2] = rotl(c[2,2], 11)
#    c[2,2] = (((c[2,2]) << 11) ^
#           ((c[2,2]) >> 21))
    c[2,3] = rotl(c[2,3], 11)
#    c[2,3] = (((c[2,3]) << 11) ^
#           ((c[2,3]) >> 21))
    vc1 = c[1,3]
    c[1,3] = c[1,2]
    c[1,2] = c[1,1]
    c[1,1] = c[1,0]
    c[1,0] = vc1
    
    a[0,0] ^= 0x00000058
    return 


def init_state(state):
    state[0] = 0xa144f6af;
    state[1] = 0x0a09bef3;                                                                                                     
    state[2] = 0xf69b27da;
    state[3] = 0xebf1aa2f;
    state[4] = 0x79ec427d;
    state[5] = 0x394b82c3;
    state[6] = 0x15d52030;
    state[7] = 0xe3d85ac4;
    state[8] = 0x661b20a0; 
    state[9] = 0x01fc8349; 
    state[10] = 0x76868f25;
    state[11] = 0x98fcda2a;

def state_absorb(state, inp8):
    for i in range(0, 4):
        state[i]=state[i] ^ struct.unpack("I",inp8[4*i:4*i+4])[0]
def init_masks(masks, inp8):
    for i in range(0, 12):
        masks[i]=struct.unpack("I",inp8[4*i:4*i+4])[0]
def share(inp8, masks8):
    state = [0] * 12
    statemasks = [0] * 12

    init_state(state)
    state_absorb(state, inp8[0:16])
    masks0 = [0] * 12
    init_masks(masks0, masks8[0:48])
    masks1 = [0] * 12
    init_masks(masks1, masks8[48:96])


    a=statemap(state)
    b=statemap(masks0)
    c=statemap(masks1)
    runuptochi(a,b,c)
    
    return a,b,c 

a,b,c = share(bytes.fromhex('33445566225588993344556622558899'),bytes.fromhex('00'*96))
print(a)

    
