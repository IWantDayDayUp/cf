# paper

---

## 0. Abstract

Virtual network embedding (VNE), working as a key step for network virtualization, can map various virtual networks(VNs) onto the shared substrate network efficiently and effectively. Previous VNE algorithms are mostly heuristic which assists the topology attributes and the locally available network resources to rank nodes, leading to a low acceptance rate and inefficient resource utilization in the long term. In addition, such methods focus on maximizing the possibility of the current virtual network being accepted, ignoring the synergy between different virtual networks, resulting in the dispersion of underlying network resources and the intensification of resource fragmentation.

To deal with these issues, we propose a heuristic virtual network mapping method based on `generalized network temperature (GNT)`.

The proposed algorithm, named as VNE-GNT, adopts a node-ranking approach that takes the GNT information into account in a recursive manner to assist the greedy node mapping.The VNE-GNT algorithm can optimize the deployment location of the current virtual network and strengthen the collaboration between different virtual networks.

At the same time, the distance impact factor is adopted to improve the synergy between the node-mapping stage and the link-mapping stage, and the mapping cost is further reduced while meeting the constraints.

Our simulation results suggest that the proposed VNE-GNT algorithm outperforms three existing VNE algorithms, in the terms of the acceptance rate of virtual network and the utilization of substrate network resources.

Index Terms: Network Virtualization(NV), Virtual Network Embedding(VNE), PageRank, Node Ranking, Generalized Network Temperature(GNT)

---

## 1. INTRODUCTION

(背景, 网络环境现状, 虚拟化, )

Recently, Internet has been growing exponentially with larger number of nodes and end-users, higher volume of traffic, and more varieties of applications.

With the development of the Internet, the number of network equipment, network traffic and end users has increased exponentially [22]. `Due to the huge system and complex structurethe of the traditional network architecture, it is difficult to meet the need of this explosive growth, but also difficult to expand and upgrade services, while the Internet rigidity problem [2] [3] is also becoming more and more serious, restricting the further development of the Internet.`

Network virtualization technology[4] allows multiple virtual networks to be deployed on the same underlying network without interfering with each other, and realizes the sharing of underlying network resources to maximize the utilization of network resources. Therefore, network virtualization technology is considered to be an effective solution to the problem of `Internet rigidity` and promote the further development of the Internet [18].

In network virtualization technology, a virtual network is a logical topology consists of a series of virtual nodes and a few virtual links that connect the virtual nodes. The substrate network consists of many reusable physical nodes and physical links [5]. The process of mapping a virtual network, requested by an end user, to a shared substrate physical network is known as Virtual Network Mapping (VNE) [19].

`Because of the conditional bundle of multiple dimensions, the solution of the traversal solution to the virtual network mapping problem has multiple dimensions of conditional constraints, which has been proved to be an NP-hard problem [1].`

The VNE problem has been proven to be NP-hard [7], and previous researches have proposed several heuristic algorithms to address it [8–13].

Therefore, the existing algorithms for solving virtual network mapping are roughly divided into three categories: precision solving, heuristics, and meta-heuristic algorithms [7].

Because the heuristic algorithm can find virtual network mappings in polynomial time and has good performance, `it is a hot topic in current research.`

The existing heuristic VNE mapping algorithm calculates the importance metric of the node from the topology information and uses it as an important basis for selecting the substrate node during the node mapping stage.

It should be pointed out that the resource importance indicator must not only reflect the size of the node's own resources, but also reflect its importance in the network topology.

In order to reduce the computational complexity of the traditional heuristic virtual network mapping algorithm, the virtual network mapping is usually solved in two stages: node mapping and link mapping.

Among them, most of the node mapping adopts a greedy mapping strategy, that is, the network node is first sorted in importance, and the virtual node with more resource requirements is mapped to the underlying node with high importance as much as possible to meet the needs of the current virtual network request as much as possible.

Most of the link mappings use the Dijkstra shortest path algorithm [12] to calculate the mapping scheme of virtual links, reducing the cost of the underlying link bandwidth.

`The best interest of the InPs is to achieve as much revenue as possible from serving the VN requests. Hence, they need to decide how to serve a VN request by allocating appropriate resources in the substrate network, i.e., virtual network embedding (VNE). Specifically, for each VN request, the InP needs to find a set of nodes and links in the substrate network, which have sufficient resources to carry the virtual nodes and virtual links.`

