# paper

---

## 0. Abstract

Virtual network embedding (VNE), working as a key step for network virtualization, can map various virtual networks(VNs) onto the shared substrate network efficiently and effectively. Previous VNE algorithms are mostly heuristic which assists the topology attributes and the locally available network resources to rank nodes, leading to a low acceptance rate and inefficient resource utilization in the long term. In addition, such methods focus on maximizing the possibility of the current virtual network being accepted, ignoring the synergy between different virtual networks, resulting in the dispersion of substrate network resources and the intensification of resource fragmentation.

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

Network virtualization technology[4] allows multiple virtual networks to be deployed on the same substrate network without interfering with each other, and realizes the sharing of substrate network resources to maximize the utilization of network resources. Therefore, network virtualization technology is considered to be an effective solution to the problem of `Internet rigidity` and promote the further development of the Internet [18].

In network virtualization technology, a virtual network is a logical topology consists of a series of virtual nodes and a few virtual links that connect the virtual nodes. The substrate network consists of many reusable physical nodes and physical links [5]. The process of mapping a virtual network, requested by an end user, to a shared substrate physical network is known as Virtual Network Mapping (VNE) [19].

`Because of the conditional bundle of multiple dimensions, the solution of the traversal solution to the virtual network mapping problem has multiple dimensions of conditional constraints, which has been proved to be an NP-hard problem [1].`

The VNE problem has been proven to be NP-hard [7], and previous researches have proposed several heuristic algorithms to address it [8–13].

Therefore, the existing algorithms for solving virtual network mapping are roughly divided into three categories: precision solving, heuristics, and meta-heuristic algorithms [7].

Because the heuristic algorithm can find virtual network mappings in polynomial time and has good performance, `it is a hot topic in current research.`

The existing heuristic VNE mapping algorithm calculates the importance metric of the node from the topology information and uses it as an important basis for selecting the substrate node during the node mapping stage.

It should be pointed out that the resource importance indicator must not only reflect the size of the node's own resources, but also reflect its importance in the network topology.

In order to reduce the computational complexity of the traditional heuristic virtual network mapping algorithm, the virtual network mapping is usually solved in two stages: node mapping and link mapping.

Among them, most of the node mapping adopts a greedy mapping strategy, that is, the network node is first sorted in importance, and the virtual node with more resource requirements is mapped to the substrate node with high importance as much as possible to meet the needs of the current virtual network request as much as possible.

Most of the link mappings use the Dijkstra shortest path algorithm [12] to calculate the mapping scheme of virtual links, reducing the cost of the substrate link bandwidth.

`The best interest of the InPs is to achieve as much revenue as possible from serving the VN requests. Hence, they need to decide how to serve a VN request by allocating appropriate resources in the substrate network, i.e., virtual network embedding (VNE). Specifically, for each VN request, the InP needs to find a set of nodes and links in the substrate network, which have sufficient resources to carry the virtual nodes and virtual links.`

In summary, the existing virtual network mapping algorithms has the following problems:

- The node importance evaluation is not comprehensive enough, resulting in a decrease in the acceptance rate of virtual network mappings.

In the node-ranking stage, such algorithms only consider the static network topology and local network resources, ignore the impact of network load changes. Therefore, the evaluation of node importance is not comprehensive enough, `resulting in the importance of the selected nodes not matching the resources they have, leading to the low acceptance rate of virtual network.`

- The acceptance rate of the virtual network is given priority, resulting in fragmentation of the substrate network resources and serious waste of resources.

`In the node mapping stage, such algorithms only focus on maximizing the possibility of the current virtual network being accepted, do not optimize the deployment location of the virtual network according to the actual configuration and consumption of resources in the network, and lack of synergy between different virtual networks, resulting in the early use of key resources in the network, fragmentation of the substrate network resources is difficult to recycle, and the acceptance rate of subsequent virtual network requests is reduced.`

- Node mapping and link mapping are separated from each other, resulting in the low acceptance rate of virtual network.

`Completely separated two-stage mapping, lack of synergy between nodes and links, there will be adjacent virtual nodes mapped to two remote substrate nodes, resulting in increased virtual link mapping overhead, reducing the utilization of substrate network resources.`

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
  
