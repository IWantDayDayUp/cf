# paper

---

## 0. Abstract

Virtual network embedding (VNE), working as a key step for network virtualization, has recently gained intensive attentions from the research community.

In this paper, we propose a novel VNE algorithm that aims to maximize () from serving virtual network (VN) requests, with the help of the (GNT).

The proposed algorithm, named as VNE-GNT, adopts a node-ranking approach that takes the GNT information into account in a recursive manner to assist the greedy node mapping, and **leverages** the shortest-path routing for link mapping.

Our simulation results suggest that the proposed VNE-GNT algorithm outperforms three existing VNE algorithms, in the terms of () and ().

Index Terms: Network Virtualization, Virtual Network Embedding(VNE), PageRank, Node Ranking, GNT

---

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

---

## 2. VNE PROBLEM FORMULATION

This part of the paper gives a universal description of VNE, its procedures, along with the performance metrics.

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

### C. Performance Metrics (评价指标)

- VNR Acceptance Ratio: The long-term average acceptance ratio of arrival VNR(virtual network request) is given by following function:

$$accept = \lim_{T \rightarrow \infty} {\frac{num_{success}}{num_{total}}}$$

where $num_{success}$ represents total number of accepted virtual network requests and $num_{total}$ corresponds to total number of arrival VNRs in the time window $T$.

- Long-Term Average Revenue: Long-term average revenue in the time $T$ is given by following function:

$$Rve = \lim_{T \rightarrow \infty} {\frac{\sum_{t=1}^{t=T}{Rev(t)}}{T}}$$

where $Rev(t)$ represents the revenue of accepting the VNRs at time $t$ which is defined as follows:

$$Rev(t) = \alpha \sum_{n_v \ in N_v}{CPU(n_v)} + \beta \sum_{l_v \in L_v}{bandwidth(l_v)}$$

where $CPU(n_v)$ represents CPU resource demand of a virtual node $n_v$, $bandwidth(l_v)$ represents bandwidth demand of virtual link $l_v$. $N_v$ represents the set of all virtual nodes and $L_v$ represents the set of all virtual links of the $VNR_i$.

- Long-Term Average Revenue to Cost(R/C) Ratio: The long term average R/C ratio is given by:

$$R/C = \frac{Rev(G_v)}{Cost(G_v)} = \frac{\lim_{T \rightarrow \infty}{\sum_{t=0}^{t=T}{Rev(G_v, t)}}}{\lim_{T \rightarrow \infty}{\sum_{t=0}^{t=T}{Cost(G_v, t)}}}$$

where $Cost(G_v, t)$ is the accepting cost of $VNR_i$ at time frame $t$. $Cost(G_v, t)$ is defined as:

$$Cost(G_v, t) = \alpha \sum_{n_v \in N_v}{CPU(n_v)} + \beta \sum_{l_v \in L_v}{\sum_{p \in P_s(l_v)}{hops(p) bandwidth(l_v)}}$$

where parameters $\alpha$ and $\beta$ are the weighting parameters of node and link resources respectively, both are set to 1 in this paper. $P_s(l_v)$ is combined assigned pathset for virtual link $l_v$; $hops(p)$ for the path number p$p$ are the number of hops elapsed on the substrate network.

The revenue of the given VN request is defined as the summation of contributions from the computing resource demand and the bandwidth demand.

$$R_v = \alpha \sum {cpu} + \beta \sum {bandwidth}$$

where $\alpha$ and $beta$ are the unit price charged for computing resources and bandwidth resources, respectively.

---

## 3. VNE-GNT algorithm

In this section, we propose a novel VNE algorithm.

The algorithm implements (a PageRank-like node-ranking) approach based on the (global resource information) and then performs node mapping according to the ranks of the nodes. After node mapping, the shortest-path-based link mapping follows.

We refer this algorithm as GNT-driven VNE (VNE-GNT) algorithm, for it aims to maximize the InP's revenue by accepting as many as possible VN requests under the resource limitation of its substrate network.

### A. Node Ranking

For the node mapping, we adopt a novel ranking approach, similar to the PageRank algorithm.

> Through this importance index formulate we are rangking the substrate nodes before mapping. The higher the importance index the higher will be the rank and that node is considered first for node mapping with the virtual node of arrival VNR.

### B. Node Mapping

In the VNE-GNT algorithm, the node mapping works as follows in `a greedy way`.

> The goal is to allocate the virtual nodes with more significant requirements to the substrate node with more significant resources. Then the process moves to the next stage of virtual link mapping, which is defined in the next subsection.

First, we backup the status of the substrate network, and then sorts the nodes of both the substrate network and the VN request in descending order according to the node-rank vectors calculated by `algorithm node rank`.

As the value of the node rank indicates the embedding capacity of the corresponding node.