In summary, the existing virtual network mapping algorithms has the following problems:

- The node importance evaluation is not comprehensive enough, resulting in a decrease in the acceptance rate of virtual network mappings.

In the node-ranking stage, such algorithms only consider the static network topology and local network resources, ignore the impact of network load changes. Therefore, the evaluation of node importance is not comprehensive enough, `resulting in the importance of the selected nodes not matching the resources they have, leading to the low acceptance rate of virtual network.`

- The acceptance rate of the virtual network is given priority, resulting in fragmentation of the substrate network resources and serious waste of resources.

`In the node mapping stage, such algorithms only focus on maximizing the possibility of the current virtual network being accepted, do not optimize the deployment location of the virtual network according to the actual configuration and consumption of resources in the network, and lack of synergy between different virtual networks, resulting in the early use of key resources in the network, fragmentation of the underlying network resources is difficult to recycle, and the acceptance rate of subsequent virtual network requests is reduced.`

- Node mapping and link mapping are separated from each other, resulting in the low acceptance rate of virtual network.

`Completely separated two-stage mapping, lack of synergy between nodes and links, there will be adjacent virtual nodes mapped to two remote substrate nodes, resulting in increased virtual link mapping overhead, reducing the utilization of underlying network resources.`

(别人的方法, 分类, 目前还存在的问题)

`Most of these algorithms performed node mapping based on the local resource information (i.e., the nodes’ resources or the nodes’ resources together with their incident links’ resources). However, this type of approach could easily result in unbalanced load distribution and congestion in the substrate network. Two recent works in [12, 13] took global resource information into consideration in the node mapping, while the algorithms only adopted over-simplified metrics to measure the embedding capacities of the nodes and did not fully explore the benefit of the global resource information.`

(怎么做的, 实验效果怎样)

Based on the Generalized Network Temperature(GNT) proposed by Wang et al. [14], this paper proposes a heuristic virtual network mapping algorithm based on the GNT, which better solves the above problems.

`While serving the VN requests, the proposed VNE-GNT algorithm adopts a node rank, similar to the PageRank in web-search algorithm`14`, to rank nodes according to their (CPU bandwidth GNT resources).`

`We then implement greedy node mapping based on the node ranks, and when node mapping is accomplished, link mapping is performed with the shortest-path routing algorithm.`

`Simulation results show that the proposed VNE-GNT algorithm outperforms three existing VNE algorithms that also use the global resource information, in terms of acceptance and revenue.`

(文章主要贡献)

Overall, the main contributions of this paper are listed as follows.

- A novel node-ranking approach is proposed by considering five network attributes and global network resources. The novel node-ranking approach, different from the previous node-ranking approaches, adopts the well-known PageRank method to calculate the node-ranking value in a stable state.

Based on the concept of GNT, a novel node-ranking approach is proposed, which considers the available resources and traffic changes of the substrate network.

`It can comprehensively evaluate the importance of nodes from multiple angles, and overcome the problem that and when mapping virtual networks, there will be problems where node CPU resources meet the constraints but link resources do not meet the constraints, or vice versa.`
  
- Based on the node-ranking approach of contribution 1, a heuristic virtual network mapping algorithm is further proposed. The proposed algorithm can not only meet the resource requirements of the given virtual network request, but also optimize the deployment location of the virtual network and improve the resource utilization of the entire substrate network.

- The distance impact factor is adopted to optimize the greedy node mapping strategy and increase the collaboration between the node-mapping stage and link-mapping stage. 

(两节点映射过于远m=, 造成带宽资源的浪费)

`It can overcomes the problem that the traditional greedy strategy causes the current adjacent virtual nodes to be mapped to two distant underlying nodes, thereby unnecessary bandwidth consumption according to law.`

`which reduces the link mapping cost as much as possible while meeting the node demand constraints, and`

> Comprehensive simulation is implemented in our self-developed simulation platform in order to validate the advantage of VNE-GNT algorithm.
>
> Five typical and latest heuristic algorithms are selected for performance comparison.

(文章结构)