- Based on the node-ranking approach of contribution 1, a heuristic virtual network mapping algorithm is further proposed. The proposed algorithm can not only meet the resource requirements of the given virtual network request but also optimize the deployment location of the virtual network and improve the resource utilization of the entire substrate network.

- The distance impact factor is adopted to optimize the greedy node mapping strategy and increase the collaboration between the node-mapping stage and the link-mapping stage.

(两节点映射过于远m=, 造成带宽资源的浪费)

`It can overcomes the problem that the traditional greedy strategy causes the current adjacent virtual nodes to be mapped to two distant substrate nodes, thereby unnecessary bandwidth consumption according to law.`

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

Yu et al. [8] proposed a heuristic mapping algorithm based on the node product value, which has become the most classic heuristic virtual network mapping algorithm used today. The core idea is to first sort all physical and virtual nodes, then use greedy strategies for node mapping, and finally use the Dijkstra method[13] and the Multi-Community Flow (MCF) method [13] to solve the virtual link mapping. When Yu et al. perform node sequencing, the sort value consists of two parts: the CPU resources of the node itself and the bandwidth of all the direct links of the node. The sort value represents the node's mapping ability in the local network, and the higher the sort value, the higher the likelihood that it will be selected by the virtual network mapping. The method is efficient because it is simple, but the method ignores the influence of nodes in the entire network, and the greediness of the algorithm leads to the premature waste of the substrate physical nodes with strong mapping ability, which leads to a sharp decrease in the success rate of the later virtual network mapping.

Cheng et al. [9] proposed a heuristic virtual network mapping algorithm based on `topology awareness`. Unlike literature 8, when performing node ranking, Cheng et al. used the Markov Random Walk model to calculate the final stable sort value of the nodes iteratively. However, this method fails to effectively quantify global resources in the node ranking stage, resulting in the waste of substrate network resources.

Feng et al. [10] proposed three different node-ranking methods based on new topology attributes, `but the essence is still to determine the importance value based on the computing resource of the nodes, the bandwidth of the direct link and the number of intermediate nodes of the physical path.`

In the literature [12], Zhang et al. used the modality attribute and clustering coefficient as the basis for node ranking, and the remaining steps were similar to `before`. However, in this method, the node degree attribute and the clustering coefficient information are still local topology attributes, and the global topology attributes are ignored. It will still prematurely exhaust the resources of the substrate nodes with strong mapping capabilities, resulting in a decrease in the success rate of virtual network mapping.

Gong et al. [11] proposed a heuristic virtual network mapping algorithm that decides the order of the virtual network to be mapped based on the mapping revenue of the virtual networks and then uses a method similar to document [9] for node-ranking, after which the virtual node mappings are the same as the virtual link mappings [8].

In summary, the node-ranking approach used by most heuristic virtual network mapping algorithms is still based on the static topology information of the network, ignoring the impact of network load changes on the node importance evaluation. With the arrival and departure of the virtual network request, the resource and load distribution of the substrate network are dynamically changing. Based solely on the static network topology and available network resource information, it is difficult to optimize the deployment location of the virtual network and prevent the fragmentation of the substrate network resources effectively.

---

## 2. VNE PROBLEM FORMULATION

This part of the paper gives a universal description of VNE, its procedures, along with the performance metrics.

### A. VNE Models

- Substrate network: We model the substrate network as an undirected graph, denoted as $G_v = (N_s, L_s, A_s^n, A_s^l, P_s)$, where $N_s$ is the set of substrate nodes and $L_s$ is the set of substrate links.

We denote the available computing resource(e.g. CPU) of node $n_s \in N_s$, and available bandwidth of link $l_s \in L_s$, as $c_n$ and $b_l$, respectively.

$P_s$ is the set of all loop-free substrate paths in $G_s$.

$P_{mn}^s$ is the set of all loop-free paths between substrate nodes $m$ and $n$, $P_{mn}$ is one path selected from the $mn$ path set $P_{mn}^s$.

An example of a substrate network is illustrated if (Fig.1 a), where the numbers around the nodes and links are their available resources.

