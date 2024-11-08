DietCli is a blazingly fast, cross-platform, command line nutrition tracker written in C++.

Note: Previously it was known as "NutritionCLI". However, that version used INI, was slow and buggy and hence is no longer supported. Though it's [source code](https://github.com/hstsethi/nutritioncli) is available for historical purposes.

## Usage

Download the release or [build](build.md) it yourself.

Any one of the three arguments, `macro`, `min` or `vit`, must be provided. An optional argument for filepath of custom `consumed.json` can be provided. If the custom file is not found then it tries to find `consumed.json` in same directory. `rdi.json` must be in same directory as program.

To generate a pie chart of calorie breakdown by macro nutrient, simply run `python visualize.py`. 


## Examples

![img](pie-diet-cli-default.png)

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

# Acknowledgements

- USDA for providing RDI of nutrients.

- Tencent for RapidJSON library.

