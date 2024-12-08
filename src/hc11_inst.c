#include "hc11.h"
#include "hc11_inst.h"
#include "hc11_search.h"
#include <stdlib.h>

// Function declarations

void ABA_I(hc11_t*);	// 1B
void ABX_I(hc11_t*);	// 3A
void ABY_I(hc11_t*);	// 183A
void ADCA_M(hc11_t*);	// 89
void ADCA_D(hc11_t*);	// 99
void ADCA_E(hc11_t*);	// B9
void ADCA_X(hc11_t*);	// A9
void ADCA_Y(hc11_t*);	// 18A9
void ADCB_M(hc11_t*);	// C9
void ADCB_D(hc11_t*);	// D9
void ADCB_E(hc11_t*);	// F9
void ADCB_X(hc11_t*);	// E9
void ADCB_Y(hc11_t*);	// 18E9
void ADDA_M(hc11_t*);	// 8B
void ADDA_D(hc11_t*);	// 9B
void ADDA_E(hc11_t*);	// BB
void ADDA_X(hc11_t*);	// AB
void ADDA_Y(hc11_t*);	// 18AB
void ADDB_M(hc11_t*);	// CB
void ADDB_D(hc11_t*);	// DB
void ADDB_E(hc11_t*);	// FB
void ADDB_X(hc11_t*);	// EB
void ADDB_Y(hc11_t*);	// 18EB
void ADDD_M(hc11_t*);	// C3
void ADDD_D(hc11_t*);	// D3
void ADDD_E(hc11_t*);	// F3
void ADDD_X(hc11_t*);	// E3
void ADDD_Y(hc11_t*);	// 18E3
void ANDA_M(hc11_t*);	// 84
void ANDA_D(hc11_t*);	// 94
void ANDA_E(hc11_t*);	// B4
void ANDA_X(hc11_t*);	// A4
void ANDA_Y(hc11_t*);	// 18A4
void ANDB_M(hc11_t*);	// C4
void ANDB_D(hc11_t*);	// D4
void ANDB_E(hc11_t*);	// F4
void ANDB_X(hc11_t*);	// E4
void ANDB_Y(hc11_t*);	// 18E4
void ASL_E(hc11_t*);	// 78
void ASL_X(hc11_t*);	// 68
void ASL_Y(hc11_t*);	// 1868
void ASLA_I(hc11_t*);	// 48
void ASLB_I(hc11_t*);	// 58
void ASLD_I(hc11_t*);	// 05
void ASR_E(hc11_t*);	// 77
void ASR_X(hc11_t*);	// 67
void ASR_Y(hc11_t*);	// 1867
void ASRA_I(hc11_t*);	// 47
void ASRB_I(hc11_t*);	// 57
void BCC_R(hc11_t*);	// 24
void BCLR_D(hc11_t*);	// 15
void BCLR_X(hc11_t*);	// 1D
void BCLR_Y(hc11_t*);	// 181D
void BCS_R(hc11_t*);	// 25
void BEQ_R(hc11_t*);	// 27
void BGE_R(hc11_t*);	// 2C
void BGT_R(hc11_t*);	// 2E
void BHI_R(hc11_t*);	// 22
void BHS_R(hc11_t*);	// 24
void BITA_M(hc11_t*);	// 85
void BITA_D(hc11_t*);	// 95
void BITA_E(hc11_t*);	// B5
void BITA_X(hc11_t*);	// A5
void BITA_Y(hc11_t*);	// 18A5
void BITB_M(hc11_t*);	// C5
void BITB_D(hc11_t*);	// D5
void BITB_E(hc11_t*);	// F5
void BITB_X(hc11_t*);	// E5
void BITB_Y(hc11_t*);	// 18E3
void BLE_R(hc11_t*);	// 2F
void BLO_R(hc11_t*);	// 25
void BLS_R(hc11_t*);	// 23
void BLT_R(hc11_t*);	// 2D
void BMI_R(hc11_t*);	// 2B
void BNE_R(hc11_t*);	// 26
void BPL_R(hc11_t*);	// 2A
void BRA_R(hc11_t*);	// 20
void BRCLR_D(hc11_t*);	// 13
void BRCLR_X(hc11_t*);	// 1F
void BRCLR_Y(hc11_t*);	// 181F
void BRN_R(hc11_t*);	// 21
void BRSET_D(hc11_t*);	// 12
void BRSET_X(hc11_t*);	// 1E
void BRSET_Y(hc11_t*);	// 181E
void BSET_D(hc11_t*);	// 14
void BSET_X(hc11_t*);	// 1C
void BSET_Y(hc11_t*);	// 181C
void BSR_R(hc11_t*);	// 8D
void BVC_R(hc11_t*);	// 28
void BVS_R(hc11_t*);	// 29
void CBA_I(hc11_t*);	// 11
void CLC_I(hc11_t*);	// 0C
void CLI_I(hc11_t*);	// 0E
void CLR_E(hc11_t*);	// 7F
void CLR_X(hc11_t*);	// 6F
void CLR_Y(hc11_t*);	// 186F
void CLRA_I(hc11_t*);	// 4F
void CLRB_I(hc11_t*);	// 5F
void CLV_I(hc11_t*);	// 0A
void CMPA_M(hc11_t*);	// 81
void CMPA_D(hc11_t*);	// 91
void CMPA_E(hc11_t*);	// B1
void CMPA_X(hc11_t*);	// A1
void CMPA_Y(hc11_t*);	// 18A1
void CMPB_M(hc11_t*);	// C1
void CMPB_D(hc11_t*);	// D1
void CMPB_E(hc11_t*);	// F1
void CMPB_X(hc11_t*);	// E1
void CMPB_Y(hc11_t*);	// 18E1
void COM_E(hc11_t*);	// 73
void COM_X(hc11_t*);	// 63
void COM_Y(hc11_t*);	// 1863
void COMA_I(hc11_t*);	// 43
void COMB_I(hc11_t*);	// 53
void CPD_M(hc11_t*);	// 1A83
void CPD_D(hc11_t*);	// 1A93
void CPD_E(hc11_t*);	// 1AB3
void CPD_X(hc11_t*);	// 1AA3
void CPD_Y(hc11_t*);	// CDA3
void CPX_M(hc11_t*);	// 8C
void CPX_D(hc11_t*);	// 9C
void CPX_E(hc11_t*);	// BC
void CPX_X(hc11_t*);	// AC
void CPX_Y(hc11_t*);	// CDAC
void CPY_M(hc11_t*);	// 188C
void CPY_D(hc11_t*);	// 189C
void CPY_E(hc11_t*);	// 18BC
void CPY_X(hc11_t*);	// 1AAC
void CPY_Y(hc11_t*);	// 18AC
void DAA_I(hc11_t*);	// 19
void DEC_E(hc11_t*);	// 7A
void DEC_X(hc11_t*);	// 6A
void DEC_Y(hc11_t*);	// 186A
void DECA_I(hc11_t*);	// 4A
void DECB_I(hc11_t*);	// 5A
void DES_I(hc11_t*);	// 34
void DEX_I(hc11_t*);	// 09
void DEY_I(hc11_t*);	// 1809
void EORA_M(hc11_t*);	// 88
void EORA_D(hc11_t*);	// 98
void EORA_E(hc11_t*);	// B8
void EORA_X(hc11_t*);	// A8
void EORA_Y(hc11_t*);	// 18A8
void EORB_M(hc11_t*);	// C8
void EORB_D(hc11_t*);	// D8
void EORB_E(hc11_t*);	// F8
void EORB_X(hc11_t*);	// E8
void EORB_Y(hc11_t*);	// 18E8
void FDIV_I(hc11_t*);	// 03
void IDIV_I(hc11_t*);	// 02
void INC_E(hc11_t*);	// 7C
void INC_X(hc11_t*);	// 6C
void INC_Y(hc11_t*);	// 186C
void INCA_I(hc11_t*);	// 4C
void INCB_I(hc11_t*);	// 5C
void INS_I(hc11_t*);	// 31
void INX_I(hc11_t*);	// 08
void INY_I(hc11_t*);	// 1808
void JMP_E(hc11_t*);	// 7E
void JMP_X(hc11_t*);	// 63
void JMP_Y(hc11_t*);	// 186E
void JSR_D(hc11_t*);	// 9D
void JSR_E(hc11_t*);	// BD
void JSR_X(hc11_t*);	// AD
void JSR_Y(hc11_t*);	// 18AD
void LDAA_M(hc11_t*);	// 86
void LDAA_D(hc11_t*);	// 96
void LDAA_E(hc11_t*);	// B6
void LDAA_X(hc11_t*);	// A6
void LDAA_Y(hc11_t*);	// 18A6
void LDAB_M(hc11_t*);	// C6
void LDAB_D(hc11_t*);	// D6
void LDAB_E(hc11_t*);	// B6
void LDAB_X(hc11_t*);	// E6
void LDAB_Y(hc11_t*);	// 18E6
void LDD_M(hc11_t*);	// CC
void LDD_D(hc11_t*);	// DC
void LDD_E(hc11_t*);	// FC
void LDD_X(hc11_t*);	// EC
void LDD_Y(hc11_t*);	// 18EC
void LDS_M(hc11_t*);	// 8E
void LDS_D(hc11_t*);	// 9E
void LDS_E(hc11_t*);	// BE
void LDS_X(hc11_t*);	// AE
void LDS_Y(hc11_t*);	// 18AE
void LDX_M(hc11_t*);	// CE
void LDX_D(hc11_t*);	// DE
void LDX_E(hc11_t*);	// FE
void LDX_X(hc11_t*);	// EE
void LDX_Y(hc11_t*);	// CDEE
void LDY_M(hc11_t*);	// 18CE
void LDY_D(hc11_t*);	// 18DE
void LDY_E(hc11_t*);	// 18FE
void LDY_X(hc11_t*);	// 1AEE
void LDY_Y(hc11_t*);	// 18EE
void LSL_E(hc11_t*);	// 78
void LSL_X(hc11_t*);	// 68
void LSL_Y(hc11_t*);	// 1868
void LSLA_I(hc11_t*);	// 48
void LSLB_I(hc11_t*);	// 58
void LSLD_I(hc11_t*);	// 05
void LSR_E(hc11_t*);	// 74
void LSR_X(hc11_t*);	// 64
void LSR_Y(hc11_t*);	// 1864
void LSRA_I(hc11_t*);	// 44
void LSRB_I(hc11_t*);	// 54
void LSRD_I(hc11_t*);	// 04
void MUL_I(hc11_t*);	// 3D
void NEG_E(hc11_t*);	// 70
void NEG_X(hc11_t*);	// 60
void NEG_Y(hc11_t*);	// 1860
void NEGA_I(hc11_t*);	// 40
void NEGB_I(hc11_t*);	// 50
void NOP_I(hc11_t*);	// 01
void ORAA_M(hc11_t*);	// 8A
void ORAA_D(hc11_t*);	// 9A
void ORAA_E(hc11_t*);	// BA
void ORAA_X(hc11_t*);	// AA
void ORAA_Y(hc11_t*);	// 18AA
void ORAB_M(hc11_t*);	// CA
void ORAB_D(hc11_t*);	// DA
void ORAB_E(hc11_t*);	// FA
void ORAB_X(hc11_t*);	// EA
void ORAB_Y(hc11_t*);	// 18EA
void PSHA_I(hc11_t*);	// 36
void PSHB_I(hc11_t*);	// 37
void PSHX_I(hc11_t*);	// 3C
void PSHY_I(hc11_t*);	// 183C
void PULA_I(hc11_t*);	// 32
void PULB_I(hc11_t*);	// 33
void PULX_I(hc11_t*);	// 38
void PULY_I(hc11_t*);	// 1838
void ROL_E(hc11_t*);	// 79
void ROL_X(hc11_t*);	// 69
void ROL_Y(hc11_t*);	// 1869
void ROLA_I(hc11_t*);	// 49
void ROLB_I(hc11_t*);	// 59
void ROR_E(hc11_t*);	// 76
void ROR_X(hc11_t*);	// 66
void ROR_Y(hc11_t*);	// 1866
void RORA_I(hc11_t*);	// 46
void RORB_I(hc11_t*);	// 56
void RTI_I(hc11_t*);	// 3B
void RTS_I(hc11_t*);	// 39
void SBA_I(hc11_t*);	// 10
void SBCA_M(hc11_t*);	// 82
void SBCA_D(hc11_t*);	// 92
void SBCA_E(hc11_t*);	// B2
void SBCA_X(hc11_t*);	// A2
void SBCA_Y(hc11_t*);	// 18A2
void SBCB_M(hc11_t*);	// C2
void SBCB_D(hc11_t*);	// D2
void SBCB_E(hc11_t*);	// F2
void SBCB_X(hc11_t*);	// E2
void SBCB_Y(hc11_t*);	// 18E2
void SEC_I(hc11_t*);	// 0D
void SEI_I(hc11_t*);	// 0F
void SEV_I(hc11_t*);	// 0B
void STAA_D(hc11_t*);	// 97
void STAA_E(hc11_t*);	// B7
void STAA_X(hc11_t*);	// A7
void STAA_Y(hc11_t*);	// 18A7
void STAB_D(hc11_t*);	// D7
void STAB_E(hc11_t*);	// F7
void STAB_X(hc11_t*);	// E7
void STAB_Y(hc11_t*);	// 18E7
void STD_D(hc11_t*);	// DD
void STD_E(hc11_t*);	// FD
void STD_X(hc11_t*);	// ED
void STD_Y(hc11_t*);	// 18ED
void STOP_I(hc11_t*);	// CF
void STS_D(hc11_t*);	// 9F
void STS_E(hc11_t*);	// BF
void STS_X(hc11_t*);	// AF
void STS_Y(hc11_t*);	// 18AF
void STX_D(hc11_t*);	// DF
void STX_E(hc11_t*);	// FF
void STX_X(hc11_t*);	// EF
void STX_Y(hc11_t*);	// CDEF
void STY_D(hc11_t*);	// 18DF
void STY_E(hc11_t*);	// 18FF
void STY_X(hc11_t*);	// 1AEF
void STY_Y(hc11_t*);	// 18EF
void SUBA_M(hc11_t*);	// 80
void SUBA_D(hc11_t*);	// 90
void SUBA_E(hc11_t*);	// B0
void SUBA_X(hc11_t*);	// A0
void SUBA_Y(hc11_t*);	// 18A0
void SUBB_M(hc11_t*);	// C0
void SUBB_D(hc11_t*);	// D0
void SUBB_E(hc11_t*);	// F0
void SUBB_X(hc11_t*);	// E0
void SUBB_Y(hc11_t*);	// 18E0
void SUBD_M(hc11_t*);	// 83
void SUBD_D(hc11_t*);	// 93
void SUBD_3(hc11_t*);	// B3
void SUBD_X(hc11_t*);	// A3
void SUBD_Y(hc11_t*);	// 18A3
void SWI_I(hc11_t*);	// 3F
void TAB_I(hc11_t*);	// 16
void TAP_I(hc11_t*);	// 06
void TBA_I(hc11_t*);	// 17
void TEST_I(hc11_t*);	// 00
void TPA_I(hc11_t*);	// 07
void TST_E(hc11_t*);	// 7D
void TST_X(hc11_t*);	// 6D
void TST_Y(hc11_t*);	// 186D
void TSTA_I(hc11_t*);	// 4D
void TSTB_I(hc11_t*);	// 5D
void TSX_I(hc11_t*);	// 30
void TSY_Y(hc11_t*);	// 1830
void TXS_I(hc11_t*);	// 35
void TYS_I(hc11_t*);	// 1835
void WAI_I(hc11_t*);	// 3E
void XGDX_I(hc11_t*);	// 8F
void XGDY_I(hc11_t*);	// 188F

