/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date:
 * Name:
 * Description:
 ******************************************************************/
package hotgen;

import ir.ntnaeem.hottentot.serializerHelper.DataLengthByteArrayMaker;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import ir.ntnaeem.hottentot.serializerHelper.ByteArrayToInteger;

public class SerializableTokenList {

  private List<Token> tokenList;

  public SerializableTokenList() {
    tokenList = new ArrayList<Token>();
  }

  public List<Token> getTokenList() {
    return tokenList;
  }

  public void setTokenList(List<Token> tokenList) {
    this.tokenList = tokenList;
  }

  public byte[] serialize() {
    if (tokenList.size() != 0) {
      int counter = 0;
      int dataLength = 0;
      //calculate serializedTokenListLength
      for (Token token : tokenList) {
        byte[] serializedToken = token.serialize();
        byte[] tokenLengthByteArray =
          DataLengthByteArrayMaker.getByteArray(serializedToken.length);
        dataLength += tokenLengthByteArray.length + serializedToken.length;
      }
      byte[] serializedTokenList = new byte[dataLength];
      for (Token token : tokenList) {
        byte[] serializedToken = token.serialize();
        int serializedTokenLength = serializedToken.length;
        byte[] tokenLengthByteArray =
          DataLengthByteArrayMaker.getByteArray(serializedTokenLength);
        System.arraycopy(tokenLengthByteArray, 0, serializedTokenList, counter, tokenLengthByteArray.length);
        counter += tokenLengthByteArray.length;
        System.arraycopy(serializedToken, 0, serializedTokenList, counter, serializedToken.length);
        counter += serializedToken.length;
      }
      return serializedTokenList;
    }
    return new byte[0];
  }

  public void deserialize(byte[] serializedTokenList) {
    if(serializedTokenList.length != 0){
      int counter = 0;
      int serializedTokenByteArrayLength = 0 ;
      while (true) {
        if (counter == serializedTokenList.length) {
          break;
        }
        int firstLengthByte = serializedTokenList[counter];
        int numOfByteForLength = 1;
        if ((firstLengthByte & 0x80) == 0) {
          serializedTokenByteArrayLength = serializedTokenList[counter];
        } else {
          counter++;
          numOfByteForLength = firstLengthByte & 0x0f;
          byte[] serializedTokenLengthByteArray = new byte[numOfByteForLength];
          int serializedDataWrapperLengthByteArrayCounter = 0;
          for (int i = counter; i < counter + numOfByteForLength; i++) {
            serializedTokenLengthByteArray[serializedDataWrapperLengthByteArrayCounter++] = serializedTokenList[i];
          }
          serializedTokenByteArrayLength = ByteArrayToInteger.getInt(serializedTokenLengthByteArray);
        }
        counter += numOfByteForLength;
        byte[] tokenByteArray = new byte[serializedTokenByteArrayLength];
        int tokenByteArrayCounter = 0;
        for (int i = counter; i < counter + serializedTokenByteArrayLength; i++) {
          tokenByteArray[tokenByteArrayCounter++] = serializedTokenList[i];
        }
        counter += serializedTokenByteArrayLength;
        Token token = new Token();
        token.deserialize(tokenByteArray);
        tokenList.add(token);
      }
    }
  }
}