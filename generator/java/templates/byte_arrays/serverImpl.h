unsigned char serverImplByteArray[] = {
  0x70, 0x61, 0x63, 0x6b, 0x61, 0x67, 0x65, 0x20, 0x5b, 0x25, 0x42, 0x41,
  0x53, 0x45, 0x5f, 0x50, 0x41, 0x43, 0x4b, 0x41, 0x47, 0x45, 0x5f, 0x4e,
  0x41, 0x4d, 0x45, 0x25, 0x5d, 0x3b, 0x0a, 0x0a, 0x0a, 0x63, 0x6c, 0x61,
  0x73, 0x73, 0x20, 0x5b, 0x25, 0x53, 0x45, 0x52, 0x56, 0x49, 0x43, 0x45,
  0x5f, 0x4e, 0x41, 0x4d, 0x45, 0x25, 0x5d, 0x49, 0x6d, 0x70, 0x6c, 0x20,
  0x65, 0x78, 0x74, 0x65, 0x6e, 0x64, 0x73, 0x20, 0x41, 0x62, 0x73, 0x74,
  0x72, 0x61, 0x63, 0x74, 0x5b, 0x25, 0x53, 0x45, 0x52, 0x56, 0x49, 0x43,
  0x45, 0x5f, 0x4e, 0x41, 0x4d, 0x45, 0x25, 0x5d, 0x53, 0x65, 0x72, 0x76,
  0x69, 0x63, 0x65, 0x20, 0x7b, 0x0a, 0x5b, 0x25, 0x4d, 0x45, 0x54, 0x48,
  0x4f, 0x44, 0x53, 0x25, 0x5d, 0x7d
};
unsigned int serverImplByteArray_len = 114;
std::string serverImplTmpStr(reinterpret_cast<char const *>(serverImplByteArray),
							         serverImplByteArray_len);
