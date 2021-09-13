# Copyright 2021 University of Adelaide
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from ASMParser import DefaultMode
import re

class ARMMode(DefaultMode):
    ret = re.compile(r"bx\s+lr|pop\s+{[r0-9, ]*pc}|pop\s+pc")
    call = re.compile(r"bl\s+([_a-zA-Z0-9]+)")
    jmp_b = re.compile(r"b\s+(\.[_a-zA-Z0-9]+)")
    jmp_ble = re.compile(r"ble\s+(\.[_a-zA-Z0-9]+)")
    jmp_bls = re.compile(r"bls\s+(\.[_a-zA-Z0-9]+)")
    jmp_bgt = re.compile(r"bgt\s+(\.[_a-zA-Z0-9]+)")
    jmp_bne = re.compile(r"bne\s+(\.[_a-zA-Z0-9]+)")
    jmp_beq = re.compile(r"beq\s+(\.[_a-zA-Z0-9]+)")
    jml_bhi = re.compile(r"bhi\s+(\.[_a-zA-Z0-9]+)")
    op = re.compile(r"[a-z]+\s+.*")
    jumps = [jmp_b, jmp_ble, jmp_bls, jmp_bne, jmp_bgt, jmp_beq, jml_bhi]
    oper = re.compile(r"(ldr|ldrb|str|strb|mov|movs|movb|ror|rors|lsls|lsl|lsrs|lsr|eors|eor|orr|orrs|bl|bx|push|pop|asrs|asr|and|ands|add|adds|sub|subs|bic|bics|cmp|b)")

    def strip_comments(self, line: str):
        return line.split("@")[0]
    def __str__(self):
        return "ARM"
    def get_state(self, line: str):
        res = self.op.match(line)
        if not res:
            return -1
        res = self.oper.match(line.split(' ')[0])
        if not res:
            raise NotImplementedError(line)
        res = res[1]
        if res in set(['str', 'strb']):
            return 0
        elif res in set(['ldr', 'ldrb']):
            return 1
        elif res in set(['bic','bics','eor','eors','mov','ror','rors','cmp','and','ands','muls','mul','lsl','lsls','lsr','lsrs','orr','orrs','add','adds','sub','subs']):
            return 2
        elif res in set(['movs']):
            return 3
        elif res in set(['push']):
            return 998
        elif res in set(['pop']):
            return 999
        elif res in set(['b','bl','blx']):
            return -1
        raise NotImplementedError("state unsupported for this inst {}".format(line))
    def get_op(self, line: str):
        res = self.oper.match(line.split(' ')[0])
        if res:
            return res[1]
        return None

