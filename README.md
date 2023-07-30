# Genie_inform

This is the 4 C++/C Programs that are used to extract information from GENIE in the simulations of (anti)neutrino-carbon interactions. 

To extract the information from the event records, 3 C++/C files are written, with the names `getdata.cpp`, `distribution.C`, and `distribution2.C`. The `getdata.cpp` file has 4 option commands:

1. Obtain the multiplicity of total final-state particles, the multiplicity of charged final-state particles, and the multiplicity of uncharged final-state particles. The program would output the multiplicity in the form of raw data.
2. Obtain the types of the final-state nuclei, i.e. `HadrBlob`.
3. For a specific final-state particle, like a proton, obtain its momentum/energy distribution. Then use `distribution.C` to plot the diagram.
4. For a specific final-state particle, obtain the relation between its momentum/energy distribution and its multiplicity. Then use `distribution2.C` to plot the diagram.

To run the program:
```
$ g++ getdata.cpp
$ ./a.out
```

`distribution3.C` is used to plot the histograms with different energies in the same canvas.

Details may refer to [here](https://sxubi.github.io/genie_command/).
