# paper

## 0. Abstract

Virtual network embedding (VNE), working as a key step for network virtualization, has recently gained intensive attentions from the research community.

In this paper, we propose a novel VNE algorithm that aims to maximize () from serving virtual network (VN) requests, with the help of the (GNT).

The proposed algorithm, named as VNE-GNT, adopts a node-ranking approach that takes the GNT information into account in a recursive manner to assist the greedy node mapping, and **leverages** the shortest-path routing for link mapping.

Our simulation results suggest that the proposed VNE-GNT algorithm outperforms three existing VNE algorithms, in the terms of () and ().

Index Terms: Network Virtualization, Virtual Network Embedding(VNE), PageRank, Node Ranking, GNT

## 1. INTRODUCTION

(背景, 网络环境现状, 虚拟化, )

Recently, Internet has been growing exponentially with larger number of nodes and end-users, higher volume of traffic, and more varieties of applications.

(提出问题, 并给出解决方法: 虚拟化)To this end, people rely on the network virtualization [4–6] to change how Internet is operated and to make it more elastic. Network virtualization helps to provision multiple virtual networks (VNs) over a substrate (or physical) network and enables seamlessly sharing of the computing and networking resources in the substrate network [4].

(VNE问题, NP-hard)

Typically, a VN consists of a set of virtual nodes (e.g., virtual routers) and a few virtual links that connect them.

The best interest of the InPs is to achieve as much revenue as possible from serving the VN requests. Hence, they need to decide how to serve a VN request by allocating appropriate resources in the substrate network, i.e., virtual network embedding (VNE). Specifically, for each VN request, the InP needs to find a set of nodes and links in the substrate network, which have sufficient resources to carry the virtual nodes and virtual links. The VNE problem has been proven to be NP-hard [7], and previous researches have proposed several heuristic algorithms to address it [8–13].

(别人的方法, 分类, 目前还存在的问题)

Most of these algorithms performed node mapping based on the local resource information (i.e., the nodes’ resources or the nodes’ resources together with their incident links’ resources). However, this type of approach could easily result in unbalanced load distribution and congestion in the substrate network. Two recent works in [12, 13] took global resource information into consideration in the node mapping, while the algorithms only adopted over-simplified metrics to measure the embedding capacities of the nodes and did not fully explore the benefit of the global resource information.

(怎么做的, 实验效果怎样)

In this paper, we propose a novel VNE-GNT algorithm to help () with the assistance of the (GNT information).

While serving the VN requests, the proposed VNE-GNT algorithm adopts a node rank, similar to the PageRank in web-search algorithm`14`, to rank nodes according to their (CPU bandwidth GNT resources).

We then implement greedy node mapping based on the node ranks, and when node mapping is accomplished, link mapping is performed with the shortest-path routing algorithm.

Simulation results show that the proposed VNE-GNT algorithm outperforms three existing VNE algorithms that also use the global resource information, in terms of acceptance and revenue.

(文章结构)

The rest of this paper is organized as follows. We formulate the VNE problem in Section 11. The details of the proposed VN-GNT algorithm are discussed in Section 11. Section 11 shows the simulation setup and results for the performance evaluation. Finally, Section 11 summarizes the paper.

## 2. VNE PROBLEM FORMULATION

### A. VNE Models

- Substrate network: We model the substrate network as an undirected graph, denoted as $G^s = (N_s, L_s,)$, where $N_s$ is the set of substrate nodes and $L_s$ is the set of substrate links.

We denote the available computing resource(e.g. CPU) of node $n_s \in N_s$, and available bandwidth of link $l_s \in L_s$, as $c_n$ and $b_l$, respectively.

$P_l$ is the set of (acyclic paths) in $G_s$.

An example of a substrate network is illustrated if (Fig.1 a), where the numbers around the nodes and links are their available resources.

- Virtual network: We use notation $G_v$ to denote a virtual network(VN) request, whose topology can also be modeled as an undirected graph, where $N_v$ is the set of virtual nodes and $L_v$ is the set of virtual links.

Each virtual node $n_v \in N_v$ is associated with a computing resource demand of $c_v$ and each virtual link $l_v \in L_v$ has a bandwidth demand of $b_l$.

(Fig. 1 b) illustrates a VN request.

Each VN request is also associated with two tie-domain parameters, i.e., $a$ for the arrival time and $b$ for its lifetime.

The notations are summarized in `Table 1`

### B. VNE Process (映射过程以及约束条件)

The VNE process, as illustrated in `Fig. 1`, consists of three key steps, i.e., node ranking, node mapping and link mapping.

- 1. node ranking:
  
ok

- 2. node mapping:
  