- Virtual network: We use the notation $G_v$ to denote a virtual network(VN) request, whose topology can also be modeled as an undirected graph $G_v = (N_v, L_v, A_v^n, A_v^l, P_v)$, where $N_v$ is the set of virtual nodes and $L_v$ is the set of virtual links.

Each virtual node $n_v \in N_v$ is associated with a computing resource demand of $c_v$ and each virtual link $l_v \in L_v$ has a bandwidth demand of $b_l$.

(Fig. 1 b) illustrates a VN request.

Each VN request is also associated with two tie-domain parameters, i.e., $a$ for the arrival time and $b$ for its lifetime.

To facilitate the understanding of the model definition of the substrate network and the virtual network, Figure 3.1 draws one substrate network and two virtual networks. It should be noted that to simplify the presentation of the model, the properties of the nodes and links are not marked.

By adding the time attributes (arrival time, duration time and leaving time), a VN is extended to be a VNR.

The notations used throughout this paper are summarized in `Table 1`.

### B. VNE Process (映射过程以及约束条件)

`Upon the arrival of a VNR, the substrate network has to decide whether to accept the VNR or not. If the VNR is accepted, the substrate network must allocate the demanded network resources to embed the VNR. Allocated network resources are released upon the expiration of VNR.`

The VNE process, as illustrated in `Fig. 1`, consists of three key steps, i.e., node-ranking stage, node-mapping stage and link-mapping stage.

- 1. node ranking:
  
ok

- 2. node mapping:

For each VN request, each virtual node must be assigned to a different substrate node that has enough available computing resources.

The assignments of all virtual nodes in the given VNR are determined by the node-mapping function $F_n(): N^V \rightarrow N^S$

$$F_N(n_v) = v_s$$

under the following constraints:

$$cpu(n_v) \le cpu(n_s)$$

$$NodeMap(m_v) = NodeMap(n_v), iff m_v = n_v$$

where (1) aims to ensure that the substrate node $n_s$ must have enough available computing resources to meet the resource demand of the virtual node $n_v$. (3.4) guarantees that different virtual nodes requested from the same virtual network are not mapped to the same substrate node. It is important to note that multiple virtual nodes from different virtual networks can share the same substrate node.

> For example, as shown in `Fig. 1`, the node mapping for the VN request is ${1 \rightarrow D, 2 \rightarrow C, ...}$.

As illustrated by `Fig. 2`, the node mapping result of virtual node of  $VNR_1$ if ${A -\rightarrow b, B \rightarrow a, C \rightarrow c}$.

- 3. link mapping

After completing the node mapping, the link mapping stage follows.

`Each virtual link of the same VNR is mapped onto a single substrate path between the corresponding substrate nodes that host two virtual nodes.`

In this paper, path splitting(cao 27) cases are not considered.

`For two adjacent nodes in the VN request, the InP finds one or more paths between the two mapped substrate nodes, and the total bandwidth of the path(s) should be larger than the corresponding virtual link bandwidth demand.`

The link mapping is performed according to a link-mapping function $F_L(): L^N \rightarrow L^S$ for all virtual links of the given VNR.

Specifically, the mapping if $F_L: L_v \rightarrow L_s$, such that,

$$F_L(l_v) = l_s$$

under the following capacity constraint, i.e.,

$$b_l \le B_L$$

where $B_L$ is the total available bandwidth of path set $F_l$.

During the VNR embedding, the node mapping and the link mapping must be fulfilled simultaneously. Otherwise, the VNR embedding fails and the given VNR is rejected.

> For example, as shown in `Fig. 1`, the link mapping for the VN request is ${(1, 2) \rightarrow (D, C), ..., }$.

`For better understanding of the VNR embedding, the embedding process of the VNR is depicted in Fig. 3.`

If the virtual network is successfully mapped, it will occupy the allocated network resources for the duration of $T_d$, and the allocated network resources will be released upon the expiration of VNR for the mappings of the subsequent virtual network requests.

### C. Performance Metrics (评价指标)

When mapping virtual networks, it is essential to define proper metrics to evaluate the mapping algorithm.

- VNR Acceptance Ratio: The long-term average acceptance ratio of VN requests is given by the following function:

