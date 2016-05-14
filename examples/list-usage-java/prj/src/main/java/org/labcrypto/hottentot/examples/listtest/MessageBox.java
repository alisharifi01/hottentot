/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   This file contains definition of an abstract service class.
 ******************************************************************/
package org.labcrypto.hottentot.examples.listtest;

import java.util.*;

import org.labcrypto.hottentot.helper.PDTSerializer;
import org.labcrypto.hottentot.helper.PDTDeserializer;
import org.labcrypto.hottentot.helper.ByteArrayToInteger;


public class MessageBox {
  private String value = "";
  private List<String> xList = new ArrayList<String>();
  private List<Byte> yList = new ArrayList<Byte>();
  private List<Boolean> zList = new ArrayList<Boolean>();
  private List<Test> testList = new ArrayList<Test>();
  private byte[] imageInBytes;
  public void setValue(String value) {
    this.value = value;
  }
  public String getValue() {
    return value;
  }
  public void setXList(List<String> xList) {
    this.xList = xList;
  }
  public List<String> getXList() {
    return xList;
  }
  public void setYList(List<Byte> yList) {
    this.yList = yList;
  }
  public List<Byte> getYList() {
    return yList;
  }
  public void setZList(List<Boolean> zList) {
    this.zList = zList;
  }
  public List<Boolean> getZList() {
    return zList;
  }
  public void setTestList(List<Test> testList) {
    this.testList = testList;
  }
  public List<Test> getTestList() {
    return testList;
  }
  public void setImageInBytes(byte[] imageInBytes) {
    this.imageInBytes = imageInBytes;
  }
  public byte[] getImageInBytes() {
    return imageInBytes;
  }
  @Override 
  public String toString() { 
    return "MessageBox{" + 
      "value = '" + value + '\'' + 
      ",xList = '" + xList + '\'' + 
      ",yList = '" + yList + '\'' + 
      ",zList = '" + zList + '\'' + 
      ",testList = '" + testList + '\'' + 
      ",imageInBytes = '" + imageInBytes + '\'' + 
      "}"; 
  }
	
  public byte[] serialize() {
    byte[] serializedValue = PDTSerializer.getString(value);
    SerializableStringList serializableStringList2 = new SerializableStringList();
    serializableStringList2.setStringList(xList);
    byte[] serializedXList  = serializableStringList2.serializeWithLength();
    SerializableUint8List serializableUint8List3 = new SerializableUint8List();
    serializableUint8List3.setUint8List(yList);
    byte[] serializedYList  = serializableUint8List3.serializeWithLength();
    SerializableBoolList serializableBoolList4 = new SerializableBoolList();
    serializableBoolList4.setBoolList(zList);
    byte[] serializedZList  = serializableBoolList4.serializeWithLength();
    SerializableTestList serializableTestList5 = new SerializableTestList();
    serializableTestList5.setTestList(testList);
    byte[] serializedTestList  = serializableTestList5.serializeWithLength();
    byte[] serializedImageInBytes = PDTSerializer.getData(imageInBytes);
    byte[] output = new byte[serializedValue.length + serializedXList.length + serializedYList.length + serializedZList.length + serializedTestList.length + serializedImageInBytes.length];
    int counter = 0;
    //use a loop for every property
    for (int i = 0; i < serializedValue.length; i++) {
      output[counter++] = serializedValue[i];
    }
    for (int i = 0; i < serializedXList.length; i++) {
      output[counter++] = serializedXList[i];
    }
    for (int i = 0; i < serializedYList.length; i++) {
      output[counter++] = serializedYList[i];
    }
    for (int i = 0; i < serializedZList.length; i++) {
      output[counter++] = serializedZList[i];
    }
    for (int i = 0; i < serializedTestList.length; i++) {
      output[counter++] = serializedTestList[i];
    }
    for (int i = 0; i < serializedImageInBytes.length; i++) {
      output[counter++] = serializedImageInBytes[i];
    }
    return output;
  }
    