/* Lookup table */

inst_t lookup[316] = {

	{ "ABA_I", {0x1B}, &ABA_I, 1 }, { "ABX_I", {0x3A}, &ABX_I, 1 }, { "ABY_I", {0x183A}, &ABY_I, 1 }, 
	{ "ADCA_M", {0x89}, &ADCA_M, 1 }, { "ADCA_D", {0x99}, &ADCA_D, 1 }, { "ADCA_E", {0xB9}, &ADCA_E, 1 }, 
	{ "ADCA_X", {0xA9}, &ADCA_X, 1 }, { "ADCA_Y", {0x18A9}, &ADCA_Y, 1 }, { "ADCB_M", {0xC9}, &ADCB_M, 1 }, 
	{ "ADCB_D", {0xD9}, &ADCB_D, 1 }, { "ADCB_E", {0xF9}, &ADCB_E, 1 }, { "ADCB_X", {0xE9}, &ADCB_X, 1 }, 
	{ "ADCB_Y", {0x18E9}, &ADCB_Y, 1 }, { "ADDA_M", {0x8B}, &ADDA_M, 1 }, { "ADDA_D", {0x9B}, &ADDA_D, 1 }, 
	{ "ADDA_E", {0xBB}, &ADDA_E, 1 }, { "ADDA_X", {0xAB}, &ADDA_X, 1 }, { "ADDA_Y", {0x18AB}, &ADDA_Y, 1 }, 
	{ "ADDB_M", {0xCB}, &ADDB_M, 1 }, { "ADDB_D", {0xDB}, &ADDB_D, 1 }, { "ADDB_E", {0xFB}, &ADDB_E, 1 }, 
	{ "ADDB_X", {0xEB}, &ADDB_X, 1 }, { "ADDB_Y", {0x18EB}, &ADDB_Y, 1 }, { "ADDD_M", {0xC3}, &ADDD_M, 1 }, 
	{ "ADDD_D", {0xD3}, &ADDD_D, 1 }, { "ADDD_E", {0xF3}, &ADDD_E, 1 }, { "ADDD_X", {0xE3}, &ADDD_X, 1 }, 
	{ "ADDD_Y", {0x18E3}, &ADDD_Y, 1 }, { "ANDA_M", {0x84}, &ANDA_M, 1 }, { "ANDA_D", {0x94}, &ANDA_D, 1 }, 
	{ "ANDA_E", {0xB4}, &ANDA_E, 1 }, { "ANDA_X", {0xA4}, &ANDA_X, 1 }, { "ANDA_Y", {0x18A4}, &ANDA_Y, 1 }, 
	{ "ANDB_M", {0xC4}, &ANDB_M, 1 }, { "ANDB_D", {0xD4}, &ANDB_D, 1 }, { "ANDB_E", {0xF4}, &ANDB_E, 1 }, 
	{ "ANDB_X", {0xE4}, &ANDB_X, 1 }, { "ANDB_Y", {0x18E4}, &ANDB_Y, 1 }, { "ASL_E", {0x78}, &ASL_E, 1 }, 
	{ "ASL_X", {0x68}, &ASL_X, 1 }, { "ASL_Y", {0x1868}, &ASL_Y, 1 }, { "ASLA_I", {0x48}, &ASLA_I, 1 }, 
	{ "ASLB_I", {0x58}, &ASLB_I, 1 }, { "ASLD_I", {0x05}, &ASLD_I, 1 }, { "ASR_E", {0x77}, &ASR_E, 1 }, 
	{ "ASR_X", {0x67}, &ASR_X, 1 }, { "ASR_Y", {0x1867}, &ASR_Y, 1 }, { "ASRA_I", {0x47}, &ASRA_I, 1 }, 
	{ "ASRB_I", {0x57}, &ASRB_I, 1 }, { "BCC_R", {0x24}, &BCC_R, 1 }, { "BCLR_D", {0x15}, &BCLR_D, 1 }, 
	{ "BCLR_X", {0x1D}, &BCLR_X, 1 }, { "BCLR_Y", {0x181D}, &BCLR_Y, 1 }, { "BCS_R", {0x25}, &BCS_R, 1 }, 
	{ "BEQ_R", {0x27}, &BEQ_R, 1 }, { "BGE_R", {0x2C}, &BGE_R, 1 }, { "BGT_R", {0x2E}, &BGT_R, 1 }, 
	{ "BHI_R", {0x22}, &BHI_R, 1 }, { "BHS_R", {0x24}, &BHS_R, 1 }, { "BITA_M", {0x85}, &BITA_M, 1 }, 
	{ "BITA_D", {0x95}, &BITA_D, 1 }, { "BITA_E", {0xB5}, &BITA_E, 1 }, { "BITA_X", {0xA5}, &BITA_X, 1 }, 
	{ "BITA_Y", {0x18A5}, &BITA_Y, 1 }, { "BITB_M", {0xC5}, &BITB_M, 1 }, { "BITB_D", {0xD5}, &BITB_D, 1 }, 
	{ "BITB_E", {0xF5}, &BITB_E, 1 }, { "BITB_X", {0xE5}, &BITB_X, 1 }, { "BITB_Y", {0x18E3}, &BITB_Y, 1 }, 
	{ "BLE_R", {0x2F}, &BLE_R, 1 }, { "BLO_R", {0x25}, &BLO_R, 1 }, { "BLS_R", {0x23}, &BLS_R, 1 }, 
	{ "BLT_R", {0x2D}, &BLT_R, 1 }, { "BMI_R", {0x2B}, &BMI_R, 1 }, { "BNE_R", {0x26}, &BNE_R, 1 }, 
	{ "BPL_R", {0x2A}, &BPL_R, 1 }, { "BRA_R", {0x20}, &BRA_R, 1 }, { "BRCLR_D", {0x13}, &BRCLR_D, 1 }, 
	{ "BRCLR_X", {0x1F}, &BRCLR_X, 1 }, { "BRCLR_Y", {0x181F}, &BRCLR_Y, 1 }, { "BRN_R", {0x21}, &BRN_R, 1 }, 
	{ "BRSET_D", {0x12}, &BRSET_D, 1 }, { "BRSET_X", {0x1E}, &BRSET_X, 1 }, { "BRSET_Y", {0x181E}, &BRSET_Y, 1 }, 
	{ "BSET_D", {0x14}, &BSET_D, 1 }, { "BSET_X", {0x1C}, &BSET_X, 1 }, { "BSET_Y", {0x181C}, &BSET_Y, 1 }, 
	{ "BSR_R", {0x8D}, &BSR_R, 1 }, { "BVC_R", {0x28}, &BVC_R, 1 }, { "BVS_R", {0x29}, &BVS_R, 1 }, 
	{ "CBA_I", {0x11}, &CBA_I, 1 }, { "CLC_I", {0x0C}, &CLC_I, 1 }, { "CLI_I", {0x0E}, &CLI_I, 1 }, 
	{ "CLR_E", {0x7F}, &CLR_E, 1 }, { "CLR_X", {0x6F}, &CLR_X, 1 }, { "CLR_Y", {0x186F}, &CLR_Y, 1 }, 
	{ "CLRA_I", {0x4F}, &CLRA_I, 1 }, { "CLRB_I", {0x5F}, &CLRB_I, 1 }, { "CLV_I", {0x0A}, &CLV_I, 1 }, 
	{ "CMPA_M", {0x81}, &CMPA_M, 1 }, { "CMPA_D", {0x91}, &CMPA_D, 1 }, { "CMPA_E", {0xB1}, &CMPA_E, 1 }, 
	{ "CMPA_X", {0xA1}, &CMPA_X, 1 }, { "CMPA_Y", {0x18A1}, &CMPA_Y, 1 }, { "CMPB_M", {0xC1}, &CMPB_M, 1 }, 
	{ "CMPB_D", {0xD1}, &CMPB_D, 1 }, { "CMPB_E", {0xF1}, &CMPB_E, 1 }, { "CMPB_X", {0xE1}, &CMPB_X, 1 }, 
	{ "CMPB_Y", {0x18E1}, &CMPB_Y, 1 }, { "COM_E", {0x73}, &COM_E, 1 }, { "COM_X", {0x63}, &COM_X, 1 }, 
	{ "COM_Y", {0x1863}, &COM_Y, 1 }, { "COMA_I", {0x43}, &COMA_I, 1 }, { "COMB_I", {0x53}, &COMB_I, 1 }, 
	{ "CPD_M", {0x1A83}, &CPD_M, 1 }, { "CPD_D", {0x1A93}, &CPD_D, 1 }, { "CPD_E", {0x1AB3}, &CPD_E, 1 }, 
	{ "CPD_X", {0x1AA3}, &CPD_X, 1 }, { "CPD_Y", {0xCDA3}, &CPD_Y, 1 }, { "CPX_M", {0x8C}, &CPX_M, 1 }, 
	{ "CPX_D", {0x9C}, &CPX_D, 1 }, { "CPX_E", {0xBC}, &CPX_E, 1 }, { "CPX_X", {0xAC}, &CPX_X, 1 }, 
	{ "CPX_Y", {0xCDAC}, &CPX_Y, 1 }, { "CPY_M", {0x188C}, &CPY_M, 1 }, { "CPY_D", {0x189C}, &CPY_D, 1 }, 
	{ "CPY_E", {0x18BC}, &CPY_E, 1 }, { "CPY_X", {0x1AAC}, &CPY_X, 1 }, { "CPY_Y", {0x18AC}, &CPY_Y, 1 }, 
	{ "DAA_I", {0x19}, &DAA_I, 1 }, { "DEC_E", {0x7A}, &DEC_E, 1 }, { "DEC_X", {0x6A}, &DEC_X, 1 }, 
	{ "DEC_Y", {0x186A}, &DEC_Y, 1 }, { "DECA_I", {0x4A}, &DECA_I, 1 }, { "DECB_I", {0x5A}, &DECB_I, 1 }, 
	{ "DES_I", {0x34}, &DES_I, 1 }, { "DEX_I", {0x09}, &DEX_I, 1 }, { "DEY_I", {0x1809}, &DEY_I, 1 }, 
	{ "EORA_M", {0x88}, &EORA_M, 1 }, { "EORA_D", {0x98}, &EORA_D, 1 }, { "EORA_E", {0xB8}, &EORA_E, 1 }, 
	{ "EORA_X", {0xA8}, &EORA_X, 1 }, { "EORA_Y", {0x18A8}, &EORA_Y, 1 }, { "EORB_M", {0xC8}, &EORB_M, 1 }, 
	{ "EORB_D", {0xD8}, &EORB_D, 1 }, { "EORB_E", {0xF8}, &EORB_E, 1 }, { "EORB_X", {0xE8}, &EORB_X, 1 }, 
	{ "EORB_Y", {0x18E8}, &EORB_Y, 1 }, { "FDIV_I", {0x03}, &FDIV_I, 1 }, { "IDIV_I", {0x02}, &IDIV_I, 1 }, 
	{ "INC_E", {0x7C}, &INC_E, 1 }, { "INC_X", {0x6C}, &INC_X, 1 }, { "INC_Y", {0x186C}, &INC_Y, 1 }, 
	{ "INCA_I", {0x4C}, &INCA_I, 1 }, { "INCB_I", {0x5C}, &INCB_I, 1 }, { "INS_I", {0x31}, &INS_I, 1 }, 
	{ "INX_I", {0x08}, &INX_I, 1 }, { "INY_I", {0x1808}, &INY_I, 1 }, { "JMP_E", {0x7E}, &JMP_E, 1 }, 
	{ "JMP_X", {0x63}, &JMP_X, 1 }, { "JMP_Y", {0x186E}, &JMP_Y, 1 }, { "JSR_D", {0x9D}, &JSR_D, 1 }, 
	{ "JSR_E", {0xBD}, &JSR_E, 1 }, { "JSR_X", {0xAD}, &JSR_X, 1 }, { "JSR_Y", {0x18AD}, &JSR_Y, 1 }, 
	{ "LDAA_M", {0x86}, &LDAA_M, 1 }, { "LDAA_D", {0x96}, &LDAA_D, 1 }, { "LDAA_E", {0xB6}, &LDAA_E, 1 }, 
	{ "LDAA_X", {0xA6}, &LDAA_X, 1 }, { "LDAA_Y", {0x18A6}, &LDAA_Y, 1 }, { "LDAB_M", {0xC6}, &LDAB_M, 1 }, 
	{ "LDAB_D", {0xD6}, &LDAB_D, 1 }, { "LDAB_E", {0xB6}, &LDAB_E, 1 }, { "LDAB_X", {0xE6}, &LDAB_X, 1 }, 
	{ "LDAB_Y", {0x18E6}, &LDAB_Y, 1 }, { "LDD_M", {0xCC}, &LDD_M, 1 }, { "LDD_D", {0xDC}, &LDD_D, 1 }, 
	{ "LDD_E", {0xFC}, &LDD_E, 1 }, { "LDD_X", {0xEC}, &LDD_X, 1 }, { "LDD_Y", {0x18EC}, &LDD_Y, 1 }, 
	{ "LDS_M", {0x8E}, &LDS_M, 1 }, { "LDS_D", {0x9E}, &LDS_D, 1 }, { "LDS_E", {0xBE}, &LDS_E, 1 }, 
	{ "LDS_X", {0xAE}, &LDS_X, 1 }, { "LDS_Y", {0x18AE}, &LDS_Y, 1 }, { "LDX_M", {0xCE}, &LDX_M, 1 }, 
	{ "LDX_D", {0xDE}, &LDX_D, 1 }, { "LDX_E", {0xFE}, &LDX_E, 1 }, { "LDX_X", {0xEE}, &LDX_X, 1 }, 
	{ "LDX_Y", {0xCDEE}, &LDX_Y, 1 }, { "LDY_M", {0x18CE}, &LDY_M, 1 }, { "LDY_D", {0x18DE}, &LDY_D, 1 }, 
	{ "LDY_E", {0x18FE}, &LDY_E, 1 }, { "LDY_X", {0x1AEE}, &LDY_X, 1 }, { "LDY_Y", {0x18EE}, &LDY_Y, 1 }, 
	{ "LSL_E", {0x78}, &LSL_E, 1 }, { "LSL_X", {0x68}, &LSL_X, 1 }, { "LSL_Y", {0x1868}, &LSL_Y, 1 }, 
	{ "LSLA_I", {0x48}, &LSLA_I, 1 }, { "LSLB_I", {0x58}, &LSLB_I, 1 }, { "LSLD_I", {0x05}, &LSLD_I, 1 }, 
	{ "LSR_E", {0x74}, &LSR_E, 1 }, { "LSR_X", {0x64}, &LSR_X, 1 }, { "LSR_Y", {0x1864}, &LSR_Y, 1 }, 
	{ "LSRA_I", {0x44}, &LSRA_I, 1 }, { "LSRB_I", {0x54}, &LSRB_I, 1 }, { "LSRD_I", {0x04}, &LSRD_I, 1 }, 
	{ "MUL_I", {0x3D}, &MUL_I, 1 }, { "NEG_E", {0x70}, &NEG_E, 1 }, { "NEG_X", {0x60}, &NEG_X, 1 }, 
	{ "NEG_Y", {0x1860}, &NEG_Y, 1 }, { "NEGA_I", {0x40}, &NEGA_I, 1 }, { "NEGB_I", {0x50}, &NEGB_I, 1 }, 
	{ "NOP_I", {0x01}, &NOP_I, 1 }, { "ORAA_M", {0x8A}, &ORAA_M, 1 }, { "ORAA_D", {0x9A}, &ORAA_D, 1 }, 
	{ "ORAA_E", {0xBA}, &ORAA_E, 1 }, { "ORAA_X", {0xAA}, &ORAA_X, 1 }, { "ORAA_Y", {0x18AA}, &ORAA_Y, 1 }, 
	{ "ORAB_M", {0xCA}, &ORAB_M, 1 }, { "ORAB_D", {0xDA}, &ORAB_D, 1 }, { "ORAB_E", {0xFA}, &ORAB_E, 1 }, 
	{ "ORAB_X", {0xEA}, &ORAB_X, 1 }, { "ORAB_Y", {0x18EA}, &ORAB_Y, 1 }, { "PSHA_I", {0x36}, &PSHA_I, 1 }, 
	{ "PSHB_I", {0x37}, &PSHB_I, 1 }, { "PSHX_I", {0x3C}, &PSHX_I, 1 }, { "PSHY_I", {0x183C}, &PSHY_I, 1 }, 
	{ "PULA_I", {0x32}, &PULA_I, 1 }, { "PULB_I", {0x33}, &PULB_I, 1 }, { "PULX_I", {0x38}, &PULX_I, 1 }, 
	{ "PULY_I", {0x1838}, &PULY_I, 1 }, { "ROL_E", {0x79}, &ROL_E, 1 }, { "ROL_X", {0x69}, &ROL_X, 1 }, 
	{ "ROL_Y", {0x1869}, &ROL_Y, 1 }, { "ROLA_I", {0x49}, &ROLA_I, 1 }, { "ROLB_I", {0x59}, &ROLB_I, 1 }, 
	{ "ROR_E", {0x76}, &ROR_E, 1 }, { "ROR_X", {0x66}, &ROR_X, 1 }, { "ROR_Y", {0x1866}, &ROR_Y, 1 }, 
	{ "RORA_I", {0x46}, &RORA_I, 1 }, { "RORB_I", {0x56}, &RORB_I, 1 }, { "RTI_I", {0x3B}, &RTI_I, 1 }, 
	{ "RTS_I", {0x39}, &RTS_I, 1 }, { "SBA_I", {0x10}, &SBA_I, 1 }, { "SBCA_M", {0x82}, &SBCA_M, 1 }, 
	{ "SBCA_D", {0x92}, &SBCA_D, 1 }, { "SBCA_E", {0xB2}, &SBCA_E, 1 }, { "SBCA_X", {0xA2}, &SBCA_X, 1 }, 
	{ "SBCA_Y", {0x18A2}, &SBCA_Y, 1 }, { "SBCB_M", {0xC2}, &SBCB_M, 1 }, { "SBCB_D", {0xD2}, &SBCB_D, 1 }, 
	{ "SBCB_E", {0xF2}, &SBCB_E, 1 }, { "SBCB_X", {0xE2}, &SBCB_X, 1 }, { "SBCB_Y", {0x18E2}, &SBCB_Y, 1 }, 
	{ "SEC_I", {0x0D}, &SEC_I, 1 }, { "SEI_I", {0x0F}, &SEI_I, 1 }, { "SEV_I", {0x0B}, &SEV_I, 1 }, 
	{ "STAA_D", {0x97}, &STAA_D, 1 }, { "STAA_E", {0xB7}, &STAA_E, 1 }, { "STAA_X", {0xA7}, &STAA_X, 1 }, 
	{ "STAA_Y", {0x18A7}, &STAA_Y, 1 }, { "STAB_D", {0xD7}, &STAB_D, 1 }, { "STAB_E", {0xF7}, &STAB_E, 1 }, 
	{ "STAB_X", {0xE7}, &STAB_X, 1 }, { "STAB_Y", {0x18E7}, &STAB_Y, 1 }, { "STD_D", {0xDD}, &STD_D, 1 }, 
	{ "STD_E", {0xFD}, &STD_E, 1 }, { "STD_X", {0xED}, &STD_X, 1 }, { "STD_Y", {0x18ED}, &STD_Y, 1 }, 
	{ "STOP_I", {0xCF}, &STOP_I, 1 }, { "STS_D", {0x9F}, &STS_D, 1 }, { "STS_E", {0xBF}, &STS_E, 1 }, 
	{ "STS_X", {0xAF}, &STS_X, 1 }, { "STS_Y", {0x18AF}, &STS_Y, 1 }, { "STX_D", {0xDF}, &STX_D, 1 }, 
	{ "STX_E", {0xFF}, &STX_E, 1 }, { "STX_X", {0xEF}, &STX_X, 1 }, { "STX_Y", {0xCDEF}, &STX_Y, 1 }, 
	{ "STY_D", {0x18DF}, &STY_D, 1 }, { "STY_E", {0x18FF}, &STY_E, 1 }, { "STY_X", {0x1AEF}, &STY_X, 1 }, 
	{ "STY_Y", {0x18EF}, &STY_Y, 1 }, { "SUBA_M", {0x80}, &SUBA_M, 1 }, { "SUBA_D", {0x90}, &SUBA_D, 1 }, 
	{ "SUBA_E", {0xB0}, &SUBA_E, 1 }, { "SUBA_X", {0xA0}, &SUBA_X, 1 }, { "SUBA_Y", {0x18A0}, &SUBA_Y, 1 }, 
	{ "SUBB_M", {0xC0}, &SUBB_M, 1 }, { "SUBB_D", {0xD0}, &SUBB_D, 1 }, { "SUBB_E", {0xF0}, &SUBB_E, 1 }, 
	{ "SUBB_X", {0xE0}, &SUBB_X, 1 }, { "SUBB_Y", {0x18E0}, &SUBB_Y, 1 }, { "SUBD_M", {0x83}, &SUBD_M, 1 }, 
	{ "SUBD_D", {0x93}, &SUBD_D, 1 }, { "SUBD_3", {0xB3}, &SUBD_3, 1 }, { "SUBD_X", {0xA3}, &SUBD_X, 1 }, 
	{ "SUBD_Y", {0x18A3}, &SUBD_Y, 1 }, { "SWI_I", {0x3F}, &SWI_I, 1 }, { "TAB_I", {0x16}, &TAB_I, 1 }, 
	{ "TAP_I", {0x06}, &TAP_I, 1 }, { "TBA_I", {0x17}, &TBA_I, 1 }, { "TEST_I", {0x00}, &TEST_I, 1 }, 
	{ "TPA_I", {0x07}, &TPA_I, 1 }, { "TST_E", {0x7D}, &TST_E, 1 }, { "TST_X", {0x6D}, &TST_X, 1 }, 
	{ "TST_Y", {0x186D}, &TST_Y, 1 }, { "TSTA_I", {0x4D}, &TSTA_I, 1 }, { "TSTB_I", {0x5D}, &TSTB_I, 1 }, 
	{ "TSX_I", {0x30}, &TSX_I, 1 }, { "TSY_Y", {0x1830}, &TSY_Y, 1 }, { "TXS_I", {0x35}, &TXS_I, 1 }, 
	{ "TYS_I", {0x1835}, &TYS_I, 1 }, { "WAI_I", {0x3E}, &WAI_I, 1 }, { "XGDX_I", {0x8F}, &XGDX_I, 1 }, 
	{ "XGDY_I", {0x188F}, &XGDY_I, 1 }, 
};

