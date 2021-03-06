#ifndef Datagram_h
#define Datagram_h

// #include "globals.h"

const int N_NODES = 3;
const int DATAGRAM_SIZE = 6;

class Datagram {
  // DATAGRAM FORMAT (string): "nodeId,hopFrom,rssi,alertStatus,counter,counter;" (nanti ganti counter dengan datetime)
  // DATAGRAM FORMAT (string): "nodeId,hopFrom,rssi,alertStatus,datetimeSent,datetimeReceived;" (nanti ganti counter dengan datetime)
  // DATAGRAM TABLE FORMAT (array): [ datagram[0], datagram[1], ... }
  // DATAGRAM FORMAT (JSON): {"hopFrom": hopFrom, "rssi": rssi, "alertStatus": alertStatus}
  // DATAGRAM TABLE FORMAT (json): { "nodeId": [datagram_nodeId1, datagram_nodeId2, ..., datagram_nodeIdN] }  

  /*
   * Note:
   * Datagram ini akan disimpan dalam sebuah DatagramTable. DatagramTable adalah sebuah
   * array of Datagram yang memiliki posisi tertentu, dan dibentuk sebagai berikut
   * Datagram[N_NODES], dimana N_NODES adalah jumlah maksimal NODE dalam suatu jaringan.
   * Datagram sangat erat kaitannya dengan nodeId tertentu, dan secara tidak langsung
   * akan tercatat tergantung dari posisinya di Array DatagramTable.
   * 
   * Maka, jika ada DatagramTable.datagrams[x], x adalah nodeId dari Datagram tersebut.
   * 
   * VARIABLES
   * nodeId = nodeId diri sendiri
   * hopFrom = hop/lompatan terdekat kepada suatu nodeId untuk bertemu dengan node ini
   * rssi = rssi value dari pengiriman terakhir
   * alertStatus = kondisi alarm pada node terkait, digunakan pada pendeteksian penebangan liar
   * datatime_sent = datatime datagram dikirimkan oleh node ybs
   * datatime_received = datatime datagram diterima nodeId ini
   */
   
  public:
    Datagram();
    Datagram(String, String, String, String, String, String);
    Datagram(String);
    void stringToStringArrayParser(String, String[DATAGRAM_SIZE]);
    void set(String, String, String, String, String, String);
    void set_from_string(String);
    String get_to_string();
    void print_to_string();
    
    String nodeId, hopFrom, rssi, alertStatus, datetimeSent, datetimeReceived;
};

#endif