  public void deserialize(byte[] serializedByteArray) {
    if(serializedByteArray.length != 0){
      int counter = 0;
      int dataLength = 0;
      int numbersOfBytesForDataLength;
      //do for every property
    //value : String
    dataLength = 0;
    if (( serializedByteArray[counter] & 0x80) == 0 ) {
      dataLength = serializedByteArray[counter++];
    } else {
      numbersOfBytesForDataLength = serializedByteArray[counter++] & 0x0f;
      byte[] serializedByteArrayLength = new byte[numbersOfBytesForDataLength];
      for (byte i = 0; i < numbersOfBytesForDataLength; i++) {
        serializedByteArrayLength[i] = serializedByteArray[counter++];
      }
      dataLength = ByteArrayToInteger.getInt(serializedByteArrayLength);
    }
    byte[] valueByteArray = new byte[dataLength];
    System.arraycopy(serializedByteArray,counter,valueByteArray,0,dataLength);
    counter += dataLength;
    setValue(PDTDeserializer.getString(valueByteArray));
    //xList : List<String>
    dataLength = 0;
    if (( serializedByteArray[counter] & 0x80) == 0 ) {
      dataLength = serializedByteArray[counter++];
    } else {
      numbersOfBytesForDataLength = serializedByteArray[counter++] & 0x0f;
      byte[] serializedByteArrayLength = new byte[numbersOfBytesForDataLength];
      for (byte i = 0; i < numbersOfBytesForDataLength; i++) {
        serializedByteArrayLength[i] = serializedByteArray[counter++];
      }
      dataLength = ByteArrayToInteger.getInt(serializedByteArrayLength);
    }
    byte[] xListByteArray = new byte[dataLength];
    System.arraycopy(serializedByteArray,counter,xListByteArray,0,dataLength);
    counter += dataLength;
    SerializableStringList serializableStringList1 = new SerializableStringList();
    serializableStringList1.deserialize(xListByteArray);
    setXList(serializableStringList1.getStringList());
    //yList : List<Byte>
    dataLength = 0;
    if (( serializedByteArray[counter] & 0x80) == 0 ) {
      dataLength = serializedByteArray[counter++];
    } else {
      numbersOfBytesForDataLength = serializedByteArray[counter++] & 0x0f;
      byte[] serializedByteArrayLength = new byte[numbersOfBytesForDataLength];
      for (byte i = 0; i < numbersOfBytesForDataLength; i++) {
        serializedByteArrayLength[i] = serializedByteArray[counter++];
      }
      dataLength = ByteArrayToInteger.getInt(serializedByteArrayLength);
    }
    byte[] yListByteArray = new byte[dataLength];
    System.arraycopy(serializedByteArray,counter,yListByteArray,0,dataLength);
    counter += dataLength;
    SerializableUint8List serializableUint8List2 = new SerializableUint8List();
    serializableUint8List2.deserialize(yListByteArray);
    setYList(serializableUint8List2.getUint8List());
    //zList : List<Boolean>
    dataLength = 0;
    if (( serializedByteArray[counter] & 0x80) == 0 ) {
      dataLength = serializedByteArray[counter++];
    } else {
      numbersOfBytesForDataLength = serializedByteArray[counter++] & 0x0f;
      byte[] serializedByteArrayLength = new byte[numbersOfBytesForDataLength];
      for (byte i = 0; i < numbersOfBytesForDataLength; i++) {
        serializedByteArrayLength[i] = serializedByteArray[counter++];
      }
      dataLength = ByteArrayToInteger.getInt(serializedByteArrayLength);
    }
    byte[] zListByteArray = new byte[dataLength];
    System.arraycopy(serializedByteArray,counter,zListByteArray,0,dataLength);
    counter += dataLength;
    SerializableBoolList serializableBoolList3 = new SerializableBoolList();
    serializableBoolList3.deserialize(zListByteArray);
    setZList(serializableBoolList3.getBoolList());
    //testList : List<Test>
    dataLength = 0;
    if (( serializedByteArray[counter] & 0x80) == 0 ) {
      dataLength = serializedByteArray[counter++];
    } else {
      numbersOfBytesForDataLength = serializedByteArray[counter++] & 0x0f;
      byte[] serializedByteArrayLength = new byte[numbersOfBytesForDataLength];
      for (byte i = 0; i < numbersOfBytesForDataLength; i++) {
        serializedByteArrayLength[i] = serializedByteArray[counter++];
      }
      dataLength = ByteArrayToInteger.getInt(serializedByteArrayLength);
    }
    byte[] testListByteArray = new byte[dataLength];
    System.arraycopy(serializedByteArray,counter,testListByteArray,0,dataLength);
    counter += dataLength;
    SerializableTestList serializableTestList4 = new SerializableTestList();
    serializableTestList4.deserialize(testListByteArray);
    setTestList(serializableTestList4.getTestList());
    //imageInBytes : byte[]
    dataLength = 0;
    if (( serializedByteArray[counter] & 0x80) == 0 ) {
      dataLength = serializedByteArray[counter++];
    } else {
      numbersOfBytesForDataLength = serializedByteArray[counter++] & 0x0f;
      byte[] serializedByteArrayLength = new byte[numbersOfBytesForDataLength];
      for (byte i = 0; i < numbersOfBytesForDataLength; i++) {
        serializedByteArrayLength[i] = serializedByteArray[counter++];
      }
      dataLength = ByteArrayToInteger.getInt(serializedByteArrayLength);
    }
    byte[] imageInBytesByteArray = new byte[dataLength];
    System.arraycopy(serializedByteArray,counter,imageInBytesByteArray,0,dataLength);
    counter += dataLength;

    }
  }
}