static tree_level_t *root;

void init_inst(void)
{
	root = make_tree(lookup, 316);
}

void exec_inst(hc11_t *hc11)
{
	if(root == NULL)
	{
		printf("Search tree not made yet!\n");
		exit(1);
	}
	inst_t *instruction = search_tree(hc11, root);
	// printf("Executing %04X, PC = %04X\n", instruction->opcode, hc11->pc);
	(instruction->op)(hc11);
}

/* Individual functions */

void ABA_I(hc11_t *hc11)	// 1B
{

}

void ABX_I(hc11_t *hc11)	// 3A
{

}

void ABY_I(hc11_t *hc11)	// 183A
{

}

void ADCA_M(hc11_t *hc11)	// 89
{

}

void ADCA_D(hc11_t *hc11)	// 99
{

}

void ADCA_E(hc11_t *hc11)	// B9
{

}

void ADCA_X(hc11_t *hc11)	// A9
{

}

void ADCA_Y(hc11_t *hc11)	// 18A9
{

}

void ADCB_M(hc11_t *hc11)	// C9
{

}

void ADCB_D(hc11_t *hc11)	// D9
{

}

void ADCB_E(hc11_t *hc11)	// F9
{

}

void ADCB_X(hc11_t *hc11)	// E9
{

}

void ADCB_Y(hc11_t *hc11)	// 18E9
{

}

