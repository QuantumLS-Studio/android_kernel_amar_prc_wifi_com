
#include "nir.h"
#include "nir_builder.h"
#include "nir_search.h"
#include "nir_search_helpers.h"

#ifndef NIR_OPT_ALGEBRAIC_STRUCT_DEFS
#define NIR_OPT_ALGEBRAIC_STRUCT_DEFS

struct transform {
   const nir_search_expression *search;
   const nir_search_value *replace;
   unsigned condition_offset;
};

struct per_op_table {
   const uint16_t *filter;
   unsigned num_filtered_states;
   const uint16_t *table;
};

/* Note: these must match the start states created in
 * TreeAutomaton._build_table()
 */

/* WILDCARD_STATE = 0 is set by zeroing the state array */
static const uint16_t CONST_STATE = 1;

#endif


   static const nir_search_variable search0_0 = {
   { nir_search_value_variable, 32 },
   0, /* a */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search0_1 = {
   { nir_search_value_variable, 32 },
   1, /* b */
   true,
   nir_type_invalid,
   (is_pos_power_of_two),
};
static const nir_search_expression search0 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_imul,
   { &search0_0.value, &search0_1.value },
   NULL,
};

   /* replace0_0 -> search0_0 in the cache */

static const nir_search_variable replace0_1_0 = {
   { nir_search_value_variable, 32 },
   1, /* b */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression replace0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_find_lsb,
   { &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search0_0.value, &replace0_1.value },
   NULL,
};

   /* search1_0 -> search0_0 in the cache */

static const nir_search_variable search1_1 = {
   { nir_search_value_variable, 32 },
   1, /* b */
   true,
   nir_type_invalid,
   (is_neg_power_of_two),
};
static const nir_search_expression search1 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_imul,
   { &search0_0.value, &search1_1.value },
   NULL,
};

   /* replace1_0_0 -> search0_0 in the cache */

/* replace1_0_1_0_0 -> replace0_1_0 in the cache */
static const nir_search_expression replace1_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_iabs,
   { &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace1_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_find_lsb,
   { &replace1_0_1_0.value },
   NULL,
};
static const nir_search_expression replace1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search0_0.value, &replace1_0_1.value },
   NULL,
};
static const nir_search_expression replace1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ineg,
   { &replace1_0.value },
   NULL,
};

   /* search2_0_0 -> search0_0 in the cache */

/* search2_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression search2_0 = {
   { nir_search_value_expression, 64 },
   false,
   0, 1,
   nir_op_imul_2x32_64,
   { &search0_0.value, &replace0_1_0.value },
   (is_used_once),
};
static const nir_search_expression search2 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_unpack_64_2x32_split_x,
   { &search2_0.value },
   NULL,
};

   /* replace2_0 -> search0_0 in the cache */

/* replace2_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace2 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_imul,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* search3_0_0 -> search0_0 in the cache */

/* search3_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression search3_0 = {
   { nir_search_value_expression, 64 },
   false,
   0, 1,
   nir_op_umul_2x32_64,
   { &search0_0.value, &replace0_1_0.value },
   (is_used_once),
};
static const nir_search_expression search3 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_unpack_64_2x32_split_x,
   { &search3_0.value },
   NULL,
};

   /* replace3_0 -> search0_0 in the cache */

/* replace3_1 -> replace0_1_0 in the cache */
/* replace3 -> replace2 in the cache */

   /* search4_0 -> search0_0 in the cache */

/* search4_1 -> replace0_1_0 in the cache */
static const nir_search_expression search4 = {
   { nir_search_value_expression, 64 },
   false,
   0, 1,
   nir_op_imul_2x32_64,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* replace4_0_0 -> search0_0 in the cache */

/* replace4_0_1 -> replace0_1_0 in the cache */
/* replace4_0 -> replace2 in the cache */

/* replace4_1_0 -> search0_0 in the cache */

/* replace4_1_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace4_1 = {
   { nir_search_value_expression, 32 },
   false,
   1, 1,
   nir_op_imul_high,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace4 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 2,
   nir_op_pack_64_2x32_split,
   { &replace2.value, &replace4_1.value },
   NULL,
};

   /* search5_0 -> search0_0 in the cache */

/* search5_1 -> replace0_1_0 in the cache */
static const nir_search_expression search5 = {
   { nir_search_value_expression, 64 },
   false,
   0, 1,
   nir_op_umul_2x32_64,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* replace5_0_0 -> search0_0 in the cache */

/* replace5_0_1 -> replace0_1_0 in the cache */
/* replace5_0 -> replace2 in the cache */

/* replace5_1_0 -> search0_0 in the cache */

/* replace5_1_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace5_1 = {
   { nir_search_value_expression, 32 },
   false,
   1, 1,
   nir_op_umul_high,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace5 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 2,
   nir_op_pack_64_2x32_split,
   { &replace2.value, &replace5_1.value },
   NULL,
};

   static const nir_search_variable search6_0 = {
   { nir_search_value_variable, -1 },
   0, /* a */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_constant search6_1 = {
   { nir_search_value_constant, -1 },
   nir_type_int, { 0x1 /* 1 */ },
};
static const nir_search_expression search6 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_udiv,
   { &search6_0.value, &search6_1.value },
   NULL,
};

   /* replace6 -> search6_0 in the cache */

   /* search7_0 -> search6_0 in the cache */

/* search7_1 -> search6_1 in the cache */
static const nir_search_expression search7 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_idiv,
   { &search6_0.value, &search6_1.value },
   NULL,
};

   /* replace7 -> search6_0 in the cache */

   /* search8_0 -> search6_0 in the cache */

/* search8_1 -> search6_1 in the cache */
static const nir_search_expression search8 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_umod,
   { &search6_0.value, &search6_1.value },
   NULL,
};

   static const nir_search_constant replace8 = {
   { nir_search_value_constant, -1 },
   nir_type_int, { 0x0 /* 0 */ },
};

   /* search9_0 -> search6_0 in the cache */

/* search9_1 -> search6_1 in the cache */
static const nir_search_expression search9 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_imod,
   { &search6_0.value, &search6_1.value },
   NULL,
};

   /* replace9 -> replace8 in the cache */

   /* search10_0 -> search0_0 in the cache */

/* search10_1 -> search0_1 in the cache */
static const nir_search_expression search10 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_udiv,
   { &search0_0.value, &search0_1.value },
   NULL,
};

   /* replace10_0 -> search0_0 in the cache */

/* replace10_1_0 -> replace0_1_0 in the cache */
/* replace10_1 -> replace0_1 in the cache */
static const nir_search_expression replace10 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search0_0.value, &replace0_1.value },
   NULL,
};

   /* search11_0 -> search0_0 in the cache */

/* search11_1 -> search0_1 in the cache */
static const nir_search_expression search11 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_idiv,
   { &search0_0.value, &search0_1.value },
   NULL,
};

   /* replace11_0_0 -> search0_0 in the cache */
static const nir_search_expression replace11_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_isign,
   { &search0_0.value },
   NULL,
};

/* replace11_1_0_0 -> search0_0 in the cache */
static const nir_search_expression replace11_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_iabs,
   { &search0_0.value },
   NULL,
};

/* replace11_1_1_0 -> replace0_1_0 in the cache */
/* replace11_1_1 -> replace0_1 in the cache */
static const nir_search_expression replace11_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ushr,
   { &replace11_1_0.value, &replace0_1.value },
   NULL,
};
static const nir_search_expression replace11 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_imul,
   { &replace11_0.value, &replace11_1.value },
   NULL,
};

   /* search12_0 -> search0_0 in the cache */

/* search12_1 -> search1_1 in the cache */
static const nir_search_expression search12 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_idiv,
   { &search0_0.value, &search1_1.value },
   NULL,
};

   /* replace12_0_0_0 -> search0_0 in the cache */
/* replace12_0_0 -> replace11_0 in the cache */

/* replace12_0_1_0_0 -> search0_0 in the cache */
/* replace12_0_1_0 -> replace11_1_0 in the cache */

/* replace12_0_1_1_0_0 -> replace0_1_0 in the cache */
/* replace12_0_1_1_0 -> replace1_0_1_0 in the cache */
/* replace12_0_1_1 -> replace1_0_1 in the cache */
static const nir_search_expression replace12_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ushr,
   { &replace11_1_0.value, &replace1_0_1.value },
   NULL,
};
static const nir_search_expression replace12_0 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_imul,
   { &replace11_0.value, &replace12_0_1.value },
   NULL,
};
static const nir_search_expression replace12 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_ineg,
   { &replace12_0.value },
   NULL,
};

   static const nir_search_variable search13_0 = {
   { nir_search_value_variable, -2 },
   0, /* a */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search13_1 = {
   { nir_search_value_variable, -2 },
   1, /* b */
   true,
   nir_type_invalid,
   (is_pos_power_of_two),
};
static const nir_search_expression search13 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_umod,
   { &search13_0.value, &search13_1.value },
   NULL,
};

   /* replace13_0 -> search13_0 in the cache */

static const nir_search_variable replace13_1_0 = {
   { nir_search_value_variable, -2 },
   1, /* b */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_constant replace13_1_1 = {
   { nir_search_value_constant, -2 },
   nir_type_int, { 0x1 /* 1 */ },
};
static const nir_search_expression replace13_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_isub,
   { &replace13_1_0.value, &replace13_1_1.value },
   NULL,
};
static const nir_search_expression replace13 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_iand,
   { &search13_0.value, &replace13_1.value },
   NULL,
};

   /* search14_0_0 -> search6_0 in the cache */
static const nir_search_expression search14_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search14 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search14_0.value },
   NULL,
};

   /* replace14 -> search6_0 in the cache */

   /* search15_0_0 -> search6_0 in the cache */
static const nir_search_expression search15_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search15 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search15_0.value },
   NULL,
};

   /* replace15 -> search6_0 in the cache */

   /* search16_0_0 -> search6_0 in the cache */
static const nir_search_expression search16_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fabs,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search16 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fabs,
   { &search16_0.value },
   NULL,
};

   /* replace16_0 -> search6_0 in the cache */
/* replace16 -> search16_0 in the cache */

   /* search17_0_0 -> search6_0 in the cache */
/* search17_0 -> search14_0 in the cache */
static const nir_search_expression search17 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fabs,
   { &search14_0.value },
   NULL,
};

   /* replace17_0 -> search6_0 in the cache */
/* replace17 -> search16_0 in the cache */

   /* search18_0_0 -> search6_0 in the cache */
static const nir_search_expression search18_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_u2f,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search18 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_fabs,
   { &search18_0.value },
   NULL,
};

   /* replace18_0 -> search6_0 in the cache */
/* replace18 -> search18_0 in the cache */

   /* search19_0_0 -> search6_0 in the cache */
static const nir_search_expression search19_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_iabs,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search19 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_iabs,
   { &search19_0.value },
   NULL,
};

   /* replace19_0 -> search6_0 in the cache */
/* replace19 -> search19_0 in the cache */

   /* search20_0_0 -> search6_0 in the cache */
/* search20_0 -> search15_0 in the cache */
static const nir_search_expression search20 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_iabs,
   { &search15_0.value },
   NULL,
};

   /* replace20_0 -> search6_0 in the cache */
/* replace20 -> search19_0 in the cache */

   /* search21_0_0 -> search6_0 in the cache */
/* search21_0 -> search14_0 in the cache */
static const nir_search_expression search21 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_f2b,
   { &search14_0.value },
   NULL,
};

   /* replace21_0 -> search6_0 in the cache */
static const nir_search_expression replace21 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_f2b,
   { &search6_0.value },
   NULL,
};

   /* search22_0_0 -> search6_0 in the cache */
/* search22_0 -> search15_0 in the cache */
static const nir_search_expression search22 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_i2b,
   { &search15_0.value },
   NULL,
};

   /* replace22_0 -> search6_0 in the cache */
static const nir_search_expression replace22 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_i2b,
   { &search6_0.value },
   NULL,
};

   /* search23_0 -> search6_0 in the cache */

static const nir_search_constant search23_1 = {
   { nir_search_value_constant, -1 },
   nir_type_float, { 0x0 /* 0.0 */ },
};
static const nir_search_expression search23 = {
   { nir_search_value_expression, -1 },
   true,
   0, 1,
   nir_op_fadd,
   { &search6_0.value, &search23_1.value },
   NULL,
};

   /* replace23 -> search6_0 in the cache */

   /* search24_0 -> search6_0 in the cache */

/* search24_1 -> replace8 in the cache */
static const nir_search_expression search24 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_iadd,
   { &search6_0.value, &replace8.value },
   NULL,
};

   /* replace24 -> search6_0 in the cache */

   /* search25_0 -> search0_0 in the cache */

static const nir_search_constant search25_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x0 /* 0 */ },
};
static const nir_search_expression search25 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_usadd_4x8,
   { &search0_0.value, &search25_1.value },
   NULL,
};

   /* replace25 -> search0_0 in the cache */

   /* search26_0 -> search0_0 in the cache */

static const nir_search_constant search26_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { -0x1 /* -1 */ },
};
static const nir_search_expression search26 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_usadd_4x8,
   { &search0_0.value, &search26_1.value },
   NULL,
};

   /* replace26 -> search26_1 in the cache */

   static const nir_search_variable search27_0_0 = {
   { nir_search_value_variable, -3 },
   0, /* a */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search27_0_1 = {
   { nir_search_value_variable, -3 },
   1, /* b */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search27_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_fmul,
   { &search27_0_0.value, &search27_0_1.value },
   NULL,
};

/* search27_1_0 -> search27_0_0 in the cache */

static const nir_search_variable search27_1_1 = {
   { nir_search_value_variable, -3 },
   2, /* c */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search27_1 = {
   { nir_search_value_expression, -3 },
   false,
   2, 1,
   nir_op_fmul,
   { &search27_0_0.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression search27 = {
   { nir_search_value_expression, -3 },
   true,
   0, 3,
   nir_op_fadd,
   { &search27_0.value, &search27_1.value },
   NULL,
};

   /* replace27_0 -> search27_0_0 in the cache */

/* replace27_1_0 -> search27_0_1 in the cache */

/* replace27_1_1 -> search27_1_1 in the cache */
static const nir_search_expression replace27_1 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_fadd,
   { &search27_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression replace27 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_fmul,
   { &search27_0_0.value, &replace27_1.value },
   NULL,
};

   /* search28_0_0 -> search27_0_0 in the cache */

/* search28_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search28_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_imul,
   { &search27_0_0.value, &search27_0_1.value },
   NULL,
};

/* search28_1_0 -> search27_0_0 in the cache */

/* search28_1_1 -> search27_1_1 in the cache */
static const nir_search_expression search28_1 = {
   { nir_search_value_expression, -3 },
   false,
   2, 1,
   nir_op_imul,
   { &search27_0_0.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression search28 = {
   { nir_search_value_expression, -3 },
   false,
   0, 3,
   nir_op_iadd,
   { &search28_0.value, &search28_1.value },
   NULL,
};

   /* replace28_0 -> search27_0_0 in the cache */

/* replace28_1_0 -> search27_0_1 in the cache */

/* replace28_1_1 -> search27_1_1 in the cache */
static const nir_search_expression replace28_1 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_iadd,
   { &search27_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression replace28 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_imul,
   { &search27_0_0.value, &replace28_1.value },
   NULL,
};

   /* search29_0_0 -> search6_0 in the cache */
/* search29_0 -> search14_0 in the cache */

/* search29_1 -> search6_0 in the cache */
static const nir_search_expression search29 = {
   { nir_search_value_expression, -1 },
   true,
   0, 1,
   nir_op_fadd,
   { &search14_0.value, &search6_0.value },
   NULL,
};

   /* replace29 -> search23_1 in the cache */

   /* search30_0_0 -> search6_0 in the cache */
/* search30_0 -> search15_0 in the cache */

/* search30_1 -> search6_0 in the cache */
static const nir_search_expression search30 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_iadd,
   { &search15_0.value, &search6_0.value },
   NULL,
};

   /* replace30 -> replace8 in the cache */

   /* search31_0_0 -> search13_0 in the cache */
static const nir_search_expression search31_0 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search13_0.value },
   NULL,
};

/* search31_1_0 -> search13_0 in the cache */

/* search31_1_1 -> replace13_1_0 in the cache */
static const nir_search_expression search31_1 = {
   { nir_search_value_expression, -2 },
   false,
   1, 1,
   nir_op_iadd,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search31 = {
   { nir_search_value_expression, -2 },
   false,
   0, 2,
   nir_op_iadd,
   { &search31_0.value, &search31_1.value },
   NULL,
};

   /* replace31 -> replace13_1_0 in the cache */

   /* search32_0 -> search13_0 in the cache */

/* search32_1_0_0 -> search13_0 in the cache */
/* search32_1_0 -> search31_0 in the cache */

/* search32_1_1 -> replace13_1_0 in the cache */
static const nir_search_expression search32_1 = {
   { nir_search_value_expression, -2 },
   false,
   1, 1,
   nir_op_iadd,
   { &search31_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search32 = {
   { nir_search_value_expression, -2 },
   false,
   0, 2,
   nir_op_iadd,
   { &search13_0.value, &search32_1.value },
   NULL,
};

   /* replace32 -> replace13_1_0 in the cache */

   /* search33_0_0 -> search13_0 in the cache */
static const nir_search_expression search33_0 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search13_0.value },
   NULL,
};

/* search33_1_0 -> search13_0 in the cache */

/* search33_1_1 -> replace13_1_0 in the cache */
static const nir_search_expression search33_1 = {
   { nir_search_value_expression, -2 },
   false,
   1, 1,
   nir_op_fadd,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search33 = {
   { nir_search_value_expression, -2 },
   true,
   0, 2,
   nir_op_fadd,
   { &search33_0.value, &search33_1.value },
   NULL,
};

   /* replace33 -> replace13_1_0 in the cache */

   /* search34_0 -> search13_0 in the cache */

/* search34_1_0_0 -> search13_0 in the cache */
/* search34_1_0 -> search33_0 in the cache */

/* search34_1_1 -> replace13_1_0 in the cache */
static const nir_search_expression search34_1 = {
   { nir_search_value_expression, -2 },
   false,
   1, 1,
   nir_op_fadd,
   { &search33_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search34 = {
   { nir_search_value_expression, -2 },
   true,
   0, 2,
   nir_op_fadd,
   { &search13_0.value, &search34_1.value },
   NULL,
};

   /* replace34 -> replace13_1_0 in the cache */

   /* search35_0 -> search6_0 in the cache */

/* search35_1 -> search23_1 in the cache */
static const nir_search_expression search35 = {
   { nir_search_value_expression, -1 },
   true,
   0, 1,
   nir_op_fmul,
   { &search6_0.value, &search23_1.value },
   NULL,
};

   /* replace35 -> search23_1 in the cache */

   /* search36_0 -> search6_0 in the cache */

/* search36_1 -> replace8 in the cache */
static const nir_search_expression search36 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_imul,
   { &search6_0.value, &replace8.value },
   NULL,
};

   /* replace36 -> replace8 in the cache */

   /* search37_0 -> search0_0 in the cache */

/* search37_1 -> search25_1 in the cache */
static const nir_search_expression search37 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_umul_unorm_4x8,
   { &search0_0.value, &search25_1.value },
   NULL,
};

   /* replace37 -> search25_1 in the cache */

   /* search38_0 -> search0_0 in the cache */

/* search38_1 -> search26_1 in the cache */
static const nir_search_expression search38 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_umul_unorm_4x8,
   { &search0_0.value, &search26_1.value },
   NULL,
};

   /* replace38 -> search0_0 in the cache */

   /* search39_0 -> search6_0 in the cache */

static const nir_search_constant search39_1 = {
   { nir_search_value_constant, -1 },
   nir_type_float, { 0x3ff0000000000000 /* 1.0 */ },
};
static const nir_search_expression search39 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_fmul,
   { &search6_0.value, &search39_1.value },
   NULL,
};

   /* replace39 -> search6_0 in the cache */

   /* search40_0 -> search6_0 in the cache */

/* search40_1 -> search6_1 in the cache */
static const nir_search_expression search40 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_imul,
   { &search6_0.value, &search6_1.value },
   NULL,
};

   /* replace40 -> search6_0 in the cache */

   /* search41_0 -> search6_0 in the cache */

static const nir_search_constant search41_1 = {
   { nir_search_value_constant, -1 },
   nir_type_float, { 0xbff0000000000000L /* -1.0 */ },
};
static const nir_search_expression search41 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_fmul,
   { &search6_0.value, &search41_1.value },
   NULL,
};

   /* replace41_0 -> search6_0 in the cache */
/* replace41 -> search14_0 in the cache */

   /* search42_0 -> search6_0 in the cache */

static const nir_search_constant search42_1 = {
   { nir_search_value_constant, -1 },
   nir_type_int, { -0x1 /* -1 */ },
};
static const nir_search_expression search42 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_imul,
   { &search6_0.value, &search42_1.value },
   NULL,
};

   /* replace42_0 -> search6_0 in the cache */
/* replace42 -> search15_0 in the cache */

   /* search43_0_0 -> search6_0 in the cache */
static const nir_search_expression search43_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fsign,
   { &search6_0.value },
   NULL,
};

/* search43_1_0 -> search6_0 in the cache */

/* search43_1_1 -> search6_0 in the cache */
static const nir_search_expression search43_1 = {
   { nir_search_value_expression, -1 },
   false,
   1, 1,
   nir_op_fmul,
   { &search6_0.value, &search6_0.value },
   NULL,
};
static const nir_search_expression search43 = {
   { nir_search_value_expression, -1 },
   false,
   0, 2,
   nir_op_fmul,
   { &search43_0.value, &search43_1.value },
   NULL,
};

   /* replace43_0_0 -> search6_0 in the cache */
/* replace43_0 -> search16_0 in the cache */

/* replace43_1 -> search6_0 in the cache */
static const nir_search_expression replace43 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_fmul,
   { &search16_0.value, &search6_0.value },
   NULL,
};

   /* search44_0_0_0 -> search6_0 in the cache */
/* search44_0_0 -> search43_0 in the cache */

/* search44_0_1 -> search6_0 in the cache */
static const nir_search_expression search44_0 = {
   { nir_search_value_expression, -1 },
   false,
   1, 1,
   nir_op_fmul,
   { &search43_0.value, &search6_0.value },
   NULL,
};

/* search44_1 -> search6_0 in the cache */
static const nir_search_expression search44 = {
   { nir_search_value_expression, -1 },
   false,
   0, 2,
   nir_op_fmul,
   { &search44_0.value, &search6_0.value },
   NULL,
};

   /* replace44_0_0 -> search6_0 in the cache */
/* replace44_0 -> search16_0 in the cache */

/* replace44_1 -> search6_0 in the cache */
/* replace44 -> replace43 in the cache */

   static const nir_search_constant search45_0 = {
   { nir_search_value_constant, -2 },
   nir_type_float, { 0x0 /* 0.0 */ },
};

/* search45_1 -> search13_0 in the cache */

/* search45_2 -> replace13_1_0 in the cache */
static const nir_search_expression search45 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_ffma,
   { &search45_0.value, &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace45 -> replace13_1_0 in the cache */

   /* search46_0 -> search13_0 in the cache */

/* search46_1 -> search45_0 in the cache */

/* search46_2 -> replace13_1_0 in the cache */
static const nir_search_expression search46 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_ffma,
   { &search13_0.value, &search45_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace46 -> replace13_1_0 in the cache */

   /* search47_0 -> search13_0 in the cache */

/* search47_1 -> replace13_1_0 in the cache */

/* search47_2 -> search45_0 in the cache */
static const nir_search_expression search47 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_ffma,
   { &search13_0.value, &replace13_1_0.value, &search45_0.value },
   NULL,
};

   /* replace47_0 -> search13_0 in the cache */

/* replace47_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace47 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_fmul,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search48_0 -> search13_0 in the cache */

static const nir_search_constant search48_1 = {
   { nir_search_value_constant, -2 },
   nir_type_float, { 0x3ff0000000000000 /* 1.0 */ },
};

/* search48_2 -> replace13_1_0 in the cache */
static const nir_search_expression search48 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_ffma,
   { &search13_0.value, &search48_1.value, &replace13_1_0.value },
   NULL,
};

   /* replace48_0 -> search13_0 in the cache */

/* replace48_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace48 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_fadd,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search49_0 -> search48_1 in the cache */

/* search49_1 -> search13_0 in the cache */

/* search49_2 -> replace13_1_0 in the cache */
static const nir_search_expression search49 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_ffma,
   { &search48_1.value, &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace49_0 -> search13_0 in the cache */

/* replace49_1 -> replace13_1_0 in the cache */
/* replace49 -> replace48 in the cache */

   /* search50_0 -> search13_0 in the cache */

/* search50_1 -> replace13_1_0 in the cache */

/* search50_2 -> search45_0 in the cache */
static const nir_search_expression search50 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_flrp,
   { &search13_0.value, &replace13_1_0.value, &search45_0.value },
   NULL,
};

   /* replace50 -> search13_0 in the cache */

   /* search51_0 -> search13_0 in the cache */

/* search51_1 -> replace13_1_0 in the cache */

/* search51_2 -> search48_1 in the cache */
static const nir_search_expression search51 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_flrp,
   { &search13_0.value, &replace13_1_0.value, &search48_1.value },
   NULL,
};

   /* replace51 -> replace13_1_0 in the cache */

   /* search52_0 -> search13_0 in the cache */

/* search52_1 -> search13_0 in the cache */

/* search52_2 -> replace13_1_0 in the cache */
static const nir_search_expression search52 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_flrp,
   { &search13_0.value, &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace52 -> search13_0 in the cache */

   /* search53_0 -> search45_0 in the cache */

/* search53_1 -> search13_0 in the cache */

/* search53_2 -> replace13_1_0 in the cache */
static const nir_search_expression search53 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_flrp,
   { &search45_0.value, &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace53_0 -> search13_0 in the cache */

/* replace53_1 -> replace13_1_0 in the cache */
/* replace53 -> replace47 in the cache */

   /* search54_0 -> search13_0 in the cache */

/* search54_1 -> replace13_1_0 in the cache */

static const nir_search_variable search54_2_0 = {
   { nir_search_value_variable, 1 },
   2, /* c */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search54_2 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &search54_2_0.value },
   NULL,
};
static const nir_search_expression search54 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_flrp,
   { &search13_0.value, &replace13_1_0.value, &search54_2.value },
   NULL,
};

   /* replace54_0 -> search54_2_0 in the cache */

/* replace54_1 -> replace13_1_0 in the cache */

/* replace54_2 -> search13_0 in the cache */
static const nir_search_expression replace54 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search54_2_0.value, &replace13_1_0.value, &search13_0.value },
   NULL,
};

   /* search55_0 -> search13_0 in the cache */

/* search55_1 -> search45_0 in the cache */

static const nir_search_variable search55_2 = {
   { nir_search_value_variable, -2 },
   1, /* c */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search55 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_flrp,
   { &search13_0.value, &search45_0.value, &search55_2.value },
   NULL,
};

   /* replace55_0_0_0 -> search13_0 in the cache */
/* replace55_0_0 -> search33_0 in the cache */

/* replace55_0_1 -> search55_2 in the cache */
static const nir_search_expression replace55_0 = {
   { nir_search_value_expression, -2 },
   false,
   1, 1,
   nir_op_fmul,
   { &search33_0.value, &search55_2.value },
   NULL,
};

/* replace55_1 -> search13_0 in the cache */
static const nir_search_expression replace55 = {
   { nir_search_value_expression, -2 },
   false,
   0, 2,
   nir_op_fadd,
   { &replace55_0.value, &search13_0.value },
   NULL,
};

   static const nir_search_variable search56_0 = {
   { nir_search_value_variable, 16 },
   0, /* a */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search56_1 = {
   { nir_search_value_variable, 16 },
   1, /* b */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search56_2 = {
   { nir_search_value_variable, 16 },
   2, /* c */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search56 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_flrp,
   { &search56_0.value, &search56_1.value, &search56_2.value },
   NULL,
};

   /* replace56_0_0 -> search56_2 in the cache */

/* replace56_0_1_0 -> search56_1 in the cache */

/* replace56_0_1_1 -> search56_0 in the cache */
static const nir_search_expression replace56_0_1 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_fsub,
   { &search56_1.value, &search56_0.value },
   NULL,
};
static const nir_search_expression replace56_0 = {
   { nir_search_value_expression, 16 },
   false,
   1, 1,
   nir_op_fmul,
   { &search56_2.value, &replace56_0_1.value },
   NULL,
};

/* replace56_1 -> search56_0 in the cache */
static const nir_search_expression replace56 = {
   { nir_search_value_expression, 16 },
   false,
   0, 2,
   nir_op_fadd,
   { &replace56_0.value, &search56_0.value },
   NULL,
};

   /* search57_0 -> search0_0 in the cache */

/* search57_1 -> replace0_1_0 in the cache */

static const nir_search_variable search57_2 = {
   { nir_search_value_variable, 32 },
   2, /* c */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search57 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_flrp,
   { &search0_0.value, &replace0_1_0.value, &search57_2.value },
   NULL,
};

   /* replace57_0_0 -> search57_2 in the cache */

/* replace57_0_1_0 -> replace0_1_0 in the cache */

/* replace57_0_1_1 -> search0_0 in the cache */
static const nir_search_expression replace57_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fsub,
   { &replace0_1_0.value, &search0_0.value },
   NULL,
};
static const nir_search_expression replace57_0 = {
   { nir_search_value_expression, 32 },
   false,
   1, 1,
   nir_op_fmul,
   { &search57_2.value, &replace57_0_1.value },
   NULL,
};

/* replace57_1 -> search0_0 in the cache */
static const nir_search_expression replace57 = {
   { nir_search_value_expression, 32 },
   false,
   0, 2,
   nir_op_fadd,
   { &replace57_0.value, &search0_0.value },
   NULL,
};

   static const nir_search_variable search58_0 = {
   { nir_search_value_variable, 64 },
   0, /* a */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search58_1 = {
   { nir_search_value_variable, 64 },
   1, /* b */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search58_2 = {
   { nir_search_value_variable, 64 },
   2, /* c */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search58 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_flrp,
   { &search58_0.value, &search58_1.value, &search58_2.value },
   NULL,
};

   /* replace58_0_0 -> search58_2 in the cache */

/* replace58_0_1_0 -> search58_1 in the cache */

/* replace58_0_1_1 -> search58_0 in the cache */
static const nir_search_expression replace58_0_1 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_fsub,
   { &search58_1.value, &search58_0.value },
   NULL,
};
static const nir_search_expression replace58_0 = {
   { nir_search_value_expression, 64 },
   false,
   1, 1,
   nir_op_fmul,
   { &search58_2.value, &replace58_0_1.value },
   NULL,
};

/* replace58_1 -> search58_0 in the cache */
static const nir_search_expression replace58 = {
   { nir_search_value_expression, 64 },
   false,
   0, 2,
   nir_op_fadd,
   { &replace58_0.value, &search58_0.value },
   NULL,
};

   /* search59_0 -> search6_0 in the cache */
static const nir_search_expression search59 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ftrunc,
   { &search6_0.value },
   NULL,
};

   /* replace59_0_0 -> search6_0 in the cache */

/* replace59_0_1 -> search23_1 in the cache */
static const nir_search_expression replace59_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search6_0.value, &search23_1.value },
   NULL,
};

/* replace59_1_0_0_0 -> search6_0 in the cache */
/* replace59_1_0_0 -> search16_0 in the cache */
static const nir_search_expression replace59_1_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ffloor,
   { &search16_0.value },
   NULL,
};
static const nir_search_expression replace59_1 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fneg,
   { &replace59_1_0.value },
   NULL,
};

/* replace59_2_0_0 -> search6_0 in the cache */
/* replace59_2_0 -> search16_0 in the cache */
/* replace59_2 -> replace59_1_0 in the cache */
static const nir_search_expression replace59 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace59_0.value, &replace59_1.value, &replace59_1_0.value },
   NULL,
};

   /* search60_0 -> search6_0 in the cache */
static const nir_search_expression search60 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ffloor,
   { &search6_0.value },
   NULL,
};

   /* replace60_0 -> search6_0 in the cache */

/* replace60_1_0 -> search6_0 in the cache */
static const nir_search_expression replace60_1 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ffract,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression replace60 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fsub,
   { &search6_0.value, &replace60_1.value },
   NULL,
};

   /* search61_0 -> search6_0 in the cache */

/* search61_1_0_0 -> search6_0 in the cache */
/* search61_1_0 -> replace60_1 in the cache */
static const nir_search_expression search61_1 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fneg,
   { &replace60_1.value },
   NULL,
};
static const nir_search_expression search61 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_fadd,
   { &search6_0.value, &search61_1.value },
   NULL,
};

   /* replace61_0 -> search6_0 in the cache */
/* replace61 -> search60 in the cache */

   /* search62_0 -> search6_0 in the cache */
/* search62 -> replace60_1 in the cache */

   /* replace62_0 -> search6_0 in the cache */

/* replace62_1_0 -> search6_0 in the cache */
/* replace62_1 -> search60 in the cache */
static const nir_search_expression replace62 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fsub,
   { &search6_0.value, &search60.value },
   NULL,
};

   /* search63_0 -> search6_0 in the cache */
static const nir_search_expression search63 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fceil,
   { &search6_0.value },
   NULL,
};

   /* replace63_0_0_0 -> search6_0 in the cache */
/* replace63_0_0 -> search14_0 in the cache */
static const nir_search_expression replace63_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ffloor,
   { &search14_0.value },
   NULL,
};
static const nir_search_expression replace63 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fneg,
   { &replace63_0.value },
   NULL,
};

   /* search64_0_0 -> search27_0_0 in the cache */

static const nir_search_constant search64_0_1_0 = {
   { nir_search_value_constant, -3 },
   nir_type_float, { 0x3ff0000000000000 /* 1.0 */ },
};

static const nir_search_variable search64_0_1_1_0_0 = {
   { nir_search_value_variable, 1 },
   1, /* c */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search64_0_1_1_0 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &search64_0_1_1_0_0.value },
   NULL,
};
static const nir_search_expression search64_0_1_1 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search64_0_1_1_0.value },
   NULL,
};
static const nir_search_expression search64_0_1 = {
   { nir_search_value_expression, -3 },
   false,
   2, 1,
   nir_op_fadd,
   { &search64_0_1_0.value, &search64_0_1_1.value },
   NULL,
};
static const nir_search_expression search64_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 2,
   nir_op_fmul,
   { &search27_0_0.value, &search64_0_1.value },
   NULL,
};

static const nir_search_variable search64_1_0 = {
   { nir_search_value_variable, -3 },
   2, /* b */
   false,
   nir_type_invalid,
   NULL,
};

/* search64_1_1_0 -> search64_0_1_1_0_0 in the cache */
/* search64_1_1 -> search64_0_1_1_0 in the cache */
static const nir_search_expression search64_1 = {
   { nir_search_value_expression, -3 },
   false,
   3, 1,
   nir_op_fmul,
   { &search64_1_0.value, &search64_0_1_1_0.value },
   NULL,
};
static const nir_search_expression search64 = {
   { nir_search_value_expression, -3 },
   true,
   0, 4,
   nir_op_fadd,
   { &search64_0.value, &search64_1.value },
   NULL,
};

   /* replace64_0 -> search64_0_1_1_0_0 in the cache */

/* replace64_1 -> search64_1_0 in the cache */

/* replace64_2 -> search27_0_0 in the cache */
static const nir_search_expression replace64 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search64_0_1_1_0_0.value, &search64_1_0.value, &search27_0_0.value },
   NULL,
};

   /* search65_0_0 -> search0_0 in the cache */

static const nir_search_constant search65_0_1_0 = {
   { nir_search_value_constant, 32 },
   nir_type_float, { 0x3ff0000000000000 /* 1.0 */ },
};

static const nir_search_variable search65_0_1_1_0 = {
   { nir_search_value_variable, 32 },
   1, /* c */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search65_0_1_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search65_0_1_1_0.value },
   NULL,
};
static const nir_search_expression search65_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   2, 1,
   nir_op_fadd,
   { &search65_0_1_0.value, &search65_0_1_1.value },
   NULL,
};
static const nir_search_expression search65_0 = {
   { nir_search_value_expression, 32 },
   false,
   1, 2,
   nir_op_fmul,
   { &search0_0.value, &search65_0_1.value },
   NULL,
};

static const nir_search_variable search65_1_0 = {
   { nir_search_value_variable, 32 },
   2, /* b */
   false,
   nir_type_invalid,
   NULL,
};

/* search65_1_1 -> search65_0_1_1_0 in the cache */
static const nir_search_expression search65_1 = {
   { nir_search_value_expression, 32 },
   false,
   3, 1,
   nir_op_fmul,
   { &search65_1_0.value, &search65_0_1_1_0.value },
   NULL,
};
static const nir_search_expression search65 = {
   { nir_search_value_expression, 32 },
   true,
   0, 4,
   nir_op_fadd,
   { &search65_0.value, &search65_1.value },
   NULL,
};

   /* replace65_0 -> search0_0 in the cache */

/* replace65_1 -> search65_1_0 in the cache */

/* replace65_2 -> search65_0_1_1_0 in the cache */
static const nir_search_expression replace65 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_flrp,
   { &search0_0.value, &search65_1_0.value, &search65_0_1_1_0.value },
   NULL,
};

   /* search66_0_0 -> search58_0 in the cache */

static const nir_search_constant search66_0_1_0 = {
   { nir_search_value_constant, 64 },
   nir_type_float, { 0x3ff0000000000000 /* 1.0 */ },
};

static const nir_search_variable search66_0_1_1_0 = {
   { nir_search_value_variable, 64 },
   1, /* c */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search66_0_1_1 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search66_0_1_1_0.value },
   NULL,
};
static const nir_search_expression search66_0_1 = {
   { nir_search_value_expression, 64 },
   false,
   2, 1,
   nir_op_fadd,
   { &search66_0_1_0.value, &search66_0_1_1.value },
   NULL,
};
static const nir_search_expression search66_0 = {
   { nir_search_value_expression, 64 },
   false,
   1, 2,
   nir_op_fmul,
   { &search58_0.value, &search66_0_1.value },
   NULL,
};

static const nir_search_variable search66_1_0 = {
   { nir_search_value_variable, 64 },
   2, /* b */
   false,
   nir_type_invalid,
   NULL,
};

/* search66_1_1 -> search66_0_1_1_0 in the cache */
static const nir_search_expression search66_1 = {
   { nir_search_value_expression, 64 },
   false,
   3, 1,
   nir_op_fmul,
   { &search66_1_0.value, &search66_0_1_1_0.value },
   NULL,
};
static const nir_search_expression search66 = {
   { nir_search_value_expression, 64 },
   true,
   0, 4,
   nir_op_fadd,
   { &search66_0.value, &search66_1.value },
   NULL,
};

   /* replace66_0 -> search58_0 in the cache */

/* replace66_1 -> search66_1_0 in the cache */

/* replace66_2 -> search66_0_1_1_0 in the cache */
static const nir_search_expression replace66 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_flrp,
   { &search58_0.value, &search66_1_0.value, &search66_0_1_1_0.value },
   NULL,
};

   /* search67_0 -> search6_0 in the cache */

/* search67_1_0_0 -> search64_0_1_1_0_0 in the cache */
static const nir_search_expression search67_1_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &search64_0_1_1_0_0.value },
   NULL,
};

static const nir_search_variable search67_1_1_0 = {
   { nir_search_value_variable, -1 },
   2, /* b */
   false,
   nir_type_invalid,
   NULL,
};

/* search67_1_1_1_0 -> search6_0 in the cache */
/* search67_1_1_1 -> search14_0 in the cache */
static const nir_search_expression search67_1_1 = {
   { nir_search_value_expression, -1 },
   false,
   2, 1,
   nir_op_fadd,
   { &search67_1_1_0.value, &search14_0.value },
   NULL,
};
static const nir_search_expression search67_1 = {
   { nir_search_value_expression, -1 },
   false,
   1, 2,
   nir_op_fmul,
   { &search67_1_0.value, &search67_1_1.value },
   NULL,
};
static const nir_search_expression search67 = {
   { nir_search_value_expression, -1 },
   true,
   0, 3,
   nir_op_fadd,
   { &search6_0.value, &search67_1.value },
   NULL,
};

   /* replace67_0 -> search64_0_1_1_0_0 in the cache */

/* replace67_1 -> search67_1_1_0 in the cache */

/* replace67_2 -> search6_0 in the cache */
static const nir_search_expression replace67 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search64_0_1_1_0_0.value, &search67_1_1_0.value, &search6_0.value },
   NULL,
};

   /* search68_0 -> search0_0 in the cache */

/* search68_1_0 -> search65_0_1_1_0 in the cache */

/* search68_1_1_0 -> search65_1_0 in the cache */

/* search68_1_1_1_0 -> search0_0 in the cache */
static const nir_search_expression search68_1_1_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search0_0.value },
   NULL,
};
static const nir_search_expression search68_1_1 = {
   { nir_search_value_expression, 32 },
   false,
   2, 1,
   nir_op_fadd,
   { &search65_1_0.value, &search68_1_1_1.value },
   NULL,
};
static const nir_search_expression search68_1 = {
   { nir_search_value_expression, 32 },
   false,
   1, 2,
   nir_op_fmul,
   { &search65_0_1_1_0.value, &search68_1_1.value },
   NULL,
};
static const nir_search_expression search68 = {
   { nir_search_value_expression, 32 },
   true,
   0, 3,
   nir_op_fadd,
   { &search0_0.value, &search68_1.value },
   NULL,
};

   /* replace68_0 -> search0_0 in the cache */

/* replace68_1 -> search65_1_0 in the cache */

/* replace68_2 -> search65_0_1_1_0 in the cache */
/* replace68 -> replace65 in the cache */

   /* search69_0 -> search58_0 in the cache */

/* search69_1_0 -> search66_0_1_1_0 in the cache */

/* search69_1_1_0 -> search66_1_0 in the cache */

/* search69_1_1_1_0 -> search58_0 in the cache */
static const nir_search_expression search69_1_1_1 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search58_0.value },
   NULL,
};
static const nir_search_expression search69_1_1 = {
   { nir_search_value_expression, 64 },
   false,
   2, 1,
   nir_op_fadd,
   { &search66_1_0.value, &search69_1_1_1.value },
   NULL,
};
static const nir_search_expression search69_1 = {
   { nir_search_value_expression, 64 },
   false,
   1, 2,
   nir_op_fmul,
   { &search66_0_1_1_0.value, &search69_1_1.value },
   NULL,
};
static const nir_search_expression search69 = {
   { nir_search_value_expression, 64 },
   true,
   0, 3,
   nir_op_fadd,
   { &search58_0.value, &search69_1.value },
   NULL,
};

   /* replace69_0 -> search58_0 in the cache */

/* replace69_1 -> search66_1_0 in the cache */

/* replace69_2 -> search66_0_1_1_0 in the cache */
/* replace69 -> replace66 in the cache */

   /* search70_0 -> search27_0_0 in the cache */

/* search70_1 -> search27_0_1 in the cache */

/* search70_2 -> search27_1_1 in the cache */
static const nir_search_expression search70 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_ffma,
   { &search27_0_0.value, &search27_0_1.value, &search27_1_1.value },
   NULL,
};

   /* replace70_0_0 -> search27_0_0 in the cache */

/* replace70_0_1 -> search27_0_1 in the cache */
/* replace70_0 -> search27_0 in the cache */

/* replace70_1 -> search27_1_1 in the cache */
static const nir_search_expression replace70 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_fadd,
   { &search27_0.value, &search27_1_1.value },
   NULL,
};

   /* search71_0_0 -> search27_0_0 in the cache */

/* search71_0_1 -> search27_0_1 in the cache */
/* search71_0 -> search27_0 in the cache */

/* search71_1 -> search27_1_1 in the cache */
static const nir_search_expression search71 = {
   { nir_search_value_expression, -3 },
   true,
   0, 2,
   nir_op_fadd,
   { &search27_0.value, &search27_1_1.value },
   NULL,
};

   /* replace71_0 -> search27_0_0 in the cache */

/* replace71_1 -> search27_0_1 in the cache */

/* replace71_2 -> search27_1_1 in the cache */
/* replace71 -> search70 in the cache */

   static const nir_search_variable search72_0_0_0_0_0 = {
   { nir_search_value_variable, 1 },
   0, /* a */
   false,
   nir_type_bool,
   NULL,
};
static const nir_search_expression search72_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_b2i32,
   { &search72_0_0_0_0_0.value },
   NULL,
};
static const nir_search_expression search72_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search72_0_0_0_0.value },
   NULL,
};

/* search72_0_0_1_0 -> replace0_1_0 in the cache */

/* search72_0_0_1_1 -> search57_2 in the cache */
static const nir_search_expression search72_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   3, 1,
   nir_op_fmul,
   { &replace0_1_0.value, &search57_2.value },
   NULL,
};
static const nir_search_expression search72_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   2, 2,
   nir_op_iand,
   { &search72_0_0_0.value, &search72_0_0_1.value },
   NULL,
};

static const nir_search_variable search72_0_1 = {
   { nir_search_value_variable, 32 },
   3, /* d */
   true,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search72_0 = {
   { nir_search_value_expression, 32 },
   false,
   1, 3,
   nir_op_fadd,
   { &search72_0_0.value, &search72_0_1.value },
   NULL,
};

static const nir_search_variable search72_1 = {
   { nir_search_value_variable, 32 },
   4, /* e */
   true,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search72 = {
   { nir_search_value_expression, 32 },
   true,
   0, 4,
   nir_op_fmul,
   { &search72_0.value, &search72_1.value },
   NULL,
};

   static const nir_search_variable replace72_0 = {
   { nir_search_value_variable, 1 },
   0, /* a */
   false,
   nir_type_invalid,
   NULL,
};

/* replace72_1_0_0_0 -> replace0_1_0 in the cache */

/* replace72_1_0_0_1 -> search57_2 in the cache */
static const nir_search_expression replace72_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   2, 1,
   nir_op_fmul,
   { &replace0_1_0.value, &search57_2.value },
   NULL,
};

static const nir_search_variable replace72_1_0_1 = {
   { nir_search_value_variable, 32 },
   3, /* d */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression replace72_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   1, 2,
   nir_op_fadd,
   { &replace72_1_0_0.value, &replace72_1_0_1.value },
   NULL,
};

static const nir_search_variable replace72_1_1 = {
   { nir_search_value_variable, 32 },
   4, /* e */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression replace72_1 = {
   { nir_search_value_expression, 32 },
   false,
   0, 3,
   nir_op_fmul,
   { &replace72_1_0.value, &replace72_1_1.value },
   NULL,
};

/* replace72_2_0 -> replace72_1_0_1 in the cache */

/* replace72_2_1 -> replace72_1_1 in the cache */
static const nir_search_expression replace72_2 = {
   { nir_search_value_expression, 32 },
   false,
   3, 1,
   nir_op_fmul,
   { &replace72_1_0_1.value, &replace72_1_1.value },
   NULL,
};
static const nir_search_expression replace72 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 4,
   nir_op_bcsel,
   { &replace72_0.value, &replace72_1.value, &replace72_2.value },
   NULL,
};

   static const nir_search_variable search73_0_0 = {
   { nir_search_value_variable, -4 },
   0, /* a */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search73_0_1 = {
   { nir_search_value_variable, -4 },
   1, /* b */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search73_0_2 = {
   { nir_search_value_variable, -4 },
   2, /* c */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_constant search73_0_3 = {
   { nir_search_value_constant, -4 },
   nir_type_float, { 0x3ff0000000000000 /* 1.0 */ },
};
static const nir_search_expression search73_0 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_vec4,
   { &search73_0_0.value, &search73_0_1.value, &search73_0_2.value, &search73_0_3.value },
   NULL,
};

static const nir_search_variable search73_1 = {
   { nir_search_value_variable, -4 },
   3, /* d */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search73 = {
   { nir_search_value_expression, -4 },
   false,
   0, 1,
   nir_op_fdot4,
   { &search73_0.value, &search73_1.value },
   NULL,
};

   /* replace73_0_0 -> search73_0_0 in the cache */

/* replace73_0_1 -> search73_0_1 in the cache */

/* replace73_0_2 -> search73_0_2 in the cache */
static const nir_search_expression replace73_0 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_vec3,
   { &search73_0_0.value, &search73_0_1.value, &search73_0_2.value },
   NULL,
};

/* replace73_1 -> search73_1 in the cache */
static const nir_search_expression replace73 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_fdph,
   { &replace73_0.value, &search73_1.value },
   NULL,
};

   /* search74_0_0 -> search13_0 in the cache */

/* search74_0_1 -> search45_0 in the cache */

/* search74_0_2 -> search45_0 in the cache */

/* search74_0_3 -> search45_0 in the cache */
static const nir_search_expression search74_0 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_vec4,
   { &search13_0.value, &search45_0.value, &search45_0.value, &search45_0.value },
   NULL,
};

/* search74_1 -> replace13_1_0 in the cache */
static const nir_search_expression search74 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_fdot4,
   { &search74_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace74_0 -> search13_0 in the cache */

/* replace74_1 -> replace13_1_0 in the cache */
/* replace74 -> replace47 in the cache */

   /* search75_0_0 -> search27_0_0 in the cache */

/* search75_0_1 -> search27_0_1 in the cache */

static const nir_search_constant search75_0_2 = {
   { nir_search_value_constant, -3 },
   nir_type_float, { 0x0 /* 0.0 */ },
};

/* search75_0_3 -> search75_0_2 in the cache */
static const nir_search_expression search75_0 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_vec4,
   { &search27_0_0.value, &search27_0_1.value, &search75_0_2.value, &search75_0_2.value },
   NULL,
};

/* search75_1 -> search27_1_1 in the cache */
static const nir_search_expression search75 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_fdot4,
   { &search75_0.value, &search27_1_1.value },
   NULL,
};

   /* replace75_0_0 -> search27_0_0 in the cache */

/* replace75_0_1 -> search27_0_1 in the cache */
static const nir_search_expression replace75_0 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_vec2,
   { &search27_0_0.value, &search27_0_1.value },
   NULL,
};

/* replace75_1 -> search27_1_1 in the cache */
static const nir_search_expression replace75 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_fdot2,
   { &replace75_0.value, &search27_1_1.value },
   NULL,
};

   /* search76_0_0 -> search73_0_0 in the cache */

/* search76_0_1 -> search73_0_1 in the cache */

/* search76_0_2 -> search73_0_2 in the cache */

static const nir_search_constant search76_0_3 = {
   { nir_search_value_constant, -4 },
   nir_type_float, { 0x0 /* 0.0 */ },
};
static const nir_search_expression search76_0 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_vec4,
   { &search73_0_0.value, &search73_0_1.value, &search73_0_2.value, &search76_0_3.value },
   NULL,
};

/* search76_1 -> search73_1 in the cache */
static const nir_search_expression search76 = {
   { nir_search_value_expression, -4 },
   false,
   0, 1,
   nir_op_fdot4,
   { &search76_0.value, &search73_1.value },
   NULL,
};

   /* replace76_0_0 -> search73_0_0 in the cache */

/* replace76_0_1 -> search73_0_1 in the cache */

/* replace76_0_2 -> search73_0_2 in the cache */
/* replace76_0 -> replace73_0 in the cache */

/* replace76_1 -> search73_1 in the cache */
static const nir_search_expression replace76 = {
   { nir_search_value_expression, -4 },
   false,
   0, 1,
   nir_op_fdot3,
   { &replace73_0.value, &search73_1.value },
   NULL,
};

   /* search77_0_0 -> search13_0 in the cache */

/* search77_0_1 -> search45_0 in the cache */

/* search77_0_2 -> search45_0 in the cache */
static const nir_search_expression search77_0 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_vec3,
   { &search13_0.value, &search45_0.value, &search45_0.value },
   NULL,
};

/* search77_1 -> replace13_1_0 in the cache */
static const nir_search_expression search77 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_fdot3,
   { &search77_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace77_0 -> search13_0 in the cache */

/* replace77_1 -> replace13_1_0 in the cache */
/* replace77 -> replace47 in the cache */

   /* search78_0_0 -> search27_0_0 in the cache */

/* search78_0_1 -> search27_0_1 in the cache */

/* search78_0_2 -> search75_0_2 in the cache */
static const nir_search_expression search78_0 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_vec3,
   { &search27_0_0.value, &search27_0_1.value, &search75_0_2.value },
   NULL,
};

/* search78_1 -> search27_1_1 in the cache */
static const nir_search_expression search78 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_fdot3,
   { &search78_0.value, &search27_1_1.value },
   NULL,
};

   /* replace78_0_0 -> search27_0_0 in the cache */

/* replace78_0_1 -> search27_0_1 in the cache */
/* replace78_0 -> replace75_0 in the cache */

/* replace78_1 -> search27_1_1 in the cache */
/* replace78 -> replace75 in the cache */

   /* search79_0_0_0 -> search27_0_0 in the cache */

static const nir_search_variable search79_0_0_1 = {
   { nir_search_value_variable, -3 },
   1, /* b */
   true,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search79_0_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_imul,
   { &search27_0_0.value, &search79_0_0_1.value },
   NULL,
};

static const nir_search_variable search79_0_1 = {
   { nir_search_value_variable, -3 },
   2, /* c */
   true,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search79_0 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_iadd,
   { &search79_0_0.value, &search79_0_1.value },
   NULL,
};

/* search79_1 -> search72_0_1 in the cache */
static const nir_search_expression search79 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 2,
   nir_op_ishl,
   { &search79_0.value, &search72_0_1.value },
   NULL,
};

   /* replace79_0_0 -> search27_0_0 in the cache */

/* replace79_0_1_0 -> search27_0_1 in the cache */

/* replace79_0_1_1 -> replace72_1_0_1 in the cache */
static const nir_search_expression replace79_0_1 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search27_0_1.value, &replace72_1_0_1.value },
   NULL,
};
static const nir_search_expression replace79_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_imul,
   { &search27_0_0.value, &replace79_0_1.value },
   NULL,
};

/* replace79_1_0 -> search27_1_1 in the cache */

/* replace79_1_1 -> replace72_1_0_1 in the cache */
static const nir_search_expression replace79_1 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search27_1_1.value, &replace72_1_0_1.value },
   NULL,
};
static const nir_search_expression replace79 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_iadd,
   { &replace79_0.value, &replace79_1.value },
   NULL,
};

   /* search80_0_0 -> search13_0 in the cache */

static const nir_search_variable search80_0_1 = {
   { nir_search_value_variable, -2 },
   1, /* b */
   true,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search80_0 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_imul,
   { &search13_0.value, &search80_0_1.value },
   NULL,
};

static const nir_search_variable search80_1 = {
   { nir_search_value_variable, 32 },
   2, /* c */
   true,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search80 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 1,
   nir_op_ishl,
   { &search80_0.value, &search80_1.value },
   NULL,
};

   /* replace80_0 -> search13_0 in the cache */

/* replace80_1_0 -> replace13_1_0 in the cache */

/* replace80_1_1 -> search57_2 in the cache */
static const nir_search_expression replace80_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_ishl,
   { &replace13_1_0.value, &search57_2.value },
   NULL,
};
static const nir_search_expression replace80 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_imul,
   { &search13_0.value, &replace80_1.value },
   NULL,
};

   /* search81_0_0 -> search13_0 in the cache */

/* search81_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression search81_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search81 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 0,
   nir_op_inot,
   { &search81_0.value },
   NULL,
};

   /* replace81_0 -> search13_0 in the cache */

/* replace81_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace81 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search82_0_0 -> search13_0 in the cache */

/* search82_0_1 -> replace13_1_0 in the cache */
/* search82_0 -> replace81 in the cache */
static const nir_search_expression search82 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 0,
   nir_op_inot,
   { &replace81.value },
   NULL,
};

   /* replace82_0 -> search13_0 in the cache */

/* replace82_1 -> replace13_1_0 in the cache */
/* replace82 -> search81_0 in the cache */

   /* search83_0_0 -> search13_0 in the cache */

/* search83_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression search83_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search83 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 1,
   nir_op_inot,
   { &search83_0.value },
   NULL,
};

   /* replace83_0 -> search13_0 in the cache */

/* replace83_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace83 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search84_0_0 -> search13_0 in the cache */

/* search84_0_1 -> replace13_1_0 in the cache */
/* search84_0 -> replace83 in the cache */
static const nir_search_expression search84 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 1,
   nir_op_inot,
   { &replace83.value },
   NULL,
};

   /* replace84_0 -> search13_0 in the cache */

/* replace84_1 -> replace13_1_0 in the cache */
/* replace84 -> search83_0 in the cache */

   /* search85_0_0 -> search13_0 in the cache */

/* search85_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression search85_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search85 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_inot,
   { &search85_0.value },
   NULL,
};

   /* replace85_0 -> search13_0 in the cache */

/* replace85_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace85 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search86_0_0 -> search13_0 in the cache */

/* search86_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression search86_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search86 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_inot,
   { &search86_0.value },
   NULL,
};

   /* replace86_0 -> search13_0 in the cache */

/* replace86_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace86 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search87_0_0 -> search13_0 in the cache */

/* search87_0_1 -> replace13_1_0 in the cache */
/* search87_0 -> replace85 in the cache */
static const nir_search_expression search87 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_inot,
   { &replace85.value },
   NULL,
};

   /* replace87_0 -> search13_0 in the cache */

/* replace87_1 -> replace13_1_0 in the cache */
/* replace87 -> search85_0 in the cache */

   /* search88_0_0 -> search13_0 in the cache */

/* search88_0_1 -> replace13_1_0 in the cache */
/* search88_0 -> replace86 in the cache */
static const nir_search_expression search88 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_inot,
   { &replace86.value },
   NULL,
};

   /* replace88_0 -> search13_0 in the cache */

/* replace88_1 -> replace13_1_0 in the cache */
/* replace88 -> search86_0 in the cache */

   /* search89_0_0 -> search13_0 in the cache */

/* search89_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression search89_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search89 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_inot,
   { &search89_0.value },
   NULL,
};

   /* replace89_0 -> search13_0 in the cache */

/* replace89_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace89 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search90_0_0 -> search13_0 in the cache */

/* search90_0_1 -> replace13_1_0 in the cache */
/* search90_0 -> replace89 in the cache */
static const nir_search_expression search90 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_inot,
   { &replace89.value },
   NULL,
};

   /* replace90_0 -> search13_0 in the cache */

/* replace90_1 -> replace13_1_0 in the cache */
/* replace90 -> search89_0 in the cache */

   static const nir_search_constant search91_0 = {
   { nir_search_value_constant, 0 },
   nir_type_float, { 0x0 /* 0.0 */ },
};

/* search91_1_0 -> replace72_0 in the cache */
static const nir_search_expression search91_1 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &replace72_0.value },
   NULL,
};
static const nir_search_expression search91 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search91_0.value, &search91_1.value },
   NULL,
};

   /* replace91_0 -> replace72_0 in the cache */
static const nir_search_expression replace91 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_inot,
   { &replace72_0.value },
   NULL,
};

   /* search92_0_0_0 -> replace72_0 in the cache */
/* search92_0_0 -> search91_1 in the cache */
static const nir_search_expression search92_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search91_1.value },
   NULL,
};

/* search92_1 -> search91_0 in the cache */
static const nir_search_expression search92 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search92_0.value, &search91_0.value },
   NULL,
};

   /* replace92_0 -> replace72_0 in the cache */
/* replace92 -> replace91 in the cache */

   /* search93_0_0_0 -> replace72_0 in the cache */
/* search93_0_0 -> search91_1 in the cache */

static const nir_search_variable search93_0_1_0 = {
   { nir_search_value_variable, 1 },
   1, /* b */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search93_0_1 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &search93_0_1_0.value },
   NULL,
};
static const nir_search_expression search93_0 = {
   { nir_search_value_expression, 0 },
   false,
   1, 1,
   nir_op_fadd,
   { &search91_1.value, &search93_0_1.value },
   NULL,
};

/* search93_1 -> search91_0 in the cache */
static const nir_search_expression search93 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_fne,
   { &search93_0.value, &search91_0.value },
   NULL,
};

   /* replace93_0 -> replace72_0 in the cache */

/* replace93_1 -> search93_0_1_0 in the cache */
static const nir_search_expression replace93 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &replace72_0.value, &search93_0_1_0.value },
   NULL,
};

   /* search94_0_0_0 -> replace72_0 in the cache */
/* search94_0_0 -> search91_1 in the cache */

/* search94_0_1_0 -> search93_0_1_0 in the cache */
/* search94_0_1 -> search93_0_1 in the cache */
static const nir_search_expression search94_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search91_1.value, &search93_0_1.value },
   NULL,
};

/* search94_1 -> search91_0 in the cache */
static const nir_search_expression search94 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search94_0.value, &search91_0.value },
   NULL,
};

   /* replace94_0 -> replace72_0 in the cache */

/* replace94_1 -> search93_0_1_0 in the cache */
/* replace94 -> replace93 in the cache */

   /* search95_0_0 -> replace72_0 in the cache */

static const nir_search_constant search95_0_1 = {
   { nir_search_value_constant, 0 },
   nir_type_float, { 0x3ff0000000000000 /* 1.0 */ },
};

/* search95_0_2_0 -> search93_0_1_0 in the cache */
/* search95_0_2 -> search93_0_1 in the cache */
static const nir_search_expression search95_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search95_0_1.value, &search93_0_1.value },
   NULL,
};

/* search95_1 -> search91_0 in the cache */
static const nir_search_expression search95 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search95_0.value, &search91_0.value },
   NULL,
};

   /* replace95_0 -> replace72_0 in the cache */

/* replace95_1 -> search93_0_1_0 in the cache */
/* replace95 -> replace93 in the cache */

   /* search96_0_0 -> replace72_0 in the cache */
/* search96_0 -> search91_1 in the cache */

/* search96_1_0_0 -> search93_0_1_0 in the cache */
/* search96_1_0 -> search93_0_1 in the cache */
static const nir_search_expression search96_1 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search93_0_1.value },
   NULL,
};
static const nir_search_expression search96 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search91_1.value, &search96_1.value },
   NULL,
};

   /* replace96_0 -> replace72_0 in the cache */

/* replace96_1 -> search93_0_1_0 in the cache */
/* replace96 -> replace93 in the cache */

   /* search97_0_0_0 -> replace72_0 in the cache */
/* search97_0_0 -> search91_1 in the cache */

/* search97_0_1_0 -> search93_0_1_0 in the cache */
/* search97_0_1 -> search93_0_1 in the cache */
static const nir_search_expression search97_0 = {
   { nir_search_value_expression, 0 },
   false,
   1, 1,
   nir_op_fmul,
   { &search91_1.value, &search93_0_1.value },
   NULL,
};

/* search97_1 -> search91_0 in the cache */
static const nir_search_expression search97 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_fne,
   { &search97_0.value, &search91_0.value },
   NULL,
};

   /* replace97_0 -> replace72_0 in the cache */

/* replace97_1 -> search93_0_1_0 in the cache */
static const nir_search_expression replace97 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &replace72_0.value, &search93_0_1_0.value },
   NULL,
};

   /* search98_0_0_0 -> replace72_0 in the cache */
/* search98_0_0 -> search91_1 in the cache */

/* search98_0_1_0 -> search93_0_1_0 in the cache */
/* search98_0_1 -> search93_0_1 in the cache */
static const nir_search_expression search98_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search91_1.value, &search93_0_1.value },
   NULL,
};

/* search98_1 -> search91_0 in the cache */
static const nir_search_expression search98 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search98_0.value, &search91_0.value },
   NULL,
};

   /* replace98_0 -> replace72_0 in the cache */

/* replace98_1 -> search93_0_1_0 in the cache */
/* replace98 -> replace97 in the cache */

   /* search99_0_0 -> replace72_0 in the cache */

/* search99_0_1_0 -> search93_0_1_0 in the cache */
/* search99_0_1 -> search93_0_1 in the cache */

/* search99_0_2 -> search91_0 in the cache */
static const nir_search_expression search99_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search93_0_1.value, &search91_0.value },
   NULL,
};

/* search99_1 -> search91_0 in the cache */
static const nir_search_expression search99 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search99_0.value, &search91_0.value },
   NULL,
};

   /* replace99_0 -> replace72_0 in the cache */

/* replace99_1 -> search93_0_1_0 in the cache */
/* replace99 -> replace97 in the cache */

   /* search100_0_0_0 -> replace72_0 in the cache */
/* search100_0_0 -> search91_1 in the cache */

/* search100_0_1_0_0 -> search93_0_1_0 in the cache */
/* search100_0_1_0 -> search93_0_1 in the cache */
/* search100_0_1 -> search96_1 in the cache */
static const nir_search_expression search100_0 = {
   { nir_search_value_expression, 0 },
   false,
   1, 1,
   nir_op_fadd,
   { &search91_1.value, &search96_1.value },
   NULL,
};

/* search100_1 -> search91_0 in the cache */
static const nir_search_expression search100 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_fne,
   { &search100_0.value, &search91_0.value },
   NULL,
};

   /* replace100_0 -> replace72_0 in the cache */

/* replace100_1 -> search93_0_1_0 in the cache */
static const nir_search_expression replace100 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ixor,
   { &replace72_0.value, &search93_0_1_0.value },
   NULL,
};

   /* search101_0_0 -> replace72_0 in the cache */
/* search101_0 -> search91_1 in the cache */

/* search101_1_0 -> search93_0_1_0 in the cache */
/* search101_1 -> search93_0_1 in the cache */
static const nir_search_expression search101 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search91_1.value, &search93_0_1.value },
   NULL,
};

   /* replace101_0 -> replace72_0 in the cache */

/* replace101_1 -> search93_0_1_0 in the cache */
/* replace101 -> replace100 in the cache */

   /* search102_0_0_0 -> replace72_0 in the cache */
/* search102_0_0 -> search91_1 in the cache */
/* search102_0 -> search92_0 in the cache */

/* search102_1_0_0 -> search93_0_1_0 in the cache */
/* search102_1_0 -> search93_0_1 in the cache */
/* search102_1 -> search96_1 in the cache */
static const nir_search_expression search102 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search92_0.value, &search96_1.value },
   NULL,
};

   /* replace102_0 -> replace72_0 in the cache */

/* replace102_1 -> search93_0_1_0 in the cache */
/* replace102 -> replace100 in the cache */

   /* search103_0_0_0 -> replace72_0 in the cache */
/* search103_0_0 -> search91_1 in the cache */

/* search103_0_1_0 -> search93_0_1_0 in the cache */
/* search103_0_1 -> search93_0_1 in the cache */
/* search103_0 -> search93_0 in the cache */

/* search103_1 -> search91_0 in the cache */
static const nir_search_expression search103 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_feq,
   { &search93_0.value, &search91_0.value },
   NULL,
};

   /* replace103_0_0 -> replace72_0 in the cache */

/* replace103_0_1 -> search93_0_1_0 in the cache */
/* replace103_0 -> replace93 in the cache */
static const nir_search_expression replace103 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_inot,
   { &replace93.value },
   NULL,
};

   /* search104_0_0_0 -> replace72_0 in the cache */
/* search104_0_0 -> search91_1 in the cache */

/* search104_0_1_0 -> search93_0_1_0 in the cache */
/* search104_0_1 -> search93_0_1 in the cache */
/* search104_0 -> search94_0 in the cache */

/* search104_1 -> search91_0 in the cache */
static const nir_search_expression search104 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search94_0.value, &search91_0.value },
   NULL,
};

   /* replace104_0_0 -> replace72_0 in the cache */

/* replace104_0_1 -> search93_0_1_0 in the cache */
/* replace104_0 -> replace93 in the cache */
/* replace104 -> replace103 in the cache */

   /* search105_0_0 -> replace72_0 in the cache */

/* search105_0_1 -> search95_0_1 in the cache */

/* search105_0_2_0 -> search93_0_1_0 in the cache */
/* search105_0_2 -> search93_0_1 in the cache */
/* search105_0 -> search95_0 in the cache */

/* search105_1 -> search91_0 in the cache */
static const nir_search_expression search105 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search95_0.value, &search91_0.value },
   NULL,
};

   /* replace105_0_0 -> replace72_0 in the cache */

/* replace105_0_1 -> search93_0_1_0 in the cache */
/* replace105_0 -> replace93 in the cache */
/* replace105 -> replace103 in the cache */

   /* search106_0_0 -> replace72_0 in the cache */
/* search106_0 -> search91_1 in the cache */

/* search106_1_0_0 -> search93_0_1_0 in the cache */
/* search106_1_0 -> search93_0_1 in the cache */
/* search106_1 -> search96_1 in the cache */
static const nir_search_expression search106 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search91_1.value, &search96_1.value },
   NULL,
};

   /* replace106_0_0 -> replace72_0 in the cache */

/* replace106_0_1 -> search93_0_1_0 in the cache */
/* replace106_0 -> replace93 in the cache */
/* replace106 -> replace103 in the cache */

   /* search107_0_0_0 -> replace72_0 in the cache */
/* search107_0_0 -> search91_1 in the cache */

/* search107_0_1_0 -> search93_0_1_0 in the cache */
/* search107_0_1 -> search93_0_1 in the cache */
/* search107_0 -> search97_0 in the cache */

/* search107_1 -> search91_0 in the cache */
static const nir_search_expression search107 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_feq,
   { &search97_0.value, &search91_0.value },
   NULL,
};

   /* replace107_0_0 -> replace72_0 in the cache */

/* replace107_0_1 -> search93_0_1_0 in the cache */
/* replace107_0 -> replace97 in the cache */
static const nir_search_expression replace107 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_inot,
   { &replace97.value },
   NULL,
};

   /* search108_0_0_0 -> replace72_0 in the cache */
/* search108_0_0 -> search91_1 in the cache */

/* search108_0_1_0 -> search93_0_1_0 in the cache */
/* search108_0_1 -> search93_0_1 in the cache */
/* search108_0 -> search98_0 in the cache */

/* search108_1 -> search91_0 in the cache */
static const nir_search_expression search108 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search98_0.value, &search91_0.value },
   NULL,
};

   /* replace108_0_0 -> replace72_0 in the cache */

/* replace108_0_1 -> search93_0_1_0 in the cache */
/* replace108_0 -> replace97 in the cache */
/* replace108 -> replace107 in the cache */

   /* search109_0_0 -> replace72_0 in the cache */

/* search109_0_1_0 -> search93_0_1_0 in the cache */
/* search109_0_1 -> search93_0_1 in the cache */

/* search109_0_2 -> search91_0 in the cache */
/* search109_0 -> search99_0 in the cache */

/* search109_1 -> search91_0 in the cache */
static const nir_search_expression search109 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search99_0.value, &search91_0.value },
   NULL,
};

   /* replace109_0_0 -> replace72_0 in the cache */

/* replace109_0_1 -> search93_0_1_0 in the cache */
/* replace109_0 -> replace97 in the cache */
/* replace109 -> replace107 in the cache */

   /* search110_0_0_0 -> replace72_0 in the cache */
/* search110_0_0 -> search91_1 in the cache */

/* search110_0_1_0_0 -> search93_0_1_0 in the cache */
/* search110_0_1_0 -> search93_0_1 in the cache */
/* search110_0_1 -> search96_1 in the cache */
/* search110_0 -> search100_0 in the cache */

/* search110_1 -> search91_0 in the cache */
static const nir_search_expression search110 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_feq,
   { &search100_0.value, &search91_0.value },
   NULL,
};

   /* replace110_0 -> replace72_0 in the cache */

/* replace110_1 -> search93_0_1_0 in the cache */
static const nir_search_expression replace110 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &replace72_0.value, &search93_0_1_0.value },
   NULL,
};

   /* search111_0_0 -> replace72_0 in the cache */
/* search111_0 -> search91_1 in the cache */

/* search111_1_0 -> search93_0_1_0 in the cache */
/* search111_1 -> search93_0_1 in the cache */
static const nir_search_expression search111 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search91_1.value, &search93_0_1.value },
   NULL,
};

   /* replace111_0 -> replace72_0 in the cache */

/* replace111_1 -> search93_0_1_0 in the cache */
/* replace111 -> replace110 in the cache */

   /* search112_0_0_0 -> replace72_0 in the cache */
/* search112_0_0 -> search91_1 in the cache */
/* search112_0 -> search92_0 in the cache */

/* search112_1_0_0 -> search93_0_1_0 in the cache */
/* search112_1_0 -> search93_0_1 in the cache */
/* search112_1 -> search96_1 in the cache */
static const nir_search_expression search112 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search92_0.value, &search96_1.value },
   NULL,
};

   /* replace112_0 -> replace72_0 in the cache */

/* replace112_1 -> search93_0_1_0 in the cache */
/* replace112 -> replace110 in the cache */

   /* search113_0_0_0_0 -> replace72_0 in the cache */
/* search113_0_0_0 -> search91_1 in the cache */

/* search113_0_0_1_0 -> search93_0_1_0 in the cache */
/* search113_0_0_1 -> search93_0_1 in the cache */
static const nir_search_expression search113_0_0 = {
   { nir_search_value_expression, 0 },
   false,
   0, 1,
   nir_op_fadd,
   { &search91_1.value, &search93_0_1.value },
   NULL,
};
static const nir_search_expression search113_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 1,
   nir_op_fneg,
   { &search113_0_0.value },
   NULL,
};

/* search113_1 -> search91_0 in the cache */
static const nir_search_expression search113 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_flt,
   { &search113_0.value, &search91_0.value },
   NULL,
};

   /* replace113_0 -> replace72_0 in the cache */

/* replace113_1 -> search93_0_1_0 in the cache */
/* replace113 -> replace93 in the cache */

   /* search114_0 -> search91_0 in the cache */

/* search114_1_0_0 -> replace72_0 in the cache */
/* search114_1_0 -> search91_1 in the cache */

/* search114_1_1_0 -> search93_0_1_0 in the cache */
/* search114_1_1 -> search93_0_1 in the cache */
/* search114_1 -> search113_0_0 in the cache */
static const nir_search_expression search114 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_flt,
   { &search91_0.value, &search113_0_0.value },
   NULL,
};

   /* replace114_0 -> replace72_0 in the cache */

/* replace114_1 -> search93_0_1_0 in the cache */
/* replace114 -> replace93 in the cache */

   /* search115_0_0_0_0 -> replace72_0 in the cache */
/* search115_0_0_0 -> search91_1 in the cache */

/* search115_0_0_1_0 -> search93_0_1_0 in the cache */
/* search115_0_0_1 -> search93_0_1 in the cache */
/* search115_0_0 -> search113_0_0 in the cache */
/* search115_0 -> search113_0 in the cache */

/* search115_1 -> search91_0 in the cache */
static const nir_search_expression search115 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_fge,
   { &search113_0.value, &search91_0.value },
   NULL,
};

   /* replace115_0_0 -> replace72_0 in the cache */

/* replace115_0_1 -> search93_0_1_0 in the cache */
/* replace115_0 -> replace93 in the cache */
/* replace115 -> replace103 in the cache */

   /* search116_0 -> search91_0 in the cache */

/* search116_1_0_0 -> replace72_0 in the cache */
/* search116_1_0 -> search91_1 in the cache */

/* search116_1_1_0 -> search93_0_1_0 in the cache */
/* search116_1_1 -> search93_0_1 in the cache */
/* search116_1 -> search113_0_0 in the cache */
static const nir_search_expression search116 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_fge,
   { &search91_0.value, &search113_0_0.value },
   NULL,
};

   /* replace116_0_0 -> replace72_0 in the cache */

/* replace116_0_1 -> search93_0_1_0 in the cache */
/* replace116_0 -> replace93 in the cache */
/* replace116 -> replace103 in the cache */

   /* search117_0 -> search6_0 in the cache */

/* search117_1_0 -> search6_0 in the cache */
/* search117_1 -> search14_0 in the cache */
static const nir_search_expression search117 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search6_0.value, &search14_0.value },
   NULL,
};

   /* replace117_0 -> search6_0 in the cache */

/* replace117_1 -> search23_1 in the cache */
/* replace117 -> replace59_0 in the cache */

   /* search118_0 -> search6_0 in the cache */

/* search118_1_0 -> search6_0 in the cache */
/* search118_1 -> search14_0 in the cache */
static const nir_search_expression search118 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search6_0.value, &search14_0.value },
   NULL,
};

   /* replace118_0 -> search6_0 in the cache */

/* replace118_1 -> search23_1 in the cache */
static const nir_search_expression replace118 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search6_0.value, &search23_1.value },
   NULL,
};

   static const nir_search_variable search119_0_0 = {
   { nir_search_value_variable, -1 },
   0, /* c */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search119_0_1_0_0_0 = {
   { nir_search_value_variable, 1 },
   1, /* a */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search119_0_1_0_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &search119_0_1_0_0_0.value },
   NULL,
};

static const nir_search_variable search119_0_1_0_1_0 = {
   { nir_search_value_variable, 1 },
   2, /* b */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search119_0_1_0_1 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &search119_0_1_0_1_0.value },
   NULL,
};
static const nir_search_expression search119_0_1_0 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_fadd,
   { &search119_0_1_0_0.value, &search119_0_1_0_1.value },
   NULL,
};
static const nir_search_expression search119_0_1 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 1,
   nir_op_fneg,
   { &search119_0_1_0.value },
   NULL,
};
static const nir_search_expression search119_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 1,
   nir_op_fmin,
   { &search119_0_0.value, &search119_0_1.value },
   NULL,
};

/* search119_1 -> search23_1 in the cache */
static const nir_search_expression search119 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_flt,
   { &search119_0.value, &search23_1.value },
   NULL,
};

   /* replace119_0_0 -> search119_0_0 in the cache */

/* replace119_0_1 -> search23_1 in the cache */
static const nir_search_expression replace119_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search119_0_0.value, &search23_1.value },
   NULL,
};

/* replace119_1_0 -> search119_0_1_0_0_0 in the cache */

/* replace119_1_1 -> search119_0_1_0_1_0 in the cache */
static const nir_search_expression replace119_1 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_ior,
   { &search119_0_1_0_0_0.value, &search119_0_1_0_1_0.value },
   NULL,
};
static const nir_search_expression replace119 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ior,
   { &replace119_0.value, &replace119_1.value },
   NULL,
};

   /* search120_0_0 -> search13_0 in the cache */

/* search120_0_1 -> replace13_1_0 in the cache */
/* search120_0 -> replace48 in the cache */

/* search120_1 -> search13_0 in the cache */
static const nir_search_expression search120 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 1,
   nir_op_flt,
   { &replace48.value, &search13_0.value },
   NULL,
};

   /* replace120_0 -> replace13_1_0 in the cache */

/* replace120_1 -> search45_0 in the cache */
static const nir_search_expression replace120 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &replace13_1_0.value, &search45_0.value },
   NULL,
};

   /* search121_0_0 -> search13_0 in the cache */

/* search121_0_1 -> replace13_1_0 in the cache */
/* search121_0 -> replace48 in the cache */

/* search121_1 -> search13_0 in the cache */
static const nir_search_expression search121 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 1,
   nir_op_fge,
   { &replace48.value, &search13_0.value },
   NULL,
};

   /* replace121_0 -> replace13_1_0 in the cache */

/* replace121_1 -> search45_0 in the cache */
static const nir_search_expression replace121 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &replace13_1_0.value, &search45_0.value },
   NULL,
};

   /* search122_0_0 -> search13_0 in the cache */

/* search122_0_1 -> replace13_1_0 in the cache */
/* search122_0 -> search33_1 in the cache */

/* search122_1 -> search13_0 in the cache */
static const nir_search_expression search122 = {
   { nir_search_value_expression, 1 },
   true,
   0, 2,
   nir_op_feq,
   { &search33_1.value, &search13_0.value },
   NULL,
};

   /* replace122_0 -> replace13_1_0 in the cache */

/* replace122_1 -> search45_0 in the cache */
static const nir_search_expression replace122 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &replace13_1_0.value, &search45_0.value },
   NULL,
};

   /* search123_0_0 -> search13_0 in the cache */

/* search123_0_1 -> replace13_1_0 in the cache */
/* search123_0 -> search33_1 in the cache */

/* search123_1 -> search13_0 in the cache */
static const nir_search_expression search123 = {
   { nir_search_value_expression, 1 },
   true,
   0, 2,
   nir_op_fne,
   { &search33_1.value, &search13_0.value },
   NULL,
};

   /* replace123_0 -> replace13_1_0 in the cache */

/* replace123_1 -> search45_0 in the cache */
static const nir_search_expression replace123 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &replace13_1_0.value, &search45_0.value },
   NULL,
};

   /* search124_0_0 -> search13_0 in the cache */

/* search124_0_1 -> replace13_1_0 in the cache */
/* search124_0 -> search31_1 in the cache */

/* search124_1 -> search13_0 in the cache */
static const nir_search_expression search124 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ieq,
   { &search31_1.value, &search13_0.value },
   NULL,
};

   /* replace124_0 -> replace13_1_0 in the cache */

static const nir_search_constant replace124_1 = {
   { nir_search_value_constant, -2 },
   nir_type_int, { 0x0 /* 0 */ },
};
static const nir_search_expression replace124 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &replace13_1_0.value, &replace124_1.value },
   NULL,
};

   /* search125_0_0 -> search13_0 in the cache */

/* search125_0_1 -> replace13_1_0 in the cache */
/* search125_0 -> search31_1 in the cache */

/* search125_1 -> search13_0 in the cache */
static const nir_search_expression search125 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ine,
   { &search31_1.value, &search13_0.value },
   NULL,
};

   /* replace125_0 -> replace13_1_0 in the cache */

/* replace125_1 -> replace124_1 in the cache */
static const nir_search_expression replace125 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &replace13_1_0.value, &replace124_1.value },
   NULL,
};

   /* search126_0_0_0_0 -> replace72_0 in the cache */
static const nir_search_expression search126_0_0_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &replace72_0.value },
   NULL,
};
static const nir_search_expression search126_0_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search126_0_0_0.value },
   NULL,
};

/* search126_0_1 -> search93_0_1_0 in the cache */
static const nir_search_expression search126_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search126_0_0.value, &search93_0_1_0.value },
   NULL,
};

static const nir_search_constant search126_1 = {
   { nir_search_value_constant, 1 },
   nir_type_float, { 0x0 /* 0.0 */ },
};
static const nir_search_expression search126 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search126_0.value, &search126_1.value },
   NULL,
};

   /* replace126_0_0 -> replace72_0 in the cache */
/* replace126_0 -> replace91 in the cache */

/* replace126_1_0 -> search93_0_1_0 in the cache */

/* replace126_1_1 -> search126_1 in the cache */
static const nir_search_expression replace126_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search93_0_1_0.value, &search126_1.value },
   NULL,
};
static const nir_search_expression replace126 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &replace91.value, &replace126_1.value },
   NULL,
};

   /* search127_0_0_0_0 -> replace72_0 in the cache */
/* search127_0_0_0 -> search126_0_0_0 in the cache */
/* search127_0_0 -> search126_0_0 in the cache */

/* search127_0_1 -> search93_0_1_0 in the cache */
/* search127_0 -> search126_0 in the cache */

/* search127_1 -> search126_1 in the cache */
static const nir_search_expression search127 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search126_0.value, &search126_1.value },
   NULL,
};

   /* replace127_0_0 -> replace72_0 in the cache */
/* replace127_0 -> replace91 in the cache */

/* replace127_1_0 -> search93_0_1_0 in the cache */

/* replace127_1_1 -> search126_1 in the cache */
/* replace127_1 -> replace126_1 in the cache */
/* replace127 -> replace126 in the cache */

   /* search128_0_0 -> replace72_0 in the cache */
/* search128_0 -> search91_1 in the cache */

/* search128_1 -> search91_0 in the cache */
static const nir_search_expression search128 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search91_1.value, &search91_0.value },
   NULL,
};

   /* replace128_0 -> replace72_0 in the cache */
/* replace128 -> replace91 in the cache */

   /* search129_0_0 -> replace72_0 in the cache */
/* search129_0 -> search91_1 in the cache */

/* search129_1 -> search91_0 in the cache */
static const nir_search_expression search129 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search91_1.value, &search91_0.value },
   NULL,
};

   /* replace129 -> replace72_0 in the cache */

   /* search130_0_0 -> replace72_0 in the cache */
static const nir_search_expression search130_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_b2i,
   { &replace72_0.value },
   NULL,
};

static const nir_search_constant search130_1 = {
   { nir_search_value_constant, 0 },
   nir_type_int, { 0x0 /* 0 */ },
};
static const nir_search_expression search130 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &search130_0.value, &search130_1.value },
   NULL,
};

   /* replace130_0 -> replace72_0 in the cache */
/* replace130 -> replace91 in the cache */

   /* search131_0_0 -> replace72_0 in the cache */
/* search131_0 -> search130_0 in the cache */

/* search131_1 -> search130_1 in the cache */
static const nir_search_expression search131 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &search130_0.value, &search130_1.value },
   NULL,
};

   /* replace131 -> replace72_0 in the cache */

   /* search132_0_0 -> search6_0 in the cache */
/* search132_0 -> search18_0 in the cache */

/* search132_1 -> search91_0 in the cache */
static const nir_search_expression search132 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search18_0.value, &search91_0.value },
   NULL,
};

   /* replace132_0 -> search6_0 in the cache */

/* replace132_1 -> replace8 in the cache */
static const nir_search_expression replace132 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &search6_0.value, &replace8.value },
   NULL,
};

   /* search133_0_0 -> search6_0 in the cache */
/* search133_0 -> search18_0 in the cache */

/* search133_1 -> search91_0 in the cache */
static const nir_search_expression search133 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search18_0.value, &search91_0.value },
   NULL,
};

   /* replace133_0 -> search6_0 in the cache */

/* replace133_1 -> replace8 in the cache */
static const nir_search_expression replace133 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &search6_0.value, &replace8.value },
   NULL,
};

   /* search134_0_0 -> search6_0 in the cache */
/* search134_0 -> search18_0 in the cache */

/* search134_1 -> search91_0 in the cache */
static const nir_search_expression search134 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search18_0.value, &search91_0.value },
   NULL,
};

   static const nir_search_constant replace134 = {
   { nir_search_value_constant, 1 },
   nir_type_bool, { NIR_TRUE /* True */ },
};

   /* search135_0 -> search91_0 in the cache */

/* search135_1_0 -> search6_0 in the cache */
/* search135_1 -> search18_0 in the cache */
static const nir_search_expression search135 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search91_0.value, &search18_0.value },
   NULL,
};

   /* replace135_0 -> replace8 in the cache */

/* replace135_1 -> search6_0 in the cache */
static const nir_search_expression replace135 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &replace8.value, &search6_0.value },
   NULL,
};

   /* search136_0_0 -> search6_0 in the cache */
/* search136_0 -> search18_0 in the cache */

/* search136_1 -> search91_0 in the cache */
static const nir_search_expression search136 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search18_0.value, &search91_0.value },
   NULL,
};

   static const nir_search_constant replace136 = {
   { nir_search_value_constant, 1 },
   nir_type_bool, { NIR_FALSE /* False */ },
};

   /* search137_0 -> search91_0 in the cache */

/* search137_1_0 -> search6_0 in the cache */
/* search137_1 -> search18_0 in the cache */
static const nir_search_expression search137 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search91_0.value, &search18_0.value },
   NULL,
};

   /* replace137_0 -> replace8 in the cache */

/* replace137_1 -> search6_0 in the cache */
static const nir_search_expression replace137 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &replace8.value, &search6_0.value },
   NULL,
};

   /* search138_0_0 -> search6_0 in the cache */
static const nir_search_expression search138_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_i2f,
   { &search6_0.value },
   NULL,
};

/* search138_1 -> search91_0 in the cache */
static const nir_search_expression search138 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search138_0.value, &search91_0.value },
   NULL,
};

   /* replace138_0 -> search6_0 in the cache */

/* replace138_1 -> replace8 in the cache */
/* replace138 -> replace132 in the cache */

   /* search139_0_0 -> search6_0 in the cache */
/* search139_0 -> search138_0 in the cache */

/* search139_1 -> search91_0 in the cache */
static const nir_search_expression search139 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search138_0.value, &search91_0.value },
   NULL,
};

   /* replace139_0 -> search6_0 in the cache */

/* replace139_1 -> replace8 in the cache */
/* replace139 -> replace133 in the cache */

   /* search140_0_0 -> search6_0 in the cache */
/* search140_0 -> search138_0 in the cache */

/* search140_1 -> search91_0 in the cache */
static const nir_search_expression search140 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search138_0.value, &search91_0.value },
   NULL,
};

   /* replace140_0 -> search6_0 in the cache */

/* replace140_1 -> replace8 in the cache */
static const nir_search_expression replace140 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search6_0.value, &replace8.value },
   NULL,
};

   /* search141_0 -> search91_0 in the cache */

/* search141_1_0 -> search6_0 in the cache */
/* search141_1 -> search138_0 in the cache */
static const nir_search_expression search141 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search91_0.value, &search138_0.value },
   NULL,
};

   /* replace141_0 -> replace8 in the cache */

/* replace141_1 -> search6_0 in the cache */
static const nir_search_expression replace141 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &replace8.value, &search6_0.value },
   NULL,
};

   /* search142_0_0 -> search6_0 in the cache */
/* search142_0 -> search138_0 in the cache */

/* search142_1 -> search91_0 in the cache */
static const nir_search_expression search142 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search138_0.value, &search91_0.value },
   NULL,
};

   /* replace142_0 -> search6_0 in the cache */

/* replace142_1 -> replace8 in the cache */
static const nir_search_expression replace142 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search6_0.value, &replace8.value },
   NULL,
};

   /* search143_0 -> search91_0 in the cache */

/* search143_1_0 -> search6_0 in the cache */
/* search143_1 -> search138_0 in the cache */
static const nir_search_expression search143 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search91_0.value, &search138_0.value },
   NULL,
};

   /* replace143_0 -> replace8 in the cache */

/* replace143_1 -> search6_0 in the cache */
static const nir_search_expression replace143 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &replace8.value, &search6_0.value },
   NULL,
};

   /* search144_0 -> search23_1 in the cache */

/* search144_1_0 -> search6_0 in the cache */
/* search144_1 -> search16_0 in the cache */
static const nir_search_expression search144 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 0,
   nir_op_flt,
   { &search23_1.value, &search16_0.value },
   NULL,
};

   /* replace144_0 -> search6_0 in the cache */

/* replace144_1 -> search23_1 in the cache */
static const nir_search_expression replace144 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search6_0.value, &search23_1.value },
   NULL,
};

   /* search145_0_0_0 -> search6_0 in the cache */
/* search145_0_0 -> search16_0 in the cache */
static const nir_search_expression search145_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search16_0.value },
   NULL,
};

/* search145_1 -> search23_1 in the cache */
static const nir_search_expression search145 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 0,
   nir_op_flt,
   { &search145_0.value, &search23_1.value },
   NULL,
};

   /* replace145_0 -> search6_0 in the cache */

/* replace145_1 -> search23_1 in the cache */
/* replace145 -> replace144 in the cache */

   /* search146_0 -> search23_1 in the cache */

/* search146_1_0 -> search6_0 in the cache */
/* search146_1 -> search16_0 in the cache */
static const nir_search_expression search146 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search23_1.value, &search16_0.value },
   NULL,
};

   /* replace146_0 -> search6_0 in the cache */

/* replace146_1 -> search23_1 in the cache */
static const nir_search_expression replace146 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search6_0.value, &search23_1.value },
   NULL,
};

   /* search147_0_0_0 -> search6_0 in the cache */
/* search147_0_0 -> search16_0 in the cache */
/* search147_0 -> search145_0 in the cache */

/* search147_1 -> search23_1 in the cache */
static const nir_search_expression search147 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search145_0.value, &search23_1.value },
   NULL,
};

   /* replace147_0 -> search6_0 in the cache */

/* replace147_1 -> search23_1 in the cache */
/* replace147 -> replace146 in the cache */

   /* search148_0_0 -> replace72_0 in the cache */
static const nir_search_expression search148_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &replace72_0.value },
   (is_used_once),
};

/* search148_1_0 -> search93_0_1_0 in the cache */
/* search148_1 -> search93_0_1 in the cache */
static const nir_search_expression search148 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search148_0.value, &search93_0_1.value },
   NULL,
};

   /* replace148_0_0 -> replace72_0 in the cache */

/* replace148_0_1 -> search93_0_1_0 in the cache */
/* replace148_0 -> replace93 in the cache */
static const nir_search_expression replace148 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 1,
   nir_search_op_b2f,
   { &replace93.value },
   NULL,
};

   /* search149_0_0_0 -> replace72_0 in the cache */
/* search149_0_0 -> search148_0 in the cache */
static const nir_search_expression search149_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search148_0.value },
   (is_used_once),
};

/* search149_1_0_0 -> search93_0_1_0 in the cache */
/* search149_1_0 -> search93_0_1 in the cache */
/* search149_1 -> search96_1 in the cache */
static const nir_search_expression search149 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search149_0.value, &search96_1.value },
   NULL,
};

   /* replace149_0_0_0 -> replace72_0 in the cache */

/* replace149_0_0_1 -> search93_0_1_0 in the cache */
/* replace149_0_0 -> replace93 in the cache */
/* replace149_0 -> replace148 in the cache */
static const nir_search_expression replace149 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 1,
   nir_op_fneg,
   { &replace148.value },
   NULL,
};

   /* search150_0_0 -> replace72_0 in the cache */
/* search150_0 -> search148_0 in the cache */

/* search150_1_0 -> search93_0_1_0 in the cache */
/* search150_1 -> search93_0_1 in the cache */
static const nir_search_expression search150 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search148_0.value, &search93_0_1.value },
   NULL,
};

   /* replace150_0_0 -> replace72_0 in the cache */

/* replace150_0_1 -> search93_0_1_0 in the cache */
/* replace150_0 -> replace97 in the cache */
static const nir_search_expression replace150 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 1,
   nir_search_op_b2f,
   { &replace97.value },
   NULL,
};

   /* search151_0_0_0 -> replace72_0 in the cache */
/* search151_0_0 -> search148_0 in the cache */
/* search151_0 -> search149_0 in the cache */

/* search151_1_0_0 -> search93_0_1_0 in the cache */
/* search151_1_0 -> search93_0_1 in the cache */
/* search151_1 -> search96_1 in the cache */
static const nir_search_expression search151 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search149_0.value, &search96_1.value },
   NULL,
};

   /* replace151_0_0_0 -> replace72_0 in the cache */

/* replace151_0_0_1 -> search93_0_1_0 in the cache */
/* replace151_0_0 -> replace97 in the cache */
/* replace151_0 -> replace150 in the cache */
static const nir_search_expression replace151 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 1,
   nir_op_fneg,
   { &replace150.value },
   NULL,
};

   /* search152_0_0 -> replace72_0 in the cache */
static const nir_search_expression search152_0 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &replace72_0.value },
   NULL,
};

/* search152_1 -> search80_0_1 in the cache */
static const nir_search_expression search152 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search152_0.value, &search80_0_1.value },
   NULL,
};

   /* replace152_0 -> replace72_0 in the cache */

/* replace152_1_0 -> replace13_1_0 in the cache */

/* replace152_1_1 -> search48_1 in the cache */
static const nir_search_expression replace152_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fmin,
   { &replace13_1_0.value, &search48_1.value },
   NULL,
};

/* replace152_2_0 -> replace13_1_0 in the cache */

/* replace152_2_1 -> search45_0 in the cache */
static const nir_search_expression replace152_2 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fmin,
   { &replace13_1_0.value, &search45_0.value },
   NULL,
};
static const nir_search_expression replace152 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &replace152_1.value, &replace152_2.value },
   NULL,
};

   /* search153_0_0 -> search13_0 in the cache */

/* search153_0_1_0 -> replace13_1_0 in the cache */
static const nir_search_expression search153_0_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fneg,
   { &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search153_0 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_fadd,
   { &search13_0.value, &search153_0_1.value },
   (is_used_once),
};

/* search153_1 -> search45_0 in the cache */
static const nir_search_expression search153 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_flt,
   { &search153_0.value, &search45_0.value },
   NULL,
};

   /* replace153_0 -> search13_0 in the cache */

/* replace153_1 -> replace13_1_0 in the cache */
/* replace153 -> search81_0 in the cache */

   /* search154_0_0_0 -> search6_0 in the cache */
/* search154_0_0 -> search16_0 in the cache */
/* search154_0 -> search145_0 in the cache */

/* search154_1 -> search23_1 in the cache */
/* search154 -> search147 in the cache */

   /* replace154_0 -> search6_0 in the cache */

/* replace154_1 -> search23_1 in the cache */
/* replace154 -> replace146 in the cache */

   static const nir_search_variable search155_0_0 = {
   { nir_search_value_variable, -2 },
   0, /* b */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search155_0_1 = {
   { nir_search_value_variable, -2 },
   1, /* a */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search155_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search155_0_0.value, &search155_0_1.value },
   NULL,
};

/* search155_1 -> search155_0_0 in the cache */

/* search155_2 -> search155_0_1 in the cache */
static const nir_search_expression search155 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_bcsel,
   { &search155_0.value, &search155_0_0.value, &search155_0_1.value },
   NULL,
};

   /* replace155_0 -> search155_0_1 in the cache */

/* replace155_1 -> search155_0_0 in the cache */
static const nir_search_expression replace155 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search155_0_1.value, &search155_0_0.value },
   NULL,
};

   /* search156_0_0 -> search13_0 in the cache */

/* search156_0_1 -> replace13_1_0 in the cache */
/* search156_0 -> search81_0 in the cache */

/* search156_1 -> replace13_1_0 in the cache */

/* search156_2 -> search13_0 in the cache */
static const nir_search_expression search156 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_bcsel,
   { &search81_0.value, &replace13_1_0.value, &search13_0.value },
   NULL,
};

   /* replace156_0 -> search13_0 in the cache */

/* replace156_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace156 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search157_0_0 -> search13_0 in the cache */

/* search157_0_1 -> replace13_1_0 in the cache */
/* search157_0 -> replace81 in the cache */

/* search157_1 -> replace13_1_0 in the cache */

/* search157_2 -> search13_0 in the cache */
static const nir_search_expression search157 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_bcsel,
   { &replace81.value, &replace13_1_0.value, &search13_0.value },
   NULL,
};

   /* replace157_0 -> search13_0 in the cache */

/* replace157_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace157 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search158_0_0 -> search155_0_0 in the cache */

/* search158_0_1 -> search155_0_1 in the cache */
static const nir_search_expression search158_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search155_0_0.value, &search155_0_1.value },
   NULL,
};

/* search158_1 -> search155_0_0 in the cache */

/* search158_2 -> search155_0_1 in the cache */
static const nir_search_expression search158 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_bcsel,
   { &search158_0.value, &search155_0_0.value, &search155_0_1.value },
   NULL,
};

   /* replace158_0 -> search155_0_1 in the cache */

/* replace158_1 -> search155_0_0 in the cache */
static const nir_search_expression replace158 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search155_0_1.value, &search155_0_0.value },
   NULL,
};

   /* search159_0_0 -> search6_0 in the cache */
static const nir_search_expression search159_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_search_op_i2b,
   { &search6_0.value },
   NULL,
};

/* search159_1 -> search27_0_1 in the cache */

/* search159_2 -> search27_1_1 in the cache */
static const nir_search_expression search159 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search159_0.value, &search27_0_1.value, &search27_1_1.value },
   NULL,
};

   /* replace159_0_0 -> search6_0 in the cache */

/* replace159_0_1 -> replace8 in the cache */
/* replace159_0 -> replace132 in the cache */

/* replace159_1 -> search27_0_1 in the cache */

/* replace159_2 -> search27_1_1 in the cache */
static const nir_search_expression replace159 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 1,
   nir_op_bcsel,
   { &replace132.value, &search27_0_1.value, &search27_1_1.value },
   NULL,
};

   /* search160_0_0 -> replace72_0 in the cache */
/* search160_0 -> replace91 in the cache */

/* search160_1 -> search27_0_1 in the cache */

/* search160_2 -> search27_1_1 in the cache */
static const nir_search_expression search160 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace91.value, &search27_0_1.value, &search27_1_1.value },
   NULL,
};

   /* replace160_0 -> replace72_0 in the cache */

/* replace160_1 -> search27_1_1 in the cache */

/* replace160_2 -> search27_0_1 in the cache */
static const nir_search_expression replace160 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search27_1_1.value, &search27_0_1.value },
   NULL,
};

   /* search161_0 -> replace72_0 in the cache */

/* search161_1_0 -> replace72_0 in the cache */

/* search161_1_1 -> search73_0_1 in the cache */

/* search161_1_2 -> search73_0_2 in the cache */
static const nir_search_expression search161_1 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search73_0_1.value, &search73_0_2.value },
   NULL,
};

/* search161_2 -> search73_1 in the cache */
static const nir_search_expression search161 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search161_1.value, &search73_1.value },
   NULL,
};

   /* replace161_0 -> replace72_0 in the cache */

/* replace161_1 -> search73_0_1 in the cache */

/* replace161_2 -> search73_1 in the cache */
static const nir_search_expression replace161 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search73_0_1.value, &search73_1.value },
   NULL,
};

   /* search162_0 -> replace72_0 in the cache */

/* search162_1 -> search73_0_1 in the cache */

/* search162_2_0 -> replace72_0 in the cache */

/* search162_2_1 -> search73_0_2 in the cache */

/* search162_2_2 -> search73_1 in the cache */
static const nir_search_expression search162_2 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression search162 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search73_0_1.value, &search162_2.value },
   NULL,
};

   /* replace162_0 -> replace72_0 in the cache */

/* replace162_1 -> search73_0_1 in the cache */

/* replace162_2 -> search73_1 in the cache */
/* replace162 -> replace161 in the cache */

   /* search163_0 -> replace72_0 in the cache */

/* search163_1_0 -> search93_0_1_0 in the cache */

static const nir_search_variable search163_1_1 = {
   { nir_search_value_variable, -5 },
   2, /* c */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search163_1_2 = {
   { nir_search_value_variable, -5 },
   3, /* d */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search163_1 = {
   { nir_search_value_expression, -5 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search93_0_1_0.value, &search163_1_1.value, &search163_1_2.value },
   NULL,
};

/* search163_2_0 -> search93_0_1_0 in the cache */

/* search163_2_1 -> search163_1_1 in the cache */

static const nir_search_variable search163_2_2 = {
   { nir_search_value_variable, -5 },
   4, /* e */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search163_2 = {
   { nir_search_value_expression, -5 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search93_0_1_0.value, &search163_1_1.value, &search163_2_2.value },
   (is_used_once),
};
static const nir_search_expression search163 = {
   { nir_search_value_expression, -5 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search163_1.value, &search163_2.value },
   NULL,
};

   /* replace163_0 -> search93_0_1_0 in the cache */

/* replace163_1 -> search163_1_1 in the cache */

/* replace163_2_0 -> replace72_0 in the cache */

/* replace163_2_1 -> search163_1_2 in the cache */

/* replace163_2_2 -> search163_2_2 in the cache */
static const nir_search_expression replace163_2 = {
   { nir_search_value_expression, -5 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search163_1_2.value, &search163_2_2.value },
   NULL,
};
static const nir_search_expression replace163 = {
   { nir_search_value_expression, -5 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search93_0_1_0.value, &search163_1_1.value, &replace163_2.value },
   NULL,
};

   /* search164_0 -> replace72_0 in the cache */

/* search164_1_0 -> search93_0_1_0 in the cache */

/* search164_1_1 -> search163_1_1 in the cache */

/* search164_1_2 -> search163_1_2 in the cache */
static const nir_search_expression search164_1 = {
   { nir_search_value_expression, -5 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search93_0_1_0.value, &search163_1_1.value, &search163_1_2.value },
   (is_used_once),
};

/* search164_2_0 -> search93_0_1_0 in the cache */

/* search164_2_1 -> search163_1_1 in the cache */

/* search164_2_2 -> search163_2_2 in the cache */
static const nir_search_expression search164_2 = {
   { nir_search_value_expression, -5 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search93_0_1_0.value, &search163_1_1.value, &search163_2_2.value },
   NULL,
};
static const nir_search_expression search164 = {
   { nir_search_value_expression, -5 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search164_1.value, &search164_2.value },
   NULL,
};

   /* replace164_0 -> search93_0_1_0 in the cache */

/* replace164_1 -> search163_1_1 in the cache */

/* replace164_2_0 -> replace72_0 in the cache */

/* replace164_2_1 -> search163_1_2 in the cache */

/* replace164_2_2 -> search163_2_2 in the cache */
/* replace164_2 -> replace163_2 in the cache */
/* replace164 -> replace163 in the cache */

   /* search165_0 -> replace72_0 in the cache */

/* search165_1_0 -> search93_0_1_0 in the cache */

/* search165_1_1 -> search73_0_2 in the cache */

/* search165_1_2 -> search73_1 in the cache */
static const nir_search_expression search165_1 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search93_0_1_0.value, &search73_0_2.value, &search73_1.value },
   NULL,
};

/* search165_2_0 -> search93_0_1_0 in the cache */

static const nir_search_variable search165_2_1 = {
   { nir_search_value_variable, -4 },
   4, /* e */
   false,
   nir_type_invalid,
   NULL,
};

/* search165_2_2 -> search73_1 in the cache */
static const nir_search_expression search165_2 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search93_0_1_0.value, &search165_2_1.value, &search73_1.value },
   (is_used_once),
};
static const nir_search_expression search165 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search165_1.value, &search165_2.value },
   NULL,
};

   /* replace165_0 -> search93_0_1_0 in the cache */

/* replace165_1_0 -> replace72_0 in the cache */

/* replace165_1_1 -> search73_0_2 in the cache */

/* replace165_1_2 -> search165_2_1 in the cache */
static const nir_search_expression replace165_1 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search73_0_2.value, &search165_2_1.value },
   NULL,
};

/* replace165_2 -> search73_1 in the cache */
static const nir_search_expression replace165 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search93_0_1_0.value, &replace165_1.value, &search73_1.value },
   NULL,
};

   /* search166_0 -> replace72_0 in the cache */

/* search166_1_0 -> search93_0_1_0 in the cache */

/* search166_1_1 -> search73_0_2 in the cache */

/* search166_1_2 -> search73_1 in the cache */
static const nir_search_expression search166_1 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search93_0_1_0.value, &search73_0_2.value, &search73_1.value },
   (is_used_once),
};

/* search166_2_0 -> search93_0_1_0 in the cache */

/* search166_2_1 -> search165_2_1 in the cache */

/* search166_2_2 -> search73_1 in the cache */
static const nir_search_expression search166_2 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search93_0_1_0.value, &search165_2_1.value, &search73_1.value },
   NULL,
};
static const nir_search_expression search166 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search166_1.value, &search166_2.value },
   NULL,
};

   /* replace166_0 -> search93_0_1_0 in the cache */

/* replace166_1_0 -> replace72_0 in the cache */

/* replace166_1_1 -> search73_0_2 in the cache */

/* replace166_1_2 -> search165_2_1 in the cache */
/* replace166_1 -> replace165_1 in the cache */

/* replace166_2 -> search73_1 in the cache */
/* replace166 -> replace165 in the cache */

   /* search167_0 -> replace72_0 in the cache */

/* search167_1 -> replace134 in the cache */

/* search167_2 -> search93_0_1_0 in the cache */
static const nir_search_expression search167 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &replace134.value, &search93_0_1_0.value },
   NULL,
};

   /* replace167_0 -> replace72_0 in the cache */

/* replace167_1 -> search93_0_1_0 in the cache */
/* replace167 -> replace93 in the cache */

   /* search168_0 -> replace72_0 in the cache */

/* search168_1 -> replace72_0 in the cache */

/* search168_2 -> search93_0_1_0 in the cache */
static const nir_search_expression search168 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &replace72_0.value, &search93_0_1_0.value },
   NULL,
};

   /* replace168_0 -> replace72_0 in the cache */

/* replace168_1 -> search93_0_1_0 in the cache */
/* replace168 -> replace93 in the cache */

   /* search169_0 -> replace72_0 in the cache */

/* search169_1 -> search93_0_1_0 in the cache */

/* search169_2 -> replace136 in the cache */
static const nir_search_expression search169 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search93_0_1_0.value, &replace136.value },
   NULL,
};

   /* replace169_0 -> replace72_0 in the cache */

/* replace169_1 -> search93_0_1_0 in the cache */
/* replace169 -> replace97 in the cache */

   /* search170_0 -> replace72_0 in the cache */

/* search170_1 -> search93_0_1_0 in the cache */

/* search170_2 -> replace72_0 in the cache */
static const nir_search_expression search170 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search93_0_1_0.value, &replace72_0.value },
   NULL,
};

   /* replace170_0 -> replace72_0 in the cache */

/* replace170_1 -> search93_0_1_0 in the cache */
/* replace170 -> replace97 in the cache */

   /* search171_0 -> search6_0 in the cache */

/* search171_1 -> search6_0 in the cache */
static const nir_search_expression search171 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace171 -> search6_0 in the cache */

   /* search172_0 -> search6_0 in the cache */

/* search172_1 -> search6_0 in the cache */
static const nir_search_expression search172 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace172 -> search6_0 in the cache */

   /* search173_0 -> search6_0 in the cache */

/* search173_1 -> search6_0 in the cache */
static const nir_search_expression search173 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_imin,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace173 -> search6_0 in the cache */

   /* search174_0 -> search6_0 in the cache */

/* search174_1 -> search6_0 in the cache */
static const nir_search_expression search174 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_imax,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace174 -> search6_0 in the cache */

   /* search175_0 -> search6_0 in the cache */

/* search175_1 -> search6_0 in the cache */
static const nir_search_expression search175 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_umin,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace175 -> search6_0 in the cache */

   /* search176_0 -> search6_0 in the cache */

/* search176_1 -> search6_0 in the cache */
static const nir_search_expression search176 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_umax,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace176 -> search6_0 in the cache */

   /* search177_0_0 -> search13_0 in the cache */

/* search177_0_1 -> replace13_1_0 in the cache */
/* search177_0 -> replace156 in the cache */

/* search177_1 -> replace13_1_0 in the cache */
static const nir_search_expression search177 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fmax,
   { &replace156.value, &replace13_1_0.value },
   NULL,
};

   /* replace177_0 -> search13_0 in the cache */

/* replace177_1 -> replace13_1_0 in the cache */
/* replace177 -> replace156 in the cache */

   /* search178_0_0 -> search13_0 in the cache */

/* search178_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression search178_0 = {
   { nir_search_value_expression, -2 },
   false,
   1, 1,
   nir_op_umax,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

/* search178_1 -> replace13_1_0 in the cache */
static const nir_search_expression search178 = {
   { nir_search_value_expression, -2 },
   false,
   0, 2,
   nir_op_umax,
   { &search178_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace178_0 -> search13_0 in the cache */

/* replace178_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace178 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_umax,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search179_0_0 -> search13_0 in the cache */

/* search179_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression search179_0 = {
   { nir_search_value_expression, -2 },
   false,
   1, 1,
   nir_op_imax,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

/* search179_1 -> replace13_1_0 in the cache */
static const nir_search_expression search179 = {
   { nir_search_value_expression, -2 },
   false,
   0, 2,
   nir_op_imax,
   { &search179_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace179_0 -> search13_0 in the cache */

/* replace179_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace179 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_imax,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search180_0_0 -> search13_0 in the cache */

/* search180_0_1 -> replace13_1_0 in the cache */
/* search180_0 -> replace157 in the cache */

/* search180_1 -> replace13_1_0 in the cache */
static const nir_search_expression search180 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fmin,
   { &replace157.value, &replace13_1_0.value },
   NULL,
};

   /* replace180_0 -> search13_0 in the cache */

/* replace180_1 -> replace13_1_0 in the cache */
/* replace180 -> replace157 in the cache */

   /* search181_0_0 -> search13_0 in the cache */

/* search181_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression search181_0 = {
   { nir_search_value_expression, -2 },
   false,
   1, 1,
   nir_op_umin,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

/* search181_1 -> replace13_1_0 in the cache */
static const nir_search_expression search181 = {
   { nir_search_value_expression, -2 },
   false,
   0, 2,
   nir_op_umin,
   { &search181_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace181_0 -> search13_0 in the cache */

/* replace181_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace181 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_umin,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search182_0_0 -> search13_0 in the cache */

/* search182_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression search182_0 = {
   { nir_search_value_expression, -2 },
   false,
   1, 1,
   nir_op_imin,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

/* search182_1 -> replace13_1_0 in the cache */
static const nir_search_expression search182 = {
   { nir_search_value_expression, -2 },
   false,
   0, 2,
   nir_op_imin,
   { &search182_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace182_0 -> search13_0 in the cache */

/* replace182_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace182 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_imin,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search183_0 -> search6_0 in the cache */

/* search183_1_0 -> search6_0 in the cache */
/* search183_1 -> search14_0 in the cache */
static const nir_search_expression search183 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search6_0.value, &search14_0.value },
   NULL,
};

   /* replace183_0 -> search6_0 in the cache */
/* replace183 -> search16_0 in the cache */

   /* search184_0 -> search6_0 in the cache */

/* search184_1_0 -> search6_0 in the cache */
/* search184_1 -> search15_0 in the cache */
static const nir_search_expression search184 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_imax,
   { &search6_0.value, &search15_0.value },
   NULL,
};

   /* replace184_0 -> search6_0 in the cache */
/* replace184 -> search19_0 in the cache */

   /* search185_0 -> search6_0 in the cache */

/* search185_1_0 -> search6_0 in the cache */
/* search185_1 -> search14_0 in the cache */
static const nir_search_expression search185 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search6_0.value, &search14_0.value },
   NULL,
};

   /* replace185_0_0 -> search6_0 in the cache */
/* replace185_0 -> search16_0 in the cache */
/* replace185 -> search145_0 in the cache */

   /* search186_0 -> search6_0 in the cache */

/* search186_1_0 -> search6_0 in the cache */
/* search186_1 -> search15_0 in the cache */
static const nir_search_expression search186 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_imin,
   { &search6_0.value, &search15_0.value },
   NULL,
};

   /* replace186_0_0 -> search6_0 in the cache */
/* replace186_0 -> search19_0 in the cache */
static const nir_search_expression replace186 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search19_0.value },
   NULL,
};

   /* search187_0 -> search6_0 in the cache */

/* search187_1_0_0 -> search6_0 in the cache */
/* search187_1_0 -> search16_0 in the cache */
/* search187_1 -> search145_0 in the cache */
static const nir_search_expression search187 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search6_0.value, &search145_0.value },
   NULL,
};

   /* replace187_0_0 -> search6_0 in the cache */
/* replace187_0 -> search16_0 in the cache */
/* replace187 -> search145_0 in the cache */

   /* search188_0 -> search6_0 in the cache */

/* search188_1_0_0 -> search6_0 in the cache */
/* search188_1_0 -> search19_0 in the cache */
/* search188_1 -> replace186 in the cache */
static const nir_search_expression search188 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_imin,
   { &search6_0.value, &replace186.value },
   NULL,
};

   /* replace188_0_0 -> search6_0 in the cache */
/* replace188_0 -> search19_0 in the cache */
/* replace188 -> replace186 in the cache */

   /* search189_0 -> search6_0 in the cache */

/* search189_1_0 -> search6_0 in the cache */
/* search189_1 -> search16_0 in the cache */
static const nir_search_expression search189 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search6_0.value, &search16_0.value },
   NULL,
};

   /* replace189 -> search6_0 in the cache */

   /* search190_0 -> search6_0 in the cache */

/* search190_1_0 -> search6_0 in the cache */
/* search190_1 -> search19_0 in the cache */
static const nir_search_expression search190 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_imin,
   { &search6_0.value, &search19_0.value },
   NULL,
};

   /* replace190 -> search6_0 in the cache */

   /* search191_0 -> search6_0 in the cache */

/* search191_1_0_0 -> search6_0 in the cache */
/* search191_1_0 -> search16_0 in the cache */
/* search191_1 -> search145_0 in the cache */
static const nir_search_expression search191 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search6_0.value, &search145_0.value },
   NULL,
};

   /* replace191 -> search6_0 in the cache */

   /* search192_0 -> search6_0 in the cache */

/* search192_1_0_0 -> search6_0 in the cache */
/* search192_1_0 -> search19_0 in the cache */
/* search192_1 -> replace186 in the cache */
static const nir_search_expression search192 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_imax,
   { &search6_0.value, &replace186.value },
   NULL,
};

   /* replace192 -> search6_0 in the cache */

   /* search193_0 -> search6_0 in the cache */

/* search193_1_0 -> search6_0 in the cache */
/* search193_1 -> search16_0 in the cache */
static const nir_search_expression search193 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search6_0.value, &search16_0.value },
   NULL,
};

   /* replace193_0 -> search6_0 in the cache */
/* replace193 -> search16_0 in the cache */

   /* search194_0 -> search6_0 in the cache */

/* search194_1_0 -> search6_0 in the cache */
/* search194_1 -> search19_0 in the cache */
static const nir_search_expression search194 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_imax,
   { &search6_0.value, &search19_0.value },
   NULL,
};

   /* replace194_0 -> search6_0 in the cache */
/* replace194 -> search19_0 in the cache */

   /* search195_0 -> search6_0 in the cache */

/* search195_1_0 -> search6_0 in the cache */
/* search195_1 -> search14_0 in the cache */
/* search195 -> search183 in the cache */

   /* replace195_0 -> search6_0 in the cache */
/* replace195 -> search16_0 in the cache */

   /* search196_0 -> search6_0 in the cache */

/* search196_1_0 -> search6_0 in the cache */
/* search196_1 -> search15_0 in the cache */
/* search196 -> search184 in the cache */

   /* replace196_0 -> search6_0 in the cache */
/* replace196 -> search19_0 in the cache */

   /* search197_0_0 -> search6_0 in the cache */

/* search197_0_1 -> search23_1 in the cache */
static const nir_search_expression search197_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search6_0.value, &search23_1.value },
   NULL,
};

/* search197_1 -> search39_1 in the cache */
static const nir_search_expression search197 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_fmin,
   { &search197_0.value, &search39_1.value },
   NULL,
};

   /* replace197_0 -> search6_0 in the cache */
static const nir_search_expression replace197 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fsat,
   { &search6_0.value },
   NULL,
};

   /* search198_0_0 -> search6_0 in the cache */

/* search198_0_1 -> search39_1 in the cache */
static const nir_search_expression search198_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search6_0.value, &search39_1.value },
   NULL,
};

/* search198_1 -> search23_1 in the cache */
static const nir_search_expression search198 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_fmax,
   { &search198_0.value, &search23_1.value },
   NULL,
};

   /* replace198_0 -> search6_0 in the cache */
/* replace198 -> replace197 in the cache */

   /* search199_0_0 -> search6_0 in the cache */
/* search199_0 -> search43_0 in the cache */
static const nir_search_expression search199 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fsat,
   { &search43_0.value },
   NULL,
};

   /* replace199_0_0 -> search23_1 in the cache */

/* replace199_0_1 -> search6_0 in the cache */
static const nir_search_expression replace199_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search23_1.value, &search6_0.value },
   NULL,
};
static const nir_search_expression replace199 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &replace199_0.value },
   NULL,
};

   /* search200_0_0 -> search6_0 in the cache */
static const nir_search_expression search200_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search200 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_fsat,
   { &search200_0.value },
   NULL,
};

   /* replace200_0 -> search6_0 in the cache */
/* replace200 -> search200_0 in the cache */

   /* search201_0 -> search6_0 in the cache */
/* search201 -> replace197 in the cache */

   /* replace201_0_0 -> search6_0 in the cache */

/* replace201_0_1 -> search23_1 in the cache */
/* replace201_0 -> search197_0 in the cache */

/* replace201_1 -> search39_1 in the cache */
static const nir_search_expression replace201 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search197_0.value, &search39_1.value },
   NULL,
};

   /* search202_0_0 -> search6_0 in the cache */
/* search202_0 -> replace197 in the cache */
static const nir_search_expression search202 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fsat,
   { &replace197.value },
   NULL,
};

   /* replace202_0 -> search6_0 in the cache */
/* replace202 -> replace197 in the cache */

   /* search203_0_0_0_0 -> search27_0_0 in the cache */

/* search203_0_0_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search203_0_0_0 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search27_0_0.value, &search27_0_1.value },
   NULL,
};

/* search203_0_0_1 -> search27_1_1 in the cache */
static const nir_search_expression search203_0_0 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search203_0_0_0.value, &search27_1_1.value },
   NULL,
};

/* search203_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search203_0 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search203_0_0.value, &search27_0_1.value },
   NULL,
};

/* search203_1 -> search27_1_1 in the cache */
static const nir_search_expression search203 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search203_0.value, &search27_1_1.value },
   NULL,
};

   /* replace203_0_0 -> search27_0_0 in the cache */

/* replace203_0_1 -> search27_0_1 in the cache */
/* replace203_0 -> search203_0_0_0 in the cache */

/* replace203_1 -> search27_1_1 in the cache */
/* replace203 -> search203_0_0 in the cache */

   /* search204_0_0_0_0 -> search27_0_0 in the cache */

/* search204_0_0_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search204_0_0_0 = {
   { nir_search_value_expression, -3 },
   false,
   3, 1,
   nir_op_imax,
   { &search27_0_0.value, &search27_0_1.value },
   NULL,
};

/* search204_0_0_1 -> search27_1_1 in the cache */
static const nir_search_expression search204_0_0 = {
   { nir_search_value_expression, -3 },
   false,
   2, 2,
   nir_op_imin,
   { &search204_0_0_0.value, &search27_1_1.value },
   NULL,
};

/* search204_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search204_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 3,
   nir_op_imax,
   { &search204_0_0.value, &search27_0_1.value },
   NULL,
};

/* search204_1 -> search27_1_1 in the cache */
static const nir_search_expression search204 = {
   { nir_search_value_expression, -3 },
   false,
   0, 4,
   nir_op_imin,
   { &search204_0.value, &search27_1_1.value },
   NULL,
};

   /* replace204_0_0 -> search27_0_0 in the cache */

/* replace204_0_1 -> search27_0_1 in the cache */
static const nir_search_expression replace204_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_imax,
   { &search27_0_0.value, &search27_0_1.value },
   NULL,
};

/* replace204_1 -> search27_1_1 in the cache */
static const nir_search_expression replace204 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_imin,
   { &replace204_0.value, &search27_1_1.value },
   NULL,
};

   /* search205_0_0_0_0 -> search27_0_0 in the cache */

/* search205_0_0_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search205_0_0_0 = {
   { nir_search_value_expression, -3 },
   false,
   3, 1,
   nir_op_umax,
   { &search27_0_0.value, &search27_0_1.value },
   NULL,
};

/* search205_0_0_1 -> search27_1_1 in the cache */
static const nir_search_expression search205_0_0 = {
   { nir_search_value_expression, -3 },
   false,
   2, 2,
   nir_op_umin,
   { &search205_0_0_0.value, &search27_1_1.value },
   NULL,
};

/* search205_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search205_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 3,
   nir_op_umax,
   { &search205_0_0.value, &search27_0_1.value },
   NULL,
};

/* search205_1 -> search27_1_1 in the cache */
static const nir_search_expression search205 = {
   { nir_search_value_expression, -3 },
   false,
   0, 4,
   nir_op_umin,
   { &search205_0.value, &search27_1_1.value },
   NULL,
};

   /* replace205_0_0 -> search27_0_0 in the cache */

/* replace205_0_1 -> search27_0_1 in the cache */
static const nir_search_expression replace205_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_umax,
   { &search27_0_0.value, &search27_0_1.value },
   NULL,
};

/* replace205_1 -> search27_1_1 in the cache */
static const nir_search_expression replace205 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_umin,
   { &replace205_0.value, &search27_1_1.value },
   NULL,
};

   /* search206_0_0 -> search0_0 in the cache */
static const nir_search_expression search206_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fsat,
   { &search0_0.value },
   NULL,
};

static const nir_search_variable search206_1 = {
   { nir_search_value_variable, 32 },
   1, /* b */
   true,
   nir_type_invalid,
   (is_zero_to_one),
};
static const nir_search_expression search206 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search206_0.value, &search206_1.value },
   NULL,
};

   /* replace206_0_0 -> search0_0 in the cache */

/* replace206_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace206_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace206 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fsat,
   { &replace206_0.value },
   NULL,
};

   /* search207_0_0 -> search0_0 in the cache */
/* search207_0 -> search206_0 in the cache */

/* search207_1 -> search206_1 in the cache */
static const nir_search_expression search207 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search206_0.value, &search206_1.value },
   NULL,
};

   /* replace207_0_0 -> search0_0 in the cache */

/* replace207_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace207_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace207 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fsat,
   { &replace207_0.value },
   NULL,
};

   /* search208_0_0_0 -> search6_0 in the cache */

/* search208_0_0_1 -> replace8 in the cache */
static const nir_search_expression search208_0_0 = {
   { nir_search_value_expression, -1 },
   false,
   1, 1,
   nir_op_imax,
   { &search6_0.value, &replace8.value },
   NULL,
};

static const nir_search_constant search208_0_1 = {
   { nir_search_value_constant, -1 },
   nir_type_int, { 0xff /* 255 */ },
};
static const nir_search_expression search208_0 = {
   { nir_search_value_expression, -1 },
   false,
   0, 2,
   nir_op_imin,
   { &search208_0_0.value, &search208_0_1.value },
   NULL,
};

/* search208_1 -> replace8 in the cache */
static const nir_search_expression search208 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 2,
   nir_op_extract_u8,
   { &search208_0.value, &replace8.value },
   NULL,
};

   /* replace208_0_0 -> search6_0 in the cache */

/* replace208_0_1 -> replace8 in the cache */
/* replace208_0 -> search208_0_0 in the cache */

/* replace208_1 -> search208_0_1 in the cache */
/* replace208 -> search208_0 in the cache */

   /* search209_0_0 -> search27_0_0 in the cache */

/* search209_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search209_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search27_0_0.value, &search27_0_1.value },
   (is_used_once),
};

/* search209_1_0 -> search27_0_0 in the cache */

/* search209_1_1 -> search27_1_1 in the cache */
static const nir_search_expression search209_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search27_0_0.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression search209 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_ior,
   { &search209_0.value, &search209_1.value },
   NULL,
};

   /* replace209_0 -> search27_0_0 in the cache */

/* replace209_1_0 -> search27_0_1 in the cache */

/* replace209_1_1 -> search27_1_1 in the cache */
static const nir_search_expression replace209_1 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search27_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression replace209 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search27_0_0.value, &replace209_1.value },
   NULL,
};

   /* search210_0_0 -> search13_0 in the cache */

/* search210_0_1 -> search55_2 in the cache */
static const nir_search_expression search210_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search13_0.value, &search55_2.value },
   (is_used_once),
};

static const nir_search_variable search210_1_0 = {
   { nir_search_value_variable, -2 },
   2, /* b */
   false,
   nir_type_invalid,
   NULL,
};

/* search210_1_1 -> search55_2 in the cache */
static const nir_search_expression search210_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search210_1_0.value, &search55_2.value },
   NULL,
};
static const nir_search_expression search210 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_ior,
   { &search210_0.value, &search210_1.value },
   NULL,
};

   /* replace210_0_0 -> search13_0 in the cache */

/* replace210_0_1 -> search210_1_0 in the cache */
static const nir_search_expression replace210_0 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search13_0.value, &search210_1_0.value },
   NULL,
};

/* replace210_1 -> search55_2 in the cache */
static const nir_search_expression replace210 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &replace210_0.value, &search55_2.value },
   NULL,
};

   /* search211_0_0 -> search27_0_0 in the cache */

/* search211_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search211_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search27_0_0.value, &search27_0_1.value },
   (is_used_once),
};

/* search211_1_0 -> search27_0_0 in the cache */

/* search211_1_1 -> search27_1_1 in the cache */
static const nir_search_expression search211_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search27_0_0.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression search211 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_ior,
   { &search211_0.value, &search211_1.value },
   NULL,
};

   /* replace211_0 -> search27_0_0 in the cache */

/* replace211_1_0 -> search27_0_1 in the cache */

/* replace211_1_1 -> search27_1_1 in the cache */
static const nir_search_expression replace211_1 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search27_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression replace211 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search27_0_0.value, &replace211_1.value },
   NULL,
};

   /* search212_0_0 -> search13_0 in the cache */

/* search212_0_1 -> search55_2 in the cache */
static const nir_search_expression search212_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search13_0.value, &search55_2.value },
   (is_used_once),
};

/* search212_1_0 -> search210_1_0 in the cache */

/* search212_1_1 -> search55_2 in the cache */
static const nir_search_expression search212_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search210_1_0.value, &search55_2.value },
   NULL,
};
static const nir_search_expression search212 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_ior,
   { &search212_0.value, &search212_1.value },
   NULL,
};

   /* replace212_0_0 -> search13_0 in the cache */

/* replace212_0_1 -> search210_1_0 in the cache */
static const nir_search_expression replace212_0 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search13_0.value, &search210_1_0.value },
   NULL,
};

/* replace212_1 -> search55_2 in the cache */
static const nir_search_expression replace212 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &replace212_0.value, &search55_2.value },
   NULL,
};

   /* search213_0_0 -> search27_0_0 in the cache */

/* search213_0_1 -> search79_0_0_1 in the cache */
static const nir_search_expression search213_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search27_0_0.value, &search79_0_0_1.value },
   NULL,
};

/* search213_1_0 -> search27_0_0 in the cache */

/* search213_1_1 -> search79_0_1 in the cache */
static const nir_search_expression search213_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search27_0_0.value, &search79_0_1.value },
   NULL,
};
static const nir_search_expression search213 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_ior,
   { &search213_0.value, &search213_1.value },
   NULL,
};

   /* replace213_0 -> search27_0_0 in the cache */

/* replace213_1_0 -> search27_0_1 in the cache */

/* replace213_1_1 -> search27_1_1 in the cache */
/* replace213_1 -> replace209_1 in the cache */
/* replace213 -> replace209 in the cache */

   static const nir_search_variable search214_0_0 = {
   { nir_search_value_variable, -2 },
   0, /* a */
   true,
   nir_type_invalid,
   NULL,
};

/* search214_0_1 -> search55_2 in the cache */
static const nir_search_expression search214_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search214_0_0.value, &search55_2.value },
   NULL,
};

static const nir_search_variable search214_1_0 = {
   { nir_search_value_variable, -2 },
   2, /* b */
   true,
   nir_type_invalid,
   NULL,
};

/* search214_1_1 -> search55_2 in the cache */
static const nir_search_expression search214_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search214_1_0.value, &search55_2.value },
   NULL,
};
static const nir_search_expression search214 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_ior,
   { &search214_0.value, &search214_1.value },
   NULL,
};

   /* replace214_0_0 -> search13_0 in the cache */

/* replace214_0_1 -> search210_1_0 in the cache */
/* replace214_0 -> replace210_0 in the cache */

/* replace214_1 -> search55_2 in the cache */
/* replace214 -> replace210 in the cache */

   /* search215_0_0 -> search27_0_0 in the cache */

/* search215_0_1 -> search79_0_0_1 in the cache */
static const nir_search_expression search215_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search27_0_0.value, &search79_0_0_1.value },
   NULL,
};

/* search215_1_0 -> search27_0_0 in the cache */

/* search215_1_1 -> search79_0_1 in the cache */
static const nir_search_expression search215_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search27_0_0.value, &search79_0_1.value },
   NULL,
};
static const nir_search_expression search215 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_ior,
   { &search215_0.value, &search215_1.value },
   NULL,
};

   /* replace215_0 -> search27_0_0 in the cache */

/* replace215_1_0 -> search27_0_1 in the cache */

/* replace215_1_1 -> search27_1_1 in the cache */
/* replace215_1 -> replace211_1 in the cache */
/* replace215 -> replace211 in the cache */

   /* search216_0_0 -> search214_0_0 in the cache */

/* search216_0_1 -> search55_2 in the cache */
static const nir_search_expression search216_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search214_0_0.value, &search55_2.value },
   NULL,
};

/* search216_1_0 -> search214_1_0 in the cache */

/* search216_1_1 -> search55_2 in the cache */
static const nir_search_expression search216_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search214_1_0.value, &search55_2.value },
   NULL,
};
static const nir_search_expression search216 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_ior,
   { &search216_0.value, &search216_1.value },
   NULL,
};

   /* replace216_0_0 -> search13_0 in the cache */

/* replace216_0_1 -> search210_1_0 in the cache */
/* replace216_0 -> replace212_0 in the cache */

/* replace216_1 -> search55_2 in the cache */
/* replace216 -> replace212 in the cache */

   /* search217_0_0 -> search27_0_0 in the cache */

/* search217_0_1 -> search27_0_1 in the cache */
/* search217_0 -> search209_0 in the cache */

/* search217_1_0 -> search27_0_0 in the cache */

/* search217_1_1 -> search27_1_1 in the cache */
/* search217_1 -> search209_1 in the cache */
static const nir_search_expression search217 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_iand,
   { &search209_0.value, &search209_1.value },
   NULL,
};

   /* replace217_0 -> search27_0_0 in the cache */

/* replace217_1_0 -> search27_0_1 in the cache */

/* replace217_1_1 -> search27_1_1 in the cache */
/* replace217_1 -> replace211_1 in the cache */
static const nir_search_expression replace217 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search27_0_0.value, &replace211_1.value },
   NULL,
};

   /* search218_0_0 -> search13_0 in the cache */

/* search218_0_1 -> search55_2 in the cache */
/* search218_0 -> search210_0 in the cache */

/* search218_1_0 -> search210_1_0 in the cache */

/* search218_1_1 -> search55_2 in the cache */
/* search218_1 -> search210_1 in the cache */
static const nir_search_expression search218 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_iand,
   { &search210_0.value, &search210_1.value },
   NULL,
};

   /* replace218_0_0 -> search13_0 in the cache */

/* replace218_0_1 -> search210_1_0 in the cache */
/* replace218_0 -> replace212_0 in the cache */

/* replace218_1 -> search55_2 in the cache */
static const nir_search_expression replace218 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &replace212_0.value, &search55_2.value },
   NULL,
};

   /* search219_0_0 -> search27_0_0 in the cache */

/* search219_0_1 -> search27_0_1 in the cache */
/* search219_0 -> search211_0 in the cache */

/* search219_1_0 -> search27_0_0 in the cache */

/* search219_1_1 -> search27_1_1 in the cache */
/* search219_1 -> search211_1 in the cache */
static const nir_search_expression search219 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_iand,
   { &search211_0.value, &search211_1.value },
   NULL,
};

   /* replace219_0 -> search27_0_0 in the cache */

/* replace219_1_0 -> search27_0_1 in the cache */

/* replace219_1_1 -> search27_1_1 in the cache */
/* replace219_1 -> replace209_1 in the cache */
static const nir_search_expression replace219 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search27_0_0.value, &replace209_1.value },
   NULL,
};

   /* search220_0_0 -> search13_0 in the cache */

/* search220_0_1 -> search55_2 in the cache */
/* search220_0 -> search212_0 in the cache */

/* search220_1_0 -> search210_1_0 in the cache */

/* search220_1_1 -> search55_2 in the cache */
/* search220_1 -> search212_1 in the cache */
static const nir_search_expression search220 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_iand,
   { &search212_0.value, &search212_1.value },
   NULL,
};

   /* replace220_0_0 -> search13_0 in the cache */

/* replace220_0_1 -> search210_1_0 in the cache */
/* replace220_0 -> replace210_0 in the cache */

/* replace220_1 -> search55_2 in the cache */
static const nir_search_expression replace220 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &replace210_0.value, &search55_2.value },
   NULL,
};

   /* search221_0_0 -> search27_0_0 in the cache */

/* search221_0_1 -> search79_0_0_1 in the cache */
/* search221_0 -> search213_0 in the cache */

/* search221_1_0 -> search27_0_0 in the cache */

/* search221_1_1 -> search79_0_1 in the cache */
/* search221_1 -> search213_1 in the cache */
static const nir_search_expression search221 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_iand,
   { &search213_0.value, &search213_1.value },
   NULL,
};

   /* replace221_0 -> search27_0_0 in the cache */

/* replace221_1_0 -> search27_0_1 in the cache */

/* replace221_1_1 -> search27_1_1 in the cache */
/* replace221_1 -> replace211_1 in the cache */
/* replace221 -> replace217 in the cache */

   /* search222_0_0 -> search214_0_0 in the cache */

/* search222_0_1 -> search55_2 in the cache */
/* search222_0 -> search214_0 in the cache */

/* search222_1_0 -> search214_1_0 in the cache */

/* search222_1_1 -> search55_2 in the cache */
/* search222_1 -> search214_1 in the cache */
static const nir_search_expression search222 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_iand,
   { &search214_0.value, &search214_1.value },
   NULL,
};

   /* replace222_0_0 -> search13_0 in the cache */

/* replace222_0_1 -> search210_1_0 in the cache */
/* replace222_0 -> replace212_0 in the cache */

/* replace222_1 -> search55_2 in the cache */
/* replace222 -> replace218 in the cache */

   /* search223_0_0 -> search27_0_0 in the cache */

/* search223_0_1 -> search79_0_0_1 in the cache */
/* search223_0 -> search215_0 in the cache */

/* search223_1_0 -> search27_0_0 in the cache */

/* search223_1_1 -> search79_0_1 in the cache */
/* search223_1 -> search215_1 in the cache */
static const nir_search_expression search223 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_iand,
   { &search215_0.value, &search215_1.value },
   NULL,
};

   /* replace223_0 -> search27_0_0 in the cache */

/* replace223_1_0 -> search27_0_1 in the cache */

/* replace223_1_1 -> search27_1_1 in the cache */
/* replace223_1 -> replace209_1 in the cache */
/* replace223 -> replace219 in the cache */

   /* search224_0_0 -> search214_0_0 in the cache */

/* search224_0_1 -> search55_2 in the cache */
/* search224_0 -> search216_0 in the cache */

/* search224_1_0 -> search214_1_0 in the cache */

/* search224_1_1 -> search55_2 in the cache */
/* search224_1 -> search216_1 in the cache */
static const nir_search_expression search224 = {
   { nir_search_value_expression, 1 },
   true,
   0, 1,
   nir_op_iand,
   { &search216_0.value, &search216_1.value },
   NULL,
};

   /* replace224_0_0 -> search13_0 in the cache */

/* replace224_0_1 -> search210_1_0 in the cache */
/* replace224_0 -> replace210_0 in the cache */

/* replace224_1 -> search55_2 in the cache */
/* replace224 -> replace220 in the cache */

   /* search225_0_0 -> search27_0_0 in the cache */

/* search225_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search225_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search27_0_0.value, &search27_0_1.value },
   (is_used_once),
};

/* search225_1_0 -> search27_0_0 in the cache */

/* search225_1_1 -> search27_1_1 in the cache */
static const nir_search_expression search225_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search27_0_0.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression search225 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search225_0.value, &search225_1.value },
   NULL,
};

   /* replace225_0 -> search27_0_0 in the cache */

/* replace225_1_0 -> search27_0_1 in the cache */

/* replace225_1_1 -> search27_1_1 in the cache */
static const nir_search_expression replace225_1 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_imax,
   { &search27_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression replace225 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &search27_0_0.value, &replace225_1.value },
   NULL,
};

   /* search226_0_0 -> search13_0 in the cache */

/* search226_0_1 -> search55_2 in the cache */
static const nir_search_expression search226_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search13_0.value, &search55_2.value },
   (is_used_once),
};

/* search226_1_0 -> search210_1_0 in the cache */

/* search226_1_1 -> search55_2 in the cache */
static const nir_search_expression search226_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search210_1_0.value, &search55_2.value },
   NULL,
};
static const nir_search_expression search226 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search226_0.value, &search226_1.value },
   NULL,
};

   /* replace226_0_0 -> search13_0 in the cache */

/* replace226_0_1 -> search210_1_0 in the cache */
static const nir_search_expression replace226_0 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_imin,
   { &search13_0.value, &search210_1_0.value },
   NULL,
};

/* replace226_1 -> search55_2 in the cache */
static const nir_search_expression replace226 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &replace226_0.value, &search55_2.value },
   NULL,
};

   /* search227_0_0 -> search27_0_0 in the cache */

/* search227_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search227_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search27_0_0.value, &search27_0_1.value },
   (is_used_once),
};

/* search227_1_0 -> search27_0_0 in the cache */

/* search227_1_1 -> search27_1_1 in the cache */
static const nir_search_expression search227_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search27_0_0.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression search227 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search227_0.value, &search227_1.value },
   NULL,
};

   /* replace227_0 -> search27_0_0 in the cache */

/* replace227_1_0 -> search27_0_1 in the cache */

/* replace227_1_1 -> search27_1_1 in the cache */
static const nir_search_expression replace227_1 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_imin,
   { &search27_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression replace227 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ige,
   { &search27_0_0.value, &replace227_1.value },
   NULL,
};

   /* search228_0_0 -> search13_0 in the cache */

/* search228_0_1 -> search55_2 in the cache */
static const nir_search_expression search228_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search13_0.value, &search55_2.value },
   (is_used_once),
};

/* search228_1_0 -> search210_1_0 in the cache */

/* search228_1_1 -> search55_2 in the cache */
static const nir_search_expression search228_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search210_1_0.value, &search55_2.value },
   NULL,
};
static const nir_search_expression search228 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search228_0.value, &search228_1.value },
   NULL,
};

   /* replace228_0_0 -> search13_0 in the cache */

/* replace228_0_1 -> search210_1_0 in the cache */
static const nir_search_expression replace228_0 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_imax,
   { &search13_0.value, &search210_1_0.value },
   NULL,
};

/* replace228_1 -> search55_2 in the cache */
static const nir_search_expression replace228 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ige,
   { &replace228_0.value, &search55_2.value },
   NULL,
};

   /* search229_0_0 -> search27_0_0 in the cache */

/* search229_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search229_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search27_0_0.value, &search27_0_1.value },
   (is_used_once),
};

/* search229_1_0 -> search27_0_0 in the cache */

/* search229_1_1 -> search27_1_1 in the cache */
static const nir_search_expression search229_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search27_0_0.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression search229 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search229_0.value, &search229_1.value },
   NULL,
};

   /* replace229_0 -> search27_0_0 in the cache */

/* replace229_1_0 -> search27_0_1 in the cache */

/* replace229_1_1 -> search27_1_1 in the cache */
static const nir_search_expression replace229_1 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_umax,
   { &search27_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression replace229 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &search27_0_0.value, &replace229_1.value },
   NULL,
};

   /* search230_0_0 -> search13_0 in the cache */

/* search230_0_1 -> search55_2 in the cache */
static const nir_search_expression search230_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search13_0.value, &search55_2.value },
   (is_used_once),
};

/* search230_1_0 -> search210_1_0 in the cache */

/* search230_1_1 -> search55_2 in the cache */
static const nir_search_expression search230_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search210_1_0.value, &search55_2.value },
   NULL,
};
static const nir_search_expression search230 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search230_0.value, &search230_1.value },
   NULL,
};

   /* replace230_0_0 -> search13_0 in the cache */

/* replace230_0_1 -> search210_1_0 in the cache */
static const nir_search_expression replace230_0 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_umin,
   { &search13_0.value, &search210_1_0.value },
   NULL,
};

/* replace230_1 -> search55_2 in the cache */
static const nir_search_expression replace230 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &replace230_0.value, &search55_2.value },
   NULL,
};

   /* search231_0_0 -> search27_0_0 in the cache */

/* search231_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search231_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search27_0_0.value, &search27_0_1.value },
   (is_used_once),
};

/* search231_1_0 -> search27_0_0 in the cache */

/* search231_1_1 -> search27_1_1 in the cache */
static const nir_search_expression search231_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search27_0_0.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression search231 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search231_0.value, &search231_1.value },
   NULL,
};

   /* replace231_0 -> search27_0_0 in the cache */

/* replace231_1_0 -> search27_0_1 in the cache */

/* replace231_1_1 -> search27_1_1 in the cache */
static const nir_search_expression replace231_1 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_umin,
   { &search27_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression replace231 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_uge,
   { &search27_0_0.value, &replace231_1.value },
   NULL,
};

   /* search232_0_0 -> search13_0 in the cache */

/* search232_0_1 -> search55_2 in the cache */
static const nir_search_expression search232_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search13_0.value, &search55_2.value },
   (is_used_once),
};

/* search232_1_0 -> search210_1_0 in the cache */

/* search232_1_1 -> search55_2 in the cache */
static const nir_search_expression search232_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search210_1_0.value, &search55_2.value },
   NULL,
};
static const nir_search_expression search232 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search232_0.value, &search232_1.value },
   NULL,
};

   /* replace232_0_0 -> search13_0 in the cache */

/* replace232_0_1 -> search210_1_0 in the cache */
static const nir_search_expression replace232_0 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_umax,
   { &search13_0.value, &search210_1_0.value },
   NULL,
};

/* replace232_1 -> search55_2 in the cache */
static const nir_search_expression replace232 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_uge,
   { &replace232_0.value, &search55_2.value },
   NULL,
};

   /* search233_0_0 -> search27_0_0 in the cache */

/* search233_0_1 -> search27_0_1 in the cache */
/* search233_0 -> search225_0 in the cache */

/* search233_1_0 -> search27_0_0 in the cache */

/* search233_1_1 -> search27_1_1 in the cache */
/* search233_1 -> search225_1 in the cache */
static const nir_search_expression search233 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search225_0.value, &search225_1.value },
   NULL,
};

   /* replace233_0 -> search27_0_0 in the cache */

/* replace233_1_0 -> search27_0_1 in the cache */

/* replace233_1_1 -> search27_1_1 in the cache */
/* replace233_1 -> replace227_1 in the cache */
static const nir_search_expression replace233 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &search27_0_0.value, &replace227_1.value },
   NULL,
};

   /* search234_0_0 -> search13_0 in the cache */

/* search234_0_1 -> search55_2 in the cache */
/* search234_0 -> search226_0 in the cache */

/* search234_1_0 -> search210_1_0 in the cache */

/* search234_1_1 -> search55_2 in the cache */
/* search234_1 -> search226_1 in the cache */
static const nir_search_expression search234 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search226_0.value, &search226_1.value },
   NULL,
};

   /* replace234_0_0 -> search13_0 in the cache */

/* replace234_0_1 -> search210_1_0 in the cache */
/* replace234_0 -> replace228_0 in the cache */

/* replace234_1 -> search55_2 in the cache */
static const nir_search_expression replace234 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &replace228_0.value, &search55_2.value },
   NULL,
};

   /* search235_0_0 -> search27_0_0 in the cache */

/* search235_0_1 -> search27_0_1 in the cache */
/* search235_0 -> search227_0 in the cache */

/* search235_1_0 -> search27_0_0 in the cache */

/* search235_1_1 -> search27_1_1 in the cache */
/* search235_1 -> search227_1 in the cache */
static const nir_search_expression search235 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search227_0.value, &search227_1.value },
   NULL,
};

   /* replace235_0 -> search27_0_0 in the cache */

/* replace235_1_0 -> search27_0_1 in the cache */

/* replace235_1_1 -> search27_1_1 in the cache */
/* replace235_1 -> replace225_1 in the cache */
static const nir_search_expression replace235 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ige,
   { &search27_0_0.value, &replace225_1.value },
   NULL,
};

   /* search236_0_0 -> search13_0 in the cache */

/* search236_0_1 -> search55_2 in the cache */
/* search236_0 -> search228_0 in the cache */

/* search236_1_0 -> search210_1_0 in the cache */

/* search236_1_1 -> search55_2 in the cache */
/* search236_1 -> search228_1 in the cache */
static const nir_search_expression search236 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search228_0.value, &search228_1.value },
   NULL,
};

   /* replace236_0_0 -> search13_0 in the cache */

/* replace236_0_1 -> search210_1_0 in the cache */
/* replace236_0 -> replace226_0 in the cache */

/* replace236_1 -> search55_2 in the cache */
static const nir_search_expression replace236 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ige,
   { &replace226_0.value, &search55_2.value },
   NULL,
};

   /* search237_0_0 -> search27_0_0 in the cache */

/* search237_0_1 -> search27_0_1 in the cache */
/* search237_0 -> search229_0 in the cache */

/* search237_1_0 -> search27_0_0 in the cache */

/* search237_1_1 -> search27_1_1 in the cache */
/* search237_1 -> search229_1 in the cache */
static const nir_search_expression search237 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search229_0.value, &search229_1.value },
   NULL,
};

   /* replace237_0 -> search27_0_0 in the cache */

/* replace237_1_0 -> search27_0_1 in the cache */

/* replace237_1_1 -> search27_1_1 in the cache */
/* replace237_1 -> replace231_1 in the cache */
static const nir_search_expression replace237 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &search27_0_0.value, &replace231_1.value },
   NULL,
};

   /* search238_0_0 -> search13_0 in the cache */

/* search238_0_1 -> search55_2 in the cache */
/* search238_0 -> search230_0 in the cache */

/* search238_1_0 -> search210_1_0 in the cache */

/* search238_1_1 -> search55_2 in the cache */
/* search238_1 -> search230_1 in the cache */
static const nir_search_expression search238 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search230_0.value, &search230_1.value },
   NULL,
};

   /* replace238_0_0 -> search13_0 in the cache */

/* replace238_0_1 -> search210_1_0 in the cache */
/* replace238_0 -> replace232_0 in the cache */

/* replace238_1 -> search55_2 in the cache */
static const nir_search_expression replace238 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &replace232_0.value, &search55_2.value },
   NULL,
};

   /* search239_0_0 -> search27_0_0 in the cache */

/* search239_0_1 -> search27_0_1 in the cache */
/* search239_0 -> search231_0 in the cache */

/* search239_1_0 -> search27_0_0 in the cache */

/* search239_1_1 -> search27_1_1 in the cache */
/* search239_1 -> search231_1 in the cache */
static const nir_search_expression search239 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search231_0.value, &search231_1.value },
   NULL,
};

   /* replace239_0 -> search27_0_0 in the cache */

/* replace239_1_0 -> search27_0_1 in the cache */

/* replace239_1_1 -> search27_1_1 in the cache */
/* replace239_1 -> replace229_1 in the cache */
static const nir_search_expression replace239 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_uge,
   { &search27_0_0.value, &replace229_1.value },
   NULL,
};

   /* search240_0_0 -> search13_0 in the cache */

/* search240_0_1 -> search55_2 in the cache */
/* search240_0 -> search232_0 in the cache */

/* search240_1_0 -> search210_1_0 in the cache */

/* search240_1_1 -> search55_2 in the cache */
/* search240_1 -> search232_1 in the cache */
static const nir_search_expression search240 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search232_0.value, &search232_1.value },
   NULL,
};

   /* replace240_0_0 -> search13_0 in the cache */

/* replace240_0_1 -> search210_1_0 in the cache */
/* replace240_0 -> replace230_0 in the cache */

/* replace240_1 -> search55_2 in the cache */
static const nir_search_expression replace240 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_uge,
   { &replace230_0.value, &search55_2.value },
   NULL,
};

   /* search241_0_0 -> search6_0 in the cache */

/* search241_0_1 -> replace8 in the cache */
static const nir_search_expression search241_0 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_ieq,
   { &search6_0.value, &replace8.value },
   NULL,
};

/* search241_1_0 -> search6_0 in the cache */

/* search241_1_1 -> search6_1 in the cache */
static const nir_search_expression search241_1 = {
   { nir_search_value_expression, 1 },
   false,
   2, 1,
   nir_op_ieq,
   { &search6_0.value, &search6_1.value },
   NULL,
};
static const nir_search_expression search241 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_ior,
   { &search241_0.value, &search241_1.value },
   NULL,
};

   /* replace241_0 -> search6_1 in the cache */

/* replace241_1 -> search6_0 in the cache */
static const nir_search_expression replace241 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search6_1.value, &search6_0.value },
   NULL,
};

   /* search242_0_0 -> search6_1 in the cache */

/* search242_0_1 -> search6_0 in the cache */
/* search242_0 -> replace241 in the cache */

/* search242_1_0 -> search6_0 in the cache */

static const nir_search_constant search242_1_1 = {
   { nir_search_value_constant, -1 },
   nir_type_int, { 0x2 /* 2 */ },
};
static const nir_search_expression search242_1 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_ieq,
   { &search6_0.value, &search242_1_1.value },
   NULL,
};
static const nir_search_expression search242 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ior,
   { &replace241.value, &search242_1.value },
   NULL,
};

   /* replace242_0 -> search242_1_1 in the cache */

/* replace242_1 -> search6_0 in the cache */
static const nir_search_expression replace242 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search242_1_1.value, &search6_0.value },
   NULL,
};

   /* search243_0_0 -> search242_1_1 in the cache */

/* search243_0_1 -> search6_0 in the cache */
/* search243_0 -> replace242 in the cache */

/* search243_1_0 -> search6_0 in the cache */

static const nir_search_constant search243_1_1 = {
   { nir_search_value_constant, -1 },
   nir_type_int, { 0x3 /* 3 */ },
};
static const nir_search_expression search243_1 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_ieq,
   { &search6_0.value, &search243_1_1.value },
   NULL,
};
static const nir_search_expression search243 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ior,
   { &replace242.value, &search243_1.value },
   NULL,
};

   /* replace243_0 -> search243_1_1 in the cache */

/* replace243_1 -> search6_0 in the cache */
static const nir_search_expression replace243 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search243_1_1.value, &search6_0.value },
   NULL,
};

   /* search244_0_0 -> search0_0 in the cache */

static const nir_search_constant search244_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_float, { 0x0 /* 0.0 */ },
};
static const nir_search_expression search244_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search0_0.value, &search244_0_1.value },
   NULL,
};

/* search244_1 -> search65_0_1_0 in the cache */

/* search244_2_0_0_0_0 -> search244_0_1 in the cache */

/* search244_2_0_0_0_1 -> search0_0 in the cache */
static const nir_search_expression search244_2_0_0_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search244_0_1.value, &search0_0.value },
   NULL,
};
static const nir_search_expression search244_2_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_b2i32,
   { &search244_2_0_0_0.value },
   NULL,
};

/* search244_2_0_1_0_0_0 -> search0_0 in the cache */

/* search244_2_0_1_0_0_1 -> search244_0_1 in the cache */
static const nir_search_expression search244_2_0_1_0_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search0_0.value, &search244_0_1.value },
   NULL,
};
static const nir_search_expression search244_2_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_b2i32,
   { &search244_2_0_1_0_0.value },
   NULL,
};
static const nir_search_expression search244_2_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search244_2_0_1_0.value },
   NULL,
};
static const nir_search_expression search244_2_0 = {
   { nir_search_value_expression, 32 },
   false,
   1, 1,
   nir_op_iadd,
   { &search244_2_0_0.value, &search244_2_0_1.value },
   NULL,
};
static const nir_search_expression search244_2 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_i2f32,
   { &search244_2_0.value },
   NULL,
};
static const nir_search_expression search244 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &search244_0.value, &search65_0_1_0.value, &search244_2.value },
   NULL,
};

   static const nir_search_constant replace244_0 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x3f800000 /* 1065353216 */ },
};

/* replace244_1_0 -> search0_0 in the cache */

static const nir_search_constant replace244_1_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x80000000 /* 2147483648 */ },
};
static const nir_search_expression replace244_1 = {
   { nir_search_value_expression, 32 },
   false,
   1, 1,
   nir_op_iand,
   { &search0_0.value, &replace244_1_1.value },
   NULL,
};
static const nir_search_expression replace244 = {
   { nir_search_value_expression, 32 },
   false,
   0, 2,
   nir_op_ior,
   { &replace244_0.value, &replace244_1.value },
   NULL,
};

   /* search245_0 -> replace72_0 in the cache */

/* search245_1_0 -> replace72_0 in the cache */

/* search245_1_1 -> replace136 in the cache */
static const nir_search_expression search245_1 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_ieq,
   { &replace72_0.value, &replace136.value },
   NULL,
};
static const nir_search_expression search245 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ior,
   { &replace72_0.value, &search245_1.value },
   NULL,
};

   /* replace245 -> replace134 in the cache */

   /* search246_0 -> search6_0 in the cache */

/* search246_1_0 -> search6_0 in the cache */
static const nir_search_expression search246_1 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_inot,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search246 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_ior,
   { &search6_0.value, &search246_1.value },
   NULL,
};

   /* replace246 -> search42_1 in the cache */

   /* search247_0_0_0 -> replace72_0 in the cache */
static const nir_search_expression search247_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_b2i32,
   { &replace72_0.value },
   NULL,
};
static const nir_search_expression search247_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search247_0_0.value },
   NULL,
};

/* search247_1_0_0 -> search93_0_1_0 in the cache */
static const nir_search_expression search247_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_b2i32,
   { &search93_0_1_0.value },
   NULL,
};
static const nir_search_expression search247_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search247_1_0.value },
   NULL,
};
static const nir_search_expression search247 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &search247_0.value, &search247_1.value },
   NULL,
};

   /* replace247_0 -> replace72_0 in the cache */

/* replace247_1 -> search93_0_1_0 in the cache */
static const nir_search_expression replace247 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &replace72_0.value, &search93_0_1_0.value },
   NULL,
};

   /* search248_0_0 -> replace72_0 in the cache */

/* search248_0_1 -> search93_0_1_0 in the cache */
/* search248_0 -> replace247 in the cache */
static const nir_search_expression search248 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_b2i32,
   { &replace247.value },
   NULL,
};

   /* replace248_0_0 -> replace72_0 in the cache */

/* replace248_0_1 -> search93_0_1_0 in the cache */
/* replace248_0 -> replace100 in the cache */
static const nir_search_expression replace248 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_b2i32,
   { &replace100.value },
   NULL,
};

   /* search249_0_0 -> search0_0 in the cache */

/* search249_0_1 -> search25_1 in the cache */
static const nir_search_expression search249_0 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_ieq,
   { &search0_0.value, &search25_1.value },
   NULL,
};

/* search249_1_0 -> replace0_1_0 in the cache */

/* search249_1_1 -> search25_1 in the cache */
static const nir_search_expression search249_1 = {
   { nir_search_value_expression, 1 },
   false,
   2, 1,
   nir_op_ieq,
   { &replace0_1_0.value, &search25_1.value },
   NULL,
};
static const nir_search_expression search249 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_iand,
   { &search249_0.value, &search249_1.value },
   NULL,
};

   /* replace249_0_0 -> search0_0 in the cache */

/* replace249_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace249_0 = {
   { nir_search_value_expression, 32 },
   false,
   1, 1,
   nir_op_ior,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

/* replace249_1 -> search25_1 in the cache */
static const nir_search_expression replace249 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ieq,
   { &replace249_0.value, &search25_1.value },
   NULL,
};

   /* search250_0 -> search6_0 in the cache */

static const nir_search_variable search250_1_0 = {
   { nir_search_value_variable, -1 },
   1, /* b */
   false,
   nir_type_invalid,
   NULL,
};

/* search250_1_1 -> search6_0 in the cache */
static const nir_search_expression search250_1 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search250_1_0.value, &search6_0.value },
   NULL,
};
static const nir_search_expression search250 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 0,
   nir_op_flt,
   { &search6_0.value, &search250_1.value },
   NULL,
};

   /* replace250_0 -> search6_0 in the cache */

/* replace250_1 -> search250_1_0 in the cache */
static const nir_search_expression replace250 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search6_0.value, &search250_1_0.value },
   NULL,
};

   /* search251_0_0 -> search13_0 in the cache */

/* search251_0_1 -> replace13_1_0 in the cache */
/* search251_0 -> replace157 in the cache */

/* search251_1 -> search13_0 in the cache */
static const nir_search_expression search251 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 0,
   nir_op_flt,
   { &replace157.value, &search13_0.value },
   NULL,
};

   /* replace251_0 -> replace13_1_0 in the cache */

/* replace251_1 -> search13_0 in the cache */
static const nir_search_expression replace251 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &replace13_1_0.value, &search13_0.value },
   NULL,
};

   /* search252_0 -> search6_0 in the cache */

/* search252_1_0 -> search250_1_0 in the cache */

/* search252_1_1 -> search6_0 in the cache */
static const nir_search_expression search252_1 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search250_1_0.value, &search6_0.value },
   NULL,
};
static const nir_search_expression search252 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 0,
   nir_op_fge,
   { &search6_0.value, &search252_1.value },
   NULL,
};

   /* replace252 -> replace134 in the cache */

   /* search253_0_0 -> search13_0 in the cache */

/* search253_0_1 -> replace13_1_0 in the cache */
/* search253_0 -> replace156 in the cache */

/* search253_1 -> search13_0 in the cache */
static const nir_search_expression search253 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 0,
   nir_op_fge,
   { &replace156.value, &search13_0.value },
   NULL,
};

   /* replace253 -> replace134 in the cache */

   /* search254_0 -> search6_0 in the cache */

/* search254_1_0 -> search250_1_0 in the cache */

/* search254_1_1 -> search6_0 in the cache */
/* search254_1 -> search252_1 in the cache */
static const nir_search_expression search254 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 0,
   nir_op_flt,
   { &search6_0.value, &search252_1.value },
   NULL,
};

   /* replace254 -> replace136 in the cache */

   /* search255_0_0 -> search13_0 in the cache */

/* search255_0_1 -> replace13_1_0 in the cache */
/* search255_0 -> replace156 in the cache */

/* search255_1 -> search13_0 in the cache */
static const nir_search_expression search255 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 0,
   nir_op_flt,
   { &replace156.value, &search13_0.value },
   NULL,
};

   /* replace255 -> replace136 in the cache */

   /* search256_0 -> search6_0 in the cache */

/* search256_1_0 -> search250_1_0 in the cache */

/* search256_1_1 -> search6_0 in the cache */
/* search256_1 -> search250_1 in the cache */
static const nir_search_expression search256 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 0,
   nir_op_fge,
   { &search6_0.value, &search250_1.value },
   NULL,
};

   /* replace256_0 -> search6_0 in the cache */

/* replace256_1 -> search250_1_0 in the cache */
static const nir_search_expression replace256 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search6_0.value, &search250_1_0.value },
   NULL,
};

   /* search257_0_0 -> search13_0 in the cache */

/* search257_0_1 -> replace13_1_0 in the cache */
/* search257_0 -> replace157 in the cache */

/* search257_1 -> search13_0 in the cache */
static const nir_search_expression search257 = {
   { nir_search_value_expression, 1 },
   true,
   -1, 0,
   nir_op_fge,
   { &replace157.value, &search13_0.value },
   NULL,
};

   /* replace257_0 -> replace13_1_0 in the cache */

/* replace257_1 -> search13_0 in the cache */
static const nir_search_expression replace257 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &replace13_1_0.value, &search13_0.value },
   NULL,
};

   /* search258_0 -> search6_0 in the cache */

/* search258_1_0 -> search250_1_0 in the cache */

/* search258_1_1 -> search6_0 in the cache */
static const nir_search_expression search258_1 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_imax,
   { &search250_1_0.value, &search6_0.value },
   NULL,
};
static const nir_search_expression search258 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &search6_0.value, &search258_1.value },
   NULL,
};

   /* replace258_0 -> search6_0 in the cache */

/* replace258_1 -> search250_1_0 in the cache */
static const nir_search_expression replace258 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search6_0.value, &search250_1_0.value },
   NULL,
};

   /* search259_0_0 -> search13_0 in the cache */

/* search259_0_1 -> replace13_1_0 in the cache */
/* search259_0 -> replace182 in the cache */

/* search259_1 -> search13_0 in the cache */
static const nir_search_expression search259 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &replace182.value, &search13_0.value },
   NULL,
};

   /* replace259_0 -> replace13_1_0 in the cache */

/* replace259_1 -> search13_0 in the cache */
static const nir_search_expression replace259 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &replace13_1_0.value, &search13_0.value },
   NULL,
};

   /* search260_0 -> search6_0 in the cache */

/* search260_1_0 -> search250_1_0 in the cache */

/* search260_1_1 -> search6_0 in the cache */
static const nir_search_expression search260_1 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_imin,
   { &search250_1_0.value, &search6_0.value },
   NULL,
};
static const nir_search_expression search260 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ige,
   { &search6_0.value, &search260_1.value },
   NULL,
};

   /* replace260 -> replace134 in the cache */

   /* search261_0_0 -> search13_0 in the cache */

/* search261_0_1 -> replace13_1_0 in the cache */
/* search261_0 -> replace179 in the cache */

/* search261_1 -> search13_0 in the cache */
static const nir_search_expression search261 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ige,
   { &replace179.value, &search13_0.value },
   NULL,
};

   /* replace261 -> replace134 in the cache */

   /* search262_0 -> search6_0 in the cache */

/* search262_1_0 -> search250_1_0 in the cache */

/* search262_1_1 -> search6_0 in the cache */
static const nir_search_expression search262_1 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_umax,
   { &search250_1_0.value, &search6_0.value },
   NULL,
};
static const nir_search_expression search262 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &search6_0.value, &search262_1.value },
   NULL,
};

   /* replace262_0 -> search6_0 in the cache */

/* replace262_1 -> search250_1_0 in the cache */
static const nir_search_expression replace262 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search6_0.value, &search250_1_0.value },
   NULL,
};

   /* search263_0_0 -> search13_0 in the cache */

/* search263_0_1 -> replace13_1_0 in the cache */
/* search263_0 -> replace181 in the cache */

/* search263_1 -> search13_0 in the cache */
static const nir_search_expression search263 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &replace181.value, &search13_0.value },
   NULL,
};

   /* replace263_0 -> replace13_1_0 in the cache */

/* replace263_1 -> search13_0 in the cache */
static const nir_search_expression replace263 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &replace13_1_0.value, &search13_0.value },
   NULL,
};

   /* search264_0 -> search6_0 in the cache */

/* search264_1_0 -> search250_1_0 in the cache */

/* search264_1_1 -> search6_0 in the cache */
static const nir_search_expression search264_1 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_umin,
   { &search250_1_0.value, &search6_0.value },
   NULL,
};
static const nir_search_expression search264 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_uge,
   { &search6_0.value, &search264_1.value },
   NULL,
};

   /* replace264 -> replace134 in the cache */

   /* search265_0_0 -> search13_0 in the cache */

/* search265_0_1 -> replace13_1_0 in the cache */
/* search265_0 -> replace178 in the cache */

/* search265_1 -> search13_0 in the cache */
static const nir_search_expression search265 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_uge,
   { &replace178.value, &search13_0.value },
   NULL,
};

   /* replace265 -> replace134 in the cache */

   /* search266_0 -> search6_0 in the cache */

/* search266_1_0 -> search250_1_0 in the cache */

/* search266_1_1 -> search6_0 in the cache */
/* search266_1 -> search260_1 in the cache */
static const nir_search_expression search266 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &search6_0.value, &search260_1.value },
   NULL,
};

   /* replace266 -> replace136 in the cache */

   /* search267_0_0 -> search13_0 in the cache */

/* search267_0_1 -> replace13_1_0 in the cache */
/* search267_0 -> replace179 in the cache */

/* search267_1 -> search13_0 in the cache */
static const nir_search_expression search267 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &replace179.value, &search13_0.value },
   NULL,
};

   /* replace267 -> replace136 in the cache */

   /* search268_0 -> search6_0 in the cache */

/* search268_1_0 -> search250_1_0 in the cache */

/* search268_1_1 -> search6_0 in the cache */
/* search268_1 -> search258_1 in the cache */
static const nir_search_expression search268 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ige,
   { &search6_0.value, &search258_1.value },
   NULL,
};

   /* replace268_0 -> search6_0 in the cache */

/* replace268_1 -> search250_1_0 in the cache */
static const nir_search_expression replace268 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search6_0.value, &search250_1_0.value },
   NULL,
};

   /* search269_0_0 -> search13_0 in the cache */

/* search269_0_1 -> replace13_1_0 in the cache */
/* search269_0 -> replace182 in the cache */

/* search269_1 -> search13_0 in the cache */
static const nir_search_expression search269 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ige,
   { &replace182.value, &search13_0.value },
   NULL,
};

   /* replace269_0 -> replace13_1_0 in the cache */

/* replace269_1 -> search13_0 in the cache */
static const nir_search_expression replace269 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &replace13_1_0.value, &search13_0.value },
   NULL,
};

   /* search270_0 -> search6_0 in the cache */

/* search270_1_0 -> search250_1_0 in the cache */

/* search270_1_1 -> search6_0 in the cache */
/* search270_1 -> search264_1 in the cache */
static const nir_search_expression search270 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &search6_0.value, &search264_1.value },
   NULL,
};

   /* replace270 -> replace136 in the cache */

   /* search271_0_0 -> search13_0 in the cache */

/* search271_0_1 -> replace13_1_0 in the cache */
/* search271_0 -> replace178 in the cache */

/* search271_1 -> search13_0 in the cache */
static const nir_search_expression search271 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &replace178.value, &search13_0.value },
   NULL,
};

   /* replace271 -> replace136 in the cache */

   /* search272_0 -> search6_0 in the cache */

/* search272_1_0 -> search250_1_0 in the cache */

/* search272_1_1 -> search6_0 in the cache */
/* search272_1 -> search262_1 in the cache */
static const nir_search_expression search272 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_uge,
   { &search6_0.value, &search262_1.value },
   NULL,
};

   /* replace272_0 -> search6_0 in the cache */

/* replace272_1 -> search250_1_0 in the cache */
static const nir_search_expression replace272 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search6_0.value, &search250_1_0.value },
   NULL,
};

   /* search273_0_0 -> search13_0 in the cache */

/* search273_0_1 -> replace13_1_0 in the cache */
/* search273_0 -> replace181 in the cache */

/* search273_1 -> search13_0 in the cache */
static const nir_search_expression search273 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_uge,
   { &replace181.value, &search13_0.value },
   NULL,
};

   /* replace273_0 -> replace13_1_0 in the cache */

/* replace273_1 -> search13_0 in the cache */
static const nir_search_expression replace273 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &replace13_1_0.value, &search13_0.value },
   NULL,
};

   static const nir_search_variable search274_0 = {
   { nir_search_value_variable, -3 },
   0, /* a */
   true,
   nir_type_invalid,
   NULL,
};

/* search274_1_0 -> search79_0_0_1 in the cache */

/* search274_1_1 -> search27_1_1 in the cache */
static const nir_search_expression search274_1 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_imax,
   { &search79_0_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression search274 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &search274_0.value, &search274_1.value },
   NULL,
};

   /* replace274_0_0 -> search27_0_0 in the cache */

/* replace274_0_1 -> search27_0_1 in the cache */
static const nir_search_expression replace274_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search27_0_0.value, &search27_0_1.value },
   NULL,
};

/* replace274_1_0 -> search27_0_0 in the cache */

/* replace274_1_1 -> search27_1_1 in the cache */
/* replace274_1 -> search225_1 in the cache */
static const nir_search_expression replace274 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &replace274_0.value, &search225_1.value },
   NULL,
};

   /* search275_0_0 -> search274_0 in the cache */

/* search275_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search275_0 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_imin,
   { &search274_0.value, &search27_0_1.value },
   NULL,
};

/* search275_1 -> search79_0_1 in the cache */
static const nir_search_expression search275 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &search275_0.value, &search79_0_1.value },
   NULL,
};

   /* replace275_0_0 -> search27_0_0 in the cache */

/* replace275_0_1 -> search27_1_1 in the cache */
/* replace275_0 -> search225_1 in the cache */

/* replace275_1_0 -> search27_0_1 in the cache */

/* replace275_1_1 -> search27_1_1 in the cache */
static const nir_search_expression replace275_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search27_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression replace275 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search225_1.value, &replace275_1.value },
   NULL,
};

   /* search276_0 -> search274_0 in the cache */

/* search276_1_0 -> search79_0_0_1 in the cache */

/* search276_1_1 -> search27_1_1 in the cache */
static const nir_search_expression search276_1 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_imin,
   { &search79_0_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression search276 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ige,
   { &search274_0.value, &search276_1.value },
   NULL,
};

   /* replace276_0_0 -> search27_0_0 in the cache */

/* replace276_0_1 -> search27_0_1 in the cache */
static const nir_search_expression replace276_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search27_0_0.value, &search27_0_1.value },
   NULL,
};

/* replace276_1_0 -> search27_0_0 in the cache */

/* replace276_1_1 -> search27_1_1 in the cache */
/* replace276_1 -> search227_1 in the cache */
static const nir_search_expression replace276 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &replace276_0.value, &search227_1.value },
   NULL,
};

   /* search277_0_0 -> search274_0 in the cache */

/* search277_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search277_0 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_imax,
   { &search274_0.value, &search27_0_1.value },
   NULL,
};

/* search277_1 -> search79_0_1 in the cache */
static const nir_search_expression search277 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ige,
   { &search277_0.value, &search79_0_1.value },
   NULL,
};

   /* replace277_0_0 -> search27_0_0 in the cache */

/* replace277_0_1 -> search27_1_1 in the cache */
/* replace277_0 -> search227_1 in the cache */

/* replace277_1_0 -> search27_0_1 in the cache */

/* replace277_1_1 -> search27_1_1 in the cache */
static const nir_search_expression replace277_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search27_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression replace277 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search227_1.value, &replace277_1.value },
   NULL,
};

   /* search278_0 -> search274_0 in the cache */

/* search278_1_0 -> search79_0_0_1 in the cache */

/* search278_1_1 -> search27_1_1 in the cache */
static const nir_search_expression search278_1 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_umax,
   { &search79_0_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression search278 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &search274_0.value, &search278_1.value },
   NULL,
};

   /* replace278_0_0 -> search27_0_0 in the cache */

/* replace278_0_1 -> search27_0_1 in the cache */
static const nir_search_expression replace278_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search27_0_0.value, &search27_0_1.value },
   NULL,
};

/* replace278_1_0 -> search27_0_0 in the cache */

/* replace278_1_1 -> search27_1_1 in the cache */
/* replace278_1 -> search229_1 in the cache */
static const nir_search_expression replace278 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &replace278_0.value, &search229_1.value },
   NULL,
};

   /* search279_0_0 -> search274_0 in the cache */

/* search279_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search279_0 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_umin,
   { &search274_0.value, &search27_0_1.value },
   NULL,
};

/* search279_1 -> search79_0_1 in the cache */
static const nir_search_expression search279 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &search279_0.value, &search79_0_1.value },
   NULL,
};

   /* replace279_0_0 -> search27_0_0 in the cache */

/* replace279_0_1 -> search27_1_1 in the cache */
/* replace279_0 -> search229_1 in the cache */

/* replace279_1_0 -> search27_0_1 in the cache */

/* replace279_1_1 -> search27_1_1 in the cache */
static const nir_search_expression replace279_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search27_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression replace279 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search229_1.value, &replace279_1.value },
   NULL,
};

   /* search280_0 -> search274_0 in the cache */

/* search280_1_0 -> search79_0_0_1 in the cache */

/* search280_1_1 -> search27_1_1 in the cache */
static const nir_search_expression search280_1 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_umin,
   { &search79_0_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression search280 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_uge,
   { &search274_0.value, &search280_1.value },
   NULL,
};

   /* replace280_0_0 -> search27_0_0 in the cache */

/* replace280_0_1 -> search27_0_1 in the cache */
static const nir_search_expression replace280_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search27_0_0.value, &search27_0_1.value },
   NULL,
};

/* replace280_1_0 -> search27_0_0 in the cache */

/* replace280_1_1 -> search27_1_1 in the cache */
/* replace280_1 -> search231_1 in the cache */
static const nir_search_expression replace280 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &replace280_0.value, &search231_1.value },
   NULL,
};

   /* search281_0_0 -> search274_0 in the cache */

/* search281_0_1 -> search27_0_1 in the cache */
static const nir_search_expression search281_0 = {
   { nir_search_value_expression, -3 },
   false,
   0, 1,
   nir_op_umax,
   { &search274_0.value, &search27_0_1.value },
   NULL,
};

/* search281_1 -> search79_0_1 in the cache */
static const nir_search_expression search281 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_uge,
   { &search281_0.value, &search79_0_1.value },
   NULL,
};

   /* replace281_0_0 -> search27_0_0 in the cache */

/* replace281_0_1 -> search27_1_1 in the cache */
/* replace281_0 -> search231_1 in the cache */

/* replace281_1_0 -> search27_0_1 in the cache */

/* replace281_1_1 -> search27_1_1 in the cache */
static const nir_search_expression replace281_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search27_0_1.value, &search27_1_1.value },
   NULL,
};
static const nir_search_expression replace281 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search231_1.value, &replace281_1.value },
   NULL,
};

   /* search282_0 -> search274_0 in the cache */

/* search282_1_0 -> search79_0_0_1 in the cache */

/* search282_1_1 -> search27_1_1 in the cache */
/* search282_1 -> search276_1 in the cache */
static const nir_search_expression search282 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &search274_0.value, &search276_1.value },
   NULL,
};

   /* replace282_0_0 -> search27_0_0 in the cache */

/* replace282_0_1 -> search27_0_1 in the cache */
/* replace282_0 -> replace274_0 in the cache */

/* replace282_1_0 -> search27_0_0 in the cache */

/* replace282_1_1 -> search27_1_1 in the cache */
/* replace282_1 -> search225_1 in the cache */
static const nir_search_expression replace282 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &replace274_0.value, &search225_1.value },
   NULL,
};

   /* search283_0_0 -> search274_0 in the cache */

/* search283_0_1 -> search27_0_1 in the cache */
/* search283_0 -> search277_0 in the cache */

/* search283_1 -> search79_0_1 in the cache */
static const nir_search_expression search283 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &search277_0.value, &search79_0_1.value },
   NULL,
};

   /* replace283_0_0 -> search27_0_0 in the cache */

/* replace283_0_1 -> search27_1_1 in the cache */
/* replace283_0 -> search225_1 in the cache */

/* replace283_1_0 -> search27_0_1 in the cache */

/* replace283_1_1 -> search27_1_1 in the cache */
/* replace283_1 -> replace275_1 in the cache */
static const nir_search_expression replace283 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search225_1.value, &replace275_1.value },
   NULL,
};

   /* search284_0 -> search274_0 in the cache */

/* search284_1_0 -> search79_0_0_1 in the cache */

/* search284_1_1 -> search27_1_1 in the cache */
/* search284_1 -> search274_1 in the cache */
static const nir_search_expression search284 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ige,
   { &search274_0.value, &search274_1.value },
   NULL,
};

   /* replace284_0_0 -> search27_0_0 in the cache */

/* replace284_0_1 -> search27_0_1 in the cache */
/* replace284_0 -> replace276_0 in the cache */

/* replace284_1_0 -> search27_0_0 in the cache */

/* replace284_1_1 -> search27_1_1 in the cache */
/* replace284_1 -> search227_1 in the cache */
static const nir_search_expression replace284 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &replace276_0.value, &search227_1.value },
   NULL,
};

   /* search285_0_0 -> search274_0 in the cache */

/* search285_0_1 -> search27_0_1 in the cache */
/* search285_0 -> search275_0 in the cache */

/* search285_1 -> search79_0_1 in the cache */
static const nir_search_expression search285 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ige,
   { &search275_0.value, &search79_0_1.value },
   NULL,
};

   /* replace285_0_0 -> search27_0_0 in the cache */

/* replace285_0_1 -> search27_1_1 in the cache */
/* replace285_0 -> search227_1 in the cache */

/* replace285_1_0 -> search27_0_1 in the cache */

/* replace285_1_1 -> search27_1_1 in the cache */
/* replace285_1 -> replace277_1 in the cache */
static const nir_search_expression replace285 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search227_1.value, &replace277_1.value },
   NULL,
};

   /* search286_0 -> search274_0 in the cache */

/* search286_1_0 -> search79_0_0_1 in the cache */

/* search286_1_1 -> search27_1_1 in the cache */
/* search286_1 -> search280_1 in the cache */
static const nir_search_expression search286 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &search274_0.value, &search280_1.value },
   NULL,
};

   /* replace286_0_0 -> search27_0_0 in the cache */

/* replace286_0_1 -> search27_0_1 in the cache */
/* replace286_0 -> replace278_0 in the cache */

/* replace286_1_0 -> search27_0_0 in the cache */

/* replace286_1_1 -> search27_1_1 in the cache */
/* replace286_1 -> search229_1 in the cache */
static const nir_search_expression replace286 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &replace278_0.value, &search229_1.value },
   NULL,
};

   /* search287_0_0 -> search274_0 in the cache */

/* search287_0_1 -> search27_0_1 in the cache */
/* search287_0 -> search281_0 in the cache */

/* search287_1 -> search79_0_1 in the cache */
static const nir_search_expression search287 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &search281_0.value, &search79_0_1.value },
   NULL,
};

   /* replace287_0_0 -> search27_0_0 in the cache */

/* replace287_0_1 -> search27_1_1 in the cache */
/* replace287_0 -> search229_1 in the cache */

/* replace287_1_0 -> search27_0_1 in the cache */

/* replace287_1_1 -> search27_1_1 in the cache */
/* replace287_1 -> replace279_1 in the cache */
static const nir_search_expression replace287 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search229_1.value, &replace279_1.value },
   NULL,
};

   /* search288_0 -> search274_0 in the cache */

/* search288_1_0 -> search79_0_0_1 in the cache */

/* search288_1_1 -> search27_1_1 in the cache */
/* search288_1 -> search278_1 in the cache */
static const nir_search_expression search288 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_uge,
   { &search274_0.value, &search278_1.value },
   NULL,
};

   /* replace288_0_0 -> search27_0_0 in the cache */

/* replace288_0_1 -> search27_0_1 in the cache */
/* replace288_0 -> replace280_0 in the cache */

/* replace288_1_0 -> search27_0_0 in the cache */

/* replace288_1_1 -> search27_1_1 in the cache */
/* replace288_1 -> search231_1 in the cache */
static const nir_search_expression replace288 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &replace280_0.value, &search231_1.value },
   NULL,
};

   /* search289_0_0 -> search274_0 in the cache */

/* search289_0_1 -> search27_0_1 in the cache */
/* search289_0 -> search279_0 in the cache */

/* search289_1 -> search79_0_1 in the cache */
static const nir_search_expression search289 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_uge,
   { &search279_0.value, &search79_0_1.value },
   NULL,
};

   /* replace289_0_0 -> search27_0_0 in the cache */

/* replace289_0_1 -> search27_1_1 in the cache */
/* replace289_0 -> search231_1 in the cache */

/* replace289_1_0 -> search27_0_1 in the cache */

/* replace289_1_1 -> search27_1_1 in the cache */
/* replace289_1 -> replace281_1 in the cache */
static const nir_search_expression replace289 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search231_1.value, &replace281_1.value },
   NULL,
};

   /* search290_0_0 -> search6_0 in the cache */

/* search290_0_1 -> replace8 in the cache */
/* search290_0 -> replace142 in the cache */

/* search290_1_0_0 -> search6_0 in the cache */

/* search290_1_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression search290_1_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search6_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression search290_1 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search290_1_0.value },
   NULL,
};

/* search290_2_0 -> search6_0 in the cache */

/* search290_2_1 -> replace0_1_0 in the cache */
/* search290_2 -> search290_1_0 in the cache */
static const nir_search_expression search290 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace142.value, &search290_1.value, &search290_1_0.value },
   NULL,
};

   /* replace290_0_0 -> search6_0 in the cache */

/* replace290_0_1 -> replace0_1_0 in the cache */
/* replace290_0 -> search290_1_0 in the cache */
static const nir_search_expression replace290 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_iabs,
   { &search290_1_0.value },
   NULL,
};

   /* search291_0_0_0 -> search6_0 in the cache */
/* search291_0_0 -> search19_0 in the cache */

/* search291_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression search291_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search19_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression search291 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_iabs,
   { &search291_0.value },
   NULL,
};

   /* replace291_0_0 -> search6_0 in the cache */
/* replace291_0 -> search19_0 in the cache */

/* replace291_1 -> replace0_1_0 in the cache */
/* replace291 -> search291_0 in the cache */

   /* search292_0_0 -> search0_0 in the cache */

/* search292_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression search292_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_slt,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression search292 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fabs,
   { &search292_0.value },
   NULL,
};

   /* replace292_0 -> search0_0 in the cache */

/* replace292_1 -> replace0_1_0 in the cache */
/* replace292 -> search292_0 in the cache */

   /* search293_0_0 -> search13_0 in the cache */

/* search293_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression search293_0 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_sge,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search293 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fabs,
   { &search293_0.value },
   NULL,
};

   /* replace293_0 -> search13_0 in the cache */

/* replace293_1 -> replace13_1_0 in the cache */
/* replace293 -> search293_0 in the cache */

   /* search294_0_0 -> search0_0 in the cache */

/* search294_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression search294_0 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_seq,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression search294 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_fabs,
   { &search294_0.value },
   NULL,
};

   /* replace294_0 -> search0_0 in the cache */

/* replace294_1 -> replace0_1_0 in the cache */
/* replace294 -> search294_0 in the cache */

   /* search295_0_0 -> search0_0 in the cache */

/* search295_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression search295_0 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_sne,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression search295 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_fabs,
   { &search295_0.value },
   NULL,
};

   /* replace295_0 -> search0_0 in the cache */

/* replace295_1 -> replace0_1_0 in the cache */
/* replace295 -> search295_0 in the cache */

   /* search296_0 -> search0_0 in the cache */

/* search296_1 -> replace0_1_0 in the cache */
/* search296 -> search292_0 in the cache */

   /* replace296_0_0 -> search0_0 in the cache */

/* replace296_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace296_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace296 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &replace296_0.value },
   NULL,
};

   /* search297_0 -> search13_0 in the cache */

/* search297_1 -> replace13_1_0 in the cache */
/* search297 -> search293_0 in the cache */

   /* replace297_0_0 -> search13_0 in the cache */

/* replace297_0_1 -> replace13_1_0 in the cache */
/* replace297_0 -> replace81 in the cache */
static const nir_search_expression replace297 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &replace81.value },
   NULL,
};

   /* search298_0 -> search0_0 in the cache */

/* search298_1 -> replace0_1_0 in the cache */
/* search298 -> search294_0 in the cache */

   /* replace298_0_0 -> search0_0 in the cache */

/* replace298_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace298_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace298 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_search_op_b2f,
   { &replace298_0.value },
   NULL,
};

   /* search299_0 -> search0_0 in the cache */

/* search299_1 -> replace0_1_0 in the cache */
/* search299 -> search295_0 in the cache */

   /* replace299_0_0 -> search0_0 in the cache */

/* replace299_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace299_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace299 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_search_op_b2f,
   { &replace299_0.value },
   NULL,
};

   /* search300_0_0 -> search6_0 in the cache */
/* search300_0 -> search14_0 in the cache */

/* search300_1 -> search6_0 in the cache */
static const nir_search_expression search300 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search14_0.value, &search6_0.value },
   NULL,
};

   /* replace300_0 -> search6_0 in the cache */

/* replace300_1 -> search23_1 in the cache */
/* replace300 -> replace144 in the cache */

   /* search301_0_0 -> search6_0 in the cache */
/* search301_0 -> search14_0 in the cache */

/* search301_1 -> search6_0 in the cache */
static const nir_search_expression search301 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search14_0.value, &search6_0.value },
   NULL,
};

   /* replace301_0 -> search6_0 in the cache */

/* replace301_1 -> search23_1 in the cache */
/* replace301 -> replace146 in the cache */

   /* search302_0_0 -> replace72_0 in the cache */
/* search302_0 -> search130_0 in the cache */

/* search302_1_0 -> search93_0_1_0 in the cache */
static const nir_search_expression search302_1 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_b2i,
   { &search93_0_1_0.value },
   NULL,
};
static const nir_search_expression search302 = {
   { nir_search_value_expression, 0 },
   false,
   0, 1,
   nir_op_imul,
   { &search130_0.value, &search302_1.value },
   NULL,
};

   /* replace302_0_0 -> replace72_0 in the cache */

/* replace302_0_1 -> search93_0_1_0 in the cache */
/* replace302_0 -> replace97 in the cache */
static const nir_search_expression replace302 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 1,
   nir_search_op_b2i,
   { &replace97.value },
   NULL,
};

   /* search303_0_0 -> replace72_0 in the cache */
/* search303_0 -> search91_1 in the cache */

/* search303_1_0 -> search93_0_1_0 in the cache */
/* search303_1 -> search93_0_1 in the cache */
static const nir_search_expression search303 = {
   { nir_search_value_expression, 0 },
   false,
   0, 1,
   nir_op_fmul,
   { &search91_1.value, &search93_0_1.value },
   NULL,
};

   /* replace303_0_0 -> replace72_0 in the cache */

/* replace303_0_1 -> search93_0_1_0 in the cache */
/* replace303_0 -> replace97 in the cache */
/* replace303 -> replace150 in the cache */

   /* search304_0_0_0 -> replace72_0 in the cache */
/* search304_0_0 -> search91_1 in the cache */

/* search304_0_1_0 -> search93_0_1_0 in the cache */
/* search304_0_1 -> search93_0_1 in the cache */
/* search304_0 -> search113_0_0 in the cache */
static const nir_search_expression search304 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 1,
   nir_op_fsat,
   { &search113_0_0.value },
   NULL,
};

   /* replace304_0_0 -> replace72_0 in the cache */

/* replace304_0_1 -> search93_0_1_0 in the cache */
/* replace304_0 -> replace93 in the cache */
/* replace304 -> replace148 in the cache */

   static const nir_search_variable search305_0 = {
   { nir_search_value_variable, 32 },
   0, /* a */
   false,
   nir_type_bool,
   NULL,
};

/* search305_1 -> search65_0_1_0 in the cache */
static const nir_search_expression search305 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_iand,
   { &search305_0.value, &search65_0_1_0.value },
   NULL,
};

   /* replace305_0 -> search0_0 in the cache */
static const nir_search_expression replace305 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &search0_0.value },
   NULL,
};

   /* search306_0_0 -> search0_0 in the cache */
static const nir_search_expression search306_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_b2i32,
   { &search0_0.value },
   NULL,
};
static const nir_search_expression search306 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search306_0.value },
   NULL,
};

   /* replace306 -> search0_0 in the cache */

   /* search307_0_0_0 -> replace72_0 in the cache */
/* search307_0_0 -> search91_1 in the cache */
/* search307_0 -> search92_0 in the cache */

/* search307_1 -> search130_1 in the cache */
static const nir_search_expression search307 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search92_0.value, &search130_1.value },
   NULL,
};

   /* replace307 -> replace72_0 in the cache */

   /* search308_0_0 -> search91_0 in the cache */

/* search308_0_1_0 -> replace72_0 in the cache */
/* search308_0_1 -> search91_1 in the cache */
static const nir_search_expression search308_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_fsub,
   { &search91_0.value, &search91_1.value },
   NULL,
};

/* search308_1 -> search130_1 in the cache */
static const nir_search_expression search308 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search308_0.value, &search130_1.value },
   NULL,
};

   /* replace308 -> replace72_0 in the cache */

   /* search309_0 -> search6_0 in the cache */

/* search309_1 -> search6_0 in the cache */
static const nir_search_expression search309 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace309 -> replace136 in the cache */

   /* search310_0 -> search6_0 in the cache */

/* search310_1 -> search6_0 in the cache */
static const nir_search_expression search310 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace310 -> replace134 in the cache */

   /* search311_0 -> search6_0 in the cache */

/* search311_1 -> search6_0 in the cache */
static const nir_search_expression search311 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace311 -> replace134 in the cache */

   /* search312_0 -> search6_0 in the cache */

/* search312_1 -> search6_0 in the cache */
static const nir_search_expression search312 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace312 -> replace136 in the cache */

   /* search313_0 -> search6_0 in the cache */

/* search313_1 -> search6_0 in the cache */
static const nir_search_expression search313 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace313 -> replace136 in the cache */

   /* search314_0 -> search6_0 in the cache */

/* search314_1 -> search6_0 in the cache */
static const nir_search_expression search314 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace314 -> replace134 in the cache */

   /* search315_0 -> search0_0 in the cache */

/* search315_1 -> search244_0_1 in the cache */
static const nir_search_expression search315 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_fand,
   { &search0_0.value, &search244_0_1.value },
   NULL,
};

   /* replace315 -> search244_0_1 in the cache */

   /* search316_0 -> search6_0 in the cache */

/* search316_1 -> search6_0 in the cache */
static const nir_search_expression search316 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_iand,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace316 -> search6_0 in the cache */

   /* search317_0 -> search6_0 in the cache */

/* search317_1 -> search42_1 in the cache */
static const nir_search_expression search317 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_iand,
   { &search6_0.value, &search42_1.value },
   NULL,
};

   /* replace317 -> search6_0 in the cache */

   /* search318_0 -> search6_0 in the cache */

/* search318_1 -> replace8 in the cache */
static const nir_search_expression search318 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_iand,
   { &search6_0.value, &replace8.value },
   NULL,
};

   /* replace318 -> replace8 in the cache */

   /* search319_0 -> search6_0 in the cache */

/* search319_1 -> search6_0 in the cache */
static const nir_search_expression search319 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_ior,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace319 -> search6_0 in the cache */

   /* search320_0 -> search6_0 in the cache */

/* search320_1 -> replace8 in the cache */
static const nir_search_expression search320 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_ior,
   { &search6_0.value, &replace8.value },
   NULL,
};

   /* replace320 -> search6_0 in the cache */

   /* search321_0 -> replace72_0 in the cache */

/* search321_1 -> replace134 in the cache */
static const nir_search_expression search321 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &replace72_0.value, &replace134.value },
   NULL,
};

   /* replace321 -> replace134 in the cache */

   /* search322_0 -> search0_0 in the cache */

/* search322_1 -> search0_0 in the cache */
static const nir_search_expression search322 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_fxor,
   { &search0_0.value, &search0_0.value },
   NULL,
};

   /* replace322 -> search244_0_1 in the cache */

   /* search323_0 -> search6_0 in the cache */

/* search323_1 -> search6_0 in the cache */
static const nir_search_expression search323 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_ixor,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* replace323 -> replace8 in the cache */

   /* search324_0 -> search6_0 in the cache */

/* search324_1 -> replace8 in the cache */
static const nir_search_expression search324 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_ixor,
   { &search6_0.value, &replace8.value },
   NULL,
};

   /* replace324 -> search6_0 in the cache */

   /* search325_0_0 -> search6_0 in the cache */
/* search325_0 -> search246_1 in the cache */
static const nir_search_expression search325 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_inot,
   { &search246_1.value },
   NULL,
};

   /* replace325 -> search6_0 in the cache */

   /* search326_0_0 -> search13_0 in the cache */

/* search326_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression search326_0 = {
   { nir_search_value_expression, -2 },
   false,
   1, 1,
   nir_op_iand,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

/* search326_1 -> replace13_1_0 in the cache */
static const nir_search_expression search326 = {
   { nir_search_value_expression, -2 },
   false,
   0, 2,
   nir_op_ior,
   { &search326_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace326 -> replace13_1_0 in the cache */

   /* search327_0_0 -> search13_0 in the cache */

/* search327_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression search327_0 = {
   { nir_search_value_expression, -2 },
   false,
   1, 1,
   nir_op_ior,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

/* search327_1 -> replace13_1_0 in the cache */
static const nir_search_expression search327 = {
   { nir_search_value_expression, -2 },
   false,
   0, 2,
   nir_op_ior,
   { &search327_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace327_0 -> search13_0 in the cache */

/* replace327_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace327 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_ior,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search328_0_0 -> search13_0 in the cache */

/* search328_0_1 -> replace13_1_0 in the cache */
/* search328_0 -> search327_0 in the cache */

/* search328_1 -> replace13_1_0 in the cache */
static const nir_search_expression search328 = {
   { nir_search_value_expression, -2 },
   false,
   0, 2,
   nir_op_iand,
   { &search327_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace328 -> replace13_1_0 in the cache */

   /* search329_0_0 -> search13_0 in the cache */

/* search329_0_1 -> replace13_1_0 in the cache */
/* search329_0 -> search326_0 in the cache */

/* search329_1 -> replace13_1_0 in the cache */
static const nir_search_expression search329 = {
   { nir_search_value_expression, -2 },
   false,
   0, 2,
   nir_op_iand,
   { &search326_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace329_0 -> search13_0 in the cache */

/* replace329_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace329 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_iand,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search330_0_0 -> search13_0 in the cache */
static const nir_search_expression search330_0 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_inot,
   { &search13_0.value },
   NULL,
};

/* search330_1_0 -> replace13_1_0 in the cache */
static const nir_search_expression search330_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_inot,
   { &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search330 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_iand,
   { &search330_0.value, &search330_1.value },
   NULL,
};

   /* replace330_0_0 -> search13_0 in the cache */

/* replace330_0_1 -> replace13_1_0 in the cache */
/* replace330_0 -> replace327 in the cache */
static const nir_search_expression replace330 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 1,
   nir_op_inot,
   { &replace327.value },
   NULL,
};

   /* search331_0_0 -> search13_0 in the cache */
/* search331_0 -> search330_0 in the cache */

/* search331_1_0 -> replace13_1_0 in the cache */
/* search331_1 -> search330_1 in the cache */
static const nir_search_expression search331 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_ior,
   { &search330_0.value, &search330_1.value },
   NULL,
};

   /* replace331_0_0 -> search13_0 in the cache */

/* replace331_0_1 -> replace13_1_0 in the cache */
/* replace331_0 -> replace329 in the cache */
static const nir_search_expression replace331 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 1,
   nir_op_inot,
   { &replace329.value },
   NULL,
};

   /* search332_0 -> search130_1 in the cache */

/* search332_1 -> search0_0 in the cache */
static const nir_search_expression search332 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search130_1.value, &search0_0.value },
   NULL,
};

   /* replace332 -> search130_1 in the cache */

   /* search333_0 -> search6_0 in the cache */

/* search333_1 -> search25_1 in the cache */
static const nir_search_expression search333 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search6_0.value, &search25_1.value },
   NULL,
};

   /* replace333 -> search6_0 in the cache */

   /* search334_0 -> search130_1 in the cache */

/* search334_1 -> search0_0 in the cache */
static const nir_search_expression search334 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search130_1.value, &search0_0.value },
   NULL,
};

   /* replace334 -> search130_1 in the cache */

   /* search335_0 -> search6_0 in the cache */

/* search335_1 -> search25_1 in the cache */
static const nir_search_expression search335 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search6_0.value, &search25_1.value },
   NULL,
};

   /* replace335 -> search6_0 in the cache */

   /* search336_0 -> search130_1 in the cache */

/* search336_1 -> search0_0 in the cache */
static const nir_search_expression search336 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search130_1.value, &search0_0.value },
   NULL,
};

   /* replace336 -> search130_1 in the cache */

   /* search337_0 -> search6_0 in the cache */

/* search337_1 -> search25_1 in the cache */
static const nir_search_expression search337 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search6_0.value, &search25_1.value },
   NULL,
};

   /* replace337 -> search6_0 in the cache */

   static const nir_search_constant search338_0 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0xff /* 255 */ },
};

/* search338_1_0 -> search0_0 in the cache */

static const nir_search_constant search338_1_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x18 /* 24 */ },
};
static const nir_search_expression search338_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search0_0.value, &search338_1_1.value },
   NULL,
};
static const nir_search_expression search338 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_iand,
   { &search338_0.value, &search338_1.value },
   NULL,
};

   /* replace338_0 -> search0_0 in the cache */

/* replace338_1 -> search338_1_1 in the cache */
/* replace338 -> search338_1 in the cache */

   static const nir_search_constant search339_0 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0xffff /* 65535 */ },
};

/* search339_1_0 -> search0_0 in the cache */

static const nir_search_constant search339_1_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x10 /* 16 */ },
};
static const nir_search_expression search339_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search0_0.value, &search339_1_1.value },
   NULL,
};
static const nir_search_expression search339 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_iand,
   { &search339_0.value, &search339_1.value },
   NULL,
};

   /* replace339_0 -> search0_0 in the cache */

/* replace339_1 -> search339_1_1 in the cache */
/* replace339 -> search339_1 in the cache */

   /* search340_0_0 -> search6_0 in the cache */
static const nir_search_expression search340_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_flog2,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search340 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_fexp2,
   { &search340_0.value },
   NULL,
};

   /* replace340 -> search6_0 in the cache */

   /* search341_0_0 -> search6_0 in the cache */
static const nir_search_expression search341_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fexp2,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search341 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_flog2,
   { &search341_0.value },
   NULL,
};

   /* replace341 -> search6_0 in the cache */

   /* search342_0 -> search13_0 in the cache */

/* search342_1 -> replace13_1_0 in the cache */
static const nir_search_expression search342 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fpow,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace342_0_0_0 -> search13_0 in the cache */
static const nir_search_expression replace342_0_0 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_flog2,
   { &search13_0.value },
   NULL,
};

/* replace342_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace342_0 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_fmul,
   { &replace342_0_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression replace342 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 1,
   nir_op_fexp2,
   { &replace342_0.value },
   NULL,
};

   /* search343_0_0_0 -> search13_0 in the cache */
/* search343_0_0 -> replace342_0_0 in the cache */

/* search343_0_1 -> replace13_1_0 in the cache */
/* search343_0 -> replace342_0 in the cache */
static const nir_search_expression search343 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 1,
   nir_op_fexp2,
   { &replace342_0.value },
   NULL,
};

   /* replace343_0 -> search13_0 in the cache */

/* replace343_1 -> replace13_1_0 in the cache */
/* replace343 -> search342 in the cache */

   /* search344_0_0_0_0 -> search73_0_0 in the cache */
static const nir_search_expression search344_0_0_0 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_flog2,
   { &search73_0_0.value },
   NULL,
};

/* search344_0_0_1 -> search73_0_1 in the cache */
static const nir_search_expression search344_0_0 = {
   { nir_search_value_expression, -4 },
   false,
   1, 1,
   nir_op_fmul,
   { &search344_0_0_0.value, &search73_0_1.value },
   NULL,
};

/* search344_0_1_0_0 -> search73_0_2 in the cache */
static const nir_search_expression search344_0_1_0 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_flog2,
   { &search73_0_2.value },
   NULL,
};

/* search344_0_1_1 -> search73_1 in the cache */
static const nir_search_expression search344_0_1 = {
   { nir_search_value_expression, -4 },
   false,
   2, 1,
   nir_op_fmul,
   { &search344_0_1_0.value, &search73_1.value },
   NULL,
};
static const nir_search_expression search344_0 = {
   { nir_search_value_expression, -4 },
   false,
   0, 3,
   nir_op_fadd,
   { &search344_0_0.value, &search344_0_1.value },
   NULL,
};
static const nir_search_expression search344 = {
   { nir_search_value_expression, -4 },
   true,
   -1, 3,
   nir_op_fexp2,
   { &search344_0.value },
   NULL,
};

   /* replace344_0_0 -> search73_0_0 in the cache */

/* replace344_0_1 -> search73_0_1 in the cache */
static const nir_search_expression replace344_0 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_fpow,
   { &search73_0_0.value, &search73_0_1.value },
   NULL,
};

/* replace344_1_0 -> search73_0_2 in the cache */

/* replace344_1_1 -> search73_1 in the cache */
static const nir_search_expression replace344_1 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_fpow,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace344 = {
   { nir_search_value_expression, -4 },
   true,
   0, 1,
   nir_op_fmul,
   { &replace344_0.value, &replace344_1.value },
   NULL,
};

   /* search345_0_0_0 -> search6_0 in the cache */
/* search345_0_0 -> search340_0 in the cache */

static const nir_search_constant search345_0_1 = {
   { nir_search_value_constant, -1 },
   nir_type_float, { 0x4000000000000000 /* 2.0 */ },
};
static const nir_search_expression search345_0 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_fmul,
   { &search340_0.value, &search345_0_1.value },
   NULL,
};
static const nir_search_expression search345 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 1,
   nir_op_fexp2,
   { &search345_0.value },
   NULL,
};

   /* replace345_0 -> search6_0 in the cache */

/* replace345_1 -> search6_0 in the cache */
static const nir_search_expression replace345 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_fmul,
   { &search6_0.value, &search6_0.value },
   NULL,
};

   /* search346_0_0_0 -> search6_0 in the cache */
/* search346_0_0 -> search340_0 in the cache */

static const nir_search_constant search346_0_1 = {
   { nir_search_value_constant, -1 },
   nir_type_float, { 0x4010000000000000 /* 4.0 */ },
};
static const nir_search_expression search346_0 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_fmul,
   { &search340_0.value, &search346_0_1.value },
   NULL,
};
static const nir_search_expression search346 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 1,
   nir_op_fexp2,
   { &search346_0.value },
   NULL,
};

   /* replace346_0_0 -> search6_0 in the cache */

/* replace346_0_1 -> search6_0 in the cache */
/* replace346_0 -> search43_1 in the cache */

/* replace346_1_0 -> search6_0 in the cache */

/* replace346_1_1 -> search6_0 in the cache */
static const nir_search_expression replace346_1 = {
   { nir_search_value_expression, -1 },
   false,
   2, 1,
   nir_op_fmul,
   { &search6_0.value, &search6_0.value },
   NULL,
};
static const nir_search_expression replace346 = {
   { nir_search_value_expression, -1 },
   false,
   0, 3,
   nir_op_fmul,
   { &search43_1.value, &replace346_1.value },
   NULL,
};

   /* search347_0 -> search6_0 in the cache */

/* search347_1 -> search39_1 in the cache */
static const nir_search_expression search347 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_fpow,
   { &search6_0.value, &search39_1.value },
   NULL,
};

   /* replace347 -> search6_0 in the cache */

   /* search348_0 -> search6_0 in the cache */

/* search348_1 -> search345_0_1 in the cache */
static const nir_search_expression search348 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_fpow,
   { &search6_0.value, &search345_0_1.value },
   NULL,
};

   /* replace348_0 -> search6_0 in the cache */

/* replace348_1 -> search6_0 in the cache */
/* replace348 -> replace345 in the cache */

   /* search349_0 -> search6_0 in the cache */

/* search349_1 -> search346_0_1 in the cache */
static const nir_search_expression search349 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_fpow,
   { &search6_0.value, &search346_0_1.value },
   NULL,
};

   /* replace349_0_0 -> search6_0 in the cache */

/* replace349_0_1 -> search6_0 in the cache */
/* replace349_0 -> search43_1 in the cache */

/* replace349_1_0 -> search6_0 in the cache */

/* replace349_1_1 -> search6_0 in the cache */
/* replace349_1 -> replace346_1 in the cache */
/* replace349 -> replace346 in the cache */

   /* search350_0 -> search345_0_1 in the cache */

/* search350_1 -> search6_0 in the cache */
static const nir_search_expression search350 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_fpow,
   { &search345_0_1.value, &search6_0.value },
   NULL,
};

   /* replace350_0 -> search6_0 in the cache */
/* replace350 -> search341_0 in the cache */

   /* search351_0_0 -> search6_0 in the cache */

static const nir_search_constant search351_0_1 = {
   { nir_search_value_constant, -1 },
   nir_type_float, { 0x400199999999999a /* 2.2 */ },
};
static const nir_search_expression search351_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fpow,
   { &search6_0.value, &search351_0_1.value },
   NULL,
};

static const nir_search_constant search351_1 = {
   { nir_search_value_constant, -1 },
   nir_type_float, { 0x3fdd1743e963dc48 /* 0.454545 */ },
};
static const nir_search_expression search351 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_fpow,
   { &search351_0.value, &search351_1.value },
   NULL,
};

   /* replace351 -> search6_0 in the cache */

   /* search352_0_0_0 -> search6_0 in the cache */

/* search352_0_0_1 -> search351_0_1 in the cache */
/* search352_0_0 -> search351_0 in the cache */
static const nir_search_expression search352_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fabs,
   { &search351_0.value },
   NULL,
};

/* search352_1 -> search351_1 in the cache */
static const nir_search_expression search352 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_fpow,
   { &search352_0.value, &search351_1.value },
   NULL,
};

   /* replace352_0 -> search6_0 in the cache */
/* replace352 -> search16_0 in the cache */

   /* search353_0_0 -> search6_0 in the cache */
/* search353_0 -> search341_0 in the cache */
static const nir_search_expression search353 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_fsqrt,
   { &search341_0.value },
   NULL,
};

   static const nir_search_constant replace353_0_0 = {
   { nir_search_value_constant, -1 },
   nir_type_float, { 0x3fe0000000000000 /* 0.5 */ },
};

/* replace353_0_1 -> search6_0 in the cache */
static const nir_search_expression replace353_0 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_fmul,
   { &replace353_0_0.value, &search6_0.value },
   NULL,
};
static const nir_search_expression replace353 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 1,
   nir_op_fexp2,
   { &replace353_0.value },
   NULL,
};

   /* search354_0_0 -> search6_0 in the cache */
/* search354_0 -> search341_0 in the cache */
static const nir_search_expression search354 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_frcp,
   { &search341_0.value },
   NULL,
};

   /* replace354_0_0 -> search6_0 in the cache */
/* replace354_0 -> search14_0 in the cache */
static const nir_search_expression replace354 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fexp2,
   { &search14_0.value },
   NULL,
};

   /* search355_0_0 -> search6_0 in the cache */
/* search355_0 -> search341_0 in the cache */
static const nir_search_expression search355 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_frsq,
   { &search341_0.value },
   NULL,
};

   static const nir_search_constant replace355_0_0 = {
   { nir_search_value_constant, -1 },
   nir_type_float, { 0xbfe0000000000000L /* -0.5 */ },
};

/* replace355_0_1 -> search6_0 in the cache */
static const nir_search_expression replace355_0 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_fmul,
   { &replace355_0_0.value, &search6_0.value },
   NULL,
};
static const nir_search_expression replace355 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 1,
   nir_op_fexp2,
   { &replace355_0.value },
   NULL,
};

   /* search356_0_0 -> search6_0 in the cache */
static const nir_search_expression search356_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fsqrt,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search356 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_flog2,
   { &search356_0.value },
   NULL,
};

   /* replace356_0 -> replace353_0_0 in the cache */

/* replace356_1_0 -> search6_0 in the cache */
/* replace356_1 -> search340_0 in the cache */
static const nir_search_expression replace356 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_fmul,
   { &replace353_0_0.value, &search340_0.value },
   NULL,
};

   /* search357_0_0 -> search6_0 in the cache */
static const nir_search_expression search357_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_frcp,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search357 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_flog2,
   { &search357_0.value },
   NULL,
};

   /* replace357_0_0 -> search6_0 in the cache */
/* replace357_0 -> search340_0 in the cache */
static const nir_search_expression replace357 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search340_0.value },
   NULL,
};

   /* search358_0_0 -> search6_0 in the cache */
static const nir_search_expression search358_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_frsq,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search358 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_flog2,
   { &search358_0.value },
   NULL,
};

   /* replace358_0 -> replace355_0_0 in the cache */

/* replace358_1_0 -> search6_0 in the cache */
/* replace358_1 -> search340_0 in the cache */
static const nir_search_expression replace358 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_fmul,
   { &replace355_0_0.value, &search340_0.value },
   NULL,
};

   /* search359_0_0 -> search13_0 in the cache */

/* search359_0_1 -> replace13_1_0 in the cache */
/* search359_0 -> search342 in the cache */
static const nir_search_expression search359 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_flog2,
   { &search342.value },
   NULL,
};

   /* replace359_0 -> replace13_1_0 in the cache */

/* replace359_1_0 -> search13_0 in the cache */
/* replace359_1 -> replace342_0_0 in the cache */
static const nir_search_expression replace359 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_fmul,
   { &replace13_1_0.value, &replace342_0_0.value },
   NULL,
};

   /* search360_0_0 -> search13_0 in the cache */
static const nir_search_expression search360_0 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fexp2,
   { &search13_0.value },
   (is_used_once),
};

/* search360_1_0 -> replace13_1_0 in the cache */
static const nir_search_expression search360_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fexp2,
   { &replace13_1_0.value },
   (is_used_once),
};
static const nir_search_expression search360 = {
   { nir_search_value_expression, -2 },
   true,
   0, 1,
   nir_op_fmul,
   { &search360_0.value, &search360_1.value },
   NULL,
};

   /* replace360_0_0 -> search13_0 in the cache */

/* replace360_0_1 -> replace13_1_0 in the cache */
/* replace360_0 -> replace48 in the cache */
static const nir_search_expression replace360 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 1,
   nir_op_fexp2,
   { &replace48.value },
   NULL,
};

   /* search361_0 -> search39_1 in the cache */

/* search361_1 -> search6_0 in the cache */
static const nir_search_expression search361 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_fdiv,
   { &search39_1.value, &search6_0.value },
   NULL,
};

   /* replace361_0 -> search6_0 in the cache */
/* replace361 -> search357_0 in the cache */

   /* search362_0 -> search13_0 in the cache */

/* search362_1 -> replace13_1_0 in the cache */
static const nir_search_expression search362 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fdiv,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace362_0 -> search13_0 in the cache */

/* replace362_1_0 -> replace13_1_0 in the cache */
static const nir_search_expression replace362_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_frcp,
   { &replace13_1_0.value },
   NULL,
};
static const nir_search_expression replace362 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_fmul,
   { &search13_0.value, &replace362_1.value },
   NULL,
};

   /* search363_0_0 -> search6_0 in the cache */
/* search363_0 -> search357_0 in the cache */
static const nir_search_expression search363 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_frcp,
   { &search357_0.value },
   NULL,
};

   /* replace363 -> search6_0 in the cache */

   /* search364_0_0 -> search6_0 in the cache */
/* search364_0 -> search356_0 in the cache */
static const nir_search_expression search364 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_frcp,
   { &search356_0.value },
   NULL,
};

   /* replace364_0 -> search6_0 in the cache */
/* replace364 -> search358_0 in the cache */

   /* search365_0 -> search6_0 in the cache */
/* search365 -> search356_0 in the cache */

   /* replace365_0_0 -> search6_0 in the cache */
/* replace365_0 -> search358_0 in the cache */
static const nir_search_expression replace365 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_frcp,
   { &search358_0.value },
   NULL,
};

   /* search366_0_0 -> search6_0 in the cache */
/* search366_0 -> search358_0 in the cache */
static const nir_search_expression search366 = {
   { nir_search_value_expression, -1 },
   true,
   -1, 0,
   nir_op_frcp,
   { &search358_0.value },
   NULL,
};

   /* replace366_0 -> search6_0 in the cache */
/* replace366 -> search356_0 in the cache */

   /* search367_0 -> search6_0 in the cache */
static const nir_search_expression search367 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2b32,
   { &search6_0.value },
   (is_used_by_if),
};

   /* replace367_0 -> search6_0 in the cache */

/* replace367_1 -> replace8 in the cache */
static const nir_search_expression replace367 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_ine32,
   { &search6_0.value, &replace8.value },
   NULL,
};

   /* search368_0 -> search6_0 in the cache */
static const nir_search_expression search368 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_i2b1,
   { &search6_0.value },
   (is_used_by_if),
};

   /* replace368_0 -> search6_0 in the cache */

/* replace368_1 -> replace8 in the cache */
/* replace368 -> replace132 in the cache */

   /* search369_0 -> replace72_0 in the cache */

/* search369_1 -> replace134 in the cache */
static const nir_search_expression search369 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &replace72_0.value, &replace134.value },
   NULL,
};

   /* replace369 -> replace72_0 in the cache */

   /* search370_0 -> replace72_0 in the cache */

/* search370_1 -> replace134 in the cache */
static const nir_search_expression search370 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &replace72_0.value, &replace134.value },
   (is_not_used_by_if),
};

   /* replace370_0 -> replace72_0 in the cache */
/* replace370 -> replace91 in the cache */

   /* search371_0 -> replace72_0 in the cache */

/* search371_1 -> replace136 in the cache */
static const nir_search_expression search371 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &replace72_0.value, &replace136.value },
   NULL,
};

   /* replace371 -> replace72_0 in the cache */

   /* search372_0 -> replace72_0 in the cache */

/* search372_1 -> replace136 in the cache */
static const nir_search_expression search372 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &replace72_0.value, &replace136.value },
   (is_not_used_by_if),
};

   /* replace372_0 -> replace72_0 in the cache */
/* replace372 -> replace91 in the cache */

   /* search373_0 -> replace72_0 in the cache */

/* search373_1 -> replace134 in the cache */

/* search373_2 -> replace136 in the cache */
static const nir_search_expression search373 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &replace134.value, &replace136.value },
   NULL,
};

   /* replace373 -> replace72_0 in the cache */

   /* search374_0 -> replace72_0 in the cache */

/* search374_1 -> replace136 in the cache */

/* search374_2 -> replace134 in the cache */
static const nir_search_expression search374 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &replace136.value, &replace134.value },
   NULL,
};

   /* replace374_0 -> replace72_0 in the cache */
/* replace374 -> replace91 in the cache */

   /* search375_0 -> replace72_0 in the cache */

/* search375_1 -> search65_0_1_0 in the cache */

/* search375_2 -> search244_0_1 in the cache */
static const nir_search_expression search375 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search65_0_1_0.value, &search244_0_1.value },
   NULL,
};

   /* replace375_0 -> replace72_0 in the cache */
static const nir_search_expression replace375 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &replace72_0.value },
   NULL,
};

   /* search376_0 -> replace72_0 in the cache */

/* search376_1 -> search244_0_1 in the cache */

/* search376_2 -> search65_0_1_0 in the cache */
static const nir_search_expression search376 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search244_0_1.value, &search65_0_1_0.value },
   NULL,
};

   /* replace376_0_0 -> replace72_0 in the cache */
/* replace376_0 -> replace91 in the cache */
static const nir_search_expression replace376 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &replace91.value },
   NULL,
};

   /* search377_0 -> replace72_0 in the cache */

static const nir_search_constant search377_1 = {
   { nir_search_value_constant, 32 },
   nir_type_float, { 0xbff0000000000000L /* -1.0 */ },
};

static const nir_search_constant search377_2 = {
   { nir_search_value_constant, 32 },
   nir_type_float, { 0x8000000000000000L /* -0.0 */ },
};
static const nir_search_expression search377 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search377_1.value, &search377_2.value },
   NULL,
};

   /* replace377_0_0 -> replace72_0 in the cache */
/* replace377_0 -> replace375 in the cache */
static const nir_search_expression replace377 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fneg,
   { &replace375.value },
   NULL,
};

   /* search378_0 -> replace72_0 in the cache */

/* search378_1 -> search377_2 in the cache */

/* search378_2 -> search377_1 in the cache */
static const nir_search_expression search378 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search377_2.value, &search377_1.value },
   NULL,
};

   /* replace378_0_0_0 -> replace72_0 in the cache */
/* replace378_0_0 -> replace91 in the cache */
/* replace378_0 -> replace376 in the cache */
static const nir_search_expression replace378 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fneg,
   { &replace376.value },
   NULL,
};

   /* search379_0 -> replace134 in the cache */

/* search379_1 -> search155_0_0 in the cache */

/* search379_2 -> search55_2 in the cache */
static const nir_search_expression search379 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace134.value, &search155_0_0.value, &search55_2.value },
   NULL,
};

   /* replace379 -> search155_0_0 in the cache */

   /* search380_0 -> replace136 in the cache */

/* search380_1 -> search155_0_0 in the cache */

/* search380_2 -> search55_2 in the cache */
static const nir_search_expression search380 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace136.value, &search155_0_0.value, &search55_2.value },
   NULL,
};

   /* replace380 -> search55_2 in the cache */

   /* search381_0 -> replace72_0 in the cache */

/* search381_1_0 -> replace0_1_0 in the cache */
static const nir_search_expression search381_1 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &replace0_1_0.value },
   (is_used_once),
};

/* search381_2_0 -> search57_2 in the cache */
static const nir_search_expression search381_2 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &search57_2.value },
   NULL,
};
static const nir_search_expression search381 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search381_1.value, &search381_2.value },
   NULL,
};

   /* replace381_0_0 -> replace72_0 in the cache */

/* replace381_0_1 -> replace0_1_0 in the cache */

/* replace381_0_2 -> search57_2 in the cache */
static const nir_search_expression replace381_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &replace0_1_0.value, &search57_2.value },
   NULL,
};
static const nir_search_expression replace381 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &replace381_0.value },
   NULL,
};

   static const nir_search_variable search382_0 = {
   { nir_search_value_variable, 1 },
   0, /* a */
   true,
   nir_type_invalid,
   NULL,
};

/* search382_1 -> search27_0_1 in the cache */

/* search382_2 -> search27_1_1 in the cache */
static const nir_search_expression search382 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search382_0.value, &search27_0_1.value, &search27_1_1.value },
   NULL,
};

   /* replace382_0_0 -> replace72_0 in the cache */

static const nir_search_constant replace382_0_1 = {
   { nir_search_value_constant, 1 },
   nir_type_int, { 0x0 /* 0 */ },
};
static const nir_search_expression replace382_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &replace72_0.value, &replace382_0_1.value },
   NULL,
};

/* replace382_1 -> search27_0_1 in the cache */

/* replace382_2 -> search27_1_1 in the cache */
static const nir_search_expression replace382 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 1,
   nir_op_bcsel,
   { &replace382_0.value, &search27_0_1.value, &search27_1_1.value },
   NULL,
};

   /* search383_0 -> replace72_0 in the cache */

/* search383_1 -> replace13_1_0 in the cache */

/* search383_2 -> replace13_1_0 in the cache */
static const nir_search_expression search383 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &replace13_1_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace383 -> replace13_1_0 in the cache */

   /* search384_0 -> search0_0 in the cache */

/* search384_1 -> replace0_1_0 in the cache */

/* search384_2 -> replace0_1_0 in the cache */
static const nir_search_expression search384 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fcsel,
   { &search0_0.value, &replace0_1_0.value, &replace0_1_0.value },
   NULL,
};

   /* replace384 -> replace0_1_0 in the cache */

   /* search385_0 -> replace72_0 in the cache */

static const nir_search_constant search385_1 = {
   { nir_search_value_constant, 0 },
   nir_type_int, { -0x1 /* -1 */ },
};

/* search385_2 -> search130_1 in the cache */
static const nir_search_expression search385 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search385_1.value, &search130_1.value },
   NULL,
};

   /* replace385_0_0 -> replace72_0 in the cache */
/* replace385_0 -> search130_0 in the cache */
static const nir_search_expression replace385 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search130_0.value },
   NULL,
};

   /* search386_0 -> replace72_0 in the cache */

/* search386_1 -> search130_1 in the cache */

/* search386_2 -> search385_1 in the cache */
static const nir_search_expression search386 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search130_1.value, &search385_1.value },
   NULL,
};

   /* replace386_0_0_0 -> replace72_0 in the cache */
/* replace386_0_0 -> replace91 in the cache */
static const nir_search_expression replace386_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_b2i,
   { &replace91.value },
   NULL,
};
static const nir_search_expression replace386 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_ineg,
   { &replace386_0.value },
   NULL,
};

   /* search387_0_0_0 -> replace72_0 in the cache */
/* search387_0_0 -> search130_0 in the cache */
/* search387_0 -> replace385 in the cache */

/* search387_1_0_0 -> search93_0_1_0 in the cache */
/* search387_1_0 -> search302_1 in the cache */
static const nir_search_expression search387_1 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search302_1.value },
   NULL,
};
static const nir_search_expression search387 = {
   { nir_search_value_expression, 0 },
   false,
   0, 1,
   nir_op_iand,
   { &replace385.value, &search387_1.value },
   NULL,
};

   /* replace387_0_0_0 -> replace72_0 in the cache */

/* replace387_0_0_1 -> search93_0_1_0 in the cache */
/* replace387_0_0 -> replace97 in the cache */
/* replace387_0 -> replace302 in the cache */
static const nir_search_expression replace387 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 1,
   nir_op_ineg,
   { &replace302.value },
   NULL,
};

   /* search388_0_0_0 -> replace72_0 in the cache */
/* search388_0_0 -> search130_0 in the cache */
/* search388_0 -> replace385 in the cache */

/* search388_1_0_0 -> search93_0_1_0 in the cache */
/* search388_1_0 -> search302_1 in the cache */
/* search388_1 -> search387_1 in the cache */
static const nir_search_expression search388 = {
   { nir_search_value_expression, 0 },
   false,
   0, 1,
   nir_op_ior,
   { &replace385.value, &search387_1.value },
   NULL,
};

   /* replace388_0_0_0 -> replace72_0 in the cache */

/* replace388_0_0_1 -> search93_0_1_0 in the cache */
/* replace388_0_0 -> replace93 in the cache */
static const nir_search_expression replace388_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 1,
   nir_search_op_b2i,
   { &replace93.value },
   NULL,
};
static const nir_search_expression replace388 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 1,
   nir_op_ineg,
   { &replace388_0.value },
   NULL,
};

   /* search389_0_0_0 -> replace72_0 in the cache */
/* search389_0_0 -> search130_0 in the cache */
/* search389_0 -> replace385 in the cache */

/* search389_1 -> search130_1 in the cache */
static const nir_search_expression search389 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &replace385.value, &search130_1.value },
   NULL,
};

   /* replace389_0 -> replace72_0 in the cache */
/* replace389 -> replace91 in the cache */

   /* search390_0_0_0 -> replace72_0 in the cache */
/* search390_0_0 -> search130_0 in the cache */
/* search390_0 -> replace385 in the cache */

/* search390_1 -> search385_1 in the cache */
static const nir_search_expression search390 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &replace385.value, &search385_1.value },
   NULL,
};

   /* replace390 -> replace72_0 in the cache */

   /* search391_0_0_0 -> replace72_0 in the cache */
/* search391_0_0 -> search130_0 in the cache */
/* search391_0 -> replace385 in the cache */

/* search391_1 -> search130_1 in the cache */
static const nir_search_expression search391 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &replace385.value, &search130_1.value },
   NULL,
};

   /* replace391 -> replace72_0 in the cache */

   /* search392_0_0_0 -> replace72_0 in the cache */
/* search392_0_0 -> search130_0 in the cache */
/* search392_0 -> replace385 in the cache */

/* search392_1 -> search385_1 in the cache */
static const nir_search_expression search392 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &replace385.value, &search385_1.value },
   NULL,
};

   /* replace392_0 -> replace72_0 in the cache */
/* replace392 -> replace91 in the cache */

   /* search393_0_0_0 -> search6_0 in the cache */
static const nir_search_expression search393_0_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_b2i,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search393_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search393_0_0.value },
   NULL,
};

/* search393_1 -> search95_0_1 in the cache */
static const nir_search_expression search393 = {
   { nir_search_value_expression, 0 },
   false,
   0, 1,
   nir_op_iand,
   { &search393_0.value, &search95_0_1.value },
   NULL,
};

   /* replace393_0 -> search6_0 in the cache */
/* replace393 -> search200_0 in the cache */

   /* search394_0 -> search0_0 in the cache */

static const nir_search_constant search394_1_0 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x1f /* 31 */ },
};

/* search394_1_1 -> replace0_1_0 in the cache */
static const nir_search_expression search394_1 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_iand,
   { &search394_1_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression search394 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_ishl,
   { &search0_0.value, &search394_1.value },
   NULL,
};

   /* replace394_0 -> search0_0 in the cache */

/* replace394_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace394 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* search395_0 -> search0_0 in the cache */

/* search395_1_0 -> search394_1_0 in the cache */

/* search395_1_1 -> replace0_1_0 in the cache */
/* search395_1 -> search394_1 in the cache */
static const nir_search_expression search395 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_ishr,
   { &search0_0.value, &search394_1.value },
   NULL,
};

   /* replace395_0 -> search0_0 in the cache */

/* replace395_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace395 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* search396_0 -> search0_0 in the cache */

/* search396_1_0 -> search394_1_0 in the cache */

/* search396_1_1 -> replace0_1_0 in the cache */
/* search396_1 -> search394_1 in the cache */
static const nir_search_expression search396 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_ushr,
   { &search0_0.value, &search394_1.value },
   NULL,
};

   /* replace396_0 -> search0_0 in the cache */

/* replace396_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace396 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* search397_0_0 -> search0_0 in the cache */
static const nir_search_expression search397_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_b2i,
   { &search0_0.value },
   NULL,
};
static const nir_search_expression search397 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2b32,
   { &search397_0.value },
   NULL,
};

   /* replace397 -> search0_0 in the cache */

   /* search398_0_0 -> search6_0 in the cache */
/* search398_0 -> search59 in the cache */
static const nir_search_expression search398 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_f2i,
   { &search59.value },
   NULL,
};

   /* replace398_0 -> search6_0 in the cache */
static const nir_search_expression replace398 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_f2i,
   { &search6_0.value },
   NULL,
};

   /* search399_0_0 -> search6_0 in the cache */
/* search399_0 -> search59 in the cache */
static const nir_search_expression search399 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_f2u,
   { &search59.value },
   NULL,
};

   /* replace399_0 -> search6_0 in the cache */
static const nir_search_expression replace399 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_f2u,
   { &search6_0.value },
   NULL,
};

   /* search400_0_0 -> search6_0 in the cache */
/* search400_0 -> search15_0 in the cache */
/* search400 -> search22 in the cache */

   /* replace400_0 -> search6_0 in the cache */
/* replace400 -> replace22 in the cache */

   /* search401_0_0 -> search6_0 in the cache */
/* search401_0 -> search19_0 in the cache */
static const nir_search_expression search401 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_i2b,
   { &search19_0.value },
   NULL,
};

   /* replace401_0 -> search6_0 in the cache */
/* replace401 -> replace22 in the cache */

   /* search402_0_0 -> search6_0 in the cache */
/* search402_0 -> search200_0 in the cache */
static const nir_search_expression search402 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_fabs,
   { &search200_0.value },
   NULL,
};

   /* replace402_0 -> search6_0 in the cache */
/* replace402 -> search200_0 in the cache */

   /* search403_0_0 -> search6_0 in the cache */
/* search403_0 -> search393_0_0 in the cache */
static const nir_search_expression search403 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_op_iabs,
   { &search393_0_0.value },
   NULL,
};

   /* replace403_0 -> search6_0 in the cache */
/* replace403 -> search393_0_0 in the cache */

   /* search404_0_0 -> search6_0 in the cache */
static const nir_search_expression search404_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_f2b1,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search404 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_inot,
   { &search404_0.value },
   NULL,
};

   /* replace404_0 -> search6_0 in the cache */

/* replace404_1 -> search23_1 in the cache */
/* replace404 -> replace146 in the cache */

   /* search405_0_0 -> search0_0 in the cache */
static const nir_search_expression search405_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_i2f,
   { &search0_0.value },
   NULL,
};
static const nir_search_expression search405 = {
   { nir_search_value_expression, 32 },
   true,
   -1, 0,
   nir_op_f2i32,
   { &search405_0.value },
   NULL,
};

   /* replace405 -> search0_0 in the cache */

   /* search406_0_0 -> search0_0 in the cache */
static const nir_search_expression search406_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_u2f,
   { &search0_0.value },
   NULL,
};
static const nir_search_expression search406 = {
   { nir_search_value_expression, 32 },
   true,
   -1, 0,
   nir_op_f2i32,
   { &search406_0.value },
   NULL,
};

   /* replace406 -> search0_0 in the cache */

   /* search407_0_0 -> search0_0 in the cache */
/* search407_0 -> search405_0 in the cache */
static const nir_search_expression search407 = {
   { nir_search_value_expression, 32 },
   true,
   -1, 0,
   nir_op_f2u32,
   { &search405_0.value },
   NULL,
};

   /* replace407 -> search0_0 in the cache */

   /* search408_0_0 -> search0_0 in the cache */
/* search408_0 -> search406_0 in the cache */
static const nir_search_expression search408 = {
   { nir_search_value_expression, 32 },
   true,
   -1, 0,
   nir_op_f2u32,
   { &search406_0.value },
   NULL,
};

   /* replace408 -> search0_0 in the cache */

   /* search409_0_0 -> search6_0 in the cache */
static const nir_search_expression search409_0 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_search_op_f2u,
   { &search6_0.value },
   NULL,
};

/* search409_1 -> replace13_1_0 in the cache */
static const nir_search_expression search409 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search409_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace409_0_0 -> search6_0 in the cache */
static const nir_search_expression replace409_0 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_search_op_f2i,
   { &search6_0.value },
   NULL,
};

/* replace409_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace409 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &replace409_0.value, &replace13_1_0.value },
   NULL,
};

   static const nir_search_variable search410_0 = {
   { nir_search_value_variable, -1 },
   0, /* b */
   false,
   nir_type_invalid,
   NULL,
};

/* search410_1_0 -> search155_0_1 in the cache */
static const nir_search_expression search410_1 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_search_op_f2u,
   { &search155_0_1.value },
   NULL,
};
static const nir_search_expression search410 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search410_0.value, &search410_1.value },
   NULL,
};

   /* replace410_0 -> search410_0 in the cache */

/* replace410_1_0 -> search155_0_1 in the cache */
static const nir_search_expression replace410_1 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_search_op_f2i,
   { &search155_0_1.value },
   NULL,
};
static const nir_search_expression replace410 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search410_0.value, &replace410_1.value },
   NULL,
};

   /* search411_0_0 -> search6_0 in the cache */
/* search411_0 -> search409_0 in the cache */

/* search411_1 -> replace13_1_0 in the cache */
static const nir_search_expression search411 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search409_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace411_0_0 -> search6_0 in the cache */
/* replace411_0 -> replace409_0 in the cache */

/* replace411_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace411 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &replace409_0.value, &replace13_1_0.value },
   NULL,
};

   /* search412_0 -> search410_0 in the cache */

/* search412_1_0 -> search155_0_1 in the cache */
/* search412_1 -> search410_1 in the cache */
static const nir_search_expression search412 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search410_0.value, &search410_1.value },
   NULL,
};

   /* replace412_0 -> search410_0 in the cache */

/* replace412_1_0 -> search155_0_1 in the cache */
/* replace412_1 -> replace410_1 in the cache */
static const nir_search_expression replace412 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search410_0.value, &replace410_1.value },
   NULL,
};

   /* search413_0_0 -> search0_0 in the cache */

/* search413_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression search413_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_pack_64_2x32_split,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression search413 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_unpack_64_2x32_split_x,
   { &search413_0.value },
   NULL,
};

   /* replace413 -> search0_0 in the cache */

   /* search414_0_0 -> search0_0 in the cache */

/* search414_0_1 -> replace0_1_0 in the cache */
/* search414_0 -> search413_0 in the cache */
static const nir_search_expression search414 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_unpack_64_2x32_split_y,
   { &search413_0.value },
   NULL,
};

   /* replace414 -> replace0_1_0 in the cache */

   /* search415_0_0 -> search58_0 in the cache */
static const nir_search_expression search415_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_unpack_64_2x32_split_x,
   { &search58_0.value },
   NULL,
};

/* search415_1_0 -> search58_0 in the cache */
static const nir_search_expression search415_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_unpack_64_2x32_split_y,
   { &search58_0.value },
   NULL,
};
static const nir_search_expression search415 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_pack_64_2x32_split,
   { &search415_0.value, &search415_1.value },
   NULL,
};

   /* replace415 -> search58_0 in the cache */

   /* search416_0 -> search56_0 in the cache */

static const nir_search_constant search416_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x8 /* 8 */ },
};
static const nir_search_expression search416 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search56_0.value, &search416_1.value },
   NULL,
};

   /* replace416_0 -> search56_0 in the cache */

static const nir_search_constant replace416_1 = {
   { nir_search_value_constant, 16 },
   nir_type_int, { 0x1 /* 1 */ },
};
static const nir_search_expression replace416 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search56_0.value, &replace416_1.value },
   NULL,
};

   /* search417_0 -> search0_0 in the cache */

/* search417_1 -> search338_1_1 in the cache */
/* search417 -> search338_1 in the cache */

   /* replace417_0 -> search0_0 in the cache */

static const nir_search_constant replace417_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x3 /* 3 */ },
};
static const nir_search_expression replace417 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search0_0.value, &replace417_1.value },
   NULL,
};

   /* search418_0 -> search58_0 in the cache */

static const nir_search_constant search418_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x38 /* 56 */ },
};
static const nir_search_expression search418 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search58_0.value, &search418_1.value },
   NULL,
};

   /* replace418_0 -> search58_0 in the cache */

static const nir_search_constant replace418_1 = {
   { nir_search_value_constant, 64 },
   nir_type_int, { 0x7 /* 7 */ },
};
static const nir_search_expression replace418 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search58_0.value, &replace418_1.value },
   NULL,
};

   /* search419_0 -> search56_0 in the cache */

/* search419_1 -> search416_1 in the cache */
static const nir_search_expression search419 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search56_0.value, &search416_1.value },
   NULL,
};

   /* replace419_0 -> search56_0 in the cache */

/* replace419_1 -> replace416_1 in the cache */
static const nir_search_expression replace419 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search56_0.value, &replace416_1.value },
   NULL,
};

   /* search420_0 -> search0_0 in the cache */

/* search420_1 -> search338_1_1 in the cache */
static const nir_search_expression search420 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search0_0.value, &search338_1_1.value },
   NULL,
};

   /* replace420_0 -> search0_0 in the cache */

/* replace420_1 -> replace417_1 in the cache */
static const nir_search_expression replace420 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search0_0.value, &replace417_1.value },
   NULL,
};

   /* search421_0 -> search58_0 in the cache */

/* search421_1 -> search418_1 in the cache */
static const nir_search_expression search421 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search58_0.value, &search418_1.value },
   NULL,
};

   /* replace421_0 -> search58_0 in the cache */

/* replace421_1 -> replace418_1 in the cache */
static const nir_search_expression replace421 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search58_0.value, &replace418_1.value },
   NULL,
};

   /* search422_0 -> search208_0_1 in the cache */

/* search422_1 -> search6_0 in the cache */
static const nir_search_expression search422 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_iand,
   { &search208_0_1.value, &search6_0.value },
   NULL,
};

   /* replace422_0 -> search6_0 in the cache */

/* replace422_1 -> replace8 in the cache */
static const nir_search_expression replace422 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search6_0.value, &replace8.value },
   NULL,
};

   /* search423_0_0 -> search56_0 in the cache */

/* search423_0_1 -> search416_1 in the cache */
/* search423_0 -> search416 in the cache */

static const nir_search_constant search423_1 = {
   { nir_search_value_constant, 16 },
   nir_type_int, { 0x0 /* 0 */ },
};
static const nir_search_expression search423 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search416.value, &search423_1.value },
   NULL,
};

   /* replace423_0 -> search56_0 in the cache */

/* replace423_1 -> replace416_1 in the cache */
/* replace423 -> replace416 in the cache */

   /* search424_0_0 -> search0_0 in the cache */

/* search424_0_1 -> search416_1 in the cache */
static const nir_search_expression search424_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search0_0.value, &search416_1.value },
   NULL,
};

/* search424_1 -> search25_1 in the cache */
static const nir_search_expression search424 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search424_0.value, &search25_1.value },
   NULL,
};

   /* replace424_0 -> search0_0 in the cache */

static const nir_search_constant replace424_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x1 /* 1 */ },
};
static const nir_search_expression replace424 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search0_0.value, &replace424_1.value },
   NULL,
};

   /* search425_0_0 -> search0_0 in the cache */

/* search425_0_1 -> search339_1_1 in the cache */
/* search425_0 -> search339_1 in the cache */

/* search425_1 -> search25_1 in the cache */
static const nir_search_expression search425 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search339_1.value, &search25_1.value },
   NULL,
};

   /* replace425_0 -> search0_0 in the cache */

static const nir_search_constant replace425_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x2 /* 2 */ },
};
static const nir_search_expression replace425 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search0_0.value, &replace425_1.value },
   NULL,
};

   /* search426_0_0 -> search0_0 in the cache */

/* search426_0_1 -> search338_1_1 in the cache */
/* search426_0 -> search338_1 in the cache */

/* search426_1 -> search25_1 in the cache */
static const nir_search_expression search426 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search338_1.value, &search25_1.value },
   NULL,
};

   /* replace426_0 -> search0_0 in the cache */

/* replace426_1 -> replace417_1 in the cache */
/* replace426 -> replace417 in the cache */

   /* search427_0_0 -> search58_0 in the cache */

/* search427_0_1 -> search416_1 in the cache */
static const nir_search_expression search427_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search58_0.value, &search416_1.value },
   NULL,
};

static const nir_search_constant search427_1 = {
   { nir_search_value_constant, 64 },
   nir_type_int, { 0x0 /* 0 */ },
};
static const nir_search_expression search427 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search427_0.value, &search427_1.value },
   NULL,
};

   /* replace427_0 -> search58_0 in the cache */

static const nir_search_constant replace427_1 = {
   { nir_search_value_constant, 64 },
   nir_type_int, { 0x1 /* 1 */ },
};
static const nir_search_expression replace427 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search58_0.value, &replace427_1.value },
   NULL,
};

   /* search428_0_0 -> search58_0 in the cache */

/* search428_0_1 -> search339_1_1 in the cache */
static const nir_search_expression search428_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search58_0.value, &search339_1_1.value },
   NULL,
};

/* search428_1 -> search427_1 in the cache */
static const nir_search_expression search428 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search428_0.value, &search427_1.value },
   NULL,
};

   /* replace428_0 -> search58_0 in the cache */

static const nir_search_constant replace428_1 = {
   { nir_search_value_constant, 64 },
   nir_type_int, { 0x2 /* 2 */ },
};
static const nir_search_expression replace428 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search58_0.value, &replace428_1.value },
   NULL,
};

   /* search429_0_0 -> search58_0 in the cache */

/* search429_0_1 -> search338_1_1 in the cache */
static const nir_search_expression search429_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search58_0.value, &search338_1_1.value },
   NULL,
};

/* search429_1 -> search427_1 in the cache */
static const nir_search_expression search429 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search429_0.value, &search427_1.value },
   NULL,
};

   /* replace429_0 -> search58_0 in the cache */

static const nir_search_constant replace429_1 = {
   { nir_search_value_constant, 64 },
   nir_type_int, { 0x3 /* 3 */ },
};
static const nir_search_expression replace429 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search58_0.value, &replace429_1.value },
   NULL,
};

   /* search430_0_0 -> search58_0 in the cache */

static const nir_search_constant search430_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x20 /* 32 */ },
};
static const nir_search_expression search430_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search58_0.value, &search430_0_1.value },
   NULL,
};

/* search430_1 -> search427_1 in the cache */
static const nir_search_expression search430 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search430_0.value, &search427_1.value },
   NULL,
};

   /* replace430_0 -> search58_0 in the cache */

static const nir_search_constant replace430_1 = {
   { nir_search_value_constant, 64 },
   nir_type_int, { 0x4 /* 4 */ },
};
static const nir_search_expression replace430 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search58_0.value, &replace430_1.value },
   NULL,
};

   /* search431_0_0 -> search58_0 in the cache */

static const nir_search_constant search431_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x28 /* 40 */ },
};
static const nir_search_expression search431_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search58_0.value, &search431_0_1.value },
   NULL,
};

/* search431_1 -> search427_1 in the cache */
static const nir_search_expression search431 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search431_0.value, &search427_1.value },
   NULL,
};

   /* replace431_0 -> search58_0 in the cache */

static const nir_search_constant replace431_1 = {
   { nir_search_value_constant, 64 },
   nir_type_int, { 0x5 /* 5 */ },
};
static const nir_search_expression replace431 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search58_0.value, &replace431_1.value },
   NULL,
};

   /* search432_0_0 -> search58_0 in the cache */

static const nir_search_constant search432_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x30 /* 48 */ },
};
static const nir_search_expression search432_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search58_0.value, &search432_0_1.value },
   NULL,
};

/* search432_1 -> search427_1 in the cache */
static const nir_search_expression search432 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search432_0.value, &search427_1.value },
   NULL,
};

   /* replace432_0 -> search58_0 in the cache */

static const nir_search_constant replace432_1 = {
   { nir_search_value_constant, 64 },
   nir_type_int, { 0x6 /* 6 */ },
};
static const nir_search_expression replace432 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search58_0.value, &replace432_1.value },
   NULL,
};

   /* search433_0_0 -> search58_0 in the cache */

/* search433_0_1 -> search418_1 in the cache */
/* search433_0 -> search418 in the cache */

/* search433_1 -> search427_1 in the cache */
static const nir_search_expression search433 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search418.value, &search427_1.value },
   NULL,
};

   /* replace433_0 -> search58_0 in the cache */

/* replace433_1 -> replace418_1 in the cache */
/* replace433 -> replace418 in the cache */

   /* search434_0_0 -> search56_0 in the cache */

/* search434_0_1 -> search416_1 in the cache */
/* search434_0 -> search419 in the cache */

/* search434_1 -> search423_1 in the cache */
static const nir_search_expression search434 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search419.value, &search423_1.value },
   NULL,
};

   /* replace434_0 -> search56_0 in the cache */

/* replace434_1 -> replace416_1 in the cache */
/* replace434 -> replace416 in the cache */

   /* search435_0_0 -> search0_0 in the cache */

/* search435_0_1 -> search416_1 in the cache */
static const nir_search_expression search435_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search0_0.value, &search416_1.value },
   NULL,
};

/* search435_1 -> search25_1 in the cache */
static const nir_search_expression search435 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search435_0.value, &search25_1.value },
   NULL,
};

   /* replace435_0 -> search0_0 in the cache */

/* replace435_1 -> replace424_1 in the cache */
/* replace435 -> replace424 in the cache */

   /* search436_0_0 -> search0_0 in the cache */

/* search436_0_1 -> search339_1_1 in the cache */
static const nir_search_expression search436_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search0_0.value, &search339_1_1.value },
   NULL,
};

/* search436_1 -> search25_1 in the cache */
static const nir_search_expression search436 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search436_0.value, &search25_1.value },
   NULL,
};

   /* replace436_0 -> search0_0 in the cache */

/* replace436_1 -> replace425_1 in the cache */
/* replace436 -> replace425 in the cache */

   /* search437_0_0 -> search0_0 in the cache */

/* search437_0_1 -> search338_1_1 in the cache */
/* search437_0 -> search420 in the cache */

/* search437_1 -> search25_1 in the cache */
static const nir_search_expression search437 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search420.value, &search25_1.value },
   NULL,
};

   /* replace437_0 -> search0_0 in the cache */

/* replace437_1 -> replace417_1 in the cache */
/* replace437 -> replace417 in the cache */

   /* search438_0_0 -> search58_0 in the cache */

/* search438_0_1 -> search416_1 in the cache */
static const nir_search_expression search438_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search58_0.value, &search416_1.value },
   NULL,
};

/* search438_1 -> search427_1 in the cache */
static const nir_search_expression search438 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search438_0.value, &search427_1.value },
   NULL,
};

   /* replace438_0 -> search58_0 in the cache */

/* replace438_1 -> replace427_1 in the cache */
/* replace438 -> replace427 in the cache */

   /* search439_0_0 -> search58_0 in the cache */

/* search439_0_1 -> search339_1_1 in the cache */
static const nir_search_expression search439_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search58_0.value, &search339_1_1.value },
   NULL,
};

/* search439_1 -> search427_1 in the cache */
static const nir_search_expression search439 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search439_0.value, &search427_1.value },
   NULL,
};

   /* replace439_0 -> search58_0 in the cache */

/* replace439_1 -> replace428_1 in the cache */
/* replace439 -> replace428 in the cache */

   /* search440_0_0 -> search58_0 in the cache */

/* search440_0_1 -> search338_1_1 in the cache */
static const nir_search_expression search440_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search58_0.value, &search338_1_1.value },
   NULL,
};

/* search440_1 -> search427_1 in the cache */
static const nir_search_expression search440 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search440_0.value, &search427_1.value },
   NULL,
};

   /* replace440_0 -> search58_0 in the cache */

/* replace440_1 -> replace429_1 in the cache */
/* replace440 -> replace429 in the cache */

   /* search441_0_0 -> search58_0 in the cache */

/* search441_0_1 -> search430_0_1 in the cache */
static const nir_search_expression search441_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search58_0.value, &search430_0_1.value },
   NULL,
};

/* search441_1 -> search427_1 in the cache */
static const nir_search_expression search441 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search441_0.value, &search427_1.value },
   NULL,
};

   /* replace441_0 -> search58_0 in the cache */

/* replace441_1 -> replace430_1 in the cache */
/* replace441 -> replace430 in the cache */

   /* search442_0_0 -> search58_0 in the cache */

/* search442_0_1 -> search431_0_1 in the cache */
static const nir_search_expression search442_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search58_0.value, &search431_0_1.value },
   NULL,
};

/* search442_1 -> search427_1 in the cache */
static const nir_search_expression search442 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search442_0.value, &search427_1.value },
   NULL,
};

   /* replace442_0 -> search58_0 in the cache */

/* replace442_1 -> replace431_1 in the cache */
/* replace442 -> replace431 in the cache */

   /* search443_0_0 -> search58_0 in the cache */

/* search443_0_1 -> search432_0_1 in the cache */
static const nir_search_expression search443_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search58_0.value, &search432_0_1.value },
   NULL,
};

/* search443_1 -> search427_1 in the cache */
static const nir_search_expression search443 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search443_0.value, &search427_1.value },
   NULL,
};

   /* replace443_0 -> search58_0 in the cache */

/* replace443_1 -> replace432_1 in the cache */
/* replace443 -> replace432 in the cache */

   /* search444_0_0 -> search58_0 in the cache */

/* search444_0_1 -> search418_1 in the cache */
/* search444_0 -> search421 in the cache */

/* search444_1 -> search427_1 in the cache */
static const nir_search_expression search444 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search421.value, &search427_1.value },
   NULL,
};

   /* replace444_0 -> search58_0 in the cache */

/* replace444_1 -> replace418_1 in the cache */
/* replace444 -> replace418 in the cache */

   /* search445_0_0 -> search6_0 in the cache */

/* search445_0_1 -> search6_1 in the cache */
static const nir_search_expression search445_0 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_extract_u16,
   { &search6_0.value, &search6_1.value },
   NULL,
};

/* search445_1 -> replace8 in the cache */
static const nir_search_expression search445 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search445_0.value, &replace8.value },
   NULL,
};

   /* replace445_0 -> search6_0 in the cache */

/* replace445_1 -> search242_1_1 in the cache */
static const nir_search_expression replace445 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search6_0.value, &search242_1_1.value },
   NULL,
};

   /* search446_0_0 -> search56_0 in the cache */

/* search446_0_1 -> search416_1 in the cache */
static const nir_search_expression search446_0 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search56_0.value, &search416_1.value },
   NULL,
};

/* search446_1 -> replace416_1 in the cache */
static const nir_search_expression search446 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search446_0.value, &replace416_1.value },
   NULL,
};

   /* replace446_0 -> search56_0 in the cache */

/* replace446_1 -> search423_1 in the cache */
static const nir_search_expression replace446 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search56_0.value, &search423_1.value },
   NULL,
};

   /* search447_0_0 -> search0_0 in the cache */

/* search447_0_1 -> search416_1 in the cache */
static const nir_search_expression search447_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search0_0.value, &search416_1.value },
   NULL,
};

/* search447_1 -> replace417_1 in the cache */
static const nir_search_expression search447 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search447_0.value, &replace417_1.value },
   NULL,
};

   /* replace447_0 -> search0_0 in the cache */

/* replace447_1 -> replace425_1 in the cache */
/* replace447 -> replace425 in the cache */

   /* search448_0_0 -> search0_0 in the cache */

/* search448_0_1 -> search339_1_1 in the cache */
static const nir_search_expression search448_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search0_0.value, &search339_1_1.value },
   NULL,
};

/* search448_1 -> replace417_1 in the cache */
static const nir_search_expression search448 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search448_0.value, &replace417_1.value },
   NULL,
};

   /* replace448_0 -> search0_0 in the cache */

/* replace448_1 -> replace424_1 in the cache */
/* replace448 -> replace424 in the cache */

   /* search449_0_0 -> search0_0 in the cache */

/* search449_0_1 -> search338_1_1 in the cache */
static const nir_search_expression search449_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search0_0.value, &search338_1_1.value },
   NULL,
};

/* search449_1 -> replace417_1 in the cache */
static const nir_search_expression search449 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search449_0.value, &replace417_1.value },
   NULL,
};

   /* replace449_0 -> search0_0 in the cache */

/* replace449_1 -> search25_1 in the cache */
static const nir_search_expression replace449 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search0_0.value, &search25_1.value },
   NULL,
};

   /* search450_0_0 -> search58_0 in the cache */

/* search450_0_1 -> search416_1 in the cache */
static const nir_search_expression search450_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search58_0.value, &search416_1.value },
   NULL,
};

/* search450_1 -> replace418_1 in the cache */
static const nir_search_expression search450 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search450_0.value, &replace418_1.value },
   NULL,
};

   /* replace450_0 -> search58_0 in the cache */

/* replace450_1 -> replace432_1 in the cache */
/* replace450 -> replace432 in the cache */

   /* search451_0_0 -> search58_0 in the cache */

/* search451_0_1 -> search339_1_1 in the cache */
static const nir_search_expression search451_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search58_0.value, &search339_1_1.value },
   NULL,
};

/* search451_1 -> replace418_1 in the cache */
static const nir_search_expression search451 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search451_0.value, &replace418_1.value },
   NULL,
};

   /* replace451_0 -> search58_0 in the cache */

/* replace451_1 -> replace431_1 in the cache */
/* replace451 -> replace431 in the cache */

   /* search452_0_0 -> search58_0 in the cache */

/* search452_0_1 -> search338_1_1 in the cache */
static const nir_search_expression search452_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search58_0.value, &search338_1_1.value },
   NULL,
};

/* search452_1 -> replace418_1 in the cache */
static const nir_search_expression search452 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search452_0.value, &replace418_1.value },
   NULL,
};

   /* replace452_0 -> search58_0 in the cache */

/* replace452_1 -> replace430_1 in the cache */
/* replace452 -> replace430 in the cache */

   /* search453_0_0 -> search58_0 in the cache */

/* search453_0_1 -> search430_0_1 in the cache */
static const nir_search_expression search453_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search58_0.value, &search430_0_1.value },
   NULL,
};

/* search453_1 -> replace418_1 in the cache */
static const nir_search_expression search453 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search453_0.value, &replace418_1.value },
   NULL,
};

   /* replace453_0 -> search58_0 in the cache */

/* replace453_1 -> replace429_1 in the cache */
/* replace453 -> replace429 in the cache */

   /* search454_0_0 -> search58_0 in the cache */

/* search454_0_1 -> search431_0_1 in the cache */
static const nir_search_expression search454_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search58_0.value, &search431_0_1.value },
   NULL,
};

/* search454_1 -> replace418_1 in the cache */
static const nir_search_expression search454 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search454_0.value, &replace418_1.value },
   NULL,
};

   /* replace454_0 -> search58_0 in the cache */

/* replace454_1 -> replace428_1 in the cache */
/* replace454 -> replace428 in the cache */

   /* search455_0_0 -> search58_0 in the cache */

/* search455_0_1 -> search432_0_1 in the cache */
static const nir_search_expression search455_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search58_0.value, &search432_0_1.value },
   NULL,
};

/* search455_1 -> replace418_1 in the cache */
static const nir_search_expression search455 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search455_0.value, &replace418_1.value },
   NULL,
};

   /* replace455_0 -> search58_0 in the cache */

/* replace455_1 -> replace427_1 in the cache */
/* replace455 -> replace427 in the cache */

   /* search456_0_0 -> search58_0 in the cache */

/* search456_0_1 -> search418_1 in the cache */
static const nir_search_expression search456_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search58_0.value, &search418_1.value },
   NULL,
};

/* search456_1 -> replace418_1 in the cache */
static const nir_search_expression search456 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search456_0.value, &replace418_1.value },
   NULL,
};

   /* replace456_0 -> search58_0 in the cache */

/* replace456_1 -> search427_1 in the cache */
static const nir_search_expression replace456 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search58_0.value, &search427_1.value },
   NULL,
};

   /* search457_0_0 -> search56_0 in the cache */

/* search457_0_1 -> search416_1 in the cache */
/* search457_0 -> search446_0 in the cache */

/* search457_1 -> replace416_1 in the cache */
static const nir_search_expression search457 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search446_0.value, &replace416_1.value },
   NULL,
};

   /* replace457_0 -> search56_0 in the cache */

/* replace457_1 -> search423_1 in the cache */
static const nir_search_expression replace457 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search56_0.value, &search423_1.value },
   NULL,
};

   /* search458_0_0 -> search0_0 in the cache */

/* search458_0_1 -> search416_1 in the cache */
/* search458_0 -> search447_0 in the cache */

/* search458_1 -> replace417_1 in the cache */
static const nir_search_expression search458 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search447_0.value, &replace417_1.value },
   NULL,
};

   /* replace458_0 -> search0_0 in the cache */

/* replace458_1 -> replace425_1 in the cache */
static const nir_search_expression replace458 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search0_0.value, &replace425_1.value },
   NULL,
};

   /* search459_0_0 -> search0_0 in the cache */

/* search459_0_1 -> search339_1_1 in the cache */
/* search459_0 -> search448_0 in the cache */

/* search459_1 -> replace417_1 in the cache */
static const nir_search_expression search459 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search448_0.value, &replace417_1.value },
   NULL,
};

   /* replace459_0 -> search0_0 in the cache */

/* replace459_1 -> replace424_1 in the cache */
static const nir_search_expression replace459 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search0_0.value, &replace424_1.value },
   NULL,
};

   /* search460_0_0 -> search0_0 in the cache */

/* search460_0_1 -> search338_1_1 in the cache */
/* search460_0 -> search449_0 in the cache */

/* search460_1 -> replace417_1 in the cache */
static const nir_search_expression search460 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search449_0.value, &replace417_1.value },
   NULL,
};

   /* replace460_0 -> search0_0 in the cache */

/* replace460_1 -> search25_1 in the cache */
static const nir_search_expression replace460 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search0_0.value, &search25_1.value },
   NULL,
};

   /* search461_0_0 -> search58_0 in the cache */

/* search461_0_1 -> search416_1 in the cache */
/* search461_0 -> search450_0 in the cache */

/* search461_1 -> replace418_1 in the cache */
static const nir_search_expression search461 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search450_0.value, &replace418_1.value },
   NULL,
};

   /* replace461_0 -> search58_0 in the cache */

/* replace461_1 -> replace432_1 in the cache */
static const nir_search_expression replace461 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search58_0.value, &replace432_1.value },
   NULL,
};

   /* search462_0_0 -> search58_0 in the cache */

/* search462_0_1 -> search339_1_1 in the cache */
/* search462_0 -> search451_0 in the cache */

/* search462_1 -> replace418_1 in the cache */
static const nir_search_expression search462 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search451_0.value, &replace418_1.value },
   NULL,
};

   /* replace462_0 -> search58_0 in the cache */

/* replace462_1 -> replace431_1 in the cache */
static const nir_search_expression replace462 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search58_0.value, &replace431_1.value },
   NULL,
};

   /* search463_0_0 -> search58_0 in the cache */

/* search463_0_1 -> search338_1_1 in the cache */
/* search463_0 -> search452_0 in the cache */

/* search463_1 -> replace418_1 in the cache */
static const nir_search_expression search463 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search452_0.value, &replace418_1.value },
   NULL,
};

   /* replace463_0 -> search58_0 in the cache */

/* replace463_1 -> replace430_1 in the cache */
static const nir_search_expression replace463 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search58_0.value, &replace430_1.value },
   NULL,
};

   /* search464_0_0 -> search58_0 in the cache */

/* search464_0_1 -> search430_0_1 in the cache */
/* search464_0 -> search453_0 in the cache */

/* search464_1 -> replace418_1 in the cache */
static const nir_search_expression search464 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search453_0.value, &replace418_1.value },
   NULL,
};

   /* replace464_0 -> search58_0 in the cache */

/* replace464_1 -> replace429_1 in the cache */
static const nir_search_expression replace464 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search58_0.value, &replace429_1.value },
   NULL,
};

   /* search465_0_0 -> search58_0 in the cache */

/* search465_0_1 -> search431_0_1 in the cache */
/* search465_0 -> search454_0 in the cache */

/* search465_1 -> replace418_1 in the cache */
static const nir_search_expression search465 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search454_0.value, &replace418_1.value },
   NULL,
};

   /* replace465_0 -> search58_0 in the cache */

/* replace465_1 -> replace428_1 in the cache */
static const nir_search_expression replace465 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search58_0.value, &replace428_1.value },
   NULL,
};

   /* search466_0_0 -> search58_0 in the cache */

/* search466_0_1 -> search432_0_1 in the cache */
/* search466_0 -> search455_0 in the cache */

/* search466_1 -> replace418_1 in the cache */
static const nir_search_expression search466 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search455_0.value, &replace418_1.value },
   NULL,
};

   /* replace466_0 -> search58_0 in the cache */

/* replace466_1 -> replace427_1 in the cache */
static const nir_search_expression replace466 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search58_0.value, &replace427_1.value },
   NULL,
};

   /* search467_0_0 -> search58_0 in the cache */

/* search467_0_1 -> search418_1 in the cache */
/* search467_0 -> search456_0 in the cache */

/* search467_1 -> replace418_1 in the cache */
static const nir_search_expression search467 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search456_0.value, &replace418_1.value },
   NULL,
};

   /* replace467_0 -> search58_0 in the cache */

/* replace467_1 -> search427_1 in the cache */
static const nir_search_expression replace467 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search58_0.value, &search427_1.value },
   NULL,
};

   /* search468_0_0 -> search0_0 in the cache */

/* search468_0_1 -> search339_1_1 in the cache */
/* search468_0 -> search448_0 in the cache */

/* search468_1 -> search339_1_1 in the cache */
static const nir_search_expression search468 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search448_0.value, &search339_1_1.value },
   NULL,
};

   /* replace468_0 -> search0_0 in the cache */

/* replace468_1 -> search25_1 in the cache */
static const nir_search_expression replace468 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u16,
   { &search0_0.value, &search25_1.value },
   NULL,
};

   /* search469_0 -> search0_0 in the cache */

/* search469_1 -> search339_1_1 in the cache */
/* search469 -> search339_1 in the cache */

   /* replace469_0 -> search0_0 in the cache */

/* replace469_1 -> replace424_1 in the cache */
static const nir_search_expression replace469 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u16,
   { &search0_0.value, &replace424_1.value },
   NULL,
};

   /* search470_0_0 -> search0_0 in the cache */

/* search470_0_1 -> search339_1_1 in the cache */
/* search470_0 -> search448_0 in the cache */

/* search470_1 -> search339_1_1 in the cache */
static const nir_search_expression search470 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishr,
   { &search448_0.value, &search339_1_1.value },
   NULL,
};

   /* replace470_0 -> search0_0 in the cache */

/* replace470_1 -> search25_1 in the cache */
static const nir_search_expression replace470 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i16,
   { &search0_0.value, &search25_1.value },
   NULL,
};

   /* search471_0 -> search0_0 in the cache */

/* search471_1 -> search339_1_1 in the cache */
/* search471 -> search436_0 in the cache */

   /* replace471_0 -> search0_0 in the cache */

/* replace471_1 -> replace424_1 in the cache */
static const nir_search_expression replace471 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i16,
   { &search0_0.value, &replace424_1.value },
   NULL,
};

   static const nir_search_constant search472_0 = {
   { nir_search_value_constant, -1 },
   nir_type_int, { 0xffff /* 65535 */ },
};

/* search472_1 -> search6_0 in the cache */
static const nir_search_expression search472 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_iand,
   { &search472_0.value, &search6_0.value },
   NULL,
};

   /* replace472_0 -> search6_0 in the cache */

/* replace472_1 -> replace8 in the cache */
static const nir_search_expression replace472 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_extract_u16,
   { &search6_0.value, &replace8.value },
   NULL,
};

   /* search473_0 -> search13_0 in the cache */

/* search473_1_0 -> search45_0 in the cache */

/* search473_1_1 -> replace13_1_0 in the cache */
static const nir_search_expression search473_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fsub,
   { &search45_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search473 = {
   { nir_search_value_expression, -2 },
   true,
   -1, 0,
   nir_op_fsub,
   { &search13_0.value, &search473_1.value },
   NULL,
};

   /* replace473_0 -> search13_0 in the cache */

/* replace473_1 -> replace13_1_0 in the cache */
/* replace473 -> replace48 in the cache */

   /* search474_0 -> search13_0 in the cache */

/* search474_1_0 -> replace124_1 in the cache */

/* search474_1_1 -> replace13_1_0 in the cache */
static const nir_search_expression search474_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_isub,
   { &replace124_1.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search474 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_isub,
   { &search13_0.value, &search474_1.value },
   NULL,
};

   /* replace474_0 -> search13_0 in the cache */

/* replace474_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace474 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_iadd,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* search475_0 -> search0_0 in the cache */

/* search475_1 -> search25_1 in the cache */
static const nir_search_expression search475 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ussub_4x8,
   { &search0_0.value, &search25_1.value },
   NULL,
};

   /* replace475 -> search0_0 in the cache */

   /* search476_0 -> search0_0 in the cache */

/* search476_1 -> search26_1 in the cache */
static const nir_search_expression search476 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ussub_4x8,
   { &search0_0.value, &search26_1.value },
   NULL,
};

   /* replace476 -> search25_1 in the cache */

   /* search477_0 -> search13_0 in the cache */

/* search477_1 -> replace13_1_0 in the cache */
static const nir_search_expression search477 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_fsub,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace477_0 -> search13_0 in the cache */

/* replace477_1_0 -> replace13_1_0 in the cache */
/* replace477_1 -> search153_0_1 in the cache */
static const nir_search_expression replace477 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_fadd,
   { &search13_0.value, &search153_0_1.value },
   NULL,
};

   /* search478_0 -> search13_0 in the cache */

/* search478_1 -> replace13_1_0 in the cache */
static const nir_search_expression search478 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_isub,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace478_0 -> search13_0 in the cache */

/* replace478_1_0 -> replace13_1_0 in the cache */
static const nir_search_expression replace478_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_ineg,
   { &replace13_1_0.value },
   NULL,
};
static const nir_search_expression replace478 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_iadd,
   { &search13_0.value, &replace478_1.value },
   NULL,
};

   /* search479_0 -> search6_0 in the cache */
/* search479 -> search14_0 in the cache */

   /* replace479_0 -> search23_1 in the cache */

/* replace479_1 -> search6_0 in the cache */
static const nir_search_expression replace479 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fsub,
   { &search23_1.value, &search6_0.value },
   NULL,
};

   /* search480_0 -> search6_0 in the cache */
/* search480 -> search15_0 in the cache */

   /* replace480_0 -> replace8 in the cache */

/* replace480_1 -> search6_0 in the cache */
static const nir_search_expression replace480 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_isub,
   { &replace8.value, &search6_0.value },
   NULL,
};

   /* search481_0 -> search13_0 in the cache */

/* search481_1_0 -> search45_0 in the cache */

/* search481_1_1 -> replace13_1_0 in the cache */
/* search481_1 -> search473_1 in the cache */
static const nir_search_expression search481 = {
   { nir_search_value_expression, -2 },
   true,
   0, 1,
   nir_op_fadd,
   { &search13_0.value, &search473_1.value },
   NULL,
};

   /* replace481_0 -> search13_0 in the cache */

/* replace481_1 -> replace13_1_0 in the cache */
/* replace481 -> search477 in the cache */

   /* search482_0 -> search13_0 in the cache */

/* search482_1_0 -> replace124_1 in the cache */

/* search482_1_1 -> replace13_1_0 in the cache */
/* search482_1 -> search474_1 in the cache */
static const nir_search_expression search482 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_iadd,
   { &search13_0.value, &search474_1.value },
   NULL,
};

   /* replace482_0 -> search13_0 in the cache */

/* replace482_1 -> replace13_1_0 in the cache */
/* replace482 -> search478 in the cache */

   /* search483_0_0 -> search23_1 in the cache */

/* search483_0_1 -> search6_0 in the cache */
/* search483_0 -> replace479 in the cache */
static const nir_search_expression search483 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fabs,
   { &replace479.value },
   NULL,
};

   /* replace483_0 -> search6_0 in the cache */
/* replace483 -> search16_0 in the cache */

   /* search484_0_0 -> replace8 in the cache */

/* search484_0_1 -> search6_0 in the cache */
/* search484_0 -> replace480 in the cache */
static const nir_search_expression search484 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_iabs,
   { &replace480.value },
   NULL,
};

   /* replace484_0 -> search6_0 in the cache */
/* replace484 -> search19_0 in the cache */

   /* search485_0_0 -> search13_0 in the cache */
/* search485_0 -> search33_0 in the cache */

/* search485_1 -> replace13_1_0 in the cache */
static const nir_search_expression search485 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_fmul,
   { &search33_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace485_0_0 -> search13_0 in the cache */

/* replace485_0_1 -> replace13_1_0 in the cache */
/* replace485_0 -> replace47 in the cache */
static const nir_search_expression replace485 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 1,
   nir_op_fneg,
   { &replace47.value },
   NULL,
};

   /* search486_0_0 -> search13_0 in the cache */
/* search486_0 -> search31_0 in the cache */

/* search486_1 -> replace13_1_0 in the cache */
static const nir_search_expression search486 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_imul,
   { &search31_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace486_0_0 -> search13_0 in the cache */

/* replace486_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace486_0 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_imul,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression replace486 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 1,
   nir_op_ineg,
   { &replace486_0.value },
   NULL,
};

   static const nir_search_variable search487_0_0 = {
   { nir_search_value_variable, -3 },
   0, /* a */
   false,
   nir_type_invalid,
   (is_not_const),
};

static const nir_search_variable search487_0_1 = {
   { nir_search_value_variable, -3 },
   1, /* b */
   false,
   nir_type_invalid,
   (is_not_const),
};
static const nir_search_expression search487_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_fmul,
   { &search487_0_0.value, &search487_0_1.value },
   (is_used_once),
};

/* search487_1 -> search79_0_1 in the cache */
static const nir_search_expression search487 = {
   { nir_search_value_expression, -3 },
   true,
   0, 2,
   nir_op_fmul,
   { &search487_0.value, &search79_0_1.value },
   (is_used_once),
};

   /* replace487_0_0 -> search27_0_0 in the cache */

/* replace487_0_1 -> search27_1_1 in the cache */
static const nir_search_expression replace487_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_fmul,
   { &search27_0_0.value, &search27_1_1.value },
   NULL,
};

/* replace487_1 -> search27_0_1 in the cache */
static const nir_search_expression replace487 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_fmul,
   { &replace487_0.value, &search27_0_1.value },
   NULL,
};

   /* search488_0_0 -> search487_0_0 in the cache */

/* search488_0_1 -> search487_0_1 in the cache */
static const nir_search_expression search488_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_imul,
   { &search487_0_0.value, &search487_0_1.value },
   (is_used_once),
};

/* search488_1 -> search79_0_1 in the cache */
static const nir_search_expression search488 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_imul,
   { &search488_0.value, &search79_0_1.value },
   (is_used_once),
};

   /* replace488_0_0 -> search27_0_0 in the cache */

/* replace488_0_1 -> search27_1_1 in the cache */
static const nir_search_expression replace488_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_imul,
   { &search27_0_0.value, &search27_1_1.value },
   NULL,
};

/* replace488_1 -> search27_0_1 in the cache */
static const nir_search_expression replace488 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_imul,
   { &replace488_0.value, &search27_0_1.value },
   NULL,
};

   /* search489_0_0 -> search487_0_0 in the cache */

/* search489_0_1 -> search487_0_1 in the cache */
static const nir_search_expression search489_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_fadd,
   { &search487_0_0.value, &search487_0_1.value },
   (is_used_once),
};

/* search489_1 -> search79_0_1 in the cache */
static const nir_search_expression search489 = {
   { nir_search_value_expression, -3 },
   true,
   0, 2,
   nir_op_fadd,
   { &search489_0.value, &search79_0_1.value },
   (is_used_once),
};

   /* replace489_0_0 -> search27_0_0 in the cache */

/* replace489_0_1 -> search27_1_1 in the cache */
static const nir_search_expression replace489_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_fadd,
   { &search27_0_0.value, &search27_1_1.value },
   NULL,
};

/* replace489_1 -> search27_0_1 in the cache */
static const nir_search_expression replace489 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_fadd,
   { &replace489_0.value, &search27_0_1.value },
   NULL,
};

   /* search490_0_0 -> search487_0_0 in the cache */

/* search490_0_1 -> search487_0_1 in the cache */
static const nir_search_expression search490_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_iadd,
   { &search487_0_0.value, &search487_0_1.value },
   (is_used_once),
};

/* search490_1 -> search79_0_1 in the cache */
static const nir_search_expression search490 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_iadd,
   { &search490_0.value, &search79_0_1.value },
   (is_used_once),
};

   /* replace490_0_0 -> search27_0_0 in the cache */

/* replace490_0_1 -> search27_1_1 in the cache */
static const nir_search_expression replace490_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_iadd,
   { &search27_0_0.value, &search27_1_1.value },
   NULL,
};

/* replace490_1 -> search27_0_1 in the cache */
static const nir_search_expression replace490 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_iadd,
   { &replace490_0.value, &search27_0_1.value },
   NULL,
};

   /* search491_0 -> search274_0 in the cache */

/* search491_1_0 -> search487_0_1 in the cache */

/* search491_1_1 -> search79_0_1 in the cache */
static const nir_search_expression search491_1 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_fmul,
   { &search487_0_1.value, &search79_0_1.value },
   NULL,
};
static const nir_search_expression search491 = {
   { nir_search_value_expression, -3 },
   true,
   0, 2,
   nir_op_fmul,
   { &search274_0.value, &search491_1.value },
   NULL,
};

   /* replace491_0_0 -> search27_0_0 in the cache */

/* replace491_0_1 -> search27_1_1 in the cache */
/* replace491_0 -> replace487_0 in the cache */

/* replace491_1 -> search27_0_1 in the cache */
/* replace491 -> replace487 in the cache */

   /* search492_0 -> search274_0 in the cache */

/* search492_1_0 -> search487_0_1 in the cache */

/* search492_1_1 -> search79_0_1 in the cache */
static const nir_search_expression search492_1 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_imul,
   { &search487_0_1.value, &search79_0_1.value },
   NULL,
};
static const nir_search_expression search492 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_imul,
   { &search274_0.value, &search492_1.value },
   NULL,
};

   /* replace492_0_0 -> search27_0_0 in the cache */

/* replace492_0_1 -> search27_1_1 in the cache */
/* replace492_0 -> replace488_0 in the cache */

/* replace492_1 -> search27_0_1 in the cache */
/* replace492 -> replace488 in the cache */

   /* search493_0 -> search274_0 in the cache */

/* search493_1_0 -> search487_0_1 in the cache */

/* search493_1_1 -> search79_0_1 in the cache */
static const nir_search_expression search493_1 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_fadd,
   { &search487_0_1.value, &search79_0_1.value },
   NULL,
};
static const nir_search_expression search493 = {
   { nir_search_value_expression, -3 },
   true,
   0, 2,
   nir_op_fadd,
   { &search274_0.value, &search493_1.value },
   NULL,
};

   /* replace493_0_0 -> search27_0_0 in the cache */

/* replace493_0_1 -> search27_1_1 in the cache */
/* replace493_0 -> replace489_0 in the cache */

/* replace493_1 -> search27_0_1 in the cache */
/* replace493 -> replace489 in the cache */

   /* search494_0 -> search274_0 in the cache */

/* search494_1_0_0 -> search487_0_1 in the cache */

/* search494_1_0_1 -> search79_0_1 in the cache */
/* search494_1_0 -> search493_1 in the cache */
static const nir_search_expression search494_1 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 1,
   nir_op_fneg,
   { &search493_1.value },
   NULL,
};
static const nir_search_expression search494 = {
   { nir_search_value_expression, -3 },
   true,
   0, 2,
   nir_op_fadd,
   { &search274_0.value, &search494_1.value },
   NULL,
};

   /* replace494_0_0 -> search27_0_0 in the cache */

/* replace494_0_1_0 -> search27_1_1 in the cache */
static const nir_search_expression replace494_0_1 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search27_1_1.value },
   NULL,
};
static const nir_search_expression replace494_0 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_fadd,
   { &search27_0_0.value, &replace494_0_1.value },
   NULL,
};

/* replace494_1_0 -> search27_0_1 in the cache */
static const nir_search_expression replace494_1 = {
   { nir_search_value_expression, -3 },
   false,
   -1, 0,
   nir_op_fneg,
   { &search27_0_1.value },
   NULL,
};
static const nir_search_expression replace494 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_fadd,
   { &replace494_0.value, &replace494_1.value },
   NULL,
};

   /* search495_0 -> search274_0 in the cache */

/* search495_1_0 -> search487_0_1 in the cache */

/* search495_1_1 -> search79_0_1 in the cache */
static const nir_search_expression search495_1 = {
   { nir_search_value_expression, -3 },
   false,
   1, 1,
   nir_op_iadd,
   { &search487_0_1.value, &search79_0_1.value },
   NULL,
};
static const nir_search_expression search495 = {
   { nir_search_value_expression, -3 },
   false,
   0, 2,
   nir_op_iadd,
   { &search274_0.value, &search495_1.value },
   NULL,
};

   /* replace495_0_0 -> search27_0_0 in the cache */

/* replace495_0_1 -> search27_1_1 in the cache */
/* replace495_0 -> replace490_0 in the cache */

/* replace495_1 -> search27_0_1 in the cache */
/* replace495 -> replace490 in the cache */

   /* search496_0_0_0 -> search6_0 in the cache */
static const nir_search_expression search496_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_find_lsb,
   { &search6_0.value },
   NULL,
};

/* search496_0_1 -> search25_1 in the cache */
static const nir_search_expression search496_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search496_0_0.value, &search25_1.value },
   NULL,
};

/* search496_1_0 -> search6_0 in the cache */
/* search496_1 -> search496_0_0 in the cache */

/* search496_2 -> search26_1 in the cache */
static const nir_search_expression search496 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search496_0.value, &search496_0_0.value, &search26_1.value },
   NULL,
};

   /* replace496_0 -> search6_0 in the cache */
/* replace496 -> search496_0_0 in the cache */

   /* search497_0_0_0 -> search0_0 in the cache */
static const nir_search_expression search497_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ifind_msb,
   { &search0_0.value },
   NULL,
};

/* search497_0_1 -> search25_1 in the cache */
static const nir_search_expression search497_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search497_0_0.value, &search25_1.value },
   NULL,
};

/* search497_1_0 -> search0_0 in the cache */
/* search497_1 -> search497_0_0 in the cache */

/* search497_2 -> search26_1 in the cache */
static const nir_search_expression search497 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search497_0.value, &search497_0_0.value, &search26_1.value },
   NULL,
};

   /* replace497_0 -> search0_0 in the cache */
/* replace497 -> search497_0_0 in the cache */

   /* search498_0_0_0 -> search6_0 in the cache */
static const nir_search_expression search498_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ufind_msb,
   { &search6_0.value },
   NULL,
};

/* search498_0_1 -> search25_1 in the cache */
static const nir_search_expression search498_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search498_0_0.value, &search25_1.value },
   NULL,
};

/* search498_1_0 -> search6_0 in the cache */
/* search498_1 -> search498_0_0 in the cache */

/* search498_2 -> search26_1 in the cache */
static const nir_search_expression search498 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search498_0.value, &search498_0_0.value, &search26_1.value },
   NULL,
};

   /* replace498_0 -> search6_0 in the cache */
/* replace498 -> search498_0_0 in the cache */

   /* search499_0_0 -> search6_0 in the cache */

/* search499_0_1 -> replace8 in the cache */
/* search499_0 -> replace132 in the cache */

/* search499_1_0 -> search6_0 in the cache */
/* search499_1 -> search496_0_0 in the cache */

/* search499_2 -> search26_1 in the cache */
static const nir_search_expression search499 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_bcsel,
   { &replace132.value, &search496_0_0.value, &search26_1.value },
   NULL,
};

   /* replace499_0 -> search6_0 in the cache */
/* replace499 -> search496_0_0 in the cache */

   /* search500_0_0 -> search0_0 in the cache */

/* search500_0_1 -> search25_1 in the cache */
static const nir_search_expression search500_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &search0_0.value, &search25_1.value },
   NULL,
};

/* search500_1_0 -> search0_0 in the cache */
/* search500_1 -> search497_0_0 in the cache */

/* search500_2 -> search26_1 in the cache */
static const nir_search_expression search500 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_bcsel,
   { &search500_0.value, &search497_0_0.value, &search26_1.value },
   NULL,
};

   /* replace500_0 -> search0_0 in the cache */
/* replace500 -> search497_0_0 in the cache */

   /* search501_0_0 -> search6_0 in the cache */

/* search501_0_1 -> replace8 in the cache */
/* search501_0 -> replace132 in the cache */

/* search501_1_0 -> search6_0 in the cache */
/* search501_1 -> search498_0_0 in the cache */

/* search501_2 -> search26_1 in the cache */
static const nir_search_expression search501 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_bcsel,
   { &replace132.value, &search498_0_0.value, &search26_1.value },
   NULL,
};

   /* replace501_0 -> search6_0 in the cache */
/* replace501 -> search498_0_0 in the cache */

   /* search502_0_0 -> search0_0 in the cache */

/* search502_0_1 -> search26_1 in the cache */
static const nir_search_expression search502_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &search0_0.value, &search26_1.value },
   NULL,
};

/* search502_1_0 -> search0_0 in the cache */
/* search502_1 -> search497_0_0 in the cache */

/* search502_2 -> search26_1 in the cache */
static const nir_search_expression search502 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_bcsel,
   { &search502_0.value, &search497_0_0.value, &search26_1.value },
   NULL,
};

   /* replace502_0 -> search0_0 in the cache */
/* replace502 -> search497_0_0 in the cache */

   /* search503_0 -> search56_0 in the cache */

/* search503_1 -> search56_1 in the cache */
static const nir_search_expression search503 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_fmod,
   { &search56_0.value, &search56_1.value },
   NULL,
};

   /* replace503_0 -> search56_0 in the cache */

/* replace503_1_0 -> search56_1 in the cache */

/* replace503_1_1_0_0 -> search56_0 in the cache */

/* replace503_1_1_0_1 -> search56_1 in the cache */
static const nir_search_expression replace503_1_1_0 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_fdiv,
   { &search56_0.value, &search56_1.value },
   NULL,
};
static const nir_search_expression replace503_1_1 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_ffloor,
   { &replace503_1_1_0.value },
   NULL,
};
static const nir_search_expression replace503_1 = {
   { nir_search_value_expression, 16 },
   false,
   0, 1,
   nir_op_fmul,
   { &search56_1.value, &replace503_1_1.value },
   NULL,
};
static const nir_search_expression replace503 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 1,
   nir_op_fsub,
   { &search56_0.value, &replace503_1.value },
   NULL,
};

   /* search504_0 -> search0_0 in the cache */

/* search504_1 -> replace0_1_0 in the cache */
static const nir_search_expression search504 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fmod,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* replace504_0 -> search0_0 in the cache */

/* replace504_1_0 -> replace0_1_0 in the cache */

/* replace504_1_1_0_0 -> search0_0 in the cache */

/* replace504_1_1_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace504_1_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fdiv,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace504_1_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ffloor,
   { &replace504_1_1_0.value },
   NULL,
};
static const nir_search_expression replace504_1 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_fmul,
   { &replace0_1_0.value, &replace504_1_1.value },
   NULL,
};
static const nir_search_expression replace504 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_fsub,
   { &search0_0.value, &replace504_1.value },
   NULL,
};

   /* search505_0 -> search58_0 in the cache */

/* search505_1 -> search58_1 in the cache */
static const nir_search_expression search505 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_fmod,
   { &search58_0.value, &search58_1.value },
   NULL,
};

   /* replace505_0 -> search58_0 in the cache */

/* replace505_1_0 -> search58_1 in the cache */

/* replace505_1_1_0_0 -> search58_0 in the cache */

/* replace505_1_1_0_1 -> search58_1 in the cache */
static const nir_search_expression replace505_1_1_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_fdiv,
   { &search58_0.value, &search58_1.value },
   NULL,
};
static const nir_search_expression replace505_1_1 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ffloor,
   { &replace505_1_1_0.value },
   NULL,
};
static const nir_search_expression replace505_1 = {
   { nir_search_value_expression, 64 },
   false,
   0, 1,
   nir_op_fmul,
   { &search58_1.value, &replace505_1_1.value },
   NULL,
};
static const nir_search_expression replace505 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 1,
   nir_op_fsub,
   { &search58_0.value, &replace505_1.value },
   NULL,
};

   /* search506_0 -> search13_0 in the cache */

/* search506_1 -> replace13_1_0 in the cache */
static const nir_search_expression search506 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_frem,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace506_0 -> search13_0 in the cache */

/* replace506_1_0 -> replace13_1_0 in the cache */

/* replace506_1_1_0_0 -> search13_0 in the cache */

/* replace506_1_1_0_1 -> replace13_1_0 in the cache */
/* replace506_1_1_0 -> search362 in the cache */
static const nir_search_expression replace506_1_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_ftrunc,
   { &search362.value },
   NULL,
};
static const nir_search_expression replace506_1 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_fmul,
   { &replace13_1_0.value, &replace506_1_1.value },
   NULL,
};
static const nir_search_expression replace506 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 1,
   nir_op_fsub,
   { &search13_0.value, &replace506_1.value },
   NULL,
};

   /* search507_0 -> search0_0 in the cache */

/* search507_1 -> replace0_1_0 in the cache */
static const nir_search_expression search507 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_uadd_carry,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* replace507_0_0_0 -> search0_0 in the cache */

/* replace507_0_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace507_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_iadd,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

/* replace507_0_1 -> search0_0 in the cache */
static const nir_search_expression replace507_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &replace507_0_0.value, &search0_0.value },
   NULL,
};
static const nir_search_expression replace507 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_search_op_b2i,
   { &replace507_0.value },
   NULL,
};

   /* search508_0 -> search0_0 in the cache */

/* search508_1 -> replace0_1_0 in the cache */
static const nir_search_expression search508 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_usub_borrow,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* replace508_0_0 -> search0_0 in the cache */

/* replace508_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace508_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace508 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_search_op_b2i,
   { &replace508_0.value },
   NULL,
};

   static const nir_search_variable search509_0 = {
   { nir_search_value_variable, 32 },
   0, /* base */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search509_1 = {
   { nir_search_value_variable, 32 },
   1, /* insert */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search509_2 = {
   { nir_search_value_variable, 32 },
   2, /* offset */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search509_3 = {
   { nir_search_value_variable, 32 },
   3, /* bits */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search509 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bitfield_insert,
   { &search509_0.value, &search509_1.value, &search509_2.value, &search509_3.value },
   NULL,
};

   /* replace509_0_0 -> search394_1_0 in the cache */

/* replace509_0_1 -> search509_3 in the cache */
static const nir_search_expression replace509_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search394_1_0.value, &search509_3.value },
   NULL,
};

/* replace509_1 -> search509_1 in the cache */

/* replace509_2_0_0 -> search509_3 in the cache */

/* replace509_2_0_1 -> search509_2 in the cache */
static const nir_search_expression replace509_2_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bfm,
   { &search509_3.value, &search509_2.value },
   NULL,
};

/* replace509_2_1 -> search509_1 in the cache */

/* replace509_2_2 -> search509_0 in the cache */
static const nir_search_expression replace509_2 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bfi,
   { &replace509_2_0.value, &search509_1.value, &search509_0.value },
   NULL,
};
static const nir_search_expression replace509 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace509_0.value, &search509_1.value, &replace509_2.value },
   NULL,
};

   /* search510_0 -> search13_0 in the cache */

/* search510_1 -> replace13_1_0 in the cache */
static const nir_search_expression search510 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_ihadd,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace510_0_0 -> search13_0 in the cache */

/* replace510_0_1 -> replace13_1_0 in the cache */
/* replace510_0 -> search326_0 in the cache */

/* replace510_1_0_0 -> search13_0 in the cache */

/* replace510_1_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace510_1_0 = {
   { nir_search_value_expression, -2 },
   false,
   2, 1,
   nir_op_ixor,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

/* replace510_1_1 -> replace424_1 in the cache */
static const nir_search_expression replace510_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 1,
   nir_op_ishr,
   { &replace510_1_0.value, &replace424_1.value },
   NULL,
};
static const nir_search_expression replace510 = {
   { nir_search_value_expression, -2 },
   false,
   0, 3,
   nir_op_iadd,
   { &search326_0.value, &replace510_1.value },
   NULL,
};

   /* search511_0 -> search13_0 in the cache */

/* search511_1 -> replace13_1_0 in the cache */
static const nir_search_expression search511 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_uhadd,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace511_0_0 -> search13_0 in the cache */

/* replace511_0_1 -> replace13_1_0 in the cache */
/* replace511_0 -> search326_0 in the cache */

/* replace511_1_0_0 -> search13_0 in the cache */

/* replace511_1_0_1 -> replace13_1_0 in the cache */
/* replace511_1_0 -> replace510_1_0 in the cache */

/* replace511_1_1 -> replace424_1 in the cache */
static const nir_search_expression replace511_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 1,
   nir_op_ushr,
   { &replace510_1_0.value, &replace424_1.value },
   NULL,
};
static const nir_search_expression replace511 = {
   { nir_search_value_expression, -2 },
   false,
   0, 3,
   nir_op_iadd,
   { &search326_0.value, &replace511_1.value },
   NULL,
};

   /* search512_0 -> search13_0 in the cache */

/* search512_1 -> replace13_1_0 in the cache */
static const nir_search_expression search512 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_irhadd,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace512_0_0 -> search13_0 in the cache */

/* replace512_0_1 -> replace13_1_0 in the cache */
/* replace512_0 -> replace327 in the cache */

/* replace512_1_0_0 -> search13_0 in the cache */

/* replace512_1_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace512_1_0 = {
   { nir_search_value_expression, -2 },
   false,
   1, 1,
   nir_op_ixor,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

/* replace512_1_1 -> replace424_1 in the cache */
static const nir_search_expression replace512_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 1,
   nir_op_ishr,
   { &replace512_1_0.value, &replace424_1.value },
   NULL,
};
static const nir_search_expression replace512 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 2,
   nir_op_isub,
   { &replace327.value, &replace512_1.value },
   NULL,
};

   /* search513_0 -> search13_0 in the cache */

/* search513_1 -> replace13_1_0 in the cache */
static const nir_search_expression search513 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_urhadd,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace513_0_0 -> search13_0 in the cache */

/* replace513_0_1 -> replace13_1_0 in the cache */
/* replace513_0 -> replace327 in the cache */

/* replace513_1_0_0 -> search13_0 in the cache */

/* replace513_1_0_1 -> replace13_1_0 in the cache */
/* replace513_1_0 -> replace512_1_0 in the cache */

/* replace513_1_1 -> replace424_1 in the cache */
static const nir_search_expression replace513_1 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 1,
   nir_op_ushr,
   { &replace512_1_0.value, &replace424_1.value },
   NULL,
};
static const nir_search_expression replace513 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 2,
   nir_op_isub,
   { &replace327.value, &replace513_1.value },
   NULL,
};

   /* search514_0 -> search13_0 in the cache */

/* search514_1 -> replace13_1_0 in the cache */
static const nir_search_expression search514 = {
   { nir_search_value_expression, -2 },
   false,
   0, 1,
   nir_op_uadd_sat,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace514_0_0_0 -> search13_0 in the cache */

/* replace514_0_0_1 -> replace13_1_0 in the cache */
/* replace514_0_0 -> replace474 in the cache */

/* replace514_0_1 -> search13_0 in the cache */
static const nir_search_expression replace514_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ult,
   { &replace474.value, &search13_0.value },
   NULL,
};

static const nir_search_constant replace514_1 = {
   { nir_search_value_constant, -2 },
   nir_type_int, { -0x1 /* -1 */ },
};

/* replace514_2_0 -> search13_0 in the cache */

/* replace514_2_1 -> replace13_1_0 in the cache */
/* replace514_2 -> search31_1 in the cache */
static const nir_search_expression replace514 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace514_0.value, &replace514_1.value, &search31_1.value },
   NULL,
};

   /* search515_0 -> search13_0 in the cache */

/* search515_1 -> replace13_1_0 in the cache */
static const nir_search_expression search515 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_usub_sat,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

   /* replace515_0_0 -> search13_0 in the cache */

/* replace515_0_1 -> replace13_1_0 in the cache */
/* replace515_0 -> search86_0 in the cache */

/* replace515_1 -> replace124_1 in the cache */

/* replace515_2_0 -> search13_0 in the cache */

/* replace515_2_1 -> replace13_1_0 in the cache */
/* replace515_2 -> search478 in the cache */
static const nir_search_expression replace515 = {
   { nir_search_value_expression, -2 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search86_0.value, &replace124_1.value, &search478.value },
   NULL,
};

   /* search516_0 -> search509_0 in the cache */

/* search516_1 -> search509_1 in the cache */

/* search516_2 -> search509_2 in the cache */

/* search516_3 -> search509_3 in the cache */
/* search516 -> search509 in the cache */

   /* replace516_0_0 -> search394_1_0 in the cache */

/* replace516_0_1 -> search509_3 in the cache */
/* replace516_0 -> replace509_0 in the cache */

/* replace516_1 -> search509_1 in the cache */

/* replace516_2_0_0 -> search509_0 in the cache */

/* replace516_2_0_1_0_0 -> search509_3 in the cache */

/* replace516_2_0_1_0_1 -> search509_2 in the cache */
/* replace516_2_0_1_0 -> replace509_2_0 in the cache */
static const nir_search_expression replace516_2_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_inot,
   { &replace509_2_0.value },
   NULL,
};
static const nir_search_expression replace516_2_0 = {
   { nir_search_value_expression, 32 },
   false,
   1, 1,
   nir_op_iand,
   { &search509_0.value, &replace516_2_0_1.value },
   NULL,
};

/* replace516_2_1_0_0 -> search509_1 in the cache */

/* replace516_2_1_0_1 -> search509_2 in the cache */
static const nir_search_expression replace516_2_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search509_1.value, &search509_2.value },
   NULL,
};

/* replace516_2_1_1_0 -> search509_3 in the cache */

/* replace516_2_1_1_1 -> search509_2 in the cache */
/* replace516_2_1_1 -> replace509_2_0 in the cache */
static const nir_search_expression replace516_2_1 = {
   { nir_search_value_expression, 32 },
   false,
   2, 1,
   nir_op_iand,
   { &replace516_2_1_0.value, &replace509_2_0.value },
   NULL,
};
static const nir_search_expression replace516_2 = {
   { nir_search_value_expression, 32 },
   false,
   0, 3,
   nir_op_ior,
   { &replace516_2_0.value, &replace516_2_1.value },
   NULL,
};
static const nir_search_expression replace516 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 3,
   nir_op_bcsel,
   { &replace509_0.value, &search509_1.value, &replace516_2.value },
   NULL,
};

   static const nir_search_variable search517_0 = {
   { nir_search_value_variable, 32 },
   0, /* bits */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search517_1 = {
   { nir_search_value_variable, 32 },
   1, /* offset */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search517 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bfm,
   { &search517_0.value, &search517_1.value },
   NULL,
};

   /* replace517_0_0_0 -> replace424_1 in the cache */

/* replace517_0_0_1 -> search517_0 in the cache */
static const nir_search_expression replace517_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishl,
   { &replace424_1.value, &search517_0.value },
   NULL,
};

/* replace517_0_1 -> replace424_1 in the cache */
static const nir_search_expression replace517_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_isub,
   { &replace517_0_0.value, &replace424_1.value },
   NULL,
};

/* replace517_1 -> search517_1 in the cache */
static const nir_search_expression replace517 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishl,
   { &replace517_0.value, &search517_1.value },
   NULL,
};

   static const nir_search_variable search518_0 = {
   { nir_search_value_variable, 32 },
   0, /* value */
   false,
   nir_type_invalid,
   NULL,
};

/* search518_1 -> search517_1 in the cache */

static const nir_search_variable search518_2 = {
   { nir_search_value_variable, 32 },
   2, /* bits */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search518 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ibitfield_extract,
   { &search518_0.value, &search517_1.value, &search518_2.value },
   NULL,
};

   /* replace518_0_0 -> search394_1_0 in the cache */

/* replace518_0_1 -> search518_2 in the cache */
static const nir_search_expression replace518_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search394_1_0.value, &search518_2.value },
   NULL,
};

/* replace518_1 -> search518_0 in the cache */

/* replace518_2_0 -> search518_0 in the cache */

/* replace518_2_1 -> search517_1 in the cache */

/* replace518_2_2 -> search518_2 in the cache */
static const nir_search_expression replace518_2 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ibfe,
   { &search518_0.value, &search517_1.value, &search518_2.value },
   NULL,
};
static const nir_search_expression replace518 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace518_0.value, &search518_0.value, &replace518_2.value },
   NULL,
};

   /* search519_0 -> search518_0 in the cache */

/* search519_1 -> search517_1 in the cache */

/* search519_2 -> search518_2 in the cache */
static const nir_search_expression search519 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ubitfield_extract,
   { &search518_0.value, &search517_1.value, &search518_2.value },
   NULL,
};

   /* replace519_0_0 -> search394_1_0 in the cache */

/* replace519_0_1 -> search518_2 in the cache */
static const nir_search_expression replace519_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search394_1_0.value, &search518_2.value },
   NULL,
};

/* replace519_1 -> search518_0 in the cache */

/* replace519_2_0 -> search518_0 in the cache */

/* replace519_2_1 -> search517_1 in the cache */

/* replace519_2_2 -> search518_2 in the cache */
static const nir_search_expression replace519_2 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ubfe,
   { &search518_0.value, &search517_1.value, &search518_2.value },
   NULL,
};
static const nir_search_expression replace519 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace519_0.value, &search518_0.value, &replace519_2.value },
   NULL,
};

   /* search520_0 -> search518_0 in the cache */

/* search520_1 -> search517_1 in the cache */

/* search520_2 -> search518_2 in the cache */
/* search520 -> search518 in the cache */

   /* replace520_0_0 -> search25_1 in the cache */

/* replace520_0_1 -> search518_2 in the cache */
static const nir_search_expression replace520_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &search25_1.value, &search518_2.value },
   NULL,
};

/* replace520_1 -> search25_1 in the cache */

/* replace520_2_0_0 -> search518_0 in the cache */

/* replace520_2_0_1_0_0 -> search430_0_1 in the cache */

/* replace520_2_0_1_0_1 -> search518_2 in the cache */
static const nir_search_expression replace520_2_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_isub,
   { &search430_0_1.value, &search518_2.value },
   NULL,
};

/* replace520_2_0_1_1 -> search517_1 in the cache */
static const nir_search_expression replace520_2_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_isub,
   { &replace520_2_0_1_0.value, &search517_1.value },
   NULL,
};
static const nir_search_expression replace520_2_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search518_0.value, &replace520_2_0_1.value },
   NULL,
};

/* replace520_2_1_0 -> search430_0_1 in the cache */

/* replace520_2_1_1 -> search518_2 in the cache */
/* replace520_2_1 -> replace520_2_0_1_0 in the cache */
static const nir_search_expression replace520_2 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishr,
   { &replace520_2_0.value, &replace520_2_0_1_0.value },
   NULL,
};
static const nir_search_expression replace520 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_bcsel,
   { &replace520_0.value, &search25_1.value, &replace520_2.value },
   NULL,
};

   /* search521_0 -> search518_0 in the cache */

/* search521_1 -> search517_1 in the cache */

/* search521_2 -> search518_2 in the cache */
/* search521 -> search519 in the cache */

   /* replace521_0_0 -> search518_0 in the cache */

/* replace521_0_1 -> search517_1 in the cache */
static const nir_search_expression replace521_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search518_0.value, &search517_1.value },
   NULL,
};

/* replace521_1_0_0 -> search518_2 in the cache */

/* replace521_1_0_1 -> search430_0_1 in the cache */
static const nir_search_expression replace521_1_0 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_ieq,
   { &search518_2.value, &search430_0_1.value },
   NULL,
};

static const nir_search_constant replace521_1_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0xffffffff /* 4294967295 */ },
};

/* replace521_1_2_0 -> search518_2 in the cache */

/* replace521_1_2_1 -> search25_1 in the cache */
static const nir_search_expression replace521_1_2 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bfm,
   { &search518_2.value, &search25_1.value },
   NULL,
};
static const nir_search_expression replace521_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_bcsel,
   { &replace521_1_0.value, &replace521_1_1.value, &replace521_1_2.value },
   NULL,
};
static const nir_search_expression replace521 = {
   { nir_search_value_expression, 32 },
   false,
   0, 2,
   nir_op_iand,
   { &replace521_0.value, &replace521_1.value },
   NULL,
};

   /* search522_0 -> search518_0 in the cache */
static const nir_search_expression search522 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ifind_msb,
   { &search518_0.value },
   NULL,
};

   /* replace522_0_0_0 -> search518_0 in the cache */

/* replace522_0_0_1 -> search25_1 in the cache */
static const nir_search_expression replace522_0_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search518_0.value, &search25_1.value },
   NULL,
};

/* replace522_0_1_0 -> search518_0 in the cache */
static const nir_search_expression replace522_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_inot,
   { &search518_0.value },
   NULL,
};

/* replace522_0_2 -> search518_0 in the cache */
static const nir_search_expression replace522_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace522_0_0.value, &replace522_0_1.value, &search518_0.value },
   NULL,
};
static const nir_search_expression replace522 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ufind_msb,
   { &replace522_0.value },
   NULL,
};

   static const nir_search_variable search523_0 = {
   { nir_search_value_variable, -1 },
   0, /* value */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search523 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_find_lsb,
   { &search523_0.value },
   NULL,
};

   /* replace523_0_0 -> search523_0 in the cache */

/* replace523_0_1_0 -> search523_0 in the cache */
static const nir_search_expression replace523_0_1 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_ineg,
   { &search523_0.value },
   NULL,
};
static const nir_search_expression replace523_0 = {
   { nir_search_value_expression, -1 },
   false,
   0, 1,
   nir_op_iand,
   { &search523_0.value, &replace523_0_1.value },
   NULL,
};
static const nir_search_expression replace523 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_ufind_msb,
   { &replace523_0.value },
   NULL,
};

   /* search524_0 -> search0_0 in the cache */

/* search524_1 -> replace0_1_0 in the cache */
static const nir_search_expression search524 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* replace524_0_0 -> search0_0 in the cache */

/* replace524_0_1_0_0 -> replace417_1 in the cache */

/* replace524_0_1_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace524_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_isub,
   { &replace417_1.value, &replace0_1_0.value },
   NULL,
};

/* replace524_0_1_1 -> search416_1 in the cache */
static const nir_search_expression replace524_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_imul,
   { &replace524_0_1_0.value, &search416_1.value },
   NULL,
};
static const nir_search_expression replace524_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_ishl,
   { &search0_0.value, &replace524_0_1.value },
   NULL,
};

/* replace524_1 -> search338_1_1 in the cache */
static const nir_search_expression replace524 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_ishr,
   { &replace524_0.value, &search338_1_1.value },
   NULL,
};

   /* search525_0 -> search0_0 in the cache */

/* search525_1 -> replace0_1_0 in the cache */
static const nir_search_expression search525 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* replace525_0_0 -> search0_0 in the cache */

/* replace525_0_1_0 -> replace0_1_0 in the cache */

/* replace525_0_1_1 -> search416_1 in the cache */
static const nir_search_expression replace525_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   1, 1,
   nir_op_imul,
   { &replace0_1_0.value, &search416_1.value },
   NULL,
};
static const nir_search_expression replace525_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_ushr,
   { &search0_0.value, &replace525_0_1.value },
   NULL,
};

/* replace525_1 -> search338_0 in the cache */
static const nir_search_expression replace525 = {
   { nir_search_value_expression, 32 },
   false,
   0, 2,
   nir_op_iand,
   { &replace525_0.value, &search338_0.value },
   NULL,
};

   /* search526_0 -> search0_0 in the cache */

/* search526_1 -> replace0_1_0 in the cache */
static const nir_search_expression search526 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i16,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* replace526_0_0 -> search0_0 in the cache */

/* replace526_0_1_0_0 -> replace424_1 in the cache */

/* replace526_0_1_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace526_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_isub,
   { &replace424_1.value, &replace0_1_0.value },
   NULL,
};

/* replace526_0_1_1 -> search339_1_1 in the cache */
static const nir_search_expression replace526_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_imul,
   { &replace526_0_1_0.value, &search339_1_1.value },
   NULL,
};
static const nir_search_expression replace526_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_ishl,
   { &search0_0.value, &replace526_0_1.value },
   NULL,
};

/* replace526_1 -> search339_1_1 in the cache */
static const nir_search_expression replace526 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_ishr,
   { &replace526_0.value, &search339_1_1.value },
   NULL,
};

   /* search527_0 -> search0_0 in the cache */

/* search527_1 -> replace0_1_0 in the cache */
static const nir_search_expression search527 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u16,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* replace527_0_0 -> search0_0 in the cache */

/* replace527_0_1_0 -> replace0_1_0 in the cache */

/* replace527_0_1_1 -> search339_1_1 in the cache */
static const nir_search_expression replace527_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   1, 1,
   nir_op_imul,
   { &replace0_1_0.value, &search339_1_1.value },
   NULL,
};
static const nir_search_expression replace527_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_ushr,
   { &search0_0.value, &replace527_0_1.value },
   NULL,
};

/* replace527_1 -> search339_0 in the cache */
static const nir_search_expression replace527 = {
   { nir_search_value_expression, 32 },
   false,
   0, 2,
   nir_op_iand,
   { &replace527_0.value, &search339_0.value },
   NULL,
};

   static const nir_search_variable search528_0 = {
   { nir_search_value_variable, 32 },
   0, /* v */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search528 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_pack_unorm_2x16,
   { &search528_0.value },
   NULL,
};

   /* replace528_0_0_0_0_0 -> search528_0 in the cache */
static const nir_search_expression replace528_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fsat,
   { &search528_0.value },
   NULL,
};

static const nir_search_constant replace528_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_float, { 0x40efffe000000000 /* 65535.0 */ },
};
static const nir_search_expression replace528_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_fmul,
   { &replace528_0_0_0_0.value, &replace528_0_0_0_1.value },
   NULL,
};
static const nir_search_expression replace528_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_fround_even,
   { &replace528_0_0_0.value },
   NULL,
};
static const nir_search_expression replace528_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_f2u32,
   { &replace528_0_0.value },
   NULL,
};
static const nir_search_expression replace528 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_pack_uvec2_to_uint,
   { &replace528_0.value },
   NULL,
};

   /* search529_0 -> search528_0 in the cache */
static const nir_search_expression search529 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_pack_unorm_4x8,
   { &search528_0.value },
   NULL,
};

   /* replace529_0_0_0_0_0 -> search528_0 in the cache */
/* replace529_0_0_0_0 -> replace528_0_0_0_0 in the cache */

static const nir_search_constant replace529_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_float, { 0x406fe00000000000 /* 255.0 */ },
};
static const nir_search_expression replace529_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_fmul,
   { &replace528_0_0_0_0.value, &replace529_0_0_0_1.value },
   NULL,
};
static const nir_search_expression replace529_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_fround_even,
   { &replace529_0_0_0.value },
   NULL,
};
static const nir_search_expression replace529_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_f2u32,
   { &replace529_0_0.value },
   NULL,
};
static const nir_search_expression replace529 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_pack_uvec4_to_uint,
   { &replace529_0.value },
   NULL,
};

   /* search530_0 -> search528_0 in the cache */
static const nir_search_expression search530 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_pack_snorm_2x16,
   { &search528_0.value },
   NULL,
};

   /* replace530_0_0_0_0_0 -> search65_0_1_0 in the cache */

/* replace530_0_0_0_0_1_0 -> search377_1 in the cache */

/* replace530_0_0_0_0_1_1 -> search528_0 in the cache */
static const nir_search_expression replace530_0_0_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search377_1.value, &search528_0.value },
   NULL,
};
static const nir_search_expression replace530_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search65_0_1_0.value, &replace530_0_0_0_0_1.value },
   NULL,
};

static const nir_search_constant replace530_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_float, { 0x40dfffc000000000 /* 32767.0 */ },
};
static const nir_search_expression replace530_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_fmul,
   { &replace530_0_0_0_0.value, &replace530_0_0_0_1.value },
   NULL,
};
static const nir_search_expression replace530_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_fround_even,
   { &replace530_0_0_0.value },
   NULL,
};
static const nir_search_expression replace530_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_f2i32,
   { &replace530_0_0.value },
   NULL,
};
static const nir_search_expression replace530 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_pack_uvec2_to_uint,
   { &replace530_0.value },
   NULL,
};

   /* search531_0 -> search528_0 in the cache */
static const nir_search_expression search531 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_pack_snorm_4x8,
   { &search528_0.value },
   NULL,
};

   /* replace531_0_0_0_0_0 -> search65_0_1_0 in the cache */

/* replace531_0_0_0_0_1_0 -> search377_1 in the cache */

/* replace531_0_0_0_0_1_1 -> search528_0 in the cache */
/* replace531_0_0_0_0_1 -> replace530_0_0_0_0_1 in the cache */
/* replace531_0_0_0_0 -> replace530_0_0_0_0 in the cache */

static const nir_search_constant replace531_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_float, { 0x405fc00000000000 /* 127.0 */ },
};
static const nir_search_expression replace531_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_fmul,
   { &replace530_0_0_0_0.value, &replace531_0_0_0_1.value },
   NULL,
};
static const nir_search_expression replace531_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_fround_even,
   { &replace531_0_0_0.value },
   NULL,
};
static const nir_search_expression replace531_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_f2i32,
   { &replace531_0_0.value },
   NULL,
};
static const nir_search_expression replace531 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 1,
   nir_op_pack_uvec4_to_uint,
   { &replace531_0.value },
   NULL,
};

   /* search532_0 -> search528_0 in the cache */
static const nir_search_expression search532 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_unpack_unorm_2x16,
   { &search528_0.value },
   NULL,
};

   /* replace532_0_0_0_0 -> search528_0 in the cache */

/* replace532_0_0_0_1 -> search25_1 in the cache */
static const nir_search_expression replace532_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u16,
   { &search528_0.value, &search25_1.value },
   NULL,
};

/* replace532_0_0_1_0 -> search528_0 in the cache */

/* replace532_0_0_1_1 -> replace424_1 in the cache */
static const nir_search_expression replace532_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u16,
   { &search528_0.value, &replace424_1.value },
   NULL,
};
static const nir_search_expression replace532_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_vec2,
   { &replace532_0_0_0.value, &replace532_0_0_1.value },
   NULL,
};
static const nir_search_expression replace532_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2f32,
   { &replace532_0_0.value },
   NULL,
};

/* replace532_1 -> replace528_0_0_0_1 in the cache */
static const nir_search_expression replace532 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fdiv,
   { &replace532_0.value, &replace528_0_0_0_1.value },
   NULL,
};

   /* search533_0 -> search528_0 in the cache */
static const nir_search_expression search533 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_unpack_unorm_4x8,
   { &search528_0.value },
   NULL,
};

   /* replace533_0_0_0_0 -> search528_0 in the cache */

/* replace533_0_0_0_1 -> search25_1 in the cache */
static const nir_search_expression replace533_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search528_0.value, &search25_1.value },
   NULL,
};

/* replace533_0_0_1_0 -> search528_0 in the cache */

/* replace533_0_0_1_1 -> replace424_1 in the cache */
static const nir_search_expression replace533_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search528_0.value, &replace424_1.value },
   NULL,
};

/* replace533_0_0_2_0 -> search528_0 in the cache */

/* replace533_0_0_2_1 -> replace425_1 in the cache */
static const nir_search_expression replace533_0_0_2 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search528_0.value, &replace425_1.value },
   NULL,
};

/* replace533_0_0_3_0 -> search528_0 in the cache */

/* replace533_0_0_3_1 -> replace417_1 in the cache */
static const nir_search_expression replace533_0_0_3 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_u8,
   { &search528_0.value, &replace417_1.value },
   NULL,
};
static const nir_search_expression replace533_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_vec4,
   { &replace533_0_0_0.value, &replace533_0_0_1.value, &replace533_0_0_2.value, &replace533_0_0_3.value },
   NULL,
};
static const nir_search_expression replace533_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2f32,
   { &replace533_0_0.value },
   NULL,
};

/* replace533_1 -> replace529_0_0_0_1 in the cache */
static const nir_search_expression replace533 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fdiv,
   { &replace533_0.value, &replace529_0_0_0_1.value },
   NULL,
};

   /* search534_0 -> search528_0 in the cache */
static const nir_search_expression search534 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_unpack_snorm_2x16,
   { &search528_0.value },
   NULL,
};

   /* replace534_0 -> search65_0_1_0 in the cache */

/* replace534_1_0 -> search377_1 in the cache */

/* replace534_1_1_0_0_0_0 -> search528_0 in the cache */

/* replace534_1_1_0_0_0_1 -> search25_1 in the cache */
static const nir_search_expression replace534_1_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i16,
   { &search528_0.value, &search25_1.value },
   NULL,
};

/* replace534_1_1_0_0_1_0 -> search528_0 in the cache */

/* replace534_1_1_0_0_1_1 -> replace424_1 in the cache */
static const nir_search_expression replace534_1_1_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i16,
   { &search528_0.value, &replace424_1.value },
   NULL,
};
static const nir_search_expression replace534_1_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_vec2,
   { &replace534_1_1_0_0_0.value, &replace534_1_1_0_0_1.value },
   NULL,
};
static const nir_search_expression replace534_1_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_search_op_i2f,
   { &replace534_1_1_0_0.value },
   NULL,
};

/* replace534_1_1_1 -> replace530_0_0_0_1 in the cache */
static const nir_search_expression replace534_1_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fdiv,
   { &replace534_1_1_0.value, &replace530_0_0_0_1.value },
   NULL,
};
static const nir_search_expression replace534_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search377_1.value, &replace534_1_1.value },
   NULL,
};
static const nir_search_expression replace534 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search65_0_1_0.value, &replace534_1.value },
   NULL,
};

   /* search535_0 -> search528_0 in the cache */
static const nir_search_expression search535 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_unpack_snorm_4x8,
   { &search528_0.value },
   NULL,
};

   /* replace535_0 -> search65_0_1_0 in the cache */

/* replace535_1_0 -> search377_1 in the cache */

/* replace535_1_1_0_0_0_0 -> search528_0 in the cache */

/* replace535_1_1_0_0_0_1 -> search25_1 in the cache */
static const nir_search_expression replace535_1_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search528_0.value, &search25_1.value },
   NULL,
};

/* replace535_1_1_0_0_1_0 -> search528_0 in the cache */

/* replace535_1_1_0_0_1_1 -> replace424_1 in the cache */
static const nir_search_expression replace535_1_1_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search528_0.value, &replace424_1.value },
   NULL,
};

/* replace535_1_1_0_0_2_0 -> search528_0 in the cache */

/* replace535_1_1_0_0_2_1 -> replace425_1 in the cache */
static const nir_search_expression replace535_1_1_0_0_2 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search528_0.value, &replace425_1.value },
   NULL,
};

/* replace535_1_1_0_0_3_0 -> search528_0 in the cache */

/* replace535_1_1_0_0_3_1 -> replace417_1 in the cache */
static const nir_search_expression replace535_1_1_0_0_3 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_extract_i8,
   { &search528_0.value, &replace417_1.value },
   NULL,
};
static const nir_search_expression replace535_1_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_vec4,
   { &replace535_1_1_0_0_0.value, &replace535_1_1_0_0_1.value, &replace535_1_1_0_0_2.value, &replace535_1_1_0_0_3.value },
   NULL,
};
static const nir_search_expression replace535_1_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_search_op_i2f,
   { &replace535_1_1_0_0.value },
   NULL,
};

/* replace535_1_1_1 -> replace531_0_0_0_1 in the cache */
static const nir_search_expression replace535_1_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fdiv,
   { &replace535_1_1_0.value, &replace531_0_0_0_1.value },
   NULL,
};
static const nir_search_expression replace535_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fmax,
   { &search377_1.value, &replace535_1_1.value },
   NULL,
};
static const nir_search_expression replace535 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_fmin,
   { &search65_0_1_0.value, &replace535_1.value },
   NULL,
};

   /* search536_0 -> search6_0 in the cache */
static const nir_search_expression search536 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_isign,
   { &search6_0.value },
   NULL,
};

   /* replace536_0_0 -> search6_0 in the cache */

/* replace536_0_1 -> search42_1 in the cache */
static const nir_search_expression replace536_0 = {
   { nir_search_value_expression, -1 },
   false,
   1, 1,
   nir_op_imax,
   { &search6_0.value, &search42_1.value },
   NULL,
};

/* replace536_1 -> search6_1 in the cache */
static const nir_search_expression replace536 = {
   { nir_search_value_expression, -1 },
   false,
   0, 2,
   nir_op_imin,
   { &replace536_0.value, &search6_1.value },
   NULL,
};

   /* search537_0 -> search6_0 in the cache */
/* search537 -> search43_0 in the cache */

   /* replace537_0_0_0 -> search23_1 in the cache */

/* replace537_0_0_1 -> search6_0 in the cache */
/* replace537_0_0 -> replace199_0 in the cache */
/* replace537_0 -> replace199 in the cache */

/* replace537_1_0_0 -> search6_0 in the cache */

/* replace537_1_0_1 -> search23_1 in the cache */
/* replace537_1_0 -> replace59_0 in the cache */
static const nir_search_expression replace537_1 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &replace59_0.value },
   NULL,
};
static const nir_search_expression replace537 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fsub,
   { &replace199.value, &replace537_1.value },
   NULL,
};

   static const nir_search_variable search538_0 = {
   { nir_search_value_variable, 8 },
   0, /* a */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search538_1 = {
   { nir_search_value_variable, 8 },
   1, /* b */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search538 = {
   { nir_search_value_expression, 8 },
   false,
   0, 1,
   nir_op_iadd_sat,
   { &search538_0.value, &search538_1.value },
   NULL,
};

   /* replace538_0_0 -> search538_1 in the cache */

static const nir_search_constant replace538_0_1 = {
   { nir_search_value_constant, 8 },
   nir_type_int, { 0x1 /* 1 */ },
};
static const nir_search_expression replace538_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search538_1.value, &replace538_0_1.value },
   NULL,
};

/* replace538_1_0_0_0 -> search538_0 in the cache */

/* replace538_1_0_0_1 -> search538_1 in the cache */
static const nir_search_expression replace538_1_0_0 = {
   { nir_search_value_expression, 8 },
   false,
   0, 1,
   nir_op_iadd,
   { &search538_0.value, &search538_1.value },
   NULL,
};

/* replace538_1_0_1 -> search538_0 in the cache */
static const nir_search_expression replace538_1_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &replace538_1_0_0.value, &search538_0.value },
   NULL,
};

static const nir_search_constant replace538_1_1 = {
   { nir_search_value_constant, 8 },
   nir_type_int, { 0x7f /* 127 */ },
};

/* replace538_1_2_0 -> search538_0 in the cache */

/* replace538_1_2_1 -> search538_1 in the cache */
static const nir_search_expression replace538_1_2 = {
   { nir_search_value_expression, 8 },
   false,
   1, 1,
   nir_op_iadd,
   { &search538_0.value, &search538_1.value },
   NULL,
};
static const nir_search_expression replace538_1 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace538_1_0.value, &replace538_1_1.value, &replace538_1_2.value },
   NULL,
};

/* replace538_2_0_0 -> search538_0 in the cache */

/* replace538_2_0_1_0 -> search538_0 in the cache */

/* replace538_2_0_1_1 -> search538_1 in the cache */
static const nir_search_expression replace538_2_0_1 = {
   { nir_search_value_expression, 8 },
   false,
   2, 1,
   nir_op_iadd,
   { &search538_0.value, &search538_1.value },
   NULL,
};
static const nir_search_expression replace538_2_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &search538_0.value, &replace538_2_0_1.value },
   NULL,
};

static const nir_search_constant replace538_2_1 = {
   { nir_search_value_constant, 8 },
   nir_type_int, { 0x80 /* 128 */ },
};

/* replace538_2_2_0 -> search538_0 in the cache */

/* replace538_2_2_1 -> search538_1 in the cache */
static const nir_search_expression replace538_2_2 = {
   { nir_search_value_expression, 8 },
   false,
   3, 1,
   nir_op_iadd,
   { &search538_0.value, &search538_1.value },
   NULL,
};
static const nir_search_expression replace538_2 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace538_2_0.value, &replace538_2_1.value, &replace538_2_2.value },
   NULL,
};
static const nir_search_expression replace538 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 4,
   nir_op_bcsel,
   { &replace538_0.value, &replace538_1.value, &replace538_2.value },
   NULL,
};

   /* search539_0 -> search538_0 in the cache */

/* search539_1 -> search538_1 in the cache */
static const nir_search_expression search539 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_isub_sat,
   { &search538_0.value, &search538_1.value },
   NULL,
};

   /* replace539_0_0 -> search538_1 in the cache */

static const nir_search_constant replace539_0_1 = {
   { nir_search_value_constant, 8 },
   nir_type_int, { 0x0 /* 0 */ },
};
static const nir_search_expression replace539_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search538_1.value, &replace539_0_1.value },
   NULL,
};

/* replace539_1_0_0_0 -> search538_0 in the cache */

/* replace539_1_0_0_1 -> search538_1 in the cache */
static const nir_search_expression replace539_1_0_0 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_isub,
   { &search538_0.value, &search538_1.value },
   NULL,
};

/* replace539_1_0_1 -> search538_0 in the cache */
static const nir_search_expression replace539_1_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &replace539_1_0_0.value, &search538_0.value },
   NULL,
};

/* replace539_1_1 -> replace538_1_1 in the cache */

/* replace539_1_2_0 -> search538_0 in the cache */

/* replace539_1_2_1 -> search538_1 in the cache */
/* replace539_1_2 -> replace539_1_0_0 in the cache */
static const nir_search_expression replace539_1 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace539_1_0.value, &replace538_1_1.value, &replace539_1_0_0.value },
   NULL,
};

/* replace539_2_0_0 -> search538_0 in the cache */

/* replace539_2_0_1_0 -> search538_0 in the cache */

/* replace539_2_0_1_1 -> search538_1 in the cache */
/* replace539_2_0_1 -> replace539_1_0_0 in the cache */
static const nir_search_expression replace539_2_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search538_0.value, &replace539_1_0_0.value },
   NULL,
};

/* replace539_2_1 -> replace538_2_1 in the cache */

/* replace539_2_2_0 -> search538_0 in the cache */

/* replace539_2_2_1 -> search538_1 in the cache */
/* replace539_2_2 -> replace539_1_0_0 in the cache */
static const nir_search_expression replace539_2 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace539_2_0.value, &replace538_2_1.value, &replace539_1_0_0.value },
   NULL,
};
static const nir_search_expression replace539 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace539_0.value, &replace539_1.value, &replace539_2.value },
   NULL,
};

   /* search540_0 -> search56_0 in the cache */

/* search540_1 -> search56_1 in the cache */
static const nir_search_expression search540 = {
   { nir_search_value_expression, 16 },
   false,
   0, 1,
   nir_op_iadd_sat,
   { &search56_0.value, &search56_1.value },
   NULL,
};

   /* replace540_0_0 -> search56_1 in the cache */

/* replace540_0_1 -> replace416_1 in the cache */
static const nir_search_expression replace540_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search56_1.value, &replace416_1.value },
   NULL,
};

/* replace540_1_0_0_0 -> search56_0 in the cache */

/* replace540_1_0_0_1 -> search56_1 in the cache */
static const nir_search_expression replace540_1_0_0 = {
   { nir_search_value_expression, 16 },
   false,
   0, 1,
   nir_op_iadd,
   { &search56_0.value, &search56_1.value },
   NULL,
};

/* replace540_1_0_1 -> search56_0 in the cache */
static const nir_search_expression replace540_1_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &replace540_1_0_0.value, &search56_0.value },
   NULL,
};

static const nir_search_constant replace540_1_1 = {
   { nir_search_value_constant, 16 },
   nir_type_int, { 0x7fff /* 32767 */ },
};

/* replace540_1_2_0 -> search56_0 in the cache */

/* replace540_1_2_1 -> search56_1 in the cache */
static const nir_search_expression replace540_1_2 = {
   { nir_search_value_expression, 16 },
   false,
   1, 1,
   nir_op_iadd,
   { &search56_0.value, &search56_1.value },
   NULL,
};
static const nir_search_expression replace540_1 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace540_1_0.value, &replace540_1_1.value, &replace540_1_2.value },
   NULL,
};

/* replace540_2_0_0 -> search56_0 in the cache */

/* replace540_2_0_1_0 -> search56_0 in the cache */

/* replace540_2_0_1_1 -> search56_1 in the cache */
static const nir_search_expression replace540_2_0_1 = {
   { nir_search_value_expression, 16 },
   false,
   2, 1,
   nir_op_iadd,
   { &search56_0.value, &search56_1.value },
   NULL,
};
static const nir_search_expression replace540_2_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &search56_0.value, &replace540_2_0_1.value },
   NULL,
};

static const nir_search_constant replace540_2_1 = {
   { nir_search_value_constant, 16 },
   nir_type_int, { 0x8000 /* 32768 */ },
};

/* replace540_2_2_0 -> search56_0 in the cache */

/* replace540_2_2_1 -> search56_1 in the cache */
static const nir_search_expression replace540_2_2 = {
   { nir_search_value_expression, 16 },
   false,
   3, 1,
   nir_op_iadd,
   { &search56_0.value, &search56_1.value },
   NULL,
};
static const nir_search_expression replace540_2 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace540_2_0.value, &replace540_2_1.value, &replace540_2_2.value },
   NULL,
};
static const nir_search_expression replace540 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 4,
   nir_op_bcsel,
   { &replace540_0.value, &replace540_1.value, &replace540_2.value },
   NULL,
};

   /* search541_0 -> search56_0 in the cache */

/* search541_1 -> search56_1 in the cache */
static const nir_search_expression search541 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_isub_sat,
   { &search56_0.value, &search56_1.value },
   NULL,
};

   /* replace541_0_0 -> search56_1 in the cache */

/* replace541_0_1 -> search423_1 in the cache */
static const nir_search_expression replace541_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search56_1.value, &search423_1.value },
   NULL,
};

/* replace541_1_0_0_0 -> search56_0 in the cache */

/* replace541_1_0_0_1 -> search56_1 in the cache */
static const nir_search_expression replace541_1_0_0 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_isub,
   { &search56_0.value, &search56_1.value },
   NULL,
};

/* replace541_1_0_1 -> search56_0 in the cache */
static const nir_search_expression replace541_1_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &replace541_1_0_0.value, &search56_0.value },
   NULL,
};

/* replace541_1_1 -> replace540_1_1 in the cache */

/* replace541_1_2_0 -> search56_0 in the cache */

/* replace541_1_2_1 -> search56_1 in the cache */
/* replace541_1_2 -> replace541_1_0_0 in the cache */
static const nir_search_expression replace541_1 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace541_1_0.value, &replace540_1_1.value, &replace541_1_0_0.value },
   NULL,
};

/* replace541_2_0_0 -> search56_0 in the cache */

/* replace541_2_0_1_0 -> search56_0 in the cache */

/* replace541_2_0_1_1 -> search56_1 in the cache */
/* replace541_2_0_1 -> replace541_1_0_0 in the cache */
static const nir_search_expression replace541_2_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search56_0.value, &replace541_1_0_0.value },
   NULL,
};

/* replace541_2_1 -> replace540_2_1 in the cache */

/* replace541_2_2_0 -> search56_0 in the cache */

/* replace541_2_2_1 -> search56_1 in the cache */
/* replace541_2_2 -> replace541_1_0_0 in the cache */
static const nir_search_expression replace541_2 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace541_2_0.value, &replace540_2_1.value, &replace541_1_0_0.value },
   NULL,
};
static const nir_search_expression replace541 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace541_0.value, &replace541_1.value, &replace541_2.value },
   NULL,
};

   /* search542_0 -> search0_0 in the cache */

/* search542_1 -> replace0_1_0 in the cache */
static const nir_search_expression search542 = {
   { nir_search_value_expression, 32 },
   false,
   0, 1,
   nir_op_iadd_sat,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* replace542_0_0 -> replace0_1_0 in the cache */

/* replace542_0_1 -> replace424_1 in the cache */
static const nir_search_expression replace542_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &replace0_1_0.value, &replace424_1.value },
   NULL,
};

/* replace542_1_0_0_0 -> search0_0 in the cache */

/* replace542_1_0_0_1 -> replace0_1_0 in the cache */
/* replace542_1_0_0 -> replace507_0_0 in the cache */

/* replace542_1_0_1 -> search0_0 in the cache */
static const nir_search_expression replace542_1_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &replace507_0_0.value, &search0_0.value },
   NULL,
};

static const nir_search_constant replace542_1_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x7fffffff /* 2147483647 */ },
};

/* replace542_1_2_0 -> search0_0 in the cache */

/* replace542_1_2_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace542_1_2 = {
   { nir_search_value_expression, 32 },
   false,
   1, 1,
   nir_op_iadd,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace542_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace542_1_0.value, &replace542_1_1.value, &replace542_1_2.value },
   NULL,
};

/* replace542_2_0_0 -> search0_0 in the cache */

/* replace542_2_0_1_0 -> search0_0 in the cache */

/* replace542_2_0_1_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace542_2_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   2, 1,
   nir_op_iadd,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace542_2_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &search0_0.value, &replace542_2_0_1.value },
   NULL,
};

/* replace542_2_1 -> replace244_1_1 in the cache */

/* replace542_2_2_0 -> search0_0 in the cache */

/* replace542_2_2_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace542_2_2 = {
   { nir_search_value_expression, 32 },
   false,
   3, 1,
   nir_op_iadd,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};
static const nir_search_expression replace542_2 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace542_2_0.value, &replace244_1_1.value, &replace542_2_2.value },
   NULL,
};
static const nir_search_expression replace542 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 4,
   nir_op_bcsel,
   { &replace542_0.value, &replace542_1.value, &replace542_2.value },
   NULL,
};

   /* search543_0 -> search0_0 in the cache */

/* search543_1 -> replace0_1_0 in the cache */
static const nir_search_expression search543 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_isub_sat,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

   /* replace543_0_0 -> replace0_1_0 in the cache */

/* replace543_0_1 -> search25_1 in the cache */
static const nir_search_expression replace543_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &replace0_1_0.value, &search25_1.value },
   NULL,
};

/* replace543_1_0_0_0 -> search0_0 in the cache */

/* replace543_1_0_0_1 -> replace0_1_0 in the cache */
static const nir_search_expression replace543_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_isub,
   { &search0_0.value, &replace0_1_0.value },
   NULL,
};

/* replace543_1_0_1 -> search0_0 in the cache */
static const nir_search_expression replace543_1_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &replace543_1_0_0.value, &search0_0.value },
   NULL,
};

/* replace543_1_1 -> replace542_1_1 in the cache */

/* replace543_1_2_0 -> search0_0 in the cache */

/* replace543_1_2_1 -> replace0_1_0 in the cache */
/* replace543_1_2 -> replace543_1_0_0 in the cache */
static const nir_search_expression replace543_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace543_1_0.value, &replace542_1_1.value, &replace543_1_0_0.value },
   NULL,
};

/* replace543_2_0_0 -> search0_0 in the cache */

/* replace543_2_0_1_0 -> search0_0 in the cache */

/* replace543_2_0_1_1 -> replace0_1_0 in the cache */
/* replace543_2_0_1 -> replace543_1_0_0 in the cache */
static const nir_search_expression replace543_2_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search0_0.value, &replace543_1_0_0.value },
   NULL,
};

/* replace543_2_1 -> replace244_1_1 in the cache */

/* replace543_2_2_0 -> search0_0 in the cache */

/* replace543_2_2_1 -> replace0_1_0 in the cache */
/* replace543_2_2 -> replace543_1_0_0 in the cache */
static const nir_search_expression replace543_2 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace543_2_0.value, &replace244_1_1.value, &replace543_1_0_0.value },
   NULL,
};
static const nir_search_expression replace543 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace543_0.value, &replace543_1.value, &replace543_2.value },
   NULL,
};

   /* search544_0 -> search58_0 in the cache */

/* search544_1 -> search58_1 in the cache */
static const nir_search_expression search544 = {
   { nir_search_value_expression, 64 },
   false,
   0, 1,
   nir_op_iadd_sat,
   { &search58_0.value, &search58_1.value },
   NULL,
};

   /* replace544_0_0 -> search58_1 in the cache */

/* replace544_0_1 -> replace427_1 in the cache */
static const nir_search_expression replace544_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search58_1.value, &replace427_1.value },
   NULL,
};

/* replace544_1_0_0_0 -> search58_0 in the cache */

/* replace544_1_0_0_1 -> search58_1 in the cache */
static const nir_search_expression replace544_1_0_0 = {
   { nir_search_value_expression, 64 },
   false,
   0, 1,
   nir_op_iadd,
   { &search58_0.value, &search58_1.value },
   NULL,
};

/* replace544_1_0_1 -> search58_0 in the cache */
static const nir_search_expression replace544_1_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &replace544_1_0_0.value, &search58_0.value },
   NULL,
};

static const nir_search_constant replace544_1_1 = {
   { nir_search_value_constant, 64 },
   nir_type_int, { 0x7fffffffffffffffL /* 9223372036854775807 */ },
};

/* replace544_1_2_0 -> search58_0 in the cache */

/* replace544_1_2_1 -> search58_1 in the cache */
static const nir_search_expression replace544_1_2 = {
   { nir_search_value_expression, 64 },
   false,
   1, 1,
   nir_op_iadd,
   { &search58_0.value, &search58_1.value },
   NULL,
};
static const nir_search_expression replace544_1 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace544_1_0.value, &replace544_1_1.value, &replace544_1_2.value },
   NULL,
};

/* replace544_2_0_0 -> search58_0 in the cache */

/* replace544_2_0_1_0 -> search58_0 in the cache */

/* replace544_2_0_1_1 -> search58_1 in the cache */
static const nir_search_expression replace544_2_0_1 = {
   { nir_search_value_expression, 64 },
   false,
   2, 1,
   nir_op_iadd,
   { &search58_0.value, &search58_1.value },
   NULL,
};
static const nir_search_expression replace544_2_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_ilt,
   { &search58_0.value, &replace544_2_0_1.value },
   NULL,
};

static const nir_search_constant replace544_2_1 = {
   { nir_search_value_constant, 64 },
   nir_type_int, { 0x8000000000000000L /* 9223372036854775808 */ },
};

/* replace544_2_2_0 -> search58_0 in the cache */

/* replace544_2_2_1 -> search58_1 in the cache */
static const nir_search_expression replace544_2_2 = {
   { nir_search_value_expression, 64 },
   false,
   3, 1,
   nir_op_iadd,
   { &search58_0.value, &search58_1.value },
   NULL,
};
static const nir_search_expression replace544_2 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace544_2_0.value, &replace544_2_1.value, &replace544_2_2.value },
   NULL,
};
static const nir_search_expression replace544 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 4,
   nir_op_bcsel,
   { &replace544_0.value, &replace544_1.value, &replace544_2.value },
   NULL,
};

   /* search545_0 -> search58_0 in the cache */

/* search545_1 -> search58_1 in the cache */
static const nir_search_expression search545 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_isub_sat,
   { &search58_0.value, &search58_1.value },
   NULL,
};

   /* replace545_0_0 -> search58_1 in the cache */

/* replace545_0_1 -> search427_1 in the cache */
static const nir_search_expression replace545_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search58_1.value, &search427_1.value },
   NULL,
};

/* replace545_1_0_0_0 -> search58_0 in the cache */

/* replace545_1_0_0_1 -> search58_1 in the cache */
static const nir_search_expression replace545_1_0_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_isub,
   { &search58_0.value, &search58_1.value },
   NULL,
};

/* replace545_1_0_1 -> search58_0 in the cache */
static const nir_search_expression replace545_1_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &replace545_1_0_0.value, &search58_0.value },
   NULL,
};

/* replace545_1_1 -> replace544_1_1 in the cache */

/* replace545_1_2_0 -> search58_0 in the cache */

/* replace545_1_2_1 -> search58_1 in the cache */
/* replace545_1_2 -> replace545_1_0_0 in the cache */
static const nir_search_expression replace545_1 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace545_1_0.value, &replace544_1_1.value, &replace545_1_0_0.value },
   NULL,
};

/* replace545_2_0_0 -> search58_0 in the cache */

/* replace545_2_0_1_0 -> search58_0 in the cache */

/* replace545_2_0_1_1 -> search58_1 in the cache */
/* replace545_2_0_1 -> replace545_1_0_0 in the cache */
static const nir_search_expression replace545_2_0 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search58_0.value, &replace545_1_0_0.value },
   NULL,
};

/* replace545_2_1 -> replace544_2_1 in the cache */

/* replace545_2_2_0 -> search58_0 in the cache */

/* replace545_2_2_1 -> search58_1 in the cache */
/* replace545_2_2 -> replace545_1_0_0 in the cache */
static const nir_search_expression replace545_2 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace545_2_0.value, &replace544_2_1.value, &replace545_1_0_0.value },
   NULL,
};
static const nir_search_expression replace545 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace545_0.value, &replace545_1.value, &replace545_2.value },
   NULL,
};

   /* search546_0_0_0 -> search13_0 in the cache */

/* search546_0_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression search546_0_0 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_feq,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

/* search546_0_1_0 -> search73_0_2 in the cache */

/* search546_0_1_1 -> search73_1 in the cache */
static const nir_search_expression search546_0_1 = {
   { nir_search_value_expression, 1 },
   false,
   2, 1,
   nir_op_feq,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression search546_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_ior,
   { &search546_0_0.value, &search546_0_1.value },
   (is_used_once),
};
static const nir_search_expression search546 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 3,
   nir_op_inot,
   { &search546_0.value },
   NULL,
};

   /* replace546_0_0 -> search13_0 in the cache */

/* replace546_0_1 -> replace13_1_0 in the cache */
static const nir_search_expression replace546_0 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_fne,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};

/* replace546_1_0 -> search73_0_2 in the cache */

/* replace546_1_1 -> search73_1 in the cache */
static const nir_search_expression replace546_1 = {
   { nir_search_value_expression, 1 },
   false,
   2, 1,
   nir_op_fne,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace546 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_iand,
   { &replace546_0.value, &replace546_1.value },
   NULL,
};

   /* search547_0_0_0 -> search13_0 in the cache */

/* search547_0_0_1 -> replace13_1_0 in the cache */
/* search547_0_0 -> search546_0_0 in the cache */

/* search547_0_1_0 -> search73_0_2 in the cache */

/* search547_0_1_1 -> search73_1 in the cache */
/* search547_0_1 -> search546_0_1 in the cache */
static const nir_search_expression search547_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_iand,
   { &search546_0_0.value, &search546_0_1.value },
   (is_used_once),
};
static const nir_search_expression search547 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 3,
   nir_op_inot,
   { &search547_0.value },
   NULL,
};

   /* replace547_0_0 -> search13_0 in the cache */

/* replace547_0_1 -> replace13_1_0 in the cache */
/* replace547_0 -> replace546_0 in the cache */

/* replace547_1_0 -> search73_0_2 in the cache */

/* replace547_1_1 -> search73_1 in the cache */
/* replace547_1 -> replace546_1 in the cache */
static const nir_search_expression replace547 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_ior,
   { &replace546_0.value, &replace546_1.value },
   NULL,
};

   /* search548_0_0_0 -> search13_0 in the cache */

/* search548_0_0_1 -> replace13_1_0 in the cache */
/* search548_0_0 -> search546_0_0 in the cache */

/* search548_0_1_0 -> search73_0_2 in the cache */

/* search548_0_1_1 -> search73_1 in the cache */
/* search548_0_1 -> replace546_1 in the cache */
static const nir_search_expression search548_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_ior,
   { &search546_0_0.value, &replace546_1.value },
   (is_used_once),
};
static const nir_search_expression search548 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 3,
   nir_op_inot,
   { &search548_0.value },
   NULL,
};

   /* replace548_0_0 -> search13_0 in the cache */

/* replace548_0_1 -> replace13_1_0 in the cache */
/* replace548_0 -> replace546_0 in the cache */

/* replace548_1_0 -> search73_0_2 in the cache */

/* replace548_1_1 -> search73_1 in the cache */
/* replace548_1 -> search546_0_1 in the cache */
static const nir_search_expression replace548 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_iand,
   { &replace546_0.value, &search546_0_1.value },
   NULL,
};

   /* search549_0_0_0 -> search13_0 in the cache */

/* search549_0_0_1 -> replace13_1_0 in the cache */
/* search549_0_0 -> search546_0_0 in the cache */

/* search549_0_1_0 -> search73_0_2 in the cache */

/* search549_0_1_1 -> search73_1 in the cache */
/* search549_0_1 -> replace546_1 in the cache */
static const nir_search_expression search549_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_iand,
   { &search546_0_0.value, &replace546_1.value },
   (is_used_once),
};
static const nir_search_expression search549 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 3,
   nir_op_inot,
   { &search549_0.value },
   NULL,
};

   /* replace549_0_0 -> search13_0 in the cache */

/* replace549_0_1 -> replace13_1_0 in the cache */
/* replace549_0 -> replace546_0 in the cache */

/* replace549_1_0 -> search73_0_2 in the cache */

/* replace549_1_1 -> search73_1 in the cache */
/* replace549_1 -> search546_0_1 in the cache */
static const nir_search_expression replace549 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_ior,
   { &replace546_0.value, &search546_0_1.value },
   NULL,
};

   /* search550_0_0_0 -> search13_0 in the cache */

/* search550_0_0_1 -> replace13_1_0 in the cache */
/* search550_0_0 -> search546_0_0 in the cache */

/* search550_0_1_0 -> search73_0_2 in the cache */

/* search550_0_1_1 -> search73_1 in the cache */
static const nir_search_expression search550_0_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression search550_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ior,
   { &search546_0_0.value, &search550_0_1.value },
   (is_used_once),
};
static const nir_search_expression search550 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_inot,
   { &search550_0.value },
   NULL,
};

   /* replace550_0_0 -> search13_0 in the cache */

/* replace550_0_1 -> replace13_1_0 in the cache */
/* replace550_0 -> replace546_0 in the cache */

/* replace550_1_0 -> search73_0_2 in the cache */

/* replace550_1_1 -> search73_1 in the cache */
static const nir_search_expression replace550_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace550 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_iand,
   { &replace546_0.value, &replace550_1.value },
   NULL,
};

   /* search551_0_0_0 -> search13_0 in the cache */

/* search551_0_0_1 -> replace13_1_0 in the cache */
/* search551_0_0 -> search546_0_0 in the cache */

/* search551_0_1_0 -> search73_0_2 in the cache */

/* search551_0_1_1 -> search73_1 in the cache */
/* search551_0_1 -> search550_0_1 in the cache */
static const nir_search_expression search551_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_iand,
   { &search546_0_0.value, &search550_0_1.value },
   (is_used_once),
};
static const nir_search_expression search551 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_inot,
   { &search551_0.value },
   NULL,
};

   /* replace551_0_0 -> search13_0 in the cache */

/* replace551_0_1 -> replace13_1_0 in the cache */
/* replace551_0 -> replace546_0 in the cache */

/* replace551_1_0 -> search73_0_2 in the cache */

/* replace551_1_1 -> search73_1 in the cache */
/* replace551_1 -> replace550_1 in the cache */
static const nir_search_expression replace551 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ior,
   { &replace546_0.value, &replace550_1.value },
   NULL,
};

   /* search552_0_0_0 -> search13_0 in the cache */

/* search552_0_0_1 -> replace13_1_0 in the cache */
/* search552_0_0 -> search546_0_0 in the cache */

/* search552_0_1_0 -> search73_0_2 in the cache */

/* search552_0_1_1 -> search73_1 in the cache */
/* search552_0_1 -> replace550_1 in the cache */
static const nir_search_expression search552_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ior,
   { &search546_0_0.value, &replace550_1.value },
   (is_used_once),
};
static const nir_search_expression search552 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_inot,
   { &search552_0.value },
   NULL,
};

   /* replace552_0_0 -> search13_0 in the cache */

/* replace552_0_1 -> replace13_1_0 in the cache */
/* replace552_0 -> replace546_0 in the cache */

/* replace552_1_0 -> search73_0_2 in the cache */

/* replace552_1_1 -> search73_1 in the cache */
/* replace552_1 -> search550_0_1 in the cache */
static const nir_search_expression replace552 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_iand,
   { &replace546_0.value, &search550_0_1.value },
   NULL,
};

   /* search553_0_0_0 -> search13_0 in the cache */

/* search553_0_0_1 -> replace13_1_0 in the cache */
/* search553_0_0 -> search546_0_0 in the cache */

/* search553_0_1_0 -> search73_0_2 in the cache */

/* search553_0_1_1 -> search73_1 in the cache */
/* search553_0_1 -> replace550_1 in the cache */
static const nir_search_expression search553_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_iand,
   { &search546_0_0.value, &replace550_1.value },
   (is_used_once),
};
static const nir_search_expression search553 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_inot,
   { &search553_0.value },
   NULL,
};

   /* replace553_0_0 -> search13_0 in the cache */

/* replace553_0_1 -> replace13_1_0 in the cache */
/* replace553_0 -> replace546_0 in the cache */

/* replace553_1_0 -> search73_0_2 in the cache */

/* replace553_1_1 -> search73_1 in the cache */
/* replace553_1 -> search550_0_1 in the cache */
static const nir_search_expression replace553 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ior,
   { &replace546_0.value, &search550_0_1.value },
   NULL,
};

   /* search554_0_0_0 -> search13_0 in the cache */

/* search554_0_0_1 -> replace13_1_0 in the cache */
/* search554_0_0 -> replace546_0 in the cache */

/* search554_0_1_0 -> search73_0_2 in the cache */

/* search554_0_1_1 -> search73_1 in the cache */
/* search554_0_1 -> replace546_1 in the cache */
static const nir_search_expression search554_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_ior,
   { &replace546_0.value, &replace546_1.value },
   (is_used_once),
};
static const nir_search_expression search554 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 3,
   nir_op_inot,
   { &search554_0.value },
   NULL,
};

   /* replace554_0_0 -> search13_0 in the cache */

/* replace554_0_1 -> replace13_1_0 in the cache */
/* replace554_0 -> search546_0_0 in the cache */

/* replace554_1_0 -> search73_0_2 in the cache */

/* replace554_1_1 -> search73_1 in the cache */
/* replace554_1 -> search546_0_1 in the cache */
static const nir_search_expression replace554 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_iand,
   { &search546_0_0.value, &search546_0_1.value },
   NULL,
};

   /* search555_0_0_0 -> search13_0 in the cache */

/* search555_0_0_1 -> replace13_1_0 in the cache */
/* search555_0_0 -> replace546_0 in the cache */

/* search555_0_1_0 -> search73_0_2 in the cache */

/* search555_0_1_1 -> search73_1 in the cache */
/* search555_0_1 -> replace546_1 in the cache */
static const nir_search_expression search555_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_iand,
   { &replace546_0.value, &replace546_1.value },
   (is_used_once),
};
static const nir_search_expression search555 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 3,
   nir_op_inot,
   { &search555_0.value },
   NULL,
};

   /* replace555_0_0 -> search13_0 in the cache */

/* replace555_0_1 -> replace13_1_0 in the cache */
/* replace555_0 -> search546_0_0 in the cache */

/* replace555_1_0 -> search73_0_2 in the cache */

/* replace555_1_1 -> search73_1 in the cache */
/* replace555_1 -> search546_0_1 in the cache */
static const nir_search_expression replace555 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_ior,
   { &search546_0_0.value, &search546_0_1.value },
   NULL,
};

   /* search556_0_0_0 -> search13_0 in the cache */

/* search556_0_0_1 -> replace13_1_0 in the cache */
/* search556_0_0 -> replace546_0 in the cache */

/* search556_0_1_0 -> search73_0_2 in the cache */

/* search556_0_1_1 -> search73_1 in the cache */
/* search556_0_1 -> search550_0_1 in the cache */
static const nir_search_expression search556_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ior,
   { &replace546_0.value, &search550_0_1.value },
   (is_used_once),
};
static const nir_search_expression search556 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_inot,
   { &search556_0.value },
   NULL,
};

   /* replace556_0_0 -> search13_0 in the cache */

/* replace556_0_1 -> replace13_1_0 in the cache */
/* replace556_0 -> search546_0_0 in the cache */

/* replace556_1_0 -> search73_0_2 in the cache */

/* replace556_1_1 -> search73_1 in the cache */
/* replace556_1 -> replace550_1 in the cache */
static const nir_search_expression replace556 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_iand,
   { &search546_0_0.value, &replace550_1.value },
   NULL,
};

   /* search557_0_0_0 -> search13_0 in the cache */

/* search557_0_0_1 -> replace13_1_0 in the cache */
/* search557_0_0 -> replace546_0 in the cache */

/* search557_0_1_0 -> search73_0_2 in the cache */

/* search557_0_1_1 -> search73_1 in the cache */
/* search557_0_1 -> search550_0_1 in the cache */
static const nir_search_expression search557_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_iand,
   { &replace546_0.value, &search550_0_1.value },
   (is_used_once),
};
static const nir_search_expression search557 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_inot,
   { &search557_0.value },
   NULL,
};

   /* replace557_0_0 -> search13_0 in the cache */

/* replace557_0_1 -> replace13_1_0 in the cache */
/* replace557_0 -> search546_0_0 in the cache */

/* replace557_1_0 -> search73_0_2 in the cache */

/* replace557_1_1 -> search73_1 in the cache */
/* replace557_1 -> replace550_1 in the cache */
static const nir_search_expression replace557 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ior,
   { &search546_0_0.value, &replace550_1.value },
   NULL,
};

   /* search558_0_0_0 -> search13_0 in the cache */

/* search558_0_0_1 -> replace13_1_0 in the cache */
/* search558_0_0 -> replace546_0 in the cache */

/* search558_0_1_0 -> search73_0_2 in the cache */

/* search558_0_1_1 -> search73_1 in the cache */
/* search558_0_1 -> replace550_1 in the cache */
static const nir_search_expression search558_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ior,
   { &replace546_0.value, &replace550_1.value },
   (is_used_once),
};
static const nir_search_expression search558 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_inot,
   { &search558_0.value },
   NULL,
};

   /* replace558_0_0 -> search13_0 in the cache */

/* replace558_0_1 -> replace13_1_0 in the cache */
/* replace558_0 -> search546_0_0 in the cache */

/* replace558_1_0 -> search73_0_2 in the cache */

/* replace558_1_1 -> search73_1 in the cache */
/* replace558_1 -> search550_0_1 in the cache */
static const nir_search_expression replace558 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_iand,
   { &search546_0_0.value, &search550_0_1.value },
   NULL,
};

   /* search559_0_0_0 -> search13_0 in the cache */

/* search559_0_0_1 -> replace13_1_0 in the cache */
/* search559_0_0 -> replace546_0 in the cache */

/* search559_0_1_0 -> search73_0_2 in the cache */

/* search559_0_1_1 -> search73_1 in the cache */
/* search559_0_1 -> replace550_1 in the cache */
static const nir_search_expression search559_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_iand,
   { &replace546_0.value, &replace550_1.value },
   (is_used_once),
};
static const nir_search_expression search559 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_inot,
   { &search559_0.value },
   NULL,
};

   /* replace559_0_0 -> search13_0 in the cache */

/* replace559_0_1 -> replace13_1_0 in the cache */
/* replace559_0 -> search546_0_0 in the cache */

/* replace559_1_0 -> search73_0_2 in the cache */

/* replace559_1_1 -> search73_1 in the cache */
/* replace559_1 -> search550_0_1 in the cache */
static const nir_search_expression replace559 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_ior,
   { &search546_0_0.value, &search550_0_1.value },
   NULL,
};

   /* search560_0_0_0 -> search13_0 in the cache */

/* search560_0_0_1 -> replace13_1_0 in the cache */
/* search560_0_0 -> replace81 in the cache */

/* search560_0_1_0 -> search73_0_2 in the cache */

/* search560_0_1_1 -> search73_1 in the cache */
/* search560_0_1 -> search550_0_1 in the cache */
static const nir_search_expression search560_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &replace81.value, &search550_0_1.value },
   (is_used_once),
};
static const nir_search_expression search560 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_inot,
   { &search560_0.value },
   NULL,
};

   /* replace560_0_0 -> search13_0 in the cache */

/* replace560_0_1 -> replace13_1_0 in the cache */
/* replace560_0 -> search81_0 in the cache */

/* replace560_1_0 -> search73_0_2 in the cache */

/* replace560_1_1 -> search73_1 in the cache */
/* replace560_1 -> replace550_1 in the cache */
static const nir_search_expression replace560 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search81_0.value, &replace550_1.value },
   NULL,
};

   /* search561_0_0_0 -> search13_0 in the cache */

/* search561_0_0_1 -> replace13_1_0 in the cache */
/* search561_0_0 -> replace81 in the cache */

/* search561_0_1_0 -> search73_0_2 in the cache */

/* search561_0_1_1 -> search73_1 in the cache */
/* search561_0_1 -> search550_0_1 in the cache */
static const nir_search_expression search561_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &replace81.value, &search550_0_1.value },
   (is_used_once),
};
static const nir_search_expression search561 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_inot,
   { &search561_0.value },
   NULL,
};

   /* replace561_0_0 -> search13_0 in the cache */

/* replace561_0_1 -> replace13_1_0 in the cache */
/* replace561_0 -> search81_0 in the cache */

/* replace561_1_0 -> search73_0_2 in the cache */

/* replace561_1_1 -> search73_1 in the cache */
/* replace561_1 -> replace550_1 in the cache */
static const nir_search_expression replace561 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search81_0.value, &replace550_1.value },
   NULL,
};

   /* search562_0_0_0 -> search13_0 in the cache */

/* search562_0_0_1 -> replace13_1_0 in the cache */
/* search562_0_0 -> replace81 in the cache */

/* search562_0_1_0 -> search73_0_2 in the cache */

/* search562_0_1_1 -> search73_1 in the cache */
/* search562_0_1 -> replace550_1 in the cache */
static const nir_search_expression search562_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &replace81.value, &replace550_1.value },
   (is_used_once),
};
static const nir_search_expression search562 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_inot,
   { &search562_0.value },
   NULL,
};

   /* replace562_0_0 -> search13_0 in the cache */

/* replace562_0_1 -> replace13_1_0 in the cache */
/* replace562_0 -> search81_0 in the cache */

/* replace562_1_0 -> search73_0_2 in the cache */

/* replace562_1_1 -> search73_1 in the cache */
/* replace562_1 -> search550_0_1 in the cache */
static const nir_search_expression replace562 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search81_0.value, &search550_0_1.value },
   NULL,
};

   /* search563_0_0_0 -> search13_0 in the cache */

/* search563_0_0_1 -> replace13_1_0 in the cache */
/* search563_0_0 -> replace81 in the cache */

/* search563_0_1_0 -> search73_0_2 in the cache */

/* search563_0_1_1 -> search73_1 in the cache */
/* search563_0_1 -> replace550_1 in the cache */
static const nir_search_expression search563_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &replace81.value, &replace550_1.value },
   (is_used_once),
};
static const nir_search_expression search563 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_inot,
   { &search563_0.value },
   NULL,
};

   /* replace563_0_0 -> search13_0 in the cache */

/* replace563_0_1 -> replace13_1_0 in the cache */
/* replace563_0 -> search81_0 in the cache */

/* replace563_1_0 -> search73_0_2 in the cache */

/* replace563_1_1 -> search73_1 in the cache */
/* replace563_1 -> search550_0_1 in the cache */
static const nir_search_expression replace563 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search81_0.value, &search550_0_1.value },
   NULL,
};

   /* search564_0_0_0 -> search13_0 in the cache */

/* search564_0_0_1 -> replace13_1_0 in the cache */
/* search564_0_0 -> search81_0 in the cache */

/* search564_0_1_0 -> search73_0_2 in the cache */

/* search564_0_1_1 -> search73_1 in the cache */
/* search564_0_1 -> replace550_1 in the cache */
static const nir_search_expression search564_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &search81_0.value, &replace550_1.value },
   (is_used_once),
};
static const nir_search_expression search564 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_inot,
   { &search564_0.value },
   NULL,
};

   /* replace564_0_0 -> search13_0 in the cache */

/* replace564_0_1 -> replace13_1_0 in the cache */
/* replace564_0 -> replace81 in the cache */

/* replace564_1_0 -> search73_0_2 in the cache */

/* replace564_1_1 -> search73_1 in the cache */
/* replace564_1 -> search550_0_1 in the cache */
static const nir_search_expression replace564 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &replace81.value, &search550_0_1.value },
   NULL,
};

   /* search565_0_0_0 -> search13_0 in the cache */

/* search565_0_0_1 -> replace13_1_0 in the cache */
/* search565_0_0 -> search81_0 in the cache */

/* search565_0_1_0 -> search73_0_2 in the cache */

/* search565_0_1_1 -> search73_1 in the cache */
/* search565_0_1 -> replace550_1 in the cache */
static const nir_search_expression search565_0 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_iand,
   { &search81_0.value, &replace550_1.value },
   (is_used_once),
};
static const nir_search_expression search565 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 1,
   nir_op_inot,
   { &search565_0.value },
   NULL,
};

   /* replace565_0_0 -> search13_0 in the cache */

/* replace565_0_1 -> replace13_1_0 in the cache */
/* replace565_0 -> replace81 in the cache */

/* replace565_1_0 -> search73_0_2 in the cache */

/* replace565_1_1 -> search73_1 in the cache */
/* replace565_1 -> search550_0_1 in the cache */
static const nir_search_expression replace565 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ior,
   { &replace81.value, &search550_0_1.value },
   NULL,
};

   /* search566_0_0 -> replace72_0 in the cache */
/* search566_0 -> search91_1 in the cache */
static const nir_search_expression search566 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_f2b1,
   { &search91_1.value },
   NULL,
};

   /* replace566 -> replace72_0 in the cache */

   /* search567_0_0 -> replace72_0 in the cache */
/* search567_0 -> search130_0 in the cache */
static const nir_search_expression search567 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_i2b1,
   { &search130_0.value },
   NULL,
};

   /* replace567 -> replace72_0 in the cache */

   /* search568_0_0 -> search0_0 in the cache */
static const nir_search_expression search568_0 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_b2f,
   { &search0_0.value },
   NULL,
};
static const nir_search_expression search568 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_f2b32,
   { &search568_0.value },
   NULL,
};

   /* replace568 -> search0_0 in the cache */

   /* search569_0_0 -> search0_0 in the cache */
/* search569_0 -> search397_0 in the cache */
/* search569 -> search397 in the cache */

   /* replace569 -> search0_0 in the cache */

   /* search570_0_0 -> search6_0 in the cache */
/* search570_0 -> search200_0 in the cache */
static const nir_search_expression search570 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_f2f,
   { &search200_0.value },
   NULL,
};

   /* replace570_0 -> search6_0 in the cache */
/* replace570 -> search200_0 in the cache */

   /* search571_0_0 -> search6_0 in the cache */
/* search571_0 -> search200_0 in the cache */
static const nir_search_expression search571 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_f2u,
   { &search200_0.value },
   NULL,
};

   /* replace571_0 -> search6_0 in the cache */
/* replace571 -> search393_0_0 in the cache */

   /* search572_0_0 -> search6_0 in the cache */
/* search572_0 -> search200_0 in the cache */
static const nir_search_expression search572 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_f2i,
   { &search200_0.value },
   NULL,
};

   /* replace572_0 -> search6_0 in the cache */
/* replace572 -> search393_0_0 in the cache */

   /* search573_0_0 -> search6_0 in the cache */
/* search573_0 -> search393_0_0 in the cache */
static const nir_search_expression search573 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_u2f,
   { &search393_0_0.value },
   NULL,
};

   /* replace573_0 -> search6_0 in the cache */
/* replace573 -> search200_0 in the cache */

   /* search574_0_0 -> search6_0 in the cache */
/* search574_0 -> search393_0_0 in the cache */
static const nir_search_expression search574 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_u2u,
   { &search393_0_0.value },
   NULL,
};

   /* replace574_0 -> search6_0 in the cache */
/* replace574 -> search393_0_0 in the cache */

   /* search575_0_0 -> search6_0 in the cache */
/* search575_0 -> search393_0_0 in the cache */
static const nir_search_expression search575 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_i2f,
   { &search393_0_0.value },
   NULL,
};

   /* replace575_0 -> search6_0 in the cache */
/* replace575 -> search200_0 in the cache */

   /* search576_0_0 -> search6_0 in the cache */
/* search576_0 -> search393_0_0 in the cache */
static const nir_search_expression search576 = {
   { nir_search_value_expression, 0 },
   false,
   -1, 0,
   nir_search_op_i2i,
   { &search393_0_0.value },
   NULL,
};

   /* replace576_0 -> search6_0 in the cache */
/* replace576 -> search393_0_0 in the cache */

   /* search577_0 -> replace72_0 in the cache */
static const nir_search_expression search577 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_i2i1,
   { &replace72_0.value },
   NULL,
};

   /* replace577 -> replace72_0 in the cache */

   /* search578_0 -> search538_0 in the cache */
static const nir_search_expression search578 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_i2i8,
   { &search538_0.value },
   NULL,
};

   /* replace578 -> search538_0 in the cache */

   /* search579_0 -> search56_0 in the cache */
static const nir_search_expression search579 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_i2i16,
   { &search56_0.value },
   NULL,
};

   /* replace579 -> search56_0 in the cache */

   /* search580_0 -> search0_0 in the cache */
static const nir_search_expression search580 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2i32,
   { &search0_0.value },
   NULL,
};

   /* replace580 -> search0_0 in the cache */

   /* search581_0 -> search58_0 in the cache */
static const nir_search_expression search581 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &search58_0.value },
   NULL,
};

   /* replace581 -> search58_0 in the cache */

   /* search582_0 -> replace72_0 in the cache */
static const nir_search_expression search582 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_u2u1,
   { &replace72_0.value },
   NULL,
};

   /* replace582 -> replace72_0 in the cache */

   /* search583_0 -> search538_0 in the cache */
static const nir_search_expression search583 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_u2u8,
   { &search538_0.value },
   NULL,
};

   /* replace583 -> search538_0 in the cache */

   /* search584_0 -> search56_0 in the cache */
static const nir_search_expression search584 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_u2u16,
   { &search56_0.value },
   NULL,
};

   /* replace584 -> search56_0 in the cache */

   /* search585_0 -> search0_0 in the cache */
static const nir_search_expression search585 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2u32,
   { &search0_0.value },
   NULL,
};

   /* replace585 -> search0_0 in the cache */

   /* search586_0 -> search58_0 in the cache */
static const nir_search_expression search586 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &search58_0.value },
   NULL,
};

   /* replace586 -> search58_0 in the cache */

   /* search587_0 -> search56_0 in the cache */
static const nir_search_expression search587 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_f2f16,
   { &search56_0.value },
   NULL,
};

   /* replace587 -> search56_0 in the cache */

   /* search588_0 -> search0_0 in the cache */
static const nir_search_expression search588 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_f2f32,
   { &search0_0.value },
   NULL,
};

   /* replace588 -> search0_0 in the cache */

   /* search589_0 -> search58_0 in the cache */
static const nir_search_expression search589 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_f2f64,
   { &search58_0.value },
   NULL,
};

   /* replace589 -> search58_0 in the cache */

   /* search590_0_0 -> search6_0 in the cache */
static const nir_search_expression search590_0 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_i2i8,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search590 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_i2i1,
   { &search590_0.value },
   NULL,
};

   /* replace590_0 -> search6_0 in the cache */
static const nir_search_expression replace590 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_i2i1,
   { &search6_0.value },
   NULL,
};

   /* search591_0_0 -> search6_0 in the cache */
static const nir_search_expression search591_0 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_u2u8,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search591 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_i2i1,
   { &search591_0.value },
   NULL,
};

   /* replace591_0 -> search6_0 in the cache */
static const nir_search_expression replace591 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_u2u1,
   { &search6_0.value },
   NULL,
};

   /* search592_0_0 -> search6_0 in the cache */
/* search592_0 -> search590_0 in the cache */
static const nir_search_expression search592 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_u2u1,
   { &search590_0.value },
   NULL,
};

   /* replace592_0 -> search6_0 in the cache */
/* replace592 -> replace590 in the cache */

   /* search593_0_0 -> search6_0 in the cache */
/* search593_0 -> search591_0 in the cache */
static const nir_search_expression search593 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_u2u1,
   { &search591_0.value },
   NULL,
};

   /* replace593_0 -> search6_0 in the cache */
/* replace593 -> replace591 in the cache */

   /* search594_0_0 -> search6_0 in the cache */
static const nir_search_expression search594_0 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_i2i16,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search594 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_i2i1,
   { &search594_0.value },
   NULL,
};

   /* replace594_0 -> search6_0 in the cache */
/* replace594 -> replace590 in the cache */

   /* search595_0_0 -> search6_0 in the cache */
static const nir_search_expression search595_0 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_u2u16,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search595 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_i2i1,
   { &search595_0.value },
   NULL,
};

   /* replace595_0 -> search6_0 in the cache */
/* replace595 -> replace591 in the cache */

   /* search596_0_0 -> search6_0 in the cache */
/* search596_0 -> search594_0 in the cache */
static const nir_search_expression search596 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_u2u1,
   { &search594_0.value },
   NULL,
};

   /* replace596_0 -> search6_0 in the cache */
/* replace596 -> replace590 in the cache */

   /* search597_0_0 -> search6_0 in the cache */
/* search597_0 -> search595_0 in the cache */
static const nir_search_expression search597 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_u2u1,
   { &search595_0.value },
   NULL,
};

   /* replace597_0 -> search6_0 in the cache */
/* replace597 -> replace591 in the cache */

   /* search598_0_0 -> search6_0 in the cache */
static const nir_search_expression search598_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2i32,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search598 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_i2i1,
   { &search598_0.value },
   NULL,
};

   /* replace598_0 -> search6_0 in the cache */
/* replace598 -> replace590 in the cache */

   /* search599_0_0 -> search6_0 in the cache */
static const nir_search_expression search599_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2u32,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search599 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_i2i1,
   { &search599_0.value },
   NULL,
};

   /* replace599_0 -> search6_0 in the cache */
/* replace599 -> replace591 in the cache */

   /* search600_0_0 -> search6_0 in the cache */
/* search600_0 -> search598_0 in the cache */
static const nir_search_expression search600 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_u2u1,
   { &search598_0.value },
   NULL,
};

   /* replace600_0 -> search6_0 in the cache */
/* replace600 -> replace590 in the cache */

   /* search601_0_0 -> search6_0 in the cache */
/* search601_0 -> search599_0 in the cache */
static const nir_search_expression search601 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_u2u1,
   { &search599_0.value },
   NULL,
};

   /* replace601_0 -> search6_0 in the cache */
/* replace601 -> replace591 in the cache */

   /* search602_0_0 -> search6_0 in the cache */
static const nir_search_expression search602_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search602 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_i2i1,
   { &search602_0.value },
   NULL,
};

   /* replace602_0 -> search6_0 in the cache */
/* replace602 -> replace590 in the cache */

   /* search603_0_0 -> search6_0 in the cache */
static const nir_search_expression search603_0 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &search6_0.value },
   NULL,
};
static const nir_search_expression search603 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_i2i1,
   { &search603_0.value },
   NULL,
};

   /* replace603_0 -> search6_0 in the cache */
/* replace603 -> replace591 in the cache */

   /* search604_0_0 -> search6_0 in the cache */
/* search604_0 -> search602_0 in the cache */
static const nir_search_expression search604 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_u2u1,
   { &search602_0.value },
   NULL,
};

   /* replace604_0 -> search6_0 in the cache */
/* replace604 -> replace590 in the cache */

   /* search605_0_0 -> search6_0 in the cache */
/* search605_0 -> search603_0 in the cache */
static const nir_search_expression search605 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_u2u1,
   { &search603_0.value },
   NULL,
};

   /* replace605_0 -> search6_0 in the cache */
/* replace605 -> replace591 in the cache */

   /* search606_0_0 -> replace72_0 in the cache */
/* search606_0 -> search577 in the cache */
static const nir_search_expression search606 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_i2i8,
   { &search577.value },
   NULL,
};

   /* replace606_0 -> replace72_0 in the cache */
static const nir_search_expression replace606 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_i2i8,
   { &replace72_0.value },
   NULL,
};

   /* search607_0_0 -> replace72_0 in the cache */
/* search607_0 -> search582 in the cache */
static const nir_search_expression search607 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_u2u8,
   { &search582.value },
   NULL,
};

   /* replace607_0 -> replace72_0 in the cache */
static const nir_search_expression replace607 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_u2u8,
   { &replace72_0.value },
   NULL,
};

   /* search608_0_0 -> search6_0 in the cache */
/* search608_0 -> search594_0 in the cache */
static const nir_search_expression search608 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_i2i8,
   { &search594_0.value },
   NULL,
};

   /* replace608_0 -> search6_0 in the cache */
/* replace608 -> search590_0 in the cache */

   /* search609_0_0 -> search6_0 in the cache */
/* search609_0 -> search595_0 in the cache */
static const nir_search_expression search609 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_i2i8,
   { &search595_0.value },
   NULL,
};

   /* replace609_0 -> search6_0 in the cache */
/* replace609 -> search591_0 in the cache */

   /* search610_0_0 -> search6_0 in the cache */
/* search610_0 -> search594_0 in the cache */
static const nir_search_expression search610 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_u2u8,
   { &search594_0.value },
   NULL,
};

   /* replace610_0 -> search6_0 in the cache */
/* replace610 -> search590_0 in the cache */

   /* search611_0_0 -> search6_0 in the cache */
/* search611_0 -> search595_0 in the cache */
static const nir_search_expression search611 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_u2u8,
   { &search595_0.value },
   NULL,
};

   /* replace611_0 -> search6_0 in the cache */
/* replace611 -> search591_0 in the cache */

   /* search612_0_0 -> search6_0 in the cache */
/* search612_0 -> search598_0 in the cache */
static const nir_search_expression search612 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_i2i8,
   { &search598_0.value },
   NULL,
};

   /* replace612_0 -> search6_0 in the cache */
/* replace612 -> search590_0 in the cache */

   /* search613_0_0 -> search6_0 in the cache */
/* search613_0 -> search599_0 in the cache */
static const nir_search_expression search613 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_i2i8,
   { &search599_0.value },
   NULL,
};

   /* replace613_0 -> search6_0 in the cache */
/* replace613 -> search591_0 in the cache */

   /* search614_0_0 -> search6_0 in the cache */
/* search614_0 -> search598_0 in the cache */
static const nir_search_expression search614 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_u2u8,
   { &search598_0.value },
   NULL,
};

   /* replace614_0 -> search6_0 in the cache */
/* replace614 -> search590_0 in the cache */

   /* search615_0_0 -> search6_0 in the cache */
/* search615_0 -> search599_0 in the cache */
static const nir_search_expression search615 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_u2u8,
   { &search599_0.value },
   NULL,
};

   /* replace615_0 -> search6_0 in the cache */
/* replace615 -> search591_0 in the cache */

   /* search616_0_0 -> search6_0 in the cache */
/* search616_0 -> search602_0 in the cache */
static const nir_search_expression search616 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_i2i8,
   { &search602_0.value },
   NULL,
};

   /* replace616_0 -> search6_0 in the cache */
/* replace616 -> search590_0 in the cache */

   /* search617_0_0 -> search6_0 in the cache */
/* search617_0 -> search603_0 in the cache */
static const nir_search_expression search617 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_i2i8,
   { &search603_0.value },
   NULL,
};

   /* replace617_0 -> search6_0 in the cache */
/* replace617 -> search591_0 in the cache */

   /* search618_0_0 -> search6_0 in the cache */
/* search618_0 -> search602_0 in the cache */
static const nir_search_expression search618 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_u2u8,
   { &search602_0.value },
   NULL,
};

   /* replace618_0 -> search6_0 in the cache */
/* replace618 -> search590_0 in the cache */

   /* search619_0_0 -> search6_0 in the cache */
/* search619_0 -> search603_0 in the cache */
static const nir_search_expression search619 = {
   { nir_search_value_expression, 8 },
   false,
   -1, 0,
   nir_op_u2u8,
   { &search603_0.value },
   NULL,
};

   /* replace619_0 -> search6_0 in the cache */
/* replace619 -> search591_0 in the cache */

   /* search620_0_0 -> replace72_0 in the cache */
/* search620_0 -> search577 in the cache */
static const nir_search_expression search620 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_i2i16,
   { &search577.value },
   NULL,
};

   /* replace620_0 -> replace72_0 in the cache */
static const nir_search_expression replace620 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_i2i16,
   { &replace72_0.value },
   NULL,
};

   /* search621_0_0 -> replace72_0 in the cache */
/* search621_0 -> search582 in the cache */
static const nir_search_expression search621 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_u2u16,
   { &search582.value },
   NULL,
};

   /* replace621_0 -> replace72_0 in the cache */
static const nir_search_expression replace621 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_u2u16,
   { &replace72_0.value },
   NULL,
};

   /* search622_0_0 -> replace72_0 in the cache */
/* search622_0 -> replace606 in the cache */
static const nir_search_expression search622 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_i2i16,
   { &replace606.value },
   NULL,
};

   /* replace622_0 -> replace72_0 in the cache */
/* replace622 -> replace620 in the cache */

   /* search623_0_0 -> replace72_0 in the cache */
/* search623_0 -> replace607 in the cache */
static const nir_search_expression search623 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_u2u16,
   { &replace607.value },
   NULL,
};

   /* replace623_0 -> replace72_0 in the cache */
/* replace623 -> replace621 in the cache */

   /* search624_0_0 -> search538_0 in the cache */
/* search624_0 -> search578 in the cache */
static const nir_search_expression search624 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_i2i16,
   { &search578.value },
   NULL,
};

   /* replace624_0 -> search538_0 in the cache */
static const nir_search_expression replace624 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_i2i16,
   { &search538_0.value },
   NULL,
};

   /* search625_0_0 -> search538_0 in the cache */
/* search625_0 -> search583 in the cache */
static const nir_search_expression search625 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_u2u16,
   { &search583.value },
   NULL,
};

   /* replace625_0 -> search538_0 in the cache */
static const nir_search_expression replace625 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_u2u16,
   { &search538_0.value },
   NULL,
};

   /* search626_0_0 -> search6_0 in the cache */
/* search626_0 -> search598_0 in the cache */
static const nir_search_expression search626 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_i2i16,
   { &search598_0.value },
   NULL,
};

   /* replace626_0 -> search6_0 in the cache */
/* replace626 -> search594_0 in the cache */

   /* search627_0_0 -> search6_0 in the cache */
/* search627_0 -> search599_0 in the cache */
static const nir_search_expression search627 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_i2i16,
   { &search599_0.value },
   NULL,
};

   /* replace627_0 -> search6_0 in the cache */
/* replace627 -> search595_0 in the cache */

   /* search628_0_0 -> search6_0 in the cache */
/* search628_0 -> search598_0 in the cache */
static const nir_search_expression search628 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_u2u16,
   { &search598_0.value },
   NULL,
};

   /* replace628_0 -> search6_0 in the cache */
/* replace628 -> search594_0 in the cache */

   /* search629_0_0 -> search6_0 in the cache */
/* search629_0 -> search599_0 in the cache */
static const nir_search_expression search629 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_u2u16,
   { &search599_0.value },
   NULL,
};

   /* replace629_0 -> search6_0 in the cache */
/* replace629 -> search595_0 in the cache */

   /* search630_0_0 -> search6_0 in the cache */
/* search630_0 -> search602_0 in the cache */
static const nir_search_expression search630 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_i2i16,
   { &search602_0.value },
   NULL,
};

   /* replace630_0 -> search6_0 in the cache */
/* replace630 -> search594_0 in the cache */

   /* search631_0_0 -> search6_0 in the cache */
/* search631_0 -> search603_0 in the cache */
static const nir_search_expression search631 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_i2i16,
   { &search603_0.value },
   NULL,
};

   /* replace631_0 -> search6_0 in the cache */
/* replace631 -> search595_0 in the cache */

   /* search632_0_0 -> search6_0 in the cache */
/* search632_0 -> search602_0 in the cache */
static const nir_search_expression search632 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_u2u16,
   { &search602_0.value },
   NULL,
};

   /* replace632_0 -> search6_0 in the cache */
/* replace632 -> search594_0 in the cache */

   /* search633_0_0 -> search6_0 in the cache */
/* search633_0 -> search603_0 in the cache */
static const nir_search_expression search633 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_u2u16,
   { &search603_0.value },
   NULL,
};

   /* replace633_0 -> search6_0 in the cache */
/* replace633 -> search595_0 in the cache */

   /* search634_0_0 -> replace72_0 in the cache */
/* search634_0 -> search577 in the cache */
static const nir_search_expression search634 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2i32,
   { &search577.value },
   NULL,
};

   /* replace634_0 -> replace72_0 in the cache */
static const nir_search_expression replace634 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2i32,
   { &replace72_0.value },
   NULL,
};

   /* search635_0_0 -> replace72_0 in the cache */
/* search635_0 -> search582 in the cache */
static const nir_search_expression search635 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2u32,
   { &search582.value },
   NULL,
};

   /* replace635_0 -> replace72_0 in the cache */
static const nir_search_expression replace635 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2u32,
   { &replace72_0.value },
   NULL,
};

   /* search636_0_0 -> replace72_0 in the cache */
/* search636_0 -> replace606 in the cache */
static const nir_search_expression search636 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2i32,
   { &replace606.value },
   NULL,
};

   /* replace636_0 -> replace72_0 in the cache */
/* replace636 -> replace634 in the cache */

   /* search637_0_0 -> replace72_0 in the cache */
/* search637_0 -> replace607 in the cache */
static const nir_search_expression search637 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2u32,
   { &replace607.value },
   NULL,
};

   /* replace637_0 -> replace72_0 in the cache */
/* replace637 -> replace635 in the cache */

   /* search638_0_0 -> search538_0 in the cache */
/* search638_0 -> search578 in the cache */
static const nir_search_expression search638 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2i32,
   { &search578.value },
   NULL,
};

   /* replace638_0 -> search538_0 in the cache */
static const nir_search_expression replace638 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2i32,
   { &search538_0.value },
   NULL,
};

   /* search639_0_0 -> search538_0 in the cache */
/* search639_0 -> search583 in the cache */
static const nir_search_expression search639 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2u32,
   { &search583.value },
   NULL,
};

   /* replace639_0 -> search538_0 in the cache */
static const nir_search_expression replace639 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2u32,
   { &search538_0.value },
   NULL,
};

   /* search640_0_0 -> replace72_0 in the cache */
/* search640_0 -> replace620 in the cache */
static const nir_search_expression search640 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2i32,
   { &replace620.value },
   NULL,
};

   /* replace640_0 -> replace72_0 in the cache */
/* replace640 -> replace634 in the cache */

   /* search641_0_0 -> replace72_0 in the cache */
/* search641_0 -> replace621 in the cache */
static const nir_search_expression search641 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2u32,
   { &replace621.value },
   NULL,
};

   /* replace641_0 -> replace72_0 in the cache */
/* replace641 -> replace635 in the cache */

   /* search642_0_0 -> search538_0 in the cache */
/* search642_0 -> replace624 in the cache */
static const nir_search_expression search642 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2i32,
   { &replace624.value },
   NULL,
};

   /* replace642_0 -> search538_0 in the cache */
/* replace642 -> replace638 in the cache */

   /* search643_0_0 -> search538_0 in the cache */
/* search643_0 -> replace625 in the cache */
static const nir_search_expression search643 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2u32,
   { &replace625.value },
   NULL,
};

   /* replace643_0 -> search538_0 in the cache */
/* replace643 -> replace639 in the cache */

   /* search644_0_0 -> search56_0 in the cache */
/* search644_0 -> search579 in the cache */
static const nir_search_expression search644 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2i32,
   { &search579.value },
   NULL,
};

   /* replace644_0 -> search56_0 in the cache */
static const nir_search_expression replace644 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2i32,
   { &search56_0.value },
   NULL,
};

   /* search645_0_0 -> search56_0 in the cache */
/* search645_0 -> search584 in the cache */
static const nir_search_expression search645 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2u32,
   { &search584.value },
   NULL,
};

   /* replace645_0 -> search56_0 in the cache */
static const nir_search_expression replace645 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2u32,
   { &search56_0.value },
   NULL,
};

   /* search646_0_0 -> search6_0 in the cache */
/* search646_0 -> search602_0 in the cache */
static const nir_search_expression search646 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2i32,
   { &search602_0.value },
   NULL,
};

   /* replace646_0 -> search6_0 in the cache */
/* replace646 -> search598_0 in the cache */

   /* search647_0_0 -> search6_0 in the cache */
/* search647_0 -> search603_0 in the cache */
static const nir_search_expression search647 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_i2i32,
   { &search603_0.value },
   NULL,
};

   /* replace647_0 -> search6_0 in the cache */
/* replace647 -> search599_0 in the cache */

   /* search648_0_0 -> search6_0 in the cache */
/* search648_0 -> search602_0 in the cache */
static const nir_search_expression search648 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2u32,
   { &search602_0.value },
   NULL,
};

   /* replace648_0 -> search6_0 in the cache */
/* replace648 -> search598_0 in the cache */

   /* search649_0_0 -> search6_0 in the cache */
/* search649_0 -> search603_0 in the cache */
static const nir_search_expression search649 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_u2u32,
   { &search603_0.value },
   NULL,
};

   /* replace649_0 -> search6_0 in the cache */
/* replace649 -> search599_0 in the cache */

   /* search650_0_0 -> replace72_0 in the cache */
/* search650_0 -> search577 in the cache */
static const nir_search_expression search650 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &search577.value },
   NULL,
};

   /* replace650_0 -> replace72_0 in the cache */
static const nir_search_expression replace650 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &replace72_0.value },
   NULL,
};

   /* search651_0_0 -> replace72_0 in the cache */
/* search651_0 -> search582 in the cache */
static const nir_search_expression search651 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &search582.value },
   NULL,
};

   /* replace651_0 -> replace72_0 in the cache */
static const nir_search_expression replace651 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &replace72_0.value },
   NULL,
};

   /* search652_0_0 -> replace72_0 in the cache */
/* search652_0 -> replace606 in the cache */
static const nir_search_expression search652 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &replace606.value },
   NULL,
};

   /* replace652_0 -> replace72_0 in the cache */
/* replace652 -> replace650 in the cache */

   /* search653_0_0 -> replace72_0 in the cache */
/* search653_0 -> replace607 in the cache */
static const nir_search_expression search653 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &replace607.value },
   NULL,
};

   /* replace653_0 -> replace72_0 in the cache */
/* replace653 -> replace651 in the cache */

   /* search654_0_0 -> search538_0 in the cache */
/* search654_0 -> search578 in the cache */
static const nir_search_expression search654 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &search578.value },
   NULL,
};

   /* replace654_0 -> search538_0 in the cache */
static const nir_search_expression replace654 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &search538_0.value },
   NULL,
};

   /* search655_0_0 -> search538_0 in the cache */
/* search655_0 -> search583 in the cache */
static const nir_search_expression search655 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &search583.value },
   NULL,
};

   /* replace655_0 -> search538_0 in the cache */
static const nir_search_expression replace655 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &search538_0.value },
   NULL,
};

   /* search656_0_0 -> replace72_0 in the cache */
/* search656_0 -> replace620 in the cache */
static const nir_search_expression search656 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &replace620.value },
   NULL,
};

   /* replace656_0 -> replace72_0 in the cache */
/* replace656 -> replace650 in the cache */

   /* search657_0_0 -> replace72_0 in the cache */
/* search657_0 -> replace621 in the cache */
static const nir_search_expression search657 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &replace621.value },
   NULL,
};

   /* replace657_0 -> replace72_0 in the cache */
/* replace657 -> replace651 in the cache */

   /* search658_0_0 -> search538_0 in the cache */
/* search658_0 -> replace624 in the cache */
static const nir_search_expression search658 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &replace624.value },
   NULL,
};

   /* replace658_0 -> search538_0 in the cache */
/* replace658 -> replace654 in the cache */

   /* search659_0_0 -> search538_0 in the cache */
/* search659_0 -> replace625 in the cache */
static const nir_search_expression search659 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &replace625.value },
   NULL,
};

   /* replace659_0 -> search538_0 in the cache */
/* replace659 -> replace655 in the cache */

   /* search660_0_0 -> search56_0 in the cache */
/* search660_0 -> search579 in the cache */
static const nir_search_expression search660 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &search579.value },
   NULL,
};

   /* replace660_0 -> search56_0 in the cache */
static const nir_search_expression replace660 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &search56_0.value },
   NULL,
};

   /* search661_0_0 -> search56_0 in the cache */
/* search661_0 -> search584 in the cache */
static const nir_search_expression search661 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &search584.value },
   NULL,
};

   /* replace661_0 -> search56_0 in the cache */
static const nir_search_expression replace661 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &search56_0.value },
   NULL,
};

   /* search662_0_0 -> replace72_0 in the cache */
/* search662_0 -> replace634 in the cache */
static const nir_search_expression search662 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &replace634.value },
   NULL,
};

   /* replace662_0 -> replace72_0 in the cache */
/* replace662 -> replace650 in the cache */

   /* search663_0_0 -> replace72_0 in the cache */
/* search663_0 -> replace635 in the cache */
static const nir_search_expression search663 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &replace635.value },
   NULL,
};

   /* replace663_0 -> replace72_0 in the cache */
/* replace663 -> replace651 in the cache */

   /* search664_0_0 -> search538_0 in the cache */
/* search664_0 -> replace638 in the cache */
static const nir_search_expression search664 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &replace638.value },
   NULL,
};

   /* replace664_0 -> search538_0 in the cache */
/* replace664 -> replace654 in the cache */

   /* search665_0_0 -> search538_0 in the cache */
/* search665_0 -> replace639 in the cache */
static const nir_search_expression search665 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &replace639.value },
   NULL,
};

   /* replace665_0 -> search538_0 in the cache */
/* replace665 -> replace655 in the cache */

   /* search666_0_0 -> search56_0 in the cache */
/* search666_0 -> replace644 in the cache */
static const nir_search_expression search666 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &replace644.value },
   NULL,
};

   /* replace666_0 -> search56_0 in the cache */
/* replace666 -> replace660 in the cache */

   /* search667_0_0 -> search56_0 in the cache */
/* search667_0 -> replace645 in the cache */
static const nir_search_expression search667 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &replace645.value },
   NULL,
};

   /* replace667_0 -> search56_0 in the cache */
/* replace667 -> replace661 in the cache */

   /* search668_0_0 -> search0_0 in the cache */
/* search668_0 -> search580 in the cache */
static const nir_search_expression search668 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &search580.value },
   NULL,
};

   /* replace668_0 -> search0_0 in the cache */
static const nir_search_expression replace668 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_i2i64,
   { &search0_0.value },
   NULL,
};

   /* search669_0_0 -> search0_0 in the cache */
/* search669_0 -> search585 in the cache */
static const nir_search_expression search669 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &search585.value },
   NULL,
};

   /* replace669_0 -> search0_0 in the cache */
static const nir_search_expression replace669 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_u2u64,
   { &search0_0.value },
   NULL,
};

   static const nir_search_variable search670_0 = {
   { nir_search_value_variable, 16 },
   0, /* x */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search670_1 = {
   { nir_search_value_variable, 32 },
   1, /* exp */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search670 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 0,
   nir_op_ldexp,
   { &search670_0.value, &search670_1.value },
   NULL,
};

   /* replace670_0_0 -> search670_0 in the cache */

/* replace670_0_1_0_0_0_0_0_0 -> search670_1 in the cache */

static const nir_search_constant replace670_0_1_0_0_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { -0x1c /* -28 */ },
};
static const nir_search_expression replace670_0_1_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   4, 1,
   nir_op_imax,
   { &search670_1.value, &replace670_0_1_0_0_0_0_0_1.value },
   NULL,
};

static const nir_search_constant replace670_0_1_0_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x1e /* 30 */ },
};
static const nir_search_expression replace670_0_1_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   3, 2,
   nir_op_imin,
   { &replace670_0_1_0_0_0_0_0.value, &replace670_0_1_0_0_0_0_1.value },
   NULL,
};

/* replace670_0_1_0_0_0_1 -> replace424_1 in the cache */
static const nir_search_expression replace670_0_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishr,
   { &replace670_0_1_0_0_0_0.value, &replace424_1.value },
   NULL,
};

static const nir_search_constant replace670_0_1_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0xf /* 15 */ },
};
static const nir_search_expression replace670_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   2, 3,
   nir_op_iadd,
   { &replace670_0_1_0_0_0.value, &replace670_0_1_0_0_1.value },
   NULL,
};

static const nir_search_constant replace670_0_1_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0xa /* 10 */ },
};
static const nir_search_expression replace670_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 3,
   nir_op_ishl,
   { &replace670_0_1_0_0.value, &replace670_0_1_0_1.value },
   NULL,
};
static const nir_search_expression replace670_0_1 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 3,
   nir_op_i2i16,
   { &replace670_0_1_0.value },
   NULL,
};
static const nir_search_expression replace670_0 = {
   { nir_search_value_expression, 16 },
   false,
   1, 4,
   nir_op_fmul,
   { &search670_0.value, &replace670_0_1.value },
   NULL,
};

/* replace670_1_0_0_0_0_0_0 -> search670_1 in the cache */

/* replace670_1_0_0_0_0_0_1 -> replace670_0_1_0_0_0_0_0_1 in the cache */
static const nir_search_expression replace670_1_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   7, 1,
   nir_op_imax,
   { &search670_1.value, &replace670_0_1_0_0_0_0_0_1.value },
   NULL,
};

/* replace670_1_0_0_0_0_1 -> replace670_0_1_0_0_0_0_1 in the cache */
static const nir_search_expression replace670_1_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   6, 2,
   nir_op_imin,
   { &replace670_1_0_0_0_0_0.value, &replace670_0_1_0_0_0_0_1.value },
   NULL,
};

/* replace670_1_0_0_0_1_0_0_0 -> search670_1 in the cache */

/* replace670_1_0_0_0_1_0_0_1 -> replace670_0_1_0_0_0_0_0_1 in the cache */
static const nir_search_expression replace670_1_0_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   9, 1,
   nir_op_imax,
   { &search670_1.value, &replace670_0_1_0_0_0_0_0_1.value },
   NULL,
};

/* replace670_1_0_0_0_1_0_1 -> replace670_0_1_0_0_0_0_1 in the cache */
static const nir_search_expression replace670_1_0_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   8, 2,
   nir_op_imin,
   { &replace670_1_0_0_0_1_0_0.value, &replace670_0_1_0_0_0_0_1.value },
   NULL,
};

/* replace670_1_0_0_0_1_1 -> replace424_1 in the cache */
static const nir_search_expression replace670_1_0_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishr,
   { &replace670_1_0_0_0_1_0.value, &replace424_1.value },
   NULL,
};
static const nir_search_expression replace670_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 4,
   nir_op_isub,
   { &replace670_1_0_0_0_0.value, &replace670_1_0_0_0_1.value },
   NULL,
};

/* replace670_1_0_0_1 -> replace670_0_1_0_0_1 in the cache */
static const nir_search_expression replace670_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   5, 5,
   nir_op_iadd,
   { &replace670_1_0_0_0.value, &replace670_0_1_0_0_1.value },
   NULL,
};

/* replace670_1_0_1 -> replace670_0_1_0_1 in the cache */
static const nir_search_expression replace670_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 5,
   nir_op_ishl,
   { &replace670_1_0_0.value, &replace670_0_1_0_1.value },
   NULL,
};
static const nir_search_expression replace670_1 = {
   { nir_search_value_expression, 16 },
   false,
   -1, 5,
   nir_op_i2i16,
   { &replace670_1_0.value },
   NULL,
};
static const nir_search_expression replace670 = {
   { nir_search_value_expression, 16 },
   false,
   0, 10,
   nir_op_fmul,
   { &replace670_0.value, &replace670_1.value },
   NULL,
};

   static const nir_search_variable search671_0 = {
   { nir_search_value_variable, 32 },
   0, /* x */
   false,
   nir_type_invalid,
   NULL,
};

/* search671_1 -> search670_1 in the cache */
static const nir_search_expression search671 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ldexp,
   { &search671_0.value, &search670_1.value },
   NULL,
};

   /* replace671_0_0 -> search671_0 in the cache */

/* replace671_0_1_0_0_0_0_0 -> search670_1 in the cache */

static const nir_search_constant replace671_0_1_0_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { -0xfc /* -252 */ },
};
static const nir_search_expression replace671_0_1_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   4, 1,
   nir_op_imax,
   { &search670_1.value, &replace671_0_1_0_0_0_0_1.value },
   NULL,
};

static const nir_search_constant replace671_0_1_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0xfe /* 254 */ },
};
static const nir_search_expression replace671_0_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   3, 2,
   nir_op_imin,
   { &replace671_0_1_0_0_0_0.value, &replace671_0_1_0_0_0_1.value },
   NULL,
};

/* replace671_0_1_0_0_1 -> replace424_1 in the cache */
static const nir_search_expression replace671_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishr,
   { &replace671_0_1_0_0_0.value, &replace424_1.value },
   NULL,
};

static const nir_search_constant replace671_0_1_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x7f /* 127 */ },
};
static const nir_search_expression replace671_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   2, 3,
   nir_op_iadd,
   { &replace671_0_1_0_0.value, &replace671_0_1_0_1.value },
   NULL,
};

static const nir_search_constant replace671_0_1_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x17 /* 23 */ },
};
static const nir_search_expression replace671_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 3,
   nir_op_ishl,
   { &replace671_0_1_0.value, &replace671_0_1_1.value },
   NULL,
};
static const nir_search_expression replace671_0 = {
   { nir_search_value_expression, 32 },
   false,
   1, 4,
   nir_op_fmul,
   { &search671_0.value, &replace671_0_1.value },
   NULL,
};

/* replace671_1_0_0_0_0_0 -> search670_1 in the cache */

/* replace671_1_0_0_0_0_1 -> replace671_0_1_0_0_0_0_1 in the cache */
static const nir_search_expression replace671_1_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   7, 1,
   nir_op_imax,
   { &search670_1.value, &replace671_0_1_0_0_0_0_1.value },
   NULL,
};

/* replace671_1_0_0_0_1 -> replace671_0_1_0_0_0_1 in the cache */
static const nir_search_expression replace671_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   6, 2,
   nir_op_imin,
   { &replace671_1_0_0_0_0.value, &replace671_0_1_0_0_0_1.value },
   NULL,
};

/* replace671_1_0_0_1_0_0_0 -> search670_1 in the cache */

/* replace671_1_0_0_1_0_0_1 -> replace671_0_1_0_0_0_0_1 in the cache */
static const nir_search_expression replace671_1_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   9, 1,
   nir_op_imax,
   { &search670_1.value, &replace671_0_1_0_0_0_0_1.value },
   NULL,
};

/* replace671_1_0_0_1_0_1 -> replace671_0_1_0_0_0_1 in the cache */
static const nir_search_expression replace671_1_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   8, 2,
   nir_op_imin,
   { &replace671_1_0_0_1_0_0.value, &replace671_0_1_0_0_0_1.value },
   NULL,
};

/* replace671_1_0_0_1_1 -> replace424_1 in the cache */
static const nir_search_expression replace671_1_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishr,
   { &replace671_1_0_0_1_0.value, &replace424_1.value },
   NULL,
};
static const nir_search_expression replace671_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 4,
   nir_op_isub,
   { &replace671_1_0_0_0.value, &replace671_1_0_0_1.value },
   NULL,
};

/* replace671_1_0_1 -> replace671_0_1_0_1 in the cache */
static const nir_search_expression replace671_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   5, 5,
   nir_op_iadd,
   { &replace671_1_0_0.value, &replace671_0_1_0_1.value },
   NULL,
};

/* replace671_1_1 -> replace671_0_1_1 in the cache */
static const nir_search_expression replace671_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 5,
   nir_op_ishl,
   { &replace671_1_0.value, &replace671_0_1_1.value },
   NULL,
};
static const nir_search_expression replace671 = {
   { nir_search_value_expression, 32 },
   false,
   0, 10,
   nir_op_fmul,
   { &replace671_0.value, &replace671_1.value },
   NULL,
};

   static const nir_search_variable search672_0 = {
   { nir_search_value_variable, 64 },
   0, /* x */
   false,
   nir_type_invalid,
   NULL,
};

/* search672_1 -> search670_1 in the cache */
static const nir_search_expression search672 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 0,
   nir_op_ldexp,
   { &search672_0.value, &search670_1.value },
   NULL,
};

   /* replace672_0_0 -> search672_0 in the cache */

/* replace672_0_1_0 -> search25_1 in the cache */

/* replace672_0_1_1_0_0_0_0_0 -> search670_1 in the cache */

static const nir_search_constant replace672_0_1_1_0_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { -0x7fc /* -2044 */ },
};
static const nir_search_expression replace672_0_1_1_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   4, 1,
   nir_op_imax,
   { &search670_1.value, &replace672_0_1_1_0_0_0_0_1.value },
   NULL,
};

static const nir_search_constant replace672_0_1_1_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x7fe /* 2046 */ },
};
static const nir_search_expression replace672_0_1_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   3, 2,
   nir_op_imin,
   { &replace672_0_1_1_0_0_0_0.value, &replace672_0_1_1_0_0_0_1.value },
   NULL,
};

/* replace672_0_1_1_0_0_1 -> replace424_1 in the cache */
static const nir_search_expression replace672_0_1_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishr,
   { &replace672_0_1_1_0_0_0.value, &replace424_1.value },
   NULL,
};

static const nir_search_constant replace672_0_1_1_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x3ff /* 1023 */ },
};
static const nir_search_expression replace672_0_1_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   2, 3,
   nir_op_iadd,
   { &replace672_0_1_1_0_0.value, &replace672_0_1_1_0_1.value },
   NULL,
};

static const nir_search_constant replace672_0_1_1_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x14 /* 20 */ },
};
static const nir_search_expression replace672_0_1_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 3,
   nir_op_ishl,
   { &replace672_0_1_1_0.value, &replace672_0_1_1_1.value },
   NULL,
};
static const nir_search_expression replace672_0_1 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 3,
   nir_op_pack_64_2x32_split,
   { &search25_1.value, &replace672_0_1_1.value },
   NULL,
};
static const nir_search_expression replace672_0 = {
   { nir_search_value_expression, 64 },
   false,
   1, 4,
   nir_op_fmul,
   { &search672_0.value, &replace672_0_1.value },
   NULL,
};

/* replace672_1_0 -> search25_1 in the cache */

/* replace672_1_1_0_0_0_0_0 -> search670_1 in the cache */

/* replace672_1_1_0_0_0_0_1 -> replace672_0_1_1_0_0_0_0_1 in the cache */
static const nir_search_expression replace672_1_1_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   7, 1,
   nir_op_imax,
   { &search670_1.value, &replace672_0_1_1_0_0_0_0_1.value },
   NULL,
};

/* replace672_1_1_0_0_0_1 -> replace672_0_1_1_0_0_0_1 in the cache */
static const nir_search_expression replace672_1_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   6, 2,
   nir_op_imin,
   { &replace672_1_1_0_0_0_0.value, &replace672_0_1_1_0_0_0_1.value },
   NULL,
};

/* replace672_1_1_0_0_1_0_0_0 -> search670_1 in the cache */

/* replace672_1_1_0_0_1_0_0_1 -> replace672_0_1_1_0_0_0_0_1 in the cache */
static const nir_search_expression replace672_1_1_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   9, 1,
   nir_op_imax,
   { &search670_1.value, &replace672_0_1_1_0_0_0_0_1.value },
   NULL,
};

/* replace672_1_1_0_0_1_0_1 -> replace672_0_1_1_0_0_0_1 in the cache */
static const nir_search_expression replace672_1_1_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   8, 2,
   nir_op_imin,
   { &replace672_1_1_0_0_1_0_0.value, &replace672_0_1_1_0_0_0_1.value },
   NULL,
};

/* replace672_1_1_0_0_1_1 -> replace424_1 in the cache */
static const nir_search_expression replace672_1_1_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishr,
   { &replace672_1_1_0_0_1_0.value, &replace424_1.value },
   NULL,
};
static const nir_search_expression replace672_1_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 4,
   nir_op_isub,
   { &replace672_1_1_0_0_0.value, &replace672_1_1_0_0_1.value },
   NULL,
};

/* replace672_1_1_0_1 -> replace672_0_1_1_0_1 in the cache */
static const nir_search_expression replace672_1_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   5, 5,
   nir_op_iadd,
   { &replace672_1_1_0_0.value, &replace672_0_1_1_0_1.value },
   NULL,
};

/* replace672_1_1_1 -> replace672_0_1_1_1 in the cache */
static const nir_search_expression replace672_1_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 5,
   nir_op_ishl,
   { &replace672_1_1_0.value, &replace672_0_1_1_1.value },
   NULL,
};
static const nir_search_expression replace672_1 = {
   { nir_search_value_expression, 64 },
   false,
   -1, 5,
   nir_op_pack_64_2x32_split,
   { &search25_1.value, &replace672_1_1.value },
   NULL,
};
static const nir_search_expression replace672 = {
   { nir_search_value_expression, 64 },
   false,
   0, 10,
   nir_op_fmul,
   { &replace672_0.value, &replace672_1.value },
   NULL,
};

   /* search673_0_0_0_0_0_0_0_0_0_0_0_0_0_0 -> search671_0 in the cache */

/* search673_0_0_0_0_0_0_0_0_0_0_0_0_0_1 -> search339_1_1 in the cache */
static const nir_search_expression search673_0_0_0_0_0_0_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ishl,
   { &search671_0.value, &search339_1_1.value },
   NULL,
};

/* search673_0_0_0_0_0_0_0_0_0_0_0_0_1_0 -> search671_0 in the cache */

/* search673_0_0_0_0_0_0_0_0_0_0_0_0_1_1 -> search339_1_1 in the cache */
static const nir_search_expression search673_0_0_0_0_0_0_0_0_0_0_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_ushr,
   { &search671_0.value, &search339_1_1.value },
   NULL,
};
static const nir_search_expression search673_0_0_0_0_0_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   8, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

static const nir_search_constant search673_0_0_0_0_0_0_0_0_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0xff00ff /* 16711935 */ },
};
static const nir_search_expression search673_0_0_0_0_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   7, 2,
   nir_op_iand,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_0_0_0_0_0_0_0_1 -> search416_1 in the cache */
static const nir_search_expression search673_0_0_0_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishl,
   { &search673_0_0_0_0_0_0_0_0_0_0_0.value, &search416_1.value },
   NULL,
};

/* search673_0_0_0_0_0_0_0_0_0_1_0_0_0_0 -> search671_0 in the cache */

/* search673_0_0_0_0_0_0_0_0_0_1_0_0_0_1 -> search339_1_1 in the cache */
/* search673_0_0_0_0_0_0_0_0_0_1_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_0_0_0_0_0_0_0_0_0_1_0_0_1_0 -> search671_0 in the cache */

/* search673_0_0_0_0_0_0_0_0_0_1_0_0_1_1 -> search339_1_1 in the cache */
/* search673_0_0_0_0_0_0_0_0_0_1_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_0_0_0_0_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   10, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

static const nir_search_constant search673_0_0_0_0_0_0_0_0_0_1_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0xff00ff00 /* 4278255360 */ },
};
static const nir_search_expression search673_0_0_0_0_0_0_0_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   9, 2,
   nir_op_iand,
   { &search673_0_0_0_0_0_0_0_0_0_1_0_0.value, &search673_0_0_0_0_0_0_0_0_0_1_0_1.value },
   NULL,
};

/* search673_0_0_0_0_0_0_0_0_0_1_1 -> search416_1 in the cache */
static const nir_search_expression search673_0_0_0_0_0_0_0_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ushr,
   { &search673_0_0_0_0_0_0_0_0_0_1_0.value, &search416_1.value },
   NULL,
};
static const nir_search_expression search673_0_0_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   6, 5,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

static const nir_search_constant search673_0_0_0_0_0_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0xf0f0f0f /* 252645135 */ },
};
static const nir_search_expression search673_0_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   5, 6,
   nir_op_iand,
   { &search673_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

static const nir_search_constant search673_0_0_0_0_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x4 /* 4 */ },
};
static const nir_search_expression search673_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 6,
   nir_op_ishl,
   { &search673_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_0_0_0_1_0_0_0_0_0_0_0 -> search671_0 in the cache */

/* search673_0_0_0_0_0_0_1_0_0_0_0_0_0_1 -> search339_1_1 in the cache */
/* search673_0_0_0_0_0_0_1_0_0_0_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_0_0_0_0_0_0_1_0_0_0_0_0_1_0 -> search671_0 in the cache */

/* search673_0_0_0_0_0_0_1_0_0_0_0_0_1_1 -> search339_1_1 in the cache */
/* search673_0_0_0_0_0_0_1_0_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_0_0_0_1_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   14, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_0_0_0_1_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_0_0_0_1_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   13, 2,
   nir_op_iand,
   { &search673_0_0_0_0_0_0_1_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_0_0_0_1_0_0_0_1 -> search416_1 in the cache */
static const nir_search_expression search673_0_0_0_0_0_0_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishl,
   { &search673_0_0_0_0_0_0_1_0_0_0_0.value, &search416_1.value },
   NULL,
};

/* search673_0_0_0_0_0_0_1_0_0_1_0_0_0_0 -> search671_0 in the cache */

/* search673_0_0_0_0_0_0_1_0_0_1_0_0_0_1 -> search339_1_1 in the cache */
/* search673_0_0_0_0_0_0_1_0_0_1_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_0_0_0_0_0_0_1_0_0_1_0_0_1_0 -> search671_0 in the cache */

/* search673_0_0_0_0_0_0_1_0_0_1_0_0_1_1 -> search339_1_1 in the cache */
/* search673_0_0_0_0_0_0_1_0_0_1_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_0_0_0_1_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   16, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_0_0_0_1_0_0_1_0_1 -> search673_0_0_0_0_0_0_0_0_0_1_0_1 in the cache */
static const nir_search_expression search673_0_0_0_0_0_0_1_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   15, 2,
   nir_op_iand,
   { &search673_0_0_0_0_0_0_1_0_0_1_0_0.value, &search673_0_0_0_0_0_0_0_0_0_1_0_1.value },
   NULL,
};

/* search673_0_0_0_0_0_0_1_0_0_1_1 -> search416_1 in the cache */
static const nir_search_expression search673_0_0_0_0_0_0_1_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ushr,
   { &search673_0_0_0_0_0_0_1_0_0_1_0.value, &search416_1.value },
   NULL,
};
static const nir_search_expression search673_0_0_0_0_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   12, 5,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_1_0_0_0.value, &search673_0_0_0_0_0_0_1_0_0_1.value },
   NULL,
};

static const nir_search_constant search673_0_0_0_0_0_0_1_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0xf0f0f0f0 /* 4042322160 */ },
};
static const nir_search_expression search673_0_0_0_0_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   11, 6,
   nir_op_iand,
   { &search673_0_0_0_0_0_0_1_0_0.value, &search673_0_0_0_0_0_0_1_0_1.value },
   NULL,
};

/* search673_0_0_0_0_0_0_1_1 -> search673_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_0_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 6,
   nir_op_ushr,
   { &search673_0_0_0_0_0_0_1_0.value, &search673_0_0_0_0_0_0_0_1.value },
   NULL,
};
static const nir_search_expression search673_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   4, 13,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_1.value },
   NULL,
};

static const nir_search_constant search673_0_0_0_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x33333333 /* 858993459 */ },
};
static const nir_search_expression search673_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   3, 14,
   nir_op_iand,
   { &search673_0_0_0_0_0_0.value, &search673_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_0_1 -> replace425_1 in the cache */
static const nir_search_expression search673_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 14,
   nir_op_ishl,
   { &search673_0_0_0_0_0.value, &replace425_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_0_0_0_0_0_0_0_0 -> search671_0 in the cache */

/* search673_0_0_0_1_0_0_0_0_0_0_0_0_0_1 -> search339_1_1 in the cache */
/* search673_0_0_0_1_0_0_0_0_0_0_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_0_0_0_1_0_0_0_0_0_0_0_0_1_0 -> search671_0 in the cache */

/* search673_0_0_0_1_0_0_0_0_0_0_0_0_1_1 -> search339_1_1 in the cache */
/* search673_0_0_0_1_0_0_0_0_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   22, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_0_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   21, 2,
   nir_op_iand,
   { &search673_0_0_0_1_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_0_0_0_0_1 -> search416_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishl,
   { &search673_0_0_0_1_0_0_0_0_0_0_0.value, &search416_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_0_0_0_1_0_0_0_0 -> search671_0 in the cache */

/* search673_0_0_0_1_0_0_0_0_0_1_0_0_0_1 -> search339_1_1 in the cache */
/* search673_0_0_0_1_0_0_0_0_0_1_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_0_0_0_1_0_0_0_0_0_1_0_0_1_0 -> search671_0 in the cache */

/* search673_0_0_0_1_0_0_0_0_0_1_0_0_1_1 -> search339_1_1 in the cache */
/* search673_0_0_0_1_0_0_0_0_0_1_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_0_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   24, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_0_0_0_1_0_1 -> search673_0_0_0_0_0_0_0_0_0_1_0_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_0_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   23, 2,
   nir_op_iand,
   { &search673_0_0_0_1_0_0_0_0_0_1_0_0.value, &search673_0_0_0_0_0_0_0_0_0_1_0_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_0_0_0_1_1 -> search416_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_0_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ushr,
   { &search673_0_0_0_1_0_0_0_0_0_1_0.value, &search416_1.value },
   NULL,
};
static const nir_search_expression search673_0_0_0_1_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   20, 5,
   nir_op_ior,
   { &search673_0_0_0_1_0_0_0_0_0_0.value, &search673_0_0_0_1_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   19, 6,
   nir_op_iand,
   { &search673_0_0_0_1_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_0_1 -> search673_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 6,
   nir_op_ishl,
   { &search673_0_0_0_1_0_0_0_0.value, &search673_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_1_0_0_0_0_0_0_0 -> search671_0 in the cache */

/* search673_0_0_0_1_0_0_1_0_0_0_0_0_0_1 -> search339_1_1 in the cache */
/* search673_0_0_0_1_0_0_1_0_0_0_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_0_0_0_1_0_0_1_0_0_0_0_0_1_0 -> search671_0 in the cache */

/* search673_0_0_0_1_0_0_1_0_0_0_0_0_1_1 -> search339_1_1 in the cache */
/* search673_0_0_0_1_0_0_1_0_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_1_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   28, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_1_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_1_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   27, 2,
   nir_op_iand,
   { &search673_0_0_0_1_0_0_1_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_1_0_0_0_1 -> search416_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishl,
   { &search673_0_0_0_1_0_0_1_0_0_0_0.value, &search416_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_1_0_0_1_0_0_0_0 -> search671_0 in the cache */

/* search673_0_0_0_1_0_0_1_0_0_1_0_0_0_1 -> search339_1_1 in the cache */
/* search673_0_0_0_1_0_0_1_0_0_1_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_0_0_0_1_0_0_1_0_0_1_0_0_1_0 -> search671_0 in the cache */

/* search673_0_0_0_1_0_0_1_0_0_1_0_0_1_1 -> search339_1_1 in the cache */
/* search673_0_0_0_1_0_0_1_0_0_1_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_1_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   30, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_1_0_0_1_0_1 -> search673_0_0_0_0_0_0_0_0_0_1_0_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_1_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   29, 2,
   nir_op_iand,
   { &search673_0_0_0_1_0_0_1_0_0_1_0_0.value, &search673_0_0_0_0_0_0_0_0_0_1_0_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_1_0_0_1_1 -> search416_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_1_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ushr,
   { &search673_0_0_0_1_0_0_1_0_0_1_0.value, &search416_1.value },
   NULL,
};
static const nir_search_expression search673_0_0_0_1_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   26, 5,
   nir_op_ior,
   { &search673_0_0_0_1_0_0_1_0_0_0.value, &search673_0_0_0_1_0_0_1_0_0_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_1_0_1 -> search673_0_0_0_0_0_0_1_0_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   25, 6,
   nir_op_iand,
   { &search673_0_0_0_1_0_0_1_0_0.value, &search673_0_0_0_0_0_0_1_0_1.value },
   NULL,
};

/* search673_0_0_0_1_0_0_1_1 -> search673_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_0_0_0_1_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 6,
   nir_op_ushr,
   { &search673_0_0_0_1_0_0_1_0.value, &search673_0_0_0_0_0_0_0_1.value },
   NULL,
};
static const nir_search_expression search673_0_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   18, 13,
   nir_op_ior,
   { &search673_0_0_0_1_0_0_0.value, &search673_0_0_0_1_0_0_1.value },
   NULL,
};

static const nir_search_constant search673_0_0_0_1_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0xcccccccc /* 3435973836 */ },
};
static const nir_search_expression search673_0_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   17, 14,
   nir_op_iand,
   { &search673_0_0_0_1_0_0.value, &search673_0_0_0_1_0_1.value },
   NULL,
};

/* search673_0_0_0_1_1 -> replace425_1 in the cache */
static const nir_search_expression search673_0_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 14,
   nir_op_ushr,
   { &search673_0_0_0_1_0.value, &replace425_1.value },
   NULL,
};
static const nir_search_expression search673_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   2, 29,
   nir_op_ior,
   { &search673_0_0_0_0.value, &search673_0_0_0_1.value },
   NULL,
};

static const nir_search_constant search673_0_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0x55555555 /* 1431655765 */ },
};
static const nir_search_expression search673_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   1, 30,
   nir_op_iand,
   { &search673_0_0_0.value, &search673_0_0_1.value },
   NULL,
};

/* search673_0_1 -> replace424_1 in the cache */
static const nir_search_expression search673_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 30,
   nir_op_ishl,
   { &search673_0_0.value, &replace424_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_0_0_0_0_0_0_0_0 -> search671_0 in the cache */

/* search673_1_0_0_0_0_0_0_0_0_0_0_0_0_1 -> search339_1_1 in the cache */
/* search673_1_0_0_0_0_0_0_0_0_0_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_1_0_0_0_0_0_0_0_0_0_0_0_1_0 -> search671_0 in the cache */

/* search673_1_0_0_0_0_0_0_0_0_0_0_0_1_1 -> search339_1_1 in the cache */
/* search673_1_0_0_0_0_0_0_0_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   38, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_0_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   37, 2,
   nir_op_iand,
   { &search673_1_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_0_0_0_0_1 -> search416_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishl,
   { &search673_1_0_0_0_0_0_0_0_0_0_0.value, &search416_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_0_0_0_1_0_0_0_0 -> search671_0 in the cache */

/* search673_1_0_0_0_0_0_0_0_0_1_0_0_0_1 -> search339_1_1 in the cache */
/* search673_1_0_0_0_0_0_0_0_0_1_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_1_0_0_0_0_0_0_0_0_1_0_0_1_0 -> search671_0 in the cache */

/* search673_1_0_0_0_0_0_0_0_0_1_0_0_1_1 -> search339_1_1 in the cache */
/* search673_1_0_0_0_0_0_0_0_0_1_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_0_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   40, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_0_0_0_1_0_1 -> search673_0_0_0_0_0_0_0_0_0_1_0_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_0_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   39, 2,
   nir_op_iand,
   { &search673_1_0_0_0_0_0_0_0_0_1_0_0.value, &search673_0_0_0_0_0_0_0_0_0_1_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_0_0_0_1_1 -> search416_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_0_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ushr,
   { &search673_1_0_0_0_0_0_0_0_0_1_0.value, &search416_1.value },
   NULL,
};
static const nir_search_expression search673_1_0_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   36, 5,
   nir_op_ior,
   { &search673_1_0_0_0_0_0_0_0_0_0.value, &search673_1_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   35, 6,
   nir_op_iand,
   { &search673_1_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 6,
   nir_op_ishl,
   { &search673_1_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_1_0_0_0_0_0_0_0 -> search671_0 in the cache */

/* search673_1_0_0_0_0_0_1_0_0_0_0_0_0_1 -> search339_1_1 in the cache */
/* search673_1_0_0_0_0_0_1_0_0_0_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_1_0_0_0_0_0_1_0_0_0_0_0_1_0 -> search671_0 in the cache */

/* search673_1_0_0_0_0_0_1_0_0_0_0_0_1_1 -> search339_1_1 in the cache */
/* search673_1_0_0_0_0_0_1_0_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_1_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   44, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_1_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_1_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   43, 2,
   nir_op_iand,
   { &search673_1_0_0_0_0_0_1_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_1_0_0_0_1 -> search416_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishl,
   { &search673_1_0_0_0_0_0_1_0_0_0_0.value, &search416_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_1_0_0_1_0_0_0_0 -> search671_0 in the cache */

/* search673_1_0_0_0_0_0_1_0_0_1_0_0_0_1 -> search339_1_1 in the cache */
/* search673_1_0_0_0_0_0_1_0_0_1_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_1_0_0_0_0_0_1_0_0_1_0_0_1_0 -> search671_0 in the cache */

/* search673_1_0_0_0_0_0_1_0_0_1_0_0_1_1 -> search339_1_1 in the cache */
/* search673_1_0_0_0_0_0_1_0_0_1_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_1_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   46, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_1_0_0_1_0_1 -> search673_0_0_0_0_0_0_0_0_0_1_0_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_1_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   45, 2,
   nir_op_iand,
   { &search673_1_0_0_0_0_0_1_0_0_1_0_0.value, &search673_0_0_0_0_0_0_0_0_0_1_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_1_0_0_1_1 -> search416_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_1_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ushr,
   { &search673_1_0_0_0_0_0_1_0_0_1_0.value, &search416_1.value },
   NULL,
};
static const nir_search_expression search673_1_0_0_0_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   42, 5,
   nir_op_ior,
   { &search673_1_0_0_0_0_0_1_0_0_0.value, &search673_1_0_0_0_0_0_1_0_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_1_0_1 -> search673_0_0_0_0_0_0_1_0_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   41, 6,
   nir_op_iand,
   { &search673_1_0_0_0_0_0_1_0_0.value, &search673_0_0_0_0_0_0_1_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_0_1_1 -> search673_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 6,
   nir_op_ushr,
   { &search673_1_0_0_0_0_0_1_0.value, &search673_0_0_0_0_0_0_0_1.value },
   NULL,
};
static const nir_search_expression search673_1_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   34, 13,
   nir_op_ior,
   { &search673_1_0_0_0_0_0_0.value, &search673_1_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_0_0_1 -> search673_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   33, 14,
   nir_op_iand,
   { &search673_1_0_0_0_0_0.value, &search673_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_0_1 -> replace425_1 in the cache */
static const nir_search_expression search673_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 14,
   nir_op_ishl,
   { &search673_1_0_0_0_0.value, &replace425_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_0_0_0_0_0_0_0_0 -> search671_0 in the cache */

/* search673_1_0_0_1_0_0_0_0_0_0_0_0_0_1 -> search339_1_1 in the cache */
/* search673_1_0_0_1_0_0_0_0_0_0_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_1_0_0_1_0_0_0_0_0_0_0_0_1_0 -> search671_0 in the cache */

/* search673_1_0_0_1_0_0_0_0_0_0_0_0_1_1 -> search339_1_1 in the cache */
/* search673_1_0_0_1_0_0_0_0_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   52, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_0_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   51, 2,
   nir_op_iand,
   { &search673_1_0_0_1_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_0_0_0_0_1 -> search416_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishl,
   { &search673_1_0_0_1_0_0_0_0_0_0_0.value, &search416_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_0_0_0_1_0_0_0_0 -> search671_0 in the cache */

/* search673_1_0_0_1_0_0_0_0_0_1_0_0_0_1 -> search339_1_1 in the cache */
/* search673_1_0_0_1_0_0_0_0_0_1_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_1_0_0_1_0_0_0_0_0_1_0_0_1_0 -> search671_0 in the cache */

/* search673_1_0_0_1_0_0_0_0_0_1_0_0_1_1 -> search339_1_1 in the cache */
/* search673_1_0_0_1_0_0_0_0_0_1_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_0_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   54, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_0_0_0_1_0_1 -> search673_0_0_0_0_0_0_0_0_0_1_0_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_0_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   53, 2,
   nir_op_iand,
   { &search673_1_0_0_1_0_0_0_0_0_1_0_0.value, &search673_0_0_0_0_0_0_0_0_0_1_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_0_0_0_1_1 -> search416_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_0_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ushr,
   { &search673_1_0_0_1_0_0_0_0_0_1_0.value, &search416_1.value },
   NULL,
};
static const nir_search_expression search673_1_0_0_1_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   50, 5,
   nir_op_ior,
   { &search673_1_0_0_1_0_0_0_0_0_0.value, &search673_1_0_0_1_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   49, 6,
   nir_op_iand,
   { &search673_1_0_0_1_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_0_1 -> search673_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 6,
   nir_op_ishl,
   { &search673_1_0_0_1_0_0_0_0.value, &search673_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_1_0_0_0_0_0_0_0 -> search671_0 in the cache */

/* search673_1_0_0_1_0_0_1_0_0_0_0_0_0_1 -> search339_1_1 in the cache */
/* search673_1_0_0_1_0_0_1_0_0_0_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_1_0_0_1_0_0_1_0_0_0_0_0_1_0 -> search671_0 in the cache */

/* search673_1_0_0_1_0_0_1_0_0_0_0_0_1_1 -> search339_1_1 in the cache */
/* search673_1_0_0_1_0_0_1_0_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_1_0_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   58, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_1_0_0_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_1_0_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   57, 2,
   nir_op_iand,
   { &search673_1_0_0_1_0_0_1_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_1_0_0_0_1 -> search416_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_1_0_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ishl,
   { &search673_1_0_0_1_0_0_1_0_0_0_0.value, &search416_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_1_0_0_1_0_0_0_0 -> search671_0 in the cache */

/* search673_1_0_0_1_0_0_1_0_0_1_0_0_0_1 -> search339_1_1 in the cache */
/* search673_1_0_0_1_0_0_1_0_0_1_0_0_0 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_0 in the cache */

/* search673_1_0_0_1_0_0_1_0_0_1_0_0_1_0 -> search671_0 in the cache */

/* search673_1_0_0_1_0_0_1_0_0_1_0_0_1_1 -> search339_1_1 in the cache */
/* search673_1_0_0_1_0_0_1_0_0_1_0_0_1 -> search673_0_0_0_0_0_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_1_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   60, 1,
   nir_op_ior,
   { &search673_0_0_0_0_0_0_0_0_0_0_0_0_0.value, &search673_0_0_0_0_0_0_0_0_0_0_0_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_1_0_0_1_0_1 -> search673_0_0_0_0_0_0_0_0_0_1_0_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_1_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   59, 2,
   nir_op_iand,
   { &search673_1_0_0_1_0_0_1_0_0_1_0_0.value, &search673_0_0_0_0_0_0_0_0_0_1_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_1_0_0_1_1 -> search416_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_1_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 2,
   nir_op_ushr,
   { &search673_1_0_0_1_0_0_1_0_0_1_0.value, &search416_1.value },
   NULL,
};
static const nir_search_expression search673_1_0_0_1_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   56, 5,
   nir_op_ior,
   { &search673_1_0_0_1_0_0_1_0_0_0.value, &search673_1_0_0_1_0_0_1_0_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_1_0_1 -> search673_0_0_0_0_0_0_1_0_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   55, 6,
   nir_op_iand,
   { &search673_1_0_0_1_0_0_1_0_0.value, &search673_0_0_0_0_0_0_1_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_0_1_1 -> search673_0_0_0_0_0_0_0_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 6,
   nir_op_ushr,
   { &search673_1_0_0_1_0_0_1_0.value, &search673_0_0_0_0_0_0_0_1.value },
   NULL,
};
static const nir_search_expression search673_1_0_0_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   48, 13,
   nir_op_ior,
   { &search673_1_0_0_1_0_0_0.value, &search673_1_0_0_1_0_0_1.value },
   NULL,
};

/* search673_1_0_0_1_0_1 -> search673_0_0_0_1_0_1 in the cache */
static const nir_search_expression search673_1_0_0_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   47, 14,
   nir_op_iand,
   { &search673_1_0_0_1_0_0.value, &search673_0_0_0_1_0_1.value },
   NULL,
};

/* search673_1_0_0_1_1 -> replace425_1 in the cache */
static const nir_search_expression search673_1_0_0_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 14,
   nir_op_ushr,
   { &search673_1_0_0_1_0.value, &replace425_1.value },
   NULL,
};
static const nir_search_expression search673_1_0_0 = {
   { nir_search_value_expression, 32 },
   false,
   32, 29,
   nir_op_ior,
   { &search673_1_0_0_0.value, &search673_1_0_0_1.value },
   NULL,
};

static const nir_search_constant search673_1_0_1 = {
   { nir_search_value_constant, 32 },
   nir_type_int, { 0xaaaaaaaa /* 2863311530 */ },
};
static const nir_search_expression search673_1_0 = {
   { nir_search_value_expression, 32 },
   false,
   31, 30,
   nir_op_iand,
   { &search673_1_0_0.value, &search673_1_0_1.value },
   NULL,
};

/* search673_1_1 -> replace424_1 in the cache */
static const nir_search_expression search673_1 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 30,
   nir_op_ushr,
   { &search673_1_0.value, &replace424_1.value },
   NULL,
};
static const nir_search_expression search673 = {
   { nir_search_value_expression, 32 },
   false,
   0, 61,
   nir_op_ior,
   { &search673_0.value, &search673_1.value },
   NULL,
};

   /* replace673_0 -> search671_0 in the cache */
static const nir_search_expression replace673 = {
   { nir_search_value_expression, 32 },
   false,
   -1, 0,
   nir_op_bitfield_reverse,
   { &search671_0.value },
   NULL,
};

   /* search674_0_0 -> search13_0 in the cache */

/* search674_0_1 -> search13_0 in the cache */
static const nir_search_expression search674_0 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_feq,
   { &search13_0.value, &search13_0.value },
   NULL,
};

/* search674_1_0 -> search13_0 in the cache */

/* search674_1_1 -> replace13_1_0 in the cache */
/* search674_1 -> search81_0 in the cache */
static const nir_search_expression search674 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_iand,
   { &search674_0.value, &search81_0.value },
   NULL,
};

   /* replace674_0 -> search13_0 in the cache */

/* replace674_1 -> replace13_1_0 in the cache */
/* replace674 -> search81_0 in the cache */

   /* search675_0_0 -> search6_0 in the cache */

/* search675_0_1 -> search6_0 in the cache */
static const nir_search_expression search675_0 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_feq,
   { &search6_0.value, &search6_0.value },
   NULL,
};

/* search675_1_0 -> search250_1_0 in the cache */

/* search675_1_1 -> search6_0 in the cache */
static const nir_search_expression search675_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search250_1_0.value, &search6_0.value },
   NULL,
};
static const nir_search_expression search675 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_iand,
   { &search675_0.value, &search675_1.value },
   NULL,
};

   /* replace675_0 -> search250_1_0 in the cache */

/* replace675_1 -> search6_0 in the cache */
/* replace675 -> search675_1 in the cache */

   /* search676_0_0 -> search13_0 in the cache */

/* search676_0_1 -> search13_0 in the cache */
/* search676_0 -> search674_0 in the cache */

/* search676_1_0 -> search13_0 in the cache */

/* search676_1_1 -> replace13_1_0 in the cache */
/* search676_1 -> replace81 in the cache */
static const nir_search_expression search676 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_iand,
   { &search674_0.value, &replace81.value },
   NULL,
};

   /* replace676_0 -> search13_0 in the cache */

/* replace676_1 -> replace13_1_0 in the cache */
/* replace676 -> replace81 in the cache */

   /* search677_0_0 -> search6_0 in the cache */

/* search677_0_1 -> search6_0 in the cache */
/* search677_0 -> search675_0 in the cache */

/* search677_1_0 -> search250_1_0 in the cache */

/* search677_1_1 -> search6_0 in the cache */
static const nir_search_expression search677_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search250_1_0.value, &search6_0.value },
   NULL,
};
static const nir_search_expression search677 = {
   { nir_search_value_expression, 1 },
   false,
   0, 2,
   nir_op_iand,
   { &search675_0.value, &search677_1.value },
   NULL,
};

   /* replace677_0 -> search250_1_0 in the cache */

/* replace677_1 -> search6_0 in the cache */
/* replace677 -> search677_1 in the cache */

   /* search678_0_0 -> search13_0 in the cache */

/* search678_0_1 -> search13_0 in the cache */
/* search678_0 -> search674_0 in the cache */

/* search678_1_0 -> search13_0 in the cache */

/* search678_1_1 -> replace13_1_0 in the cache */
static const nir_search_expression search678_1 = {
   { nir_search_value_expression, 1 },
   false,
   2, 1,
   nir_op_feq,
   { &search13_0.value, &replace13_1_0.value },
   NULL,
};
static const nir_search_expression search678 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_iand,
   { &search674_0.value, &search678_1.value },
   NULL,
};

   /* replace678_0 -> search13_0 in the cache */

/* replace678_1 -> replace13_1_0 in the cache */
/* replace678 -> search83_0 in the cache */

   /* search679_0_0 -> search6_0 in the cache */

/* search679_0_1 -> search6_0 in the cache */
/* search679_0 -> search675_0 in the cache */

/* search679_1_0 -> search250_1_0 in the cache */

/* search679_1_1 -> search6_0 in the cache */
static const nir_search_expression search679_1 = {
   { nir_search_value_expression, 1 },
   false,
   2, 1,
   nir_op_feq,
   { &search250_1_0.value, &search6_0.value },
   NULL,
};
static const nir_search_expression search679 = {
   { nir_search_value_expression, 1 },
   false,
   0, 3,
   nir_op_iand,
   { &search675_0.value, &search679_1.value },
   NULL,
};

   /* replace679_0 -> search250_1_0 in the cache */

/* replace679_1 -> search6_0 in the cache */
static const nir_search_expression replace679 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search250_1_0.value, &search6_0.value },
   NULL,
};

   /* search680_0_0 -> replace72_0 in the cache */

static const nir_search_variable search680_0_1 = {
   { nir_search_value_variable, -4 },
   1, /* b */
   true,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search680_0_2 = {
   { nir_search_value_variable, -4 },
   2, /* c */
   true,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search680_0 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search680_0_1.value, &search680_0_2.value },
   NULL,
};

static const nir_search_variable search680_1 = {
   { nir_search_value_variable, -4 },
   3, /* d */
   true,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search680 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search680_0.value, &search680_1.value },
   NULL,
};

   /* replace680_0 -> replace72_0 in the cache */

/* replace680_1_0 -> search73_0_1 in the cache */

/* replace680_1_1 -> search73_1 in the cache */
static const nir_search_expression replace680_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace680_2_0 -> search73_0_2 in the cache */

/* replace680_2_1 -> search73_1 in the cache */
/* replace680_2 -> replace550_1 in the cache */
static const nir_search_expression replace680 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &replace680_1.value, &replace550_1.value },
   NULL,
};

   static const nir_search_variable search681_0 = {
   { nir_search_value_variable, -4 },
   0, /* d */
   true,
   nir_type_invalid,
   NULL,
};

/* search681_1_0 -> search119_0_1_0_0_0 in the cache */

static const nir_search_variable search681_1_1 = {
   { nir_search_value_variable, -4 },
   2, /* b */
   true,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable search681_1_2 = {
   { nir_search_value_variable, -4 },
   3, /* c */
   true,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression search681_1 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search119_0_1_0_0_0.value, &search681_1_1.value, &search681_1_2.value },
   NULL,
};
static const nir_search_expression search681 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &search681_0.value, &search681_1.value },
   NULL,
};

   /* replace681_0 -> search119_0_1_0_0_0 in the cache */

static const nir_search_variable replace681_1_0 = {
   { nir_search_value_variable, -4 },
   0, /* d */
   false,
   nir_type_invalid,
   NULL,
};

static const nir_search_variable replace681_1_1 = {
   { nir_search_value_variable, -4 },
   2, /* b */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression replace681_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &replace681_1_0.value, &replace681_1_1.value },
   NULL,
};

/* replace681_2_0 -> replace681_1_0 in the cache */

static const nir_search_variable replace681_2_1 = {
   { nir_search_value_variable, -4 },
   3, /* c */
   false,
   nir_type_invalid,
   NULL,
};
static const nir_search_expression replace681_2 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_flt,
   { &replace681_1_0.value, &replace681_2_1.value },
   NULL,
};
static const nir_search_expression replace681 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search119_0_1_0_0_0.value, &replace681_1.value, &replace681_2.value },
   NULL,
};

   /* search682_0_0 -> replace72_0 in the cache */

/* search682_0_1 -> search680_0_1 in the cache */

/* search682_0_2 -> search680_0_2 in the cache */
/* search682_0 -> search680_0 in the cache */

/* search682_1 -> search680_1 in the cache */
static const nir_search_expression search682 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search680_0.value, &search680_1.value },
   NULL,
};

   /* replace682_0 -> replace72_0 in the cache */

/* replace682_1_0 -> search73_0_1 in the cache */

/* replace682_1_1 -> search73_1 in the cache */
static const nir_search_expression replace682_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace682_2_0 -> search73_0_2 in the cache */

/* replace682_2_1 -> search73_1 in the cache */
/* replace682_2 -> search550_0_1 in the cache */
static const nir_search_expression replace682 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &replace682_1.value, &search550_0_1.value },
   NULL,
};

   /* search683_0 -> search681_0 in the cache */

/* search683_1_0 -> search119_0_1_0_0_0 in the cache */

/* search683_1_1 -> search681_1_1 in the cache */

/* search683_1_2 -> search681_1_2 in the cache */
/* search683_1 -> search681_1 in the cache */
static const nir_search_expression search683 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &search681_0.value, &search681_1.value },
   NULL,
};

   /* replace683_0 -> search119_0_1_0_0_0 in the cache */

/* replace683_1_0 -> replace681_1_0 in the cache */

/* replace683_1_1 -> replace681_1_1 in the cache */
static const nir_search_expression replace683_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &replace681_1_0.value, &replace681_1_1.value },
   NULL,
};

/* replace683_2_0 -> replace681_1_0 in the cache */

/* replace683_2_1 -> replace681_2_1 in the cache */
static const nir_search_expression replace683_2 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_fge,
   { &replace681_1_0.value, &replace681_2_1.value },
   NULL,
};
static const nir_search_expression replace683 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search119_0_1_0_0_0.value, &replace683_1.value, &replace683_2.value },
   NULL,
};

   /* search684_0_0 -> replace72_0 in the cache */

/* search684_0_1 -> search680_0_1 in the cache */

/* search684_0_2 -> search680_0_2 in the cache */
/* search684_0 -> search680_0 in the cache */

/* search684_1 -> search680_1 in the cache */
static const nir_search_expression search684 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search680_0.value, &search680_1.value },
   NULL,
};

   /* replace684_0 -> replace72_0 in the cache */

/* replace684_1_0 -> search73_0_1 in the cache */

/* replace684_1_1 -> search73_1 in the cache */
static const nir_search_expression replace684_1 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace684_2_0 -> search73_0_2 in the cache */

/* replace684_2_1 -> search73_1 in the cache */
static const nir_search_expression replace684_2 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_feq,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace684 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace72_0.value, &replace684_1.value, &replace684_2.value },
   NULL,
};

   /* search685_0 -> search681_0 in the cache */

/* search685_1_0 -> search119_0_1_0_0_0 in the cache */

/* search685_1_1 -> search681_1_1 in the cache */

/* search685_1_2 -> search681_1_2 in the cache */
/* search685_1 -> search681_1 in the cache */
static const nir_search_expression search685 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &search681_0.value, &search681_1.value },
   NULL,
};

   /* replace685_0 -> search119_0_1_0_0_0 in the cache */

/* replace685_1_0 -> replace681_1_0 in the cache */

/* replace685_1_1 -> replace681_1_1 in the cache */
static const nir_search_expression replace685_1 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_feq,
   { &replace681_1_0.value, &replace681_1_1.value },
   NULL,
};

/* replace685_2_0 -> replace681_1_0 in the cache */

/* replace685_2_1 -> replace681_2_1 in the cache */
static const nir_search_expression replace685_2 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_feq,
   { &replace681_1_0.value, &replace681_2_1.value },
   NULL,
};
static const nir_search_expression replace685 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &search119_0_1_0_0_0.value, &replace685_1.value, &replace685_2.value },
   NULL,
};

   /* search686_0_0 -> replace72_0 in the cache */

/* search686_0_1 -> search680_0_1 in the cache */

/* search686_0_2 -> search680_0_2 in the cache */
/* search686_0 -> search680_0 in the cache */

/* search686_1 -> search680_1 in the cache */
static const nir_search_expression search686 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search680_0.value, &search680_1.value },
   NULL,
};

   /* replace686_0 -> replace72_0 in the cache */

/* replace686_1_0 -> search73_0_1 in the cache */

/* replace686_1_1 -> search73_1 in the cache */
static const nir_search_expression replace686_1 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace686_2_0 -> search73_0_2 in the cache */

/* replace686_2_1 -> search73_1 in the cache */
static const nir_search_expression replace686_2 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_fne,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace686 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace72_0.value, &replace686_1.value, &replace686_2.value },
   NULL,
};

   /* search687_0 -> search681_0 in the cache */

/* search687_1_0 -> search119_0_1_0_0_0 in the cache */

/* search687_1_1 -> search681_1_1 in the cache */

/* search687_1_2 -> search681_1_2 in the cache */
/* search687_1 -> search681_1 in the cache */
static const nir_search_expression search687 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &search681_0.value, &search681_1.value },
   NULL,
};

   /* replace687_0 -> search119_0_1_0_0_0 in the cache */

/* replace687_1_0 -> replace681_1_0 in the cache */

/* replace687_1_1 -> replace681_1_1 in the cache */
static const nir_search_expression replace687_1 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_fne,
   { &replace681_1_0.value, &replace681_1_1.value },
   NULL,
};

/* replace687_2_0 -> replace681_1_0 in the cache */

/* replace687_2_1 -> replace681_2_1 in the cache */
static const nir_search_expression replace687_2 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_fne,
   { &replace681_1_0.value, &replace681_2_1.value },
   NULL,
};
static const nir_search_expression replace687 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &search119_0_1_0_0_0.value, &replace687_1.value, &replace687_2.value },
   NULL,
};

   /* search688_0_0 -> replace72_0 in the cache */

/* search688_0_1 -> search680_0_1 in the cache */

/* search688_0_2 -> search680_0_2 in the cache */
/* search688_0 -> search680_0 in the cache */

/* search688_1 -> search680_1 in the cache */
static const nir_search_expression search688 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search680_0.value, &search680_1.value },
   NULL,
};

   /* replace688_0 -> replace72_0 in the cache */

/* replace688_1_0 -> search73_0_1 in the cache */

/* replace688_1_1 -> search73_1 in the cache */
static const nir_search_expression replace688_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace688_2_0 -> search73_0_2 in the cache */

/* replace688_2_1 -> search73_1 in the cache */
static const nir_search_expression replace688_2 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace688 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &replace688_1.value, &replace688_2.value },
   NULL,
};

   /* search689_0 -> search681_0 in the cache */

/* search689_1_0 -> search119_0_1_0_0_0 in the cache */

/* search689_1_1 -> search681_1_1 in the cache */

/* search689_1_2 -> search681_1_2 in the cache */
/* search689_1 -> search681_1 in the cache */
static const nir_search_expression search689 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &search681_0.value, &search681_1.value },
   NULL,
};

   /* replace689_0 -> search119_0_1_0_0_0 in the cache */

/* replace689_1_0 -> replace681_1_0 in the cache */

/* replace689_1_1 -> replace681_1_1 in the cache */
static const nir_search_expression replace689_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &replace681_1_0.value, &replace681_1_1.value },
   NULL,
};

/* replace689_2_0 -> replace681_1_0 in the cache */

/* replace689_2_1 -> replace681_2_1 in the cache */
static const nir_search_expression replace689_2 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ilt,
   { &replace681_1_0.value, &replace681_2_1.value },
   NULL,
};
static const nir_search_expression replace689 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search119_0_1_0_0_0.value, &replace689_1.value, &replace689_2.value },
   NULL,
};

   /* search690_0_0 -> replace72_0 in the cache */

/* search690_0_1 -> search680_0_1 in the cache */

/* search690_0_2 -> search680_0_2 in the cache */
/* search690_0 -> search680_0 in the cache */

/* search690_1 -> search680_1 in the cache */
static const nir_search_expression search690 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search680_0.value, &search680_1.value },
   NULL,
};

   /* replace690_0 -> replace72_0 in the cache */

/* replace690_1_0 -> search73_0_1 in the cache */

/* replace690_1_1 -> search73_1 in the cache */
static const nir_search_expression replace690_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace690_2_0 -> search73_0_2 in the cache */

/* replace690_2_1 -> search73_1 in the cache */
static const nir_search_expression replace690_2 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace690 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &replace690_1.value, &replace690_2.value },
   NULL,
};

   /* search691_0 -> search681_0 in the cache */

/* search691_1_0 -> search119_0_1_0_0_0 in the cache */

/* search691_1_1 -> search681_1_1 in the cache */

/* search691_1_2 -> search681_1_2 in the cache */
/* search691_1 -> search681_1 in the cache */
static const nir_search_expression search691 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &search681_0.value, &search681_1.value },
   NULL,
};

   /* replace691_0 -> search119_0_1_0_0_0 in the cache */

/* replace691_1_0 -> replace681_1_0 in the cache */

/* replace691_1_1 -> replace681_1_1 in the cache */
static const nir_search_expression replace691_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &replace681_1_0.value, &replace681_1_1.value },
   NULL,
};

/* replace691_2_0 -> replace681_1_0 in the cache */

/* replace691_2_1 -> replace681_2_1 in the cache */
static const nir_search_expression replace691_2 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ige,
   { &replace681_1_0.value, &replace681_2_1.value },
   NULL,
};
static const nir_search_expression replace691 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search119_0_1_0_0_0.value, &replace691_1.value, &replace691_2.value },
   NULL,
};

   /* search692_0_0 -> replace72_0 in the cache */

/* search692_0_1 -> search680_0_1 in the cache */

/* search692_0_2 -> search680_0_2 in the cache */
/* search692_0 -> search680_0 in the cache */

/* search692_1 -> search680_1 in the cache */
static const nir_search_expression search692 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &search680_0.value, &search680_1.value },
   NULL,
};

   /* replace692_0 -> replace72_0 in the cache */

/* replace692_1_0 -> search73_0_1 in the cache */

/* replace692_1_1 -> search73_1 in the cache */
static const nir_search_expression replace692_1 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace692_2_0 -> search73_0_2 in the cache */

/* replace692_2_1 -> search73_1 in the cache */
static const nir_search_expression replace692_2 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_ieq,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace692 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace72_0.value, &replace692_1.value, &replace692_2.value },
   NULL,
};

   /* search693_0 -> search681_0 in the cache */

/* search693_1_0 -> search119_0_1_0_0_0 in the cache */

/* search693_1_1 -> search681_1_1 in the cache */

/* search693_1_2 -> search681_1_2 in the cache */
/* search693_1 -> search681_1 in the cache */
static const nir_search_expression search693 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &search681_0.value, &search681_1.value },
   NULL,
};

   /* replace693_0 -> search119_0_1_0_0_0 in the cache */

/* replace693_1_0 -> replace681_1_0 in the cache */

/* replace693_1_1 -> replace681_1_1 in the cache */
static const nir_search_expression replace693_1 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ieq,
   { &replace681_1_0.value, &replace681_1_1.value },
   NULL,
};

/* replace693_2_0 -> replace681_1_0 in the cache */

/* replace693_2_1 -> replace681_2_1 in the cache */
static const nir_search_expression replace693_2 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_ieq,
   { &replace681_1_0.value, &replace681_2_1.value },
   NULL,
};
static const nir_search_expression replace693 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &search119_0_1_0_0_0.value, &replace693_1.value, &replace693_2.value },
   NULL,
};

   /* search694_0_0 -> replace72_0 in the cache */

/* search694_0_1 -> search680_0_1 in the cache */

/* search694_0_2 -> search680_0_2 in the cache */
/* search694_0 -> search680_0 in the cache */

/* search694_1 -> search680_1 in the cache */
static const nir_search_expression search694 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &search680_0.value, &search680_1.value },
   NULL,
};

   /* replace694_0 -> replace72_0 in the cache */

/* replace694_1_0 -> search73_0_1 in the cache */

/* replace694_1_1 -> search73_1 in the cache */
static const nir_search_expression replace694_1 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace694_2_0 -> search73_0_2 in the cache */

/* replace694_2_1 -> search73_1 in the cache */
static const nir_search_expression replace694_2 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_ine,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace694 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace72_0.value, &replace694_1.value, &replace694_2.value },
   NULL,
};

   /* search695_0 -> search681_0 in the cache */

/* search695_1_0 -> search119_0_1_0_0_0 in the cache */

/* search695_1_1 -> search681_1_1 in the cache */

/* search695_1_2 -> search681_1_2 in the cache */
/* search695_1 -> search681_1 in the cache */
static const nir_search_expression search695 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &search681_0.value, &search681_1.value },
   NULL,
};

   /* replace695_0 -> search119_0_1_0_0_0 in the cache */

/* replace695_1_0 -> replace681_1_0 in the cache */

/* replace695_1_1 -> replace681_1_1 in the cache */
static const nir_search_expression replace695_1 = {
   { nir_search_value_expression, 1 },
   false,
   0, 1,
   nir_op_ine,
   { &replace681_1_0.value, &replace681_1_1.value },
   NULL,
};

/* replace695_2_0 -> replace681_1_0 in the cache */

/* replace695_2_1 -> replace681_2_1 in the cache */
static const nir_search_expression replace695_2 = {
   { nir_search_value_expression, 1 },
   false,
   1, 1,
   nir_op_ine,
   { &replace681_1_0.value, &replace681_2_1.value },
   NULL,
};
static const nir_search_expression replace695 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &search119_0_1_0_0_0.value, &replace695_1.value, &replace695_2.value },
   NULL,
};

   /* search696_0_0 -> replace72_0 in the cache */

/* search696_0_1 -> search680_0_1 in the cache */

/* search696_0_2 -> search680_0_2 in the cache */
/* search696_0 -> search680_0 in the cache */

/* search696_1 -> search680_1 in the cache */
static const nir_search_expression search696 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search680_0.value, &search680_1.value },
   NULL,
};

   /* replace696_0 -> replace72_0 in the cache */

/* replace696_1_0 -> search73_0_1 in the cache */

/* replace696_1_1 -> search73_1 in the cache */
static const nir_search_expression replace696_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace696_2_0 -> search73_0_2 in the cache */

/* replace696_2_1 -> search73_1 in the cache */
static const nir_search_expression replace696_2 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace696 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &replace696_1.value, &replace696_2.value },
   NULL,
};

   /* search697_0 -> search681_0 in the cache */

/* search697_1_0 -> search119_0_1_0_0_0 in the cache */

/* search697_1_1 -> search681_1_1 in the cache */

/* search697_1_2 -> search681_1_2 in the cache */
/* search697_1 -> search681_1 in the cache */
static const nir_search_expression search697 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &search681_0.value, &search681_1.value },
   NULL,
};

   /* replace697_0 -> search119_0_1_0_0_0 in the cache */

/* replace697_1_0 -> replace681_1_0 in the cache */

/* replace697_1_1 -> replace681_1_1 in the cache */
static const nir_search_expression replace697_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &replace681_1_0.value, &replace681_1_1.value },
   NULL,
};

/* replace697_2_0 -> replace681_1_0 in the cache */

/* replace697_2_1 -> replace681_2_1 in the cache */
static const nir_search_expression replace697_2 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_ult,
   { &replace681_1_0.value, &replace681_2_1.value },
   NULL,
};
static const nir_search_expression replace697 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search119_0_1_0_0_0.value, &replace697_1.value, &replace697_2.value },
   NULL,
};

   /* search698_0_0 -> replace72_0 in the cache */

/* search698_0_1 -> search680_0_1 in the cache */

/* search698_0_2 -> search680_0_2 in the cache */
/* search698_0 -> search680_0 in the cache */

/* search698_1 -> search680_1 in the cache */
static const nir_search_expression search698 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search680_0.value, &search680_1.value },
   NULL,
};

   /* replace698_0 -> replace72_0 in the cache */

/* replace698_1_0 -> search73_0_1 in the cache */

/* replace698_1_1 -> search73_1 in the cache */
static const nir_search_expression replace698_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace698_2_0 -> search73_0_2 in the cache */

/* replace698_2_1 -> search73_1 in the cache */
static const nir_search_expression replace698_2 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace698 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &replace698_1.value, &replace698_2.value },
   NULL,
};

   /* search699_0 -> search681_0 in the cache */

/* search699_1_0 -> search119_0_1_0_0_0 in the cache */

/* search699_1_1 -> search681_1_1 in the cache */

/* search699_1_2 -> search681_1_2 in the cache */
/* search699_1 -> search681_1 in the cache */
static const nir_search_expression search699 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &search681_0.value, &search681_1.value },
   NULL,
};

   /* replace699_0 -> search119_0_1_0_0_0 in the cache */

/* replace699_1_0 -> replace681_1_0 in the cache */

/* replace699_1_1 -> replace681_1_1 in the cache */
static const nir_search_expression replace699_1 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &replace681_1_0.value, &replace681_1_1.value },
   NULL,
};

/* replace699_2_0 -> replace681_1_0 in the cache */

/* replace699_2_1 -> replace681_2_1 in the cache */
static const nir_search_expression replace699_2 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_uge,
   { &replace681_1_0.value, &replace681_2_1.value },
   NULL,
};
static const nir_search_expression replace699 = {
   { nir_search_value_expression, 1 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &search119_0_1_0_0_0.value, &replace699_1.value, &replace699_2.value },
   NULL,
};

   /* search700_0_0 -> replace72_0 in the cache */

/* search700_0_1 -> search680_0_1 in the cache */

/* search700_0_2 -> search73_0_2 in the cache */
static const nir_search_expression search700_0 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 0,
   nir_op_bcsel,
   { &replace72_0.value, &search680_0_1.value, &search73_0_2.value },
   (is_used_once),
};

/* search700_1 -> search680_1 in the cache */
static const nir_search_expression search700 = {
   { nir_search_value_expression, -4 },
   false,
   0, 1,
   nir_op_fadd,
   { &search700_0.value, &search680_1.value },
   NULL,
};

   /* replace700_0 -> replace72_0 in the cache */

/* replace700_1_0 -> search73_0_1 in the cache */

/* replace700_1_1 -> search73_1 in the cache */
static const nir_search_expression replace700_1 = {
   { nir_search_value_expression, -4 },
   false,
   0, 1,
   nir_op_fadd,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace700_2_0 -> search73_0_2 in the cache */

/* replace700_2_1 -> search73_1 in the cache */
static const nir_search_expression replace700_2 = {
   { nir_search_value_expression, -4 },
   false,
   1, 1,
   nir_op_fadd,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace700 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace72_0.value, &replace700_1.value, &replace700_2.value },
   NULL,
};

   /* search701_0_0 -> replace72_0 in the cache */

/* search701_0_1 -> search680_0_1 in the cache */

/* search701_0_2 -> search73_0_2 in the cache */
/* search701_0 -> search700_0 in the cache */

/* search701_1 -> search680_1 in the cache */
static const nir_search_expression search701 = {
   { nir_search_value_expression, -4 },
   false,
   0, 1,
   nir_op_fmul,
   { &search700_0.value, &search680_1.value },
   NULL,
};

   /* replace701_0 -> replace72_0 in the cache */

/* replace701_1_0 -> search73_0_1 in the cache */

/* replace701_1_1 -> search73_1 in the cache */
static const nir_search_expression replace701_1 = {
   { nir_search_value_expression, -4 },
   false,
   0, 1,
   nir_op_fmul,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace701_2_0 -> search73_0_2 in the cache */

/* replace701_2_1 -> search73_1 in the cache */
static const nir_search_expression replace701_2 = {
   { nir_search_value_expression, -4 },
   false,
   1, 1,
   nir_op_fmul,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace701 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace72_0.value, &replace701_1.value, &replace701_2.value },
   NULL,
};

   /* search702_0_0 -> replace72_0 in the cache */

/* search702_0_1 -> search680_0_1 in the cache */

/* search702_0_2 -> search73_0_2 in the cache */
/* search702_0 -> search700_0 in the cache */

/* search702_1 -> search680_1 in the cache */
static const nir_search_expression search702 = {
   { nir_search_value_expression, -4 },
   false,
   0, 1,
   nir_op_iadd,
   { &search700_0.value, &search680_1.value },
   NULL,
};

   /* replace702_0 -> replace72_0 in the cache */

/* replace702_1_0 -> search73_0_1 in the cache */

/* replace702_1_1 -> search73_1 in the cache */
static const nir_search_expression replace702_1 = {
   { nir_search_value_expression, -4 },
   false,
   0, 1,
   nir_op_iadd,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace702_2_0 -> search73_0_2 in the cache */

/* replace702_2_1 -> search73_1 in the cache */
static const nir_search_expression replace702_2 = {
   { nir_search_value_expression, -4 },
   false,
   1, 1,
   nir_op_iadd,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace702 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace72_0.value, &replace702_1.value, &replace702_2.value },
   NULL,
};

   /* search703_0_0 -> replace72_0 in the cache */

/* search703_0_1 -> search680_0_1 in the cache */

/* search703_0_2 -> search73_0_2 in the cache */
/* search703_0 -> search700_0 in the cache */

/* search703_1 -> search680_1 in the cache */
static const nir_search_expression search703 = {
   { nir_search_value_expression, -4 },
   false,
   0, 1,
   nir_op_imul,
   { &search700_0.value, &search680_1.value },
   NULL,
};

   /* replace703_0 -> replace72_0 in the cache */

/* replace703_1_0 -> search73_0_1 in the cache */

/* replace703_1_1 -> search73_1 in the cache */
static const nir_search_expression replace703_1 = {
   { nir_search_value_expression, -4 },
   false,
   0, 1,
   nir_op_imul,
   { &search73_0_1.value, &search73_1.value },
   NULL,
};

/* replace703_2_0 -> search73_0_2 in the cache */

/* replace703_2_1 -> search73_1 in the cache */
static const nir_search_expression replace703_2 = {
   { nir_search_value_expression, -4 },
   false,
   1, 1,
   nir_op_imul,
   { &search73_0_2.value, &search73_1.value },
   NULL,
};
static const nir_search_expression replace703 = {
   { nir_search_value_expression, -4 },
   false,
   -1, 2,
   nir_op_bcsel,
   { &replace72_0.value, &replace703_1.value, &replace703_2.value },
   NULL,
};

   /* search704_0 -> search6_0 in the cache */
static const nir_search_expression search704 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fddx,
   { &search6_0.value },
   NULL,
};

   /* replace704 -> search23_1 in the cache */

   /* search705_0 -> search6_0 in the cache */
static const nir_search_expression search705 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fddx_fine,
   { &search6_0.value },
   NULL,
};

   /* replace705 -> search23_1 in the cache */

   /* search706_0 -> search6_0 in the cache */
static const nir_search_expression search706 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fddx_coarse,
   { &search6_0.value },
   NULL,
};

   /* replace706 -> search23_1 in the cache */

   /* search707_0 -> search6_0 in the cache */
static const nir_search_expression search707 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fddy,
   { &search6_0.value },
   NULL,
};

   /* replace707 -> search23_1 in the cache */

   /* search708_0 -> search6_0 in the cache */
static const nir_search_expression search708 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fddy_fine,
   { &search6_0.value },
   NULL,
};

   /* replace708 -> search23_1 in the cache */

   /* search709_0 -> search6_0 in the cache */
static const nir_search_expression search709 = {
   { nir_search_value_expression, -1 },
   false,
   -1, 0,
   nir_op_fddy_coarse,
   { &search6_0.value },
   NULL,
};

   /* replace709 -> search23_1 in the cache */


static const struct transform nir_opt_algebraic_state3_xforms[] = {
  { &search0, &replace0.value, 0 },
  { &search1, &replace1.value, 0 },
  { &search36, &replace8.value, 0 },
  { &search40, &search6_0.value, 0 },
  { &search42, &search15_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state5_xforms[] = {
  { &search4, &replace4.value, 1 },
};
static const struct transform nir_opt_algebraic_state6_xforms[] = {
  { &search5, &replace5.value, 1 },
};
static const struct transform nir_opt_algebraic_state7_xforms[] = {
  { &search6, &search6_0.value, 0 },
  { &search10, &replace10.value, 0 },
};
static const struct transform nir_opt_algebraic_state8_xforms[] = {
  { &search7, &search6_0.value, 0 },
  { &search11, &replace11.value, 2 },
  { &search12, &replace12.value, 2 },
};
static const struct transform nir_opt_algebraic_state9_xforms[] = {
  { &search8, &replace8.value, 0 },
  { &search13, &replace13.value, 0 },
};
static const struct transform nir_opt_algebraic_state10_xforms[] = {
  { &search9, &replace8.value, 0 },
};
static const struct transform nir_opt_algebraic_state11_xforms[] = {
  { &search14_0, &replace479.value, 26 },
};
static const struct transform nir_opt_algebraic_state12_xforms[] = {
  { &search15_0, &replace480.value, 26 },
};
static const struct transform nir_opt_algebraic_state17_xforms[] = {
  { &search367, &replace367.value, 0 },
  { &search368, &replace132.value, 0 },
};
static const struct transform nir_opt_algebraic_state19_xforms[] = {
  { &search23, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state21_xforms[] = {
  { &search24, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state22_xforms[] = {
  { &search25, &search0_0.value, 0 },
  { &search26, &search26_1.value, 0 },
};
static const struct transform nir_opt_algebraic_state24_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state25_xforms[] = {
  { &search37, &search25_1.value, 0 },
  { &search38, &search0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state26_xforms[] = {
  { &search43_0, &replace537.value, 52 },
};
static const struct transform nir_opt_algebraic_state27_xforms[] = {
  { &search70, &replace70.value, 13 },
};
static const struct transform nir_opt_algebraic_state28_xforms[] = {
  { &search47, &replace47.value, 0 },
  { &search70, &replace70.value, 13 },
};
static const struct transform nir_opt_algebraic_state29_xforms[] = {
  { &search46, &replace13_1_0.value, 0 },
  { &search48, &replace48.value, 0 },
  { &search70, &replace70.value, 13 },
};
static const struct transform nir_opt_algebraic_state30_xforms[] = {
  { &search46, &replace13_1_0.value, 0 },
  { &search47, &replace47.value, 0 },
  { &search48, &replace48.value, 0 },
  { &search70, &replace70.value, 13 },
};
static const struct transform nir_opt_algebraic_state31_xforms[] = {
  { &search45, &replace13_1_0.value, 0 },
  { &search49, &replace48.value, 0 },
  { &search70, &replace70.value, 13 },
};
static const struct transform nir_opt_algebraic_state32_xforms[] = {
  { &search45, &replace13_1_0.value, 0 },
  { &search47, &replace47.value, 0 },
  { &search49, &replace48.value, 0 },
  { &search70, &replace70.value, 13 },
};
static const struct transform nir_opt_algebraic_state33_xforms[] = {
  { &search45, &replace13_1_0.value, 0 },
  { &search46, &replace13_1_0.value, 0 },
  { &search48, &replace48.value, 0 },
  { &search49, &replace48.value, 0 },
  { &search70, &replace70.value, 13 },
};
static const struct transform nir_opt_algebraic_state34_xforms[] = {
  { &search45, &replace13_1_0.value, 0 },
  { &search46, &replace13_1_0.value, 0 },
  { &search47, &replace47.value, 0 },
  { &search48, &replace48.value, 0 },
  { &search49, &replace48.value, 0 },
  { &search70, &replace70.value, 13 },
};
static const struct transform nir_opt_algebraic_state35_xforms[] = {
  { &search52, &search13_0.value, 0 },
  { &search56, &replace56.value, 4 },
  { &search57, &replace57.value, 3 },
  { &search58, &replace58.value, 5 },
};
static const struct transform nir_opt_algebraic_state36_xforms[] = {
  { &search50, &search13_0.value, 0 },
  { &search51, &replace13_1_0.value, 0 },
  { &search52, &search13_0.value, 0 },
  { &search56, &replace56.value, 4 },
  { &search57, &replace57.value, 3 },
  { &search58, &replace58.value, 5 },
};
static const struct transform nir_opt_algebraic_state37_xforms[] = {
  { &search52, &search13_0.value, 0 },
  { &search55, &replace55.value, 0 },
  { &search56, &replace56.value, 4 },
  { &search57, &replace57.value, 3 },
  { &search58, &replace58.value, 5 },
};
static const struct transform nir_opt_algebraic_state38_xforms[] = {
  { &search50, &search13_0.value, 0 },
  { &search51, &replace13_1_0.value, 0 },
  { &search52, &search13_0.value, 0 },
  { &search55, &replace55.value, 0 },
  { &search56, &replace56.value, 4 },
  { &search57, &replace57.value, 3 },
  { &search58, &replace58.value, 5 },
};
static const struct transform nir_opt_algebraic_state39_xforms[] = {
  { &search52, &search13_0.value, 0 },
  { &search53, &replace47.value, 0 },
  { &search56, &replace56.value, 4 },
  { &search57, &replace57.value, 3 },
  { &search58, &replace58.value, 5 },
};
static const struct transform nir_opt_algebraic_state40_xforms[] = {
  { &search50, &search13_0.value, 0 },
  { &search51, &replace13_1_0.value, 0 },
  { &search52, &search13_0.value, 0 },
  { &search53, &replace47.value, 0 },
  { &search56, &replace56.value, 4 },
  { &search57, &replace57.value, 3 },
  { &search58, &replace58.value, 5 },
};
static const struct transform nir_opt_algebraic_state41_xforms[] = {
  { &search52, &search13_0.value, 0 },
  { &search53, &replace47.value, 0 },
  { &search55, &replace55.value, 0 },
  { &search56, &replace56.value, 4 },
  { &search57, &replace57.value, 3 },
  { &search58, &replace58.value, 5 },
};
static const struct transform nir_opt_algebraic_state42_xforms[] = {
  { &search50, &search13_0.value, 0 },
  { &search51, &replace13_1_0.value, 0 },
  { &search52, &search13_0.value, 0 },
  { &search53, &replace47.value, 0 },
  { &search55, &replace55.value, 0 },
  { &search56, &replace56.value, 4 },
  { &search57, &replace57.value, 3 },
  { &search58, &replace58.value, 5 },
};
static const struct transform nir_opt_algebraic_state44_xforms[] = {
  { &search59, &replace59.value, 6 },
};
static const struct transform nir_opt_algebraic_state45_xforms[] = {
  { &search60, &replace60.value, 7 },
};
static const struct transform nir_opt_algebraic_state46_xforms[] = {
  { &replace60_1, &replace62.value, 9 },
};
static const struct transform nir_opt_algebraic_state47_xforms[] = {
  { &search63, &replace63.value, 10 },
};
static const struct transform nir_opt_algebraic_state48_xforms[] = {
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state49_xforms[] = {
  { &search305, &replace305.value, 0 },
  { &search316, &search6_0.value, 0 },
  { &search317, &search6_0.value, 0 },
  { &search318, &replace8.value, 0 },
  { &search422, &replace422.value, 23 },
  { &search472, &replace472.value, 24 },
};
static const struct transform nir_opt_algebraic_state56_xforms[] = {
  { &search333, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state57_xforms[] = {
  { &search332, &search130_1.value, 0 },
};
static const struct transform nir_opt_algebraic_state58_xforms[] = {
  { &search332, &search130_1.value, 0 },
  { &search333, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state71_xforms[] = {
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state72_xforms[] = {
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state73_xforms[] = {
  { &search313, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state74_xforms[] = {
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state75_xforms[] = {
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state76_xforms[] = {
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state77_xforms[] = {
  { &search311, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state78_xforms[] = {
  { &search311, &replace134.value, 0 },
  { &search369, &replace72_0.value, 0 },
  { &search372, &replace91.value, 0 },
};
static const struct transform nir_opt_algebraic_state79_xforms[] = {
  { &search312, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state80_xforms[] = {
  { &search312, &replace136.value, 0 },
  { &search370, &replace91.value, 0 },
  { &search371, &replace72_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state81_xforms[] = {
  { &search172, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state82_xforms[] = {
  { &search172, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state83_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state84_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state85_xforms[] = {
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state86_xforms[] = {
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search373, &replace72_0.value, 0 },
  { &search374, &replace91.value, 0 },
  { &search375, &replace375.value, 0 },
  { &search376, &replace376.value, 0 },
  { &search377, &replace377.value, 0 },
  { &search378, &replace378.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
  { &search385, &replace385.value, 0 },
  { &search386, &replace386.value, 0 },
};
static const struct transform nir_opt_algebraic_state87_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search379, &search155_0_0.value, 0 },
  { &search380, &search55_2.value, 0 },
  { &search382, &replace382.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state88_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search379, &search155_0_0.value, 0 },
  { &search380, &search55_2.value, 0 },
  { &search382, &replace382.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state89_xforms[] = {
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search379, &search155_0_0.value, 0 },
  { &search380, &search55_2.value, 0 },
  { &search382, &replace382.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state90_xforms[] = {
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search373, &replace72_0.value, 0 },
  { &search374, &replace91.value, 0 },
  { &search375, &replace375.value, 0 },
  { &search376, &replace376.value, 0 },
  { &search377, &replace377.value, 0 },
  { &search378, &replace378.value, 0 },
  { &search379, &search155_0_0.value, 0 },
  { &search380, &search55_2.value, 0 },
  { &search382, &replace382.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
  { &search385, &replace385.value, 0 },
  { &search386, &replace386.value, 0 },
};
static const struct transform nir_opt_algebraic_state91_xforms[] = {
  { &search171, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state92_xforms[] = {
  { &search171, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state94_xforms[] = {
  { &search173, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state95_xforms[] = {
  { &search173, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state96_xforms[] = {
  { &search174, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state97_xforms[] = {
  { &search174, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state98_xforms[] = {
  { &search175, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state99_xforms[] = {
  { &search175, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state100_xforms[] = {
  { &search176, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state101_xforms[] = {
  { &search176, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state102_xforms[] = {
  { &replace197, &replace201.value, 16 },
};
static const struct transform nir_opt_algebraic_state103_xforms[] = {
  { &search525, &replace525.value, 41 },
};
static const struct transform nir_opt_algebraic_state104_xforms[] = {
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state105_xforms[] = {
  { &search319, &search6_0.value, 0 },
  { &search320, &search6_0.value, 0 },
  { &search321, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state107_xforms[] = {
  { &search335, &search6_0.value, 0 },
  { &search419, &replace419.value, 23 },
  { &search420, &replace420.value, 23 },
  { &search421, &replace421.value, 23 },
  { &search436_0, &replace471.value, 24 },
};
static const struct transform nir_opt_algebraic_state108_xforms[] = {
  { &search334, &search130_1.value, 0 },
};
static const struct transform nir_opt_algebraic_state109_xforms[] = {
  { &search334, &search130_1.value, 0 },
  { &search335, &search6_0.value, 0 },
  { &search419, &replace419.value, 23 },
  { &search420, &replace420.value, 23 },
  { &search421, &replace421.value, 23 },
  { &search436_0, &replace471.value, 24 },
};
static const struct transform nir_opt_algebraic_state110_xforms[] = {
  { &search292_0, &replace296.value, 17 },
};
static const struct transform nir_opt_algebraic_state111_xforms[] = {
  { &search293_0, &replace297.value, 17 },
};
static const struct transform nir_opt_algebraic_state112_xforms[] = {
  { &search294_0, &replace298.value, 17 },
};
static const struct transform nir_opt_algebraic_state113_xforms[] = {
  { &search295_0, &replace299.value, 17 },
};
static const struct transform nir_opt_algebraic_state114_xforms[] = {
  { &search477, &replace477.value, 25 },
};
static const struct transform nir_opt_algebraic_state115_xforms[] = {
  { &search477, &replace477.value, 25 },
};
static const struct transform nir_opt_algebraic_state116_xforms[] = {
  { &search315, &search244_0_1.value, 0 },
};
static const struct transform nir_opt_algebraic_state117_xforms[] = {
  { &search322, &search244_0_1.value, 0 },
};
static const struct transform nir_opt_algebraic_state118_xforms[] = {
  { &search323, &replace8.value, 0 },
};
static const struct transform nir_opt_algebraic_state119_xforms[] = {
  { &search323, &replace8.value, 0 },
  { &search324, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state120_xforms[] = {
  { &search337, &search6_0.value, 0 },
  { &search416, &replace416.value, 23 },
  { &search338_1, &replace417.value, 23 },
  { &search418, &replace418.value, 23 },
  { &search339_1, &replace469.value, 24 },
};
static const struct transform nir_opt_algebraic_state121_xforms[] = {
  { &search336, &search130_1.value, 0 },
};
static const struct transform nir_opt_algebraic_state122_xforms[] = {
  { &search336, &search130_1.value, 0 },
  { &search337, &search6_0.value, 0 },
  { &search416, &replace416.value, 23 },
  { &search338_1, &replace417.value, 23 },
  { &search418, &replace418.value, 23 },
  { &search339_1, &replace469.value, 24 },
};
static const struct transform nir_opt_algebraic_state125_xforms[] = {
  { &search342, &replace342.value, 18 },
};
static const struct transform nir_opt_algebraic_state126_xforms[] = {
  { &search342, &replace342.value, 18 },
  { &search347, &search6_0.value, 0 },
  { &search348, &replace345.value, 0 },
  { &search349, &replace346.value, 0 },
};
static const struct transform nir_opt_algebraic_state127_xforms[] = {
  { &search342, &replace342.value, 18 },
  { &search350, &search341_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state128_xforms[] = {
  { &search342, &replace342.value, 18 },
  { &search347, &search6_0.value, 0 },
  { &search348, &replace345.value, 0 },
  { &search349, &replace346.value, 0 },
  { &search350, &search341_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state129_xforms[] = {
  { &search356_0, &replace365.value, 21 },
};
static const struct transform nir_opt_algebraic_state132_xforms[] = {
  { &search362, &replace362.value, 20 },
};
static const struct transform nir_opt_algebraic_state133_xforms[] = {
  { &search361, &search357_0.value, 0 },
  { &search362, &replace362.value, 20 },
};
static const struct transform nir_opt_algebraic_state134_xforms[] = {
  { &search384, &replace0_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state138_xforms[] = {
  { &search527, &replace527.value, 42 },
};
static const struct transform nir_opt_algebraic_state139_xforms[] = {
  { &search527, &replace527.value, 42 },
};
static const struct transform nir_opt_algebraic_state140_xforms[] = {
  { &search524, &replace524.value, 41 },
};
static const struct transform nir_opt_algebraic_state141_xforms[] = {
  { &search478, &replace478.value, 25 },
};
static const struct transform nir_opt_algebraic_state142_xforms[] = {
  { &search478, &replace478.value, 25 },
};
static const struct transform nir_opt_algebraic_state143_xforms[] = {
  { &search475, &search0_0.value, 0 },
  { &search476, &search25_1.value, 0 },
};
static const struct transform nir_opt_algebraic_state144_xforms[] = {
  { &search523, &replace523.value, 40 },
};
static const struct transform nir_opt_algebraic_state145_xforms[] = {
  { &search522, &replace522.value, 39 },
};
static const struct transform nir_opt_algebraic_state147_xforms[] = {
  { &search503, &replace503.value, 27 },
  { &search504, &replace504.value, 28 },
  { &search505, &replace505.value, 29 },
};
static const struct transform nir_opt_algebraic_state148_xforms[] = {
  { &search506, &replace506.value, 28 },
};
static const struct transform nir_opt_algebraic_state149_xforms[] = {
  { &search507, &replace507.value, 30 },
};
static const struct transform nir_opt_algebraic_state150_xforms[] = {
  { &search508, &replace508.value, 31 },
};
static const struct transform nir_opt_algebraic_state151_xforms[] = {
  { &search509, &replace509.value, 32 },
  { &search509, &replace516.value, 35 },
};
static const struct transform nir_opt_algebraic_state152_xforms[] = {
  { &search510, &replace510.value, 33 },
};
static const struct transform nir_opt_algebraic_state153_xforms[] = {
  { &search511, &replace511.value, 33 },
};
static const struct transform nir_opt_algebraic_state154_xforms[] = {
  { &search512, &replace512.value, 33 },
};
static const struct transform nir_opt_algebraic_state155_xforms[] = {
  { &search513, &replace513.value, 33 },
};
static const struct transform nir_opt_algebraic_state156_xforms[] = {
  { &search514, &replace514.value, 34 },
};
static const struct transform nir_opt_algebraic_state157_xforms[] = {
  { &search515, &replace515.value, 34 },
};
static const struct transform nir_opt_algebraic_state158_xforms[] = {
  { &search517, &replace517.value, 36 },
};
static const struct transform nir_opt_algebraic_state159_xforms[] = {
  { &search518, &replace518.value, 37 },
  { &search518, &replace520.value, 38 },
};
static const struct transform nir_opt_algebraic_state160_xforms[] = {
  { &search519, &replace519.value, 37 },
  { &search519, &replace521.value, 38 },
};
static const struct transform nir_opt_algebraic_state161_xforms[] = {
  { &search526, &replace526.value, 42 },
};
static const struct transform nir_opt_algebraic_state162_xforms[] = {
  { &search528, &replace528.value, 43 },
};
static const struct transform nir_opt_algebraic_state163_xforms[] = {
  { &search529, &replace529.value, 44 },
};
static const struct transform nir_opt_algebraic_state164_xforms[] = {
  { &search530, &replace530.value, 45 },
};
static const struct transform nir_opt_algebraic_state165_xforms[] = {
  { &search531, &replace531.value, 46 },
};
static const struct transform nir_opt_algebraic_state166_xforms[] = {
  { &search532, &replace532.value, 47 },
};
static const struct transform nir_opt_algebraic_state167_xforms[] = {
  { &search533, &replace533.value, 48 },
};
static const struct transform nir_opt_algebraic_state168_xforms[] = {
  { &search534, &replace534.value, 49 },
};
static const struct transform nir_opt_algebraic_state169_xforms[] = {
  { &search535, &replace535.value, 50 },
};
static const struct transform nir_opt_algebraic_state170_xforms[] = {
  { &search536, &replace536.value, 51 },
};
static const struct transform nir_opt_algebraic_state171_xforms[] = {
  { &search538, &replace538.value, 34 },
  { &search540, &replace540.value, 34 },
  { &search542, &replace542.value, 34 },
  { &search544, &replace544.value, 34 },
};
static const struct transform nir_opt_algebraic_state172_xforms[] = {
  { &search539, &replace539.value, 34 },
  { &search541, &replace541.value, 34 },
  { &search543, &replace543.value, 34 },
  { &search545, &replace545.value, 34 },
};
static const struct transform nir_opt_algebraic_state173_xforms[] = {
  { &search587, &search56_0.value, 0 },
  { &search588, &search0_0.value, 0 },
  { &search589, &search58_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state174_xforms[] = {
  { &search582, &replace72_0.value, 0 },
  { &search583, &search538_0.value, 0 },
  { &search584, &search56_0.value, 0 },
  { &search585, &search0_0.value, 0 },
  { &search586, &search58_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state175_xforms[] = {
  { &search577, &replace72_0.value, 0 },
  { &search578, &search538_0.value, 0 },
  { &search579, &search56_0.value, 0 },
  { &search580, &search0_0.value, 0 },
  { &search581, &search58_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state176_xforms[] = {
  { &search670, &replace670.value, 53 },
  { &search671, &replace671.value, 53 },
  { &search672, &replace672.value, 53 },
};
static const struct transform nir_opt_algebraic_state177_xforms[] = {
  { &search704, &search23_1.value, 54 },
};
static const struct transform nir_opt_algebraic_state178_xforms[] = {
  { &search705, &search23_1.value, 54 },
};
static const struct transform nir_opt_algebraic_state179_xforms[] = {
  { &search706, &search23_1.value, 54 },
};
static const struct transform nir_opt_algebraic_state180_xforms[] = {
  { &search707, &search23_1.value, 54 },
};
static const struct transform nir_opt_algebraic_state181_xforms[] = {
  { &search708, &search23_1.value, 54 },
};
static const struct transform nir_opt_algebraic_state182_xforms[] = {
  { &search709, &search23_1.value, 54 },
};
static const struct transform nir_opt_algebraic_state183_xforms[] = {
  { &search486, &replace486.value, 0 },
};
static const struct transform nir_opt_algebraic_state184_xforms[] = {
  { &search0, &replace0.value, 0 },
  { &search1, &replace1.value, 0 },
  { &search36, &replace8.value, 0 },
  { &search40, &search6_0.value, 0 },
  { &search42, &search15_0.value, 0 },
  { &search488, &replace488.value, 0 },
};
static const struct transform nir_opt_algebraic_state185_xforms[] = {
  { &search0, &replace0.value, 0 },
  { &search1, &replace1.value, 0 },
  { &search36, &replace8.value, 0 },
  { &search40, &search6_0.value, 0 },
  { &search42, &search15_0.value, 0 },
  { &search488, &replace488.value, 0 },
  { &search492, &replace488.value, 0 },
};
static const struct transform nir_opt_algebraic_state186_xforms[] = {
  { &search0, &replace0.value, 0 },
  { &search1, &replace1.value, 0 },
  { &search36, &replace8.value, 0 },
  { &search40, &search6_0.value, 0 },
  { &search42, &search15_0.value, 0 },
  { &search486, &replace486.value, 0 },
};
static const struct transform nir_opt_algebraic_state187_xforms[] = {
  { &search0, &replace0.value, 0 },
  { &search1, &replace1.value, 0 },
  { &search36, &replace8.value, 0 },
  { &search40, &search6_0.value, 0 },
  { &search42, &search15_0.value, 0 },
  { &search703, &replace703.value, 0 },
};
static const struct transform nir_opt_algebraic_state188_xforms[] = {
  { &search302, &replace302.value, 0 },
};
static const struct transform nir_opt_algebraic_state189_xforms[] = {
  { &search30, &replace8.value, 0 },
};
static const struct transform nir_opt_algebraic_state190_xforms[] = {
  { &search482, &search478.value, 0 },
};
static const struct transform nir_opt_algebraic_state191_xforms[] = {
  { &search24, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state192_xforms[] = {
  { &search24, &search6_0.value, 0 },
  { &search30, &replace8.value, 0 },
};
static const struct transform nir_opt_algebraic_state193_xforms[] = {
  { &search24, &search6_0.value, 0 },
  { &search490, &replace490.value, 0 },
};
static const struct transform nir_opt_algebraic_state194_xforms[] = {
  { &search24, &search6_0.value, 0 },
  { &search490, &replace490.value, 0 },
  { &search495, &replace490.value, 0 },
};
static const struct transform nir_opt_algebraic_state195_xforms[] = {
  { &search24, &search6_0.value, 0 },
  { &search702, &replace702.value, 0 },
};
static const struct transform nir_opt_algebraic_state196_xforms[] = {
  { &search24, &search6_0.value, 0 },
  { &search482, &search478.value, 0 },
};
static const struct transform nir_opt_algebraic_state197_xforms[] = {
  { &search28, &replace28.value, 0 },
};
static const struct transform nir_opt_algebraic_state198_xforms[] = {
  { &search30, &replace8.value, 0 },
  { &search31, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state199_xforms[] = {
  { &search30, &replace8.value, 0 },
  { &search482, &search478.value, 0 },
};
static const struct transform nir_opt_algebraic_state200_xforms[] = {
  { &search394, &replace394.value, 0 },
};
static const struct transform nir_opt_algebraic_state201_xforms[] = {
  { &search332, &search130_1.value, 0 },
  { &search394, &replace394.value, 0 },
};
static const struct transform nir_opt_algebraic_state202_xforms[] = {
  { &search80, &replace80.value, 0 },
  { &search333, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state203_xforms[] = {
  { &search415, &search58_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state204_xforms[] = {
  { &search2, &replace2.value, 0 },
};
static const struct transform nir_opt_algebraic_state205_xforms[] = {
  { &search3, &replace2.value, 0 },
};
static const struct transform nir_opt_algebraic_state206_xforms[] = {
  { &search413, &search0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state207_xforms[] = {
  { &search14, &search6_0.value, 0 },
  { &search14_0, &replace479.value, 26 },
};
static const struct transform nir_opt_algebraic_state208_xforms[] = {
  { &search14_0, &replace479.value, 26 },
};
static const struct transform nir_opt_algebraic_state209_xforms[] = {
  { &search14_0, &replace479.value, 26 },
};
static const struct transform nir_opt_algebraic_state210_xforms[] = {
  { &search14_0, &replace479.value, 26 },
};
static const struct transform nir_opt_algebraic_state211_xforms[] = {
  { &search14_0, &replace479.value, 26 },
};
static const struct transform nir_opt_algebraic_state212_xforms[] = {
  { &search17, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state213_xforms[] = {
  { &search16, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state214_xforms[] = {
  { &search18, &search18_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state215_xforms[] = {
  { &search402, &search200_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state216_xforms[] = {
  { &search292, &search292_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state217_xforms[] = {
  { &search293, &search293_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state218_xforms[] = {
  { &search294, &search294_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state219_xforms[] = {
  { &search295, &search295_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state220_xforms[] = {
  { &search483, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state222_xforms[] = {
  { &search21, &replace21.value, 0 },
};
static const struct transform nir_opt_algebraic_state223_xforms[] = {
  { &search566, &replace72_0.value, 0 },
  { &search568, &search0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state224_xforms[] = {
  { &search29, &search23_1.value, 0 },
};
static const struct transform nir_opt_algebraic_state225_xforms[] = {
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state226_xforms[] = {
  { &search481, &search477.value, 0 },
};
static const struct transform nir_opt_algebraic_state227_xforms[] = {
  { &search23, &search6_0.value, 0 },
  { &search29, &search23_1.value, 0 },
};
static const struct transform nir_opt_algebraic_state228_xforms[] = {
  { &search23, &search6_0.value, 0 },
  { &search489, &replace489.value, 0 },
};
static const struct transform nir_opt_algebraic_state229_xforms[] = {
  { &search23, &search6_0.value, 0 },
  { &search489, &replace489.value, 0 },
  { &search493, &replace489.value, 0 },
};
static const struct transform nir_opt_algebraic_state230_xforms[] = {
  { &search23, &search6_0.value, 0 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state231_xforms[] = {
  { &search23, &search6_0.value, 0 },
  { &search700, &replace700.value, 0 },
};
static const struct transform nir_opt_algebraic_state232_xforms[] = {
  { &search23, &search6_0.value, 0 },
  { &search481, &search477.value, 0 },
};
static const struct transform nir_opt_algebraic_state233_xforms[] = {
  { &search29, &search23_1.value, 0 },
  { &search33, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state234_xforms[] = {
  { &search29, &search23_1.value, 0 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state235_xforms[] = {
  { &search29, &search23_1.value, 0 },
  { &search481, &search477.value, 0 },
};
static const struct transform nir_opt_algebraic_state236_xforms[] = {
  { &search27, &replace27.value, 0 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state237_xforms[] = {
  { &search71, &search70.value, 14 },
  { &search481, &search477.value, 0 },
};
static const struct transform nir_opt_algebraic_state239_xforms[] = {
  { &search485, &replace485.value, 0 },
};
static const struct transform nir_opt_algebraic_state243_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
  { &search485, &replace485.value, 0 },
};
static const struct transform nir_opt_algebraic_state244_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
  { &search487, &replace487.value, 0 },
};
static const struct transform nir_opt_algebraic_state245_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
  { &search487, &replace487.value, 0 },
  { &search491, &replace487.value, 0 },
};
static const struct transform nir_opt_algebraic_state246_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state247_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state248_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
  { &search701, &replace701.value, 0 },
};
static const struct transform nir_opt_algebraic_state249_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state250_xforms[] = {
  { &search485, &replace485.value, 0 },
};
static const struct transform nir_opt_algebraic_state251_xforms[] = {
  { &search485, &replace485.value, 0 },
};
static const struct transform nir_opt_algebraic_state252_xforms[] = {
  { &search485, &replace485.value, 0 },
};
static const struct transform nir_opt_algebraic_state253_xforms[] = {
  { &search43, &replace43.value, 0 },
};
static const struct transform nir_opt_algebraic_state256_xforms[] = {
  { &search303, &replace150.value, 0 },
};
static const struct transform nir_opt_algebraic_state258_xforms[] = {
  { &search360, &replace360.value, 0 },
};
static const struct transform nir_opt_algebraic_state259_xforms[] = {
  { &search117, &replace59_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state260_xforms[] = {
  { &search250, &replace250.value, 0 },
};
static const struct transform nir_opt_algebraic_state261_xforms[] = {
  { &search254, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state262_xforms[] = {
  { &search117, &replace59_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state263_xforms[] = {
  { &search144, &replace144.value, 0 },
};
static const struct transform nir_opt_algebraic_state264_xforms[] = {
  { &search137, &replace137.value, 0 },
};
static const struct transform nir_opt_algebraic_state265_xforms[] = {
  { &search250, &replace250.value, 0 },
};
static const struct transform nir_opt_algebraic_state266_xforms[] = {
  { &search681, &replace681.value, 0 },
};
static const struct transform nir_opt_algebraic_state267_xforms[] = {
  { &search254, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state268_xforms[] = {
  { &search143, &replace143.value, 0 },
};
static const struct transform nir_opt_algebraic_state269_xforms[] = {
  { &search136, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state270_xforms[] = {
  { &search120, &replace120.value, 0 },
};
static const struct transform nir_opt_algebraic_state271_xforms[] = {
  { &search120, &replace120.value, 0 },
};
static const struct transform nir_opt_algebraic_state272_xforms[] = {
  { &search117, &replace59_0.value, 0 },
  { &search120, &replace120.value, 0 },
};
static const struct transform nir_opt_algebraic_state273_xforms[] = {
  { &search120, &replace120.value, 0 },
  { &search250, &replace250.value, 0 },
};
static const struct transform nir_opt_algebraic_state274_xforms[] = {
  { &search120, &replace120.value, 0 },
  { &search254, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state275_xforms[] = {
  { &search255, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state276_xforms[] = {
  { &search255, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state277_xforms[] = {
  { &search117, &replace59_0.value, 0 },
  { &search255, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state278_xforms[] = {
  { &search250, &replace250.value, 0 },
  { &search255, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state279_xforms[] = {
  { &search254, &replace136.value, 0 },
  { &search255, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state280_xforms[] = {
  { &search680, &replace680.value, 0 },
};
static const struct transform nir_opt_algebraic_state281_xforms[] = {
  { &search251, &replace251.value, 0 },
};
static const struct transform nir_opt_algebraic_state282_xforms[] = {
  { &search251, &replace251.value, 0 },
};
static const struct transform nir_opt_algebraic_state283_xforms[] = {
  { &search117, &replace59_0.value, 0 },
  { &search251, &replace251.value, 0 },
};
static const struct transform nir_opt_algebraic_state284_xforms[] = {
  { &search250, &replace250.value, 0 },
  { &search251, &replace251.value, 0 },
};
static const struct transform nir_opt_algebraic_state285_xforms[] = {
  { &search251, &replace251.value, 0 },
  { &search254, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state286_xforms[] = {
  { &search142, &replace142.value, 0 },
};
static const struct transform nir_opt_algebraic_state287_xforms[] = {
  { &search118, &replace118.value, 0 },
};
static const struct transform nir_opt_algebraic_state288_xforms[] = {
  { &search256, &replace256.value, 0 },
};
static const struct transform nir_opt_algebraic_state289_xforms[] = {
  { &search252, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state290_xforms[] = {
  { &search118, &replace118.value, 0 },
};
static const struct transform nir_opt_algebraic_state291_xforms[] = {
  { &search146, &replace146.value, 0 },
};
static const struct transform nir_opt_algebraic_state292_xforms[] = {
  { &search135, &replace135.value, 0 },
};
static const struct transform nir_opt_algebraic_state293_xforms[] = {
  { &search91, &replace91.value, 0 },
};
static const struct transform nir_opt_algebraic_state294_xforms[] = {
  { &search256, &replace256.value, 0 },
};
static const struct transform nir_opt_algebraic_state295_xforms[] = {
  { &search683, &replace683.value, 0 },
};
static const struct transform nir_opt_algebraic_state296_xforms[] = {
  { &search252, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state297_xforms[] = {
  { &search141, &replace141.value, 0 },
};
static const struct transform nir_opt_algebraic_state298_xforms[] = {
  { &search134, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state299_xforms[] = {
  { &search121, &replace121.value, 0 },
};
static const struct transform nir_opt_algebraic_state300_xforms[] = {
  { &search121, &replace121.value, 0 },
};
static const struct transform nir_opt_algebraic_state301_xforms[] = {
  { &search118, &replace118.value, 0 },
  { &search121, &replace121.value, 0 },
};
static const struct transform nir_opt_algebraic_state302_xforms[] = {
  { &search121, &replace121.value, 0 },
  { &search256, &replace256.value, 0 },
};
static const struct transform nir_opt_algebraic_state303_xforms[] = {
  { &search121, &replace121.value, 0 },
  { &search252, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state304_xforms[] = {
  { &search253, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state305_xforms[] = {
  { &search253, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state306_xforms[] = {
  { &search118, &replace118.value, 0 },
  { &search253, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state307_xforms[] = {
  { &search253, &replace134.value, 0 },
  { &search256, &replace256.value, 0 },
};
static const struct transform nir_opt_algebraic_state308_xforms[] = {
  { &search252, &replace134.value, 0 },
  { &search253, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state309_xforms[] = {
  { &search682, &replace682.value, 0 },
};
static const struct transform nir_opt_algebraic_state310_xforms[] = {
  { &search257, &replace257.value, 0 },
};
static const struct transform nir_opt_algebraic_state311_xforms[] = {
  { &search257, &replace257.value, 0 },
};
static const struct transform nir_opt_algebraic_state312_xforms[] = {
  { &search118, &replace118.value, 0 },
  { &search257, &replace257.value, 0 },
};
static const struct transform nir_opt_algebraic_state313_xforms[] = {
  { &search256, &replace256.value, 0 },
  { &search257, &replace257.value, 0 },
};
static const struct transform nir_opt_algebraic_state314_xforms[] = {
  { &search252, &replace134.value, 0 },
  { &search257, &replace257.value, 0 },
};
static const struct transform nir_opt_algebraic_state315_xforms[] = {
  { &search140, &replace140.value, 0 },
};
static const struct transform nir_opt_algebraic_state316_xforms[] = {
  { &search301, &replace146.value, 0 },
};
static const struct transform nir_opt_algebraic_state317_xforms[] = {
  { &search122, &replace122.value, 0 },
};
static const struct transform nir_opt_algebraic_state318_xforms[] = {
  { &search301, &replace146.value, 0 },
};
static const struct transform nir_opt_algebraic_state319_xforms[] = {
  { &search133, &replace133.value, 0 },
};
static const struct transform nir_opt_algebraic_state320_xforms[] = {
  { &search122, &replace122.value, 0 },
};
static const struct transform nir_opt_algebraic_state321_xforms[] = {
  { &search128, &replace91.value, 0 },
};
static const struct transform nir_opt_algebraic_state322_xforms[] = {
  { &search684, &replace684.value, 0 },
  { &search685, &replace685.value, 0 },
};
static const struct transform nir_opt_algebraic_state323_xforms[] = {
  { &search139, &replace133.value, 0 },
};
static const struct transform nir_opt_algebraic_state324_xforms[] = {
  { &search122, &replace122.value, 0 },
  { &search301, &replace146.value, 0 },
};
static const struct transform nir_opt_algebraic_state325_xforms[] = {
  { &search111, &replace110.value, 0 },
};
static const struct transform nir_opt_algebraic_state326_xforms[] = {
  { &search300, &replace144.value, 0 },
};
static const struct transform nir_opt_algebraic_state327_xforms[] = {
  { &search123, &replace123.value, 0 },
};
static const struct transform nir_opt_algebraic_state328_xforms[] = {
  { &search132, &replace132.value, 0 },
};
static const struct transform nir_opt_algebraic_state329_xforms[] = {
  { &search129, &replace72_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state330_xforms[] = {
  { &search686, &replace686.value, 0 },
  { &search687, &replace687.value, 0 },
};
static const struct transform nir_opt_algebraic_state331_xforms[] = {
  { &search138, &replace132.value, 0 },
};
static const struct transform nir_opt_algebraic_state332_xforms[] = {
  { &search123, &replace123.value, 0 },
  { &search300, &replace144.value, 0 },
};
static const struct transform nir_opt_algebraic_state333_xforms[] = {
  { &search101, &replace100.value, 0 },
};
static const struct transform nir_opt_algebraic_state334_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search183, &search16_0.value, 0 },
  { &search183, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state335_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search193, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state336_xforms[] = {
  { &search148, &replace148.value, 0 },
  { &search172, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state337_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search177, &replace156.value, 0 },
};
static const struct transform nir_opt_algebraic_state338_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search177, &replace156.value, 0 },
};
static const struct transform nir_opt_algebraic_state339_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search177, &replace156.value, 0 },
  { &search183, &search16_0.value, 0 },
  { &search183, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state340_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search177, &replace156.value, 0 },
  { &search193, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state341_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search198, &replace197.value, 15 },
};
static const struct transform nir_opt_algebraic_state342_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search206, &replace206.value, 0 },
};
static const struct transform nir_opt_algebraic_state343_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search185, &search145_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state344_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search189, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state345_xforms[] = {
  { &search152, &replace152.value, 0 },
  { &search171, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state346_xforms[] = {
  { &search150, &replace150.value, 0 },
  { &search171, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state347_xforms[] = {
  { &search171, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state348_xforms[] = {
  { &search171, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state349_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search185, &search145_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state350_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search189, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state351_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search197, &replace197.value, 15 },
};
static const struct transform nir_opt_algebraic_state352_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search180, &replace157.value, 0 },
};
static const struct transform nir_opt_algebraic_state353_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search180, &replace157.value, 0 },
};
static const struct transform nir_opt_algebraic_state354_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search180, &replace157.value, 0 },
  { &search185, &search145_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state355_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search180, &replace157.value, 0 },
  { &search189, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state356_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search207, &replace207.value, 0 },
};
static const struct transform nir_opt_algebraic_state357_xforms[] = {
  { &search15, &search6_0.value, 0 },
  { &search15_0, &replace480.value, 26 },
};
static const struct transform nir_opt_algebraic_state358_xforms[] = {
  { &search15_0, &replace480.value, 26 },
};
static const struct transform nir_opt_algebraic_state359_xforms[] = {
  { &search306, &search0_0.value, 0 },
  { &search15_0, &replace480.value, 26 },
};
static const struct transform nir_opt_algebraic_state360_xforms[] = {
  { &search15_0, &replace480.value, 26 },
};
static const struct transform nir_opt_algebraic_state361_xforms[] = {
  { &search20, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state362_xforms[] = {
  { &search19, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state363_xforms[] = {
  { &search403, &search393_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state364_xforms[] = {
  { &search484, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state365_xforms[] = {
  { &search22, &replace22.value, 0 },
  { &search367, &replace367.value, 0 },
  { &search368, &replace132.value, 0 },
  { &search22, &replace22.value, 0 },
};
static const struct transform nir_opt_algebraic_state366_xforms[] = {
  { &search367, &replace367.value, 0 },
  { &search368, &replace132.value, 0 },
  { &search401, &replace22.value, 0 },
};
static const struct transform nir_opt_algebraic_state367_xforms[] = {
  { &search367, &replace367.value, 0 },
  { &search368, &replace132.value, 0 },
  { &search397, &search0_0.value, 0 },
  { &search567, &replace72_0.value, 0 },
  { &search397, &search0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state368_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search186, &replace186.value, 0 },
};
static const struct transform nir_opt_algebraic_state369_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search190, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state370_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search182, &replace182.value, 0 },
};
static const struct transform nir_opt_algebraic_state371_xforms[] = {
  { &search173, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state372_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search186, &replace186.value, 0 },
};
static const struct transform nir_opt_algebraic_state373_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search190, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state374_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search182, &replace182.value, 0 },
};
static const struct transform nir_opt_algebraic_state375_xforms[] = {
  { &search173, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state376_xforms[] = {
  { &search173, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state377_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search186, &replace186.value, 0 },
  { &search190, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state378_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search182, &replace182.value, 0 },
  { &search186, &replace186.value, 0 },
};
static const struct transform nir_opt_algebraic_state379_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search186, &replace186.value, 0 },
};
static const struct transform nir_opt_algebraic_state380_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search182, &replace182.value, 0 },
  { &search190, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state381_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search190, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state382_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search182, &replace182.value, 0 },
};
static const struct transform nir_opt_algebraic_state383_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search184, &search19_0.value, 0 },
  { &search184, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state384_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search194, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state385_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search179, &replace179.value, 0 },
};
static const struct transform nir_opt_algebraic_state386_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search184, &search19_0.value, 0 },
  { &search184, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state387_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search194, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state388_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search179, &replace179.value, 0 },
};
static const struct transform nir_opt_algebraic_state389_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search184, &search19_0.value, 0 },
  { &search194, &search19_0.value, 0 },
  { &search184, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state390_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search179, &replace179.value, 0 },
  { &search184, &search19_0.value, 0 },
  { &search184, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state391_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search179, &replace179.value, 0 },
  { &search194, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state392_xforms[] = {
  { &search406, &search0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state393_xforms[] = {
  { &search572, &search393_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state394_xforms[] = {
  { &search398, &replace398.value, 0 },
};
static const struct transform nir_opt_algebraic_state395_xforms[] = {
  { &search405, &search0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state396_xforms[] = {
  { &search408, &search0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state397_xforms[] = {
  { &search571, &search393_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state398_xforms[] = {
  { &search399, &replace399.value, 0 },
};
static const struct transform nir_opt_algebraic_state399_xforms[] = {
  { &search407, &search0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state400_xforms[] = {
  { &search395, &replace395.value, 0 },
};
static const struct transform nir_opt_algebraic_state401_xforms[] = {
  { &search334, &search130_1.value, 0 },
  { &search395, &replace395.value, 0 },
};
static const struct transform nir_opt_algebraic_state403_xforms[] = {
  { &search335, &search6_0.value, 0 },
  { &search419, &replace419.value, 23 },
  { &search420, &replace420.value, 23 },
  { &search421, &replace421.value, 23 },
  { &search436_0, &replace471.value, 24 },
};
static const struct transform nir_opt_algebraic_state404_xforms[] = {
  { &search395, &replace395.value, 0 },
};
static const struct transform nir_opt_algebraic_state405_xforms[] = {
  { &search335, &search6_0.value, 0 },
  { &search419, &replace419.value, 23 },
  { &search420, &replace420.value, 23 },
  { &search421, &replace421.value, 23 },
  { &search470, &replace470.value, 24 },
  { &search436_0, &replace471.value, 24 },
};
static const struct transform nir_opt_algebraic_state406_xforms[] = {
  { &search404, &replace146.value, 0 },
};
static const struct transform nir_opt_algebraic_state407_xforms[] = {
  { &search325, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state408_xforms[] = {
  { &search81, &replace81.value, 0 },
};
static const struct transform nir_opt_algebraic_state409_xforms[] = {
  { &search82, &search81_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state410_xforms[] = {
  { &search83, &replace83.value, 0 },
};
static const struct transform nir_opt_algebraic_state411_xforms[] = {
  { &search84, &search83_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state412_xforms[] = {
  { &search85, &replace85.value, 0 },
};
static const struct transform nir_opt_algebraic_state413_xforms[] = {
  { &search86, &replace86.value, 0 },
};
static const struct transform nir_opt_algebraic_state414_xforms[] = {
  { &search87, &search85_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state415_xforms[] = {
  { &search88, &search86_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state416_xforms[] = {
  { &search89, &replace89.value, 0 },
};
static const struct transform nir_opt_algebraic_state417_xforms[] = {
  { &search90, &search89_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state418_xforms[] = {
  { &search162, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state419_xforms[] = {
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state420_xforms[] = {
  { &search162, &replace161.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state421_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state422_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search381, &replace381.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state423_xforms[] = {
  { &search161, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state424_xforms[] = {
  { &search161, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state425_xforms[] = {
  { &search161, &replace161.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search163, &replace163.value, 0 },
  { &search164, &replace163.value, 0 },
  { &search165, &replace165.value, 0 },
  { &search166, &replace165.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state426_xforms[] = {
  { &search162, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search379, &search155_0_0.value, 0 },
  { &search380, &search55_2.value, 0 },
  { &search382, &replace382.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state427_xforms[] = {
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search379, &search155_0_0.value, 0 },
  { &search380, &search55_2.value, 0 },
  { &search382, &replace382.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state428_xforms[] = {
  { &search162, &replace161.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search379, &search155_0_0.value, 0 },
  { &search380, &search55_2.value, 0 },
  { &search382, &replace382.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state429_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search379, &search155_0_0.value, 0 },
  { &search380, &search55_2.value, 0 },
  { &search382, &replace382.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state430_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search379, &search155_0_0.value, 0 },
  { &search380, &search55_2.value, 0 },
  { &search381, &replace381.value, 0 },
  { &search382, &replace382.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state431_xforms[] = {
  { &search161, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search379, &search155_0_0.value, 0 },
  { &search380, &search55_2.value, 0 },
  { &search382, &replace382.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state432_xforms[] = {
  { &search161, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search379, &search155_0_0.value, 0 },
  { &search380, &search55_2.value, 0 },
  { &search382, &replace382.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state433_xforms[] = {
  { &search161, &replace161.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search163, &replace163.value, 0 },
  { &search164, &replace163.value, 0 },
  { &search165, &replace165.value, 0 },
  { &search166, &replace165.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search379, &search155_0_0.value, 0 },
  { &search380, &search55_2.value, 0 },
  { &search382, &replace382.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state434_xforms[] = {
  { &search159, &replace159.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state435_xforms[] = {
  { &search159, &replace159.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state436_xforms[] = {
  { &search159, &replace159.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state437_xforms[] = {
  { &search159, &replace159.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state438_xforms[] = {
  { &search159, &replace159.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search373, &replace72_0.value, 0 },
  { &search374, &replace91.value, 0 },
  { &search375, &replace375.value, 0 },
  { &search376, &replace376.value, 0 },
  { &search377, &replace377.value, 0 },
  { &search378, &replace378.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
  { &search385, &replace385.value, 0 },
  { &search386, &replace386.value, 0 },
};
static const struct transform nir_opt_algebraic_state439_xforms[] = {
  { &search159, &replace159.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state440_xforms[] = {
  { &search159, &replace159.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state441_xforms[] = {
  { &search159, &replace159.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state442_xforms[] = {
  { &search159, &replace159.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search381, &replace381.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state443_xforms[] = {
  { &search159, &replace159.value, 0 },
  { &search161, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state444_xforms[] = {
  { &search159, &replace159.value, 0 },
  { &search161, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state445_xforms[] = {
  { &search159, &replace159.value, 0 },
  { &search161, &replace161.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search163, &replace163.value, 0 },
  { &search164, &replace163.value, 0 },
  { &search165, &replace165.value, 0 },
  { &search166, &replace165.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state446_xforms[] = {
  { &search160, &replace160.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state447_xforms[] = {
  { &search160, &replace160.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state448_xforms[] = {
  { &search160, &replace160.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state449_xforms[] = {
  { &search160, &replace160.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state450_xforms[] = {
  { &search160, &replace160.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search373, &replace72_0.value, 0 },
  { &search374, &replace91.value, 0 },
  { &search375, &replace375.value, 0 },
  { &search376, &replace376.value, 0 },
  { &search377, &replace377.value, 0 },
  { &search378, &replace378.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
  { &search385, &replace385.value, 0 },
  { &search386, &replace386.value, 0 },
};
static const struct transform nir_opt_algebraic_state451_xforms[] = {
  { &search160, &replace160.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state452_xforms[] = {
  { &search160, &replace160.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state453_xforms[] = {
  { &search160, &replace160.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state454_xforms[] = {
  { &search160, &replace160.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search381, &replace381.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state455_xforms[] = {
  { &search160, &replace160.value, 0 },
  { &search161, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state456_xforms[] = {
  { &search160, &replace160.value, 0 },
  { &search161, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state457_xforms[] = {
  { &search160, &replace160.value, 0 },
  { &search161, &replace161.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search163, &replace163.value, 0 },
  { &search164, &replace163.value, 0 },
  { &search165, &replace165.value, 0 },
  { &search166, &replace165.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state458_xforms[] = {
  { &search155, &replace155.value, 0 },
  { &search156, &replace156.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state459_xforms[] = {
  { &search155, &replace155.value, 0 },
  { &search156, &replace156.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state460_xforms[] = {
  { &search155, &replace155.value, 0 },
  { &search156, &replace156.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state461_xforms[] = {
  { &search155, &replace155.value, 0 },
  { &search156, &replace156.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state462_xforms[] = {
  { &search155, &replace155.value, 0 },
  { &search156, &replace156.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search373, &replace72_0.value, 0 },
  { &search374, &replace91.value, 0 },
  { &search375, &replace375.value, 0 },
  { &search376, &replace376.value, 0 },
  { &search377, &replace377.value, 0 },
  { &search378, &replace378.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
  { &search385, &replace385.value, 0 },
  { &search386, &replace386.value, 0 },
};
static const struct transform nir_opt_algebraic_state463_xforms[] = {
  { &search155, &replace155.value, 0 },
  { &search156, &replace156.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state464_xforms[] = {
  { &search155, &replace155.value, 0 },
  { &search156, &replace156.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state465_xforms[] = {
  { &search155, &replace155.value, 0 },
  { &search156, &replace156.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state466_xforms[] = {
  { &search155, &replace155.value, 0 },
  { &search156, &replace156.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search381, &replace381.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state467_xforms[] = {
  { &search155, &replace155.value, 0 },
  { &search156, &replace156.value, 0 },
  { &search161, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state468_xforms[] = {
  { &search155, &replace155.value, 0 },
  { &search156, &replace156.value, 0 },
  { &search161, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state469_xforms[] = {
  { &search155, &replace155.value, 0 },
  { &search156, &replace156.value, 0 },
  { &search161, &replace161.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search163, &replace163.value, 0 },
  { &search164, &replace163.value, 0 },
  { &search165, &replace165.value, 0 },
  { &search166, &replace165.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state470_xforms[] = {
  { &search157, &replace157.value, 0 },
  { &search158, &replace158.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state471_xforms[] = {
  { &search157, &replace157.value, 0 },
  { &search158, &replace158.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state472_xforms[] = {
  { &search157, &replace157.value, 0 },
  { &search158, &replace158.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state473_xforms[] = {
  { &search157, &replace157.value, 0 },
  { &search158, &replace158.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state474_xforms[] = {
  { &search157, &replace157.value, 0 },
  { &search158, &replace158.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search373, &replace72_0.value, 0 },
  { &search374, &replace91.value, 0 },
  { &search375, &replace375.value, 0 },
  { &search376, &replace376.value, 0 },
  { &search377, &replace377.value, 0 },
  { &search378, &replace378.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
  { &search385, &replace385.value, 0 },
  { &search386, &replace386.value, 0 },
};
static const struct transform nir_opt_algebraic_state475_xforms[] = {
  { &search157, &replace157.value, 0 },
  { &search158, &replace158.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state476_xforms[] = {
  { &search157, &replace157.value, 0 },
  { &search158, &replace158.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state477_xforms[] = {
  { &search157, &replace157.value, 0 },
  { &search158, &replace158.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state478_xforms[] = {
  { &search157, &replace157.value, 0 },
  { &search158, &replace158.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search381, &replace381.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state479_xforms[] = {
  { &search157, &replace157.value, 0 },
  { &search158, &replace158.value, 0 },
  { &search161, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state480_xforms[] = {
  { &search157, &replace157.value, 0 },
  { &search158, &replace158.value, 0 },
  { &search161, &replace161.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state481_xforms[] = {
  { &search157, &replace157.value, 0 },
  { &search158, &replace158.value, 0 },
  { &search161, &replace161.value, 0 },
  { &search162, &replace161.value, 0 },
  { &search163, &replace163.value, 0 },
  { &search164, &replace163.value, 0 },
  { &search165, &replace165.value, 0 },
  { &search166, &replace165.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state482_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
  { &search499, &search496_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state483_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
  { &search500, &search497_0_0.value, 0 },
  { &search502, &search497_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state484_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
  { &search501, &search498_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state485_xforms[] = {
  { &search124, &replace124.value, 0 },
  { &search311, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state486_xforms[] = {
  { &search124, &replace124.value, 0 },
  { &search311, &replace134.value, 0 },
  { &search369, &replace72_0.value, 0 },
  { &search372, &replace91.value, 0 },
};
static const struct transform nir_opt_algebraic_state487_xforms[] = {
  { &search130, &replace91.value, 0 },
  { &search311, &replace134.value, 0 },
  { &search369, &replace72_0.value, 0 },
  { &search372, &replace91.value, 0 },
};
static const struct transform nir_opt_algebraic_state488_xforms[] = {
  { &search311, &replace134.value, 0 },
  { &search369, &replace72_0.value, 0 },
  { &search372, &replace91.value, 0 },
  { &search692, &replace692.value, 0 },
  { &search693, &replace693.value, 0 },
};
static const struct transform nir_opt_algebraic_state489_xforms[] = {
  { &search125, &replace125.value, 0 },
  { &search312, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state490_xforms[] = {
  { &search125, &replace125.value, 0 },
  { &search312, &replace136.value, 0 },
  { &search370, &replace91.value, 0 },
  { &search371, &replace72_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state491_xforms[] = {
  { &search131, &replace72_0.value, 0 },
  { &search312, &replace136.value, 0 },
  { &search370, &replace91.value, 0 },
  { &search371, &replace72_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state492_xforms[] = {
  { &search312, &replace136.value, 0 },
  { &search370, &replace91.value, 0 },
  { &search371, &replace72_0.value, 0 },
  { &search694, &replace694.value, 0 },
  { &search695, &replace695.value, 0 },
};
static const struct transform nir_opt_algebraic_state493_xforms[] = {
  { &search316, &search6_0.value, 0 },
  { &search329, &replace329.value, 0 },
};
static const struct transform nir_opt_algebraic_state494_xforms[] = {
  { &search316, &search6_0.value, 0 },
  { &search328, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state495_xforms[] = {
  { &search305, &replace305.value, 0 },
  { &search316, &search6_0.value, 0 },
  { &search317, &search6_0.value, 0 },
  { &search318, &replace8.value, 0 },
  { &search329, &replace329.value, 0 },
  { &search422, &replace422.value, 23 },
  { &search472, &replace472.value, 24 },
};
static const struct transform nir_opt_algebraic_state496_xforms[] = {
  { &search305, &replace305.value, 0 },
  { &search316, &search6_0.value, 0 },
  { &search317, &search6_0.value, 0 },
  { &search318, &replace8.value, 0 },
  { &search328, &replace13_1_0.value, 0 },
  { &search422, &replace422.value, 23 },
  { &search472, &replace472.value, 24 },
};
static const struct transform nir_opt_algebraic_state497_xforms[] = {
  { &search305, &replace305.value, 0 },
  { &search316, &search6_0.value, 0 },
  { &search317, &search6_0.value, 0 },
  { &search318, &replace8.value, 0 },
  { &search338, &search338_1.value, 0 },
  { &search339, &search339_1.value, 0 },
  { &search422, &replace422.value, 23 },
  { &search472, &replace472.value, 24 },
};
static const struct transform nir_opt_algebraic_state498_xforms[] = {
  { &search316, &search6_0.value, 0 },
  { &search328, &replace13_1_0.value, 0 },
  { &search329, &replace329.value, 0 },
};
static const struct transform nir_opt_algebraic_state499_xforms[] = {
  { &search316, &search6_0.value, 0 },
  { &search330, &replace330.value, 0 },
};
static const struct transform nir_opt_algebraic_state500_xforms[] = {
  { &search217, &replace217.value, 0 },
  { &search218, &replace218.value, 0 },
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state501_xforms[] = {
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state502_xforms[] = {
  { &search316, &search6_0.value, 0 },
  { &search674, &search81_0.value, 0 },
  { &search675, &search675_1.value, 0 },
};
static const struct transform nir_opt_algebraic_state503_xforms[] = {
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state504_xforms[] = {
  { &search217, &replace217.value, 0 },
  { &search218, &replace218.value, 0 },
  { &search221, &replace217.value, 0 },
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state505_xforms[] = {
  { &search217, &replace217.value, 0 },
  { &search218, &replace218.value, 0 },
  { &search222, &replace218.value, 0 },
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state506_xforms[] = {
  { &search217, &replace217.value, 0 },
  { &search218, &replace218.value, 0 },
  { &search221, &replace217.value, 0 },
  { &search222, &replace218.value, 0 },
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state507_xforms[] = {
  { &search219, &replace219.value, 0 },
  { &search220, &replace220.value, 0 },
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state508_xforms[] = {
  { &search316, &search6_0.value, 0 },
  { &search676, &replace81.value, 0 },
  { &search677, &search677_1.value, 0 },
};
static const struct transform nir_opt_algebraic_state509_xforms[] = {
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state510_xforms[] = {
  { &search219, &replace219.value, 0 },
  { &search220, &replace220.value, 0 },
  { &search223, &replace219.value, 0 },
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state511_xforms[] = {
  { &search219, &replace219.value, 0 },
  { &search220, &replace220.value, 0 },
  { &search224, &replace220.value, 0 },
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state512_xforms[] = {
  { &search219, &replace219.value, 0 },
  { &search220, &replace220.value, 0 },
  { &search223, &replace219.value, 0 },
  { &search224, &replace220.value, 0 },
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state513_xforms[] = {
  { &search316, &search6_0.value, 0 },
  { &search678, &search83_0.value, 0 },
  { &search679, &replace679.value, 0 },
};
static const struct transform nir_opt_algebraic_state514_xforms[] = {
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state515_xforms[] = {
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state516_xforms[] = {
  { &search233, &replace233.value, 0 },
  { &search234, &replace234.value, 0 },
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state517_xforms[] = {
  { &search237, &replace237.value, 0 },
  { &search238, &replace238.value, 0 },
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state518_xforms[] = {
  { &search235, &replace235.value, 0 },
  { &search236, &replace236.value, 0 },
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state519_xforms[] = {
  { &search239, &replace239.value, 0 },
  { &search240, &replace240.value, 0 },
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state520_xforms[] = {
  { &search249, &replace249.value, 0 },
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state521_xforms[] = {
  { &search199, &replace199.value, 0 },
  { &replace197, &replace201.value, 16 },
};
static const struct transform nir_opt_algebraic_state522_xforms[] = {
  { &search200, &search200_0.value, 0 },
  { &replace197, &replace201.value, 16 },
};
static const struct transform nir_opt_algebraic_state523_xforms[] = {
  { &replace197, &replace201.value, 16 },
  { &search202, &replace197.value, 0 },
};
static const struct transform nir_opt_algebraic_state524_xforms[] = {
  { &search52, &search13_0.value, 0 },
  { &search54, &replace54.value, 3 },
  { &search56, &replace56.value, 4 },
  { &search57, &replace57.value, 3 },
  { &search58, &replace58.value, 5 },
};
static const struct transform nir_opt_algebraic_state525_xforms[] = {
  { &search52, &search13_0.value, 0 },
  { &search54, &replace54.value, 3 },
  { &search55, &replace55.value, 0 },
  { &search56, &replace56.value, 4 },
  { &search57, &replace57.value, 3 },
  { &search58, &replace58.value, 5 },
};
static const struct transform nir_opt_algebraic_state526_xforms[] = {
  { &search52, &search13_0.value, 0 },
  { &search53, &replace47.value, 0 },
  { &search54, &replace54.value, 3 },
  { &search56, &replace56.value, 4 },
  { &search57, &replace57.value, 3 },
  { &search58, &replace58.value, 5 },
};
static const struct transform nir_opt_algebraic_state527_xforms[] = {
  { &search52, &search13_0.value, 0 },
  { &search53, &replace47.value, 0 },
  { &search54, &replace54.value, 3 },
  { &search55, &replace55.value, 0 },
  { &search56, &replace56.value, 4 },
  { &search57, &replace57.value, 3 },
  { &search58, &replace58.value, 5 },
};
static const struct transform nir_opt_algebraic_state528_xforms[] = {
  { &search473, &replace48.value, 0 },
  { &search477, &replace477.value, 25 },
};
static const struct transform nir_opt_algebraic_state529_xforms[] = {
  { &search477, &replace477.value, 25 },
};
static const struct transform nir_opt_algebraic_state530_xforms[] = {
  { &search473, &replace48.value, 0 },
  { &search477, &replace477.value, 25 },
};
static const struct transform nir_opt_algebraic_state531_xforms[] = {
  { &search570, &search200_0.value, 0 },
  { &search587, &search56_0.value, 0 },
  { &search588, &search0_0.value, 0 },
  { &search589, &search58_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state532_xforms[] = {
  { &search319, &search6_0.value, 0 },
  { &search326, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state533_xforms[] = {
  { &search246, &search42_1.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state534_xforms[] = {
  { &search245, &replace134.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state535_xforms[] = {
  { &search319, &search6_0.value, 0 },
  { &search327, &replace327.value, 0 },
};
static const struct transform nir_opt_algebraic_state536_xforms[] = {
  { &search319, &search6_0.value, 0 },
  { &search320, &search6_0.value, 0 },
  { &search321, &replace134.value, 0 },
  { &search326, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state537_xforms[] = {
  { &search246, &search42_1.value, 0 },
  { &search319, &search6_0.value, 0 },
  { &search320, &search6_0.value, 0 },
  { &search321, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state538_xforms[] = {
  { &search245, &replace134.value, 0 },
  { &search319, &search6_0.value, 0 },
  { &search320, &search6_0.value, 0 },
  { &search321, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state539_xforms[] = {
  { &search319, &search6_0.value, 0 },
  { &search320, &search6_0.value, 0 },
  { &search321, &replace134.value, 0 },
  { &search327, &replace327.value, 0 },
};
static const struct transform nir_opt_algebraic_state540_xforms[] = {
  { &search246, &search42_1.value, 0 },
  { &search319, &search6_0.value, 0 },
  { &search326, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state541_xforms[] = {
  { &search245, &replace134.value, 0 },
  { &search319, &search6_0.value, 0 },
  { &search326, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state542_xforms[] = {
  { &search319, &search6_0.value, 0 },
  { &search326, &replace13_1_0.value, 0 },
  { &search327, &replace327.value, 0 },
};
static const struct transform nir_opt_algebraic_state543_xforms[] = {
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state544_xforms[] = {
  { &search246, &search42_1.value, 0 },
  { &search319, &search6_0.value, 0 },
  { &search331, &replace331.value, 0 },
};
static const struct transform nir_opt_algebraic_state545_xforms[] = {
  { &search245, &replace134.value, 0 },
  { &search246, &search42_1.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state546_xforms[] = {
  { &search246, &search42_1.value, 0 },
  { &search319, &search6_0.value, 0 },
  { &search327, &replace327.value, 0 },
};
static const struct transform nir_opt_algebraic_state547_xforms[] = {
  { &search209, &replace209.value, 0 },
  { &search210, &replace210.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state548_xforms[] = {
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state549_xforms[] = {
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state550_xforms[] = {
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state551_xforms[] = {
  { &search209, &replace209.value, 0 },
  { &search210, &replace210.value, 0 },
  { &search213, &replace209.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state552_xforms[] = {
  { &search209, &replace209.value, 0 },
  { &search210, &replace210.value, 0 },
  { &search214, &replace210.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state553_xforms[] = {
  { &search209, &replace209.value, 0 },
  { &search210, &replace210.value, 0 },
  { &search213, &replace209.value, 0 },
  { &search214, &replace210.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state554_xforms[] = {
  { &search211, &replace211.value, 0 },
  { &search212, &replace212.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state555_xforms[] = {
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state556_xforms[] = {
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state557_xforms[] = {
  { &search211, &replace211.value, 0 },
  { &search212, &replace212.value, 0 },
  { &search215, &replace211.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state558_xforms[] = {
  { &search211, &replace211.value, 0 },
  { &search212, &replace212.value, 0 },
  { &search216, &replace212.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state559_xforms[] = {
  { &search211, &replace211.value, 0 },
  { &search212, &replace212.value, 0 },
  { &search215, &replace211.value, 0 },
  { &search216, &replace212.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state560_xforms[] = {
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state561_xforms[] = {
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state562_xforms[] = {
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state563_xforms[] = {
  { &search225, &replace225.value, 0 },
  { &search226, &replace226.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state564_xforms[] = {
  { &search229, &replace229.value, 0 },
  { &search230, &replace230.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state565_xforms[] = {
  { &search227, &replace227.value, 0 },
  { &search228, &replace228.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state566_xforms[] = {
  { &search231, &replace231.value, 0 },
  { &search232, &replace232.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state567_xforms[] = {
  { &search242, &replace242.value, 0 },
  { &search243, &replace243.value, 0 },
  { &search245, &replace134.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state568_xforms[] = {
  { &search241, &replace241.value, 0 },
  { &search245, &replace134.value, 0 },
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state569_xforms[] = {
  { &search245, &replace134.value, 0 },
  { &search319, &search6_0.value, 0 },
  { &search327, &replace327.value, 0 },
};
static const struct transform nir_opt_algebraic_state570_xforms[] = {
  { &search396, &replace396.value, 0 },
};
static const struct transform nir_opt_algebraic_state571_xforms[] = {
  { &search336, &search130_1.value, 0 },
  { &search396, &replace396.value, 0 },
};
static const struct transform nir_opt_algebraic_state572_xforms[] = {
  { &search337, &search6_0.value, 0 },
  { &search416, &replace416.value, 23 },
  { &search338_1, &replace417.value, 23 },
  { &search418, &replace418.value, 23 },
  { &search468, &replace468.value, 24 },
  { &search339_1, &replace469.value, 24 },
};
static const struct transform nir_opt_algebraic_state573_xforms[] = {
  { &search573, &search200_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state574_xforms[] = {
  { &search575, &search200_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state575_xforms[] = {
  { &search574, &search393_0_0.value, 0 },
  { &search582, &replace72_0.value, 0 },
  { &search583, &search538_0.value, 0 },
  { &search584, &search56_0.value, 0 },
  { &search585, &search0_0.value, 0 },
  { &search586, &search58_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state576_xforms[] = {
  { &search582, &replace72_0.value, 0 },
  { &search583, &search538_0.value, 0 },
  { &search584, &search56_0.value, 0 },
  { &search585, &search0_0.value, 0 },
  { &search586, &search58_0.value, 0 },
  { &search593, &replace591.value, 0 },
  { &search597, &replace591.value, 0 },
  { &search601, &replace591.value, 0 },
  { &search605, &replace591.value, 0 },
  { &search607, &replace607.value, 0 },
  { &search611, &search591_0.value, 0 },
  { &search615, &search591_0.value, 0 },
  { &search619, &search591_0.value, 0 },
  { &search621, &replace621.value, 0 },
  { &search623, &replace621.value, 0 },
  { &search625, &replace625.value, 0 },
  { &search629, &search595_0.value, 0 },
  { &search633, &search595_0.value, 0 },
  { &search635, &replace635.value, 0 },
  { &search637, &replace635.value, 0 },
  { &search639, &replace639.value, 0 },
  { &search641, &replace635.value, 0 },
  { &search643, &replace639.value, 0 },
  { &search645, &replace645.value, 0 },
  { &search649, &search599_0.value, 0 },
  { &search651, &replace651.value, 0 },
  { &search653, &replace651.value, 0 },
  { &search655, &replace655.value, 0 },
  { &search657, &replace651.value, 0 },
  { &search659, &replace655.value, 0 },
  { &search661, &replace661.value, 0 },
  { &search663, &replace651.value, 0 },
  { &search665, &replace655.value, 0 },
  { &search667, &replace661.value, 0 },
  { &search669, &replace669.value, 0 },
};
static const struct transform nir_opt_algebraic_state577_xforms[] = {
  { &search582, &replace72_0.value, 0 },
  { &search583, &search538_0.value, 0 },
  { &search584, &search56_0.value, 0 },
  { &search585, &search0_0.value, 0 },
  { &search586, &search58_0.value, 0 },
  { &search592, &replace590.value, 0 },
  { &search596, &replace590.value, 0 },
  { &search600, &replace590.value, 0 },
  { &search604, &replace590.value, 0 },
  { &search610, &search590_0.value, 0 },
  { &search614, &search590_0.value, 0 },
  { &search618, &search590_0.value, 0 },
  { &search628, &search594_0.value, 0 },
  { &search632, &search594_0.value, 0 },
  { &search648, &search598_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state578_xforms[] = {
  { &search576, &search393_0_0.value, 0 },
  { &search577, &replace72_0.value, 0 },
  { &search578, &search538_0.value, 0 },
  { &search579, &search56_0.value, 0 },
  { &search580, &search0_0.value, 0 },
  { &search581, &search58_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state579_xforms[] = {
  { &search577, &replace72_0.value, 0 },
  { &search578, &search538_0.value, 0 },
  { &search579, &search56_0.value, 0 },
  { &search580, &search0_0.value, 0 },
  { &search581, &search58_0.value, 0 },
  { &search591, &replace591.value, 0 },
  { &search595, &replace591.value, 0 },
  { &search599, &replace591.value, 0 },
  { &search603, &replace591.value, 0 },
  { &search609, &search591_0.value, 0 },
  { &search613, &search591_0.value, 0 },
  { &search617, &search591_0.value, 0 },
  { &search627, &search595_0.value, 0 },
  { &search631, &search595_0.value, 0 },
  { &search647, &search599_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state580_xforms[] = {
  { &search577, &replace72_0.value, 0 },
  { &search578, &search538_0.value, 0 },
  { &search579, &search56_0.value, 0 },
  { &search580, &search0_0.value, 0 },
  { &search581, &search58_0.value, 0 },
  { &search590, &replace590.value, 0 },
  { &search594, &replace590.value, 0 },
  { &search598, &replace590.value, 0 },
  { &search602, &replace590.value, 0 },
  { &search606, &replace606.value, 0 },
  { &search608, &search590_0.value, 0 },
  { &search612, &search590_0.value, 0 },
  { &search616, &search590_0.value, 0 },
  { &search620, &replace620.value, 0 },
  { &search622, &replace620.value, 0 },
  { &search624, &replace624.value, 0 },
  { &search626, &search594_0.value, 0 },
  { &search630, &search594_0.value, 0 },
  { &search634, &replace634.value, 0 },
  { &search636, &replace634.value, 0 },
  { &search638, &replace638.value, 0 },
  { &search640, &replace634.value, 0 },
  { &search642, &replace638.value, 0 },
  { &search644, &replace644.value, 0 },
  { &search646, &search598_0.value, 0 },
  { &search650, &replace650.value, 0 },
  { &search652, &replace650.value, 0 },
  { &search654, &replace654.value, 0 },
  { &search656, &replace650.value, 0 },
  { &search658, &replace654.value, 0 },
  { &search660, &replace660.value, 0 },
  { &search662, &replace650.value, 0 },
  { &search664, &replace654.value, 0 },
  { &search666, &replace660.value, 0 },
  { &search668, &replace668.value, 0 },
};
static const struct transform nir_opt_algebraic_state581_xforms[] = {
  { &search73, &replace73.value, 0 },
  { &search76, &replace76.value, 0 },
};
static const struct transform nir_opt_algebraic_state582_xforms[] = {
  { &search73, &replace73.value, 0 },
  { &search75, &replace75.value, 0 },
  { &search76, &replace76.value, 0 },
};
static const struct transform nir_opt_algebraic_state583_xforms[] = {
  { &search73, &replace73.value, 0 },
  { &search74, &replace47.value, 0 },
  { &search75, &replace75.value, 0 },
  { &search76, &replace76.value, 0 },
};
static const struct transform nir_opt_algebraic_state584_xforms[] = {
  { &search78, &replace75.value, 0 },
};
static const struct transform nir_opt_algebraic_state585_xforms[] = {
  { &search77, &replace47.value, 0 },
  { &search78, &replace75.value, 0 },
};
static const struct transform nir_opt_algebraic_state586_xforms[] = {
  { &search446, &replace446.value, 0 },
  { &search447, &replace425.value, 0 },
  { &search448, &replace424.value, 0 },
  { &search449, &replace449.value, 0 },
  { &search450, &replace432.value, 0 },
  { &search451, &replace431.value, 0 },
  { &search452, &replace430.value, 0 },
  { &search453, &replace429.value, 0 },
  { &search454, &replace428.value, 0 },
  { &search455, &replace427.value, 0 },
  { &search456, &replace456.value, 0 },
  { &search525, &replace525.value, 41 },
};
static const struct transform nir_opt_algebraic_state587_xforms[] = {
  { &search434, &replace416.value, 0 },
  { &search435, &replace424.value, 0 },
  { &search436, &replace425.value, 0 },
  { &search437, &replace417.value, 0 },
  { &search438, &replace427.value, 0 },
  { &search439, &replace428.value, 0 },
  { &search440, &replace429.value, 0 },
  { &search441, &replace430.value, 0 },
  { &search442, &replace431.value, 0 },
  { &search443, &replace432.value, 0 },
  { &search444, &replace418.value, 0 },
  { &search525, &replace525.value, 41 },
};
static const struct transform nir_opt_algebraic_state588_xforms[] = {
  { &search423, &replace416.value, 0 },
  { &search424, &replace424.value, 0 },
  { &search425, &replace425.value, 0 },
  { &search426, &replace417.value, 0 },
  { &search427, &replace427.value, 0 },
  { &search428, &replace428.value, 0 },
  { &search429, &replace429.value, 0 },
  { &search430, &replace430.value, 0 },
  { &search431, &replace431.value, 0 },
  { &search432, &replace432.value, 0 },
  { &search433, &replace418.value, 0 },
  { &search525, &replace525.value, 41 },
};
static const struct transform nir_opt_algebraic_state589_xforms[] = {
  { &search445, &replace445.value, 0 },
  { &search525, &replace525.value, 41 },
};
static const struct transform nir_opt_algebraic_state590_xforms[] = {
  { &search457, &replace457.value, 0 },
  { &search458, &replace458.value, 0 },
  { &search459, &replace459.value, 0 },
  { &search460, &replace460.value, 0 },
  { &search461, &replace461.value, 0 },
  { &search462, &replace462.value, 0 },
  { &search463, &replace463.value, 0 },
  { &search464, &replace464.value, 0 },
  { &search465, &replace465.value, 0 },
  { &search466, &replace466.value, 0 },
  { &search467, &replace467.value, 0 },
  { &search524, &replace524.value, 41 },
};
static const struct transform nir_opt_algebraic_state594_xforms[] = {
  { &search248, &replace248.value, 0 },
};
static const struct transform nir_opt_algebraic_state595_xforms[] = {
  { &search266, &replace136.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state596_xforms[] = {
  { &search258, &replace258.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state597_xforms[] = {
  { &search309, &replace136.value, 0 },
  { &search412, &replace412.value, 0 },
};
static const struct transform nir_opt_algebraic_state598_xforms[] = {
  { &search309, &replace136.value, 0 },
  { &search689, &replace689.value, 0 },
};
static const struct transform nir_opt_algebraic_state599_xforms[] = {
  { &search266, &replace136.value, 0 },
  { &search282, &replace282.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state600_xforms[] = {
  { &search258, &replace258.value, 0 },
  { &search274, &replace274.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state601_xforms[] = {
  { &search309, &replace136.value, 0 },
  { &search688, &replace688.value, 0 },
};
static const struct transform nir_opt_algebraic_state602_xforms[] = {
  { &search259, &replace259.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state603_xforms[] = {
  { &search259, &replace259.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state604_xforms[] = {
  { &search259, &replace259.value, 0 },
  { &search266, &replace136.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state605_xforms[] = {
  { &search258, &replace258.value, 0 },
  { &search259, &replace259.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state606_xforms[] = {
  { &search259, &replace259.value, 0 },
  { &search309, &replace136.value, 0 },
  { &search412, &replace412.value, 0 },
};
static const struct transform nir_opt_algebraic_state607_xforms[] = {
  { &search259, &replace259.value, 0 },
  { &search275, &replace275.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state608_xforms[] = {
  { &search267, &replace136.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state609_xforms[] = {
  { &search267, &replace136.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state610_xforms[] = {
  { &search266, &replace136.value, 0 },
  { &search267, &replace136.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state611_xforms[] = {
  { &search258, &replace258.value, 0 },
  { &search267, &replace136.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state612_xforms[] = {
  { &search267, &replace136.value, 0 },
  { &search309, &replace136.value, 0 },
  { &search412, &replace412.value, 0 },
};
static const struct transform nir_opt_algebraic_state613_xforms[] = {
  { &search267, &replace136.value, 0 },
  { &search283, &replace283.value, 0 },
  { &search309, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state614_xforms[] = {
  { &search309, &replace136.value, 0 },
  { &search411, &replace411.value, 0 },
};
static const struct transform nir_opt_algebraic_state615_xforms[] = {
  { &search309, &replace136.value, 0 },
  { &search411, &replace411.value, 0 },
};
static const struct transform nir_opt_algebraic_state616_xforms[] = {
  { &search266, &replace136.value, 0 },
  { &search309, &replace136.value, 0 },
  { &search411, &replace411.value, 0 },
};
static const struct transform nir_opt_algebraic_state617_xforms[] = {
  { &search258, &replace258.value, 0 },
  { &search309, &replace136.value, 0 },
  { &search411, &replace411.value, 0 },
};
static const struct transform nir_opt_algebraic_state618_xforms[] = {
  { &search309, &replace136.value, 0 },
  { &search411, &replace411.value, 0 },
  { &search412, &replace412.value, 0 },
};
static const struct transform nir_opt_algebraic_state619_xforms[] = {
  { &search270, &replace136.value, 0 },
  { &search313, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state620_xforms[] = {
  { &search262, &replace262.value, 0 },
  { &search313, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state621_xforms[] = {
  { &search313, &replace136.value, 0 },
  { &search697, &replace697.value, 0 },
};
static const struct transform nir_opt_algebraic_state622_xforms[] = {
  { &search270, &replace136.value, 0 },
  { &search286, &replace286.value, 0 },
  { &search313, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state623_xforms[] = {
  { &search262, &replace262.value, 0 },
  { &search278, &replace278.value, 0 },
  { &search313, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state624_xforms[] = {
  { &search313, &replace136.value, 0 },
  { &search696, &replace696.value, 0 },
};
static const struct transform nir_opt_algebraic_state625_xforms[] = {
  { &search263, &replace263.value, 0 },
  { &search313, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state626_xforms[] = {
  { &search263, &replace263.value, 0 },
  { &search270, &replace136.value, 0 },
  { &search313, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state627_xforms[] = {
  { &search262, &replace262.value, 0 },
  { &search263, &replace263.value, 0 },
  { &search313, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state628_xforms[] = {
  { &search263, &replace263.value, 0 },
  { &search279, &replace279.value, 0 },
  { &search313, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state629_xforms[] = {
  { &search271, &replace136.value, 0 },
  { &search313, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state630_xforms[] = {
  { &search270, &replace136.value, 0 },
  { &search271, &replace136.value, 0 },
  { &search313, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state631_xforms[] = {
  { &search262, &replace262.value, 0 },
  { &search271, &replace136.value, 0 },
  { &search313, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state632_xforms[] = {
  { &search271, &replace136.value, 0 },
  { &search287, &replace287.value, 0 },
  { &search313, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state633_xforms[] = {
  { &search260, &replace134.value, 0 },
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state634_xforms[] = {
  { &search268, &replace268.value, 0 },
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state635_xforms[] = {
  { &search310, &replace134.value, 0 },
  { &search410, &replace410.value, 0 },
};
static const struct transform nir_opt_algebraic_state636_xforms[] = {
  { &search310, &replace134.value, 0 },
  { &search691, &replace691.value, 0 },
};
static const struct transform nir_opt_algebraic_state637_xforms[] = {
  { &search260, &replace134.value, 0 },
  { &search276, &replace276.value, 0 },
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state638_xforms[] = {
  { &search268, &replace268.value, 0 },
  { &search284, &replace284.value, 0 },
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state639_xforms[] = {
  { &search310, &replace134.value, 0 },
  { &search690, &replace690.value, 0 },
};
static const struct transform nir_opt_algebraic_state640_xforms[] = {
  { &search269, &replace269.value, 0 },
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state641_xforms[] = {
  { &search260, &replace134.value, 0 },
  { &search269, &replace269.value, 0 },
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state642_xforms[] = {
  { &search268, &replace268.value, 0 },
  { &search269, &replace269.value, 0 },
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state643_xforms[] = {
  { &search269, &replace269.value, 0 },
  { &search310, &replace134.value, 0 },
  { &search410, &replace410.value, 0 },
};
static const struct transform nir_opt_algebraic_state644_xforms[] = {
  { &search269, &replace269.value, 0 },
  { &search285, &replace285.value, 0 },
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state645_xforms[] = {
  { &search261, &replace134.value, 0 },
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state646_xforms[] = {
  { &search260, &replace134.value, 0 },
  { &search261, &replace134.value, 0 },
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state647_xforms[] = {
  { &search261, &replace134.value, 0 },
  { &search268, &replace268.value, 0 },
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state648_xforms[] = {
  { &search261, &replace134.value, 0 },
  { &search310, &replace134.value, 0 },
  { &search410, &replace410.value, 0 },
};
static const struct transform nir_opt_algebraic_state649_xforms[] = {
  { &search261, &replace134.value, 0 },
  { &search277, &replace277.value, 0 },
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state650_xforms[] = {
  { &search310, &replace134.value, 0 },
  { &search409, &replace409.value, 0 },
};
static const struct transform nir_opt_algebraic_state651_xforms[] = {
  { &search260, &replace134.value, 0 },
  { &search310, &replace134.value, 0 },
  { &search409, &replace409.value, 0 },
};
static const struct transform nir_opt_algebraic_state652_xforms[] = {
  { &search268, &replace268.value, 0 },
  { &search310, &replace134.value, 0 },
  { &search409, &replace409.value, 0 },
};
static const struct transform nir_opt_algebraic_state653_xforms[] = {
  { &search310, &replace134.value, 0 },
  { &search409, &replace409.value, 0 },
  { &search410, &replace410.value, 0 },
};
static const struct transform nir_opt_algebraic_state654_xforms[] = {
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state655_xforms[] = {
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state656_xforms[] = {
  { &search310, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state657_xforms[] = {
  { &search264, &replace134.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state658_xforms[] = {
  { &search272, &replace272.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state659_xforms[] = {
  { &search314, &replace134.value, 0 },
  { &search699, &replace699.value, 0 },
};
static const struct transform nir_opt_algebraic_state660_xforms[] = {
  { &search264, &replace134.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state661_xforms[] = {
  { &search264, &replace134.value, 0 },
  { &search280, &replace280.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state662_xforms[] = {
  { &search272, &replace272.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state663_xforms[] = {
  { &search272, &replace272.value, 0 },
  { &search288, &replace288.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state664_xforms[] = {
  { &search314, &replace134.value, 0 },
  { &search698, &replace698.value, 0 },
};
static const struct transform nir_opt_algebraic_state665_xforms[] = {
  { &search273, &replace273.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state666_xforms[] = {
  { &search264, &replace134.value, 0 },
  { &search273, &replace273.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state667_xforms[] = {
  { &search272, &replace272.value, 0 },
  { &search273, &replace273.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state668_xforms[] = {
  { &search273, &replace273.value, 0 },
  { &search289, &replace289.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state669_xforms[] = {
  { &search265, &replace134.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state670_xforms[] = {
  { &search264, &replace134.value, 0 },
  { &search265, &replace134.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state671_xforms[] = {
  { &search265, &replace134.value, 0 },
  { &search272, &replace272.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state672_xforms[] = {
  { &search265, &replace134.value, 0 },
  { &search281, &replace281.value, 0 },
  { &search314, &replace134.value, 0 },
};
static const struct transform nir_opt_algebraic_state673_xforms[] = {
  { &search175, &search6_0.value, 0 },
  { &search181, &replace181.value, 0 },
};
static const struct transform nir_opt_algebraic_state674_xforms[] = {
  { &search175, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state675_xforms[] = {
  { &search175, &search6_0.value, 0 },
  { &search181, &replace181.value, 0 },
};
static const struct transform nir_opt_algebraic_state676_xforms[] = {
  { &search175, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state677_xforms[] = {
  { &search175, &search6_0.value, 0 },
  { &search181, &replace181.value, 0 },
};
static const struct transform nir_opt_algebraic_state678_xforms[] = {
  { &search176, &search6_0.value, 0 },
  { &search178, &replace178.value, 0 },
};
static const struct transform nir_opt_algebraic_state679_xforms[] = {
  { &search176, &search6_0.value, 0 },
  { &search178, &replace178.value, 0 },
};
static const struct transform nir_opt_algebraic_state680_xforms[] = {
  { &search341, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state681_xforms[] = {
  { &search359, &replace359.value, 0 },
};
static const struct transform nir_opt_algebraic_state682_xforms[] = {
  { &search356, &replace356.value, 0 },
};
static const struct transform nir_opt_algebraic_state683_xforms[] = {
  { &search357, &replace357.value, 0 },
};
static const struct transform nir_opt_algebraic_state684_xforms[] = {
  { &search358, &replace358.value, 0 },
};
static const struct transform nir_opt_algebraic_state685_xforms[] = {
  { &search353, &replace353.value, 0 },
  { &search356_0, &replace365.value, 21 },
};
static const struct transform nir_opt_algebraic_state686_xforms[] = {
  { &search354, &replace354.value, 0 },
};
static const struct transform nir_opt_algebraic_state687_xforms[] = {
  { &search364, &search358_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state688_xforms[] = {
  { &search363, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state689_xforms[] = {
  { &search366, &search356_0.value, 22 },
};
static const struct transform nir_opt_algebraic_state690_xforms[] = {
  { &search355, &replace355.value, 0 },
};
static const struct transform nir_opt_algebraic_state691_xforms[] = {
  { &search340, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state692_xforms[] = {
  { &search342, &replace342.value, 18 },
  { &search347, &search6_0.value, 0 },
  { &search348, &replace345.value, 0 },
  { &search349, &replace346.value, 0 },
  { &search351, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state693_xforms[] = {
  { &search414, &replace0_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state694_xforms[] = {
  { &search474, &replace474.value, 0 },
  { &search478, &replace478.value, 25 },
};
static const struct transform nir_opt_algebraic_state695_xforms[] = {
  { &search474, &replace474.value, 0 },
  { &search478, &replace478.value, 25 },
};
static const struct transform nir_opt_algebraic_state696_xforms[] = {
  { &search32, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state697_xforms[] = {
  { &search24, &search6_0.value, 0 },
  { &search32, &replace13_1_0.value, 0 },
  { &search490, &replace490.value, 0 },
};
static const struct transform nir_opt_algebraic_state698_xforms[] = {
  { &search24, &search6_0.value, 0 },
  { &search32, &replace13_1_0.value, 0 },
  { &search490, &replace490.value, 0 },
  { &search495, &replace490.value, 0 },
};
static const struct transform nir_opt_algebraic_state699_xforms[] = {
  { &search30, &replace8.value, 0 },
  { &search31, &replace13_1_0.value, 0 },
  { &search32, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state700_xforms[] = {
  { &search32, &replace13_1_0.value, 0 },
  { &search482, &search478.value, 0 },
};
static const struct transform nir_opt_algebraic_state701_xforms[] = {
  { &search79, &replace79.value, 0 },
  { &search333, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state702_xforms[] = {
  { &search114, &replace93.value, 0 },
};
static const struct transform nir_opt_algebraic_state703_xforms[] = {
  { &search145, &replace144.value, 0 },
};
static const struct transform nir_opt_algebraic_state704_xforms[] = {
  { &search307, &replace72_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state705_xforms[] = {
  { &search120, &replace120.value, 0 },
  { &search153, &search81_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state706_xforms[] = {
  { &search308, &replace72_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state707_xforms[] = {
  { &search116, &replace103.value, 0 },
};
static const struct transform nir_opt_algebraic_state708_xforms[] = {
  { &search147, &replace146.value, 0 },
  { &search147, &replace146.value, 0 },
};
static const struct transform nir_opt_algebraic_state709_xforms[] = {
  { &search92, &replace91.value, 0 },
};
static const struct transform nir_opt_algebraic_state710_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search183, &search16_0.value, 0 },
  { &search191, &search6_0.value, 0 },
  { &search183, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state711_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search177, &replace156.value, 0 },
  { &search183, &search16_0.value, 0 },
  { &search191, &search6_0.value, 0 },
  { &search183, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state712_xforms[] = {
  { &search149, &replace149.value, 0 },
  { &search172, &search6_0.value, 0 },
  { &search183, &search16_0.value, 0 },
  { &search183, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state713_xforms[] = {
  { &search172, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state714_xforms[] = {
  { &search172, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state715_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search183, &search16_0.value, 0 },
  { &search183, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state716_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search193, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state717_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search183, &search16_0.value, 0 },
  { &search191, &search6_0.value, 0 },
  { &search183, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state718_xforms[] = {
  { &search172, &search6_0.value, 0 },
  { &search198, &replace197.value, 15 },
};
static const struct transform nir_opt_algebraic_state719_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search185, &search145_0.value, 0 },
  { &search187, &search145_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state720_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search185, &search145_0.value, 0 },
  { &search187, &search145_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state721_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search180, &replace157.value, 0 },
  { &search185, &search145_0.value, 0 },
  { &search187, &search145_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state722_xforms[] = {
  { &search171, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state723_xforms[] = {
  { &search171, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state724_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search185, &search145_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state725_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search189, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state726_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search185, &search145_0.value, 0 },
  { &search187, &search145_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state727_xforms[] = {
  { &search151, &replace151.value, 0 },
  { &search171, &search6_0.value, 0 },
  { &search185, &search145_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state728_xforms[] = {
  { &search29, &search23_1.value, 0 },
  { &search61, &search60.value, 8 },
};
static const struct transform nir_opt_algebraic_state729_xforms[] = {
  { &search34, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state730_xforms[] = {
  { &search23, &search6_0.value, 0 },
  { &search29, &search23_1.value, 0 },
  { &search494, &replace494.value, 0 },
};
static const struct transform nir_opt_algebraic_state731_xforms[] = {
  { &search23, &search6_0.value, 0 },
  { &search29, &search23_1.value, 0 },
};
static const struct transform nir_opt_algebraic_state732_xforms[] = {
  { &search23, &search6_0.value, 0 },
  { &search29, &search23_1.value, 0 },
  { &search61, &search60.value, 8 },
};
static const struct transform nir_opt_algebraic_state733_xforms[] = {
  { &search23, &search6_0.value, 0 },
  { &search34, &replace13_1_0.value, 0 },
  { &search489, &replace489.value, 0 },
};
static const struct transform nir_opt_algebraic_state734_xforms[] = {
  { &search23, &search6_0.value, 0 },
  { &search34, &replace13_1_0.value, 0 },
  { &search489, &replace489.value, 0 },
  { &search493, &replace489.value, 0 },
};
static const struct transform nir_opt_algebraic_state735_xforms[] = {
  { &search29, &search23_1.value, 0 },
  { &search33, &replace13_1_0.value, 0 },
  { &search34, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state736_xforms[] = {
  { &search29, &search23_1.value, 0 },
  { &search33, &replace13_1_0.value, 0 },
  { &search61, &search60.value, 8 },
};
static const struct transform nir_opt_algebraic_state737_xforms[] = {
  { &search29, &search23_1.value, 0 },
  { &search61, &search60.value, 8 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state738_xforms[] = {
  { &search34, &replace13_1_0.value, 0 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state739_xforms[] = {
  { &search29, &search23_1.value, 0 },
};
static const struct transform nir_opt_algebraic_state740_xforms[] = {
  { &search29, &search23_1.value, 0 },
  { &search61, &search60.value, 8 },
  { &search481, &search477.value, 0 },
};
static const struct transform nir_opt_algebraic_state741_xforms[] = {
  { &search34, &replace13_1_0.value, 0 },
  { &search481, &search477.value, 0 },
};
static const struct transform nir_opt_algebraic_state742_xforms[] = {
  { &search29, &search23_1.value, 0 },
  { &search33, &replace13_1_0.value, 0 },
  { &search34, &replace13_1_0.value, 0 },
  { &search61, &search60.value, 8 },
};
static const struct transform nir_opt_algebraic_state743_xforms[] = {
  { &search27, &replace27.value, 0 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state744_xforms[] = {
  { &search103, &replace103.value, 0 },
  { &search122, &replace122.value, 0 },
};
static const struct transform nir_opt_algebraic_state745_xforms[] = {
  { &search107, &replace107.value, 0 },
};
static const struct transform nir_opt_algebraic_state746_xforms[] = {
  { &search104, &replace103.value, 0 },
};
static const struct transform nir_opt_algebraic_state747_xforms[] = {
  { &search108, &replace107.value, 0 },
};
static const struct transform nir_opt_algebraic_state748_xforms[] = {
  { &search105, &replace103.value, 0 },
};
static const struct transform nir_opt_algebraic_state749_xforms[] = {
  { &search109, &replace107.value, 0 },
};
static const struct transform nir_opt_algebraic_state750_xforms[] = {
  { &search106, &replace103.value, 0 },
  { &search301, &replace146.value, 0 },
};
static const struct transform nir_opt_algebraic_state751_xforms[] = {
  { &search112, &replace110.value, 0 },
  { &search301, &replace146.value, 0 },
};
static const struct transform nir_opt_algebraic_state752_xforms[] = {
  { &search93, &replace93.value, 0 },
  { &search123, &replace123.value, 0 },
};
static const struct transform nir_opt_algebraic_state753_xforms[] = {
  { &search97, &replace97.value, 0 },
};
static const struct transform nir_opt_algebraic_state754_xforms[] = {
  { &search94, &replace93.value, 0 },
};
static const struct transform nir_opt_algebraic_state755_xforms[] = {
  { &search98, &replace97.value, 0 },
};
static const struct transform nir_opt_algebraic_state756_xforms[] = {
  { &search95, &replace93.value, 0 },
};
static const struct transform nir_opt_algebraic_state757_xforms[] = {
  { &search99, &replace97.value, 0 },
};
static const struct transform nir_opt_algebraic_state758_xforms[] = {
  { &search96, &replace93.value, 0 },
  { &search300, &replace144.value, 0 },
};
static const struct transform nir_opt_algebraic_state759_xforms[] = {
  { &search102, &replace100.value, 0 },
  { &search300, &replace144.value, 0 },
};
static const struct transform nir_opt_algebraic_state760_xforms[] = {
  { &search342, &replace342.value, 18 },
  { &search347, &search6_0.value, 0 },
  { &search348, &replace345.value, 0 },
  { &search349, &replace346.value, 0 },
  { &search352, &search16_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state763_xforms[] = {
  { &search44, &replace43.value, 0 },
};
static const struct transform nir_opt_algebraic_state764_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state765_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state766_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
  { &search44, &replace43.value, 0 },
  { &search487, &replace487.value, 0 },
};
static const struct transform nir_opt_algebraic_state767_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
  { &search44, &replace43.value, 0 },
  { &search487, &replace487.value, 0 },
  { &search491, &replace487.value, 0 },
};
static const struct transform nir_opt_algebraic_state768_xforms[] = {
  { &search485, &replace485.value, 0 },
};
static const struct transform nir_opt_algebraic_state769_xforms[] = {
  { &search485, &replace485.value, 0 },
};
static const struct transform nir_opt_algebraic_state770_xforms[] = {
  { &search44, &replace43.value, 0 },
  { &search485, &replace485.value, 0 },
};
static const struct transform nir_opt_algebraic_state773_xforms[] = {
  { &search43, &replace43.value, 0 },
  { &search44, &replace43.value, 0 },
};
static const struct transform nir_opt_algebraic_state776_xforms[] = {
  { &search44, &replace43.value, 0 },
};
static const struct transform nir_opt_algebraic_state779_xforms[] = {
  { &search44, &replace43.value, 0 },
};
static const struct transform nir_opt_algebraic_state780_xforms[] = {
  { &search44, &replace43.value, 0 },
};
static const struct transform nir_opt_algebraic_state781_xforms[] = {
  { &search44, &replace43.value, 0 },
};
static const struct transform nir_opt_algebraic_state782_xforms[] = {
  { &search14_0, &replace479.value, 26 },
};
static const struct transform nir_opt_algebraic_state783_xforms[] = {
  { &replace197, &replace201.value, 16 },
  { &search304, &replace148.value, 0 },
};
static const struct transform nir_opt_algebraic_state784_xforms[] = {
  { &search343, &search342.value, 19 },
};
static const struct transform nir_opt_algebraic_state785_xforms[] = {
  { &search343, &search342.value, 19 },
  { &search345, &replace345.value, 0 },
  { &search346, &replace346.value, 0 },
};
static const struct transform nir_opt_algebraic_state786_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search186, &replace186.value, 0 },
  { &search188, &replace186.value, 0 },
};
static const struct transform nir_opt_algebraic_state787_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search186, &replace186.value, 0 },
  { &search188, &replace186.value, 0 },
};
static const struct transform nir_opt_algebraic_state788_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search186, &replace186.value, 0 },
  { &search188, &replace186.value, 0 },
  { &search190, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state789_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search182, &replace182.value, 0 },
  { &search186, &replace186.value, 0 },
  { &search188, &replace186.value, 0 },
};
static const struct transform nir_opt_algebraic_state790_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search186, &replace186.value, 0 },
  { &search188, &replace186.value, 0 },
};
static const struct transform nir_opt_algebraic_state791_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search184, &search19_0.value, 0 },
  { &search192, &search6_0.value, 0 },
  { &search184, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state792_xforms[] = {
  { &search174, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state793_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search184, &search19_0.value, 0 },
  { &search192, &search6_0.value, 0 },
  { &search184, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state794_xforms[] = {
  { &search174, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state795_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search184, &search19_0.value, 0 },
  { &search184, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state796_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search184, &search19_0.value, 0 },
  { &search192, &search6_0.value, 0 },
  { &search194, &search19_0.value, 0 },
  { &search184, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state797_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search194, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state798_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search179, &replace179.value, 0 },
  { &search184, &search19_0.value, 0 },
  { &search192, &search6_0.value, 0 },
  { &search184, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state799_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search179, &replace179.value, 0 },
};
static const struct transform nir_opt_algebraic_state800_xforms[] = {
  { &search174, &search6_0.value, 0 },
  { &search184, &search19_0.value, 0 },
  { &search192, &search6_0.value, 0 },
  { &search184, &search19_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state801_xforms[] = {
  { &search305, &replace305.value, 0 },
  { &search316, &search6_0.value, 0 },
  { &search317, &search6_0.value, 0 },
  { &search318, &replace8.value, 0 },
  { &search393, &search200_0.value, 0 },
  { &search422, &replace422.value, 23 },
  { &search472, &replace472.value, 24 },
};
static const struct transform nir_opt_algebraic_state802_xforms[] = {
  { &search305, &replace305.value, 0 },
  { &search316, &search6_0.value, 0 },
  { &search317, &search6_0.value, 0 },
  { &search318, &replace8.value, 0 },
  { &search328, &replace13_1_0.value, 0 },
  { &search422, &replace422.value, 23 },
  { &search472, &replace472.value, 24 },
};
static const struct transform nir_opt_algebraic_state803_xforms[] = {
  { &search316, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state804_xforms[] = {
  { &search316, &search6_0.value, 0 },
  { &search387, &replace387.value, 0 },
};
static const struct transform nir_opt_algebraic_state805_xforms[] = {
  { &search311, &replace134.value, 0 },
  { &search369, &replace72_0.value, 0 },
  { &search372, &replace91.value, 0 },
  { &search389, &replace91.value, 0 },
  { &search390, &replace72_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state806_xforms[] = {
  { &search312, &replace136.value, 0 },
  { &search370, &replace91.value, 0 },
  { &search371, &replace72_0.value, 0 },
  { &search391, &replace72_0.value, 0 },
  { &search392, &replace91.value, 0 },
};
static const struct transform nir_opt_algebraic_state807_xforms[] = {
  { &search247, &replace247.value, 0 },
  { &search312, &replace136.value, 0 },
};
static const struct transform nir_opt_algebraic_state808_xforms[] = {
  { &search319, &search6_0.value, 0 },
  { &search388, &replace388.value, 0 },
};
static const struct transform nir_opt_algebraic_state809_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search290, &replace290.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state810_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
  { &search496, &search496_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state811_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
  { &search497, &search497_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state812_xforms[] = {
  { &search168, &replace93.value, 0 },
  { &search169, &replace97.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
  { &search498, &search498_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state813_xforms[] = {
  { &search208, &search208_0.value, 0 },
  { &search525, &replace525.value, 41 },
};
static const struct transform nir_opt_algebraic_state814_xforms[] = {
  { &search291, &search291_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state815_xforms[] = {
  { &search565, &replace565.value, 0 },
};
static const struct transform nir_opt_algebraic_state816_xforms[] = {
  { &search563, &replace563.value, 0 },
};
static const struct transform nir_opt_algebraic_state817_xforms[] = {
  { &search553, &replace553.value, 0 },
};
static const struct transform nir_opt_algebraic_state818_xforms[] = {
  { &search559, &replace559.value, 0 },
};
static const struct transform nir_opt_algebraic_state819_xforms[] = {
  { &search561, &replace561.value, 0 },
};
static const struct transform nir_opt_algebraic_state820_xforms[] = {
  { &search551, &replace551.value, 0 },
};
static const struct transform nir_opt_algebraic_state821_xforms[] = {
  { &search557, &replace557.value, 0 },
};
static const struct transform nir_opt_algebraic_state822_xforms[] = {
  { &search547, &replace547.value, 0 },
};
static const struct transform nir_opt_algebraic_state823_xforms[] = {
  { &search549, &replace549.value, 0 },
};
static const struct transform nir_opt_algebraic_state824_xforms[] = {
  { &search555, &replace555.value, 0 },
};
static const struct transform nir_opt_algebraic_state825_xforms[] = {
  { &search564, &replace564.value, 0 },
};
static const struct transform nir_opt_algebraic_state826_xforms[] = {
  { &search562, &replace562.value, 0 },
};
static const struct transform nir_opt_algebraic_state827_xforms[] = {
  { &search552, &replace552.value, 0 },
};
static const struct transform nir_opt_algebraic_state828_xforms[] = {
  { &search558, &replace558.value, 0 },
};
static const struct transform nir_opt_algebraic_state829_xforms[] = {
  { &search560, &replace560.value, 0 },
};
static const struct transform nir_opt_algebraic_state830_xforms[] = {
  { &search550, &replace550.value, 0 },
};
static const struct transform nir_opt_algebraic_state831_xforms[] = {
  { &search556, &replace556.value, 0 },
};
static const struct transform nir_opt_algebraic_state832_xforms[] = {
  { &search546, &replace546.value, 0 },
};
static const struct transform nir_opt_algebraic_state833_xforms[] = {
  { &search548, &replace548.value, 0 },
};
static const struct transform nir_opt_algebraic_state834_xforms[] = {
  { &search554, &replace554.value, 0 },
};
static const struct transform nir_opt_algebraic_state835_xforms[] = {
  { &search306, &search0_0.value, 0 },
  { &search15_0, &replace480.value, 26 },
};
static const struct transform nir_opt_algebraic_state836_xforms[] = {
  { &search176, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state837_xforms[] = {
  { &search176, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state838_xforms[] = {
  { &search176, &search6_0.value, 0 },
  { &search178, &replace178.value, 0 },
};
static const struct transform nir_opt_algebraic_state839_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search185, &search145_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state840_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search185, &search145_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state841_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search180, &replace157.value, 0 },
  { &search185, &search145_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state842_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search185, &search145_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state843_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search203, &search203_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state844_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search203, &search203_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state845_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search185, &search145_0.value, 0 },
  { &search203, &search203_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state846_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search189, &search6_0.value, 0 },
  { &search203, &search203_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state847_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search185, &search145_0.value, 0 },
  { &search187, &search145_0.value, 0 },
  { &search203, &search203_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state848_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search185, &search145_0.value, 0 },
  { &search203, &search203_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state849_xforms[] = {
  { &search171, &search6_0.value, 0 },
  { &search197, &replace197.value, 15 },
  { &search203, &search203_0_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state850_xforms[] = {
  { &search126, &replace126.value, 0 },
  { &search257, &replace257.value, 0 },
};
static const struct transform nir_opt_algebraic_state851_xforms[] = {
  { &search115, &replace103.value, 0 },
};
static const struct transform nir_opt_algebraic_state852_xforms[] = {
  { &search127, &replace126.value, 0 },
};
static const struct transform nir_opt_algebraic_state853_xforms[] = {
  { &search110, &replace110.value, 0 },
  { &search122, &replace122.value, 0 },
};
static const struct transform nir_opt_algebraic_state855_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state856_xforms[] = {
  { &search485, &replace485.value, 0 },
};
static const struct transform nir_opt_algebraic_state860_xforms[] = {
  { &search44, &replace43.value, 0 },
};
static const struct transform nir_opt_algebraic_state861_xforms[] = {
  { &search100, &replace100.value, 0 },
  { &search123, &replace123.value, 0 },
};
static const struct transform nir_opt_algebraic_state862_xforms[] = {
  { &search344, &replace344.value, 19 },
};
static const struct transform nir_opt_algebraic_state863_xforms[] = {
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state864_xforms[] = {
  { &search67, &replace67.value, 3 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state865_xforms[] = {
  { &search23, &search6_0.value, 0 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state866_xforms[] = {
  { &search23, &search6_0.value, 0 },
  { &search67, &replace67.value, 3 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state867_xforms[] = {
  { &search23, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state868_xforms[] = {
  { &search29, &search23_1.value, 0 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state869_xforms[] = {
  { &search29, &search23_1.value, 0 },
  { &search67, &replace67.value, 3 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state870_xforms[] = {
  { &search27, &replace27.value, 0 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state871_xforms[] = {
  { &search27, &replace27.value, 0 },
  { &search65, &replace65.value, 11 },
  { &search66, &replace66.value, 12 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state872_xforms[] = {
  { &search27, &replace27.value, 0 },
  { &search67, &replace67.value, 3 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state873_xforms[] = {
  { &search27, &replace27.value, 0 },
  { &search65, &replace65.value, 11 },
  { &search66, &replace66.value, 12 },
  { &search67, &replace67.value, 3 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state874_xforms[] = {
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
  { &search481, &search477.value, 0 },
};
static const struct transform nir_opt_algebraic_state875_xforms[] = {
  { &search67, &replace67.value, 3 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
  { &search481, &search477.value, 0 },
};
static const struct transform nir_opt_algebraic_state876_xforms[] = {
  { &search29, &search23_1.value, 0 },
  { &search61, &search60.value, 8 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state877_xforms[] = {
  { &search29, &search23_1.value, 0 },
  { &search61, &search60.value, 8 },
  { &search67, &replace67.value, 3 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state878_xforms[] = {
  { &search34, &replace13_1_0.value, 0 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state879_xforms[] = {
  { &search34, &replace13_1_0.value, 0 },
  { &search67, &replace67.value, 3 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state880_xforms[] = {
  { &search27, &replace27.value, 0 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state881_xforms[] = {
  { &search27, &replace27.value, 0 },
  { &search65, &replace65.value, 11 },
  { &search66, &replace66.value, 12 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state882_xforms[] = {
  { &search113, &replace93.value, 0 },
};
static const struct transform nir_opt_algebraic_state883_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search204, &replace204.value, 0 },
};
static const struct transform nir_opt_algebraic_state884_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search204, &replace204.value, 0 },
};
static const struct transform nir_opt_algebraic_state885_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search204, &replace204.value, 0 },
};
static const struct transform nir_opt_algebraic_state886_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search186, &replace186.value, 0 },
  { &search204, &replace204.value, 0 },
};
static const struct transform nir_opt_algebraic_state887_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search190, &search6_0.value, 0 },
  { &search204, &replace204.value, 0 },
};
static const struct transform nir_opt_algebraic_state888_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search182, &replace182.value, 0 },
  { &search204, &replace204.value, 0 },
};
static const struct transform nir_opt_algebraic_state889_xforms[] = {
  { &search173, &search6_0.value, 0 },
  { &search186, &replace186.value, 0 },
  { &search188, &replace186.value, 0 },
  { &search204, &replace204.value, 0 },
};
static const struct transform nir_opt_algebraic_state890_xforms[] = {
  { &search333, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state891_xforms[] = {
  { &search337, &search6_0.value, 0 },
  { &search416, &replace416.value, 23 },
  { &search338_1, &replace417.value, 23 },
  { &search418, &replace418.value, 23 },
  { &search339_1, &replace469.value, 24 },
};
static const struct transform nir_opt_algebraic_state892_xforms[] = {
  { &search30, &replace8.value, 0 },
};
static const struct transform nir_opt_algebraic_state893_xforms[] = {
  { &search175, &search6_0.value, 0 },
  { &search205, &replace205.value, 0 },
};
static const struct transform nir_opt_algebraic_state894_xforms[] = {
  { &search175, &search6_0.value, 0 },
  { &search205, &replace205.value, 0 },
};
static const struct transform nir_opt_algebraic_state895_xforms[] = {
  { &search175, &search6_0.value, 0 },
  { &search181, &replace181.value, 0 },
  { &search205, &replace205.value, 0 },
};
static const struct transform nir_opt_algebraic_state896_xforms[] = {
  { &search119, &replace119.value, 0 },
  { &search251, &replace251.value, 0 },
};
static const struct transform nir_opt_algebraic_state897_xforms[] = {
  { &search27, &replace27.value, 0 },
  { &search64, &replace64.value, 3 },
  { &search65, &replace65.value, 11 },
  { &search66, &replace66.value, 12 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state898_xforms[] = {
  { &search27, &replace27.value, 0 },
  { &search64, &replace64.value, 3 },
  { &search65, &replace65.value, 11 },
  { &search66, &replace66.value, 12 },
  { &search67, &replace67.value, 3 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state899_xforms[] = {
  { &search27, &replace27.value, 0 },
  { &search64, &replace64.value, 3 },
  { &search65, &replace65.value, 11 },
  { &search66, &replace66.value, 12 },
  { &search68, &replace65.value, 11 },
  { &search69, &replace66.value, 12 },
  { &search71, &search70.value, 14 },
};
static const struct transform nir_opt_algebraic_state900_xforms[] = {
  { &search35, &search23_1.value, 0 },
  { &search39, &search6_0.value, 0 },
  { &search41, &search14_0.value, 0 },
  { &search72, &replace72.value, 0 },
};
static const struct transform nir_opt_algebraic_state901_xforms[] = {
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state903_xforms[] = {
  { &search305, &replace305.value, 0 },
  { &search316, &search6_0.value, 0 },
  { &search317, &search6_0.value, 0 },
  { &search318, &replace8.value, 0 },
  { &search328, &replace13_1_0.value, 0 },
  { &search422, &replace422.value, 23 },
  { &search472, &replace472.value, 24 },
};
static const struct transform nir_opt_algebraic_state904_xforms[] = {
  { &search167, &replace93.value, 0 },
  { &search168, &replace93.value, 0 },
  { &search170, &replace97.value, 0 },
  { &search244, &replace244.value, 0 },
  { &search383, &replace13_1_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state905_xforms[] = {
  { &search333, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state906_xforms[] = {
  { &search337, &search6_0.value, 0 },
  { &search416, &replace416.value, 23 },
  { &search338_1, &replace417.value, 23 },
  { &search418, &replace418.value, 23 },
  { &search339_1, &replace469.value, 24 },
};
static const struct transform nir_opt_algebraic_state907_xforms[] = {
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state908_xforms[] = {
  { &search305, &replace305.value, 0 },
  { &search316, &search6_0.value, 0 },
  { &search317, &search6_0.value, 0 },
  { &search318, &replace8.value, 0 },
  { &search328, &replace13_1_0.value, 0 },
  { &search422, &replace422.value, 23 },
  { &search472, &replace472.value, 24 },
};
static const struct transform nir_opt_algebraic_state909_xforms[] = {
  { &search333, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state910_xforms[] = {
  { &search337, &search6_0.value, 0 },
  { &search416, &replace416.value, 23 },
  { &search338_1, &replace417.value, 23 },
  { &search418, &replace418.value, 23 },
  { &search339_1, &replace469.value, 24 },
};
static const struct transform nir_opt_algebraic_state911_xforms[] = {
  { &search319, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state912_xforms[] = {
  { &search305, &replace305.value, 0 },
  { &search316, &search6_0.value, 0 },
  { &search317, &search6_0.value, 0 },
  { &search318, &replace8.value, 0 },
  { &search328, &replace13_1_0.value, 0 },
  { &search422, &replace422.value, 23 },
  { &search472, &replace472.value, 24 },
};
static const struct transform nir_opt_algebraic_state913_xforms[] = {
  { &search333, &search6_0.value, 0 },
};
static const struct transform nir_opt_algebraic_state914_xforms[] = {
  { &search337, &search6_0.value, 0 },
  { &search416, &replace416.value, 23 },
  { &search338_1, &replace417.value, 23 },
  { &search418, &replace418.value, 23 },
  { &search339_1, &replace469.value, 24 },
};
static const struct transform nir_opt_algebraic_state915_xforms[] = {
  { &search319, &search6_0.value, 0 },
  { &search673, &replace673.value, 0 },
};

static const struct per_op_table nir_opt_algebraic_table[nir_num_search_ops] = {
   [nir_op_imul] = {
      .filter = (uint16_t []) {
         0,
         1,
         2,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         4,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         5,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         6,
         6,
         0,
         0,
         6,
         6,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         2,
         3,
         3,
         3,
         3,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         4,
         4,
         4,
         4,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         6,
         6,
         0,
         0,
         0,
         0,
         0,
         0,
         6,
         6,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         6,
         6,
         6,
         6,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         6,
         6,
         6,
         6,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         6,
         6,
         6,
         6,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         6,
         6,
         6,
         6,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         5,
         5,
         5,
         5,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         4,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         6,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 7,
      .table = (uint16_t []) {
      
         2,
         3,
         2,
         2,
         183,
         2,
         2,
         3,
         3,
         184,
         185,
         186,
         3,
         187,
         2,
         184,
         2,
         2,
         183,
         2,
         2,
         2,
         185,
         2,
         2,
         183,
         2,
         2,
         183,
         186,
         183,
         183,
         183,
         183,
         183,
         2,
         3,
         2,
         2,
         183,
         188,
         2,
         2,
         187,
         2,
         2,
         183,
         2,
         2,
      },
   },
   [nir_op_unpack_64_2x32_split_x] = {
      .filter = (uint16_t []) {
         0,
         0,
         0,
         0,
         0,
         1,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 4,
      .table = (uint16_t []) {
      
         4,
         204,
         205,
         206,
      },
   },
   [nir_op_imul_2x32_64] = {
      .filter = (uint16_t []) {
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 1,
      .table = (uint16_t []) {
      
         5,
      },
   },
   [nir_op_umul_2x32_64] = {
      .filter = (uint16_t []) {
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 1,
      .table = (uint16_t []) {
      
         6,
      },
   },
   [nir_op_udiv] = {
      .filter = (uint16_t []) {
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (uint16_t []) {
      
         0,
         7,
         0,
         7,
      },
   },
   [nir_op_idiv] = {
      .filter = (uint16_t []) {
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (uint16_t []) {
      
         0,
         8,
         0,
         8,
      },
   },
   [nir_op_umod] = {
      .filter = (uint16_t []) {
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (uint16_t []) {
      
         0,
         9,
         0,
         9,
      },
   },
   [nir_op_imod] = {
      .filter = (uint16_t []) {
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (uint16_t []) {
      
         0,
         10,
         0,
         10,
      },
   },
   [nir_op_fneg] = {
      .filter = (uint16_t []) {
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         2,
         0,
         0,
         0,
         0,
         0,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         4,
         0,
         0,
         5,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         1,
         1,
         1,
         1,
         2,
         2,
         2,
         2,
         2,
         2,
         2,
         2,
         2,
         2,
         0,
         0,
         0,
         0,
         0,
         3,
         3,
         3,
         3,
         3,
         3,
         0,
         0,
         0,
         0,
         0,
         6,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         3,
         3,
         3,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         3,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 7,
      .table = (uint16_t []) {
      
         11,
         207,
         208,
         209,
         210,
         211,
         782,
      },
   },
   [nir_op_ineg] = {
      .filter = (uint16_t []) {
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         0,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         4,
         4,
         4,
         4,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         1,
         1,
         1,
         2,
         2,
         2,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         4,
         4,
         4,
         4,
         4,
         4,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         5,
         3,
         5,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 6,
      .table = (uint16_t []) {
      
         12,
         357,
         358,
         359,
         360,
         835,
      },
   },
   [nir_op_fabs] = {
      .filter = (uint16_t []) {
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         2,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         4,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         5,
         6,
         7,
         8,
         0,
         9,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         10,
         0,
         10,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         1,
         1,
         1,
         1,
         2,
         2,
         2,
         2,
         2,
         2,
         2,
         2,
         2,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         9,
         9,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         10,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         10,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 11,
      .table = (uint16_t []) {
      
         13,
         212,
         213,
         214,
         215,
         216,
         217,
         218,
         219,
         220,
         221,
      },
   },
   [nir_search_op_u2f] = {
      .filter = (uint16_t []) {
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         1,
         1,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (uint16_t []) {
      
         14,
         573,
      },
   },
   [nir_op_iabs] = {
      .filter = (uint16_t []) {
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         0,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         4,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         1,
         1,
         1,
         2,
         2,
         2,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         5,
         5,
         5,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         3,
         3,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         4,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 6,
      .table = (uint16_t []) {
      
         15,
         361,
         362,
         363,
         364,
         814,
      },
   },
   [nir_search_op_f2b] = {
      .filter = (uint16_t []) {
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         1,
         1,
         1,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 3,
      .table = (uint16_t []) {
      
         16,
         222,
         223,
      },
   },
   [nir_search_op_i2b] = {
      .filter = (uint16_t []) {
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         0,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         1,
         1,
         1,
         2,
         2,
         2,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         3,
         3,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 4,
      .table = (uint16_t []) {
      
         17,
         365,
         366,
         367,
      },
   },
   [nir_op_fadd] = {
      .filter = (uint16_t []) {
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         4,
         0,
         0,
         0,
         5,
         5,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         6,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         0,
         0,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         8,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         2,
         2,
         9,
         10,
         11,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         12,
         3,
         3,
         13,
         4,
         4,
         4,
         4,
         4,
         12,
         12,
         12,
         3,
         3,
         3,
         5,
         5,
         14,
         15,
         5,
         5,
         5,
         5,
         14,
         5,
         15,
         5,
         14,
         15,
         5,
         14,
         15,
         14,
         16,
         5,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         8,
         8,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         12,
         3,
         13,
         13,
         13,
         4,
         4,
         12,
         12,
         12,
         3,
         12,
         12,
         3,
         12,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         17,
         18,
         5,
         17,
         18,
         5,
         5,
         17,
         18,
         5,
         17,
         18,
         5,
         19,
         20,
         14,
         21,
         22,
         15,
         17,
         18,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         23,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         24,
         24,
         24,
         24,
         25,
         26,
         24,
         0,
         0,
         3,
         3,
         4,
         4,
         4,
         12,
         12,
         3,
         3,
         3,
         3,
         3,
         3,
         12,
         12,
         3,
         3,
         3,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         3,
         3,
         5,
         0,
         0,
         0,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 27,
      .table = (uint16_t []) {
      
         18,
         19,
         224,
         18,
         18,
         225,
         18,
         18,
         226,
         224,
         224,
         728,
         729,
         729,
         225,
         225,
         225,
         863,
         863,
         864,
         864,
         863,
         863,
         18,
         863,
         864,
         863,
         19,
         19,
         227,
         228,
         229,
         230,
         19,
         231,
         232,
         730,
         731,
         732,
         733,
         734,
         230,
         230,
         230,
         865,
         865,
         866,
         866,
         865,
         865,
         867,
         865,
         866,
         865,
         224,
         227,
         224,
         233,
         233,
         234,
         224,
         224,
         235,
         224,
         224,
         728,
         735,
         735,
         234,
         234,
         234,
         868,
         868,
         869,
         869,
         868,
         868,
         224,
         868,
         869,
         868,
         18,
         228,
         233,
         18,
         18,
         225,
         18,
         18,
         226,
         233,
         233,
         736,
         729,
         729,
         225,
         225,
         225,
         863,
         863,
         864,
         864,
         863,
         863,
         18,
         863,
         864,
         863,
         18,
         229,
         233,
         18,
         18,
         225,
         18,
         18,
         226,
         233,
         233,
         736,
         729,
         729,
         225,
         225,
         225,
         863,
         863,
         864,
         864,
         863,
         863,
         18,
         863,
         864,
         863,
         225,
         230,
         234,
         225,
         225,
         236,
         225,
         225,
         237,
         234,
         234,
         737,
         738,
         738,
         236,
         236,
         236,
         870,
         871,
         872,
         873,
         870,
         871,
         225,
         871,
         873,
         871,
         18,
         19,
         224,
         18,
         18,
         225,
         238,
         18,
         226,
         224,
         739,
         728,
         729,
         729,
         225,
         225,
         225,
         863,
         863,
         864,
         864,
         863,
         863,
         18,
         863,
         864,
         863,
         18,
         231,
         224,
         18,
         18,
         225,
         18,
         18,
         226,
         224,
         224,
         728,
         729,
         729,
         225,
         225,
         225,
         863,
         863,
         864,
         864,
         863,
         863,
         18,
         863,
         864,
         863,
         226,
         232,
         235,
         226,
         226,
         237,
         226,
         226,
         226,
         235,
         235,
         740,
         741,
         741,
         237,
         237,
         237,
         874,
         874,
         875,
         875,
         874,
         874,
         226,
         874,
         875,
         874,
         224,
         730,
         224,
         233,
         233,
         234,
         224,
         224,
         235,
         224,
         224,
         728,
         735,
         735,
         234,
         234,
         234,
         868,
         868,
         869,
         869,
         868,
         868,
         224,
         868,
         869,
         868,
         224,
         731,
         224,
         233,
         233,
         234,
         739,
         224,
         235,
         224,
         224,
         728,
         735,
         735,
         234,
         234,
         234,
         868,
         868,
         869,
         869,
         868,
         868,
         224,
         868,
         869,
         868,
         728,
         732,
         728,
         736,
         736,
         737,
         728,
         728,
         740,
         728,
         728,
         728,
         742,
         742,
         737,
         737,
         737,
         876,
         876,
         877,
         877,
         876,
         876,
         728,
         876,
         877,
         876,
         729,
         733,
         735,
         729,
         729,
         738,
         729,
         729,
         741,
         735,
         735,
         742,
         729,
         729,
         738,
         738,
         738,
         878,
         878,
         879,
         879,
         878,
         878,
         729,
         878,
         879,
         878,
         729,
         734,
         735,
         729,
         729,
         738,
         729,
         729,
         741,
         735,
         735,
         742,
         729,
         729,
         738,
         738,
         738,
         878,
         878,
         879,
         879,
         878,
         878,
         729,
         878,
         879,
         878,
         225,
         230,
         234,
         225,
         225,
         236,
         225,
         225,
         237,
         234,
         234,
         737,
         738,
         738,
         236,
         236,
         236,
         870,
         871,
         872,
         873,
         870,
         871,
         225,
         897,
         898,
         897,
         225,
         230,
         234,
         225,
         225,
         236,
         225,
         225,
         237,
         234,
         234,
         737,
         738,
         738,
         236,
         743,
         743,
         870,
         871,
         872,
         873,
         880,
         881,
         225,
         871,
         873,
         881,
         225,
         230,
         234,
         225,
         225,
         236,
         225,
         225,
         237,
         234,
         234,
         737,
         738,
         738,
         236,
         743,
         743,
         870,
         871,
         872,
         873,
         880,
         881,
         225,
         897,
         898,
         899,
         863,
         865,
         868,
         863,
         863,
         870,
         863,
         863,
         874,
         868,
         868,
         876,
         878,
         878,
         870,
         870,
         870,
         870,
         871,
         872,
         873,
         870,
         871,
         863,
         871,
         873,
         871,
         863,
         865,
         868,
         863,
         863,
         871,
         863,
         863,
         874,
         868,
         868,
         876,
         878,
         878,
         871,
         871,
         871,
         871,
         871,
         873,
         873,
         871,
         871,
         863,
         871,
         873,
         871,
         864,
         866,
         869,
         864,
         864,
         872,
         864,
         864,
         875,
         869,
         869,
         877,
         879,
         879,
         872,
         872,
         872,
         872,
         873,
         872,
         873,
         872,
         873,
         864,
         898,
         898,
         898,
         864,
         866,
         869,
         864,
         864,
         873,
         864,
         864,
         875,
         869,
         869,
         877,
         879,
         879,
         873,
         873,
         873,
         873,
         873,
         873,
         873,
         873,
         873,
         864,
         898,
         898,
         898,
         863,
         865,
         868,
         863,
         863,
         870,
         863,
         863,
         874,
         868,
         868,
         876,
         878,
         878,
         870,
         880,
         880,
         870,
         871,
         872,
         873,
         880,
         881,
         863,
         871,
         873,
         881,
         863,
         865,
         868,
         863,
         863,
         871,
         863,
         863,
         874,
         868,
         868,
         876,
         878,
         878,
         871,
         881,
         881,
         871,
         871,
         873,
         873,
         881,
         881,
         863,
         871,
         873,
         881,
         18,
         867,
         224,
         18,
         18,
         225,
         18,
         18,
         226,
         224,
         224,
         728,
         729,
         729,
         225,
         225,
         225,
         863,
         863,
         864,
         864,
         863,
         863,
         18,
         863,
         864,
         863,
         863,
         865,
         868,
         863,
         863,
         871,
         863,
         863,
         874,
         868,
         868,
         876,
         878,
         878,
         897,
         871,
         897,
         871,
         871,
         898,
         898,
         871,
         871,
         863,
         871,
         898,
         871,
         864,
         866,
         869,
         864,
         864,
         873,
         864,
         864,
         875,
         869,
         869,
         877,
         879,
         879,
         898,
         873,
         898,
         873,
         873,
         898,
         898,
         873,
         873,
         864,
         898,
         898,
         898,
         863,
         865,
         868,
         863,
         863,
         871,
         863,
         863,
         874,
         868,
         868,
         876,
         878,
         878,
         897,
         881,
         899,
         871,
         871,
         898,
         898,
         881,
         881,
         863,
         871,
         898,
         881,
      },
   },
   [nir_op_iadd] = {
      .filter = (uint16_t []) {
         0,
         1,
         2,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         4,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         5,
         6,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         0,
         0,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         8,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         2,
         3,
         3,
         3,
         3,
         2,
         9,
         5,
         6,
         10,
         6,
         6,
         6,
         6,
         5,
         9,
         9,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         4,
         4,
         4,
         4,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         11,
         11,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         8,
         5,
         6,
         6,
         9,
         5,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         12,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         9,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 13,
      .table = (uint16_t []) {
      
         20,
         21,
         20,
         20,
         189,
         20,
         20,
         20,
         190,
         696,
         696,
         20,
         189,
         21,
         21,
         21,
         191,
         192,
         193,
         194,
         195,
         196,
         697,
         698,
         21,
         192,
         20,
         21,
         197,
         197,
         189,
         20,
         20,
         20,
         190,
         696,
         696,
         20,
         189,
         20,
         191,
         197,
         197,
         189,
         20,
         20,
         20,
         190,
         696,
         696,
         20,
         189,
         189,
         192,
         189,
         189,
         189,
         198,
         198,
         189,
         199,
         699,
         699,
         189,
         189,
         20,
         193,
         20,
         20,
         198,
         20,
         20,
         20,
         190,
         696,
         696,
         20,
         198,
         20,
         194,
         20,
         20,
         198,
         20,
         20,
         20,
         190,
         696,
         696,
         20,
         198,
         20,
         195,
         20,
         20,
         189,
         20,
         20,
         20,
         190,
         696,
         696,
         20,
         189,
         190,
         196,
         190,
         190,
         199,
         190,
         190,
         190,
         190,
         700,
         700,
         190,
         199,
         696,
         697,
         696,
         696,
         699,
         696,
         696,
         696,
         700,
         696,
         696,
         696,
         699,
         696,
         698,
         696,
         696,
         699,
         696,
         696,
         696,
         700,
         696,
         696,
         696,
         699,
         20,
         21,
         20,
         20,
         189,
         20,
         20,
         20,
         190,
         696,
         696,
         20,
         892,
         189,
         192,
         189,
         189,
         189,
         198,
         198,
         189,
         199,
         699,
         699,
         892,
         189,
      },
   },
   [nir_op_usadd_4x8] = {
      .filter = (uint16_t []) {
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (uint16_t []) {
      
         0,
         22,
         22,
         22,
      },
   },
   [nir_op_fmul] = {
      .filter = (uint16_t []) {
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         4,
         0,
         5,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         6,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         0,
         0,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         8,
         9,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         2,
         2,
         2,
         2,
         2,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         10,
         0,
         0,
         11,
         0,
         0,
         0,
         0,
         0,
         10,
         10,
         10,
         0,
         0,
         0,
         3,
         12,
         3,
         3,
         4,
         4,
         4,
         13,
         4,
         4,
         4,
         12,
         3,
         3,
         12,
         12,
         12,
         3,
         3,
         3,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         7,
         7,
         7,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         9,
         9,
         9,
         9,
         9,
         0,
         0,
         0,
         0,
         0,
         0,
         8,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         10,
         0,
         11,
         14,
         11,
         0,
         0,
         10,
         10,
         10,
         0,
         10,
         10,
         0,
         10,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         3,
         3,
         4,
         4,
         4,
         4,
         3,
         3,
         3,
         12,
         12,
         12,
         3,
         3,
         3,
         3,
         3,
         3,
         3,
         3,
         2,
         0,
         8,
         8,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         3,
         4,
         3,
         12,
         3,
         3,
         3,
         0,
         8,
         0,
         0,
         0,
         0,
         15,
         10,
         10,
         0,
         0,
         0,
         0,
         0,
         0,
         10,
         10,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         4,
         0,
         0,
         0,
         7,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 16,
      .table = (uint16_t []) {
      
         23,
         24,
         239,
         23,
         23,
         240,
         241,
         23,
         23,
         242,
         761,
         762,
         763,
         763,
         854,
         23,
         24,
         24,
         243,
         244,
         245,
         246,
         247,
         248,
         24,
         249,
         764,
         765,
         766,
         767,
         855,
         900,
         239,
         243,
         239,
         239,
         239,
         250,
         251,
         239,
         239,
         252,
         768,
         769,
         770,
         770,
         856,
         239,
         23,
         244,
         239,
         23,
         23,
         253,
         241,
         23,
         23,
         242,
         761,
         762,
         763,
         763,
         854,
         23,
         23,
         245,
         239,
         23,
         23,
         253,
         241,
         23,
         23,
         242,
         761,
         762,
         763,
         763,
         854,
         23,
         240,
         246,
         250,
         253,
         253,
         240,
         254,
         240,
         240,
         255,
         771,
         772,
         773,
         773,
         857,
         240,
         241,
         247,
         251,
         241,
         241,
         254,
         256,
         241,
         241,
         257,
         774,
         775,
         776,
         776,
         858,
         241,
         23,
         248,
         239,
         23,
         23,
         240,
         241,
         23,
         23,
         242,
         761,
         762,
         763,
         763,
         854,
         23,
         23,
         24,
         239,
         23,
         23,
         240,
         241,
         23,
         258,
         242,
         761,
         762,
         763,
         763,
         854,
         23,
         242,
         249,
         252,
         242,
         242,
         255,
         257,
         242,
         242,
         242,
         777,
         778,
         779,
         779,
         859,
         242,
         761,
         764,
         768,
         761,
         761,
         771,
         774,
         761,
         761,
         777,
         761,
         762,
         780,
         780,
         854,
         761,
         762,
         765,
         769,
         762,
         762,
         772,
         775,
         762,
         762,
         778,
         762,
         762,
         781,
         781,
         854,
         762,
         763,
         766,
         770,
         763,
         763,
         773,
         776,
         763,
         763,
         779,
         780,
         781,
         763,
         763,
         860,
         763,
         763,
         767,
         770,
         763,
         763,
         773,
         776,
         763,
         763,
         779,
         780,
         781,
         763,
         763,
         860,
         763,
         854,
         855,
         856,
         854,
         854,
         857,
         858,
         854,
         854,
         859,
         854,
         854,
         860,
         860,
         854,
         854,
         23,
         900,
         239,
         23,
         23,
         240,
         241,
         23,
         23,
         242,
         761,
         762,
         763,
         763,
         854,
         23,
      },
   },
   [nir_op_umul_unorm_4x8] = {
      .filter = (uint16_t []) {
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (uint16_t []) {
      
         0,
         25,
         25,
         25,
      },
   },
   [nir_op_fsign] = {
      .filter = (uint16_t []) {
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 1,
      .table = (uint16_t []) {
      
         26,
      },
   },
   [nir_op_ffma] = {
      .filter = (uint16_t []) {
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },
      
      .num_filtered_states = 2,
      .table = (uint16_t []) {
      
         27,
         28,
         29,
         30,
         31,
         32,
         33,
         34,
      },
   },
   [nir_op_flrp] = {
      .filter = (uint16_t []) {
         0,
         1,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
         0,
      },