$$VNE_{accept} = \lim_{T \rightarrow \infty} {\frac{VNR_{accept}}{VNR_{total}}}$$

where $num_{success}$ represents the total number of accepted virtual network requests and $num_{total}$ corresponds to the total number of arrival VNRs in the time window $T$.

- Long-Term Average Revenue: The long-term average revenue in the time $T$ is given by the following function:

$$Rev = \lim_{T \rightarrow \infty} {\frac{\sum_{t=1}^{t=T}{Rev(t)}}{T}}$$

where $Rev$ represents the revenue of accepting the VNRs at time $t$ which is defined as follows:

$$Revenue(G_v) = \alpha \sum_{n_v \in N_v}{cpu(n_v)} + \beta \sum_{l_v \in L_v}{bandwidth(l_v)}$$

where $cpu(n_v)$ represents computing resource demand of a virtual node $n_v$, $bandwidth(l_v)$ represents bandwidth demand of a virtual link $l_v$. $N_v$ represents the set of all virtual nodes and $L_v$ represents the set of all virtual links of the $VNR_i$. Weight factors $\alpha$ and $\beta$ are used to balance different types of network resources.

- Long-Term Average Cost: The long-term average cost in the time $T$ is given by the following function:

$$Cost(G_v) = \gamma \sum_{n_v \in N_v}{CPU(n_v)} + \eta \sum_{l_v \in L_v}{\sum_{p \in P_s(l_v)}{hops(p) bandwidth(l_v)}}$$

where parameters $\gamma$ and $\eta$ are the weighting parameters of node and link resources respectively, both are set to 1 in this paper.

$P_s(l_v)$ is combined assigned pathset for virtual link $l_v$; $hops(p)$ for the path number p$p$ are the number of hops elapsed on the substrate network.

- Long-Term Average Revenue to Cost(R/C) Ratio: The long-term average R/C ratio is given by:

$$R/C = \frac{Rev(G_v)}{Cost(G_v)} = \frac{\lim_{T \rightarrow \infty}{\sum_{t=0}^{t=T}{Rev(G_v, t)}}}{\lim_{T \rightarrow \infty}{\sum_{t=0}^{t=T}{Cost(G_v, t)}}}$$

### C. Network Entropy

- Shannon Entropy
Shannon extends the concept of entropy in statistical physics to the process of channel communication and defines it as information entropy (also known as Shannon entropy). Specifically, for a random variable $x$, the Shannon entropy is defined as:

$$H(x) = -\sum_{x \in X} {p_i \log_{b} {p_i}}$$

where $p_i$ represents the probability of the occurrence of the variable $i$; $X = {p_1, p_2, ..., p_n}$ represents the set of occurrence probabilities for all examples. The base number $b$ corresponds to the scale of Shannon entropy.

`the scale of b = 2 is bit (bit), b = e (natural logarithmic base) is nat (nat), in this paper, if there is no special description, the base will be omitted in the subsequent discussion, and b = e (that is, the dimension is nat) will be uniformly taken, and represented by ln.`

Properties of Shannon entropy: 1) Continuity: The variable Shannon entropy changes continuously with probability; 2) Monotonicity: The Shannon entropy of the variable increases monotonically with the increase of the value of the variable; 3) Adductability: Information from different sources can be superimposed, as follows:

$$H(p_1, p_2, ..., p_n) = H(p_1) + H(p_2) + ... + H(p_n)$$

In the literature [14], the authors use Shannon entropy as the network entropy of GNT, but in some specific scenarios, Shannon entropy is slightly less effective than other types of entropy, to better improve the universality of the algorithm, this article will introduce more types of network entropy.

- Rényi Entropy

Rényi entropy is obtained by Shannon entropy by relaxing the additive conditions, as defined below:

$$R(x) = \frac{1}{1 - \alpha} \ln {\sum {p_i^{\aplha}}}$$

Compared to Shannon entropy, Rényi entropy introduces adjustable parameter α, making the measurement of information more general and flexible. At α>1, certain high-probability events have a greater effect on Rényi entropy than Shannon entropy. In particular, when α→ 1, Rényi entropy degenerates into Shannon entropy, i.e. R(X) →H(X).

