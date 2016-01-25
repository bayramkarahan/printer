/*
 * Manifest constants for the ZjStream protocol
 *
 * I'm told that a lot of this stuff came from a file called "zjrca.h".
 * But a Google search does not turn up that file. I added my own
 * improvements and missing pieces. -Rick
 */

#include <inttypes.h>
typedef uint32_t	DWORD;
typedef uint16_t	WORD;
typedef uint8_t		BYTE;

#pragma pack(push)
#pragma pack(1)

typedef struct _HBPL_HEADER {
    char	type[3];
    char	len;
} HBPL_HEADER;

typedef struct _HBPL_JP {
    HBPL_HEADER	hdr;		// 0
    DWORD	unk1;		// 4
    DWORD	unk2;		// 8
    char	unk3[3];	// 12,13,14
    char	source_size;	// 15
    DWORD	unk[12];	// 16 ... 60
} HBPL_JP;

typedef struct _HBPL_PS {
    HBPL_HEADER	hdr;		// 0
    DWORD	w;		// 4
    DWORD	h;		// 8
    DWORD	wh_total;	// 12 in bytes
    DWORD	len;		// 16
    char	papersize;	// 20
    char	mediatype;	// 21
    char	color;		// 22
    char	unk2;		// 23
    WORD	res;		// 24
    DWORD	bihoff[4];	// 26, 30, 34, 38
    WORD	unk3;		// 42
    DWORD	unk4[5];	// 44, 48, 52, 56, 60
} HBPL_PS;

typedef struct _HBPL_PE {
    HBPL_HEADER	hdr;		// 0
    DWORD	unk[15];	// 4 ... 60
} HBPL_PE;

typedef struct _HBPL_DM {
    HBPL_HEADER	hdr;
    DWORD	data;	
} HBPL_DM;

#pragma pack(pop)

typedef enum
{
    DMDUPLEX_OFF	= 1,
    DMDUPLEX_LONGEDGE	= 2,
    DMDUPLEX_SHORTEDGE	= 3,
    DMDUPLEX_MANUALLONG	= 4,
    DMDUPLEX_MANUALSHORT= 5
} DMDUPLEX;

typedef enum {
    DMBIN_UPPER		= 1,
    DMBIN_ONLYONE	= 1,
    DMBIN_LOWER		= 2,
    DMBIN_MIDDLE	= 3,
    DMBIN_MANUAL	= 4,
    DMBIN_ENVELOPE	= 5,
    DMBIN_ENVMANUAL	= 6,
    DMBIN_AUTO		= 7,
    DMBIN_TRACTOR	= 8,
    DMBIN_SMALLFMT	= 9,
    DMBIN_LARGEFMT	=10,
    DMBIN_LARGECAPACITY	=11,
    DMBIN_CASSETTE	=14,
    DMBIN_FORMSOURCE	=15
} DM_BIN;

typedef enum {
    DMMEDIA_STANDARD	= 1,	// Standard paper
    DMMEDIA_TRANSPARENCY= 2,	// Transparency
    DMMEDIA_GLOSSY	= 3,	// Glossy paper
    DMMEDIA_USER	= 4,	// Device-specific media start here

    DMMEDIA_ENVELOPE	= 0x101, // Envelope
    DMMEDIA_LETTERHEAD	= 0x103, // Letterhead
    DMMEDIA_THICK_STOCK	= 0x105, // Thick Stock
    DMMEDIA_POSTCARD	= 0x106, // Postcard
    DMMEDIA_LABELS	= 0x107, // Labels
} DMMEDIA;

typedef enum {
    DMCOLOR_MONOCHROME	= 1,
    DMCOLOR_COLOR	= 2,
} DMCOLOR;

typedef enum {
    DMORIENT_PORTRAIT	= 1,
    DMORIENT_LANDSCAPE	= 2,
} DMORIENT;

