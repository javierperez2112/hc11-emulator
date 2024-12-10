#include "hc11.h"
#include "hc11_inst.h"
#include "hc11_search.h"
#include <stdlib.h>

#define _DEBUG

#pragma region DECLARATIONS

/* Dirmode declarations */

arg_t DIR_I(hc11_t*, size_t);	// Inherent
arg_t DIR_M(hc11_t*, size_t);	// Immediate
arg_t DIR_E(hc11_t*, size_t);	// Extended
arg_t DIR_D(hc11_t*, size_t);	// Direct
arg_t DIR_X(hc11_t*, size_t);	// Index X
arg_t DIR_Y(hc11_t*, size_t);	// Index Y
arg_t DIR_R(hc11_t*, size_t);	// Relative

/* Function declarations */

void ABA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ABX(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ABY(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ADCA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ADCB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ADDA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ADDB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ADDD(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ANDA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ANDB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ASL(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ASLA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ASLB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ASLD(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ASR(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ASRA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ASRB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BCC(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BCLR(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BCS(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BEQ(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BGE(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BGT(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BHI(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BHS(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BITA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BITB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BLE(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BLO(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BLS(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BLT(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BMI(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BNE(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BPL(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BRA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BRCLR(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BRN(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BRSET(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BSET(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BSR(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BVC(hc11_t*, arg_t (*)(hc11_t*, size_t));
void BVS(hc11_t*, arg_t (*)(hc11_t*, size_t));
void CBA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void CLC(hc11_t*, arg_t (*)(hc11_t*, size_t));
void CLI(hc11_t*, arg_t (*)(hc11_t*, size_t));
void CLR(hc11_t*, arg_t (*)(hc11_t*, size_t));
void CLRA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void CLRB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void CLV(hc11_t*, arg_t (*)(hc11_t*, size_t));
void CMPA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void CMPB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void COM(hc11_t*, arg_t (*)(hc11_t*, size_t));
void COMA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void COMB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void CPD(hc11_t*, arg_t (*)(hc11_t*, size_t));
void CPX(hc11_t*, arg_t (*)(hc11_t*, size_t));
void CPY(hc11_t*, arg_t (*)(hc11_t*, size_t));
void DAA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void DEC(hc11_t*, arg_t (*)(hc11_t*, size_t));
void DECA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void DECB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void DES(hc11_t*, arg_t (*)(hc11_t*, size_t));
void DEX(hc11_t*, arg_t (*)(hc11_t*, size_t));
void DEY(hc11_t*, arg_t (*)(hc11_t*, size_t));
void EORA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void EORB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void FDIV(hc11_t*, arg_t (*)(hc11_t*, size_t));
void IDIV(hc11_t*, arg_t (*)(hc11_t*, size_t));
void INC(hc11_t*, arg_t (*)(hc11_t*, size_t));
void INCA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void INCB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void INS(hc11_t*, arg_t (*)(hc11_t*, size_t));
void INX(hc11_t*, arg_t (*)(hc11_t*, size_t));
void INY(hc11_t*, arg_t (*)(hc11_t*, size_t));
void JMP(hc11_t*, arg_t (*)(hc11_t*, size_t));
void JSR(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LDAA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LDAB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LDD(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LDS(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LDX(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LDY(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LSL(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LSLA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LSLB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LSLD(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LSR(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LSRA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LSRB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void LSRD(hc11_t*, arg_t (*)(hc11_t*, size_t));
void MUL(hc11_t*, arg_t (*)(hc11_t*, size_t));
void NEG(hc11_t*, arg_t (*)(hc11_t*, size_t));
void NEGA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void NEGB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void NOP(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ORAA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ORAB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void PSHA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void PSHB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void PSHX(hc11_t*, arg_t (*)(hc11_t*, size_t));
void PSHY(hc11_t*, arg_t (*)(hc11_t*, size_t));
void PULA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void PULB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void PULX(hc11_t*, arg_t (*)(hc11_t*, size_t));
void PULY(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ROL(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ROLA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ROLB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void ROR(hc11_t*, arg_t (*)(hc11_t*, size_t));
void RORA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void RORB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void RTI(hc11_t*, arg_t (*)(hc11_t*, size_t));
void RTS(hc11_t*, arg_t (*)(hc11_t*, size_t));
void SBA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void SBCA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void SBCB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void SEC(hc11_t*, arg_t (*)(hc11_t*, size_t));
void SEI(hc11_t*, arg_t (*)(hc11_t*, size_t));
void SEV(hc11_t*, arg_t (*)(hc11_t*, size_t));
void STAA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void STAB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void STD(hc11_t*, arg_t (*)(hc11_t*, size_t));
void STOP(hc11_t*, arg_t (*)(hc11_t*, size_t));
void STS(hc11_t*, arg_t (*)(hc11_t*, size_t));
void STX(hc11_t*, arg_t (*)(hc11_t*, size_t));
void STY(hc11_t*, arg_t (*)(hc11_t*, size_t));
void SUBA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void SUBB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void SUBD(hc11_t*, arg_t (*)(hc11_t*, size_t));
void SWI(hc11_t*, arg_t (*)(hc11_t*, size_t));
void TAB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void TAP(hc11_t*, arg_t (*)(hc11_t*, size_t));
void TBA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void TEST(hc11_t*, arg_t (*)(hc11_t*, size_t));
void TPA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void TST(hc11_t*, arg_t (*)(hc11_t*, size_t));
void TSTA(hc11_t*, arg_t (*)(hc11_t*, size_t));
void TSTB(hc11_t*, arg_t (*)(hc11_t*, size_t));
void TSX(hc11_t*, arg_t (*)(hc11_t*, size_t));
void TSY(hc11_t*, arg_t (*)(hc11_t*, size_t));
void TXS(hc11_t*, arg_t (*)(hc11_t*, size_t));
void TYS(hc11_t*, arg_t (*)(hc11_t*, size_t));
void WAI(hc11_t*, arg_t (*)(hc11_t*, size_t));
void XGDX(hc11_t*, arg_t (*)(hc11_t*, size_t));
void XGDY(hc11_t*, arg_t (*)(hc11_t*, size_t));

#pragma endregion DECLARATIONS

#pragma region LOOKUP

inst_t lookup[316] = {		// Gracias Python por existir :p

	{ "ABA", {0x1B}, &ABA, &DIR_I, 1 }, { "ABX", {0x3A}, &ABX, &DIR_I, 1 }, { "ABY", {0x183A}, &ABY, &DIR_I, 1 }, 
	{ "ADCA", {0x89}, &ADCA, &DIR_M, 1 }, { "ADCA", {0x99}, &ADCA, &DIR_D, 1 }, { "ADCA", {0xB9}, &ADCA, &DIR_E, 1 }, 
	{ "ADCA", {0xA9}, &ADCA, &DIR_X, 1 }, { "ADCA", {0x18A9}, &ADCA, &DIR_Y, 1 }, { "ADCB", {0xC9}, &ADCB, &DIR_M, 1 }, 
	{ "ADCB", {0xD9}, &ADCB, &DIR_D, 1 }, { "ADCB", {0xF9}, &ADCB, &DIR_E, 1 }, { "ADCB", {0xE9}, &ADCB, &DIR_X, 1 }, 
	{ "ADCB", {0x18E9}, &ADCB, &DIR_Y, 1 }, { "ADDA", {0x8B}, &ADDA, &DIR_M, 1 }, { "ADDA", {0x9B}, &ADDA, &DIR_D, 1 }, 
	{ "ADDA", {0xBB}, &ADDA, &DIR_E, 1 }, { "ADDA", {0xAB}, &ADDA, &DIR_X, 1 }, { "ADDA", {0x18AB}, &ADDA, &DIR_Y, 1 }, 
	{ "ADDB", {0xCB}, &ADDB, &DIR_M, 1 }, { "ADDB", {0xDB}, &ADDB, &DIR_D, 1 }, { "ADDB", {0xFB}, &ADDB, &DIR_E, 1 }, 
	{ "ADDB", {0xEB}, &ADDB, &DIR_X, 1 }, { "ADDB", {0x18EB}, &ADDB, &DIR_Y, 1 }, { "ADDD", {0xC3}, &ADDD, &DIR_M, 1 }, 
	{ "ADDD", {0xD3}, &ADDD, &DIR_D, 1 }, { "ADDD", {0xF3}, &ADDD, &DIR_E, 1 }, { "ADDD", {0xE3}, &ADDD, &DIR_X, 1 }, 
	{ "ADDD", {0x18E3}, &ADDD, &DIR_Y, 1 }, { "ANDA", {0x84}, &ANDA, &DIR_M, 1 }, { "ANDA", {0x94}, &ANDA, &DIR_D, 1 }, 
	{ "ANDA", {0xB4}, &ANDA, &DIR_E, 1 }, { "ANDA", {0xA4}, &ANDA, &DIR_X, 1 }, { "ANDA", {0x18A4}, &ANDA, &DIR_Y, 1 }, 
	{ "ANDB", {0xC4}, &ANDB, &DIR_M, 1 }, { "ANDB", {0xD4}, &ANDB, &DIR_D, 1 }, { "ANDB", {0xF4}, &ANDB, &DIR_E, 1 }, 
	{ "ANDB", {0xE4}, &ANDB, &DIR_X, 1 }, { "ANDB", {0x18E4}, &ANDB, &DIR_Y, 1 }, { "ASL", {0x78}, &ASL, &DIR_E, 1 }, 
	{ "ASL", {0x68}, &ASL, &DIR_X, 1 }, { "ASL", {0x1868}, &ASL, &DIR_Y, 1 }, { "ASLA", {0x48}, &ASLA, &DIR_I, 1 }, 
	{ "ASLB", {0x58}, &ASLB, &DIR_I, 1 }, { "ASLD", {0x05}, &ASLD, &DIR_I, 1 }, { "ASR", {0x77}, &ASR, &DIR_E, 1 }, 
	{ "ASR", {0x67}, &ASR, &DIR_X, 1 }, { "ASR", {0x1867}, &ASR, &DIR_Y, 1 }, { "ASRA", {0x47}, &ASRA, &DIR_I, 1 }, 
	{ "ASRB", {0x57}, &ASRB, &DIR_I, 1 }, { "BCC", {0x24}, &BCC, &DIR_R, 1 }, { "BCLR", {0x15}, &BCLR, &DIR_D, 1 }, 
	{ "BCLR", {0x1D}, &BCLR, &DIR_X, 1 }, { "BCLR", {0x181D}, &BCLR, &DIR_Y, 1 }, { "BCS", {0x25}, &BCS, &DIR_R, 1 }, 
	{ "BEQ", {0x27}, &BEQ, &DIR_R, 1 }, { "BGE", {0x2C}, &BGE, &DIR_R, 1 }, { "BGT", {0x2E}, &BGT, &DIR_R, 1 }, 
	{ "BHI", {0x22}, &BHI, &DIR_R, 1 }, { "BHS", {0x24}, &BHS, &DIR_R, 1 }, { "BITA", {0x85}, &BITA, &DIR_M, 1 }, 
	{ "BITA", {0x95}, &BITA, &DIR_D, 1 }, { "BITA", {0xB5}, &BITA, &DIR_E, 1 }, { "BITA", {0xA5}, &BITA, &DIR_X, 1 }, 
	{ "BITA", {0x18A5}, &BITA, &DIR_Y, 1 }, { "BITB", {0xC5}, &BITB, &DIR_M, 1 }, { "BITB", {0xD5}, &BITB, &DIR_D, 1 }, 
	{ "BITB", {0xF5}, &BITB, &DIR_E, 1 }, { "BITB", {0xE5}, &BITB, &DIR_X, 1 }, { "BITB", {0x18E3}, &BITB, &DIR_Y, 1 }, 
	{ "BLE", {0x2F}, &BLE, &DIR_R, 1 }, { "BLO", {0x25}, &BLO, &DIR_R, 1 }, { "BLS", {0x23}, &BLS, &DIR_R, 1 }, 
	{ "BLT", {0x2D}, &BLT, &DIR_R, 1 }, { "BMI", {0x2B}, &BMI, &DIR_R, 1 }, { "BNE", {0x26}, &BNE, &DIR_R, 1 }, 
	{ "BPL", {0x2A}, &BPL, &DIR_R, 1 }, { "BRA", {0x20}, &BRA, &DIR_R, 1 }, { "BRCLR", {0x13}, &BRCLR, &DIR_D, 1 }, 
	{ "BRCLR", {0x1F}, &BRCLR, &DIR_X, 1 }, { "BRCLR", {0x181F}, &BRCLR, &DIR_Y, 1 }, { "BRN", {0x21}, &BRN, &DIR_R, 1 }, 
	{ "BRSET", {0x12}, &BRSET, &DIR_D, 1 }, { "BRSET", {0x1E}, &BRSET, &DIR_X, 1 }, { "BRSET", {0x181E}, &BRSET, &DIR_Y, 1 }, 
	{ "BSET", {0x14}, &BSET, &DIR_D, 1 }, { "BSET", {0x1C}, &BSET, &DIR_X, 1 }, { "BSET", {0x181C}, &BSET, &DIR_Y, 1 }, 
	{ "BSR", {0x8D}, &BSR, &DIR_R, 1 }, { "BVC", {0x28}, &BVC, &DIR_R, 1 }, { "BVS", {0x29}, &BVS, &DIR_R, 1 }, 
	{ "CBA", {0x11}, &CBA, &DIR_I, 1 }, { "CLC", {0x0C}, &CLC, &DIR_I, 1 }, { "CLI", {0x0E}, &CLI, &DIR_I, 1 }, 
	{ "CLR", {0x7F}, &CLR, &DIR_E, 1 }, { "CLR", {0x6F}, &CLR, &DIR_X, 1 }, { "CLR", {0x186F}, &CLR, &DIR_Y, 1 }, 
	{ "CLRA", {0x4F}, &CLRA, &DIR_I, 1 }, { "CLRB", {0x5F}, &CLRB, &DIR_I, 1 }, { "CLV", {0x0A}, &CLV, &DIR_I, 1 }, 
	{ "CMPA", {0x81}, &CMPA, &DIR_M, 1 }, { "CMPA", {0x91}, &CMPA, &DIR_D, 1 }, { "CMPA", {0xB1}, &CMPA, &DIR_E, 1 }, 
	{ "CMPA", {0xA1}, &CMPA, &DIR_X, 1 }, { "CMPA", {0x18A1}, &CMPA, &DIR_Y, 1 }, { "CMPB", {0xC1}, &CMPB, &DIR_M, 1 }, 
	{ "CMPB", {0xD1}, &CMPB, &DIR_D, 1 }, { "CMPB", {0xF1}, &CMPB, &DIR_E, 1 }, { "CMPB", {0xE1}, &CMPB, &DIR_X, 1 }, 
	{ "CMPB", {0x18E1}, &CMPB, &DIR_Y, 1 }, { "COM", {0x73}, &COM, &DIR_E, 1 }, { "COM", {0x63}, &COM, &DIR_X, 1 }, 
	{ "COM", {0x1863}, &COM, &DIR_Y, 1 }, { "COMA", {0x43}, &COMA, &DIR_I, 1 }, { "COMB", {0x53}, &COMB, &DIR_I, 1 }, 
	{ "CPD", {0x1A83}, &CPD, &DIR_M, 1 }, { "CPD", {0x1A93}, &CPD, &DIR_D, 1 }, { "CPD", {0x1AB3}, &CPD, &DIR_E, 1 }, 
	{ "CPD", {0x1AA3}, &CPD, &DIR_X, 1 }, { "CPD", {0xCDA3}, &CPD, &DIR_Y, 1 }, { "CPX", {0x8C}, &CPX, &DIR_M, 1 }, 
	{ "CPX", {0x9C}, &CPX, &DIR_D, 1 }, { "CPX", {0xBC}, &CPX, &DIR_E, 1 }, { "CPX", {0xAC}, &CPX, &DIR_X, 1 }, 
	{ "CPX", {0xCDAC}, &CPX, &DIR_Y, 1 }, { "CPY", {0x188C}, &CPY, &DIR_M, 1 }, { "CPY", {0x189C}, &CPY, &DIR_D, 1 }, 
	{ "CPY", {0x18BC}, &CPY, &DIR_E, 1 }, { "CPY", {0x1AAC}, &CPY, &DIR_X, 1 }, { "CPY", {0x18AC}, &CPY, &DIR_Y, 1 }, 
	{ "DAA", {0x19}, &DAA, &DIR_I, 1 }, { "DEC", {0x7A}, &DEC, &DIR_E, 1 }, { "DEC", {0x6A}, &DEC, &DIR_X, 1 }, 
	{ "DEC", {0x186A}, &DEC, &DIR_Y, 1 }, { "DECA", {0x4A}, &DECA, &DIR_I, 1 }, { "DECB", {0x5A}, &DECB, &DIR_I, 1 }, 
	{ "DES", {0x34}, &DES, &DIR_I, 1 }, { "DEX", {0x09}, &DEX, &DIR_I, 1 }, { "DEY", {0x1809}, &DEY, &DIR_I, 1 }, 
	{ "EORA", {0x88}, &EORA, &DIR_M, 1 }, { "EORA", {0x98}, &EORA, &DIR_D, 1 }, { "EORA", {0xB8}, &EORA, &DIR_E, 1 }, 
	{ "EORA", {0xA8}, &EORA, &DIR_X, 1 }, { "EORA", {0x18A8}, &EORA, &DIR_Y, 1 }, { "EORB", {0xC8}, &EORB, &DIR_M, 1 }, 
	{ "EORB", {0xD8}, &EORB, &DIR_D, 1 }, { "EORB", {0xF8}, &EORB, &DIR_E, 1 }, { "EORB", {0xE8}, &EORB, &DIR_X, 1 }, 
	{ "EORB", {0x18E8}, &EORB, &DIR_Y, 1 }, { "FDIV", {0x03}, &FDIV, &DIR_I, 1 }, { "IDIV", {0x02}, &IDIV, &DIR_I, 1 }, 
	{ "INC", {0x7C}, &INC, &DIR_E, 1 }, { "INC", {0x6C}, &INC, &DIR_X, 1 }, { "INC", {0x186C}, &INC, &DIR_Y, 1 }, 
	{ "INCA", {0x4C}, &INCA, &DIR_I, 1 }, { "INCB", {0x5C}, &INCB, &DIR_I, 1 }, { "INS", {0x31}, &INS, &DIR_I, 1 }, 
	{ "INX", {0x08}, &INX, &DIR_I, 1 }, { "INY", {0x1808}, &INY, &DIR_I, 1 }, { "JMP", {0x7E}, &JMP, &DIR_E, 1 }, 
	{ "JMP", {0x63}, &JMP, &DIR_X, 1 }, { "JMP", {0x186E}, &JMP, &DIR_Y, 1 }, { "JSR", {0x9D}, &JSR, &DIR_D, 1 }, 
	{ "JSR", {0xBD}, &JSR, &DIR_E, 1 }, { "JSR", {0xAD}, &JSR, &DIR_X, 1 }, { "JSR", {0x18AD}, &JSR, &DIR_Y, 1 }, 
	{ "LDAA", {0x86}, &LDAA, &DIR_M, 1 }, { "LDAA", {0x96}, &LDAA, &DIR_D, 1 }, { "LDAA", {0xB6}, &LDAA, &DIR_E, 1 }, 
	{ "LDAA", {0xA6}, &LDAA, &DIR_X, 1 }, { "LDAA", {0x18A6}, &LDAA, &DIR_Y, 1 }, { "LDAB", {0xC6}, &LDAB, &DIR_M, 1 }, 
	{ "LDAB", {0xD6}, &LDAB, &DIR_D, 1 }, { "LDAB", {0xB6}, &LDAB, &DIR_E, 1 }, { "LDAB", {0xE6}, &LDAB, &DIR_X, 1 }, 
	{ "LDAB", {0x18E6}, &LDAB, &DIR_Y, 1 }, { "LDD", {0xCC}, &LDD, &DIR_M, 1 }, { "LDD", {0xDC}, &LDD, &DIR_D, 1 }, 
	{ "LDD", {0xFC}, &LDD, &DIR_E, 1 }, { "LDD", {0xEC}, &LDD, &DIR_X, 1 }, { "LDD", {0x18EC}, &LDD, &DIR_Y, 1 }, 
	{ "LDS", {0x8E}, &LDS, &DIR_M, 1 }, { "LDS", {0x9E}, &LDS, &DIR_D, 1 }, { "LDS", {0xBE}, &LDS, &DIR_E, 1 }, 
	{ "LDS", {0xAE}, &LDS, &DIR_X, 1 }, { "LDS", {0x18AE}, &LDS, &DIR_Y, 1 }, { "LDX", {0xCE}, &LDX, &DIR_M, 1 }, 
	{ "LDX", {0xDE}, &LDX, &DIR_D, 1 }, { "LDX", {0xFE}, &LDX, &DIR_E, 1 }, { "LDX", {0xEE}, &LDX, &DIR_X, 1 }, 
	{ "LDX", {0xCDEE}, &LDX, &DIR_Y, 1 }, { "LDY", {0x18CE}, &LDY, &DIR_M, 1 }, { "LDY", {0x18DE}, &LDY, &DIR_D, 1 }, 
	{ "LDY", {0x18FE}, &LDY, &DIR_E, 1 }, { "LDY", {0x1AEE}, &LDY, &DIR_X, 1 }, { "LDY", {0x18EE}, &LDY, &DIR_Y, 1 }, 
	{ "LSL", {0x78}, &LSL, &DIR_E, 1 }, { "LSL", {0x68}, &LSL, &DIR_X, 1 }, { "LSL", {0x1868}, &LSL, &DIR_Y, 1 }, 
	{ "LSLA", {0x48}, &LSLA, &DIR_I, 1 }, { "LSLB", {0x58}, &LSLB, &DIR_I, 1 }, { "LSLD", {0x05}, &LSLD, &DIR_I, 1 }, 
	{ "LSR", {0x74}, &LSR, &DIR_E, 1 }, { "LSR", {0x64}, &LSR, &DIR_X, 1 }, { "LSR", {0x1864}, &LSR, &DIR_Y, 1 }, 
	{ "LSRA", {0x44}, &LSRA, &DIR_I, 1 }, { "LSRB", {0x54}, &LSRB, &DIR_I, 1 }, { "LSRD", {0x04}, &LSRD, &DIR_I, 1 }, 
	{ "MUL", {0x3D}, &MUL, &DIR_I, 1 }, { "NEG", {0x70}, &NEG, &DIR_E, 1 }, { "NEG", {0x60}, &NEG, &DIR_X, 1 }, 
	{ "NEG", {0x1860}, &NEG, &DIR_Y, 1 }, { "NEGA", {0x40}, &NEGA, &DIR_I, 1 }, { "NEGB", {0x50}, &NEGB, &DIR_I, 1 }, 
	{ "NOP", {0x01}, &NOP, &DIR_I, 1 }, { "ORAA", {0x8A}, &ORAA, &DIR_M, 1 }, { "ORAA", {0x9A}, &ORAA, &DIR_D, 1 }, 
	{ "ORAA", {0xBA}, &ORAA, &DIR_E, 1 }, { "ORAA", {0xAA}, &ORAA, &DIR_X, 1 }, { "ORAA", {0x18AA}, &ORAA, &DIR_Y, 1 }, 
	{ "ORAB", {0xCA}, &ORAB, &DIR_M, 1 }, { "ORAB", {0xDA}, &ORAB, &DIR_D, 1 }, { "ORAB", {0xFA}, &ORAB, &DIR_E, 1 }, 
	{ "ORAB", {0xEA}, &ORAB, &DIR_X, 1 }, { "ORAB", {0x18EA}, &ORAB, &DIR_Y, 1 }, { "PSHA", {0x36}, &PSHA, &DIR_I, 1 }, 
	{ "PSHB", {0x37}, &PSHB, &DIR_I, 1 }, { "PSHX", {0x3C}, &PSHX, &DIR_I, 1 }, { "PSHY", {0x183C}, &PSHY, &DIR_I, 1 }, 
	{ "PULA", {0x32}, &PULA, &DIR_I, 1 }, { "PULB", {0x33}, &PULB, &DIR_I, 1 }, { "PULX", {0x38}, &PULX, &DIR_I, 1 }, 
	{ "PULY", {0x1838}, &PULY, &DIR_I, 1 }, { "ROL", {0x79}, &ROL, &DIR_E, 1 }, { "ROL", {0x69}, &ROL, &DIR_X, 1 }, 
	{ "ROL", {0x1869}, &ROL, &DIR_Y, 1 }, { "ROLA", {0x49}, &ROLA, &DIR_I, 1 }, { "ROLB", {0x59}, &ROLB, &DIR_I, 1 }, 
	{ "ROR", {0x76}, &ROR, &DIR_E, 1 }, { "ROR", {0x66}, &ROR, &DIR_X, 1 }, { "ROR", {0x1866}, &ROR, &DIR_Y, 1 }, 
	{ "RORA", {0x46}, &RORA, &DIR_I, 1 }, { "RORB", {0x56}, &RORB, &DIR_I, 1 }, { "RTI", {0x3B}, &RTI, &DIR_I, 1 }, 
	{ "RTS", {0x39}, &RTS, &DIR_I, 1 }, { "SBA", {0x10}, &SBA, &DIR_I, 1 }, { "SBCA", {0x82}, &SBCA, &DIR_M, 1 }, 
	{ "SBCA", {0x92}, &SBCA, &DIR_D, 1 }, { "SBCA", {0xB2}, &SBCA, &DIR_E, 1 }, { "SBCA", {0xA2}, &SBCA, &DIR_X, 1 }, 
	{ "SBCA", {0x18A2}, &SBCA, &DIR_Y, 1 }, { "SBCB", {0xC2}, &SBCB, &DIR_M, 1 }, { "SBCB", {0xD2}, &SBCB, &DIR_D, 1 }, 
	{ "SBCB", {0xF2}, &SBCB, &DIR_E, 1 }, { "SBCB", {0xE2}, &SBCB, &DIR_X, 1 }, { "SBCB", {0x18E2}, &SBCB, &DIR_Y, 1 }, 
	{ "SEC", {0x0D}, &SEC, &DIR_I, 1 }, { "SEI", {0x0F}, &SEI, &DIR_I, 1 }, { "SEV", {0x0B}, &SEV, &DIR_I, 1 }, 
	{ "STAA", {0x97}, &STAA, &DIR_D, 1 }, { "STAA", {0xB7}, &STAA, &DIR_E, 1 }, { "STAA", {0xA7}, &STAA, &DIR_X, 1 }, 
	{ "STAA", {0x18A7}, &STAA, &DIR_Y, 1 }, { "STAB", {0xD7}, &STAB, &DIR_D, 1 }, { "STAB", {0xF7}, &STAB, &DIR_E, 1 }, 
	{ "STAB", {0xE7}, &STAB, &DIR_X, 1 }, { "STAB", {0x18E7}, &STAB, &DIR_Y, 1 }, { "STD", {0xDD}, &STD, &DIR_D, 1 }, 
	{ "STD", {0xFD}, &STD, &DIR_E, 1 }, { "STD", {0xED}, &STD, &DIR_X, 1 }, { "STD", {0x18ED}, &STD, &DIR_Y, 1 }, 
	{ "STOP", {0xCF}, &STOP, &DIR_I, 1 }, { "STS", {0x9F}, &STS, &DIR_D, 1 }, { "STS", {0xBF}, &STS, &DIR_E, 1 }, 
	{ "STS", {0xAF}, &STS, &DIR_X, 1 }, { "STS", {0x18AF}, &STS, &DIR_Y, 1 }, { "STX", {0xDF}, &STX, &DIR_D, 1 }, 
	{ "STX", {0xFF}, &STX, &DIR_E, 1 }, { "STX", {0xEF}, &STX, &DIR_X, 1 }, { "STX", {0xCDEF}, &STX, &DIR_Y, 1 }, 
	{ "STY", {0x18DF}, &STY, &DIR_D, 1 }, { "STY", {0x18FF}, &STY, &DIR_E, 1 }, { "STY", {0x1AEF}, &STY, &DIR_X, 1 }, 
	{ "STY", {0x18EF}, &STY, &DIR_Y, 1 }, { "SUBA", {0x80}, &SUBA, &DIR_M, 1 }, { "SUBA", {0x90}, &SUBA, &DIR_D, 1 }, 
	{ "SUBA", {0xB0}, &SUBA, &DIR_E, 1 }, { "SUBA", {0xA0}, &SUBA, &DIR_X, 1 }, { "SUBA", {0x18A0}, &SUBA, &DIR_Y, 1 }, 
	{ "SUBB", {0xC0}, &SUBB, &DIR_M, 1 }, { "SUBB", {0xD0}, &SUBB, &DIR_D, 1 }, { "SUBB", {0xF0}, &SUBB, &DIR_E, 1 }, 
	{ "SUBB", {0xE0}, &SUBB, &DIR_X, 1 }, { "SUBB", {0x18E0}, &SUBB, &DIR_Y, 1 }, { "SUBD", {0x83}, &SUBD, &DIR_M, 1 }, 
	{ "SUBD", {0x93}, &SUBD, &DIR_D, 1 }, { "SUBD", {0xB3}, &SUBD, &DIR_E, 1 }, { "SUBD", {0xA3}, &SUBD, &DIR_X, 1 }, 
	{ "SUBD", {0x18A3}, &SUBD, &DIR_Y, 1 }, { "SWI", {0x3F}, &SWI, &DIR_I, 1 }, { "TAB", {0x16}, &TAB, &DIR_I, 1 }, 
	{ "TAP", {0x06}, &TAP, &DIR_I, 1 }, { "TBA", {0x17}, &TBA, &DIR_I, 1 }, { "TEST", {0x00}, &TEST, &DIR_I, 1 }, 
	{ "TPA", {0x07}, &TPA, &DIR_I, 1 }, { "TST", {0x7D}, &TST, &DIR_E, 1 }, { "TST", {0x6D}, &TST, &DIR_X, 1 }, 
	{ "TST", {0x186D}, &TST, &DIR_Y, 1 }, { "TSTA", {0x4D}, &TSTA, &DIR_I, 1 }, { "TSTB", {0x5D}, &TSTB, &DIR_I, 1 }, 
	{ "TSX", {0x30}, &TSX, &DIR_I, 1 }, { "TSY", {0x1830}, &TSY, &DIR_Y, 1 }, { "TXS", {0x35}, &TXS, &DIR_I, 1 }, 
	{ "TYS", {0x1835}, &TYS, &DIR_I, 1 }, { "WAI", {0x3E}, &WAI, &DIR_I, 1 }, { "XGDX", {0x8F}, &XGDX, &DIR_I, 1 }, 
	{ "XGDY", {0x188F}, &XGDY, &DIR_I, 1 }, 
};

#pragma endregion LOOKUP

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
	#ifdef _DEBUG
	printf("---------------------------\n");
	printf("Called: %s (%02X)\n", instruction->mnemonic, instruction->opcode);	// DEBUG
	#endif
	(instruction->op)(hc11, instruction->mode);
}

void end_inst(void)
{
	end_tree(root);
	root = NULL;
}

#pragma region DIRMODE

arg_t DIR_I(hc11_t *hc11, size_t n)	// Inherent
{
	#ifdef _DEBUG
	printf("Dirmode: INH\n");
	#endif
	return (arg_t)0;	// Value doesn't matter!
}

arg_t DIR_M(hc11_t *hc11, size_t n)	// Immediate
{
	#ifdef _DEBUG
	printf("Dirmode: IMM\n");
	#endif
	arg_t ret = (arg_t)0;
	if(n == 1)
	{
		ret = hc11->memory[hc11->pc++];
	}
	if(n == 2)
	{
		ret = hc11->memory[hc11->pc++] << 8;
		ret += hc11->memory[hc11->pc++];
	}
	return ret;
}

arg_t DIR_E(hc11_t *hc11, size_t n)	// Extended
{
	#ifdef _DEBUG
	printf("Dirmode: EXT\n");
	#endif
	arg_t ret = hc11->memory[hc11->pc++] << 8;
	ret += hc11->memory[hc11->pc++];
	return ret;
}

arg_t DIR_D(hc11_t *hc11, size_t n)	// Direct
{
	#ifdef _DEBUG
	printf("Dirmode: DIR\n");
	#endif
	arg_t ret = hc11->memory[hc11->pc++];
	return ret;
}

arg_t DIR_X(hc11_t *hc11, size_t n)	// Index X
{
	#ifdef _DEBUG
	printf("Dirmode: IND_X\n");
	#endif
	arg_t ret = (arg_t)0;
	uint8_t ind = hc11->memory[hc11->pc++];
	ret = hc11->ind_x + ind;
	return ret;
}

arg_t DIR_Y(hc11_t *hc11, size_t n)	// Index Y
{
	#ifdef _DEBUG
	printf("Dirmode: IND_Y\n");
	#endif
	arg_t ret = (arg_t)0;
	uint8_t ind = hc11->memory[hc11->pc++];
	ret = hc11->ind_y + ind;
	return ret;
}

arg_t DIR_R(hc11_t *hc11, size_t n)	// Relative
{
	#ifdef _DEBUG
	printf("Dirmode: REL\n");
	#endif
	arg_t ret = (arg_t)0;
	if(n == 1)
	{
		int8_t jump = (int8_t)hc11->memory[hc11->pc++];
		ret = jump;
	}
	if(n == 2)
	{
		uint16_t jump = hc11->memory[hc11->pc++] << 8;
		jump += hc11->memory[hc11->pc++];
		ret = jump;
	}
	return ret;
}

#pragma endregion

#pragma region FUNCS

void ABA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ABX(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{
	
}

void ABY(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ADCA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ADCB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ADDA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ADDB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ADDD(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ANDA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ANDB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ASL(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ASLA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ASLB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ASLD(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ASR(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ASRA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ASRB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BCC(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BCLR(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BCS(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BEQ(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BGE(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BGT(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BHI(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BHS(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BITA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BITB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BLE(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BLO(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BLS(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BLT(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BMI(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BNE(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BPL(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BRA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BRCLR(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BRN(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BRSET(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BSET(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BSR(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BVC(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void BVS(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void CBA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void CLC(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void CLI(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void CLR(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void CLRA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void CLRB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void CLV(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void CMPA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void CMPB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void COM(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void COMA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void COMB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void CPD(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void CPX(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void CPY(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void DAA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void DEC(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void DECA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void DECB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void DES(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void DEX(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void DEY(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void EORA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void EORB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void FDIV(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void IDIV(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void INC(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void INCA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void INCB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void INS(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void INX(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void INY(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void JMP(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void JSR(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void LDAA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{
	hc11->acc_a = arg(hc11, 1);	// Testing...
}

void LDAB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void LDD(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void LDS(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void LDX(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void LDY(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void LSL(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void LSLA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void LSLB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void LSLD(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void LSR(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void LSRA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void LSRB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void LSRD(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void MUL(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void NEG(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void NEGA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void NEGB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void NOP(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ORAA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ORAB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void PSHA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void PSHB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void PSHX(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void PSHY(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void PULA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void PULB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void PULX(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void PULY(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ROL(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ROLA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ROLB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void ROR(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void RORA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void RORB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void RTI(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void RTS(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void SBA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void SBCA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void SBCB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void SEC(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void SEI(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void SEV(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void STAA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void STAB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void STD(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void STOP(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void STS(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void STX(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void STY(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void SUBA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void SUBB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void SUBD(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void SWI(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void TAB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void TAP(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void TBA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void TEST(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void TPA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void TST(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void TSTA(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void TSTB(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void TSX(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void TSY(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void TXS(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void TYS(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void WAI(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void XGDX(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

void XGDY(hc11_t *hc11, arg_t (*arg)(hc11_t*, size_t))
{

}

#pragma endregion FUNCS