The rest of this paper is organized as follows. We formulate the VNE problem in Section 11. The details of the proposed VN-GNT algorithm are discussed in Section 11. Section 11 shows the simulation setup and results for the performance evaluation. Finally, Section 11 summarizes the paper.

---

## 2. Related work

The literature [6, 7] proves that virtual network mapping (VNE) is an NP-hard problem. In the literature [7], the authors divide VNE algorithms into three categories according to the optimization strategies employed: precision solving, heuristics, and meta-heuristics. Precision solution algorithms and meta-heuristics can obtain the best or nearest optimal mapping result, but the time complexity of the algorithm is high and cannot be applied to large-scale network environments. The time complexity of the heuristic algorithm is relatively low, and a feasible mapping scheme can be found in polynomial time, which is suitable for larger networks.

`However, VNE is an online problem and tries to embed proposed VNRs efficiently and dynamically in real networking. Therefore, we need to design a heuristic VNE algorithm, compromising the global optimality for a short execution time.`

Yu et al. [8] proposed a heuristic mapping algorithm based on the node product value, which has become the most classic heuristic virtual network mapping algorithm used today. The core idea is to first sort all physical and virtual nodes, then use greedy strategies for node mapping, and finally use the Dijkstra method[13] and the Multi-Community Flow (MCF) method [13] to solve the virtual link mapping. When Yu et al. perform node sequencing, the sort value consists of two parts: the CPU resources of the node itself and the bandwidth of all the direct links of the node. The sort value represents the node's mapping ability in the local network, and the higher the sort value, the higher the likelihood that it will be selected by the virtual network mapping. The method is efficient because it is simple, but the method ignores the influence of nodes in the entire network, and the greediness of the algorithm leads to the premature waste of the underlying physical nodes with strong mapping ability, which leads to a sharp decrease in the success rate of the later virtual network mapping.

Cheng et al. [9] proposed a heuristic virtual network mapping algorithm based on `topology awareness`. Unlike literature 8, when performing node ranking, Cheng et al. used the Markov Random Walk model to calculate the final stable sort value of the nodes iteratively. However, this method fails to effectively quantify global resources in the node ranking stage, resulting in the waste of substrate network resources.

Feng et al. [10] proposed three different node-ranking methods based on new topology attributes, `but the essence is still to determine the importance value based on the computing resource of the nodes, the bandwidth of the direct link and the number of intermediate nodes of the physical path.` 

In the literature [12], Zhang et al. used the modality attribute and clustering coefficient as the basis for node ranking, and the remaining steps were similar to `before`. However, in this method, the node degree attribute and the clustering coefficient information are still local topology attributes, and the global topology attributes are ignored. It will still prematurely exhaust the resources of the underlying nodes with strong mapping capabilities, resulting in a decrease in the success rate of virtual network mapping.

Gong et al. [11] proposed a heuristic virtual network mapping algorithm that decides the order of the virtual network to be mapped based on the mapping revenue of the virtual networks and then uses a method similar to document [9] for node-ranking, after which the virtual node mappings are the same as the virtual link mappings [8].

In summary, the node-ranking approach used by most heuristic virtual network mapping algorithms is still based on the static topology information of the network, ignoring the impact of network load changes on the node importance evaluation. With the arrival and departure of the virtual network request, the resource and load distribution of the substrate network are dynamically changing. Based solely on the static network topology and available network resource information, it is difficult to optimize the deployment location of the virtual network and prevent the fragmentation of the substrate network resources effectively.

---

## 2. VNE PROBLEM FORMULATION

This part of the paper gives a universal description of VNE, its procedures, along with the performance metrics.

### A. VNE Models

- Substrate network: We model the substrate network as an undirected graph, denoted as $G^s = (N_s, L_s,)$, where $N_s$ is the set of substrate nodes and $L_s$ is the set of substrate links.

We denote the available computing resource(e.g. CPU) of node $n_s \in N_s$, and available bandwidth of link $l_s \in L_s$, as $c_n$ and $b_l$, respectively.

$P_l$ is the set of (acyclic paths) in $G_s$.

$P_{mn}^s$ is the set of all loop-free paths between substrate nodes $m$ and $n$, $P_{mn}$ is one path selected from the $mn$ path set $P_{mn}^s$.

An example of a substrate network is illustrated if (Fig.1 a), where the numbers around the nodes and links are their available resources.