typedef enum {
    DMPAPER_LETTER	= 1,	// Letter, 8 1/2- by 11-inches
    DMPAPER_LETTERSMALL	= 2,	// Letter Small, 8 1/2- by 11-inches
    DMPAPER_TABLOID	= 3,	// Tabloid, 11- by 17-inches
    DMPAPER_LEDGER	= 4,	// Ledger, 17- by 11-inches
    DMPAPER_LEGAL	= 5,	// Legal, 8 1/2- by 14-inches
    DMPAPER_STATEMENT	= 6,	// Statement, 5 1/2- by 8 1/2-inches
    DMPAPER_EXECUTIVE	= 7,	// Executive, 7 1/4- by 10 1/2-inches
    DMPAPER_A3		= 8,	// A3 sheet, 297- by 420-millimeters
    DMPAPER_A4		= 9,	// A4 Sheet, 210- by 297-millimeters
    DMPAPER_A4SMALL	=10,	// A4 small sheet, 210- by 297-millimeters
    DMPAPER_A5		=11,	// A5 sheet, 148- by 210-millimeters
    DMPAPER_B4		=12,	// B4 sheet, 250- by 354-millimeters
    DMPAPER_B5		=13,	// B5 sheet, 182- by 257-millimeter paper
    DMPAPER_FOLIO	=14,	// Folio, 8 1/2- by 13-inch paper
    DMPAPER_QUARTO	=15,	// Quarto, 215- by 275-millimeter paper
    DMPAPER_10X14	=16,	// 10- by 14-inch sheet
    DMPAPER_11X17	=17,	// 11- by 17-inch sheet
    DMPAPER_NOTE	=18,	// Note, 8 1/2- by 11-inches
    DMPAPER_ENV_9	=19,	// #9 Envelope, 3 7/8- by 8 7/8-inches
    DMPAPER_ENV_10	=20,	// #10 Envelope, 4 1/8- by 9 1/2-inches
    DMPAPER_ENV_11	=21,	// #11 Envelope, 4 1/2- by 10 3/8-inches
    DMPAPER_ENV_12	=22,	// #12 Envelope, 4 3/4- by 11-inches
    DMPAPER_ENV_14	=23,	// #14 Envelope, 5- by 11 1/2-inches
    DMPAPER_CSHEET	=24,	// C Sheet, 17- by 22-inches
    DMPAPER_DSHEET	=25,	// D Sheet, 22- by 34-inches
    DMPAPER_ESHEET	=26,	// E Sheet, 34- by 44-inches
    DMPAPER_ENV_DL	=27,	// DL Envelope, 110- by 220-millimeters
    DMPAPER_ENV_C5	=28,	// C5 Envelope, 162- by 229-millimeters
    DMPAPER_ENV_C3	=29,	// C3 Envelope, 324- by 458-millimeters
    DMPAPER_ENV_C4	=30,	// C4 Envelope, 229- by 324-millimeters
    DMPAPER_ENV_C6	=31,	// C6 Envelope, 114- by 162-millimeters
    DMPAPER_ENV_C65	=32,	// C65 Envelope, 114- by 229-millimeters
    DMPAPER_ENV_B4	=33,	// B4 Envelope, 250- by 353-millimeters
    DMPAPER_ENV_B5	=34,	// B5 Envelope, 176- by 250-millimeters
    DMPAPER_ENV_B6	=35,	// B6 Envelope, 176- by 125-millimeters
    DMPAPER_ENV_ITALY	=36,	// Italy Envelope, 110- by 230-millimeters
    DMPAPER_ENV_MONARCH	=37,	// Monarch Envelope, 3 7/8- by 7 1/2-inches
    DMPAPER_ENV_PERSONAL=38,	// 6 3/4 Envelope, 3 5/8- by 6 1/2-inches
    DMPAPER_FANFOLD_US	=39,	// US Std Fanfold, 14 7/8- by 11-inches
    DMPAPER_FANFOLD_STD_GERMAN	=40,	// German Std Fanfold, 8 1/2 x 12 in
    DMPAPER_FANFOLD_LGL_GERMAN	=41,	// German Legal Fanfold, 8 1/2 x 13 in

    DMPAPER_ISO_B4		   =42,	// B4 (ISO) 250 x 353 mm
    DMPAPER_JAPANESE_POSTCARD	   =43,	// Japanese Postcard 100 x 148 mm
    DMPAPER_9X11		   =44,	// 9 x 11 in
    DMPAPER_10X11		   =45,	// 10 x 11 in
    DMPAPER_15X11		   =46,	// 15 x 11 in
    DMPAPER_ENV_INVITE		   =47,	// Envelope Invite 220 x 220 mm
    DMPAPER_RESERVED_48		   =48,	// RESERVED--DO NOT USE
    DMPAPER_RESERVED_49		   =49,	// RESERVED--DO NOT USE
    DMPAPER_LETTER_EXTRA	   =50,	// Letter Extra 9 \275 x 12 in
    DMPAPER_LEGAL_EXTRA		   =51,	// Legal Extra 9 \275 x 15 in
    DMPAPER_TABLOID_EXTRA	   =52,	// Tabloid Extra 11.69 x 18 in
    DMPAPER_A4_EXTRA		   =53,	// A4 Extra 9.27 x 12.69 in
    DMPAPER_LETTER_TRANSVERSE	   =54,	// Letter Transverse 8 \275 x 11 in
    DMPAPER_A4_TRANSVERSE	   =55,	// A4 Transverse 210 x 297 mm
    DMPAPER_LETTER_EXTRA_TRANSVERSE=56,	// Letter Extra Transverse 9\275 x 12 in
    DMPAPER_A_PLUS		   =57,	// SuperA/SuperA/A4 227 x 356 mm
    DMPAPER_B_PLUS		   =58,	// SuperB/SuperB/A3 305 x 487 mm
    DMPAPER_LETTER_PLUS		   =59,	// Letter Plus 8.5 x 12.69 in
    DMPAPER_A4_PLUS		   =60,	// A4 Plus 210 x 330 mm
    DMPAPER_A5_TRANSVERSE	   =61,	// A5 Transverse 148 x 210 mm
    DMPAPER_B5_TRANSVERSE	   =62,	// B5 (JIS) Transverse 182 x 257 mm
    DMPAPER_A3_EXTRA		   =63,	// A3 Extra 322 x 445 mm
    DMPAPER_A5_EXTRA		   =64,	// A5 Extra 174 x 235 mm
    DMPAPER_B5_EXTRA		   =65,	// B5 (ISO) Extra 201 x 276 mm
    DMPAPER_A2			   =66,	// A2 420 x 594 mm
    DMPAPER_A3_TRANSVERSE	   =67,	// A3 Transverse 297 x 420 mm
    DMPAPER_A3_EXTRA_TRANSVERSE	   =68,	// A3 Extra Transverse 322 x 445 mm
} DMPAPER;