- Tsallis Entropy

The definition of Tsallis entropy is as follows:

$$S(x) = \frac{1}{\alpha - 1} (1 - \sum_{i}{p_i^{\alpha}})$$

Among them, consistent with Rényi entropy, α is an adjustable parameter. When α>1, the smaller the p-value, the closer the value of p^α to 0, the distribution of high-probability events is more obvious than that of low-probability events, so Tsallis entropy mainly reflects the distribution state of high-probability events when α>1; On the contrary, when α<0, it mainly reflects the distribution state of low-probability events.

In summary, Shannon entropy is more extensive and universal, while Rényi entropy and Tsallis entropy are further generalized by introducing adjustable parameter α to further promote Shannon entropy, focusing on measuring information.

- GNT

Generalized Network Temperature (GNT) is a new statistical metric proposed by Wang[14] et al. for the portrayal of the network data transmission environment, which takes into account the changes in network topology in the time scale and the changes in network traffic distribution in the space scale, and has typical spatiotemporal fusion characteristics. This indicator has a wide range of applications in many fields such as network anomaly detection[15] and network security posture assessment.

The definition of generalized network temperature GNT is analogous to thermodynamic temperature, in which temperature $T$ is defined as the amount of heat introduced or lost in an insulation system $dQ$ and the resulting change in thermodynamic entropy dS micro-quotient. In the literature [14], taking into account the relationship between thermodynamic entropy and information entropy, the author proposes that if the thermotropic entropy is replaced by the Shannon entropy of the network and the "amount of heat introduced or lost" in the thermodynamics is replaced by the "change in the number of packets transmitted" in the network, a new metric will eventually be obtained, namely the generalized network temperature GNT, which is defined as follows:

$$GNT = \frac{\Delta P}{\Delta H}$$

where $\Delta P$ represents a change in the number of packets transmitted in the network, while $\Delta H$ represents a change in Shannon entropy caused by a change in the number of packets.

Because GNT is derived from thermodynamic temperature analogy, it has similar properties to thermodynamic temperature and can be used to measure how busy data transmission near nodes is. In general, the higher the GNT value of an area in the network, the greater the network load in that region[20]

---

## 3. VNE-GNT algorithm

The proposed VNE-GNT algorithm is detailed in this section.

The basic idea is that in the substrate network, the greater the change of the network load near the node, the higher the generalized network temperature, which also indicates that the node is busy and plays a more important role in the entire network.

Therefore, in addition to the topology attributes and the available resources of the network, the impact of GNT on the node ranking is also considered to make the node importance evaluation more accurate.

Next, greedy node mapping is implemented based on the node-ranking approach and distance factor is also adopted to further reduce the cost of mapping the given VNR.

After completing the node mapping, the link mapping stage follows. In the last section, the time complexity of VNE-GNT is presented to prove that the VNE-GNT algorithm can conduct each given VNR embedding in polynomial time.

### A. Node Ranking

`The importance indicator of a node must not only reflect the size of the node's own resources, but also reflect the mapping ability of the node in the entire network.` When mapping a virtual network, nodes of different importance have different effects on the mapping results, and the more important the node is, the greater the impact on the mapping results.

Liao et al. [10] combined with various topological attributes such as degree centrality and proximity centrality of nodes, concluded that multiple topology attributes can improve the accuracy of node importance evaluation, thereby improving the acceptance rate and mapping revenue of virtual network requests in the long run. Therefore, this paper draws from [10] and evaluates the importance of nodes in combination with various attributes.

- Degree of a node $n$: Formula (4.1) defines the degree of node $n$ in a given network.

$$Degree(i) = \sum_{j = 1}^{N}{a_{ij}}$$

where $N$ represents the number of nodes in a given network. $a_{ij} = 1$ indicates that there is a direct link between the nodes $i$ and $j$, $a_{ij} = 0$ vice versa. The degree of a node indicates the connectivity of the node in the entire network. The greater the degree of a node, the greater the impact on the virtual network mapping results.

- Strength of a node $n$: Formula (4.2) is the definition of the strength of node $n$ in the given network.

$$NodeResource[i] = cpu[i]*\sum_{j = 1}^{N}{bandwidth(ij)}$$

