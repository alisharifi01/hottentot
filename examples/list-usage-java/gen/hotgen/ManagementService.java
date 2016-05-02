/******************************************************************
 * Generated by Hottentot JAVA Generator
 * Date: 
 * Name: 
 * Description:
 *   
 ******************************************************************/

package ir.ntnaeem.hottentot.examples.listtest.hotgen;

import ir.ntnaeem.hottentot.runtime.Service;
import java.util.List;

public interface ManagementService extends Service {
  boolean isCrawlerIdValid(long crawlerId);
  long startCrawler(Crawler crawler);
  void stopCrawler(long crawlerId);
  void pauseCrawler(long crawlerId);
  void resumeCrawler(long crawlerId);
  List<Crawler> getCrawlers();
  Crawler getCrawlerById(long crawlerId);
  String getStartURL(long crawlerId);
  List<String> getDomainList(long crawlerId);

}
