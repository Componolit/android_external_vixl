// Copyright 2016, VIXL authors
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of ARM Limited nor the names of its contributors may be
//     used to endorse or promote products derived from this software without
//     specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


// -----------------------------------------------------------------------------
// This file is auto generated from the
// test/aarch32/config/template-assembler-aarch32.cc.in template file using
// tools/generate_tests.py.
//
// PLEASE DO NOT EDIT.
// -----------------------------------------------------------------------------


#include "test-runner.h"

#include "test-utils.h"
#include "test-utils-aarch32.h"

#include "aarch32/assembler-aarch32.h"
#include "aarch32/macro-assembler-aarch32.h"

#define BUF_SIZE (4096)

namespace vixl {
namespace aarch32 {

// List of instruction mnemonics.
#define FOREACH_INSTRUCTION(M) \
  M(cmn)                       \
  M(cmp)                       \
  M(mov)                       \
  M(movs)                      \
  M(mvn)                       \
  M(mvns)                      \
  M(teq)                       \
  M(tst)


// The following definitions are defined again in each generated test, therefore
// we need to place them in an anomymous namespace. It expresses that they are
// local to this file only, and the compiler is not allowed to share these types
// across test files during template instantiation. Specifically, `Operands` has
// various layouts across generated tests so it absolutely cannot be shared.

namespace {

// Values to be passed to the assembler to produce the instruction under test.
struct Operands {
  Condition cond;
  Register rd;
  Register rn;
  ShiftType shift;
  uint32_t amount;
};

// This structure contains all data needed to test one specific
// instruction.
struct TestData {
  // The `operands` field represents what to pass to the assembler to
  // produce the instruction.
  Operands operands;
  // True if we need to generate an IT instruction for this test to be valid.
  bool in_it_block;
  // The condition to give the IT instruction, this will be set to "al" by
  // default.
  Condition it_condition;
  // Description of the operands, used for error reporting.
  const char* operands_description;
  // Unique identifier, used for generating traces.
  const char* identifier;
};

struct TestResult {
  size_t size;
  const byte* encoding;
};

// Each element of this array produce one instruction encoding.
const TestData kTests[] = {
    {{eq, r10, r13, LSR, 23},
     false,
     al,
     "eq r10 r13 LSR 23",
     "eq_r10_r13_LSR_23"},
    {{eq, r12, r13, LSR, 13},
     false,
     al,
     "eq r12 r13 LSR 13",
     "eq_r12_r13_LSR_13"},
    {{pl, r13, r5, LSR, 12}, false, al, "pl r13 r5 LSR 12", "pl_r13_r5_LSR_12"},
    {{vc, r8, r11, ASR, 13}, false, al, "vc r8 r11 ASR 13", "vc_r8_r11_ASR_13"},
    {{al, r9, r12, ASR, 1}, false, al, "al r9 r12 ASR 1", "al_r9_r12_ASR_1"},
    {{vs, r10, r3, ASR, 31}, false, al, "vs r10 r3 ASR 31", "vs_r10_r3_ASR_31"},
    {{pl, r2, r11, ASR, 14}, false, al, "pl r2 r11 ASR 14", "pl_r2_r11_ASR_14"},
    {{al, r11, r10, LSR, 27},
     false,
     al,
     "al r11 r10 LSR 27",
     "al_r11_r10_LSR_27"},
    {{le, r10, r8, LSR, 19}, false, al, "le r10 r8 LSR 19", "le_r10_r8_LSR_19"},
    {{vc, r6, r2, ASR, 9}, false, al, "vc r6 r2 ASR 9", "vc_r6_r2_ASR_9"},
    {{al, r10, r10, ASR, 7}, false, al, "al r10 r10 ASR 7", "al_r10_r10_ASR_7"},
    {{pl, r4, r6, LSR, 3}, false, al, "pl r4 r6 LSR 3", "pl_r4_r6_LSR_3"},
    {{vs, r0, r6, ASR, 19}, false, al, "vs r0 r6 ASR 19", "vs_r0_r6_ASR_19"},
    {{vc, r5, r8, LSR, 5}, false, al, "vc r5 r8 LSR 5", "vc_r5_r8_LSR_5"},
    {{ne, r2, r9, LSR, 26}, false, al, "ne r2 r9 LSR 26", "ne_r2_r9_LSR_26"},
    {{lt, r14, r0, LSR, 12}, false, al, "lt r14 r0 LSR 12", "lt_r14_r0_LSR_12"},
    {{hi, r8, r1, ASR, 15}, false, al, "hi r8 r1 ASR 15", "hi_r8_r1_ASR_15"},
    {{vc, r9, r13, LSR, 16}, false, al, "vc r9 r13 LSR 16", "vc_r9_r13_LSR_16"},
    {{lt, r4, r11, LSR, 26}, false, al, "lt r4 r11 LSR 26", "lt_r4_r11_LSR_26"},
    {{vs, r2, r2, ASR, 7}, false, al, "vs r2 r2 ASR 7", "vs_r2_r2_ASR_7"},
    {{pl, r8, r8, ASR, 4}, false, al, "pl r8 r8 ASR 4", "pl_r8_r8_ASR_4"},
    {{al, r10, r11, ASR, 31},
     false,
     al,
     "al r10 r11 ASR 31",
     "al_r10_r11_ASR_31"},
    {{cs, r14, r11, ASR, 3}, false, al, "cs r14 r11 ASR 3", "cs_r14_r11_ASR_3"},
    {{vs, r0, r11, LSR, 30}, false, al, "vs r0 r11 LSR 30", "vs_r0_r11_LSR_30"},
    {{pl, r6, r13, LSR, 18}, false, al, "pl r6 r13 LSR 18", "pl_r6_r13_LSR_18"},
    {{pl, r14, r2, ASR, 32}, false, al, "pl r14 r2 ASR 32", "pl_r14_r2_ASR_32"},
    {{ls, r11, r6, ASR, 23}, false, al, "ls r11 r6 ASR 23", "ls_r11_r6_ASR_23"},
    {{cc, r11, r2, ASR, 2}, false, al, "cc r11 r2 ASR 2", "cc_r11_r2_ASR_2"},
    {{le, r12, r5, ASR, 27}, false, al, "le r12 r5 ASR 27", "le_r12_r5_ASR_27"},
    {{ge, r2, r5, ASR, 31}, false, al, "ge r2 r5 ASR 31", "ge_r2_r5_ASR_31"},
    {{le, r0, r5, ASR, 7}, false, al, "le r0 r5 ASR 7", "le_r0_r5_ASR_7"},
    {{ge, r1, r10, ASR, 28}, false, al, "ge r1 r10 ASR 28", "ge_r1_r10_ASR_28"},
    {{vc, r6, r0, LSR, 13}, false, al, "vc r6 r0 LSR 13", "vc_r6_r0_LSR_13"},
    {{eq, r13, r2, ASR, 4}, false, al, "eq r13 r2 ASR 4", "eq_r13_r2_ASR_4"},
    {{pl, r10, r12, ASR, 20},
     false,
     al,
     "pl r10 r12 ASR 20",
     "pl_r10_r12_ASR_20"},
    {{gt, r2, r0, ASR, 32}, false, al, "gt r2 r0 ASR 32", "gt_r2_r0_ASR_32"},
    {{hi, r10, r5, LSR, 9}, false, al, "hi r10 r5 LSR 9", "hi_r10_r5_LSR_9"},
    {{ge, r12, r1, ASR, 27}, false, al, "ge r12 r1 ASR 27", "ge_r12_r1_ASR_27"},
    {{eq, r5, r5, LSR, 17}, false, al, "eq r5 r5 LSR 17", "eq_r5_r5_LSR_17"},
    {{pl, r10, r0, LSR, 2}, false, al, "pl r10 r0 LSR 2", "pl_r10_r0_LSR_2"},
    {{mi, r6, r3, ASR, 24}, false, al, "mi r6 r3 ASR 24", "mi_r6_r3_ASR_24"},
    {{eq, r1, r7, LSR, 1}, false, al, "eq r1 r7 LSR 1", "eq_r1_r7_LSR_1"},
    {{eq, r13, r14, ASR, 24},
     false,
     al,
     "eq r13 r14 ASR 24",
     "eq_r13_r14_ASR_24"},
    {{pl, r0, r5, ASR, 12}, false, al, "pl r0 r5 ASR 12", "pl_r0_r5_ASR_12"},
    {{gt, r2, r14, ASR, 17}, false, al, "gt r2 r14 ASR 17", "gt_r2_r14_ASR_17"},
    {{cs, r14, r0, LSR, 15}, false, al, "cs r14 r0 LSR 15", "cs_r14_r0_LSR_15"},
    {{ls, r14, r3, LSR, 18}, false, al, "ls r14 r3 LSR 18", "ls_r14_r3_LSR_18"},
    {{le, r0, r13, ASR, 29}, false, al, "le r0 r13 ASR 29", "le_r0_r13_ASR_29"},
    {{ge, r5, r14, ASR, 17}, false, al, "ge r5 r14 ASR 17", "ge_r5_r14_ASR_17"},
    {{vc, r7, r1, ASR, 12}, false, al, "vc r7 r1 ASR 12", "vc_r7_r1_ASR_12"},
    {{ne, r1, r5, ASR, 23}, false, al, "ne r1 r5 ASR 23", "ne_r1_r5_ASR_23"},
    {{ls, r5, r2, LSR, 15}, false, al, "ls r5 r2 LSR 15", "ls_r5_r2_LSR_15"},
    {{le, r12, r7, ASR, 18}, false, al, "le r12 r7 ASR 18", "le_r12_r7_ASR_18"},
    {{hi, r11, r8, ASR, 8}, false, al, "hi r11 r8 ASR 8", "hi_r11_r8_ASR_8"},
    {{pl, r9, r0, LSR, 16}, false, al, "pl r9 r0 LSR 16", "pl_r9_r0_LSR_16"},
    {{ls, r13, r4, LSR, 18}, false, al, "ls r13 r4 LSR 18", "ls_r13_r4_LSR_18"},
    {{ls, r4, r6, ASR, 7}, false, al, "ls r4 r6 ASR 7", "ls_r4_r6_ASR_7"},
    {{gt, r1, r7, LSR, 1}, false, al, "gt r1 r7 LSR 1", "gt_r1_r7_LSR_1"},
    {{eq, r7, r11, LSR, 24}, false, al, "eq r7 r11 LSR 24", "eq_r7_r11_LSR_24"},
    {{al, r8, r10, LSR, 7}, false, al, "al r8 r10 LSR 7", "al_r8_r10_LSR_7"},
    {{pl, r8, r14, LSR, 32}, false, al, "pl r8 r14 LSR 32", "pl_r8_r14_LSR_32"},
    {{ne, r12, r10, LSR, 9}, false, al, "ne r12 r10 LSR 9", "ne_r12_r10_LSR_9"},
    {{vc, r2, r4, LSR, 23}, false, al, "vc r2 r4 LSR 23", "vc_r2_r4_LSR_23"},
    {{ne, r1, r3, ASR, 22}, false, al, "ne r1 r3 ASR 22", "ne_r1_r3_ASR_22"},
    {{eq, r7, r1, ASR, 32}, false, al, "eq r7 r1 ASR 32", "eq_r7_r1_ASR_32"},
    {{ge, r7, r12, LSR, 29}, false, al, "ge r7 r12 LSR 29", "ge_r7_r12_LSR_29"},
    {{hi, r4, r6, LSR, 2}, false, al, "hi r4 r6 LSR 2", "hi_r4_r6_LSR_2"},
    {{hi, r12, r8, LSR, 3}, false, al, "hi r12 r8 LSR 3", "hi_r12_r8_LSR_3"},
    {{vs, r3, r9, ASR, 11}, false, al, "vs r3 r9 ASR 11", "vs_r3_r9_ASR_11"},
    {{cs, r4, r9, ASR, 2}, false, al, "cs r4 r9 ASR 2", "cs_r4_r9_ASR_2"},
    {{cs, r7, r6, ASR, 23}, false, al, "cs r7 r6 ASR 23", "cs_r7_r6_ASR_23"},
    {{lt, r5, r8, LSR, 17}, false, al, "lt r5 r8 LSR 17", "lt_r5_r8_LSR_17"},
    {{eq, r8, r2, LSR, 11}, false, al, "eq r8 r2 LSR 11", "eq_r8_r2_LSR_11"},
    {{ls, r12, r9, LSR, 5}, false, al, "ls r12 r9 LSR 5", "ls_r12_r9_LSR_5"},
    {{cc, r14, r14, ASR, 15},
     false,
     al,
     "cc r14 r14 ASR 15",
     "cc_r14_r14_ASR_15"},
    {{mi, r2, r14, LSR, 10}, false, al, "mi r2 r14 LSR 10", "mi_r2_r14_LSR_10"},
    {{vs, r5, r11, ASR, 29}, false, al, "vs r5 r11 ASR 29", "vs_r5_r11_ASR_29"},
    {{gt, r12, r9, LSR, 27}, false, al, "gt r12 r9 LSR 27", "gt_r12_r9_LSR_27"},
    {{hi, r12, r5, LSR, 11}, false, al, "hi r12 r5 LSR 11", "hi_r12_r5_LSR_11"},
    {{cc, r12, r10, ASR, 10},
     false,
     al,
     "cc r12 r10 ASR 10",
     "cc_r12_r10_ASR_10"},
    {{lt, r11, r1, LSR, 20}, false, al, "lt r11 r1 LSR 20", "lt_r11_r1_LSR_20"},
    {{lt, r0, r0, ASR, 25}, false, al, "lt r0 r0 ASR 25", "lt_r0_r0_ASR_25"},
    {{le, r10, r1, LSR, 19}, false, al, "le r10 r1 LSR 19", "le_r10_r1_LSR_19"},
    {{le, r5, r1, LSR, 28}, false, al, "le r5 r1 LSR 28", "le_r5_r1_LSR_28"},
    {{cs, r6, r11, LSR, 32}, false, al, "cs r6 r11 LSR 32", "cs_r6_r11_LSR_32"},
    {{vs, r10, r13, LSR, 8}, false, al, "vs r10 r13 LSR 8", "vs_r10_r13_LSR_8"},
    {{eq, r3, r4, ASR, 5}, false, al, "eq r3 r4 ASR 5", "eq_r3_r4_ASR_5"},
    {{pl, r3, r13, LSR, 17}, false, al, "pl r3 r13 LSR 17", "pl_r3_r13_LSR_17"},
    {{vs, r3, r6, ASR, 5}, false, al, "vs r3 r6 ASR 5", "vs_r3_r6_ASR_5"},
    {{al, r7, r8, ASR, 3}, false, al, "al r7 r8 ASR 3", "al_r7_r8_ASR_3"},
    {{hi, r9, r8, ASR, 16}, false, al, "hi r9 r8 ASR 16", "hi_r9_r8_ASR_16"},
    {{le, r12, r5, ASR, 16}, false, al, "le r12 r5 ASR 16", "le_r12_r5_ASR_16"},
    {{al, r12, r10, ASR, 8}, false, al, "al r12 r10 ASR 8", "al_r12_r10_ASR_8"},
    {{lt, r9, r9, LSR, 3}, false, al, "lt r9 r9 LSR 3", "lt_r9_r9_LSR_3"},
    {{ge, r2, r11, ASR, 26}, false, al, "ge r2 r11 ASR 26", "ge_r2_r11_ASR_26"},
    {{cs, r13, r12, ASR, 12},
     false,
     al,
     "cs r13 r12 ASR 12",
     "cs_r13_r12_ASR_12"},
    {{hi, r14, r2, ASR, 9}, false, al, "hi r14 r2 ASR 9", "hi_r14_r2_ASR_9"},
    {{lt, r0, r3, ASR, 23}, false, al, "lt r0 r3 ASR 23", "lt_r0_r3_ASR_23"},
    {{eq, r6, r4, LSR, 16}, false, al, "eq r6 r4 LSR 16", "eq_r6_r4_LSR_16"},
    {{mi, r11, r8, LSR, 20}, false, al, "mi r11 r8 LSR 20", "mi_r11_r8_LSR_20"},
    {{vc, r0, r9, ASR, 23}, false, al, "vc r0 r9 ASR 23", "vc_r0_r9_ASR_23"},
    {{pl, r11, r0, LSR, 8}, false, al, "pl r11 r0 LSR 8", "pl_r11_r0_LSR_8"},
    {{pl, r14, r9, LSR, 11}, false, al, "pl r14 r9 LSR 11", "pl_r14_r9_LSR_11"},
    {{pl, r10, r12, LSR, 2}, false, al, "pl r10 r12 LSR 2", "pl_r10_r12_LSR_2"},
    {{mi, r0, r9, ASR, 23}, false, al, "mi r0 r9 ASR 23", "mi_r0_r9_ASR_23"},
    {{ge, r12, r0, ASR, 9}, false, al, "ge r12 r0 ASR 9", "ge_r12_r0_ASR_9"},
    {{eq, r4, r9, LSR, 1}, false, al, "eq r4 r9 LSR 1", "eq_r4_r9_LSR_1"},
    {{eq, r14, r11, ASR, 4}, false, al, "eq r14 r11 ASR 4", "eq_r14_r11_ASR_4"},
    {{ge, r1, r1, ASR, 23}, false, al, "ge r1 r1 ASR 23", "ge_r1_r1_ASR_23"},
    {{ge, r14, r2, LSR, 3}, false, al, "ge r14 r2 LSR 3", "ge_r14_r2_LSR_3"},
    {{pl, r1, r5, ASR, 16}, false, al, "pl r1 r5 ASR 16", "pl_r1_r5_ASR_16"},
    {{vc, r9, r14, ASR, 28}, false, al, "vc r9 r14 ASR 28", "vc_r9_r14_ASR_28"},
    {{cs, r6, r3, LSR, 9}, false, al, "cs r6 r3 LSR 9", "cs_r6_r3_LSR_9"},
    {{pl, r6, r12, ASR, 32}, false, al, "pl r6 r12 ASR 32", "pl_r6_r12_ASR_32"},
    {{ne, r4, r4, ASR, 32}, false, al, "ne r4 r4 ASR 32", "ne_r4_r4_ASR_32"},
    {{cs, r14, r6, ASR, 14}, false, al, "cs r14 r6 ASR 14", "cs_r14_r6_ASR_14"},
    {{al, r2, r5, LSR, 1}, false, al, "al r2 r5 LSR 1", "al_r2_r5_LSR_1"},
    {{ge, r0, r1, LSR, 20}, false, al, "ge r0 r1 LSR 20", "ge_r0_r1_LSR_20"},
    {{vs, r2, r5, LSR, 11}, false, al, "vs r2 r5 LSR 11", "vs_r2_r5_LSR_11"},
    {{vs, r1, r10, LSR, 17}, false, al, "vs r1 r10 LSR 17", "vs_r1_r10_LSR_17"},
    {{hi, r0, r2, LSR, 13}, false, al, "hi r0 r2 LSR 13", "hi_r0_r2_LSR_13"},
    {{hi, r11, r14, LSR, 9}, false, al, "hi r11 r14 LSR 9", "hi_r11_r14_LSR_9"},
    {{le, r11, r9, ASR, 3}, false, al, "le r11 r9 ASR 3", "le_r11_r9_ASR_3"},
    {{le, r14, r13, LSR, 9}, false, al, "le r14 r13 LSR 9", "le_r14_r13_LSR_9"},
    {{cc, r7, r4, ASR, 24}, false, al, "cc r7 r4 ASR 24", "cc_r7_r4_ASR_24"},
    {{lt, r1, r3, LSR, 17}, false, al, "lt r1 r3 LSR 17", "lt_r1_r3_LSR_17"},
    {{mi, r10, r12, LSR, 16},
     false,
     al,
     "mi r10 r12 LSR 16",
     "mi_r10_r12_LSR_16"},
    {{vc, r7, r14, LSR, 11}, false, al, "vc r7 r14 LSR 11", "vc_r7_r14_LSR_11"},
    {{gt, r7, r3, ASR, 29}, false, al, "gt r7 r3 ASR 29", "gt_r7_r3_ASR_29"},
    {{mi, r7, r13, ASR, 27}, false, al, "mi r7 r13 ASR 27", "mi_r7_r13_ASR_27"},
    {{cs, r4, r10, ASR, 21}, false, al, "cs r4 r10 ASR 21", "cs_r4_r10_ASR_21"},
    {{cc, r8, r9, ASR, 16}, false, al, "cc r8 r9 ASR 16", "cc_r8_r9_ASR_16"},
    {{gt, r1, r1, LSR, 29}, false, al, "gt r1 r1 LSR 29", "gt_r1_r1_LSR_29"},
    {{lt, r11, r8, LSR, 8}, false, al, "lt r11 r8 LSR 8", "lt_r11_r8_LSR_8"},
    {{eq, r9, r3, ASR, 24}, false, al, "eq r9 r3 ASR 24", "eq_r9_r3_ASR_24"},
    {{mi, r0, r14, LSR, 13}, false, al, "mi r0 r14 LSR 13", "mi_r0_r14_LSR_13"},
    {{hi, r5, r9, LSR, 31}, false, al, "hi r5 r9 LSR 31", "hi_r5_r9_LSR_31"},
    {{vc, r8, r3, LSR, 25}, false, al, "vc r8 r3 LSR 25", "vc_r8_r3_LSR_25"},
    {{le, r6, r5, ASR, 28}, false, al, "le r6 r5 ASR 28", "le_r6_r5_ASR_28"},
    {{ne, r11, r6, ASR, 24}, false, al, "ne r11 r6 ASR 24", "ne_r11_r6_ASR_24"},
    {{vc, r11, r10, LSR, 9}, false, al, "vc r11 r10 LSR 9", "vc_r11_r10_LSR_9"},
    {{cc, r9, r4, LSR, 31}, false, al, "cc r9 r4 LSR 31", "cc_r9_r4_LSR_31"},
    {{vs, r14, r3, ASR, 32}, false, al, "vs r14 r3 ASR 32", "vs_r14_r3_ASR_32"},
    {{cs, r5, r3, ASR, 27}, false, al, "cs r5 r3 ASR 27", "cs_r5_r3_ASR_27"},
    {{gt, r2, r8, ASR, 18}, false, al, "gt r2 r8 ASR 18", "gt_r2_r8_ASR_18"},
    {{lt, r11, r7, LSR, 4}, false, al, "lt r11 r7 LSR 4", "lt_r11_r7_LSR_4"},
    {{eq, r11, r3, LSR, 17}, false, al, "eq r11 r3 LSR 17", "eq_r11_r3_LSR_17"},
    {{cc, r2, r12, LSR, 10}, false, al, "cc r2 r12 LSR 10", "cc_r2_r12_LSR_10"},
    {{ne, r10, r12, ASR, 31},
     false,
     al,
     "ne r10 r12 ASR 31",
     "ne_r10_r12_ASR_31"},
    {{lt, r11, r5, LSR, 4}, false, al, "lt r11 r5 LSR 4", "lt_r11_r5_LSR_4"},
    {{gt, r3, r10, ASR, 3}, false, al, "gt r3 r10 ASR 3", "gt_r3_r10_ASR_3"},
    {{ge, r7, r0, ASR, 17}, false, al, "ge r7 r0 ASR 17", "ge_r7_r0_ASR_17"},
    {{hi, r7, r14, ASR, 23}, false, al, "hi r7 r14 ASR 23", "hi_r7_r14_ASR_23"},
    {{mi, r10, r14, LSR, 28},
     false,
     al,
     "mi r10 r14 LSR 28",
     "mi_r10_r14_LSR_28"},
    {{al, r14, r11, LSR, 12},
     false,
     al,
     "al r14 r11 LSR 12",
     "al_r14_r11_LSR_12"},
    {{cc, r13, r6, ASR, 23}, false, al, "cc r13 r6 ASR 23", "cc_r13_r6_ASR_23"},
    {{ge, r4, r0, ASR, 3}, false, al, "ge r4 r0 ASR 3", "ge_r4_r0_ASR_3"},
    {{vc, r8, r2, LSR, 16}, false, al, "vc r8 r2 LSR 16", "vc_r8_r2_LSR_16"},
    {{vc, r9, r8, ASR, 26}, false, al, "vc r9 r8 ASR 26", "vc_r9_r8_ASR_26"},
    {{pl, r3, r4, ASR, 16}, false, al, "pl r3 r4 ASR 16", "pl_r3_r4_ASR_16"},
    {{vc, r12, r13, ASR, 29},
     false,
     al,
     "vc r12 r13 ASR 29",
     "vc_r12_r13_ASR_29"},
    {{hi, r0, r7, LSR, 13}, false, al, "hi r0 r7 LSR 13", "hi_r0_r7_LSR_13"},
    {{vc, r2, r2, ASR, 1}, false, al, "vc r2 r2 ASR 1", "vc_r2_r2_ASR_1"},
    {{eq, r13, r6, ASR, 2}, false, al, "eq r13 r6 ASR 2", "eq_r13_r6_ASR_2"},
    {{ge, r14, r3, LSR, 5}, false, al, "ge r14 r3 LSR 5", "ge_r14_r3_LSR_5"},
    {{cc, r2, r11, ASR, 19}, false, al, "cc r2 r11 ASR 19", "cc_r2_r11_ASR_19"},
    {{eq, r14, r6, LSR, 17}, false, al, "eq r14 r6 LSR 17", "eq_r14_r6_LSR_17"},
    {{mi, r11, r2, LSR, 1}, false, al, "mi r11 r2 LSR 1", "mi_r11_r2_LSR_1"},
    {{pl, r6, r14, ASR, 31}, false, al, "pl r6 r14 ASR 31", "pl_r6_r14_ASR_31"},
    {{le, r10, r11, LSR, 30},
     false,
     al,
     "le r10 r11 LSR 30",
     "le_r10_r11_LSR_30"},
    {{lt, r4, r5, ASR, 30}, false, al, "lt r4 r5 ASR 30", "lt_r4_r5_ASR_30"},
    {{ge, r11, r0, LSR, 15}, false, al, "ge r11 r0 LSR 15", "ge_r11_r0_LSR_15"},
    {{cc, r0, r1, ASR, 14}, false, al, "cc r0 r1 ASR 14", "cc_r0_r1_ASR_14"},
    {{le, r10, r12, LSR, 30},
     false,
     al,
     "le r10 r12 LSR 30",
     "le_r10_r12_LSR_30"},
    {{le, r8, r2, ASR, 11}, false, al, "le r8 r2 ASR 11", "le_r8_r2_ASR_11"},
    {{ls, r12, r7, ASR, 23}, false, al, "ls r12 r7 ASR 23", "ls_r12_r7_ASR_23"},
    {{hi, r14, r9, ASR, 31}, false, al, "hi r14 r9 ASR 31", "hi_r14_r9_ASR_31"},
    {{lt, r12, r4, LSR, 20}, false, al, "lt r12 r4 LSR 20", "lt_r12_r4_LSR_20"},
    {{lt, r6, r4, ASR, 12}, false, al, "lt r6 r4 ASR 12", "lt_r6_r4_ASR_12"},
    {{pl, r0, r0, ASR, 21}, false, al, "pl r0 r0 ASR 21", "pl_r0_r0_ASR_21"},
    {{ls, r2, r3, LSR, 9}, false, al, "ls r2 r3 LSR 9", "ls_r2_r3_LSR_9"},
    {{le, r4, r11, LSR, 22}, false, al, "le r4 r11 LSR 22", "le_r4_r11_LSR_22"},
    {{gt, r9, r6, LSR, 28}, false, al, "gt r9 r6 LSR 28", "gt_r9_r6_LSR_28"},
    {{lt, r7, r6, ASR, 25}, false, al, "lt r7 r6 ASR 25", "lt_r7_r6_ASR_25"},
    {{ne, r10, r3, LSR, 25}, false, al, "ne r10 r3 LSR 25", "ne_r10_r3_LSR_25"},
    {{hi, r14, r11, ASR, 16},
     false,
     al,
     "hi r14 r11 ASR 16",
     "hi_r14_r11_ASR_16"},
    {{cc, r0, r8, ASR, 26}, false, al, "cc r0 r8 ASR 26", "cc_r0_r8_ASR_26"},
    {{pl, r5, r0, LSR, 29}, false, al, "pl r5 r0 LSR 29", "pl_r5_r0_LSR_29"},
    {{lt, r5, r6, ASR, 9}, false, al, "lt r5 r6 ASR 9", "lt_r5_r6_ASR_9"},
    {{vc, r11, r7, ASR, 20}, false, al, "vc r11 r7 ASR 20", "vc_r11_r7_ASR_20"},
    {{vc, r14, r13, ASR, 20},
     false,
     al,
     "vc r14 r13 ASR 20",
     "vc_r14_r13_ASR_20"},
    {{le, r3, r0, ASR, 31}, false, al, "le r3 r0 ASR 31", "le_r3_r0_ASR_31"},
    {{eq, r5, r12, LSR, 18}, false, al, "eq r5 r12 LSR 18", "eq_r5_r12_LSR_18"},
    {{cs, r2, r14, ASR, 3}, false, al, "cs r2 r14 ASR 3", "cs_r2_r14_ASR_3"},
    {{ge, r1, r4, ASR, 15}, false, al, "ge r1 r4 ASR 15", "ge_r1_r4_ASR_15"},
    {{mi, r8, r5, ASR, 9}, false, al, "mi r8 r5 ASR 9", "mi_r8_r5_ASR_9"},
    {{vc, r7, r11, LSR, 9}, false, al, "vc r7 r11 LSR 9", "vc_r7_r11_LSR_9"},
    {{pl, r4, r7, ASR, 10}, false, al, "pl r4 r7 ASR 10", "pl_r4_r7_ASR_10"},
    {{hi, r4, r13, ASR, 32}, false, al, "hi r4 r13 ASR 32", "hi_r4_r13_ASR_32"},
    {{lt, r4, r10, ASR, 22}, false, al, "lt r4 r10 ASR 22", "lt_r4_r10_ASR_22"},
    {{ne, r2, r4, LSR, 23}, false, al, "ne r2 r4 LSR 23", "ne_r2_r4_LSR_23"},
    {{lt, r12, r12, ASR, 18},
     false,
     al,
     "lt r12 r12 ASR 18",
     "lt_r12_r12_ASR_18"},
    {{lt, r6, r13, LSR, 28}, false, al, "lt r6 r13 LSR 28", "lt_r6_r13_LSR_28"},
    {{vc, r8, r8, ASR, 32}, false, al, "vc r8 r8 ASR 32", "vc_r8_r8_ASR_32"},
    {{vs, r4, r1, LSR, 24}, false, al, "vs r4 r1 LSR 24", "vs_r4_r1_LSR_24"},
    {{al, r7, r7, ASR, 24}, false, al, "al r7 r7 ASR 24", "al_r7_r7_ASR_24"},
    {{mi, r9, r2, LSR, 2}, false, al, "mi r9 r2 LSR 2", "mi_r9_r2_LSR_2"},
    {{lt, r4, r6, ASR, 5}, false, al, "lt r4 r6 ASR 5", "lt_r4_r6_ASR_5"},
    {{vs, r14, r11, LSR, 18},
     false,
     al,
     "vs r14 r11 LSR 18",
     "vs_r14_r11_LSR_18"},
    {{cc, r9, r7, LSR, 12}, false, al, "cc r9 r7 LSR 12", "cc_r9_r7_LSR_12"},
    {{mi, r0, r6, LSR, 12}, false, al, "mi r0 r6 LSR 12", "mi_r0_r6_LSR_12"},
    {{vs, r5, r0, LSR, 11}, false, al, "vs r5 r0 LSR 11", "vs_r5_r0_LSR_11"},
    {{hi, r0, r14, LSR, 13}, false, al, "hi r0 r14 LSR 13", "hi_r0_r14_LSR_13"},
    {{vc, r1, r5, LSR, 30}, false, al, "vc r1 r5 LSR 30", "vc_r1_r5_LSR_30"},
    {{vc, r14, r7, LSR, 19}, false, al, "vc r14 r7 LSR 19", "vc_r14_r7_LSR_19"},
    {{eq, r2, r14, LSR, 28}, false, al, "eq r2 r14 LSR 28", "eq_r2_r14_LSR_28"},
    {{ls, r5, r1, LSR, 14}, false, al, "ls r5 r1 LSR 14", "ls_r5_r1_LSR_14"},
    {{mi, r6, r12, LSR, 14}, false, al, "mi r6 r12 LSR 14", "mi_r6_r12_LSR_14"},
    {{ne, r1, r0, LSR, 11}, false, al, "ne r1 r0 LSR 11", "ne_r1_r0_LSR_11"},
    {{al, r14, r12, LSR, 2}, false, al, "al r14 r12 LSR 2", "al_r14_r12_LSR_2"},
    {{eq, r10, r10, LSR, 20},
     false,
     al,
     "eq r10 r10 LSR 20",
     "eq_r10_r10_LSR_20"},
    {{vc, r2, r14, ASR, 29}, false, al, "vc r2 r14 ASR 29", "vc_r2_r14_ASR_29"},
    {{vc, r3, r1, ASR, 22}, false, al, "vc r3 r1 ASR 22", "vc_r3_r1_ASR_22"},
    {{vs, r6, r5, ASR, 2}, false, al, "vs r6 r5 ASR 2", "vs_r6_r5_ASR_2"},
    {{gt, r2, r5, ASR, 19}, false, al, "gt r2 r5 ASR 19", "gt_r2_r5_ASR_19"},
    {{eq, r12, r13, LSR, 16},
     false,
     al,
     "eq r12 r13 LSR 16",
     "eq_r12_r13_LSR_16"},
    {{ls, r7, r7, ASR, 14}, false, al, "ls r7 r7 ASR 14", "ls_r7_r7_ASR_14"},
    {{ge, r5, r7, ASR, 15}, false, al, "ge r5 r7 ASR 15", "ge_r5_r7_ASR_15"},
    {{al, r10, r1, ASR, 29}, false, al, "al r10 r1 ASR 29", "al_r10_r1_ASR_29"},
    {{pl, r4, r11, LSR, 14}, false, al, "pl r4 r11 LSR 14", "pl_r4_r11_LSR_14"},
    {{cc, r9, r13, LSR, 5}, false, al, "cc r9 r13 LSR 5", "cc_r9_r13_LSR_5"},
    {{ls, r10, r12, ASR, 13},
     false,
     al,
     "ls r10 r12 ASR 13",
     "ls_r10_r12_ASR_13"},
    {{gt, r5, r11, LSR, 25}, false, al, "gt r5 r11 LSR 25", "gt_r5_r11_LSR_25"},
    {{vc, r1, r13, ASR, 18}, false, al, "vc r1 r13 ASR 18", "vc_r1_r13_ASR_18"},
    {{le, r0, r4, LSR, 30}, false, al, "le r0 r4 LSR 30", "le_r0_r4_LSR_30"},
    {{eq, r6, r1, ASR, 15}, false, al, "eq r6 r1 ASR 15", "eq_r6_r1_ASR_15"},
    {{eq, r11, r6, LSR, 19}, false, al, "eq r11 r6 LSR 19", "eq_r11_r6_LSR_19"},
    {{vc, r3, r7, ASR, 2}, false, al, "vc r3 r7 ASR 2", "vc_r3_r7_ASR_2"},
    {{cs, r9, r13, ASR, 11}, false, al, "cs r9 r13 ASR 11", "cs_r9_r13_ASR_11"},
    {{lt, r12, r3, ASR, 1}, false, al, "lt r12 r3 ASR 1", "lt_r12_r3_ASR_1"},
    {{le, r0, r11, LSR, 26}, false, al, "le r0 r11 LSR 26", "le_r0_r11_LSR_26"},
    {{lt, r9, r10, LSR, 23}, false, al, "lt r9 r10 LSR 23", "lt_r9_r10_LSR_23"},
    {{ls, r10, r13, LSR, 25},
     false,
     al,
     "ls r10 r13 LSR 25",
     "ls_r10_r13_LSR_25"},
    {{eq, r5, r9, ASR, 32}, false, al, "eq r5 r9 ASR 32", "eq_r5_r9_ASR_32"},
    {{vc, r9, r12, LSR, 11}, false, al, "vc r9 r12 LSR 11", "vc_r9_r12_LSR_11"},
    {{lt, r12, r0, LSR, 5}, false, al, "lt r12 r0 LSR 5", "lt_r12_r0_LSR_5"},
    {{mi, r13, r5, LSR, 23}, false, al, "mi r13 r5 LSR 23", "mi_r13_r5_LSR_23"},
    {{ge, r13, r14, ASR, 3}, false, al, "ge r13 r14 ASR 3", "ge_r13_r14_ASR_3"},
    {{cc, r7, r6, LSR, 2}, false, al, "cc r7 r6 LSR 2", "cc_r7_r6_LSR_2"},
    {{ge, r11, r7, LSR, 26}, false, al, "ge r11 r7 LSR 26", "ge_r11_r7_LSR_26"},
    {{vs, r7, r5, LSR, 3}, false, al, "vs r7 r5 LSR 3", "vs_r7_r5_LSR_3"},
    {{cs, r2, r2, ASR, 23}, false, al, "cs r2 r2 ASR 23", "cs_r2_r2_ASR_23"},
    {{hi, r11, r11, ASR, 15},
     false,
     al,
     "hi r11 r11 ASR 15",
     "hi_r11_r11_ASR_15"},
    {{ge, r14, r13, LSR, 1}, false, al, "ge r14 r13 LSR 1", "ge_r14_r13_LSR_1"},
    {{vs, r6, r13, ASR, 29}, false, al, "vs r6 r13 ASR 29", "vs_r6_r13_ASR_29"},
    {{lt, r1, r9, LSR, 3}, false, al, "lt r1 r9 LSR 3", "lt_r1_r9_LSR_3"},
    {{vs, r8, r7, ASR, 4}, false, al, "vs r8 r7 ASR 4", "vs_r8_r7_ASR_4"},
    {{ls, r14, r14, ASR, 31},
     false,
     al,
     "ls r14 r14 ASR 31",
     "ls_r14_r14_ASR_31"},
    {{pl, r2, r7, ASR, 2}, false, al, "pl r2 r7 ASR 2", "pl_r2_r7_ASR_2"},
    {{al, r1, r2, LSR, 14}, false, al, "al r1 r2 LSR 14", "al_r1_r2_LSR_14"},
    {{ge, r7, r9, ASR, 17}, false, al, "ge r7 r9 ASR 17", "ge_r7_r9_ASR_17"},
    {{le, r2, r9, ASR, 1}, false, al, "le r2 r9 ASR 1", "le_r2_r9_ASR_1"},
    {{cs, r7, r2, ASR, 26}, false, al, "cs r7 r2 ASR 26", "cs_r7_r2_ASR_26"},
    {{eq, r6, r0, LSR, 26}, false, al, "eq r6 r0 LSR 26", "eq_r6_r0_LSR_26"},
    {{gt, r10, r12, ASR, 10},
     false,
     al,
     "gt r10 r12 ASR 10",
     "gt_r10_r12_ASR_10"},
    {{ge, r2, r2, ASR, 7}, false, al, "ge r2 r2 ASR 7", "ge_r2_r2_ASR_7"},
    {{vc, r1, r1, ASR, 5}, false, al, "vc r1 r1 ASR 5", "vc_r1_r1_ASR_5"},
    {{cs, r1, r7, ASR, 7}, false, al, "cs r1 r7 ASR 7", "cs_r1_r7_ASR_7"},
    {{eq, r0, r5, LSR, 21}, false, al, "eq r0 r5 LSR 21", "eq_r0_r5_LSR_21"},
    {{lt, r13, r1, LSR, 22}, false, al, "lt r13 r1 LSR 22", "lt_r13_r1_LSR_22"},
    {{cs, r11, r3, ASR, 26}, false, al, "cs r11 r3 ASR 26", "cs_r11_r3_ASR_26"},
    {{cs, r2, r14, LSR, 13}, false, al, "cs r2 r14 LSR 13", "cs_r2_r14_LSR_13"},
    {{cs, r11, r0, LSR, 9}, false, al, "cs r11 r0 LSR 9", "cs_r11_r0_LSR_9"},
    {{lt, r11, r12, LSR, 29},
     false,
     al,
     "lt r11 r12 LSR 29",
     "lt_r11_r12_LSR_29"},
    {{vc, r9, r0, ASR, 7}, false, al, "vc r9 r0 ASR 7", "vc_r9_r0_ASR_7"},
    {{eq, r8, r12, ASR, 13}, false, al, "eq r8 r12 ASR 13", "eq_r8_r12_ASR_13"},
    {{vc, r0, r8, ASR, 22}, false, al, "vc r0 r8 ASR 22", "vc_r0_r8_ASR_22"},
    {{lt, r6, r4, ASR, 25}, false, al, "lt r6 r4 ASR 25", "lt_r6_r4_ASR_25"},
    {{cs, r11, r9, ASR, 2}, false, al, "cs r11 r9 ASR 2", "cs_r11_r9_ASR_2"},
    {{cs, r8, r1, ASR, 1}, false, al, "cs r8 r1 ASR 1", "cs_r8_r1_ASR_1"},
    {{hi, r9, r7, ASR, 26}, false, al, "hi r9 r7 ASR 26", "hi_r9_r7_ASR_26"},
    {{pl, r8, r10, ASR, 6}, false, al, "pl r8 r10 ASR 6", "pl_r8_r10_ASR_6"},
    {{al, r6, r11, ASR, 1}, false, al, "al r6 r11 ASR 1", "al_r6_r11_ASR_1"},
    {{al, r2, r8, ASR, 28}, false, al, "al r2 r8 ASR 28", "al_r2_r8_ASR_28"},
    {{eq, r6, r10, LSR, 8}, false, al, "eq r6 r10 LSR 8", "eq_r6_r10_LSR_8"},
    {{pl, r6, r6, ASR, 10}, false, al, "pl r6 r6 ASR 10", "pl_r6_r6_ASR_10"},
    {{ls, r10, r6, LSR, 8}, false, al, "ls r10 r6 LSR 8", "ls_r10_r6_LSR_8"},
    {{ge, r7, r4, LSR, 10}, false, al, "ge r7 r4 LSR 10", "ge_r7_r4_LSR_10"},
    {{pl, r3, r2, ASR, 29}, false, al, "pl r3 r2 ASR 29", "pl_r3_r2_ASR_29"},
    {{vc, r12, r4, LSR, 1}, false, al, "vc r12 r4 LSR 1", "vc_r12_r4_LSR_1"},
    {{hi, r8, r8, ASR, 24}, false, al, "hi r8 r8 ASR 24", "hi_r8_r8_ASR_24"},
    {{vs, r0, r12, ASR, 8}, false, al, "vs r0 r12 ASR 8", "vs_r0_r12_ASR_8"},
    {{ge, r1, r0, ASR, 6}, false, al, "ge r1 r0 ASR 6", "ge_r1_r0_ASR_6"},
    {{gt, r13, r3, ASR, 3}, false, al, "gt r13 r3 ASR 3", "gt_r13_r3_ASR_3"},
    {{cc, r0, r8, LSR, 26}, false, al, "cc r0 r8 LSR 26", "cc_r0_r8_LSR_26"},
    {{eq, r8, r9, ASR, 19}, false, al, "eq r8 r9 ASR 19", "eq_r8_r9_ASR_19"},
    {{eq, r3, r6, LSR, 10}, false, al, "eq r3 r6 LSR 10", "eq_r3_r6_LSR_10"},
    {{gt, r4, r3, ASR, 24}, false, al, "gt r4 r3 ASR 24", "gt_r4_r3_ASR_24"},
    {{pl, r12, r14, ASR, 5}, false, al, "pl r12 r14 ASR 5", "pl_r12_r14_ASR_5"},
    {{cs, r7, r5, ASR, 8}, false, al, "cs r7 r5 ASR 8", "cs_r7_r5_ASR_8"},
    {{cc, r3, r8, LSR, 21}, false, al, "cc r3 r8 LSR 21", "cc_r3_r8_LSR_21"},
    {{ge, r5, r12, ASR, 9}, false, al, "ge r5 r12 ASR 9", "ge_r5_r12_ASR_9"},
    {{lt, r2, r4, ASR, 21}, false, al, "lt r2 r4 ASR 21", "lt_r2_r4_ASR_21"},
    {{ne, r5, r10, LSR, 24}, false, al, "ne r5 r10 LSR 24", "ne_r5_r10_LSR_24"},
    {{eq, r10, r13, LSR, 6}, false, al, "eq r10 r13 LSR 6", "eq_r10_r13_LSR_6"},
    {{le, r2, r12, ASR, 25}, false, al, "le r2 r12 ASR 25", "le_r2_r12_ASR_25"},
    {{lt, r6, r1, ASR, 7}, false, al, "lt r6 r1 ASR 7", "lt_r6_r1_ASR_7"},
    {{vs, r12, r10, ASR, 28},
     false,
     al,
     "vs r12 r10 ASR 28",
     "vs_r12_r10_ASR_28"},
    {{ls, r10, r4, ASR, 17}, false, al, "ls r10 r4 ASR 17", "ls_r10_r4_ASR_17"},
    {{le, r3, r4, ASR, 8}, false, al, "le r3 r4 ASR 8", "le_r3_r4_ASR_8"},
    {{hi, r14, r0, LSR, 31}, false, al, "hi r14 r0 LSR 31", "hi_r14_r0_LSR_31"},
    {{ge, r13, r2, ASR, 19}, false, al, "ge r13 r2 ASR 19", "ge_r13_r2_ASR_19"},
    {{pl, r13, r3, ASR, 10}, false, al, "pl r13 r3 ASR 10", "pl_r13_r3_ASR_10"},
    {{cc, r7, r8, ASR, 32}, false, al, "cc r7 r8 ASR 32", "cc_r7_r8_ASR_32"},
    {{cc, r8, r3, ASR, 20}, false, al, "cc r8 r3 ASR 20", "cc_r8_r3_ASR_20"},
    {{vc, r5, r10, LSR, 25}, false, al, "vc r5 r10 LSR 25", "vc_r5_r10_LSR_25"},
    {{le, r3, r14, ASR, 24}, false, al, "le r3 r14 ASR 24", "le_r3_r14_ASR_24"},
    {{pl, r1, r12, LSR, 12}, false, al, "pl r1 r12 LSR 12", "pl_r1_r12_LSR_12"},
    {{vs, r11, r0, ASR, 11}, false, al, "vs r11 r0 ASR 11", "vs_r11_r0_ASR_11"},
    {{eq, r14, r1, LSR, 2}, false, al, "eq r14 r1 LSR 2", "eq_r14_r1_LSR_2"},
    {{ne, r2, r1, LSR, 18}, false, al, "ne r2 r1 LSR 18", "ne_r2_r1_LSR_18"},
    {{al, r7, r13, LSR, 2}, false, al, "al r7 r13 LSR 2", "al_r7_r13_LSR_2"},
    {{vc, r5, r8, LSR, 18}, false, al, "vc r5 r8 LSR 18", "vc_r5_r8_LSR_18"},
    {{le, r1, r12, ASR, 5}, false, al, "le r1 r12 ASR 5", "le_r1_r12_ASR_5"},
    {{pl, r6, r2, LSR, 11}, false, al, "pl r6 r2 LSR 11", "pl_r6_r2_LSR_11"},
    {{cc, r7, r12, LSR, 3}, false, al, "cc r7 r12 LSR 3", "cc_r7_r12_LSR_3"},
    {{al, r10, r0, LSR, 9}, false, al, "al r10 r0 LSR 9", "al_r10_r0_LSR_9"},
    {{hi, r2, r1, LSR, 29}, false, al, "hi r2 r1 LSR 29", "hi_r2_r1_LSR_29"},
    {{lt, r3, r13, LSR, 13}, false, al, "lt r3 r13 LSR 13", "lt_r3_r13_LSR_13"},
    {{mi, r13, r14, ASR, 23},
     false,
     al,
     "mi r13 r14 ASR 23",
     "mi_r13_r14_ASR_23"},
    {{lt, r14, r14, LSR, 16},
     false,
     al,
     "lt r14 r14 LSR 16",
     "lt_r14_r14_LSR_16"},
    {{hi, r11, r14, ASR, 8}, false, al, "hi r11 r14 ASR 8", "hi_r11_r14_ASR_8"},
    {{eq, r4, r1, LSR, 1}, false, al, "eq r4 r1 LSR 1", "eq_r4_r1_LSR_1"},
    {{ls, r14, r0, LSR, 30}, false, al, "ls r14 r0 LSR 30", "ls_r14_r0_LSR_30"},
    {{le, r1, r9, LSR, 29}, false, al, "le r1 r9 LSR 29", "le_r1_r9_LSR_29"},
    {{vc, r4, r2, ASR, 27}, false, al, "vc r4 r2 ASR 27", "vc_r4_r2_ASR_27"},
    {{cc, r11, r2, LSR, 27}, false, al, "cc r11 r2 LSR 27", "cc_r11_r2_LSR_27"},
    {{lt, r13, r7, ASR, 3}, false, al, "lt r13 r7 ASR 3", "lt_r13_r7_ASR_3"},
    {{hi, r12, r12, ASR, 1}, false, al, "hi r12 r12 ASR 1", "hi_r12_r12_ASR_1"},
    {{ne, r14, r13, LSR, 25},
     false,
     al,
     "ne r14 r13 LSR 25",
     "ne_r14_r13_LSR_25"},
    {{mi, r8, r11, ASR, 6}, false, al, "mi r8 r11 ASR 6", "mi_r8_r11_ASR_6"},
    {{pl, r7, r5, ASR, 31}, false, al, "pl r7 r5 ASR 31", "pl_r7_r5_ASR_31"},
    {{gt, r14, r6, LSR, 9}, false, al, "gt r14 r6 LSR 9", "gt_r14_r6_LSR_9"},
    {{cc, r1, r9, LSR, 7}, false, al, "cc r1 r9 LSR 7", "cc_r1_r9_LSR_7"},
    {{ge, r11, r14, LSR, 10},
     false,
     al,
     "ge r11 r14 LSR 10",
     "ge_r11_r14_LSR_10"},
    {{le, r7, r9, ASR, 25}, false, al, "le r7 r9 ASR 25", "le_r7_r9_ASR_25"},
    {{gt, r0, r14, LSR, 14}, false, al, "gt r0 r14 LSR 14", "gt_r0_r14_LSR_14"},
    {{ne, r11, r4, ASR, 6}, false, al, "ne r11 r4 ASR 6", "ne_r11_r4_ASR_6"},
    {{ls, r10, r9, LSR, 12}, false, al, "ls r10 r9 LSR 12", "ls_r10_r9_LSR_12"},
    {{al, r8, r0, ASR, 27}, false, al, "al r8 r0 ASR 27", "al_r8_r0_ASR_27"},
    {{le, r4, r7, ASR, 21}, false, al, "le r4 r7 ASR 21", "le_r4_r7_ASR_21"},
    {{cc, r8, r5, ASR, 18}, false, al, "cc r8 r5 ASR 18", "cc_r8_r5_ASR_18"},
    {{al, r4, r10, LSR, 21}, false, al, "al r4 r10 LSR 21", "al_r4_r10_LSR_21"},
    {{hi, r8, r5, LSR, 25}, false, al, "hi r8 r5 LSR 25", "hi_r8_r5_LSR_25"},
    {{gt, r4, r2, LSR, 29}, false, al, "gt r4 r2 LSR 29", "gt_r4_r2_LSR_29"},
    {{al, r10, r0, ASR, 1}, false, al, "al r10 r0 ASR 1", "al_r10_r0_ASR_1"},
    {{ls, r1, r12, LSR, 26}, false, al, "ls r1 r12 LSR 26", "ls_r1_r12_LSR_26"},
    {{vs, r13, r6, ASR, 8}, false, al, "vs r13 r6 ASR 8", "vs_r13_r6_ASR_8"},
    {{eq, r13, r12, ASR, 1}, false, al, "eq r13 r12 ASR 1", "eq_r13_r12_ASR_1"},
    {{eq, r9, r11, ASR, 5}, false, al, "eq r9 r11 ASR 5", "eq_r9_r11_ASR_5"},
    {{le, r11, r2, LSR, 18}, false, al, "le r11 r2 LSR 18", "le_r11_r2_LSR_18"},
    {{hi, r11, r0, LSR, 32}, false, al, "hi r11 r0 LSR 32", "hi_r11_r0_LSR_32"},
    {{eq, r8, r5, LSR, 31}, false, al, "eq r8 r5 LSR 31", "eq_r8_r5_LSR_31"},
    {{ne, r7, r13, ASR, 4}, false, al, "ne r7 r13 ASR 4", "ne_r7_r13_ASR_4"},
    {{cs, r7, r7, LSR, 32}, false, al, "cs r7 r7 LSR 32", "cs_r7_r7_LSR_32"},
    {{pl, r13, r5, ASR, 2}, false, al, "pl r13 r5 ASR 2", "pl_r13_r5_ASR_2"},
    {{vc, r9, r2, ASR, 11}, false, al, "vc r9 r2 ASR 11", "vc_r9_r2_ASR_11"},
    {{mi, r7, r7, ASR, 16}, false, al, "mi r7 r7 ASR 16", "mi_r7_r7_ASR_16"},
    {{vs, r2, r3, ASR, 8}, false, al, "vs r2 r3 ASR 8", "vs_r2_r3_ASR_8"},
    {{lt, r5, r3, LSR, 19}, false, al, "lt r5 r3 LSR 19", "lt_r5_r3_LSR_19"},
    {{al, r3, r14, ASR, 20}, false, al, "al r3 r14 ASR 20", "al_r3_r14_ASR_20"},
    {{ge, r10, r11, LSR, 7}, false, al, "ge r10 r11 LSR 7", "ge_r10_r11_LSR_7"},
    {{mi, r2, r14, LSR, 11}, false, al, "mi r2 r14 LSR 11", "mi_r2_r14_LSR_11"},
    {{mi, r3, r1, ASR, 24}, false, al, "mi r3 r1 ASR 24", "mi_r3_r1_ASR_24"},
    {{lt, r7, r14, ASR, 23}, false, al, "lt r7 r14 ASR 23", "lt_r7_r14_ASR_23"},
    {{ge, r14, r3, LSR, 8}, false, al, "ge r14 r3 LSR 8", "ge_r14_r3_LSR_8"},
    {{al, r3, r3, ASR, 16}, false, al, "al r3 r3 ASR 16", "al_r3_r3_ASR_16"},
    {{cs, r12, r6, LSR, 8}, false, al, "cs r12 r6 LSR 8", "cs_r12_r6_LSR_8"},
    {{ge, r9, r1, LSR, 1}, false, al, "ge r9 r1 LSR 1", "ge_r9_r1_LSR_1"},
    {{hi, r0, r2, LSR, 15}, false, al, "hi r0 r2 LSR 15", "hi_r0_r2_LSR_15"},
    {{pl, r4, r3, LSR, 22}, false, al, "pl r4 r3 LSR 22", "pl_r4_r3_LSR_22"},
    {{mi, r14, r1, ASR, 3}, false, al, "mi r14 r1 ASR 3", "mi_r14_r1_ASR_3"},
    {{vc, r7, r6, LSR, 5}, false, al, "vc r7 r6 LSR 5", "vc_r7_r6_LSR_5"},
    {{lt, r7, r3, LSR, 19}, false, al, "lt r7 r3 LSR 19", "lt_r7_r3_LSR_19"},
    {{vc, r9, r3, LSR, 4}, false, al, "vc r9 r3 LSR 4", "vc_r9_r3_LSR_4"},
    {{ls, r2, r1, ASR, 15}, false, al, "ls r2 r1 ASR 15", "ls_r2_r1_ASR_15"},
    {{ls, r1, r10, ASR, 31}, false, al, "ls r1 r10 ASR 31", "ls_r1_r10_ASR_31"},
    {{mi, r5, r9, ASR, 7}, false, al, "mi r5 r9 ASR 7", "mi_r5_r9_ASR_7"},
    {{ne, r7, r2, ASR, 31}, false, al, "ne r7 r2 ASR 31", "ne_r7_r2_ASR_31"},
    {{vc, r0, r1, LSR, 20}, false, al, "vc r0 r1 LSR 20", "vc_r0_r1_LSR_20"},
    {{ge, r7, r11, ASR, 9}, false, al, "ge r7 r11 ASR 9", "ge_r7_r11_ASR_9"},
    {{vc, r8, r13, ASR, 19}, false, al, "vc r8 r13 ASR 19", "vc_r8_r13_ASR_19"},
    {{hi, r7, r5, LSR, 17}, false, al, "hi r7 r5 LSR 17", "hi_r7_r5_LSR_17"},
    {{mi, r11, r2, LSR, 23}, false, al, "mi r11 r2 LSR 23", "mi_r11_r2_LSR_23"},
    {{pl, r13, r13, LSR, 5}, false, al, "pl r13 r13 LSR 5", "pl_r13_r13_LSR_5"},
    {{ls, r1, r3, LSR, 17}, false, al, "ls r1 r3 LSR 17", "ls_r1_r3_LSR_17"},
    {{vc, r6, r5, LSR, 10}, false, al, "vc r6 r5 LSR 10", "vc_r6_r5_LSR_10"},
    {{cs, r6, r6, ASR, 9}, false, al, "cs r6 r6 ASR 9", "cs_r6_r6_ASR_9"},
    {{ls, r3, r8, LSR, 21}, false, al, "ls r3 r8 LSR 21", "ls_r3_r8_LSR_21"},
    {{cs, r2, r0, ASR, 23}, false, al, "cs r2 r0 ASR 23", "cs_r2_r0_ASR_23"},
    {{ge, r0, r13, LSR, 29}, false, al, "ge r0 r13 LSR 29", "ge_r0_r13_LSR_29"},
    {{lt, r13, r12, ASR, 10},
     false,
     al,
     "lt r13 r12 ASR 10",
     "lt_r13_r12_ASR_10"},
    {{vs, r4, r2, ASR, 15}, false, al, "vs r4 r2 ASR 15", "vs_r4_r2_ASR_15"},
    {{mi, r6, r14, ASR, 6}, false, al, "mi r6 r14 ASR 6", "mi_r6_r14_ASR_6"},
    {{ge, r10, r12, ASR, 22},
     false,
     al,
     "ge r10 r12 ASR 22",
     "ge_r10_r12_ASR_22"},
    {{cs, r4, r5, ASR, 2}, false, al, "cs r4 r5 ASR 2", "cs_r4_r5_ASR_2"},
    {{cc, r5, r4, ASR, 4}, false, al, "cc r5 r4 ASR 4", "cc_r5_r4_ASR_4"},
    {{ge, r13, r13, LSR, 30},
     false,
     al,
     "ge r13 r13 LSR 30",
     "ge_r13_r13_LSR_30"},
    {{gt, r1, r11, ASR, 20}, false, al, "gt r1 r11 ASR 20", "gt_r1_r11_ASR_20"},
    {{cs, r2, r12, ASR, 15}, false, al, "cs r2 r12 ASR 15", "cs_r2_r12_ASR_15"},
    {{le, r11, r0, ASR, 32}, false, al, "le r11 r0 ASR 32", "le_r11_r0_ASR_32"},
    {{hi, r0, r3, ASR, 9}, false, al, "hi r0 r3 ASR 9", "hi_r0_r3_ASR_9"},
    {{mi, r9, r8, LSR, 10}, false, al, "mi r9 r8 LSR 10", "mi_r9_r8_LSR_10"},
    {{lt, r12, r3, ASR, 2}, false, al, "lt r12 r3 ASR 2", "lt_r12_r3_ASR_2"},
    {{ne, r11, r2, LSR, 32}, false, al, "ne r11 r2 LSR 32", "ne_r11_r2_LSR_32"},
    {{al, r1, r5, ASR, 6}, false, al, "al r1 r5 ASR 6", "al_r1_r5_ASR_6"},
    {{eq, r0, r3, LSR, 21}, false, al, "eq r0 r3 LSR 21", "eq_r0_r3_LSR_21"},
    {{lt, r7, r11, ASR, 23}, false, al, "lt r7 r11 ASR 23", "lt_r7_r11_ASR_23"},
    {{hi, r8, r13, LSR, 19}, false, al, "hi r8 r13 LSR 19", "hi_r8_r13_LSR_19"},
    {{ne, r9, r10, LSR, 18}, false, al, "ne r9 r10 LSR 18", "ne_r9_r10_LSR_18"},
    {{hi, r9, r8, ASR, 24}, false, al, "hi r9 r8 ASR 24", "hi_r9_r8_ASR_24"},
    {{ls, r14, r8, ASR, 9}, false, al, "ls r14 r8 ASR 9", "ls_r14_r8_ASR_9"},
    {{al, r0, r6, LSR, 1}, false, al, "al r0 r6 LSR 1", "al_r0_r6_LSR_1"},
    {{al, r9, r12, ASR, 32}, false, al, "al r9 r12 ASR 32", "al_r9_r12_ASR_32"},
    {{gt, r8, r14, ASR, 5}, false, al, "gt r8 r14 ASR 5", "gt_r8_r14_ASR_5"},
    {{cc, r6, r13, ASR, 31}, false, al, "cc r6 r13 ASR 31", "cc_r6_r13_ASR_31"},
    {{ne, r2, r14, ASR, 10}, false, al, "ne r2 r14 ASR 10", "ne_r2_r14_ASR_10"},
    {{mi, r0, r11, ASR, 22}, false, al, "mi r0 r11 ASR 22", "mi_r0_r11_ASR_22"},
    {{mi, r1, r5, LSR, 22}, false, al, "mi r1 r5 LSR 22", "mi_r1_r5_LSR_22"},
    {{pl, r5, r1, ASR, 2}, false, al, "pl r5 r1 ASR 2", "pl_r5_r1_ASR_2"},
    {{cs, r6, r13, LSR, 9}, false, al, "cs r6 r13 LSR 9", "cs_r6_r13_LSR_9"},
    {{al, r12, r5, LSR, 12}, false, al, "al r12 r5 LSR 12", "al_r12_r5_LSR_12"},
    {{gt, r6, r12, ASR, 2}, false, al, "gt r6 r12 ASR 2", "gt_r6_r12_ASR_2"},
    {{eq, r4, r0, LSR, 24}, false, al, "eq r4 r0 LSR 24", "eq_r4_r0_LSR_24"},
    {{ls, r5, r6, LSR, 32}, false, al, "ls r5 r6 LSR 32", "ls_r5_r6_LSR_32"},
    {{mi, r13, r7, ASR, 24}, false, al, "mi r13 r7 ASR 24", "mi_r13_r7_ASR_24"},
    {{ge, r8, r6, ASR, 26}, false, al, "ge r8 r6 ASR 26", "ge_r8_r6_ASR_26"},
    {{eq, r5, r1, ASR, 24}, false, al, "eq r5 r1 ASR 24", "eq_r5_r1_ASR_24"},
    {{al, r13, r2, ASR, 6}, false, al, "al r13 r2 ASR 6", "al_r13_r2_ASR_6"},
    {{mi, r0, r2, ASR, 15}, false, al, "mi r0 r2 ASR 15", "mi_r0_r2_ASR_15"},
    {{lt, r7, r13, ASR, 8}, false, al, "lt r7 r13 ASR 8", "lt_r7_r13_ASR_8"},
    {{cs, r7, r12, ASR, 27}, false, al, "cs r7 r12 ASR 27", "cs_r7_r12_ASR_27"},
    {{ls, r9, r1, ASR, 27}, false, al, "ls r9 r1 ASR 27", "ls_r9_r1_ASR_27"},
    {{ne, r14, r7, ASR, 18}, false, al, "ne r14 r7 ASR 18", "ne_r14_r7_ASR_18"},
    {{cc, r5, r14, LSR, 28}, false, al, "cc r5 r14 LSR 28", "cc_r5_r14_LSR_28"},
    {{vs, r0, r8, ASR, 14}, false, al, "vs r0 r8 ASR 14", "vs_r0_r8_ASR_14"},
    {{gt, r3, r7, ASR, 1}, false, al, "gt r3 r7 ASR 1", "gt_r3_r7_ASR_1"},
    {{pl, r8, r6, ASR, 18}, false, al, "pl r8 r6 ASR 18", "pl_r8_r6_ASR_18"},
    {{vc, r14, r5, ASR, 4}, false, al, "vc r14 r5 ASR 4", "vc_r14_r5_ASR_4"},
    {{vc, r7, r5, LSR, 9}, false, al, "vc r7 r5 LSR 9", "vc_r7_r5_LSR_9"},
    {{vs, r8, r1, LSR, 15}, false, al, "vs r8 r1 LSR 15", "vs_r8_r1_LSR_15"},
    {{ge, r12, r13, ASR, 21},
     false,
     al,
     "ge r12 r13 ASR 21",
     "ge_r12_r13_ASR_21"},
    {{vs, r8, r3, ASR, 8}, false, al, "vs r8 r3 ASR 8", "vs_r8_r3_ASR_8"},
    {{al, r0, r3, ASR, 8}, false, al, "al r0 r3 ASR 8", "al_r0_r3_ASR_8"},
    {{vs, r9, r7, LSR, 13}, false, al, "vs r9 r7 LSR 13", "vs_r9_r7_LSR_13"},
    {{al, r7, r6, LSR, 31}, false, al, "al r7 r6 LSR 31", "al_r7_r6_LSR_31"},
    {{lt, r8, r1, ASR, 14}, false, al, "lt r8 r1 ASR 14", "lt_r8_r1_ASR_14"},
    {{ne, r10, r13, ASR, 10},
     false,
     al,
     "ne r10 r13 ASR 10",
     "ne_r10_r13_ASR_10"},
    {{ls, r7, r14, ASR, 22}, false, al, "ls r7 r14 ASR 22", "ls_r7_r14_ASR_22"},
    {{vs, r10, r4, LSR, 9}, false, al, "vs r10 r4 LSR 9", "vs_r10_r4_LSR_9"},
    {{eq, r0, r5, ASR, 6}, false, al, "eq r0 r5 ASR 6", "eq_r0_r5_ASR_6"},
    {{vc, r1, r13, LSR, 27}, false, al, "vc r1 r13 LSR 27", "vc_r1_r13_LSR_27"},
    {{vc, r1, r13, ASR, 19}, false, al, "vc r1 r13 ASR 19", "vc_r1_r13_ASR_19"},
    {{mi, r11, r7, ASR, 27}, false, al, "mi r11 r7 ASR 27", "mi_r11_r7_ASR_27"},
    {{hi, r6, r0, ASR, 18}, false, al, "hi r6 r0 ASR 18", "hi_r6_r0_ASR_18"},
    {{vs, r12, r13, ASR, 22},
     false,
     al,
     "vs r12 r13 ASR 22",
     "vs_r12_r13_ASR_22"},
    {{vc, r0, r14, LSR, 23}, false, al, "vc r0 r14 LSR 23", "vc_r0_r14_LSR_23"},
    {{mi, r14, r8, LSR, 24}, false, al, "mi r14 r8 LSR 24", "mi_r14_r8_LSR_24"},
    {{mi, r2, r10, LSR, 13}, false, al, "mi r2 r10 LSR 13", "mi_r2_r10_LSR_13"},
    {{ne, r13, r9, LSR, 17}, false, al, "ne r13 r9 LSR 17", "ne_r13_r9_LSR_17"},
    {{cs, r1, r1, ASR, 28}, false, al, "cs r1 r1 ASR 28", "cs_r1_r1_ASR_28"},
    {{eq, r14, r1, LSR, 9}, false, al, "eq r14 r1 LSR 9", "eq_r14_r1_LSR_9"},
    {{gt, r7, r11, LSR, 5}, false, al, "gt r7 r11 LSR 5", "gt_r7_r11_LSR_5"},
    {{le, r4, r13, ASR, 25}, false, al, "le r4 r13 ASR 25", "le_r4_r13_ASR_25"},
    {{eq, r5, r11, LSR, 15}, false, al, "eq r5 r11 LSR 15", "eq_r5_r11_LSR_15"},
    {{mi, r10, r13, ASR, 13},
     false,
     al,
     "mi r10 r13 ASR 13",
     "mi_r10_r13_ASR_13"},
    {{gt, r10, r7, ASR, 32}, false, al, "gt r10 r7 ASR 32", "gt_r10_r7_ASR_32"},
    {{mi, r2, r12, ASR, 31}, false, al, "mi r2 r12 ASR 31", "mi_r2_r12_ASR_31"},
    {{gt, r8, r14, ASR, 31}, false, al, "gt r8 r14 ASR 31", "gt_r8_r14_ASR_31"},
    {{hi, r6, r8, ASR, 4}, false, al, "hi r6 r8 ASR 4", "hi_r6_r8_ASR_4"},
    {{ne, r5, r12, ASR, 23}, false, al, "ne r5 r12 ASR 23", "ne_r5_r12_ASR_23"},
    {{eq, r4, r10, ASR, 13}, false, al, "eq r4 r10 ASR 13", "eq_r4_r10_ASR_13"},
    {{ls, r11, r12, LSR, 21},
     false,
     al,
     "ls r11 r12 LSR 21",
     "ls_r11_r12_LSR_21"},
    {{mi, r8, r3, ASR, 29}, false, al, "mi r8 r3 ASR 29", "mi_r8_r3_ASR_29"},
    {{ls, r0, r13, LSR, 16}, false, al, "ls r0 r13 LSR 16", "ls_r0_r13_LSR_16"},
    {{mi, r12, r7, LSR, 22}, false, al, "mi r12 r7 LSR 22", "mi_r12_r7_LSR_22"},
    {{eq, r4, r14, LSR, 19}, false, al, "eq r4 r14 LSR 19", "eq_r4_r14_LSR_19"},
    {{ge, r3, r7, LSR, 4}, false, al, "ge r3 r7 LSR 4", "ge_r3_r7_LSR_4"},
    {{ge, r10, r10, LSR, 5}, false, al, "ge r10 r10 LSR 5", "ge_r10_r10_LSR_5"},
    {{vc, r13, r8, LSR, 30}, false, al, "vc r13 r8 LSR 30", "vc_r13_r8_LSR_30"},
    {{mi, r2, r14, LSR, 8}, false, al, "mi r2 r14 LSR 8", "mi_r2_r14_LSR_8"},
    {{hi, r14, r11, ASR, 20},
     false,
     al,
     "hi r14 r11 ASR 20",
     "hi_r14_r11_ASR_20"},
    {{ge, r13, r6, LSR, 16}, false, al, "ge r13 r6 LSR 16", "ge_r13_r6_LSR_16"},
    {{vs, r5, r0, LSR, 16}, false, al, "vs r5 r0 LSR 16", "vs_r5_r0_LSR_16"},
    {{cc, r6, r1, LSR, 23}, false, al, "cc r6 r1 LSR 23", "cc_r6_r1_LSR_23"},
    {{mi, r14, r12, LSR, 16},
     false,
     al,
     "mi r14 r12 LSR 16",
     "mi_r14_r12_LSR_16"},
    {{vs, r1, r9, ASR, 24}, false, al, "vs r1 r9 ASR 24", "vs_r1_r9_ASR_24"},
    {{vs, r9, r4, LSR, 28}, false, al, "vs r9 r4 LSR 28", "vs_r9_r4_LSR_28"},
    {{cc, r12, r10, ASR, 25},
     false,
     al,
     "cc r12 r10 ASR 25",
     "cc_r12_r10_ASR_25"},
    {{lt, r8, r7, LSR, 1}, false, al, "lt r8 r7 LSR 1", "lt_r8_r7_LSR_1"}};

// These headers each contain an array of `TestResult` with the reference output
// values. The reference arrays are names `kReference{mnemonic}`.
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-a32-cmn.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-a32-cmp.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-a32-mov.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-a32-movs.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-a32-mvn.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-a32-mvns.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-a32-teq.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-a32-tst.h"


// The maximum number of errors to report in detail for each test.
const unsigned kErrorReportLimit = 8;

typedef void (MacroAssembler::*Fn)(Condition cond,
                                   Register rd,
                                   const Operand& op);

void TestHelper(Fn instruction,
                const char* mnemonic,
                const TestResult reference[]) {
  unsigned total_error_count = 0;
  MacroAssembler masm(BUF_SIZE);

  masm.UseA32();

  for (unsigned i = 0; i < ARRAY_SIZE(kTests); i++) {
    // Values to pass to the macro-assembler.
    Condition cond = kTests[i].operands.cond;
    Register rd = kTests[i].operands.rd;
    Register rn = kTests[i].operands.rn;
    ShiftType shift = kTests[i].operands.shift;
    uint32_t amount = kTests[i].operands.amount;
    Operand op(rn, shift, amount);

    int32_t start = masm.GetCursorOffset();
    {
      // We never generate more that 4 bytes, as IT instructions are only
      // allowed for narrow encodings.
      AssemblerAccurateScope scope(&masm,
                                   4,
                                   AssemblerAccurateScope::kMaximumSize);
      if (kTests[i].in_it_block) {
        masm.it(kTests[i].it_condition);
      }
      (masm.*instruction)(cond, rd, op);
    }
    int32_t end = masm.GetCursorOffset();

    const byte* result_ptr =
        masm.GetBuffer()->GetOffsetAddress<const byte*>(start);
    VIXL_ASSERT(start < end);
    uint32_t result_size = end - start;

    if (Test::generate_test_trace()) {
      // Print the result bytes.
      printf("const byte kInstruction_%s_%s[] = {\n",
             mnemonic,
             kTests[i].identifier);
      for (uint32_t j = 0; j < result_size; j++) {
        if (j == 0) {
          printf("  0x%02" PRIx8, result_ptr[j]);
        } else {
          printf(", 0x%02" PRIx8, result_ptr[j]);
        }
      }
      // This comment is meant to be used by external tools to validate
      // the encoding. We can parse the comment to figure out what
      // instruction this corresponds to.
      if (kTests[i].in_it_block) {
        printf(" // It %s; %s %s\n};\n",
               kTests[i].it_condition.GetName(),
               mnemonic,
               kTests[i].operands_description);
      } else {
        printf(" // %s %s\n};\n", mnemonic, kTests[i].operands_description);
      }
    } else {
      // Check we've emitted the exact same encoding as present in the
      // trace file. Only print up to `kErrorReportLimit` errors.
      if (((result_size != reference[i].size) ||
           (memcmp(result_ptr, reference[i].encoding, reference[i].size) !=
            0)) &&
          (++total_error_count <= kErrorReportLimit)) {
        printf("Error when testing \"%s\" with operands \"%s\":\n",
               mnemonic,
               kTests[i].operands_description);
        printf("  Expected: ");
        for (uint32_t j = 0; j < reference[i].size; j++) {
          if (j == 0) {
            printf("0x%02" PRIx8, reference[i].encoding[j]);
          } else {
            printf(", 0x%02" PRIx8, reference[i].encoding[j]);
          }
        }
        printf("\n");
        printf("  Found:    ");
        for (uint32_t j = 0; j < result_size; j++) {
          if (j == 0) {
            printf("0x%02" PRIx8, result_ptr[j]);
          } else {
            printf(", 0x%02" PRIx8, result_ptr[j]);
          }
        }
        printf("\n");
      }
    }
  }

  masm.FinalizeCode();

  if (Test::generate_test_trace()) {
    // Finalize the trace file by writing the final `TestResult` array
    // which links all generated instruction encodings.
    printf("const TestResult kReference%s[] = {\n", mnemonic);
    for (unsigned i = 0; i < ARRAY_SIZE(kTests); i++) {
      printf("  {\n");
      printf("    ARRAY_SIZE(kInstruction_%s_%s),\n",
             mnemonic,
             kTests[i].identifier);
      printf("    kInstruction_%s_%s,\n", mnemonic, kTests[i].identifier);
      printf("  },\n");
    }
    printf("};\n");
  } else {
    if (total_error_count > kErrorReportLimit) {
      printf("%u other errors follow.\n",
             total_error_count - kErrorReportLimit);
    }
    // Crash if the test failed.
    VIXL_CHECK(total_error_count == 0);
  }
}

// Instantiate tests for each instruction in the list.
#define TEST(mnemonic)                                                      \
  void Test_##mnemonic() {                                                  \
    TestHelper(&MacroAssembler::mnemonic, #mnemonic, kReference##mnemonic); \
  }                                                                         \
  Test test_##mnemonic(                                                     \
      "AARCH32_ASSEMBLER_COND_RD_OPERAND_RN_SHIFT_AMOUNT_1TO32_"            \
      "A32_" #mnemonic,                                                     \
      &Test_##mnemonic);
FOREACH_INSTRUCTION(TEST)
#undef TEST

}  // namespace

}  // namespace aarch32
}  // namespace vixl
