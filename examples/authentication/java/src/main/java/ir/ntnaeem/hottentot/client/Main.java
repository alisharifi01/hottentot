/*  The MIT License (MIT)
 *
 *  Copyright (c) 2015 Noavaran Tejarat Gostar NAEEM Co.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

package ir.ntnaeem.hottentot.client;


import ir.ntnaeem.hottentot.generated.AuthenticationService;
import ir.ntnaeem.hottentot.generated.Credential;
import ir.ntnaeem.hottentot.generated.Token;
import ir.ntnaeem.hottentot.generated.proxy.AuthenticationServiceProxyBuilder;
import ir.ntnaeem.hottentot.runtime.exception.TcpClientConnectException;
import ir.ntnaeem.hottentot.runtime.exception.TcpClientReadException;
import ir.ntnaeem.hottentot.runtime.exception.TcpClientWriteException;

public class Main {
    public static void main(String[] args) {
        AuthenticationService proxy = AuthenticationServiceProxyBuilder.create("127.0.0.1", 8000);
        Credential credential = new Credential();
        credential.setUsername("test");
        credential.setPassword("12345");
        try {
            Token token = proxy.authenticate(credential);
            System.out.println(token);
        } catch (TcpClientConnectException e) {
            e.printStackTrace();
        } catch (TcpClientWriteException e) {
            e.printStackTrace();
        } catch (TcpClientReadException e){
            e.printStackTrace();
        }
        AuthenticationServiceProxyBuilder.destroy();
    }
}