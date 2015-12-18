s.graph.addNode({size: 2, id: "1", label: "1", x: "23", y: "3"});
s.graph.addNode({size: 2, id: "2", label: "2", x: "16", y: "7"});
// #commentaire
s.graph.addNode({size: 2, id: "3", label: "3", x: "16", y: "3"});
s.graph.addNode({size: 2, id: "4", label: "4", x: "16", y: "5"});
s.graph.addNode({size: 2, id: "5", label: "5", x: "9", y: "3"});
s.graph.addNode({size: 2, id: "6", label: "6", x: "1", y: "5"});
s.graph.addNode({size: 2, id: "7", label: "7", x: "4", y: "8"});
s.graph.addNode({size: 2, id: "0", label: "0", x: "9", y: "5"});
s.graph.addEdge({id: "0_4", source: "0", target: "4"});
s.graph.addEdge({id: "0_6", source: "0", target: "6"});
s.graph.addEdge({id: "1_3", source: "1", target: "3"});
s.graph.addEdge({id: "4_3", source: "4", target: "3"});
s.graph.addEdge({id: "5_2", source: "5", target: "2"});
s.graph.addEdge({id: "3_5", source: "3", target: "5"});
// #autre commentaire
s.graph.addEdge({id: "4_2", source: "4", target: "2"});
s.graph.addEdge({id: "2_1", source: "2", target: "1"});
s.graph.addEdge({id: "7_6", source: "7", target: "6"});
s.graph.addEdge({id: "7_2", source: "7", target: "2"});
s.graph.addEdge({id: "7_4", source: "7", target: "4"});
s.graph.addEdge({id: "6_5", source: "6", target: "5"});
s.refresh();
// L0-2
// L0-4
// L0-0
// L1-2
// L1-4
// L1-0
