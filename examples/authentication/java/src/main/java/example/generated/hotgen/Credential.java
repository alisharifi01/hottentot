/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   This file contains definition of an abstract service class.
 ******************************************************************/
package example.generated.hotgen;

import ir.ntnaeem.hottentot.serializerHelper.PDTSerializer;
import ir.ntnaeem.hottentot.serializerHelper.PDTDeserializer;
import ir.ntnaeem.hottentot.serializerHelper.ByteArrayToInteger;

public class Credential {
  private String username = "";
  private String password = "";
  public void setUsername(String username) {
    this.username = username;
  }
  public String getUsername() {
    return username;
  }
  public void setPassword(String password) {
    this.password = password;
  }
  public String getPassword() {
    return password;
  }
  @Override 
  public String toString() { 
    return "Credential{" + 
      "username = '" + username + '\'' + 
      ",password = '" + password + '\'' + 
      "}"; 
  }
	
  public byte[] serialize() {
    byte[] serializedUsername = PDTSerializer.getString(username);
    byte[] serializedPassword = PDTSerializer.getString(password);
    byte[] output = new byte[serializedUsername.length + serializedPassword.length];
    int counter = 0;
    //use a loop for every property
    for (int i = 0; i < serializedUsername.length; i++) {
      output[counter++] = serializedUsername[i];
    }
    for (int i = 0; i < serializedPassword.length; i++) {
      output[counter++] = serializedPassword[i];
    }
    return output;
  }
    
  public void deserialize(byte[] serializedByteArray) {
    if(serializedByteArray.length != 0){
      int counter = 0;
      int dataLength = 0;
      int numbersOfBytesForDataLength;
      //do for every property
    //username : String
    dataLength = 0;
    if(( serializedByteArray[counter] & 0x80) == 0 ) {
      dataLength = serializedByteArray[counter++];
    }else{
      numbersOfBytesForDataLength = serializedByteArray[counter++] & 0x0f;
      byte[] serializedByteArrayLength = new byte[numbersOfBytesForDataLength];
      for(byte i = 0 ; i < numbersOfBytesForDataLength ; i++){
        serializedByteArrayLength[i] = serializedByteArray[counter++];
      }
      dataLength = ByteArrayToInteger.getInt(serializedByteArrayLength);
    }
    byte[] usernameByteArray = new byte[dataLength];
    System.arraycopy(serializedByteArray,counter,usernameByteArray,0,dataLength);
    counter += dataLength;
    setUsername(PDTDeserializer.getString(usernameByteArray));
    //password : String
    dataLength = 0;
    if(( serializedByteArray[counter] & 0x80) == 0 ) {
      dataLength = serializedByteArray[counter++];
    }else{
      numbersOfBytesForDataLength = serializedByteArray[counter++] & 0x0f;
      byte[] serializedByteArrayLength = new byte[numbersOfBytesForDataLength];
      for(byte i = 0 ; i < numbersOfBytesForDataLength ; i++){
        serializedByteArrayLength[i] = serializedByteArray[counter++];
      }
      dataLength = ByteArrayToInteger.getInt(serializedByteArrayLength);
    }
    byte[] passwordByteArray = new byte[dataLength];
    System.arraycopy(serializedByteArray,counter,passwordByteArray,0,dataLength);
    counter += dataLength;
    setPassword(PDTDeserializer.getString(passwordByteArray));

    }
  }
}