void ADDA_M(hc11_t *hc11)	// 8B
{

}

void ADDA_D(hc11_t *hc11)	// 9B
{

}

void ADDA_E(hc11_t *hc11)	// BB
{

}

void ADDA_X(hc11_t *hc11)	// AB
{

}

void ADDA_Y(hc11_t *hc11)	// 18AB
{

}

void ADDB_M(hc11_t *hc11)	// CB
{

}

void ADDB_D(hc11_t *hc11)	// DB
{

}

void ADDB_E(hc11_t *hc11)	// FB
{

}

void ADDB_X(hc11_t *hc11)	// EB
{

}

void ADDB_Y(hc11_t *hc11)	// 18EB
{

}

void ADDD_M(hc11_t *hc11)	// C3
{

}

void ADDD_D(hc11_t *hc11)	// D3
{

}

void ADDD_E(hc11_t *hc11)	// F3
{

}

void ADDD_X(hc11_t *hc11)	// E3
{

}

void ADDD_Y(hc11_t *hc11)	// 18E3
{

}

void ANDA_M(hc11_t *hc11)	// 84
{

}

void ANDA_D(hc11_t *hc11)	// 94
{

}

void ANDA_E(hc11_t *hc11)	// B4
{

}

void ANDA_X(hc11_t *hc11)	// A4
{

}