Thus, the virtual node with the highest node rank among the remaining ones will always embed onto the substrate node that also has the highest node rank among the remaining substrate ones, whose available computing resource meets the demand.

if the computing resource demand cannot be satisfied by any of the remaining substrate nodes, the VN request is marked as `blocked`(rejected), and if all virtual nodes ars embedded successfully, the computing resource of the corresponding substrate bodes would be updated.

> If the CPU capacity of selected node cannot meet the required demand of any virtual node of $VNR_i$, then the request can be rejected(Step 13).
>
> If every virtual node of the $VNR_i$ are mapped favorably, the CPU capacity of SN is further updated for the next VNR.

The details of the greedy node mapping algorithm are shown in `algorithm 2`.

> The status of the whole network is backed-up on the arrival of $VNR_i$.

```markdown

Node Mapping Algorithm

**Input**: Arrived Set of VNRs.
**Output**: Node Mapping Result.

**While** There is numapped virtual node $n_v$ in $VNR_i$ **do**:
    <!-- 1. re-sort substrate nodes -->

**end while**
```

The complexity of this algorithm is $O(|N_s||N_v|)$

### C. Shortest-Path-based Link Mapping

For link mapping, Similar to previous works `[11, 12]`, we apply the shortest-path routing algorithm, which aims to minimize the total substrate bandwidth allocated to each virtual link.

Specifically, we embed the virtual links of the VN request one by one, and for each virtual link, we adopt the Dijkstra's algorithm to find the shortest path between the two corresponding nodes in the substrate network.

What's more, to improve the efficiency of the algorithm, we propose (), which pre-cuts all substrate links in the substrate network that do not have enough bandwidth for the corresponding virtual link.

if any virtual link of the VN request mapping fails, we restore the status of the substrate network and mark the VN request as `blocked`.

`algorithm 3` describes the details of the shortest-path-based link mapping algorithm.

```markdown

Link Mapping Algorithm

**if** virtual node mapping of $VNR_i$ is succeded **then**:
    **for** each numapped virtual link $l$ in $VNR_i$ **do**:
        <!-- 1. 删掉
        2. Dijkstra -->
        **if** find a link **then**:
            Map the link $l$
        **else**:
            Reject $VNR_i$
        **end if**
    **end for**
**end for**

```

The complexity of this algorithm is $O(|E_v||E_s|\log {|E_s|})$

### D. Our Proposed Algorithm

$11111$

### E. Time Complexity

The time Complexity of the proposed VNE-GNT algorithm can be calculated by adding up the complexities of its three steps, i.e. node ranking, node mapping and link mapping.

- The time complexity of the node ranking stage is $O(|N_v|^2)$, where $|N_v|$ represents the number of virtual nodes in each VN request.
- The time complexity of the node mapping stage:
- The time complexity of the node mapping stage:

Hence, we determine that its time complexity is $O(\max {1, 2})$

---

## 5. PERFORMANCE EVALUATION

In this section, the simulation environment settings, the performance comparisons and the simulation results are discussed.

> This section introduces the simulation parameter settings. We select three heuristic algorithms to compare our results. Finally, we present our main simulation result.

~~This section presents the simulation parameter settings, in the form of tables. We use the (measurement index of performance metrics) which proposed in section 2.4 to evaluate our VNE-GNT algorithm. Two state-of-the-art algorithms which called as Greedy [24] and RW [7] are compared with our proposed algorithm, respectively. In this paper, we do not consider the case of supporting path splitting.~~

### A. Simulation Parameter Settings

We perform extensive simulations to evaluate the proposed VNE-GNT algorithm.

Similar to the previous literature [24], we use GT-ITM tool to generate the topology of the virtual network requests and substrate network.

`Table 2` summarizes the shared substrate network parameters and the VN parameters for our simulation. These parameters are typical in the VNE research area.

(具体的参数描述)

Simulations run for about 150 000 time units.

$\alpha, \beta, \gamma$ and $\delta$ in `公式` are all set to be $1$.

$\delta$ in node-ranking approach(Algorithm 1) is set to be $0.00001$`文献`

The value of $d$ in this paper is set to be $0.85$, same to the value setting in the PageRank algorithm.

All simulations run on a Windows 11 desktop, with an Intel Core CPU i7-4790@3.6GHZ processor and a 16.00G RAM Machine.

### B. Performance Comparisons

In this subsection, we compare the performance of our proposed VNE-GNT algorithm with three existing VNE algorithms, i.e. the VNE-DCC `reference`, the RW-BFS `reference` and the VNE-SP algorithm `reference`. In this paper, we do not consider the case of supporting path splitting.

The description of each algorithm used for comparisons is shown in `Table 2`.

~~Besides our proposed VNE-NTANRC-D and VNE-NTANRC-S, remaining algorithms are G-SP [16], RW-SP [17], VNE-DCC [20], VNE-RD [21], and VNE-NRM [23].~~

