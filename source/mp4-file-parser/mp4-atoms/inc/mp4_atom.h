#pragma once
#include <stdint.h>
#include <string>

//Filenames should be all lowercase and can include underscores(_) or dashes(-).
//Namespace names are all lower-case.
//The names of variables (including function parameters) and data members are all lowercase, with underscores between words. 
namespace mp4atom {

#define TO_UINT32(a, b, c, d)            \
    (((static_cast<uint32_t>(a))<<24) |  \
    ((static_cast<uint32_t>(b))<<16)  |  \
    ((static_cast<uint32_t>(c))<< 8)  |  \
    ((static_cast<uint32_t>(d))))


#define ATOM_TYPE(c1, c2, c3, c4) TO_UINT32(c1, c2, c3, c4)

    const uint32_t ATOM_TYPE_DUMM = ATOM_TYPE('d', 'u', 'm', 'm');
    const uint32_t ATOM_TYPE_FTYP = ATOM_TYPE('f', 't', 'y', 'p');
    const uint32_t ATOM_TYPE_MOOV = ATOM_TYPE('m', 'o', 'o', 'v');    
    const uint32_t ATOM_TYPE_MVHD = ATOM_TYPE('m', 'v', 'h', 'd');

    const uint32_t ATOM_TYPE_TRAK = ATOM_TYPE('t', 'r', 'a', 'k');
    const uint32_t ATOM_TYPE_TKHD = ATOM_TYPE('t', 'k', 'h', 'd');
    const uint32_t ATOM_TYPE_MDIA = ATOM_TYPE('m', 'd', 'i', 'a');
    const uint32_t ATOM_TYPE_MDHD = ATOM_TYPE('m', 'd', 'h', 'd');
    const uint32_t ATOM_TYPE_HDLR = ATOM_TYPE('h', 'd', 'l', 'r');
    const uint32_t ATOM_TYPE_MINF = ATOM_TYPE('m', 'i', 'n', 'f');
    const uint32_t ATOM_TYPE_SMHD = ATOM_TYPE('s', 'm', 'h', 'd');
    const uint32_t ATOM_TYPE_VMHD = ATOM_TYPE('v', 'm', 'h', 'd');
    
    const uint32_t ATOM_TYPE_DINF = ATOM_TYPE('d', 'i', 'n', 'f');
    const uint32_t ATOM_TYPE_DREF = ATOM_TYPE('d', 'r', 'e', 'f');    
    const uint32_t ATOM_TYPE_STBL = ATOM_TYPE('s', 't', 'b', 'l');
    const uint32_t ATOM_TYPE_STSD = ATOM_TYPE('s', 't', 's', 'd');
    const uint32_t ATOM_TYPE_AVC1 = ATOM_TYPE('a', 'v', 'c', 'l');
    const uint32_t ATOM_TYPE_AVCC = ATOM_TYPE('a', 'v', 'c', 'C');    
    
    const uint32_t ATOM_TYPE_STTS = ATOM_TYPE('s', 't', 't', 's');
    const uint32_t ATOM_TYPE_STSS = ATOM_TYPE('s', 't', 's', 's');
    const uint32_t ATOM_TYPE_STSC = ATOM_TYPE('s', 't', 's', 'c');
    const uint32_t ATOM_TYPE_STSZ = ATOM_TYPE('s', 't', 's', 'z');
    const uint32_t ATOM_TYPE_STCO = ATOM_TYPE('s', 't', 'c', 'o');

    const uint32_t ATOM_TYPE_UDTA = ATOM_TYPE('u', 'd', 't', 'a');
    const uint32_t ATOM_TYPE_META = ATOM_TYPE('m', 'e', 't', 'a');
    const uint32_t ATOM_TYPE_ILST = ATOM_TYPE('i', 'l', 's', 't');

    const uint32_t ATOM_TYPE_MDAT = ATOM_TYPE('m', 'd', 'a', 't');

    class Mp4Atom
    {
    public:
        explicit Mp4Atom(uint32_t atom_type, char *payload);
        explicit Mp4Atom(uint32_t atom_type, uint32_t size, char *payload);
        explicit Mp4Atom(uint32_t atom_type, uint32_t size, uint8_t version, uint32_t flags);
        explicit Mp4Atom(uint32_t atom_type, uint64_t ext_size, uint8_t version, uint32_t flags);
        virtual ~Mp4Atom();

    protected:
        uint32_t      atomType_;       // 4 byte
        uint32_t      size_;            // 4 byte
        uint64_t      extSize_;        // 8 byte
        uint8_t       version_;         // 1 byte
        uint32_t      flags_;           // 3 byte
        uint32_t      payloadSize_;    //
        char          *payload_;        // Atom payload
        int32_t       hasChildren_;    // has children
        bool          canHaveChildren_; //atom type in string
        char          *atomTypeStr_;  //atom type in string
        char          header_[8];       // 8 byte header; 4 byte size + 4 byte length
        //TODO 8 byte size handling

    public:
        //methods
        uint32_t    GetAtomType() const { return atomType_; }
        void        SetAtomType(uint32_t atom_type) { atomType_ = atom_type; }
        uint32_t    GetSize() const { return size_; }
        void        SetSize(uint32_t size) { size_ = size; }
        uint64_t    GetExtSize() const { return extSize_; }
        void        SetExtSize(uint64_t long_size) { extSize_ = long_size; }
        uint8_t     GetVersion() const { return version_; }
        void        SetVersion(uint8_t version) { version_ = version; }
        uint32_t    GetFlags() const { return flags_; }
        void        SetFlags(uint32_t flags) { flags_ = flags; }
        bool        CanHaveChildren() const { return canHaveChildren_; }
        void        SetPayload(char *payload, uint32_t payload_size) { payload_ = payload; payloadSize_ = payload_size; }
        char *      GetPayload() const { return payload_; }
        uint32_t    GetPayloadSize() const { return payloadSize_; }
        const char* GetAttomTypStr() const { return atomTypeStr_; }
        uint32_t    HasChildren() const { return hasChildren_; }
        void        SetHeader(char *header) { memcpy_s(header_, 8, header, 8); }
        const char* GetHeader() const { return header_; }
        
        //virtual functions
        void        PrintAtom();
    };
} //namespace mp4atom
