//  待修改

//
//  MD5_BIN.hpp
//  DEMO_DAY_04_USER_XCODE
//
//  Created by Jingtao Fan on 2021/8/2.
//

#ifndef MD5_BIN_hpp
#define MD5_BIN_hpp
#include<cstdint>
#include<string>
using namespace std;

//c++11 have some fixed bits int types, can work well in defferent compiler and OS
using BYTE = uint8_t;
using WORD = uint16_t;
using DWORD_T = uint32_t;
using QWORD = uint64_t;

//A data type with 512 bits
using BIT512 = union{
    BYTE  Byte[64];
    WORD  Word[32];
    DWORD_T DWORD_T[16];
    QWORD QWord[8];
};

//A data type with 125 bits
using BIT128 = union{
    BYTE  Byte[16];
    WORD  Word[8];
    DWORD_T DWORD_T[4];
    QWORD QWord[2];
};


//class MD5
class MD5{
public:
    //default constructor, with no plaintext
    MD5();
    //constructor, with plaintext
    MD5(const string& PlainText);
    //copy constructor
    MD5(const MD5& aMD5);
    //as the base class, considering the possibility of subsequent expansion and modification, the destructor should be a virtual function
    virtual ~MD5();
    //Encypte plaintext to m_ciphertext via MD5 algorithm
    void Update(const string& PlainText);
    //the overloading of operator assigment function
    MD5& operator=(const MD5& aMD5);
    //the overloading of operator equal function
    bool operator==(const MD5& aMD5) const;
    //the overloading of operator not equal function
    bool operator!=(const MD5& aMD5) const;
    //the overloading of stream insertion operator
    friend ostream& operator<<(ostream& stream, const MD5& aMD5);
    //the overloading of stream extraction operator
    friend istream& operator>>(istream& stream, MD5& aMD5);
    //Encypte plaintext to return value as string via MD5 algorithm
    static string Encrypt(const string& Plaintext);
    //return a MD5 object from a ciphertext string
    static MD5 FromCipherText(const string& aCipherText);
    //a tool function of making BIT512 from string, for input convertion of MD5 algorithm
    static BIT512 StrToBit512(const string& PlainText);
    //2022-07-17添加
    //检测是否为空
    bool empty() const;
private:
    string m_CipherText;
    static const DWORD_T T[4][16];
    static const DWORD_T S[4][16];
    static const DWORD_T M[4][16];
    static void FRound(DWORD_T& a, DWORD_T& b, DWORD_T& c, DWORD_T& d, DWORD_T mj, DWORD_T s, DWORD_T ti);
    static void GRound(DWORD_T& a, DWORD_T& b, DWORD_T& c, DWORD_T& d, DWORD_T mj, DWORD_T s, DWORD_T ti);
    static void HRound(DWORD_T& a, DWORD_T& b, DWORD_T& c, DWORD_T& d, DWORD_T mj, DWORD_T s, DWORD_T ti);
    static void RRound(DWORD_T& a, DWORD_T& b, DWORD_T& c, DWORD_T& d, DWORD_T mj, DWORD_T s, DWORD_T ti);
};
#endif /* MD5_BIN_hpp */
