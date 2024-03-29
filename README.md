# LoRa Network Topology - Routing Table

This project extends the implementation of [royyandzakiy/LoRa-simple-send-recv](https://github.com/royyandzakiy/LoRa-simple-send-recv), for further details, please refer directly to it

This Routing Table is a simple array of Routing, which will then be able to be printed or sent as a json object. This project DOES NOT aim to be able to forward messages, nor create new routes. It simply helps update the link strength (RSSI), to help **present the whole topology of the network**. The Routing Table is hardcoded to having N_NODES size (currently 4, but you may change this number to any number you wish). It does not change in size, when initiated for the first time, the Routing Table will be filled with Routing of `n` = 0, and `r` = 0, multiplied to an N_NODE sized array. This Routing will then be expected to get updated along the way, through exchange of messages among other NODES that are concurrently active. Hence, this topology will always get updated, and you can periodically see the change in RSSI among nodes by printing the Routing Table with `RoutingTable::print()`, or through other means (you can send the RoutingTable through mqtt and create a live visualization of it using the provided `json`).

### Routing Table
The Routing table is the main component here, it is based upon Routing which is a simple data structure consisting of `r` and `n`
- `n`: target node. defined as an `int`, leading to the address defined as `NODEID`
- `r`: rssi. what is the link strength from this node to the target node? [what is rssi?](https://www.sonicwall.com/support/knowledge-base/wireless-snr-rssi-and-noise-basics-of-wireless-troubleshooting/180314090744170/#:~:text=RSSI%20(Received%20Signal%20Strength%20Indicator,they%20just%20call%20it%20Signal.)

- in case of there might be a `Routing` to its self, then the default value of `n` is `255`. this prevents storing an address to self, because this is unpresentable through the expected json that will be generated using RoutingTable::get_to_string()