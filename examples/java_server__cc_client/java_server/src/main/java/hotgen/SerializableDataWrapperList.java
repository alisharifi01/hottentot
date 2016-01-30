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

public class SerializableDataWrapperList {

  private List<DataWrapper> dataWrapperList;

  public SerializableDataWrapperList() {
    dataWrapperList = new ArrayList<DataWrapper>();
  }

  public List<DataWrapper> getDataWrapperList() {
    return dataWrapperList;
  }

  public void setDataWrapperList(List<DataWrapper> dataWrapperList) {
    this.dataWrapperList = dataWrapperList;
  }

  public byte[] serialize() {
    if (dataWrapperList.size() != 0) {
      int counter = 0;
      int dataLength = 0;
      //calculate serializedDataWrapperListLength
      for (DataWrapper dataWrapper : dataWrapperList) {
        byte[] serializedDataWrapper = dataWrapper.serialize();
        byte[] dataWrapperLengthByteArray =
          DataLengthByteArrayMaker.getByteArray(serializedDataWrapper.length);
        dataLength += dataWrapperLengthByteArray.length + serializedDataWrapper.length;
      }
      byte[] serializedDataWrapperList = new byte[dataLength];
      for (DataWrapper dataWrapper : dataWrapperList) {
        byte[] serializedDataWrapper = dataWrapper.serialize();
        int serializedDataWrapperLength = serializedDataWrapper.length;
        byte[] dataWrapperLengthByteArray =
          DataLengthByteArrayMaker.getByteArray(serializedDataWrapperLength);
        System.arraycopy(dataWrapperLengthByteArray, 0, serializedDataWrapperList, counter, dataWrapperLengthByteArray.length);
        counter += dataWrapperLengthByteArray.length;
        System.arraycopy(serializedDataWrapper, 0, serializedDataWrapperList, counter, serializedDataWrapper.length);
        counter += serializedDataWrapper.length;
      }
      return serializedDataWrapperList;
    }
    return new byte[0];
  }

  public void deserialize(byte[] serializedDataWrapperList) {
    if(serializedDataWrapperList.length != 0){
      int counter = 0;
      int serializedDataWrapperByteArrayLength = 0 ;
      while (true) {
        if (counter == serializedDataWrapperList.length) {
          break;
        }
        int firstLengthByte = serializedDataWrapperList[counter];
        int numOfByteForLength = 1;
        if ((firstLengthByte & 0x80) == 0) {
          serializedDataWrapperByteArrayLength = serializedDataWrapperList[counter];
        } else {
          counter++;
          numOfByteForLength = firstLengthByte & 0x0f;
          byte[] serializedDataWrapperLengthByteArray = new byte[numOfByteForLength];
          int serializedDataWrapperLengthByteArrayCounter = 0;
          for (int i = counter; i < counter + numOfByteForLength; i++) {
            serializedDataWrapperLengthByteArray[serializedDataWrapperLengthByteArrayCounter++] = serializedDataWrapperList[i];
          }
          serializedDataWrapperByteArrayLength = ByteArrayToInteger.getInt(serializedDataWrapperLengthByteArray);
        }
        counter += numOfByteForLength;
        byte[] dataWrapperByteArray = new byte[serializedDataWrapperByteArrayLength];
        int dataWrapperByteArrayCounter = 0;
        for (int i = counter; i < counter + serializedDataWrapperByteArrayLength; i++) {
          dataWrapperByteArray[dataWrapperByteArrayCounter++] = serializedDataWrapperList[i];
        }
        counter += serializedDataWrapperByteArrayLength;
        DataWrapper dataWrapper = new DataWrapper();
        dataWrapper.deserialize(dataWrapperByteArray);
        dataWrapperList.add(dataWrapper);
      }
    }
  }
}