- Virtual network: We use notation $G_v$ to denote a virtual network(VN) request, whose topology can also be modeled as an undirected graph, where $N_v$ is the set of virtual nodes and $L_v$ is the set of virtual links.

Each virtual node $n_v \in N_v$ is associated with a computing resource demand of $c_v$ and each virtual link $l_v \in L_v$ has a bandwidth demand of $b_l$.

(Fig. 1 b) illustrates a VN request.

Each VN request is also associated with two tie-domain parameters, i.e., $a$ for the arrival time and $b$ for its lifetime.

With adding the time attributes (arrival time, duration time and leaving time), a VN is extended to be a VNR.

The notations are summarized in `Table 1`

### B. VNE Process (映射过程以及约束条件)

Upon the arrival of a VNR, the substrate network has t o decide whether to accept the VNR or not. If the VNR is accepted, the substrate network must allocate the demanded network resources to embed the VNR. Allocated network resources are released upon the expiration of VNR.

The VNE process, as illustrated in `Fig. 1`, consists of three key steps, i.e., node ranking, node mapping and link mapping.

- 1. node ranking:
  
ok

- 2. node mapping:

To each VNR, each virtual node must be assigned to a different substrate node of the SN.
  
The InP finds, for each virtual node from the VN request, q unique substrate node that has enough available computing resource to meet its computing resource demand, through a mapping, i.e., $F_N: N_v \rightarrow N_s$, such that,

The assignments of all virtual node in one VNR are determined by the nod-mapping function $F_n(): N^V \rightarrow N^S$

$$F_N(n_v) = v_s$$

under the following two constraints:

where (1) aims to ensure that node capacity demand of virtual node $M$ must not exceed the available node capacity of the selected substrate node $F_N(M)$ that accommodates the virtual node $M$; (2) aims to ensure that the deviation relationship between the virtual node $M$ and the selected substrate node $F_N(M)4 must be within the required radius $LR(M)$ of virtual node $M$. Both two formulas must be fulfilled simultaneously in the node mapping stage.

For example, as shown in `Fig. 1`, the node mapping for the VN request is ${1 \rightarrow D, 2 \rightarrow C, ...}$.

As illustrated by `Fig. 2`, the node mapping result of virtual node of  $VNR_1$ if ${A -\rightarrow b, B \rightarrow a, C \rightarrow c}$.

- 3. link mapping

Each virtual link of the same VNR is mapped onto a single substrate path in this paper between the corresponding substrate nodes that host two end virtual nodes.

For two adjacent nodes in the VN request, the InP finds one or more paths between the two mapped substrate nodes, and the total bandwidth of the path(s) should be larger than the corresponding virtual link bandwidth demand.

In this paper, path splitting(cao 27) cases are not considered.

The link mapping is performed according to a link-mapping function $F_L(): L^N \rightarrow L^S$ for all virtual links(of the given VNR).

Specifically, the mapping if $F_L: L_v \rightarrow L_s$, such that,

$$F_L(l_v) = l_s$$

under the following capacity constraints, i.e.,

$$b_l \le B_L$$

where $B_L$ is the total available bandwidth of path set $F_l$.

During the VNR embedding, both the node mapping and the link mapping must be fulfilled. Otherwise, the VNR embedding fails and the given VNR is rejected.

For example, as shown in `Fig. 1`, the link mapping for the VN request is ${(1, 2) \rightarrow (D, C), ..., }$.

For better understanding of the VNR embedding, the embedding process of the VNR is depicted in `Fig. 3`.

### C. Performance Metrics (评价指标)

After successfully mapping one VNR, it is essential to define proper metrics so as to evaluate the mapping algorithm.

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

We refer this algorithm as GNT-Derived  VNE (VNE-GNT) algorithm, for it aims to from the famous Google PageRank website algorithm, we introduce hoe to get the stable node-ranking values of a given network in the following content.
maximize the InP's revenue by accepting as many as possible VN requests under the resource limitation of its substrate network.

(example 2)

The proposed VNE-GNT algorithm is detailed in this section. Five important network topology attributes, adopted in VNE-GNT, are introduced and quantified at first. Then the novel node-ranking approach is presented, which consists of two subapproaches. Next, greedy node mapping is implemented based on the novel node-ranking approach. After completing the node mapping, the link mapping stage follows. In the last section, the time complexity of VNE-GNT is presented to prove that the VNE-GNT algorithm can conduct each given VNR embedding in polynomial time.