void ANDA_Y(hc11_t *hc11)	// 18A4
{

}

void ANDB_M(hc11_t *hc11)	// C4
{

}

void ANDB_D(hc11_t *hc11)	// D4
{

}

void ANDB_E(hc11_t *hc11)	// F4
{

}

void ANDB_X(hc11_t *hc11)	// E4
{

}

void ANDB_Y(hc11_t *hc11)	// 18E4
{

}

void ASL_E(hc11_t *hc11)	// 78
{

}

void ASL_X(hc11_t *hc11)	// 68
{

}

void ASL_Y(hc11_t *hc11)	// 1868
{

}

void ASLA_I(hc11_t *hc11)	// 48
{

}

void ASLB_I(hc11_t *hc11)	// 58
{

}

void ASLD_I(hc11_t *hc11)	// 05
{

}

void ASR_E(hc11_t *hc11)	// 77
{

}

void ASR_X(hc11_t *hc11)	// 67
{

}

void ASR_Y(hc11_t *hc11)	// 1867
{

}

void ASRA_I(hc11_t *hc11)	// 47
{

}

void ASRB_I(hc11_t *hc11)	// 57
{

}

void BCC_R(hc11_t *hc11)	// 24
{

}

void BCLR_D(hc11_t *hc11)	// 15
{

}

