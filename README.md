![header](https://capsule-render.vercel.app/api?type=wave&color=auto&height=300&section=header&text=Adaptive%20Load%20Balancing&fontSize=70)

# ADB - Traffic adaptive Load Balancing using AD-Sketch in Datacenter Networks

Introduction of NS2
NS2 stands for Network Simulator Version 2. It is an open-source event-driven simulator designed specifically for research in computer communication networks.

Download at ns2.35 at https://www.isi.edu/nsnam/ns/ns-build.html

Features of NS2
1. It is a discrete event simulator for networking research.

2. It provides substantial support to simulate bunch of protocols like TCP, FTP, UDP, https and DSR.

3. It simulates wired and wireless network.

4. It is primarily Unix based.

5. Uses TCL as its scripting language.

6. Otcl: Object oriented support

7. Tclcl: C++ and otcl linkage

8. Discrete event scheduler

Basic Architecture
NS2 consists of two key languages: C++ and Object-oriented Tool Command Language (OTcl). While the C++ defines the internal mechanism (i.e., a backend) of the simulation objects, the OTcl sets up simulation by assembling and configuring the objects as well as scheduling discrete events. The C++ and the OTcl are linked together using TclCL

--------------------------------------------------------

Code Description
-----------------------------------------------------------------
scripts : OTcl code (Network Topology, basic setup for simulation)

classifier : C++ code for switch load balancing in datacenter networks