### A. Node Ranking

Drawn from `19`, different topology attributes will have different critical effects on the embedding of each VNR. Each topology attribute enables to measure the relative importance of each node from the corresponding respect.

Derived from the previous studies (e.g. 19 and 20), five fundamental and important topology attributes, adopted in our novel node-ranking approach.

- Degree of a node $n$: Formula (10) defines the degree of node $n$ in a given network. It is determined by the function $totlink()$, counting the number of adjacent links of node $n$ in the network

$$Degree(n) = totlink(n)$$

- Strength of a node $n$: Formula (11) is the definition of the strength of node $n$ in the given network. It is determined by the function $totband()$, counting the sum of adjacent link bandwidth of node $n$ in the network

$$Strength(n) = totband(n)$$

The node-ranking approach is able to estimate the embedding ability of each substrate node.

At first, a novel metric "Nov", quantifying topology attributes and global resources simultaneously, is defined. Global network resources considered in the novel node-ranking approach are node capacity and link bandwidth.

Inspired by the *Coulomb's Law* in () area and the *Newton's Law* in () field, the interactions between any two discrete objects can be quantified. Therefore, formula (18) to quantify the interaction between any two nodes, $n$ and $m$, in the given network. Formula (18) is proposed to qualify the interaction between node $n$ and node $m$ in the node-ranking stage.

$$nov = $$

where $n$ is ...

$$RB\% = benefiting$$

where $RB\%$ is the normalized $RB$ of node $m$ in the network.

Weight factors $\alpha$ and $\beta$ are used to balance the normalized resource block $RB$ and $Nov$ of node $m$.

However, in extreme cases, such as sparse networks, *Direct node-ranking approach* is not able to calculate the importance of all nodes accurately, leading to inefficient resource utilization in the long term. Therefore, it is necessary to calculate stable $Nov$ of the given network, enabling to show the importance of all nodes accurately. Derived from the famous Google PageRank website algorithm, we introduce hoe to get the stable node-ranking values of a given network in the following content.

(PageRank部分)

For the node mapping, we adopt a novel ranking approach, similar to the PageRank algorithm.

> Through this importance index formulate we are ranking the substrate nodes before mapping. The higher the importance index the higher will be the rank and that node is considered first for node mapping with the virtual node of arrival VNR.

```markdown
Stable Node Ranking approach

Input: Network $G=(N, L)$, a small positive number $\delta$
Output: Node Ranking Vector $R$ of the given Network $G$

1. calculate matrix $M$ and initial vector $R_0(T_0)$
2. Define the iteration number $k$, $k = 0$
3. Define the variable number $w$, $w = 8$
4. **while** $w \le \delta$ **do**:
5.     $R_{k + 1} = (1 - d) * RB + d * M * R_k$;
6.     w = ||R_{k + 1} - R_k||;
7.     k = k + 1;
8. **end while**
9. $R = R_{k + 1}$


<!-- 1. Given a positive value $\epsilon$, $i \leftarrow 0$
2. **repeat**
3. 　$NR^{i + 1} = NR^i$
4.   $\delta \leftarrow ||NR^{i + 1} - NR^i||$
5.   $i += 1$
6. **until** $\delta \gt \epsilon$ -->
```

Backtracking and recursion methods cannot be applied to calculate (28), Therefore, an iterative approach can be adopted. Through $k$ iterations, it is easy to converge to the stable solution and get a final solution of (18). Therefore, corresponding complexity of the iteration-based node-ranking approach is $O(|N|^2\log{\frac{1}{\delta}})$, $\delta$ is a small positive number to ensure the number of iterations.

The procedure of the stable node-ranking approach are detailed in `Algorithm 1`.

### B. Node Mapping

(总的说: 贪心策略, 然后再讲具体怎么贪心)

In our proposed VNE-GNT algorithm, the node mapping of a given $VNR$ works as follows greedily(works in a greedy way).

> The goal is to allocate the virtual nodes with more significant requirements to the substrate node with more significant resources. Then the process moves to the next stage of virtual link mapping, which is defined in the next subsection.

(网络状态的读取, 备份)

