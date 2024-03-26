DietCli is a blazingly fast, cross-platform, command line nutrition tracker written in C++.


# Usage.

Download the release or [build](build.md) it yourself.

Any one of the three arguments, `macro`, `min` or `vit`, mut be provided. An optional argument for filepath of custom `consumed.json` can be provided. If the custom file is not found then it tries to find `consumed.ini` in same directory. `rdi.json` must be in same directory as program.


```

$ ./dietcli macro my-custom-config.json
Protein RDI amount : 50 Consumed amount : 20     Remaining : 30
Carbs   RDI amount : 225        Consumed amount : 100     Remaining : 125
Fats    RDI amount : 70 Consumed amount : 10     Remaining : 60
Fiber   RDI amount : 30 Consumed amount : 20     Remaining : 10

```

```
$ ./dietcli vit | awk '{print $1, $12}'

# NutrientName, RemainingAmount

A 200
B12 1
C 81
D 18
E 7
K 3

```
