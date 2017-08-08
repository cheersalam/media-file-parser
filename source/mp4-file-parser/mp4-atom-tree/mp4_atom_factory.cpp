#include "../mp4-atoms/inc/mp4_atom_factory.h"
#include "../mp4-atoms/inc/mp4_atom_dumm.h"
#include "../mp4-atoms/inc/mp4_atom_ftyp.h"
#include "../mp4-atoms/inc/mp4_atom_mvhd.h"
#include "../mp4-atoms/inc/mp4_atom_trak.h"
#include "../mp4-atoms/inc/mp4_atom_tkhd.h"
#include "../mp4-atoms/inc/mp4_atom_mdia.h"
#include "../mp4-atoms/inc/mp4_atom_mdhd.h"
#include "../mp4-atoms/inc/mp4_atom_hdlr.h"
#include "../mp4-atoms/inc/mp4_atom_minf.h"
#include "../mp4-atoms/inc/mp4_atom_vmhd.h"
#include "../mp4-atoms/inc/mp4_atom_smhd.h"
#include "../mp4-atoms/inc/mp4_atom_dinf.h"
#include "../mp4-atoms/inc/mp4_atom_dref.h"
#include "../mp4-atoms/inc/mp4_atom_stbl.h"
#include "../mp4-atoms/inc/mp4_atom_stsd.h"
#include "../mp4-atoms/inc/mp4_atom_avc1.h"
#include "../mp4-atoms/inc/mp4_atom_avcC.h"
#include "../mp4-atoms/inc/mp4_atom_stts.h"
#include "../mp4-atoms/inc/mp4_atom_stss.h"
#include "../mp4-atoms/inc/mp4_atom_stsc.h"
#include "../mp4-atoms/inc/mp4_atom_stsz.h"
#include "../mp4-atoms/inc/mp4_atom_stco.h"
#include "../mp4-atoms/inc/mp4_atom_udta.h"
#include "../mp4-atoms/inc/mp4_atom_mdat.h"
#include "../mp4-atoms/inc/mp4_atom_ukwn.h"

namespace mp4atom {
    Mp4AtomFactory::Mp4AtomFactory()
    {
    }

    Mp4AtomFactory::~Mp4AtomFactory()
    {
    }

    mp4atom::Mp4Atom * Mp4AtomFactory::CreateAtom(uint32_t type, uint32_t size, char *payload)
    {
        mp4atom::Mp4Atom *mp4Atom = nullptr;

        switch (type) {
        case ATOM_TYPE_DUMM:
            mp4Atom = new Mp4AtomDumm(size, payload);
            break;

        case ATOM_TYPE_FTYP:
            mp4Atom = new Mp4AtomFtyp(size, payload);
            break;

        case ATOM_TYPE_MOOV:
            mp4Atom = new Mp4AtomMoov(size, payload);
            break;

        case ATOM_TYPE_MVHD:
            mp4Atom = new Mp4AtomMvhd(size, payload);
            break;

        case ATOM_TYPE_TRAK:
            mp4Atom = new Mp4AtomTrak(size, payload);
            break;

        case ATOM_TYPE_TKHD:
            mp4Atom = new Mp4AtomTkhd(size, payload);
            break;

        case ATOM_TYPE_MDIA:
            mp4Atom = new Mp4AtomMdia(size, payload);
            break;

        case ATOM_TYPE_MDHD:
            mp4Atom = new Mp4AtomMdhd(size, payload);
            break;

        case ATOM_TYPE_HDLR:
            mp4Atom = new Mp4AtomHdlr(size, payload);
            break;

        case ATOM_TYPE_MINF:
            mp4Atom = new Mp4AtomMinf(size, payload);
            break;

        case ATOM_TYPE_VMHD:
            mp4Atom = new Mp4AtomVmhd(size, payload);
            break;

        case ATOM_TYPE_SMHD:
            mp4Atom = new Mp4AtomSmhd(size, payload);
            break;

        case ATOM_TYPE_DINF:
            mp4Atom = new Mp4AtomDinf(size, payload);
            break;

        case ATOM_TYPE_DREF:
            mp4Atom = new Mp4AtomDref(size, payload);
            break;

        case ATOM_TYPE_STBL:
            mp4Atom = new Mp4AtomStbl(size, payload);
            break;

        case ATOM_TYPE_STSD:
            mp4Atom = new Mp4AtomStsd(size, payload);
            break;

        case ATOM_TYPE_AVC1:
            mp4Atom = new Mp4AtomAvc1(size, payload);
            break;

        case ATOM_TYPE_AVCC:
            mp4Atom = new Mp4AtomAvcC(size, payload);
            break;

        case ATOM_TYPE_STTS:
            mp4Atom = new Mp4AtomStts(size, payload);
            break;

        case ATOM_TYPE_STSS:
            mp4Atom = new Mp4AtomStss(size, payload);
            break;

        case ATOM_TYPE_STSC:
            mp4Atom = new Mp4AtomStsc(size, payload);
            break;

        case ATOM_TYPE_STSZ:
            mp4Atom = new Mp4AtomStsz(size, payload);
            break;

        case ATOM_TYPE_STCO:
            mp4Atom = new Mp4AtomStco(size, payload);
            break;

        case ATOM_TYPE_UDTA:
            mp4Atom = new Mp4AtomUdta(size, payload);
            break;

        case ATOM_TYPE_MDAT:
            mp4Atom = new Mp4AtomMdat(size, payload);
            break;

        default:
            mp4Atom = new Mp4AtomUkwn(size, payload);
        }
        return mp4Atom;
    }
    
} //namespace mp4atom {