typedef union _SWAP_32{
    char		byte[sizeof(uint32_t)];
    uint32_t		dword;
} SWAP_32;

typedef union _SWAP_16{
    char		byte[sizeof(uint16_t)];
    uint16_t		word;
} SWAP_16;

static inline uint32_t
be32(uint32_t dword)
{
    SWAP_32	swap;
    uint32_t	probe = 1;

    if (((char *)&probe)[0] == 1)
    {
	swap.byte[3] = (( SWAP_32 )dword).byte[0]; 
	swap.byte[2] = (( SWAP_32 )dword).byte[1];
	swap.byte[1] = (( SWAP_32 )dword).byte[2]; 
	swap.byte[0] = (( SWAP_32 )dword).byte[3];
	return swap.dword;
    }
    else
	return dword;
}

static inline uint16_t
be16(uint16_t word)
{
    SWAP_16	swap;
    uint16_t	probe = 1;

    if (((char *)&probe)[0] == 1)
    {
	swap.byte[1] = (( SWAP_16 )word).byte[0]; 
	swap.byte[0] = (( SWAP_16 )word).byte[1];
	return swap.word;
    }
    else
	return word;
}

static inline uint32_t
le32(uint32_t dword)
{
    SWAP_32	swap;
    uint32_t	probe = 1;

    if (((char *)&probe)[0] != 1)
    {
	swap.byte[3] = (( SWAP_32 )dword).byte[0]; 
	swap.byte[2] = (( SWAP_32 )dword).byte[1];
	swap.byte[1] = (( SWAP_32 )dword).byte[2]; 
	swap.byte[0] = (( SWAP_32 )dword).byte[3];
	return swap.dword;
    }
    else
	return dword;
}

static inline uint16_t
le16(uint16_t word)
{
    SWAP_16	swap;
    uint16_t	probe = 1;

    if (((char *)&probe)[0] != 1)
    {
	swap.byte[1] = (( SWAP_16 )word).byte[0]; 
	swap.byte[0] = (( SWAP_16 )word).byte[1];
	return swap.word;
    }
    else
	return word;
}