void BCLR_X(hc11_t *hc11)	// 1D
{

}

void BCLR_Y(hc11_t *hc11)	// 181D
{

}

void BCS_R(hc11_t *hc11)	// 25
{

}

void BEQ_R(hc11_t *hc11)	// 27
{

}

void BGE_R(hc11_t *hc11)	// 2C
{

}

void BGT_R(hc11_t *hc11)	// 2E
{

}

void BHI_R(hc11_t *hc11)	// 22
{

}

void BHS_R(hc11_t *hc11)	// 24
{

}

void BITA_M(hc11_t *hc11)	// 85
{

}

void BITA_D(hc11_t *hc11)	// 95
{

}

void BITA_E(hc11_t *hc11)	// B5
{

}

void BITA_X(hc11_t *hc11)	// A5
{

}

void BITA_Y(hc11_t *hc11)	// 18A5
{

}

void BITB_M(hc11_t *hc11)	// C5
{

}

void BITB_D(hc11_t *hc11)	// D5
{

}

void BITB_E(hc11_t *hc11)	// F5
{

}

void BITB_X(hc11_t *hc11)	// E5
{

}

void BITB_Y(hc11_t *hc11)	// 18E3
{

}

void BLE_R(hc11_t *hc11)	// 2F
{

}

void BLO_R(hc11_t *hc11)	// 25
{

}

void BLS_R(hc11_t *hc11)	// 23
{

}

void BLT_R(hc11_t *hc11)	// 2D
{

}

void BMI_R(hc11_t *hc11)	// 2B
{

}

void BNE_R(hc11_t *hc11)	// 26
{

}

void BPL_R(hc11_t *hc11)	// 2A
{

}

void BRA_R(hc11_t *hc11)	// 20
{

}

void BRCLR_D(hc11_t *hc11)	// 13
{

}

void BRCLR_X(hc11_t *hc11)	// 1F
{

}

void BRCLR_Y(hc11_t *hc11)	// 181F
{

}

void BRN_R(hc11_t *hc11)	// 21
{

}

void BRSET_D(hc11_t *hc11)	// 12
{

}

void BRSET_X(hc11_t *hc11)	// 1E
{

}

void BRSET_Y(hc11_t *hc11)	// 181E
{

}

void BSET_D(hc11_t *hc11)	// 14
{

}

void BSET_X(hc11_t *hc11)	// 1C
{

}

void BSET_Y(hc11_t *hc11)	// 181C
{

}

void BSR_R(hc11_t *hc11)	// 8D
{

}

void BVC_R(hc11_t *hc11)	// 28
{

}

void BVS_R(hc11_t *hc11)	// 29
{

}