Nodes and links in the network that are rich in resource or have a greater impact on network connectivity are key resources. The traditional heuristic mapping algorithms use the greedy strategy for node mapping, giving priority to the use of key resources for the mapping of the current virtual network, and maximizing the possibility of the current virtual network being accepted. This strategy leads to over-consumption of critical resources in the substrate network, exacerbating the degree of resource fragmentation, thereby reducing the acceptance rate of subsequent virtual network requests.

Therefore, when mapping virtual networks, it is necessary not only to meet the needs of the current virtual network, but also to optimize the deployment location of the virtual network and strengthen the collaboration between different virtual networks in order to map more virtual networks and improve the resource utilization of the substrate network.

At the same time, the importance of network nodes is not only related to the topology of the network or its own network resources, but also to the current network load situation, and the importance of nodes changes with the change of network load [20]. However, traditional heuristic virtual network mapping algorithms are mostly based on static analysis methods based on topology awareness when it comes to node ranking. In the case of changing network status, these methods generally fail to comprehensively and accurately measure the importance of network nodes, resulting in a decrease in the acceptance rate of virtual network mapping and the utilization of network resources.

In summary, in order to evaluate the importance of nodes more comprehensively and strengthen the collaboration between different virtual network requests, this paper takes into account the changes in network load when ranking the network nodes. Then optimize the deployment location of the current virtual network and reserve resources for mapping more subsequent virtual network requests.

To represent the load of a network, we introduce the network traffic matrix. It is the global view of the substrate network traffic, which can obtain the operating state of the network from a more macroscopic perspective [16].

Network Traffic Matrix: A matrix consisting of all OD (Origin-Destination) traffic in the current network, where the OD stream $(v_1, v_2)$ is defined as a collection of all traffic entering from the node $v_1$ (source node) and finally flowing out of the node $v_2$ (target node).

The network traffic matrix of a network with $n$ network nodes is represented in $T$, containing $n × n$ elements.

$$sthsdthdsthdshts$$

where the rows represent the source nodes, the columns represent the destination nodes. The sum of the elements of the $i$ row of the matrix represents the total traffic flowing out of the source node $v_i$, and the sum of the elements of column $j$ of the matrix represents the total traffic flowing into the destination node $v_j$.

According to the definition of network entropy and network traffic matrix, all OD streams gathered near a source node can be regarded as basic states, `which meet the conditions of the network entropy probability mentioned above`. The probability of the state is defined as:

$$p_i = \frac{t_{ij}}{\sum_{j = 1}^{j = n}{t_{ij}}}$$

where $\sum_{j = 1}^{j = n}{t_{ij}}$ represents the total traffic flowing out of the source node $v_i$.

According to the definition of the three types of network entropy, the network entropy of Shannon, Rényi, and Tsallis near the source node is calculated as follows:

$$H_i = -\sum_{i = 1}^{n}{p_i \log{p_i}}$$
$$R_i = \frac{1}{1 - \alpha} \ln_{i = 1}^{n}{p_i^{\alpha}}$$
$$S_i = \frac{1}{\alpha - 1} (1 - \sum_{i = 1}^{n}{p_i^{\alpha}})$$

The GNT of the node can be further obtained as follows:

$$GNT_H = \frac{\Delta T}{\Delta H}$$
$$GNT_R = \frac{\Delta T}{\Delta R}$$
$$GNT_S = \frac{\Delta T}{\Delta S}$$

where $\Delta T$ represents the increment of the change in network traffic over the duration of $\Delta t$, which can be positive or negative. $\Delta H$, $\Delta S$ and $\Delta S$ represents the changes in the entropy Shannon, the entropy of Rényi and the entropy of Tsallis of the network in $\Delta$, respectively.

Formally, the generalized network temperature is the derivative of network traffic relative to network entropy, and its physical significance is the rate of change of network entropy with network traffic.

Therefore, the faster the network traffic near the node changes, the faster the network entropy changes, and the greater the GNT near the node.

With the help of GNT, we can quickly find the substrate nodes with obvious load changes or have a greater impact on network communication under the current network condition, then avoid mapping virtual nodes onto such nodes, thereby optimizing the deployment location of the current virtual network request and preventing the key resources of the substrate network from being overused.