First, we backup the status of the substrate network, and then sorts the nodes of both the substrate network and the VN request in descending order according to the node-rank vectors calculated by `algorithm node rank`.

> The status of the whole network is backed-up on the arrival of $VNR_i$.

(利用上一章节的算法, 计算节点重要性, 然后将底层网络和虚拟网络的节点进行排序, 倒序)

Then all nodes of the substrate network and the proposed $VN$ are sorted in the descending order, according to the node-ranking values calculated by the novel node-ranking approach in above section.

As the value of the node-ranking indicates the embedding capacity of the corresponding node.

(然后就是贪心映射的具体解释)

Thus, the virtual node with the highest node rank among the remaining ones will always embed onto the substrate node that also has the highest node rank among the remaining substrate ones, whose available computing resource meets the demand.

(如果不满足映射约束条件, 就拒绝该VNR)

if the computing resource demand cannot be satisfied by any of the remaining substrate nodes, the VN request is marked as `blocked`(rejected), and if all virtual nodes ars embedded successfully, the computing resource of the corresponding substrate bodes would be updated.

> If the CPU capacity of selected node cannot meet the required demand of any virtual node of $VNR_i$, then the request can be rejected(Step 13).
>
> If every virtual node of the $VNR_i$ are mapped favorably, the CPU capacity of SN is further updated for the next VNR.

The details of the greedy node mapping algorithm are shown in `algorithm 2`(The greedy node mapping procedure is presented in Algorithm 2).

Node Mapping Algorithm

**Input**: Arrived Set of VNRs.
**Output**: Node Mapping Result.

1. Compute the NodeRank values of all nodes in both $G_s$ and $G_v$ using Algorithm 1 with a given value of $\epsilon$
2. Sort the nodes in $G_s$ according to their NodeRank values in non-increasing order
3. Sort the nodes in $G_v$ according to their NodeRank values in non-increasing order
4. **for** each virtual node of the ${VNR}_i$ **do**:
5. &emsp;Re-sort the nodes
6. &emsp;Select the virtual node with the highest node-ranking value of the $VNR_i$ and map it to the substrate node with the highest node-ranking value of the SN, meeting the constraints of CPU demand.
7. **end for**
8. **if** the virtual node mapping of $VNR_i$ succeeds **then**
9. &emsp; return node mapping result
10. **else** reject the $VNR_i$ and throw the $VNR_i$ into the waiting queue
11. **end if**
12. **end while**

The complexity of this algorithm is $O(|N_s||N_v|)$

### C. Shortest-Path-based Link Mapping

With all virtual nodes of the given VNR embedded successfully, the virtual links of the VNR will be embedded.

For the link mapping stage, similar to previous works `[11, 12]`, we apply the shortest-path routing algorithm, which aims to minimize the total substrate bandwidth allocated to each virtual link.

Specifically, we embed the virtual links of the VN request one by one, and for each virtual link, the Dijkstra's algorithm is adopted to find the shortest path between the two corresponding nodes in the substrate network.

What's more(In addition), to improve the efficiency of the Dijkstra algorithm, we delete all substrate links in the substrate network that do not have enough bandwidth for the corresponding virtual link.

If not all virtual links of the given VNR are embedded successfully, the status of the substrate network is restored and the VN request is `rejected`.

`algorithm 3` describes the details of the shortest-path-based link mapping algorithm.

```markdown

Link Mapping Algorithm

**if** virtual node mapping of $VNR_i$ is succeded **then**:
    **for** each numapped virtual link $l$ in $VNR_i$ **do**:
        <!-- 1. 删掉 -->
        delete all the substrate links in the substrate network that do not have enough bandwidth resource for the corresponding virtual link.

        select the shortest path to map all virtual links, with fulfilling all link bandwidth demands of $VNR_i$
        <!-- 2. Dijkstra -->
        **if** find a link **then**:
            Map the link $l$
        **else**:
            Reject the $VNR_i$ and throw the $VNR_i$ into the waiting queue
        **end if**
    **end for**
**end for**
```

The complexity of this algorithm is $O(|E_v||E_s|\log {|E_s|})$

### D. Our Proposed Algorithm

> so, the proposed algorithm runs in polynomial time and can be simulated in a continuous time event(Section V).

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
