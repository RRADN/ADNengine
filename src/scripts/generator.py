from pathlib import Path

def generatePath(name):
    assets_dir = Path(f"assets/{name}")
    output = Path(f"src/core/paths/{name}Path.hpp")

    with open(output, "w") as f:

        f.write('#pragma once\n\n')
        f.write('#include <string>\n')
        f.write('#include <unordered_map>\n\n')
        f.write(f'#include "../ids/{name}ID.hpp"\n\n')

        name = name.capitalize()

        f.write(f'inline std::unordered_map<{name}ID, std::string> get{name}Path() ')
        f.write("{\n   return {\n")

        files = sorted([f for f in assets_dir.iterdir() if f.is_file()])

        for i, file in enumerate(files):
            idName = file.stem.capitalize()
            ending = ",\n" if i < len(files) - 1 else "\n"

            f.write(f'    {{{name}ID::{idName}, "{file.as_posix()}"}}{ending}')    

        f.write("   };\n}")

def generateIDs(name):
    assets_dir = Path(f"assets/{name}")
    output = Path(f"src/core/ids/{name}ID.hpp")

    with open(output, "w") as f:
        name = name.capitalize()

        f.write('#pragma once\n\n')
        f.write(f'enum class {name}ID ')
        f.write("{\n")

        files = sorted([f for f in assets_dir.iterdir() if f.is_file()])

        for i, file in enumerate(files):
            idName = file.stem.capitalize()
            ending = ",\n" if i < len(files) - 1 else "\n"

            f.write(f'    {idName}{ending}')    

        f.write("};")

assets = Path("assets")

for folder in sorted(assets.iterdir()):
    if folder.is_dir():
        generateIDs(folder.name)
        generatePath(folder.name)