The InP finds, for each virtual node from the VN request, q unique substrate node that has enough available computing resource to meet its computing resource demand, through a mapping, i.e., $F_N: N_v \rightarrow N_s$, such that, 

$$F_N(n_v) = v_s$$

under the following two constraints:

For example, as shown in `Fig. 1`, the node mapping for the VN request is ${1 \rightarrow D, 2 \rightarrow C, ...}$.

- 3. link mapping
  
For two adjacent nodes in the VN request, the InP finds one or more paths between the two mapped substrate nodes, and the total bandwidth of the path(s) should be larger than the corresponding virtual link bandwidth demand.

Specifically, the mapping if $F_L: L_v \rightarrow L_s$, such that,

$$F_L(l_v) = l_s$$

under the following capacity constraints, i.e.,

$$b_l \le B_L$$

where $B_L$ is the total available bandwidth of path set $F_l$.

For example, as shown in `Fig. 1`, the link mapping for the VN request is ${(1, 2) \rightarrow (D, C), ..., }$.

### C. VNE Revenue Model (评价指标)

In this paper

The revenue of the given VN request is defined as the summation of contributions from the computing resource demand and the bandwidth demand.

$$R_v = \alpha \sum {cpu} + \beta \sum {bandwidth}$$

where $\alpha$ and $beta$ are the unit price charged for computing resources and bandwidth resources, respectively.

## 3. VNE-GNT algorithm

In this section, we propose a novel VNE algorithm.

The algorithm implements (a PageRank-like node-ranking) approach based on the (global resource information) and then performs node mapping according to the ranks of the nodes. After node mapping, the shortest-path-based link mapping follows.

We refer this algorithm as GNT-driven VNE (VNE-GNT) algorithm, for it aims to maximize the InP's revenue by accepting as many as possible VN requests under the resource limitation of its substrate network.

### A. Node Ranking

For the node mapping, we adopt a novel ranking approach, similar to the PageRank algorithm.

### B. Node Mapping

In the VNE-GNT algorithm, the node mapping works as follows in a greedy way.

First, we backup the status of the substrate network, and then sorts the nodes of both the substrate network and the VN request in descending order according to the node-rank vectors calculated by `algorithm node rank`.

As the value of the node rank indicates the embedding capacity of the corresponding node.

Thus, the virtual node with the highest node rank among the remaining ones will always embed onto the substrate node that also has the highest node rank among the remaining substrate ones, whose available computing resource meets the demand.

if the computing resource demand cannot be satisfied by any of the remaining substrate nodes, the VN request is marked as `blocked`, and if all virtual nodes ars embedded successfully, the computing resource of the corresponding substrate bodes would be updated.

The details of the greedy node mapping algorithm are shown in `algorithm 2`.

The complexity of this algorithm is $O(|N_s||N_v|)$

### C. Shortest-Path-based Link Mapping

For link mapping, Similar to previous works `[11, 12]`, we apply the shortest-path routing algorithm, which aims to minimize the total substrate bandwidth allocated to each virtual link.

Specifically, we embed the virtual links of the VN request one by one, and for each virtual link, we adopt the Dijkstra's algorithm to find the shortest path between the two corresponding nodes in the substrate network.

What's more, to improve the efficiency of the algorithm, we propose (), which pre-cuts all substrate links in the substrate network that do not have enough bandwidth for the corresponding virtual link.

if any virtual link of the VN request mapping fails, we restore the status of the substrate network and mark the VN request as `blocked`.

`algorithm 3` describes the details of the shortest-path-based link mapping algorithm.

The complexity of this algorithm is $O(|E_v||E_s|\log {|E_s|})$

### D. Time Complexity

The time Complexity of the proposed VNE-GNT algorithm can be calculated by adding up the complexities of its three steps, i.e. node ranking, node mapping and link mapping.

Hence, we determine that its time complexity is $O(\max {1, 2})$

## 4. PERFORMANCE EVALUATION

### A. Simulation Setup

To evaluate the proposed VNE-GNT algorithm, we perform extensive simulations with a substrate topology that is randomly generated by the GT_ITM tool `reference`.

The topologies of the VN requests are also randomly generated by the GT_ITM tool.

For each VN request, the computing resource demand and the bandwidth demand are uniformly distributed within the ranges shown in `Table 1`

`Table 2` shows the simulation parameters.

### B. Performance Comparisons

In this subsection, we compare the performance of our proposed VNE-GNT algorithm with three existing VNE algorithms, i.e. the VNE-DCC `reference`, the RW-BFS `reference` and the VNE-SP algorithm `reference`.

For all simulations, we set: $\alpha = \beta = 1, \zeta = 0.00001$ and $d = 0.85$.
