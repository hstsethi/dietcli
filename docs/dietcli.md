# NAME

DietCLI (1)

# SYNOPSIS

dietcli [macro|min|vit] [filepath]

# DESCRIPTION

DietCli is a blazingly fast, cross-platform, command line nutrition tracker written in C++.

# ARGUMENTS


macro
: Analyze macronutrients.

min
: Analyze minerals.

vit
: Analyze vitamins.

# Files


consumed.json
: File containing consumed nutrition data. Looks for it in current directory if custom file is not found or provided.

rdi.json
: File containing recommended daily intake data. Must be in same directory as program.