$$zdfvlkbzdnsjlfvbjnzlbfjnv$$

The topology awareness is adopted to distinguish the differences in the importance of resources in the substrate network, while GNT is to provide certain protection for important resources and avoid them from being overused.

The importance value for a node used in this paper is defined as follows:

$$R[i] = \frac{Degree[i] \ast NodeResource[i]}{GNT[i]}$$

where the node degree attribute and the resource strength of the node are positively correlated with the mapping ability of the node, that is, the larger the molecule, the greater the mapping ability of the node; The GNT attribute of the node is negatively correlated with the node importance, so as to avoid the excessive occupation of key resources in the current network state.

Different from the traditional importance-based virtual network mapping algorithms, the method in this paper use the generalized network temperature in the virtual network mapping process to adopt a more reasonable resource mapping strategy and strengthen the collaborative processing between different virtual network requests.

Therefore, when mapping virtual networks, it is more inclined to select nodes with relatively low GNT and relatively rich resources in the generalized network to map, so as to optimize the deployment location of the virtual network, which not only meets the needs of the current virtual network, but also protects important resources to accept more subsequent virtual network mapping requests and improve the resource utilization of the underlying network.

<!-- 
> The node-ranking approach is able to estimate the embedding ability of each substrate node.
>
> At first, a novel metric "Nov", quantifying topology attributes and global resources simultaneously, is defined. Global network resources considered in the novel node-ranking approach are node capacity and link bandwidth.
>
> Inspired by the *Coulomb's Law* in () area and the *Newton's Law* in () field, the interactions between any two discrete objects can be quantified. Therefore, formula (18) to quantify the interaction between any two nodes, $n$ and $m$, in the given network. Formula (18) is proposed to qualify the interaction between node $n$ and node $m$ in the node-ranking stage.

$$nov = $$

where $n$ is ...

$$RB\% = benefiting$$

where $RB\%$ is the normalized $RB$ of node $m$ in the network.

Weight factors $\alpha$ and $\beta$ are used to balance the normalized resource block $RB$ and $Nov$ of node $m$. -->

(PageRank部分)

For the node mapping, we adopt a novel ranking approach, similar to the PageRank algorithm.

It is worth noting that equation (4.10) represents the mapping capabilities of the substrate node itself. But the importance of a node is related not only to the amount of resources of the node itself, but also to the importance of neighboring nodes [9]. In addition, in extreme cases such as sparse networks, the direct node ranking method shown in equation (4.10) can not evaluate the importance of all nodes accurately[10], which affects the virtual network node mapping process, resulting in low resource utilization and low virtual network acceptance rate in the long term.

In order to calculate the stable importance of all the nodes in the entire network accurately, `on the basis of equation (4.10), using the method of calculating the node importance based on the Markov random walk model proposed in the literature [9], the node importance value is iteratively calculated to convergence, and then normalized to obtain the final stable ranking value of the node, and the specific calculation steps are as follows:`

- Sets the initial importance value of the node $NR^0$ based on equation (4.10).

$$NR^0 = \frac{R(n)}{\sum_{u \in N_s}{R(u)}}$$

- The Markov random walk model is then used to iterate on the initial substrate network

$$NR^(i + 1) = X \eta NR^i$$

where $X$ is the Markov one-step transfer matrix defined in [9].

- Finally, using normalization to obtain the final importance value NR(n) of node $n$

$$Rank(n) = \frac{NR(n)}{\sum_{i = 1}^{N}{NR(n_i)}}$$

where $N$ is the number of substrate nodes in the SN.

`However, in extreme cases, such as sparse networks, *Direct node-ranking approach* is not able to calculate the importance of all nodes accurately, leading to inefficient resource utilization in the long term. Therefore, it is necessary to calculate stable $Nov$ of the given network, enabling to show the importance of all nodes accurately. Derived from the famous Google PageRank website algorithm, we introduce how to get the stable node-ranking values of a given network in the following content.`

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