void CBA_I(hc11_t *hc11)	// 11
{

}

void CLC_I(hc11_t *hc11)	// 0C
{

}

void CLI_I(hc11_t *hc11)	// 0E
{

}

void CLR_E(hc11_t *hc11)	// 7F
{

}

void CLR_X(hc11_t *hc11)	// 6F
{

}

void CLR_Y(hc11_t *hc11)	// 186F
{

}

void CLRA_I(hc11_t *hc11)	// 4F
{

}

void CLRB_I(hc11_t *hc11)	// 5F
{

}

void CLV_I(hc11_t *hc11)	// 0A
{

}

void CMPA_M(hc11_t *hc11)	// 81
{

}

void CMPA_D(hc11_t *hc11)	// 91
{

}

void CMPA_E(hc11_t *hc11)	// B1
{

}

void CMPA_X(hc11_t *hc11)	// A1
{

}

void CMPA_Y(hc11_t *hc11)	// 18A1
{

}

void CMPB_M(hc11_t *hc11)	// C1
{

}

void CMPB_D(hc11_t *hc11)	// D1
{

}

void CMPB_E(hc11_t *hc11)	// F1
{

}

void CMPB_X(hc11_t *hc11)	// E1
{

}

void CMPB_Y(hc11_t *hc11)	// 18E1
{

}

void COM_E(hc11_t *hc11)	// 73
{

}

void COM_X(hc11_t *hc11)	// 63
{

}

void COM_Y(hc11_t *hc11)	// 1863
{

}

void COMA_I(hc11_t *hc11)	// 43
{

}

void COMB_I(hc11_t *hc11)	// 53
{

}

void CPD_M(hc11_t *hc11)	// 1A83
{

}

void CPD_D(hc11_t *hc11)	// 1A93
{

}

void CPD_E(hc11_t *hc11)	// 1AB3
{

}

void CPD_X(hc11_t *hc11)	// 1AA3
{

}

void CPD_Y(hc11_t *hc11)	// CDA3
{

}

void CPX_M(hc11_t *hc11)	// 8C
{

}

void CPX_D(hc11_t *hc11)	// 9C
{

}

void CPX_E(hc11_t *hc11)	// BC
{

}

void CPX_X(hc11_t *hc11)	// AC
{

}

void CPX_Y(hc11_t *hc11)	// CDAC
{

}

void CPY_M(hc11_t *hc11)	// 188C
{

}

void CPY_D(hc11_t *hc11)	// 189C
{

}

void CPY_E(hc11_t *hc11)	// 18BC
{

}

void CPY_X(hc11_t *hc11)	// 1AAC
{

}

void CPY_Y(hc11_t *hc11)	// 18AC
{

}

void DAA_I(hc11_t *hc11)	// 19
{

}

void DEC_E(hc11_t *hc11)	// 7A
{

}

void DEC_X(hc11_t *hc11)	// 6A
{

}

void DEC_Y(hc11_t *hc11)	// 186A
{

}

void DECA_I(hc11_t *hc11)	// 4A
{

}

void DECB_I(hc11_t *hc11)	// 5A
{

}

void DES_I(hc11_t *hc11)	// 34
{

}

void DEX_I(hc11_t *hc11)	// 09
{

}

void DEY_I(hc11_t *hc11)	// 1809
{

}

void EORA_M(hc11_t *hc11)	// 88
{

}

void EORA_D(hc11_t *hc11)	// 98
{

}

void EORA_E(hc11_t *hc11)	// B8
{

}

void EORA_X(hc11_t *hc11)	// A8
{

}

void EORA_Y(hc11_t *hc11)	// 18A8
{

}

void EORB_M(hc11_t *hc11)	// C8
{

}

void EORB_D(hc11_t *hc11)	// D8
{

}

void EORB_E(hc11_t *hc11)	// F8
{

}

void EORB_X(hc11_t *hc11)	// E8
{

}

void EORB_Y(hc11_t *hc11)	// 18E8
{

}

void FDIV_I(hc11_t *hc11)	// 03
{

}

void IDIV_I(hc11_t *hc11)	// 02
{

}

void INC_E(hc11_t *hc11)	// 7C
{

}

void INC_X(hc11_t *hc11)	// 6C
{

}

void INC_Y(hc11_t *hc11)	// 186C
{

}

void INCA_I(hc11_t *hc11)	// 4C
{

}

void INCB_I(hc11_t *hc11)	// 5C
{

}

void INS_I(hc11_t *hc11)	// 31
{

}

void INX_I(hc11_t *hc11)	// 08
{

}

void INY_I(hc11_t *hc11)	// 1808
{

}

void JMP_E(hc11_t *hc11)	// 7E
{

}

void JMP_X(hc11_t *hc11)	// 63
{

}

void JMP_Y(hc11_t *hc11)	// 186E
{

}

void JSR_D(hc11_t *hc11)	// 9D
{

}

void JSR_E(hc11_t *hc11)	// BD
{

}

void JSR_X(hc11_t *hc11)	// AD
{

}

void JSR_Y(hc11_t *hc11)	// 18AD
{

}

void LDAA_M(hc11_t *hc11)	// 86
{

}

void LDAA_D(hc11_t *hc11)	// 96
{

}

void LDAA_E(hc11_t *hc11)	// B6
{

}

void LDAA_X(hc11_t *hc11)	// A6
{

}

void LDAA_Y(hc11_t *hc11)	// 18A6
{

}

void LDAB_M(hc11_t *hc11)	// C6
{

}

void LDAB_D(hc11_t *hc11)	// D6
{

}

void LDAB_E(hc11_t *hc11)	// B6
{

}

void LDAB_X(hc11_t *hc11)	// E6
{

}

void LDAB_Y(hc11_t *hc11)	// 18E6
{

}

void LDD_M(hc11_t *hc11)	// CC
{

}

void LDD_D(hc11_t *hc11)	// DC
{

}

void LDD_E(hc11_t *hc11)	// FC
{

}

void LDD_X(hc11_t *hc11)	// EC
{

}

void LDD_Y(hc11_t *hc11)	// 18EC
{

}

void LDS_M(hc11_t *hc11)	// 8E
{

}

void LDS_D(hc11_t *hc11)	// 9E
{

}

void LDS_E(hc11_t *hc11)	// BE
{

}

void LDS_X(hc11_t *hc11)	// AE
{

}

void LDS_Y(hc11_t *hc11)	// 18AE
{

}

void LDX_M(hc11_t *hc11)	// CE
{

}

void LDX_D(hc11_t *hc11)	// DE
{

}

void LDX_E(hc11_t *hc11)	// FE
{

}

void LDX_X(hc11_t *hc11)	// EE
{

}

void LDX_Y(hc11_t *hc11)	// CDEE
{

}

void LDY_M(hc11_t *hc11)	// 18CE
{

}

void LDY_D(hc11_t *hc11)	// 18DE
{

}

void LDY_E(hc11_t *hc11)	// 18FE
{

}

void LDY_X(hc11_t *hc11)	// 1AEE
{

}

void LDY_Y(hc11_t *hc11)	// 18EE
{

}

void LSL_E(hc11_t *hc11)	// 78
{

}

void LSL_X(hc11_t *hc11)	// 68
{

}

void LSL_Y(hc11_t *hc11)	// 1868
{

}

void LSLA_I(hc11_t *hc11)	// 48
{

}

void LSLB_I(hc11_t *hc11)	// 58
{

}

void LSLD_I(hc11_t *hc11)	// 05
{

}

void LSR_E(hc11_t *hc11)	// 74
{

}

void LSR_X(hc11_t *hc11)	// 64
{

}

