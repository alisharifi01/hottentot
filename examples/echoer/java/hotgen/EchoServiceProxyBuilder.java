/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   
 ******************************************************************/
package ir.ntnaeem.hottentot.examples.echoer.hotgen;

public class EchoServiceProxyBuilder {

  public static EchoService create(String host, int port) {
    return new EchoServiceProxy(host,port);
  }

  public static void destroy() {
    //TODO
  }
}