`Backtracking and recursion methods cannot be applied to calculate (28), Therefore, an iterative approach can be adopted. Through $k$ iterations, it is easy to converge to the stable solution and get a final solution of (18). Therefore, corresponding complexity of the iteration-based node-ranking approach is $O(|N|^2\log{\frac{1}{\delta}})$, $\delta$ is a small positive number to ensure the number of iterations.`

The procedure of the stable node-ranking approach are detailed in `Algorithm 1`.

### B. Node Mapping

Virtual node mapping can be divided into one-stage mapping method and two-stage mapping method according to different mapping relationships. Among them, the one-stage mapping method is completed alternately between node and link mapping; The two-stage mapping method is to map all virtual nodes after the link mapping is completed.

The proposed approach belongs to the two-stage heuristic mapping algorithm, but in order to strengthen the synergy between the two stages of virtual node mapping and virtual link mapping, and reduce the cost of virtual link mapping effectively, the node mapping is optimized by using a greedy strategy. Specifically, the defined distance impact factor is as follows:

$$DisFactor(n) = \frac{\sum_{v \in nei(n)}{distance(n, v)}}{|nei(n)|}$$

where $distance(n, v)$ represents the shortest distance between node $n$ and $v$ calculated by the Dijkstra algorithm. $nei(n)$ is the set of substrate nodes, consisting of the substrate nodes corresponding to the virtual nodes of the neighbor of the current virtual node $n$.

As shown in `Figure 4.1`, suppose that virtual nodes $A$ and $B$ have been mapped to the substrate nodes $b$ and $a$, and virtual node $C$ is the virtual node that currently needs to be mapped. For virtual node $C$, if the traditional greedy mapping strategy is still adopted, it may be mapped to the substrate node $i$ according to the `node ranking result calculated above`. However, at this time, the substrate node $i$ is far away from the substrate nodes $a$ and $b$, and more bandwidth resources need to be spent in the subsequent virtual link mapping stage, resulting in the waste of resources.

If the distance factor is introduced to reorder the substrate nodes, the ranking of the nodes that near from the substrate nodes $a$ and $b$ may increase, and if it is mapped to the substrate node $e$, it can not only meet the needs of the virtual node, but also reduce the consumption of bandwidth resources in the virtual link mapping stage.

For the virtual network mapping revenue-cost ratio $Revenue/Cost(G_v)$ (3.10), we can adjust the revenue-to-cost ratio of the virtual network mapping through the distance impact factor. The specific analysis is as follows: for a given virtual network mapping request, the mapping revenue is fixed (e.g., equation (3.8)), so the impact of the revenue-expenditure ratio is the expenditure required to complete the mapping, (e.g., equation (3.9)), which is positively related to the length of the path mapped by the virtual link in the substrate network. In general, the closer the distance between the two substrate nodes, the smaller the shortest path length of the corresponding physical link, then the virtual link mapping cost is smaller when the virtual link is mapped so that the important resources of the substrate network can be protected, leaving more resources for the mapping of subsequent virtual network requests, and improving the resource utilization of the substrate network.

The specific process of optimizing node mapping proposed in this article is as follows:

- For the virtual node $n$ currently to be mapped, add the distance factor to the formula (4.13) to re-rank the substrate nodes.

Node mapping is considered successful if and only if all virtual nodes requested by the virtual network are successfully mapped, otherwise, if any one of the virtual nodes is not successfully mapped, the virtual network is rejected.

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

However, the large number of substrate links will lead to a significant increase in the computational complexity of the Dijkstra algorithm.

So to improve the efficiency of the Dijkstra algorithm, before calculating the link mapping scheme, the substrate network needs to be preprocessed.

When the link is mapped, a possible solution path calculated by the Dijkstra shortest path algorithm is connected by several segments of the substrate link and each substrate link itself bandwidth resources must be greater than or equal to the bandwidth requirements of the current mapped virtual link.

Therefore, we delete temporarily all substrate links in the substrate network that do not have enough bandwidth for the corresponding virtual link to simplify the substrate network topology, reduce the computational complexity of the Dijkstra algorithm, and improve the performance of the link mapping.

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

Hence, we determine that its time complexity is $O(\max {1, 2})$.

Overall, the algorithm can complete the mapping of virtual network requests in polynomial time.

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
