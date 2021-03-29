Per compilare, siccome stiamo utilizzando delle librerie dei thread, dobbiamo specificare che stiamo usando la versione del c++ 11, altrimenti alcune funzioni dei thread non funzionano:

g++ multi_server.cpp -o multi_server -std=c++11