~~For all simulations, we set: $\alpha = \beta = 1, \zeta = 0.00001$ and $d = 0.85$.~~

### C. Simulation Results

This Section presents the main simulation results. `Fig. 1` presents the average VNR acceptance ratio as a function of time, while `Fig. 2` shows the average revenue to cost ratio as a function of time.

Both figures (`Fig. 1` and `Fig. 2`) aim to directly prove the efficiency and effectiveness of VNE-GNT in the long term.

- Average VNR Acceptance Ratio:

> the main reason is that all of our compared three algorithms are based on node ranking methods, the bigger the CPU capacity requirement is, the more effective the
algorithms are.
>
> we found that the available CPU capacity of substrate nodes and the available bandwidth capacity of the substrate links are gradually reducing with the number of virtual network requests (VNRs) which have been successfully mapped increases during the mapping process, the remained network resources that can be mapped are gradually decreased with the mapping process, the acceptance ratio will be decreasing with the changing.

() `Fig.1` is the average VNR acceptance ratio as a function of continuous time.

The VNR acceptance ratio is an important metric to evaluate the mapping abilities of different VNE algorithms.

As observed in `Fig.`1`, the average VNR acceptance ratio of all algorithms almost decays with the variation on time. This decay shows that there are no infinite substrate resources for embedding more and more VNRs.

In addition, the algorithm we proposed outperforms all selected heuristics, it runs as expected because the VNE-GNT takes () and () into account simultaneously.

Through using the iterative approach, a stable node-ranking values can be achieved, The relationship of each node with all other nodes is fully explored, benefiting the following greedy node mapping.

- Average Revenue to Cost Ratio:

`Fig.4` illustrates the average revenue to cost ratio as a function of time.

(总体趋势, 随着时间流逝慢慢降低, 并分析原因)

Derived from `Fig.5`, the average revenue to cost ratio of all selected algorithms decreases with the simulation time increasing.

(劣势+原因)

To G-SP, the reason for lowest revenue to cost ratio contributes to the fact that adjacent virtual nodes are mapped onto substrate nodes, far from each other. This leads to a large amount of unnecessary substrate resource consumption.

(优势+原因)

It is owing to that multiple topology attributes and global network resources are considered in VNE-GNT algorithm simultaneously.

More extra substrate resources are saved.

(总结)

Through conducting the simulation, it is apparent that the novel node-ranking approach of VNE-GNT further ensures the efficiency of substrate network resource usage in the long run.

- Average Node and Link Utilization:

Average node and link utilization as a function of time are depicted in `Fig. 5` and `Fig. 5`

(总体趋势)

> As we can observe from `Fig. 1` that our algorithm VNE-GNT outperforms other three algorithms with reapect to revenue-to-cost ratio.

(), with the number of VNRs increasing, the node and link utilization of all selected algorithms increase, too.

(个别优势/劣势, 并分析原因)

To the node utilization, depicted in `Fig.5`, the VNE-GNT(-香浓, -瑞丽, -T) has an apparent advantage over the remaining heuristic algorithms. The reason for (VNE-GNT algorithm having a larger node utilization than the other algorithms) lies to VNE-GNT's ability of accepting more VNRs than the other heuristics, considering more (network attributes) before the node mapping stage.

However, as shown in `Fig.5`, the link utilization does not have the same behavior for all algorithms.

## 6. CONCLUSION

(背景)

In the environment of network virtualization, virtual network embedding is one of the most challenging task aim to address the issue of network ossification.

(这篇文章做了什么)

We use the node degree and clustering coefficient information to improve the metric of nodes importance.

Based on the metric of node importance, we proposed a novel two-stage algorithm called VNE-DCC and performed extensive simulations to validate our proposed algorithm. Extensive experiments and results analysis have shown that our proposed algorithm improves the performance of VN embedding procedure in terms of R/C ratio and acceptance ratio, as well as decreases the scaling factor

(优点)

The merits of the provided algorithm is as follows:

(i) The proposed algorithm presents a comprehensive metric of node importance named NIM to measure the embedding potential of substrate nodes.

(ii) The proposed algorithm uses the breadth-first-search algorithm to embed the virtual nodes aims at reducing the bandwidth utilization of substrate links.

The demerits of the provided algorithm are as follows:

(i) The proposed algorithm considered the VN embedding as two separated procedures which would lead to lower acceptance ratio due to improper node mapping results.

(ii) The proposed node importance metric does not consider the multiple features of the substrate nodes, hence the node ranking method can be further improved by means of other features of substrate nodes.

(未来计划)
There are still some issues which should be further investigated.

We focus mainly on the improvement of measurement of node importance, the improvement of the link mapping algorithm is seldom considered. We should further
optimize the link mapping stage to enhance the efficiency of virtual network embedding algorithm.