void LSR_Y(hc11_t *hc11)	// 1864
{

}

void LSRA_I(hc11_t *hc11)	// 44
{

}

void LSRB_I(hc11_t *hc11)	// 54
{

}

void LSRD_I(hc11_t *hc11)	// 04
{

}

void MUL_I(hc11_t *hc11)	// 3D
{

}

void NEG_E(hc11_t *hc11)	// 70
{

}

void NEG_X(hc11_t *hc11)	// 60
{

}

void NEG_Y(hc11_t *hc11)	// 1860
{

}

void NEGA_I(hc11_t *hc11)	// 40
{

}

void NEGB_I(hc11_t *hc11)	// 50
{

}

void NOP_I(hc11_t *hc11)	// 01
{

}

void ORAA_M(hc11_t *hc11)	// 8A
{

}

void ORAA_D(hc11_t *hc11)	// 9A
{

}

void ORAA_E(hc11_t *hc11)	// BA
{

}

void ORAA_X(hc11_t *hc11)	// AA
{

}

void ORAA_Y(hc11_t *hc11)	// 18AA
{

}

void ORAB_M(hc11_t *hc11)	// CA
{

}

void ORAB_D(hc11_t *hc11)	// DA
{

}

void ORAB_E(hc11_t *hc11)	// FA
{

}

void ORAB_X(hc11_t *hc11)	// EA
{

}

void ORAB_Y(hc11_t *hc11)	// 18EA
{

}

void PSHA_I(hc11_t *hc11)	// 36
{

}

void PSHB_I(hc11_t *hc11)	// 37
{

}

void PSHX_I(hc11_t *hc11)	// 3C
{

}

void PSHY_I(hc11_t *hc11)	// 183C
{

}

void PULA_I(hc11_t *hc11)	// 32
{

}

void PULB_I(hc11_t *hc11)	// 33
{

}

void PULX_I(hc11_t *hc11)	// 38
{

}

void PULY_I(hc11_t *hc11)	// 1838
{

}

void ROL_E(hc11_t *hc11)	// 79
{

}

void ROL_X(hc11_t *hc11)	// 69
{

}

void ROL_Y(hc11_t *hc11)	// 1869
{

}

void ROLA_I(hc11_t *hc11)	// 49
{

}

void ROLB_I(hc11_t *hc11)	// 59
{

}

void ROR_E(hc11_t *hc11)	// 76
{

}

void ROR_X(hc11_t *hc11)	// 66
{

}

void ROR_Y(hc11_t *hc11)	// 1866
{

}

void RORA_I(hc11_t *hc11)	// 46
{

}

void RORB_I(hc11_t *hc11)	// 56
{

}

void RTI_I(hc11_t *hc11)	// 3B
{

}

void RTS_I(hc11_t *hc11)	// 39
{

}

void SBA_I(hc11_t *hc11)	// 10
{

}

void SBCA_M(hc11_t *hc11)	// 82
{

}

void SBCA_D(hc11_t *hc11)	// 92
{

}

void SBCA_E(hc11_t *hc11)	// B2
{

}

void SBCA_X(hc11_t *hc11)	// A2
{

}

void SBCA_Y(hc11_t *hc11)	// 18A2
{

}

void SBCB_M(hc11_t *hc11)	// C2
{

}

void SBCB_D(hc11_t *hc11)	// D2
{

}

void SBCB_E(hc11_t *hc11)	// F2
{

}

void SBCB_X(hc11_t *hc11)	// E2
{

}

void SBCB_Y(hc11_t *hc11)	// 18E2
{

}

void SEC_I(hc11_t *hc11)	// 0D
{

}

void SEI_I(hc11_t *hc11)	// 0F
{

}

void SEV_I(hc11_t *hc11)	// 0B
{

}

void STAA_D(hc11_t *hc11)	// 97
{

}

void STAA_E(hc11_t *hc11)	// B7
{

}

void STAA_X(hc11_t *hc11)	// A7
{

}

void STAA_Y(hc11_t *hc11)	// 18A7
{

}

void STAB_D(hc11_t *hc11)	// D7
{

}

void STAB_E(hc11_t *hc11)	// F7
{

}

void STAB_X(hc11_t *hc11)	// E7
{

}

void STAB_Y(hc11_t *hc11)	// 18E7
{

}

void STD_D(hc11_t *hc11)	// DD
{

}

void STD_E(hc11_t *hc11)	// FD
{

}

void STD_X(hc11_t *hc11)	// ED
{

}

void STD_Y(hc11_t *hc11)	// 18ED
{

}

void STOP_I(hc11_t *hc11)	// CF
{

}

void STS_D(hc11_t *hc11)	// 9F
{

}

void STS_E(hc11_t *hc11)	// BF
{

}

void STS_X(hc11_t *hc11)	// AF
{

}

void STS_Y(hc11_t *hc11)	// 18AF
{

}

void STX_D(hc11_t *hc11)	// DF
{

}

void STX_E(hc11_t *hc11)	// FF
{

}

void STX_X(hc11_t *hc11)	// EF
{

}

void STX_Y(hc11_t *hc11)	// CDEF
{

}

void STY_D(hc11_t *hc11)	// 18DF
{

}

void STY_E(hc11_t *hc11)	// 18FF
{

}

void STY_X(hc11_t *hc11)	// 1AEF
{

}

void STY_Y(hc11_t *hc11)	// 18EF
{

}

void SUBA_M(hc11_t *hc11)	// 80
{

}

void SUBA_D(hc11_t *hc11)	// 90
{

}

void SUBA_E(hc11_t *hc11)	// B0
{

}

void SUBA_X(hc11_t *hc11)	// A0
{

}

void SUBA_Y(hc11_t *hc11)	// 18A0
{

}

void SUBB_M(hc11_t *hc11)	// C0
{

}

void SUBB_D(hc11_t *hc11)	// D0
{

}

void SUBB_E(hc11_t *hc11)	// F0
{

}

void SUBB_X(hc11_t *hc11)	// E0
{

}

void SUBB_Y(hc11_t *hc11)	// 18E0
{

}

void SUBD_M(hc11_t *hc11)	// 83
{

}

void SUBD_D(hc11_t *hc11)	// 93
{

}

void SUBD_3(hc11_t *hc11)	// B3
{

}

void SUBD_X(hc11_t *hc11)	// A3
{

}

void SUBD_Y(hc11_t *hc11)	// 18A3
{

}

void SWI_I(hc11_t *hc11)	// 3F
{

}

void TAB_I(hc11_t *hc11)	// 16
{

}

void TAP_I(hc11_t *hc11)	// 06
{

}

void TBA_I(hc11_t *hc11)	// 17
{

}

void TEST_I(hc11_t *hc11)	// 00
{

}

void TPA_I(hc11_t *hc11)	// 07
{

}

void TST_E(hc11_t *hc11)	// 7D
{

}

void TST_X(hc11_t *hc11)	// 6D
{

}

void TST_Y(hc11_t *hc11)	// 186D
{

}

void TSTA_I(hc11_t *hc11)	// 4D
{

}

void TSTB_I(hc11_t *hc11)	// 5D
{

}

void TSX_I(hc11_t *hc11)	// 30
{

}

void TSY_Y(hc11_t *hc11)	// 1830
{

}

void TXS_I(hc11_t *hc11)	// 35
{

}

void TYS_I(hc11_t *hc11)	// 1835
{

}

void WAI_I(hc11_t *hc11)	// 3E
{

}

void XGDX_I(hc11_t *hc11)	// 8F
{

}

void XGDY_I(hc11_t *hc11)	// 188F
{

}