DietCli is a cross-platform, command line nutrition tracker written in C++.


# Usage.

Download the release or [build](build.md) it yourself.

Any one of the three arguments, `macro`, `min` or `vit`, mut be provided. An optional argument for filepath of custom `consumed.json` can be provided. If the custom file is not found then it tries to find `consumed.ini` in same directory. `rdi.json` must be in same directory as program.


```

$ ./dietcli macro my-custom-config.json
Protein RDI amount : 50 Consumed amount : 0     Remaining : 50
Carbs   RDI amount : 225        Consumed amount : 0     Remaining : 225
Fats    RDI amount : 70 Consumed amount : 0     Remaining : 70
Fiber   RDI amount : 30 Consumed amount : 0     Remaining : 30

```

